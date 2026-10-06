#!/usr/bin/env python3
"""Estimate a D555-to-Velodyne extrinsic correction from a static scene.

The script deliberately does not write TF configuration.  It uses the live TF as
an initial guess, collects a few stationary point clouds, crops the Velodyne cloud
to the D555 field of view, and runs robust multi-scale point-to-plane ICP.
"""

import argparse
import math
import sys
import time

import numpy as np
import open3d as o3d
import rclpy
from rclpy.duration import Duration
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy
from scipy.spatial.transform import Rotation
from sensor_msgs.msg import PointCloud2
from sensor_msgs_py import point_cloud2
from tf2_ros import Buffer, TransformListener


def transform_matrix(transform) -> np.ndarray:
    q = transform.rotation
    t = transform.translation
    matrix = np.eye(4)
    matrix[:3, :3] = Rotation.from_quat([q.x, q.y, q.z, q.w]).as_matrix()
    matrix[:3, 3] = [t.x, t.y, t.z]
    return matrix


def voxel_cloud(points: np.ndarray, voxel: float) -> o3d.geometry.PointCloud:
    cloud = o3d.geometry.PointCloud(o3d.utility.Vector3dVector(points))
    return cloud.voxel_down_sample(voxel)


def rotation_angle_deg(matrix: np.ndarray) -> float:
    value = np.clip((np.trace(matrix[:3, :3]) - 1.0) / 2.0, -1.0, 1.0)
    return math.degrees(math.acos(value))


class Collector(Node):
    def __init__(self, args):
        super().__init__("d555_velodyne_calibration_collector")
        self.args = args
        self.tf_buffer = Buffer(cache_time=Duration(seconds=10.0))
        self.tf_listener = TransformListener(self.tf_buffer, self)
        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=2,
        )
        self.camera_frames = []
        self.velodyne_frames = []
        self.last_camera_stamp = -1.0
        self.last_velodyne_stamp = -1.0
        self.create_subscription(PointCloud2, args.camera_topic, self.camera_cb, qos)
        self.create_subscription(PointCloud2, args.velodyne_topic, self.velodyne_cb, qos)

    @staticmethod
    def xyz(message: PointCloud2) -> np.ndarray:
        structured = point_cloud2.read_points(
            message, field_names=("x", "y", "z"), skip_nans=True
        )
        points = np.column_stack(
            (structured["x"], structured["y"], structured["z"])
        ).astype(np.float64, copy=False)
        return points[np.isfinite(points).all(axis=1)]

    def camera_cb(self, message: PointCloud2):
        stamp = message.header.stamp.sec + message.header.stamp.nanosec * 1e-9
        if len(self.camera_frames) >= self.args.camera_frames:
            return
        if stamp - self.last_camera_stamp < self.args.camera_interval:
            return
        points = self.xyz(message)
        depth = points[:, 2]
        points = points[(depth > self.args.min_depth) & (depth < self.args.max_depth)]
        self.camera_frames.append(points)
        self.last_camera_stamp = stamp
        self.get_logger().info(
            f"camera sample {len(self.camera_frames)}/{self.args.camera_frames}: "
            f"{len(points)} valid points"
        )

    def velodyne_cb(self, message: PointCloud2):
        stamp = message.header.stamp.sec + message.header.stamp.nanosec * 1e-9
        if len(self.velodyne_frames) >= self.args.velodyne_frames:
            return
        if stamp - self.last_velodyne_stamp < self.args.velodyne_interval:
            return
        points = self.xyz(message)
        distance = np.linalg.norm(points, axis=1)
        points = points[(distance > self.args.min_depth) & (distance < self.args.max_depth)]
        self.velodyne_frames.append(points)
        self.last_velodyne_stamp = stamp
        self.get_logger().info(
            f"velodyne sample {len(self.velodyne_frames)}/{self.args.velodyne_frames}: "
            f"{len(points)} valid points"
        )


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--camera-topic", default="/camera/camera/depth/color/points")
    parser.add_argument("--velodyne-topic", default="/velodyne_points")
    parser.add_argument("--camera-frame", default="camera_depth_optical_frame")
    parser.add_argument("--velodyne-frame", default="velodyne")
    parser.add_argument("--camera-frames", type=int, default=4)
    parser.add_argument("--velodyne-frames", type=int, default=12)
    parser.add_argument("--camera-interval", type=float, default=0.35)
    parser.add_argument("--velodyne-interval", type=float, default=0.09)
    parser.add_argument("--timeout", type=float, default=15.0)
    parser.add_argument("--min-depth", type=float, default=0.4)
    parser.add_argument("--max-depth", type=float, default=12.0)
    parser.add_argument("--hfov-tan", type=float, default=1.0)
    parser.add_argument("--vfov-tan", type=float, default=0.60)
    args = parser.parse_args()

    rclpy.init()
    node = Collector(args)
    deadline = time.monotonic() + args.timeout
    try:
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(node, timeout_sec=0.1)
            if (len(node.camera_frames) >= args.camera_frames and
                    len(node.velodyne_frames) >= args.velodyne_frames):
                break
        if not node.camera_frames or not node.velodyne_frames:
            raise RuntimeError("did not receive both point-cloud topics")

        tf = node.tf_buffer.lookup_transform(
            args.velodyne_frame,
            args.camera_frame,
            rclpy.time.Time(),
            timeout=Duration(seconds=2.0),
        )
        initial = transform_matrix(tf.transform)
    finally:
        node.destroy_node()
        rclpy.shutdown()

    camera_points = np.concatenate(node.camera_frames)
    velodyne_points = np.concatenate(node.velodyne_frames)

    # Keep only Velodyne points that project into the camera's approximate FOV
    # under the current TF. This prevents the 360-degree scan from dominating ICP.
    velodyne_to_camera = np.linalg.inv(initial)
    homogeneous = np.column_stack((velodyne_points, np.ones(len(velodyne_points))))
    velodyne_in_camera = (velodyne_to_camera @ homogeneous.T).T[:, :3]
    z = velodyne_in_camera[:, 2]
    visible = (
        (z > args.min_depth)
        & (z < args.max_depth)
        & (np.abs(velodyne_in_camera[:, 0]) < args.hfov_tan * z)
        & (np.abs(velodyne_in_camera[:, 1]) < args.vfov_tan * z)
    )
    velodyne_points = velodyne_points[visible]
    if len(velodyne_points) < 500:
        raise RuntimeError(f"only {len(velodyne_points)} Velodyne points overlap the camera FOV")

    estimate = initial.copy()
    stages = ((0.20, 0.60, 45), (0.10, 0.30, 35), (0.05, 0.15, 30))
    initial_eval = None
    result = None
    for voxel, max_distance, iterations in stages:
        source = voxel_cloud(camera_points, voxel)
        target = voxel_cloud(velodyne_points, voxel)
        source.estimate_normals(o3d.geometry.KDTreeSearchParamHybrid(radius=voxel * 3, max_nn=40))
        target.estimate_normals(o3d.geometry.KDTreeSearchParamHybrid(radius=voxel * 3, max_nn=40))
        if initial_eval is None:
            initial_eval = o3d.pipelines.registration.evaluate_registration(
                source, target, max_distance, initial
            )
        loss = o3d.pipelines.registration.TukeyLoss(k=max_distance)
        result = o3d.pipelines.registration.registration_icp(
            source,
            target,
            max_distance,
            estimate,
            o3d.pipelines.registration.TransformationEstimationPointToPlane(loss),
            o3d.pipelines.registration.ICPConvergenceCriteria(max_iteration=iterations),
        )
        estimate = result.transformation
        print(
            f"stage voxel={voxel:.2f}m fitness={result.fitness:.4f} "
            f"rmse={result.inlier_rmse:.4f}m"
        )

    correction = estimate @ np.linalg.inv(initial)
    translation = correction[:3, 3]
    euler = Rotation.from_matrix(correction[:3, :3]).as_euler("xyz", degrees=True)
    initial_t = initial[:3, 3]
    initial_rpy = Rotation.from_matrix(initial[:3, :3]).as_euler("xyz", degrees=True)
    final_t = estimate[:3, 3]
    final_rpy = Rotation.from_matrix(estimate[:3, :3]).as_euler("xyz", degrees=True)

    print("\nInitial camera optical -> velodyne TF")
    print("  xyz [m]:", np.array2string(initial_t, precision=6))
    print("  rpy [deg]:", np.array2string(initial_rpy, precision=6))
    print("Estimated correction in velodyne frame")
    print("  xyz [m]:", np.array2string(translation, precision=6))
    print("  rpy [deg]:", np.array2string(euler, precision=6))
    print("Corrected camera optical -> velodyne TF")
    print("  xyz [m]:", np.array2string(final_t, precision=6))
    print("  rpy [deg]:", np.array2string(final_rpy, precision=6))
    print(
        f"Initial fitness={initial_eval.fitness:.4f}, rmse={initial_eval.inlier_rmse:.4f}m"
    )
    print(f"Final fitness={result.fitness:.4f}, rmse={result.inlier_rmse:.4f}m")
    print(
        f"Correction magnitude: translation={np.linalg.norm(translation):.4f}m, "
        f"rotation={rotation_angle_deg(correction):.3f}deg"
    )

    trustworthy = (
        result.fitness >= 0.25
        and result.inlier_rmse <= 0.12
        and np.linalg.norm(translation) <= 0.50
        and rotation_angle_deg(correction) <= 15.0
    )
    print("RESULT:", "candidate accepted for manual validation" if trustworthy else "REJECTED: insufficient confidence")
    return 0 if trustworthy else 2


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception as error:
        print(f"ERROR: {error}", file=sys.stderr)
        sys.exit(1)

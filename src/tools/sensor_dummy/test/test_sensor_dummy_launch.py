"""Starts the real launch file and checks what a downstream node sees on the wire."""

import math
import os
import re
import struct
import threading
import time
import unittest

from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import PoseWithCovarianceStamped
from geometry_msgs.msg import Twist
from geometry_msgs.msg import TwistWithCovarianceStamped
from hunter_msgs.msg import HunterStatus
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
import launch_testing
from nav_msgs.msg import Odometry
import pytest
from rcl_interfaces.msg import Parameter
from rcl_interfaces.msg import ParameterType
from rcl_interfaces.msg import ParameterValue
from rcl_interfaces.srv import SetParameters
import rclpy
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.qos import ReliabilityPolicy
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import CameraInfo
from sensor_msgs.msg import Image
from sensor_msgs.msg import Imu
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import PointCloud2
from std_msgs.msg import Float64
from tf2_msgs.msg import TFMessage
from ublox_msgs.msg import NavPVT
from ublox_msgs.msg import RxmRTCM
import yaml

SHARE = get_package_share_directory("sensor_dummy")
HUNTER_PARAMS = os.path.join(
    os.path.dirname(__file__),
    "..",
    "..",
    "..",
    "vehicle",
    "hunter_ros2",
    "hunter_base",
    "include",
    "hunter_base",
    "hunter_params.hpp",
)
RATE_TOLERANCE = 0.10
SAMPLE_SECONDS = 4.0

# topic, type, frame_id (None: the message has no header), rate
SIM_TOPICS = [
    ("/velodyne_points", PointCloud2, "velodyne", 10.0),
    ("/vectornav/imu", Imu, "vectornav", 20.0),
    ("/vectornav/pose", PoseWithCovarianceStamped, "earth", 20.0),
    ("/ublox_gps_node/fix", NavSatFix, "gnss_antenna", 10.0),
    ("/ublox_gps_node/fix_velocity", TwistWithCovarianceStamped, "gnss_antenna", 10.0),
    ("/ublox_gps_node/navpvt", NavPVT, None, 10.0),
    ("/navpvt", NavPVT, None, 10.0),
    ("/rxmrtcm", RxmRTCM, None, 1.0),
    ("/hunter_status", HunterStatus, "", 50.0),
    ("/hunter/velocity", Float64, None, 50.0),
    ("/current_speed", Float64, None, 50.0),
    ("/current_steer_angle", Float64, None, 50.0),
    ("/odom", Odometry, "odom", 50.0),
    ("/odometry/global", Odometry, "map", 30.0),
]
CAMERA_TOPICS = [
    ("/camera/d435i/color/image_raw", Image, "d435i_color_optical_frame", 30.0),
    ("/camera/d435i/color/camera_info", CameraInfo, "d435i_color_optical_frame", 30.0),
    ("/camera/d435i/depth/image_rect_raw", Image, "d435i_depth_optical_frame", 30.0),
    ("/camera/d435i/depth/camera_info", CameraInfo, "d435i_depth_optical_frame", 30.0),
    ("/camera/d435i/aligned_depth_to_color/image_raw", Image, "d435i_color_optical_frame", 30.0),
    (
        "/camera/d435i/aligned_depth_to_color/camera_info",
        CameraInfo,
        "d435i_color_optical_frame",
        30.0,
    ),
    ("/camera/d435i/imu", Imu, "d435i_imu_optical_frame", 200.0),
    ("/d435_left/d435_left/color/image_raw", Image, "d435_left_color_optical_frame", 15.0),
    ("/d435_left/d435_left/color/camera_info", CameraInfo, "d435_left_color_optical_frame", 15.0),
    ("/d435_left/d435_left/depth/image_rect_raw", Image, "d435_left_depth_optical_frame", 15.0),
    ("/zed/zed_node/rgb/color/rect/image", Image, "zed_left_camera_frame_optical", 60.0),
    ("/zed/zed_node/rgb/color/rect/camera_info", CameraInfo, "zed_left_camera_frame_optical", 60.0),
    ("/zed/zed_node/depth/depth_registered", Image, "zed_left_camera_frame_optical", 60.0),
    ("/zed/zed_node/depth/camera_info", CameraInfo, "zed_left_camera_frame_optical", 60.0),
    ("/zed/zed_node/imu/data", Imu, "zed_imu_link", 100.0),
    ("/cam0/zed_node/rgb/color/rect/image", Image, "cam0_camera_frame_optical", 30.0),
    ("/cam0/zed_node/rgb/color/rect/camera_info", CameraInfo, "cam0_camera_frame_optical", 30.0),
    ("/cam0/zed_node/imu/data", Imu, "cam0_imu_link", 100.0),
]
IMAGE_FORMATS = {
    "/camera/d435i/color/image_raw": (640, 480, "rgb8"),
    "/camera/d435i/depth/image_rect_raw": (848, 480, "16UC1"),
    "/d435_left/d435_left/color/image_raw": (1280, 720, "rgb8"),
    "/zed/zed_node/rgb/color/rect/image": (1280, 720, "bgra8"),
    "/zed/zed_node/depth/depth_registered": (1280, 720, "32FC1"),
    "/cam0/zed_node/rgb/color/rect/image": (1920, 1200, "bgra8"),
}


@pytest.mark.launch_test
def generate_test_description():
    launch_file = os.path.join(SHARE, "launch", "sensor_dummy.launch.py")
    return LaunchDescription(
        [
            IncludeLaunchDescription(
                launch_file,
                launch_arguments={
                    "ground_truth": "true",
                    "cameras": "d435i,d435_left,zed2i,cam0",
                }.items(),
            ),
            launch_testing.actions.ReadyToTest(),
        ]
    )


class Probe:
    """Counts raw messages on a topic and keeps the last one."""

    def __init__(self, node, topic, msg_type):
        self.msg_type = msg_type
        self.count = 0
        self.last_raw = None
        self.stamps = []
        # Reliable, as the DDS rule of the workspace asks for big messages: a best-effort reader
        # drops a whole image when one UDP fragment is lost.
        qos = QoSProfile(depth=50, reliability=ReliabilityPolicy.RELIABLE)
        node.create_subscription(msg_type, topic, self._on_raw, qos, raw=True)

    def _on_raw(self, raw):
        self.count += 1
        self.stamps.append(time.monotonic())
        self.last_raw = raw

    def last(self):
        return deserialize_message(self.last_raw, self.msg_type)

    def rate(self, seconds):
        start = self.count
        time.sleep(seconds)
        return (self.count - start) / seconds


class SensorDummyTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        rclpy.init()
        cls.node = Node("sensor_dummy_test")
        cls.executor_ = MultiThreadedExecutor(num_threads=4)
        cls.executor_.add_node(cls.node)
        cls.spin_thread = threading.Thread(target=cls.executor_.spin, daemon=True)
        cls.probes = {
            topic: Probe(cls.node, topic, msg_type)
            for topic, msg_type, _, _ in SIM_TOPICS + CAMERA_TOPICS
        }
        cls.tf_transforms = {}
        cls.node.create_subscription(TFMessage, "/tf", cls._on_tf, 100)
        static_qos = QoSProfile(depth=100, durability=rclpy.qos.DurabilityPolicy.TRANSIENT_LOCAL)
        cls.node.create_subscription(TFMessage, "/tf_static", cls._on_tf, static_qos)
        cls.command = cls.node.create_publisher(Twist, "/final_cmd", 1)
        cls.spin_thread.start()
        deadline = time.monotonic() + 30.0
        while time.monotonic() < deadline:
            if all(p.count > 0 for p in cls.probes.values()):
                break
            time.sleep(0.2)

    @classmethod
    def tearDownClass(cls):
        cls.executor_.shutdown()
        cls.node.destroy_node()
        rclpy.shutdown()

    @classmethod
    def _on_tf(cls, msg):
        for t in msg.transforms:
            cls.tf_transforms[(t.header.frame_id, t.child_frame_id)] = t

    def set_parameter(self, node_name, name, value):
        client = self.node.create_client(SetParameters, f"/{node_name}/set_parameters")
        self.assertTrue(client.wait_for_service(timeout_sec=5.0))
        param = Parameter(name=name)
        if isinstance(value, str):
            param.value = ParameterValue(type=ParameterType.PARAMETER_STRING, string_value=value)
        else:
            param.value = ParameterValue(type=ParameterType.PARAMETER_DOUBLE, double_value=value)
        future = client.call_async(SetParameters.Request(parameters=[param]))
        deadline = time.monotonic() + 5.0
        while not future.done() and time.monotonic() < deadline:
            time.sleep(0.01)
        self.assertTrue(future.result().results[0].successful, name)

    def drive(self, linear, angular, seconds):
        twist = Twist()
        twist.linear.x = linear
        twist.angular.z = angular
        deadline = time.monotonic() + seconds
        while time.monotonic() < deadline:
            self.command.publish(twist)
            time.sleep(0.02)

    def forward_obstacle_range(self):
        cloud = self.probes["/velodyne_points"].last()
        nearest = math.inf
        for row in range(0, cloud.height):
            for column in range(cloud.width):
                offset = (row * cloud.width + column) * cloud.point_step
                x, y, z = struct.unpack_from("<fff", cloud.data, offset)
                if not math.isnan(x) and x > 0.0 and abs(y) < 0.3 and -0.6 < z < 0.2:
                    nearest = min(nearest, x)
        return nearest

    def test_1_every_topic_has_the_real_frame_and_rate(self):
        probes = self.probes
        counts = {topic: probe.count for topic, probe in probes.items()}
        time.sleep(SAMPLE_SECONDS)
        for topic, msg_type, frame, rate in SIM_TOPICS + CAMERA_TOPICS:
            with self.subTest(topic=topic):
                self.assertIsNotNone(probes[topic].last_raw, "no message")
                measured = (probes[topic].count - counts[topic]) / SAMPLE_SECONDS
                print(f"RATE {topic} measured {measured:.1f} target {rate:.1f}")
                self.assertLess(abs(measured - rate) / rate, RATE_TOLERANCE)
                if frame is not None:
                    self.assertEqual(probes[topic].last().header.frame_id, frame)

    def test_2_images_have_the_real_format(self):
        for topic, (width, height, encoding) in IMAGE_FORMATS.items():
            with self.subTest(topic=topic):
                image = self.probes[topic].last()
                self.assertEqual(
                    (image.width, image.height, image.encoding), (width, height, encoding)
                )
                self.assertEqual(len(image.data), image.step * image.height)

    def test_3_cloud_has_the_real_layout(self):
        cloud = self.probes["/velodyne_points"].last()
        self.assertEqual((cloud.width, cloud.height, cloud.point_step), (32, 1812, 22))
        self.assertEqual(
            [(f.name, f.offset, f.datatype) for f in cloud.fields],
            [
                ("x", 0, 7),
                ("y", 4, 7),
                ("z", 8, 7),
                ("intensity", 12, 7),
                ("ring", 16, 4),
                ("time", 18, 7),
            ],
        )
        self.assertFalse(cloud.is_dense)

    def test_4_tf_tree_reaches_every_sensor(self):
        time.sleep(1.0)
        pairs = set(self.tf_transforms)
        for pair in [
            ("map", "odom"),
            ("odom", "base_link"),
            ("base_link", "sensors_base_link"),
            ("sensors_base_link", "velodyne"),
            ("sensors_base_link", "vectornav"),
            ("sensors_base_link", "gnss_antenna"),
            ("sensors_base_link", "d435_left_color_optical_frame"),
            ("base_link", "cam0_camera_frame"),
            ("cam0_camera_frame", "cam0_camera_frame_optical"),
            ("base_link", "d435i_link"),
            ("base_link", "zed_camera_link"),
        ]:
            with self.subTest(pair=pair):
                self.assertIn(pair, pairs)

    def test_5_final_cmd_step_moves_pose_and_cloud(self):
        odom = self.probes["/odom"]
        truth = self.probes["/odometry/global"]
        status = self.probes["/hunter_status"]
        before_x = odom.last().pose.pose.position.x
        before_range = self.forward_obstacle_range()
        self.assertLess(before_range, 12.0)

        self.drive(1.0, 0.0, 3.0)
        self.assertGreater(status.last().linear_velocity, 0.9)
        self.drive(0.0, 0.0, 2.0)

        moved = odom.last().pose.pose.position.x - before_x
        self.assertGreater(moved, 2.0)
        self.assertAlmostEqual(truth.last().pose.pose.position.x, moved + before_x, delta=0.05)
        print(
            f"CLOSED_LOOP moved {moved:.3f} range {before_range:.3f} -> "
            f"{self.forward_obstacle_range():.3f}"
        )
        self.assertAlmostEqual(self.forward_obstacle_range(), before_range - moved, delta=0.15)

    def test_6_steering_turns_and_reports_central_angle(self):
        self.drive(0.5, 0.25, 1.5)
        status = self.probes["/hunter_status"].last()
        self.assertGreater(status.steering_angle, 0.05)
        self.assertGreater(self.probes["/odom"].last().twist.twist.angular.z, 0.1)
        self.drive(0.0, 0.0, 1.0)

    def test_7_dropout_stops_and_recovers(self):
        probe = self.probes["/vectornav/imu"]
        self.set_parameter("sensor_sim", "fault.imu.mode", "dropout")
        time.sleep(0.3)
        self.assertEqual(probe.rate(1.0), 0.0)
        self.set_parameter("sensor_sim", "fault.imu.mode", "none")
        self.assertGreater(probe.rate(1.0), 15.0)

    def test_8_nan_reaches_the_wire(self):
        self.set_parameter("sensor_sim", "fault.odom.mode", "nan")
        self.set_parameter("sensor_sim", "fault.lidar.mode", "nan")
        time.sleep(0.4)
        self.assertTrue(math.isnan(self.probes["/odom"].last().pose.pose.position.x))
        cloud = self.probes["/velodyne_points"].last()
        self.assertTrue(math.isnan(struct.unpack_from("<f", cloud.data, 0)[0]))
        self.set_parameter("sensor_sim", "fault.odom.mode", "none")
        self.set_parameter("sensor_sim", "fault.lidar.mode", "none")
        time.sleep(0.4)
        self.assertFalse(math.isnan(self.probes["/odom"].last().pose.pose.position.x))

    def test_9_freeze_keeps_values_while_stamps_advance(self):
        self.drive(1.0, 0.0, 1.0)
        self.set_parameter("sensor_sim", "fault.odom.mode", "freeze")
        time.sleep(0.1)
        first = self.probes["/odom"].last()
        self.drive(1.0, 0.0, 1.0)
        second = self.probes["/odom"].last()
        self.assertEqual(first.pose.pose.position.x, second.pose.pose.position.x)
        self.assertGreater(
            second.header.stamp.sec + second.header.stamp.nanosec * 1e-9,
            first.header.stamp.sec + first.header.stamp.nanosec * 1e-9 + 0.5,
        )
        self.set_parameter("sensor_sim", "fault.odom.mode", "none")
        self.drive(0.0, 0.0, 1.0)

    def test_a_latency_keeps_old_stamps(self):
        self.set_parameter("sensor_sim", "fault.gnss.latency_s", 0.5)
        self.set_parameter("sensor_sim", "fault.gnss.mode", "latency")
        time.sleep(1.0)
        message = self.probes["/ublox_gps_node/fix"].last()
        age = time.time() - (message.header.stamp.sec + message.header.stamp.nanosec * 1e-9)
        print(f"LATENCY age {age:.3f}")
        self.assertGreater(age, 0.45)
        self.assertLess(age, 0.7)
        self.set_parameter("sensor_sim", "fault.gnss.mode", "none")

    def test_b_camera_fault_is_per_camera(self):
        info = self.probes["/camera/d435i/color/camera_info"]
        self.set_parameter("d435i_dummy", "fault.mode", "dropout")
        time.sleep(0.2)
        self.assertEqual(info.rate(0.5), 0.0)
        self.assertGreater(self.probes["/cam0/zed_node/imu/data"].rate(0.5), 50.0)
        self.set_parameter("d435i_dummy", "fault.mode", "none")
        self.assertGreater(info.rate(0.5), 15.0)

    def test_c_vehicle_config_matches_hunter_params(self):
        with open(HUNTER_PARAMS) as f:
            header = f.read()
        block = header[
            header.index("struct HunterV2Params") : header.index("struct HunterV1Params")
        ]
        real = {
            name: float(value)
            for name, value in re.findall(r"constexpr double (\w+) = ([\d.]+);", block)
        }
        with open(os.path.join(SHARE, "config", "sensor_sim.param.yaml")) as f:
            vehicle = yaml.safe_load(f)["/**"]["ros__parameters"]["vehicle"]
        for name in (
            "track",
            "wheelbase",
            "wheel_radius",
            "transmission_reduction_rate",
            "max_steer_angle",
            "max_linear_speed",
        ):
            self.assertEqual(vehicle[name], real[name], name)

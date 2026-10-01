#!/usr/bin/env python3
"""Check that the VLP-32C, the three D435 color images and their depth agree.

Uses only what is installed on the SCV: the TF from hunter2_description
(robot.urdf.xacro -> tf_mounts.xacro, frames d435_*_color_optical_frame) and
the streams of bring_up/launch/d435_tri.launch.py (upright images from the
180-degree rotation filter). For every ChArUco board a camera sees it reports

  * lidar_to_plane_mean_mm   lidar points vs. camera-estimated board plane
                             (depth direction; + = lidar behind the board)
  * depth_to_plane_mean_mm   D435 aligned depth vs. the same plane
  * pattern_contrast_at_0    lidar-intensity checkerboard match (black squares
                             return low intensity); ~0.9+ means aligned
  * lidar_should_move_right/down_mm   in-plane shift that maximises the match
  * depth_minus_lidar_median_pct      whole-image depth vs. lidar

and writes <out_dir>/<camera>.jpg (lidar coloured by range | depth overlay)
plus <out_dir>/report.yaml.

Usage on the SCV, with velodyne + d435_tri (or sensors_start) running in the
same ROS_DOMAIN_ID and boards standing in front of the cameras:

    source ~/SCV/install/setup.bash
    python3 ~/SCV/tools/scv_alignment_check.py            # -> ./alignment_check
    python3 ~/SCV/tools/scv_alignment_check.py <board_params.yaml> <out_dir>

Note: the VLP-32C range drifts ~1 cm per 20-30 min after power-on; compare
depth-direction numbers only after the lidar has warmed up (~1 h).
"""

import os
import subprocess
import sys
import threading
import time
import xml.etree.ElementTree as ET

import cv2
import numpy as np
import rclpy
import yaml
from cv_bridge import CvBridge
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from scipy.spatial.transform import Rotation
from sensor_msgs.msg import CameraInfo, Image, PointCloud2
from sensor_msgs_py import point_cloud2

CAMS = ("left", "center", "right")


def urdf_tf():
    """sensors_base_link -> child transforms from the installed robot model."""
    pkg = subprocess.check_output(["ros2", "pkg", "prefix", "hunter2_description"], text=True).strip()
    urdf = subprocess.check_output(
        ["xacro", f"{pkg}/share/hunter2_description/urdf/robot.urdf.xacro"], text=True)
    T = {}
    for j in ET.fromstring(urdf).findall("joint"):
        if j.find("parent").get("link") != "sensors_base_link":
            continue
        o = j.find("origin")
        M = np.eye(4)
        M[:3, :3] = Rotation.from_euler("xyz", [float(v) for v in o.get("rpy").split()]).as_matrix()
        M[:3, 3] = [float(v) for v in o.get("xyz").split()]
        T[j.find("child").get("link")] = M
    return T


def boards_from(path):
    p = yaml.safe_load(open(path))
    A = cv2.aruco
    D = A.getPredefinedDictionary(getattr(A, p["aruco_dict"]))
    n = (p["squares_x"] * p["squares_y"]) // 2
    out = {}
    for b in p["boards"]:
        ids = np.arange(b * p["id_stride"], b * p["id_stride"] + n, dtype=np.int32).reshape(-1, 1)
        bd = A.CharucoBoard((p["squares_x"], p["squares_y"]), p["square_length_m"],
                            p["marker_length_m"], D, ids)
        out[b] = (A.CharucoDetector(bd), np.asarray(bd.getChessboardCorners()).reshape(-1, 3),
                  p["squares_x"] * p["square_length_m"], p["squares_y"] * p["square_length_m"])
    return out


class Grab(Node):
    def __init__(self):
        super().__init__("scv_alignment_check")
        self.lock = threading.Lock()
        self.m = {}
        self.scans = []
        for c in CAMS:
            base = f"/d435_{c}/d435_{c}"
            for k, t, typ in (("color", f"{base}/color/image_raw", Image),
                              ("depth", f"{base}/aligned_depth_to_color/image_raw", Image),
                              ("info", f"{base}/color/camera_info", CameraInfo)):
                self.create_subscription(typ, t, lambda msg, key=(c, k): self._put(key, msg),
                                         qos_profile_sensor_data)
        self.create_subscription(PointCloud2, "/velodyne_points", self._lidar, qos_profile_sensor_data)

    def _put(self, key, msg):
        with self.lock:
            self.m[key] = msg

    def _lidar(self, msg):
        r = point_cloud2.read_points(msg, field_names=("x", "y", "z", "intensity"), skip_nans=True)
        with self.lock:
            self.scans.append(np.stack([r["x"], r["y"], r["z"], r["intensity"]], 1).astype(np.float64))
            self.scans = self.scans[-10:]


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    board_params = sys.argv[1] if len(sys.argv) > 1 else os.path.join(here, "charuco_board_params.yaml")
    out_dir = sys.argv[2] if len(sys.argv) > 2 else "alignment_check"
    os.makedirs(out_dir, exist_ok=True)
    T_sb = urdf_tf()
    T_vel = T_sb["velodyne"]
    boards = boards_from(board_params)
    rclpy.init()
    node = Grab()
    threading.Thread(target=rclpy.spin, args=(node,), daemon=True).start()
    t0 = time.time()
    while time.time() - t0 < 30:
        with node.lock:
            ok = len(node.scans) >= 10 and all((c, k) in node.m for c in CAMS
                                              for k in ("color", "depth", "info"))
        if ok:
            break
        time.sleep(0.2)
    br = CvBridge()
    with node.lock:
        m, lidar4 = dict(node.m), np.concatenate(node.scans)
    lidar, lint = lidar4[:, :3], lidar4[:, 3]
    print(f"lidar points stacked: {len(lidar)}")
    report = {}
    for c in CAMS:
        if (c, "color") not in m:
            print(f"[{c}] no color"); continue
        img = br.imgmsg_to_cv2(m[(c, "color")], "bgr8")
        dep = br.imgmsg_to_cv2(m[(c, "depth")], "passthrough").astype(np.float64) * 1e-3 \
            if (c, "depth") in m else None
        info = m[(c, "info")]
        h, w = img.shape[:2]
        K = np.array(info.k).reshape(3, 3).copy()
        # rotation_filter 180: CameraInfo is still the native one -> mirror cx, cy.
        K[0, 2], K[1, 2] = (w - 1) - K[0, 2], (h - 1) - K[1, 2]
        Dc = np.zeros(5)
        T_lc = np.linalg.inv(T_vel) @ T_sb[f"d435_{c}_color_optical_frame"]   # velodyne <- cam
        Pc = (lidar - T_lc[:3, 3]) @ T_lc[:3, :3]                             # lidar in cam frame
        keep = (Pc[:, 2] > 0.3) & (Pc[:, 2] < 8.0)
        Pc, Ic = Pc[keep], lint[keep]
        uv = (Pc[:, :2] / Pc[:, 2:3]) * [K[0, 0], K[1, 1]] + [K[0, 2], K[1, 2]]
        inside = (uv[:, 0] >= 0) & (uv[:, 0] < w) & (uv[:, 1] >= 0) & (uv[:, 1] < h)
        uv, Pin = uv[inside], Pc[inside]
        res = {"boards": []}
        # lidar vs depth at the same pixels
        if dep is not None and dep.shape == (h, w):
            ui, vi = uv[:, 0].astype(int), uv[:, 1].astype(int)
            dz = dep[vi, ui]
            v = dz > 0.2
            diff = (dz[v] - Pin[v, 2])
            rel = diff / Pin[v, 2]
            res["depth_minus_lidar_median_mm"] = round(float(np.median(diff)) * 1000, 1)
            res["depth_minus_lidar_median_pct"] = round(float(np.median(rel)) * 100, 2)
            res["depth_vs_lidar_pairs"] = int(v.sum())
        # boards
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        for b, (det, c3, sx, sy) in boards.items():
            cc, ids, _, _ = det.detectBoard(gray)
            if ids is None or len(ids) < 8:
                continue
            ok, rv, tv = cv2.solvePnP(c3[ids.ravel()], cc, K, Dc, flags=cv2.SOLVEPNP_IPPE)
            R = cv2.Rodrigues(rv)[0]
            pb = (Pc - tv.ravel()) @ R                                         # lidar in board frame
            inb = (pb[:, 0] > 0.03) & (pb[:, 0] < sx - 0.03) & (pb[:, 1] > 0.03) & \
                  (pb[:, 1] < sy - 0.03) & (np.abs(pb[:, 2]) < 0.15)
            entry = {"board": int(b), "dist_m": round(float(np.linalg.norm(tv)), 2),
                     "lidar_pts": int(inb.sum())}
            # In-plane check: lidar points on the board plane (incl. its white
            # margin) -> centre of their extent vs the printed grid centre.
            # x = along the board's long side, y = along its short side.
            # Horizontal lidar resolution is fine; vertical is ring-quantised.
            onp = (np.abs(pb[:, 2]) < 0.04) & (pb[:, 0] > -0.12) & (pb[:, 0] < sx + 0.12) & \
                  (pb[:, 1] > -0.12) & (pb[:, 1] < sy + 0.12)
            if onp.sum() >= 30:
                q = pb[onp]
                lo, hi = np.percentile(q[:, :2], 1, axis=0), np.percentile(q[:, :2], 99, axis=0)
                entry["lidar_extent_x_mm"] = [round(float(lo[0]) * 1000), round(float(hi[0]) * 1000)]
                entry["lidar_extent_y_mm"] = [round(float(lo[1]) * 1000), round(float(hi[1]) * 1000)]
                entry["inplane_center_offset_mm"] = [
                    round(float((lo[0] + hi[0]) / 2 - sx / 2) * 1000, 1),
                    round(float((lo[1] + hi[1]) / 2 - sy / 2) * 1000, 1)]
                # direction of board x/y axes in the image (to read the offset)
                ex = R[:, 0]; ey = R[:, 1]
                entry["board_x_axis_in_cam"] = [round(float(v), 2) for v in ex]
                entry["board_y_axis_in_cam"] = [round(float(v), 2) for v in ey]
            if inb.sum() >= 10:
                entry["lidar_to_plane_mean_mm"] = round(float(np.mean(pb[inb, 2])) * 1000, 1)
                entry["lidar_to_plane_rms_mm"] = round(float(np.sqrt(np.mean(pb[inb, 2] ** 2))) * 1000, 1)
            if dep is not None and dep.shape == (h, w):
                g = np.stack(np.meshgrid(np.linspace(.1 * sx, .9 * sx, 15),
                                         np.linspace(.1 * sy, .9 * sy, 11)), -1).reshape(-1, 2)
                P = np.c_[g, np.zeros(len(g))] @ R.T + tv.ravel()
                q = (P[:, :2] / P[:, 2:3]) * [K[0, 0], K[1, 1]] + [K[0, 2], K[1, 2]]
                ok2 = (q[:, 0] >= 0) & (q[:, 0] < w) & (q[:, 1] >= 0) & (q[:, 1] < h)
                z = dep[q[ok2, 1].astype(int), q[ok2, 0].astype(int)]
                vv = z > 0.2
                if vv.sum() > 20:
                    rays = np.c_[(q[ok2][vv] - [K[0, 2], K[1, 2]]) / [K[0, 0], K[1, 1]], np.ones(vv.sum())]
                    Pd = rays * z[vv, None]
                    dd = (Pd - tv.ravel()) @ R[:, 2]
                    entry["depth_to_plane_mean_mm"] = round(float(np.mean(dd)) * 1000, 1)
            # in-plane offset from the intensity pattern (black squares are dark)
            sq = sx / 7.0
            near = (np.abs(pb[:, 2]) < 0.04) & (pb[:, 0] > -0.1) & (pb[:, 0] < sx + 0.1) & \
                   (pb[:, 1] > -0.1) & (pb[:, 1] < sy + 0.1)
            if near.sum() >= 200:
                Pm, im = Pc[near], Ic[near]
                im = (im - im.mean()) / (im.std() + 1e-9)
                sh = np.arange(-0.08, 0.0801, 0.005)
                best, c0 = (-9, 0, 0), None
                for dx in sh:
                    for dy in sh:
                        q = (Pm + [dx, dy, 0] - tv.ravel()) @ R
                        x, y = q[:, 0], q[:, 1]
                        ins = (x > .005) & (x < sx - .005) & (y > .005) & (y < sy - .005)
                        blk = ((np.floor(x / sq) + np.floor(y / sq)) % 2 == 0) & ins
                        wht = (~blk) & ins
                        if blk.sum() < 20 or wht.sum() < 20:
                            continue
                        cval = im[wht].mean() - im[blk].mean()
                        if abs(dx) < 1e-9 and abs(dy) < 1e-9:
                            c0 = cval
                        if cval > best[0]:
                            best = (cval, dx, dy)
                # upright optical frame: +x = image right, +y = image down
                entry["pattern_contrast_at_0"] = round(float(c0), 2) if c0 is not None else None
                entry["pattern_best_contrast"] = round(float(best[0]), 2)
                entry["lidar_should_move_right_mm"] = round(best[1] * 1000)
                entry["lidar_should_move_down_mm"] = round(best[2] * 1000)
            res["boards"].append(entry)
        report[c] = res
        # overlay: lidar coloured by range, plus a depth panel
        ov = img.copy()
        col = cv2.applyColorMap(np.clip(Pin[:, 2] / 8 * 255, 0, 255).astype(np.uint8).reshape(-1, 1),
                                cv2.COLORMAP_JET).reshape(-1, 3)
        for (u, v_), cl in zip(uv.astype(int), col):
            cv2.circle(ov, (u, v_), 1, tuple(int(x) for x in cl), -1)
        panels = [ov]
        if dep is not None and dep.shape == (h, w):
            dv = cv2.applyColorMap(np.clip(dep / 8 * 255, 0, 255).astype(np.uint8), cv2.COLORMAP_JET)
            dv[dep <= 0] = 0
            panels.append(cv2.addWeighted(img, 0.5, dv, 0.5, 0))
        cv2.imwrite(os.path.join(out_dir, f"{c}.jpg"), cv2.hconcat([cv2.resize(p, (960, 540)) for p in panels]))
        print(f"[{c}] {res}")
    yaml.safe_dump(report, open(os.path.join(out_dir, "report.yaml"), "w"), sort_keys=False)
    rclpy.shutdown()


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""baseline vs FGO 결과 bag 비교 평가.

usage: evaluate.py <fgo_bag_dir> [baseline_bag_dir] [--out out.png]

지표:
  - RTK 기준 절대오차: raw σ<0.05 인 /gps/coarse_position 을 준-GT 로 |/global_pose - GT|
  - map->odom 점프 (>0.3 m 연속 델타)
  - /fgo/gps_bias 궤적 (FGO), /localization/mode 분포 (baseline)
  - 궤적/불일치 플롯
"""
import argparse
import math
import os
import sqlite3

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
from rclpy.serialization import deserialize_message
from geometry_msgs.msg import PointStamped, PoseWithCovarianceStamped, TransformStamped
from nav_msgs.msg import Odometry
from std_msgs.msg import String


def open_bag(bag_dir):
    db = [f for f in os.listdir(bag_dir) if f.endswith(".db3")]
    conn = sqlite3.connect(f"file:{os.path.join(bag_dir, db[0])}?mode=ro", uri=True)
    cur = conn.cursor()
    topics = {n: i for i, n, t in cur.execute("SELECT id,name,type FROM topics")}
    t0 = cur.execute("SELECT MIN(timestamp) FROM messages").fetchone()[0]
    return cur, topics, t0


def read(cur, topics, t0, topic, msgtype, stamp_from_header=True):
    if topic not in topics:
        return []
    out = []
    for ts, data in cur.execute(
            "SELECT timestamp, data FROM messages WHERE topic_id=? ORDER BY timestamp",
            (topics[topic],)):
        m = deserialize_message(data, msgtype)
        if stamp_from_header and hasattr(m, "header"):
            t = m.header.stamp.sec + m.header.stamp.nanosec * 1e-9
        else:
            t = (ts - t0) / 1e9
        out.append((t, m))
    return out


def yaw_of(q):
    return math.atan2(2 * (q.w * q.z + q.x * q.y), 1 - 2 * (q.y * q.y + q.z * q.z))


def analyze(bag_dir, label):
    cur, topics, t0 = open_bag(bag_dir)
    r = {"label": label}

    gp = read(cur, topics, t0, "/global_pose", Odometry)
    r["gp_t"] = np.array([t for t, _ in gp])
    r["gp_x"] = np.array([m.pose.pose.position.x for _, m in gp])
    r["gp_y"] = np.array([m.pose.pose.position.y for _, m in gp])

    coarse = read(cur, topics, t0, "/gps/coarse_position", PoseWithCovarianceStamped)
    r["gps_t"] = np.array([t for t, _ in coarse])
    r["gps_x"] = np.array([m.pose.pose.position.x for _, m in coarse])
    r["gps_y"] = np.array([m.pose.pose.position.y for _, m in coarse])
    r["gps_sigma"] = np.array(
        [math.sqrt(max(m.pose.covariance[0], 0.0)) for _, m in coarse])

    mt = read(cur, topics, t0, "/localization/map_to_odom", TransformStamped)
    r["mt_t"] = np.array([t for t, _ in mt])
    r["mt_x"] = np.array([m.transform.translation.x for _, m in mt])
    r["mt_y"] = np.array([m.transform.translation.y for _, m in mt])

    pcd = read(cur, topics, t0, "/pcd/global_pose", Odometry)
    r["pcd_t"] = np.array([t for t, _ in pcd])
    r["pcd_x"] = np.array([m.pose.pose.position.x for _, m in pcd])
    r["pcd_y"] = np.array([m.pose.pose.position.y for _, m in pcd])
    r["pcd_has_cov"] = np.array([m.pose.covariance[35] > 0 for _, m in pcd])

    bias = read(cur, topics, t0, "/fgo/gps_bias", PointStamped)
    r["bias_t"] = np.array([t for t, _ in bias])
    r["bias_x"] = np.array([m.point.x for _, m in bias])
    r["bias_y"] = np.array([m.point.y for _, m in bias])

    r["mode"] = [(t, m.data) for t, m in read(
        cur, topics, t0, "/localization/mode", String, stamp_from_header=False)]
    r["fgo_status"] = [(t, m.data) for t, m in read(
        cur, topics, t0, "/fgo/status", String, stamp_from_header=False)]
    return r


def rtk_error(r):
    """raw σ<0.05 GPS 를 준-GT 로 global_pose 오차."""
    rtk = r["gps_sigma"] < 0.05
    if rtk.sum() < 5 or len(r["gp_t"]) < 2:
        return None
    tr, xr, yr = r["gps_t"][rtk], r["gps_x"][rtk], r["gps_y"][rtk]
    xi = np.interp(tr, r["gp_t"], r["gp_x"])
    yi = np.interp(tr, r["gp_t"], r["gp_y"])
    # global_pose 가 존재하는 시간 범위 내로 제한
    ok = (tr >= r["gp_t"][0]) & (tr <= r["gp_t"][-1])
    return np.hypot(xi[ok] - xr[ok], yi[ok] - yr[ok]), tr[ok]


def jumps(r, thresh=0.3):
    if len(r["mt_t"]) < 2:
        return []
    d = np.hypot(np.diff(r["mt_x"]), np.diff(r["mt_y"]))
    idx = np.where(d > thresh)[0]
    return [(r["mt_t"][i + 1], d[i]) for i in idx]


def report(r):
    print(f"\n===== {r['label']} =====")
    print(f"global_pose n={len(r['gp_t'])}, "
          f"pcd msgs={len(r['pcd_t'])} (scan-match={int(r['pcd_has_cov'].sum())})")
    e = rtk_error(r)
    if e is not None:
        err, _ = e
        print(f"RTK(σ<0.05) 준-GT 오차: n={len(err)}, p50={np.percentile(err,50):.3f} "
              f"p90={np.percentile(err,90):.3f} max={err.max():.3f} m")
    else:
        print("RTK 준-GT 오차: RTK 샘플 부족")
    j = jumps(r)
    print(f"map->odom 점프(>0.3m): {len(j)}회" +
          (f", 최대 {max(d for _, d in j):.2f} m" if j else ""))
    if len(r["bias_t"]):
        print(f"gps_bias 최종: ({r['bias_x'][-1]:+.2f}, {r['bias_y'][-1]:+.2f}) m, "
              f"|{math.hypot(r['bias_x'][-1], r['bias_y'][-1]):.2f}|")
    if r["mode"]:
        from collections import Counter
        trans = sum(1 for i in range(1, len(r["mode"]))
                    if r["mode"][i][1] != r["mode"][i - 1][1])
        print(f"mode 전환 {trans}회, 분포 {dict(Counter(m for _, m in r['mode']))}")
    if r["fgo_status"]:
        print(f"fgo status 이력: {[(round(t,1), s) for t, s in r['fgo_status'][:10]]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("fgo_bag")
    ap.add_argument("baseline_bag", nargs="?")
    ap.add_argument("--out", default="eval_compare.png")
    args = ap.parse_args()

    runs = [analyze(args.fgo_bag, "FGO")]
    if args.baseline_bag:
        runs.append(analyze(args.baseline_bag, "baseline"))
    for r in runs:
        report(r)

    fig, axes = plt.subplots(2, 2, figsize=(16, 10))
    ax = axes[0][0]
    colors = {"FGO": "#2ca02c", "baseline": "#d62728"}
    for r in runs:
        ax.plot(r["gp_x"], r["gp_y"], lw=1.0, color=colors[r["label"]],
                label=f"{r['label']} /global_pose")
    r0 = runs[0]
    good = r0["gps_sigma"] < 0.5
    ax.plot(r0["gps_x"][good], r0["gps_y"][good], ".", ms=1.5, color="#1f77b4",
            alpha=0.4, label="raw GPS (σ<0.5)")
    rtk = r0["gps_sigma"] < 0.05
    ax.plot(r0["gps_x"][rtk], r0["gps_y"][rtk], ".", ms=3, color="k",
            label="raw GPS RTK (σ<0.05)")
    ax.set_aspect("equal"); ax.grid(alpha=0.3); ax.legend(fontsize=8)
    ax.set_title("trajectories (map frame)")

    ax = axes[0][1]
    for r in runs:
        e = rtk_error(r)
        if e is not None:
            err, tr = e
            ax.plot(tr - tr[0], err, ".", ms=3, color=colors[r["label"]],
                    label=f"{r['label']} |gp - RTK|")
    ax.grid(alpha=0.3); ax.legend(fontsize=8); ax.set_xlabel("t [s]")
    ax.set_title("error vs RTK quasi-GT [m]")

    ax = axes[1][0]
    for r in runs:
        if len(r["mt_t"]) > 1:
            d = np.hypot(np.diff(r["mt_x"]), np.diff(r["mt_y"]))
            ax.plot(r["mt_t"][1:] - r["mt_t"][0], d, lw=0.8,
                    color=colors[r["label"]], label=f"{r['label']} Δmap→odom")
    ax.axhline(0.3, color="r", ls="--", lw=0.8)
    ax.set_yscale("log"); ax.grid(alpha=0.3); ax.legend(fontsize=8)
    ax.set_xlabel("t [s]"); ax.set_title("map→odom step size [m] (log)")

    ax = axes[1][1]
    if len(r0["bias_t"]):
        tb = r0["bias_t"] - r0["bias_t"][0]
        ax.plot(tb, r0["bias_x"], label="bias x", color="#9467bd")
        ax.plot(tb, r0["bias_y"], label="bias y", color="#8c564b")
        ax.grid(alpha=0.3); ax.legend(fontsize=8); ax.set_xlabel("t [s]")
    ax.set_title("FGO estimated GPS bias [m]")

    fig.tight_layout()
    fig.savefig(args.out, dpi=110)
    print(f"\nsaved: {args.out}")


if __name__ == "__main__":
    main()

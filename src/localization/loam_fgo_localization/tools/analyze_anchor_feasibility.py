#!/usr/bin/env python3
"""Event-based anchoring localization feasibility analysis from rosbag2 recordings.

Reads a rosbag2 directory directly with rosbag2_py (no playback) and reports:
  Metric 1: RTK availability ratio, flapping, RTK / non-RTK segment length distributions
  Metric 2: PCD registration error vs RTK-interpolated position (accepted matches only)
            NOTE: includes ~0.2 m antenna-to-lidar horizontal offset (uncompensated)
  Metric 3: absolute-measurement gap analysis (RTK_FIXED + accepted PCD), drift budget

RTK_FIXED convention:
  /gps/measurement (PoseWithCovarianceStamped, already in map frame):
      pose.covariance[14] >= 1.5   (repo convention: 2.0 = RTK_FIXED, 1.0 = FLOAT)
  /ublox_gps_node/fix (NavSatFix) fallback:
      status.status >= 2 and sqrt(position_covariance[0]) < 0.05
      position converted to map frame via UTM zone 52N minus datum.

Usage:
  source /opt/ros/humble/setup.bash
  python3 analyze_anchor_feasibility.py /path/to/bag_dir [--window 1.0] [--drift-rate 0.5/60]
"""
import argparse
import glob
import math
import os
import sqlite3
import sys

from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message

# map-frame datum: UTM 52N easting/northing subtracted from raw fixes
DATUM_E = 482278.2382001437
DATUM_N = 3974410.5352799334

GPS_MEAS_TOPIC = '/gps/measurement'
FIX_TOPIC = '/ublox_gps_node/fix'
PCD_TOPIC = '/pcd/global_pose'


def stamp_to_sec(stamp):
    return stamp.sec + stamp.nanosec * 1e-9


def percentile(sorted_vals, p):
    if not sorted_vals:
        return float('nan')
    if len(sorted_vals) == 1:
        return sorted_vals[0]
    k = (len(sorted_vals) - 1) * p / 100.0
    f = math.floor(k)
    c = min(f + 1, len(sorted_vals) - 1)
    return sorted_vals[f] + (sorted_vals[c] - sorted_vals[f]) * (k - f)


def dist_stats(vals):
    s = sorted(vals)
    return {
        'n': len(s),
        'mean': (sum(s) / len(s)) if s else float('nan'),
        'p50': percentile(s, 50),
        'p95': percentile(s, 95),
        'max': s[-1] if s else float('nan'),
    }


def make_utm_converter():
    """Return fn(lat, lon) -> (map_x, map_y). Uses pyproj if present, else a
    standard Karney/Kruger-series UTM formula (sub-mm agreement with pyproj)."""
    try:
        from pyproj import Transformer
        tr = Transformer.from_crs('EPSG:4326', 'EPSG:32652', always_xy=True)

        def conv(lat, lon):
            e, n = tr.transform(lon, lat)
            return e - DATUM_E, n - DATUM_N
        return conv, 'pyproj EPSG:32652'
    except ImportError:
        pass

    # WGS84 / UTM zone 52N (central meridian 129E), transverse Mercator series
    a = 6378137.0
    f_ = 1 / 298.257223563
    k0 = 0.9996
    E0, N0 = 500000.0, 0.0
    lon0 = math.radians(129.0)
    n = f_ / (2 - f_)
    n2, n3, n4 = n * n, n ** 3, n ** 4
    A = a / (1 + n) * (1 + n2 / 4 + n4 / 64)
    alpha = [
        n / 2 - 2 * n2 / 3 + 5 * n3 / 16,
        13 * n2 / 48 - 3 * n3 / 5,
        61 * n3 / 240,
    ]

    def conv(lat, lon):
        phi = math.radians(lat)
        lam = math.radians(lon) - lon0
        t = math.sinh(math.atanh(math.sin(phi))
                      - (2 * math.sqrt(n) / (1 + n)) * math.atanh(2 * math.sqrt(n) / (1 + n) * math.sin(phi)))
        xi_p = math.atan2(t, math.cos(lam))
        eta_p = math.atanh(math.sin(lam) / math.sqrt(1 + t * t))
        xi = xi_p
        eta = eta_p
        for j, aj in enumerate(alpha, start=1):
            xi += aj * math.sin(2 * j * xi_p) * math.cosh(2 * j * eta_p)
            eta += aj * math.cos(2 * j * xi_p) * math.sinh(2 * j * eta_p)
        easting = E0 + k0 * A * eta
        northing = N0 + k0 * A * xi
        return easting - DATUM_E, northing - DATUM_N
    return conv, 'builtin transverse-Mercator series (UTM 52N)'


def merge_windows(stamps, window, t0, t1):
    """Union of [s, s+window] intervals clipped to [t0, t1]; returns merged list."""
    merged = []
    for s in stamps:
        lo, hi = max(s, t0), min(s + window, t1)
        if hi <= lo:
            continue
        if merged and lo <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], hi)
        else:
            merged.append([lo, hi])
    return merged


def fmt_stats(st, unit='s'):
    if st['n'] == 0:
        return 'n=0'
    return (f"n={st['n']}  mean={st['mean']:.3f}{unit}  p50={st['p50']:.3f}{unit}  "
            f"p95={st['p95']:.3f}{unit}  max={st['max']:.3f}{unit}")


def metadata_duration(bag_path):
    """Bag duration in seconds from metadata.yaml (None if unreadable)."""
    try:
        import yaml
        with open(os.path.join(bag_path, 'metadata.yaml')) as f:
            m = yaml.safe_load(f)['rosbag2_bagfile_information']
        return m['duration']['nanoseconds'] * 1e-9
    except Exception:
        return None


def iter_messages_sqlite(db_files, wanted):
    """Yield (topic_name, raw_data) for wanted topics, reading .db3 directly.

    rosbag2's messages table has no topic_id index, so a filtered read via
    rosbag2_py scans every blob. A direct table scan that only materializes
    matching rows skips the overflow pages of large (lidar/camera) blobs and
    is much faster on multi-GB bags. Order is rowid order (chronological per
    file); callers must sort by header stamp anyway.
    """
    for db in db_files:
        con = sqlite3.connect(f'file:{db}?mode=ro&immutable=1', uri=True)
        try:
            topics = {name: tid for tid, name in
                      con.execute('SELECT id, name FROM topics')}
            ids = {topics[t]: t for t in wanted if t in topics}
            if not ids:
                continue
            ph = ','.join('?' * len(ids))
            cur = con.execute(
                f'SELECT topic_id, data FROM messages WHERE topic_id IN ({ph})',
                list(ids))
            for tid, data in cur:
                yield ids[tid], data
        finally:
            con.close()


def iter_messages_rosbag2py(bag_path, wanted):
    """Fallback reader (mcap etc.) via rosbag2_py with a topic filter."""
    from rosbag2_py import (SequentialReader, StorageOptions, ConverterOptions,
                            StorageFilter)
    reader = SequentialReader()
    reader.open(StorageOptions(uri=bag_path, storage_id=''),
                ConverterOptions(input_serialization_format='cdr',
                                 output_serialization_format='cdr'))
    reader.set_filter(StorageFilter(topics=list(wanted)))
    while reader.has_next():
        topic, data, _ = reader.read_next()
        yield topic, data


def topic_types(bag_path):
    """{topic: type} without opening message data."""
    db_files = sorted(glob.glob(os.path.join(bag_path, '*.db3')))
    if db_files:
        out = {}
        for db in db_files:
            con = sqlite3.connect(f'file:{db}?mode=ro&immutable=1', uri=True)
            try:
                out.update({n: t for n, t in
                            con.execute('SELECT name, type FROM topics')})
            finally:
                con.close()
        return out, db_files
    from rosbag2_py import SequentialReader, StorageOptions, ConverterOptions
    reader = SequentialReader()
    reader.open(StorageOptions(uri=bag_path, storage_id=''),
                ConverterOptions(input_serialization_format='cdr',
                                 output_serialization_format='cdr'))
    return {t.name: t.type for t in reader.get_all_topics_and_types()}, None


def analyze(bag_path, window, drift_rate):
    try:
        avail, db_files = topic_types(bag_path)
    except Exception as e:
        print(f'=== Bag: {bag_path}')
        print(f'[ERROR] cannot open bag: {e}')
        return 1
    use_meas = GPS_MEAS_TOPIC in avail
    use_fix = (not use_meas) and FIX_TOPIC in avail
    has_pcd = PCD_TOPIC in avail

    wanted = []
    if use_meas:
        wanted.append(GPS_MEAS_TOPIC)
    if use_fix:
        wanted.append(FIX_TOPIC)
    if has_pcd:
        wanted.append(PCD_TOPIC)

    print(f'=== Bag: {bag_path}')
    if not wanted:
        print('[SKIP] none of the required topics present '
              f'({GPS_MEAS_TOPIC}, {FIX_TOPIC}, {PCD_TOPIC})')
        return 1
    gps_src = GPS_MEAS_TOPIC if use_meas else (FIX_TOPIC if use_fix else 'NONE')
    print(f'GPS source: {gps_src}   PCD topic: {"present" if has_pcd else "absent"}')

    msg_types = {t: get_message(avail[t]) for t in wanted}

    conv = None
    if use_fix:
        conv, conv_name = make_utm_converter()
        print(f'raw fix -> map conversion: {conv_name}, datum E={DATUM_E} N={DATUM_N}')

    gps = []          # (stamp, x, y, is_rtk)
    pcd_acc = []      # (stamp, x, y)
    pcd_total = 0
    fix_bands = {}    # diagnostic: (status, stddev band) -> count

    if db_files:
        source = iter_messages_sqlite(db_files, wanted)
    else:
        source = iter_messages_rosbag2py(bag_path, wanted)

    for topic, data in source:
        msg = deserialize_message(data, msg_types[topic])
        if topic == GPS_MEAS_TOPIC:
            s = stamp_to_sec(msg.header.stamp)
            is_rtk = msg.pose.covariance[14] >= 1.5
            p = msg.pose.pose.position
            gps.append((s, p.x, p.y, is_rtk))
        elif topic == FIX_TOPIC:
            s = stamp_to_sec(msg.header.stamp)
            if math.isnan(msg.latitude) or (msg.latitude == 0.0 and msg.longitude == 0.0):
                continue
            sd = math.sqrt(max(msg.position_covariance[0], 0.0))
            is_rtk = msg.status.status >= 2 and sd < 0.05
            band = '<0.05' if sd < 0.05 else ('<0.5' if sd < 0.5 else '>=0.5')
            key = (msg.status.status, band)
            fix_bands[key] = fix_bands.get(key, 0) + 1
            x, y = conv(msg.latitude, msg.longitude)
            gps.append((s, x, y, is_rtk))
        elif topic == PCD_TOPIC:
            pcd_total += 1
            if msg.pose.covariance[35] > 0:
                s = stamp_to_sec(msg.header.stamp)
                p = msg.pose.pose.position
                pcd_acc.append((s, p.x, p.y))

    if not gps and not pcd_acc:
        print('[SKIP] no usable messages on required topics')
        return 1

    gps.sort(key=lambda m: m[0])
    pcd_acc.sort(key=lambda m: m[0])
    all_stamps = [m[0] for m in gps] + [m[0] for m in pcd_acc]
    t0, t1 = min(all_stamps), max(all_stamps)
    duration = t1 - t0                      # span covered by analyzed topics
    bag_dur = metadata_duration(bag_path)   # whole-bag duration (all topics)
    rtk = [m for m in gps if m[3]]
    rtk_stamps = [m[0] for m in rtk]
    bd = f'{bag_dur:.1f}' if bag_dur else '?'
    print(f'analyzed-topic stamp span: {duration:.1f} s   whole-bag duration: {bd} s')
    print(f'gps msgs: {len(gps)} (RTK_FIXED: {len(rtk)})   '
          f'pcd msgs: {pcd_total} (accepted: {len(pcd_acc)})')
    if fix_bands:
        band_str = ', '.join(f'status={k[0]} sd{k[1]}: {v}'
                             for k, v in sorted(fix_bands.items()))
        print(f'fix diagnostic (status, sqrt(cov[0]) band): {band_str}')

    # ---------- Metric 1 ----------
    print(f'\n--- Metric 1: RTK availability & flapping (window = {window:.1f} s) ---')
    if not gps:
        print('  no GPS messages -> metric 1 unavailable')
    else:
        merged = merge_windows(rtk_stamps, window, t0, t1)
        covered = sum(hi - lo for lo, hi in merged)
        ratio = 100.0 * covered / duration if duration > 0 else float('nan')
        # transitions: each boundary strictly inside (t0, t1) is one state flip
        transitions = 0
        for lo, hi in merged:
            if lo > t0:
                transitions += 1
            if hi < t1:
                transitions += 1
        rtk_seg = [hi - lo for lo, hi in merged]
        non_seg = []
        prev = t0
        for lo, hi in merged:
            if lo - prev > 1e-9:
                non_seg.append(lo - prev)
            prev = hi
        if t1 - prev > 1e-9:
            non_seg.append(t1 - prev)
        print(f'  RTK available ("RTK fix within last {window:.0f} s"): '
              f'{ratio:.2f} % of analyzed span'
              + (f'  ({100.0 * covered / bag_dur:.2f} % of whole-bag duration)'
                 if bag_dur else ''))
        print(f'  RTK<->non-RTK transitions (flapping): {transitions}')
        print(f'  RTK segment lengths:     {fmt_stats(dist_stats(rtk_seg))}')
        print(f'  non-RTK segment lengths: {fmt_stats(dist_stats(non_seg))}')

    # ---------- Metric 2 ----------
    print('\n--- Metric 2: accepted PCD registration error vs RTK-interpolated position ---')
    print('  (NOTE: error includes ~0.2 m uncompensated antenna-to-lidar horizontal offset)')
    if not has_pcd:
        print('  /pcd/global_pose absent -> metric 2 unavailable')
    elif not pcd_acc:
        print('  no accepted PCD matches (covariance[35] > 0) -> metric 2 unavailable')
    elif not rtk:
        print('  no RTK_FIXED measurements -> metric 2 unavailable')
    else:
        errs = []
        import bisect
        for s, px, py in pcd_acc:
            i = bisect.bisect_left(rtk_stamps, s)
            prev = rtk[i - 1] if i > 0 else None
            nxt = rtk[i] if i < len(rtk) else None
            if prev is None or nxt is None:
                continue
            if s - prev[0] > 0.5 or nxt[0] - s > 0.5:
                continue
            if nxt[0] - prev[0] < 1e-9:
                gx, gy = prev[1], prev[2]
            else:
                w = (s - prev[0]) / (nxt[0] - prev[0])
                gx = prev[1] + w * (nxt[1] - prev[1])
                gy = prev[2] + w * (nxt[2] - prev[2])
            errs.append(math.hypot(px - gx, py - gy))
        st = dist_stats(errs)
        print(f'  accepted PCD with bracketing RTK (+-0.5 s): {st["n"]} / {len(pcd_acc)}')
        if st['n']:
            print(f'  2D error: mean={st["mean"]:.3f} m  p50={st["p50"]:.3f} m  '
                  f'p95={st["p95"]:.3f} m  max={st["max"]:.3f} m')

    # ---------- Metric 3 ----------
    print('\n--- Metric 3: absolute-measurement gap analysis (drift budget) ---')

    def gap_report(label, stamps):
        if len(stamps) < 2:
            print(f'  [{label}] fewer than 2 events -> no gap distribution')
            return
        gaps = [b - a for a, b in zip(stamps, stamps[1:])]
        st = dist_stats(gaps)
        over = {th: sum(1 for g in gaps if g > th) for th in (1, 5, 10, 30, 60)}
        print(f'  [{label}] events={len(stamps)}  gap p50={st["p50"]:.3f} s  '
              f'p95={st["p95"]:.3f} s  max={st["max"]:.3f} s')
        print(f'  [{label}] gaps over 1s/5s/10s/30s/60s: '
              f'{over[1]} / {over[5]} / {over[10]} / {over[30]} / {over[60]}')
        print(f'  [{label}] worst expected drift = max_gap * {drift_rate:.4f} m/s '
              f'= {st["max"] * drift_rate:.3f} m')
        print(f'  [{label}] first event at t+{stamps[0] - t0:.1f} s, '
              f'last event at t_end-{t1 - stamps[-1]:.1f} s')

    combined = sorted(rtk_stamps + [s for s, _, _ in pcd_acc])
    gap_report('RTK + accepted PCD', combined)
    gap_report('RTK only', rtk_stamps)
    print()
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('bags', nargs='+', help='rosbag2 directory path(s)')
    ap.add_argument('--window', type=float, default=1.0,
                    help='RTK availability window in seconds (default 1.0)')
    ap.add_argument('--drift-rate', type=float, default=0.5 / 60.0,
                    help='assumed odometry drift rate in m/s (default 0.5/60)')
    args = ap.parse_args()
    rc = 0
    for bag in args.bags:
        rc |= analyze(bag, args.window, args.drift_rate)
    return rc


if __name__ == '__main__':
    sys.exit(main())

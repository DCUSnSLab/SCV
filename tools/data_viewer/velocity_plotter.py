#!/usr/bin/env python3

import argparse
import math
import sqlite3
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, List, Tuple, Dict

import matplotlib.pyplot as plt
import numpy as np

try:
    from rosidl_runtime_py.utilities import get_message
    from rclpy.serialization import deserialize_message
except ImportError:
    get_message = None  # type: ignore
    deserialize_message = None  # type: ignore


ARDUINO_TOPIC = '/arduino_raw/speed_ms'
VEHICLE_TOPIC = '/vehicle_cmd'
GPS_TOPIC = '/ublox_gps_node/fix_velocity'


@dataclass(slots=True)
class Series:
    t: List[float]
    v: List[float]

    def add(self, ts: float, val: float) -> None:
        self.t.append(ts)
        self.v.append(val)

    def stats(self) -> Tuple[float, float, float]:
        if not self.v:
            return (float('nan'),) * 3
        arr = np.asarray(self.v, dtype=float)
        return float(arr.mean()), float(arr.max()), float(arr.min())


def load_topics_mapping(db: sqlite3.Connection) -> Dict[int, str]:
    cur = db.execute('SELECT id, name FROM topics')
    return {row[0]: row[1] for row in cur.fetchall()}


def iter_messages(db: sqlite3.Connection, wanted_topic_ids: Iterable[int]):
    placeholders = ','.join('?' for _ in wanted_topic_ids)
    query = f'SELECT timestamp, topic_id, data FROM messages WHERE topic_id IN ({placeholders}) ORDER BY timestamp'
    for ts, topic_id, data in db.execute(query, list(wanted_topic_ids)):
        yield ts, topic_id, data


def normalize_timestamp(first_ts: int, ts: int) -> float:
    return (ts - first_ts) / 1e9  # nanoseconds -> seconds


def parse_ros_message(type_str: str, raw: bytes):
    if get_message is None or deserialize_message is None:
        raise RuntimeError('ROS2 python runtime not available. Run inside ROS2 env.')
    msg_type = get_message(type_str)
    return deserialize_message(raw, msg_type)


def extract_speed(topic: str, msg) -> float | None:
    if topic == ARDUINO_TOPIC:
        return float(msg.data)
    if topic == VEHICLE_TOPIC:
        return float(msg.twist.linear.x)
    if topic == GPS_TOPIC:
        v = msg.twist.twist.linear
        return math.sqrt(v.x * v.x + v.y * v.y + v.z * v.z)
    return None


def load_bag(bag_path: Path) -> Dict[str, Series]:
    db_file = bag_path / 'rosbag2_0' / 'rosbag2_0.db3'
    if not db_file.exists():
        raise FileNotFoundError(f'Database not found: {db_file}')
    conn = sqlite3.connect(str(db_file))
    with conn:
        id_to_name = load_topics_mapping(conn)
        # topic type mapping
        cur = conn.execute('SELECT id, type FROM topics')
        id_to_type = {row[0]: row[1] for row in cur.fetchall()}

        target_names = {ARDUINO_TOPIC, VEHICLE_TOPIC, GPS_TOPIC}
        wanted_ids = [tid for tid, name in id_to_name.items() if name in target_names]
        if not wanted_ids:
            raise RuntimeError('No target topics found in bag.')

        series_map = {
            ARDUINO_TOPIC: Series([], []),
            VEHICLE_TOPIC: Series([], []),
            GPS_TOPIC: Series([], []),
        }

        first_ts: int | None = None

        for ts, topic_id, raw in iter_messages(conn, wanted_ids):
            if first_ts is None:
                first_ts = ts
            topic_name = id_to_name[topic_id]
            msg_type_str = id_to_type[topic_id]
            msg = parse_ros_message(msg_type_str, raw)
            speed = extract_speed(topic_name, msg)
            if speed is None:
                continue
            t = normalize_timestamp(first_ts, ts)
            series_map[topic_name].add(t, speed)

    return series_map


def plot(series_map: Dict[str, Series], save: Path | None = None) -> None:
    if not any(s.v for s in series_map.values()):
        print('No data to plot.')
        return

    fig, ax = plt.subplots(figsize=(14, 7))
    colors = {
        ARDUINO_TOPIC: 'b',
        VEHICLE_TOPIC: 'g',
        GPS_TOPIC: 'r',
    }
    labels = {
        ARDUINO_TOPIC: 'Arduino',
        VEHICLE_TOPIC: 'Vehicle',
        GPS_TOPIC: 'GPS',
    }

    summary_lines: List[str] = []
    for topic, series in series_map.items():
        if not series.v:
            continue
        ax.plot(series.t, series.v, color=colors[topic], label=labels[topic], alpha=0.7, linewidth=1.2)
        mean_, max_, min_ = series.stats()
        summary_lines.append(f"{labels[topic]}: mean={mean_:.2f} max={max_:.2f} min={min_:.2f} m/s")

    ax.set_xlabel('Time (s)')
    ax.set_ylabel('Speed (m/s)')
    ax.set_title('Speed Comparison (rosbag2)')
    ax.grid(True, alpha=0.3)
    ax.axhline(0.0, color='k', linewidth=0.5)
    ax.legend(loc='best')

    if summary_lines:
        ax.text(
            0.02,
            0.98,
            "\n".join(summary_lines),
            transform=ax.transAxes,
            fontsize=10,
            verticalalignment='top',
            bbox=dict(boxstyle='round', facecolor='white', alpha=0.9),
        )

    plt.tight_layout()
    if save:
        save.parent.mkdir(parents=True, exist_ok=True)
        plt.savefig(save, dpi=150)
        print(f'Saved figure -> {save}')
    else:
        plt.show()


def main():
    parser = argparse.ArgumentParser(description='Offline velocity plotter from rosbag2.')
    parser.add_argument('bag_dir', type=Path, help='rosbag2 base directory (contains rosbag2_0, metadata.yaml)')
    parser.add_argument('--save', type=Path, default=None, help='파일로 저장 경로 (예: output.png)')
    parser.add_argument('--no-gps', action='store_true', help='GPS 제외')
    parser.add_argument('--no-arduino', action='store_true', help='Arduino 제외')
    parser.add_argument('--no-vehicle', action='store_true', help='Vehicle 제외')
    args = parser.parse_args()

    series_map = load_bag(args.bag_dir)

    if args.no_gps:
        series_map[GPS_TOPIC] = Series([], [])
    if args.no_arduino:
        series_map[ARDUINO_TOPIC] = Series([], [])
    if args.no_vehicle:
        series_map[VEHICLE_TOPIC] = Series([], [])

    plot(series_map, args.save)


if __name__ == '__main__':
    main()
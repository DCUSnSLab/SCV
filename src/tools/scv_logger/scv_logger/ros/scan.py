"""카탈로그 스캔 — 지금 ROS 그래프의 토픽·타입·실측 주기·평균 크기를 수집.

    scv_logger_scan --duration 5 --out scan.json

발행자가 있는 토픽만 대상. 큰 토픽도 잠깐 구독하므로 주행 중에는 쓰지 말 것.
"""
from __future__ import annotations

import argparse
import json
import os
import sys
import time
from pathlib import Path

import rclpy
from rclpy._rclpy_pybind11 import RCLError
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy
from rosidl_runtime_py.utilities import get_message

from ..constants import SCAN_IGNORE_PREFIXES
from .probe import BEST_EFFORT_QOS, LATCHED_QOS, Probe


def _spin_for(node: Node, seconds: float) -> None:
    end = time.monotonic() + seconds
    try:
        while time.monotonic() < end and rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.05)
    except RCLError:
        pass


def _published_topics(node: Node) -> list[tuple[str, list[str]]]:
    return [(n, t) for n, t in node.get_topic_names_and_types()
            if not n.startswith(SCAN_IGNORE_PREFIXES) and node.count_publishers(n) > 0]


def scan(node: Node, duration: float, discovery: float) -> list[dict]:
    _spin_for(node, discovery)
    if not _published_topics(node):
        _spin_for(node, discovery)          # DDS 탐색이 늦은 경우 한 번 더 기다린다
    probes: dict[str, Probe] = {}
    for name, types in node.get_topic_names_and_types():
        if name.startswith(SCAN_IGNORE_PREFIXES):
            continue
        infos = node.get_publishers_info_by_topic(name)
        if not infos:
            continue
        p = Probe(name)
        p.type_name = types[0]
        p.publishers = len(infos)
        p.latched = any(i.qos_profile.durability == DurabilityPolicy.TRANSIENT_LOCAL for i in infos)
        probes[name] = p
        try:
            cls = get_message(p.type_name)
        except (AttributeError, ModuleNotFoundError, ValueError):
            p.error = 'type_unavailable'
            continue
        p.sub = node.create_subscription(cls, name, p.on_msg,
                                         LATCHED_QOS if p.latched else BEST_EFFORT_QOS, raw=True)
    _spin_for(node, duration)
    out = []
    for name in sorted(probes):
        p = probes[name]
        arr = list(p.arrivals)
        hz = (len(arr) - 1) / (arr[-1] - arr[0]) if len(arr) >= 2 and arr[-1] > arr[0] else None
        size = p.avg_size_kb()
        out.append({'name': name, 'type': p.type_name, 'hz': None if hz is None else round(hz, 2),
                    'size_kb': None if size is None else round(size, 2), 'latched': p.latched,
                    'publishers': p.publishers, 'count': p.count, 'error': p.error})
    return out


def main(argv: list[str] | None = None) -> None:
    argv = list(sys.argv if argv is None else argv)
    ap = argparse.ArgumentParser(description='SCV Logger 카탈로그 스캔')
    ap.add_argument('--duration', type=float, default=5.0, help='측정 시간 (초)')
    ap.add_argument('--discovery', type=float, default=2.0, help='그래프 탐색 대기 (초)')
    ap.add_argument('--out', help='결과 JSON 경로 (없으면 stdout)')
    args = ap.parse_args(rclpy.utilities.remove_ros_args(argv)[1:])
    rclpy.init(args=argv)
    node = Node(f'scv_logger_scan_{os.getpid()}')
    try:
        result = scan(node, args.duration, args.discovery)
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    text = json.dumps({'duration': args.duration, 'topics': result}, ensure_ascii=False, indent=1)
    if args.out:
        Path(args.out).write_text(text, encoding='utf-8')
    else:
        print(text)


if __name__ == '__main__':
    main()

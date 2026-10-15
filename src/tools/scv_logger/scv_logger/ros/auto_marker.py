"""자동 마커 보조 노드 — 카탈로그 auto_markers 토픽의 값이 바뀌면 /scv_logger/marker 발행.

C++ 감시 노드(scv_logger_monitor)가 세션 모드에서 자식으로 띄운다. 메시지 내용을 비교해야 해서
역직렬화가 필요한데, 대상 토픽(주행 모드·비상정지 등)이 저주기라 파이썬으로 충분하다.
마커 파일 기록은 감시 노드가 /scv_logger/marker 를 받아서 한다.

    python3 -m scv_logger.ros.auto_marker --config <monitor_config.json>
"""
from __future__ import annotations

import argparse
import json
import sys
from functools import partial
from pathlib import Path

import rclpy
from rclpy._rclpy_pybind11 import RCLError
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_ordereddict
from rosidl_runtime_py.utilities import get_message
from std_msgs.msg import String

from ..constants import MARKER_TOPIC
from .monitor_node import extract_field, short
from .probe import BEST_EFFORT_QOS


class AutoMarkerNode(Node):
    def __init__(self, markers: list[dict]):
        super().__init__(f'scv_logger_auto_marker_{__import__("os").getpid()}')
        self.pub = self.create_publisher(String, MARKER_TOPIC, 10)
        self.entries = [{'cfg': m, 'sub': None, 'last': None, 'error': ''} for m in markers]
        self.create_timer(1.0, self._resolve)
        self._resolve()

    def _resolve(self) -> None:
        pending = [e for e in self.entries if e['sub'] is None and not e['error']]
        if not pending:
            return
        types = dict(self.get_topic_names_and_types())
        for e in pending:
            tnames = types.get(e['cfg']['topic'])
            if not tnames:
                continue
            try:
                cls = get_message(tnames[0])
            except (AttributeError, ModuleNotFoundError, ValueError):
                e['error'] = f'type_unavailable: {tnames[0]}'
                self.get_logger().warn(f'자동 마커 비활성 {e["cfg"]["topic"]}: {e["error"]}')
                continue
            e['sub'] = self.create_subscription(cls, e['cfg']['topic'], partial(self._on_msg, e), BEST_EFFORT_QOS)

    def _on_msg(self, entry: dict, msg) -> None:
        m = entry['cfg']
        value = extract_field(message_to_ordereddict(msg), m.get('field'))
        last, entry['last'] = entry['last'], value
        if last is None or value == last:
            return
        label = m.get('label') or m['topic']
        payload = {'ts': self.get_clock().now().nanoseconds / 1e9, 'kind': m.get('kind', 'auto'),
                   'text': f'{label}: {short(last)} → {short(value)}', 'source': 'auto', 'topic': m['topic']}
        self.pub.publish(String(data=json.dumps(payload, ensure_ascii=False)))


def main(argv: list[str] | None = None) -> None:
    argv = list(sys.argv if argv is None else argv)
    ap = argparse.ArgumentParser(description='SCV Logger 자동 마커')
    ap.add_argument('--config', required=True)
    args = ap.parse_args(rclpy.utilities.remove_ros_args(argv)[1:])
    markers = json.loads(Path(args.config).read_text(encoding='utf-8')).get('auto_markers', [])
    rclpy.init(args=argv)
    node = AutoMarkerNode(markers)
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException, RCLError):
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()

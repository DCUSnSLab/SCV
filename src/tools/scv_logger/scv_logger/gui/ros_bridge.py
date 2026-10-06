"""GUI의 ROS 연결 — health 구독, 마커 발행, 노드 목록.

GUI는 큰 토픽을 직접 구독하지 않는다. 상태는 monitor 프로세스가 보내는
/scv_logger/health(작은 JSON)로만 받는다.
"""
from __future__ import annotations

import json
import os
import threading
import time

import rclpy
from PyQt5.QtCore import QObject, pyqtSignal
from rclpy.executors import ExternalShutdownException, SingleThreadedExecutor
from std_msgs.msg import String

from ..constants import HEALTH_TOPIC, MARKER_TOPIC


class RosBridge(QObject):
    health_received = pyqtSignal(dict)

    def __init__(self):
        super().__init__()
        self.node = rclpy.create_node(f'scv_logger_gui_{os.getpid()}')
        self.node.create_subscription(String, HEALTH_TOPIC, self._on_health, 10)
        self.marker_pub = self.node.create_publisher(String, MARKER_TOPIC, 10)
        self.expected_pid: int | None = None
        self._executor = SingleThreadedExecutor()
        self._executor.add_node(self.node)
        self._thread = threading.Thread(target=self._spin, name='ros-spin', daemon=True)
        self._thread.start()

    def _spin(self) -> None:
        try:
            self._executor.spin()
        except (ExternalShutdownException, KeyboardInterrupt):
            pass

    def _on_health(self, msg: String) -> None:
        try:
            data = json.loads(msg.data)
        except ValueError:
            return
        # preview→session 전환 직후 이전 monitor의 마지막 메시지를 무시
        if self.expected_pid is not None and data.get('pid') != self.expected_pid:
            return
        self.health_received.emit(data)

    def publish_marker(self, kind: str, text: str) -> dict:
        payload = {'ts': time.time(), 'kind': kind, 'text': text, 'source': 'gui'}
        self.marker_pub.publish(String(data=json.dumps(payload, ensure_ascii=False)))
        return payload

    def node_names(self) -> list[str]:
        out = []
        for name, ns in self.node.get_node_names_and_namespaces():
            if name.startswith('scv_logger_'):
                continue
            out.append(f'{ns.rstrip("/")}/{name}')
        return sorted(set(out))

    def shutdown(self) -> None:
        self._executor.shutdown(timeout_sec=1.0)
        self.node.destroy_node()

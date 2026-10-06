"""토픽 상태 감시 노드.

preview 모드 (--session-dir 없음)
    GUI가 프로파일을 고를 때 띄운다. /scv_logger/health만 1초마다 발행.
session 모드 (--session-dir, --recorder-pid)
    녹화와 함께 분리 실행된다. GUI가 꺼져도 계속 돈다.
    - health.csv / system.csv 기록
    - /scv_logger/marker 구독 → markers.jsonl (수동·자동 마커의 유일한 기록자)
    - 자동 마커: 카탈로그 auto_markers 토픽의 값이 바뀌면 마커 발행
    - 디스크가 disk_stop_gb 미만으로 3초 연속이면 녹화 자동 정지
    - 녹화 프로세스가 끝나면 manifest를 마감하고 종료
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import sys
import time
from collections import deque
from datetime import datetime
from functools import partial
from pathlib import Path
from typing import Any

import rclpy
from rclpy._rclpy_pybind11 import RCLError
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy
from rosidl_runtime_py.convert import message_to_ordereddict
from rosidl_runtime_py.utilities import get_message
from std_msgs.msg import String

from ..constants import HEALTH_TOPIC, MARKER_TOPIC
from ..core import recorder
from ..core.preflight import disk_free_gb
from ..core.session import Session
from .probe import BEST_EFFORT_QOS, LATCHED_QOS, Probe, evaluate

DISK_STOP_TICKS = 3


def strip_stamps(value: Any) -> Any:
    """header·stamp를 뺀 값 — 매 메시지 바뀌는 시각 때문에 변화로 잡히지 않게."""
    if isinstance(value, dict):
        return {k: strip_stamps(v) for k, v in value.items() if k not in ('header', 'stamp')}
    if isinstance(value, list):
        return [strip_stamps(v) for v in value]
    return value


def extract_field(value: Any, path: str | None) -> Any:
    if not path:
        return strip_stamps(value)
    for key in path.split('.'):
        if isinstance(value, dict) and key in value:
            value = value[key]
        else:
            return None
    return value


def short(value: Any, limit: int = 120) -> str:
    text = value if isinstance(value, str) else json.dumps(value, ensure_ascii=False, default=str)
    return text if len(text) <= limit else text[:limit - 1] + '…'


class Watch:
    def __init__(self, cfg: dict, probe: Probe):
        self.name = cfg['name']
        self.monitor = cfg.get('monitor') or self.name
        self.hz = cfg.get('hz')
        self.required = bool(cfg.get('required'))
        self.latched = bool(cfg.get('latched'))
        self.heavy = bool(cfg.get('heavy'))
        self.probe = probe


class MonitorNode(Node):
    def __init__(self, cfg: dict, session: Session | None, recorder_pid: int | None, rate: float):
        super().__init__(f'scv_logger_monitor_{os.getpid()}')
        self.cfg = cfg
        self.session = session
        self.recorder_pid = recorder_pid
        self.tolerance = float(cfg.get('hz_tolerance', 0.8))
        self.output_dir = Path(cfg.get('output_dir') or '.')
        self.disk_warn = float(cfg.get('disk_warn_gb', 30))
        self.disk_stop = float(cfg.get('disk_stop_gb', 10))
        self.done = False
        self._disk_low_ticks = 0
        self._disk_stop_sent = False
        self._bytes_hist: deque[tuple[float, int]] = deque(maxlen=12)

        self.probes: dict[str, Probe] = {}
        self.watches: list[Watch] = []
        for t in cfg.get('topics', []):
            mon = t.get('monitor') or t['name']
            probe = self.probes.setdefault(mon, Probe(mon))
            probe.latched = probe.latched or bool(t.get('latched'))
            self.watches.append(Watch(t, probe))

        self.health_pub = self.create_publisher(String, HEALTH_TOPIC, 10)
        self.marker_pub = self.create_publisher(String, MARKER_TOPIC, 10)

        self._auto: list[dict] = []
        self._health_csv = self._system_csv = None
        if session is not None:
            self._started = self._session_start_epoch()
            self.create_subscription(String, MARKER_TOPIC, self._on_marker, 50)
            self._auto = [{'cfg': m, 'sub': None, 'last': None, 'error': ''}
                          for m in cfg.get('auto_markers', [])]
            self._health_csv = self._open_csv(session.health_path, ['time', 'topic', 'hz', 'age_s', 'status'])
            self._system_csv = self._open_csv(session.system_path,
                                              ['time', 'disk_free_gb', 'bag_bytes', 'write_mbps', 'recorder_alive'])

        self._resolve()
        self.create_timer(1.0, self._resolve)
        self.create_timer(1.0 / max(rate, 0.1), self._report)

    # ---- 구독 연결 ------------------------------------------------------
    def _session_start_epoch(self) -> float:
        try:
            return datetime.fromisoformat(self.session.read_manifest()['started_at']).timestamp()
        except (KeyError, TypeError, ValueError):
            return time.time()

    @staticmethod
    def _open_csv(path: Path, header: list[str]):
        new = not path.exists()
        f = open(path, 'a', newline='', encoding='utf-8')
        w = csv.writer(f)
        if new:
            w.writerow(header)
        return f, w

    def _resolve(self) -> None:
        """아직 구독하지 못한 토픽을 그래프에서 찾아 연결 (발행자가 늦게 떠도 됨)."""
        pending = [p for p in self.probes.values() if p.sub is None and not p.error]
        pending_auto = [a for a in self._auto if a['sub'] is None and not a['error']]
        if not pending and not pending_auto:
            for p in self.probes.values():
                p.publishers = self.count_publishers(p.topic)
            return
        types = dict(self.get_topic_names_and_types())
        for p in self.probes.values():
            p.publishers = self.count_publishers(p.topic)
        for p in pending:
            tnames = types.get(p.topic)
            if not tnames or p.publishers == 0:
                continue
            p.type_name = tnames[0]
            try:
                cls = get_message(p.type_name)
            except (AttributeError, ModuleNotFoundError, ValueError) as e:
                p.error = f'type_unavailable: {p.type_name} ({e.__class__.__name__})'
                continue
            if not p.latched:
                infos = self.get_publishers_info_by_topic(p.topic)
                p.latched = any(i.qos_profile.durability == DurabilityPolicy.TRANSIENT_LOCAL for i in infos)
            p.sub = self.create_subscription(cls, p.topic, p.on_msg,
                                             LATCHED_QOS if p.latched else BEST_EFFORT_QOS, raw=True)
        for a in pending_auto:
            topic = a['cfg']['topic']
            tnames = types.get(topic)
            if not tnames:
                continue
            try:
                cls = get_message(tnames[0])
            except (AttributeError, ModuleNotFoundError, ValueError):
                a['error'] = f'type_unavailable: {tnames[0]}'
                continue
            a['sub'] = self.create_subscription(cls, topic, partial(self._on_auto, a), BEST_EFFORT_QOS)

    # ---- 마커 ----------------------------------------------------------
    def _on_auto(self, entry: dict, msg) -> None:
        m = entry['cfg']
        value = extract_field(message_to_ordereddict(msg), m.get('field'))
        last, entry['last'] = entry['last'], value
        if last is None or value == last:
            return
        label = m.get('label') or m['topic']
        self.publish_marker(m.get('kind', 'auto'), f'{label}: {short(last)} → {short(value)}',
                            source='auto', topic=m['topic'])

    def publish_marker(self, kind: str, text: str, **extra: Any) -> None:
        payload = {'ts': time.time(), 'kind': kind, 'text': text, **extra}
        self.marker_pub.publish(String(data=json.dumps(payload, ensure_ascii=False)))

    def _on_marker(self, msg: String) -> None:
        try:
            marker = json.loads(msg.data)
            if not isinstance(marker, dict):
                raise ValueError
        except ValueError:
            marker = {'ts': time.time(), 'kind': 'note', 'text': msg.data}
        marker.setdefault('ts', time.time())
        marker['t_rel'] = round(float(marker['ts']) - self._started, 2)
        self.session.append_marker(marker)

    # ---- 보고 ----------------------------------------------------------
    def _report(self) -> None:
        now = time.monotonic()
        wall = time.time()
        topics: dict[str, dict] = {}
        for w in self.watches:
            p = w.probe
            st = evaluate(w.hz, p.arrivals, now, publishers=p.publishers, latched=p.latched,
                          error=p.error, count=p.count, tolerance=self.tolerance)
            size = p.avg_size_kb() if w.monitor == w.name else None
            topics[w.name] = {**st, 'expected': w.hz, 'required': w.required,
                              'publishers': p.publishers,
                              'size_kb': None if size is None else round(size, 2),
                              'via': w.monitor if w.monitor != w.name else None,
                              'direct_heavy': w.heavy and w.monitor == w.name}

        free = disk_free_gb(self.output_dir)
        warnings: list[str] = []
        if free is not None and free < self.disk_warn:
            warnings.append(f'디스크 여유 {free:.0f} GB (경고 {self.disk_warn:.0f} GB)')
        for a in self._auto:
            if a['error']:
                warnings.append(f'자동 마커 비활성 {a["cfg"]["topic"]}: {a["error"]}')

        health: dict[str, Any] = {
            'ts': wall, 'pid': os.getpid(), 'profile': self.cfg.get('profile'),
            'mode': 'session' if self.session else 'preview',
            'disk': {'path': str(self.output_dir), 'free_gb': None if free is None else round(free, 1),
                     'warn_gb': self.disk_warn, 'stop_gb': self.disk_stop},
            'topics': topics,
            'warnings': warnings,
        }
        counts = {'ok': 0, 'bad': 0}
        for t in topics.values():
            counts['ok' if t['status'] == 'ok' else 'bad'] += 1
        health['summary'] = counts

        if self.session is not None:
            alive = recorder.pid_alive(self.recorder_pid)
            bag_bytes = self.session.bag_bytes()
            self._bytes_hist.append((now, bag_bytes))
            t0, b0 = self._bytes_hist[0]
            mbps = (bag_bytes - b0) / (now - t0) / 1024 ** 2 if now > t0 else 0.0
            remaining = None
            if free is not None and mbps > 0.01:
                remaining = max(0.0, (free - self.disk_stop) * 1024 / mbps / 60)
            health['session'] = self.session.id
            health['recorder'] = {'pid': self.recorder_pid, 'alive': alive}
            health['bag'] = {'bytes': bag_bytes, 'mbps': round(mbps, 2),
                             'remaining_min': None if remaining is None else round(remaining)}
            health['elapsed_sec'] = round(wall - self._started, 1)
            self._write_csv(wall, topics, free, bag_bytes, mbps, alive)
            self._check_disk(free, alive)
            if not alive:
                m = self.session.finalize()
                health['final_status'] = m.get('status')
                self.done = True

        self.health_pub.publish(String(data=json.dumps(health, ensure_ascii=False)))

    def _write_csv(self, wall, topics, free, bag_bytes, mbps, alive) -> None:
        f, w = self._health_csv
        for name, t in topics.items():
            w.writerow([f'{wall:.3f}', name, t['hz'], '' if t['age'] is None else t['age'], t['status']])
        f.flush()
        f, w = self._system_csv
        w.writerow([f'{wall:.3f}', '' if free is None else round(free, 2), bag_bytes, round(mbps, 3), int(alive)])
        f.flush()

    def _check_disk(self, free: float | None, alive: bool) -> None:
        if free is None or not alive or self._disk_stop_sent:
            return
        self._disk_low_ticks = self._disk_low_ticks + 1 if free < self.disk_stop else 0
        if self._disk_low_ticks >= DISK_STOP_TICKS:
            self._disk_stop_sent = True
            self.get_logger().error(f'디스크 여유 {free:.1f} GB < {self.disk_stop} GB — 녹화 자동 정지')
            self.session.update_manifest(stop_reason='disk_low')
            self.publish_marker('disk_stop', f'디스크 여유 {free:.1f} GB — 녹화 자동 정지', source='auto')
            recorder.send_sigint(self.recorder_pid)

    def close(self) -> None:
        for pair in (self._health_csv, self._system_csv):
            if pair:
                pair[0].close()


def main(argv: list[str] | None = None) -> None:
    argv = list(sys.argv if argv is None else argv)
    ap = argparse.ArgumentParser(description='SCV Logger 토픽 상태 감시')
    ap.add_argument('--config', required=True, help='monitor 설정 JSON')
    ap.add_argument('--session-dir', help='세션 모드: 세션 폴더')
    ap.add_argument('--recorder-pid', type=int, help='세션 모드: ros2 bag record PID')
    ap.add_argument('--rate', type=float, default=1.0)
    args = ap.parse_args(rclpy.utilities.remove_ros_args(argv)[1:])
    cfg = json.loads(Path(args.config).read_text(encoding='utf-8'))
    session = Session(Path(args.session_dir)) if args.session_dir else None

    rclpy.init(args=argv)
    node = MonitorNode(cfg, session, args.recorder_pid, args.rate)
    try:
        while rclpy.ok() and not node.done:
            rclpy.spin_once(node, timeout_sec=0.2)
    except (KeyboardInterrupt, ExternalShutdownException, RCLError):
        pass                 # SIGINT/SIGTERM — rclpy가 컨텍스트를 먼저 내린 경우 포함
    finally:
        node.close()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()

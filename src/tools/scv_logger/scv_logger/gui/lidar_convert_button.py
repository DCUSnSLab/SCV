"""녹화가 끝난 세션의 /velodyne_packets → /velodyne_points 변환 버튼 (녹화 탭, 시작 버튼 아래).

대상은 이 GUI에서 마지막으로 끝난 세션(없으면 저장 경로의 최신 세션). 변환은 별도 프로세스
(scv_logger.ros.lidar_convert)로 돌리고 stdout의 JSON 진행 상황을 읽는다.
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

from PyQt5.QtCore import QProcess
from PyQt5.QtWidgets import QMessageBox, QPushButton

from ..core.preflight import disk_free_gb
from ..core.session import list_sessions
from ..core.yamlio import load_yaml
from .common import fmt_bytes

PACKETS = '/velodyne_packets'
CLOUD_BYTES = 1812 * 32 * 22          # VLP-32C organized cloud 한 장 (실측 1.27 MB)


def topic_count(session: Path, topic: str) -> int:
    """bag metadata의 토픽 메시지 수 (없으면 0)."""
    meta = session / 'bag' / 'metadata.yaml'
    if not meta.exists():
        return 0
    info = (load_yaml(meta) or {}).get('rosbag2_bagfile_information', {})
    for t in info.get('topics_with_message_count', []):
        if t['topic_metadata']['name'] == topic:
            return int(t['message_count'])
    return 0


def packet_count(session: Path) -> int:
    return topic_count(session, PACKETS)


def bag_bytes(d: Path) -> int:
    return sum(p.stat().st_size for p in d.iterdir() if p.is_file()) if d.is_dir() else 0


class LidarConvertButton(QPushButton):
    def __init__(self, ctx, controller):
        super().__init__('LiDAR 포인트 변환')
        self.ctx = ctx
        self.ctl = controller
        self.target: Path | None = None
        self.proc: QProcess | None = None
        self._buf = ''
        self._stage = ''
        self._result: dict = {}
        self.setMinimumHeight(28)
        self.clicked.connect(self._on_click)
        controller.session_finished.connect(lambda p: self.set_target(Path(p)))
        controller.state_changed.connect(lambda _s: self.refresh())
        ctx.settings_changed.connect(self._pick_latest)
        self._pick_latest()

    # ---- 대상 세션 -----------------------------------------------------
    def _pick_latest(self) -> None:
        for s in list_sessions(self.ctx.settings.output_path):
            if s.status != 'recording':
                self.set_target(s.path)
                return
        self.set_target(None)

    def set_target(self, path: Path | None) -> None:
        if self.proc is not None:
            return                                   # 변환 중엔 대상 유지
        self.target = path
        self.refresh()

    def refresh(self) -> None:
        if self.proc is not None:
            return
        t = self.target
        if t is None:
            self._set('LiDAR 포인트 변환', False, '변환할 세션이 없습니다')
        elif self.ctl.state != 'idle':
            self._set('LiDAR 포인트 변환', False, '녹화가 끝난 뒤에 변환할 수 있습니다')
        elif (t / 'bag_points').exists():
            merged = ' + bag_merged' if (t / 'bag_merged').exists() else ''
            self._set('포인트 변환 완료 ✓', False, f'{t.name}\n{t / "bag_points"}{merged}')
        elif topic_count(t, '/velodyne_points') > 0:
            self._set('LiDAR 포인트 변환', False, f'{t.name}\n이미 /velodyne_points가 녹화된 세션입니다')
        elif packet_count(t) == 0:
            self._set('LiDAR 포인트 변환', False, f'{t.name}\n이 세션에는 {PACKETS}가 녹화되지 않았습니다')
        else:
            self._set('LiDAR 포인트 변환', True,
                      f'{t.name}\n{PACKETS} {packet_count(t):,}개 → /velodyne_points')

    def _set(self, text: str, enabled: bool, tip: str) -> None:
        self.setText(text)
        self.setEnabled(enabled)
        self.setToolTip(tip)

    # ---- 실행 ----------------------------------------------------------
    def _on_click(self) -> None:
        if self.proc is not None:
            if QMessageBox.question(self, '변환 취소', 'LiDAR 포인트 변환을 취소할까요?') == QMessageBox.Yes:
                self.proc.kill()
            return
        t = self.target
        n = packet_count(t)
        points_size = n * CLOUD_BYTES
        merged_size = bag_bytes(t / 'bag') + points_size
        free = disk_free_gb(t) or 0
        box = QMessageBox(self)
        box.setWindowTitle('LiDAR 포인트 변환')
        box.setText(f'{t.name}\n\n{PACKETS} {n:,}개를 /velodyne_points로 변환합니다.\n'
                    f'실차와 같은 velodyne_transform_node 설정을 쓰고, 프레임 손실 없이 변환합니다.\n\n'
                    f'• 포인트만: bag_points/ (약 {fmt_bytes(points_size)})\n'
                    f'• 원본과 합치기: bag_merged/ 도 만듦 (약 {fmt_bytes(merged_size)}) — '
                    f'ros2 bag play 한 번으로 재생\n\n디스크 여유 {free:.0f} GB')
        only = box.addButton('포인트만', QMessageBox.AcceptRole)
        merge = box.addButton('원본과 합치기', QMessageBox.AcceptRole)
        box.addButton('취소', QMessageBox.RejectRole)
        box.exec_()
        clicked = box.clickedButton()
        if clicked not in (only, merge):
            return
        need = (merged_size if clicked is merge else points_size) / 1024 ** 3
        if need > free - 5 and QMessageBox.question(
                self, '디스크 부족', f'필요 약 {need:.0f} GB, 여유 {free:.0f} GB 입니다. 그래도 진행할까요?') != QMessageBox.Yes:
            return
        self._start(t, merge=clicked is merge)

    def _start(self, session: Path, merge: bool) -> None:
        self.proc = QProcess(self)
        self.proc.setProcessChannelMode(QProcess.SeparateChannels)
        self.proc.readyReadStandardOutput.connect(self._on_output)
        self.proc.finished.connect(self._on_finished)
        self._buf, self._stage, self._result = '', 'convert', {}
        args = ['-m', 'scv_logger.ros.lidar_convert', '--session', str(session)]
        if merge:
            args.append('--merge')
        self.proc.start(sys.executable, args)
        self._set('변환 준비 중… (누르면 취소)', True, str(session))

    def _on_output(self) -> None:
        self._buf += bytes(self.proc.readAllStandardOutput()).decode(errors='replace')
        *lines, self._buf = self._buf.split('\n')
        for line in lines:
            try:
                ev = json.loads(line)
            except ValueError:
                continue
            self._stage = ev.get('stage', self._stage)
            if self._stage == 'convert' and ev.get('total'):
                self.setText(f'포인트 변환 중 {ev["done"] * 100 // ev["total"]}% (누르면 취소)')
            elif self._stage == 'merge':
                self.setText('원본과 합치는 중… (누르면 취소)')
            elif self._stage in ('finished', 'error'):
                self._result = ev

    def _on_finished(self, code: int, _status) -> None:
        err = bytes(self.proc.readAllStandardError()).decode(errors='replace')
        self.proc = None
        r = self._result
        if r.get('stage') == 'finished':
            msg = (f'변환 완료: 포인트클라우드 {r["clouds"]:,}개 / 패킷 {r["packets"]:,}개 ({r["seconds"]:.0f}초)\n'
                   f'{r["points_bag"]}')
            if r.get('merged_bag'):
                msg += f'\n재생: ros2 bag play {r["merged_bag"]} --clock'
            QMessageBox.information(self, 'LiDAR 포인트 변환', msg)
        elif r.get('stage') == 'error':
            QMessageBox.warning(self, 'LiDAR 포인트 변환 실패', r.get('error', ''))
        else:
            QMessageBox.warning(self, 'LiDAR 포인트 변환 중단',
                                f'변환 프로세스가 끝났습니다 (코드 {code}). 다시 누르면 처음부터 변환합니다.'
                                f'\n\n{err[-600:]}')
        self.refresh()

"""녹화 상태 머신 — 위젯과 분리.

    IDLE ──시작──▶ WAITING(준비 대기/지연) ──▶ STARTING(세션 준비) ──▶ RECORDING
      ▲                                                                 │
      └──────────────────── STOPPING ◀──────────정지────────────────────┘

IDLE에서는 preview monitor(GUI 자식 프로세스)가 고른 프로파일의 토픽을 감시한다.
RECORDING에서는 ros2 bag record와 session monitor가 GUI와 분리돼 돈다.
"""
from __future__ import annotations

import subprocess
import sys
import time
from pathlib import Path

from PyQt5.QtCore import QObject, QTimer, pyqtSignal

from ..core import gitinfo, recorder
from ..core.command import (build_record_command, monitor_config, qos_overrides, write_json,
                            write_qos_file)
from ..core.preflight import required_ready
from ..core.profile import ResolvedProfile
from ..core.recorder import ActiveState
from ..core.session import (STATUS_LABELS, Session, fta_status, now_iso, running_launches,
                            snapshot_params)
from ..paths import state_dir
from .common import run_async
from .context import AppContext
from .ros_bridge import RosBridge

IDLE, WAITING, STARTING, RECORDING, STOPPING = 'idle', 'waiting', 'starting', 'recording', 'stopping'


def _monitor_cmd(config: Path, session: Session | None = None, recorder_pid: int | None = None) -> list[str]:
    cmd = [sys.executable, '-m', 'scv_logger.ros.monitor_node', '--config', str(config)]
    if session is not None:
        cmd += ['--session-dir', str(session.path), '--recorder-pid', str(recorder_pid)]
    return cmd


def log_tail(path: Path, lines: int = 8) -> str:
    try:
        return '\n'.join(path.read_text(errors='replace').splitlines()[-lines:])
    except OSError:
        return ''


class RecordingController(QObject):
    state_changed = pyqtSignal(str)
    message = pyqtSignal(str, str)             # level, text
    health_updated = pyqtSignal(dict)
    session_started = pyqtSignal(str)
    session_finished = pyqtSignal(str)
    waiting_progress = pyqtSignal(str)         # 대기 중 안내 문구
    ready_timeout = pyqtSignal(list)           # 준비 안 된 필수 토픽

    def __init__(self, ctx: AppContext, bridge: RosBridge):
        super().__init__()
        self.ctx = ctx
        self.bridge = bridge
        self.state = IDLE
        self.resolved: ResolvedProfile | None = None
        self.session: Session | None = None
        self.active: ActiveState | None = None
        self.latest_health: dict | None = None
        self._preview: subprocess.Popen | None = None
        self._preview_started = 0.0
        self._pending: tuple[str, str] = ('', '')
        self._pending_after_timeout: tuple[str, str] = ('', '')
        self._wait_deadline = 0.0
        self._start_check_at = 0.0
        self._handling_end = False

        bridge.health_received.connect(self._on_health)
        self._restart_timer = QTimer(self, singleShot=True, interval=300)
        self._restart_timer.timeout.connect(self._restart_preview)
        self._tick_timer = QTimer(self, interval=500)
        self._tick_timer.timeout.connect(self._tick)
        self._tick_timer.start()
        ctx.settings_changed.connect(self._schedule_preview)
        ctx.catalog_changed.connect(self._schedule_preview)

    # ---- 상태 ----------------------------------------------------------
    def _set_state(self, state: str) -> None:
        self.state = state
        self.state_changed.emit(state)

    def _on_health(self, data: dict) -> None:
        self.latest_health = data
        self.health_updated.emit(data)

    # ---- preview monitor ---------------------------------------------
    def set_profile(self, resolved: ResolvedProfile | None) -> None:
        self.resolved = resolved
        self._schedule_preview()

    def _schedule_preview(self) -> None:
        if self.state in (IDLE, WAITING):
            self._restart_timer.start()

    def _restart_preview(self) -> None:
        self.stop_preview()
        if self.resolved is None or self.state not in (IDLE, WAITING):
            return
        cfg = monitor_config(self.resolved, self.ctx.catalog,
                             hz_tolerance=self.ctx.settings.hz_tolerance,
                             output_dir=self.ctx.settings.output_path)
        path = write_json(state_dir() / 'preview_monitor.json', cfg)
        log = open(state_dir() / 'preview_monitor.log', 'ab')
        self._preview = subprocess.Popen(_monitor_cmd(path), stdout=log, stderr=subprocess.STDOUT,
                                         stdin=subprocess.DEVNULL)
        log.close()
        self._preview_started = time.monotonic()
        self.bridge.expected_pid = self._preview.pid
        self.latest_health = None

    def stop_preview(self) -> None:
        if self._preview is not None and self._preview.poll() is None:
            self._preview.terminate()
            try:
                self._preview.wait(timeout=2)
            except subprocess.TimeoutExpired:
                self._preview.kill()
        self._preview = None

    # ---- 시작 ----------------------------------------------------------
    def request_start(self, label: str, notes: str) -> None:
        if self.state != IDLE or self.resolved is None:
            return
        self._pending = (label, notes)
        o = self.resolved.options
        if o.start_mode == 'immediate':
            self._begin_start()
            return
        secs = o.wait_ready_sec if o.start_mode == 'wait_ready' else o.start_delay_sec
        self._wait_deadline = time.monotonic() + secs
        self._set_state(WAITING)

    def cancel_wait(self) -> None:
        if self.state == WAITING:
            self._set_state(IDLE)

    def start_now(self) -> None:
        if self.state == WAITING:
            self._begin_start()

    def _begin_start(self) -> None:
        self._set_state(STARTING)
        resolved, ctx = self.resolved, self.ctx
        label, notes = self._pending
        nodes = self.bridge.node_names()
        settings, catalog, ws = ctx.settings, ctx.catalog, ctx.workspace

        def prepare():
            git = gitinfo.snapshot(ws)
            session = Session.create(settings.output_path, resolved, label=label, notes=notes,
                                     workspace=ws, git=git, nodes=nodes,
                                     launches=running_launches(), fta=fta_status())
            params = snapshot_params(ws, settings.param_globs, session.params_dir,
                                     settings.param_copy_max_mb)
            overrides = qos_overrides(resolved, catalog)
            qos = write_qos_file(session.qos_path, overrides)
            cmd = build_record_command(resolved, session.bag_dir, qos)
            write_json(session.monitor_config_path,
                       monitor_config(resolved, catalog, hz_tolerance=settings.hz_tolerance,
                                      output_dir=settings.output_path))
            session.update_manifest(params=params, command=cmd, qos_overrides=sorted(overrides))
            return session, cmd

        run_async(prepare, self._on_prepared, self._on_start_failed)

    def _on_start_failed(self, err: str) -> None:
        self.message.emit('error', f'세션 준비 실패: {err.splitlines()[0]}')
        self._set_state(IDLE)
        self._schedule_preview()

    def _on_prepared(self, result) -> None:
        session, cmd = result
        try:
            rec_pid = recorder.start_detached(cmd, session.recorder_log, cwd=session.path)
        except OSError as e:
            session.finalize('recorder_exited')
            self.message.emit('error', f'녹화 프로세스 실행 실패: {e}')
            self._set_state(IDLE)
            self._schedule_preview()
            return
        self.stop_preview()
        mon_pid = self._start_session_monitor(session, rec_pid)
        self.active = ActiveState(str(session.path), rec_pid, mon_pid, now_iso())
        self.active.save()
        session.update_manifest(recorder={'pid': rec_pid}, monitor={'pid': mon_pid})
        self.session = session
        self._start_check_at = time.monotonic() + 3.0
        self._set_state(RECORDING)
        self.session_started.emit(str(session.path))
        self.message.emit('ok', f'녹화 시작: {session.id}')

    def _start_session_monitor(self, session: Session, rec_pid: int) -> int:
        pid = recorder.start_detached(_monitor_cmd(session.monitor_config_path, session, rec_pid),
                                      session.monitor_log)
        self.bridge.expected_pid = pid
        self.latest_health = None
        return pid

    # ---- 정지 ----------------------------------------------------------
    def request_stop(self) -> None:
        if self.state != RECORDING:
            return
        self._set_state(STOPPING)
        session, active, timeout = self.session, self.active, self.ctx.settings.stop_timeout_sec

        def stop():
            if not session.read_manifest().get('stop_reason'):
                session.update_manifest(stop_reason='user')
            how = recorder.stop_process(active.recorder_pid, timeout)
            # monitor가 녹화 종료를 감지하고 manifest를 마감한 뒤 스스로 끝난다
            if not recorder.wait_exit(active.monitor_pid, 8.0):
                recorder.stop_process(active.monitor_pid, 3.0)
            return how, session.finalize()

        run_async(stop, self._on_stopped, self._on_stop_failed)

    def _on_stopped(self, result) -> None:
        how, manifest = result
        path = str(self.session.path)
        status = manifest.get('status', '')
        note = '' if how in ('sigint', 'not_running') else f' (정상 종료 실패 → {how})'
        self._finish(path)
        self.message.emit('ok' if status == 'completed' else 'warn',
                          f'녹화 종료: {STATUS_LABELS.get(status, status)}{note}')

    def _on_stop_failed(self, err: str) -> None:
        self.message.emit('error', f'정지 중 오류: {err.splitlines()[0]}')
        self._set_state(RECORDING)

    def _finish(self, path: str) -> None:
        ActiveState.clear()
        self.session = None
        self.active = None
        self._handling_end = False
        self._set_state(IDLE)
        self.session_finished.emit(path)
        self._schedule_preview()

    # ---- 주기 점검 -----------------------------------------------------
    def _tick(self) -> None:
        if self.state in (IDLE, WAITING):
            if self._preview is not None and self._preview.poll() is not None \
                    and time.monotonic() - self._preview_started > 5:
                self.message.emit('warn', 'preview monitor가 종료됨 — 다시 띄움 (state_dir/preview_monitor.log)')
                self._restart_preview()
        if self.state == WAITING:
            self._tick_waiting()
        elif self.state == RECORDING:
            self._tick_recording()

    def _tick_waiting(self) -> None:
        o = self.resolved.options
        left = max(0, int(self._wait_deadline - time.monotonic() + 0.99))
        if o.start_mode == 'delay':
            if left <= 0:
                self._begin_start()
            else:
                self.waiting_progress.emit(f'{left}초 후 녹화 시작')
            return
        ready, bad = required_ready(self.latest_health)
        if ready:
            self._begin_start()
        elif left <= 0:
            self._set_state(IDLE)
            self._pending_after_timeout = self._pending
            self.ready_timeout.emit(bad)
        else:
            self.waiting_progress.emit(f'필수 토픽 대기 중 ({left}초) — 미준비: {", ".join(bad[:3])}'
                                       f'{" 외" if len(bad) > 3 else ""}')

    def start_after_timeout(self) -> None:
        """준비 대기 시간 초과 후 사용자가 '그래도 시작'을 고른 경우."""
        if self.state == IDLE:
            self._pending = self._pending_after_timeout
            self._begin_start()

    def _tick_recording(self) -> None:
        a = self.active
        if self._handling_end:
            return
        if not recorder.pid_alive(a.recorder_pid):
            self._handling_end = True
            session = self.session
            early = time.monotonic() < self._start_check_at

            def wait_monitor():
                recorder.wait_exit(a.monitor_pid, 5.0)
                if recorder.pid_alive(a.monitor_pid):
                    recorder.stop_process(a.monitor_pid, 3.0)
                return session.finalize()

            def done(manifest):
                status = manifest.get('status', '')
                path = str(session.path)
                self._finish(path)
                if status == 'stopped_disk_low':
                    self.message.emit('error', '디스크 여유 부족으로 녹화가 자동 정지됨')
                else:
                    tail = log_tail(session.recorder_log)
                    what = '녹화 프로세스가 바로 종료됨' if early else '녹화 프로세스가 예기치 않게 종료됨'
                    self.message.emit('error', f'{what} — recorder.log:\n{tail}')

            run_async(wait_monitor, done, lambda e: self._finish(str(session.path)))
            return
        if not recorder.pid_alive(a.monitor_pid):
            a.monitor_pid = self._start_session_monitor(self.session, a.recorder_pid)
            a.save()
            self.message.emit('warn', 'session monitor가 종료되어 다시 띄움')

    # ---- 재연결 --------------------------------------------------------
    def attach_existing(self) -> bool:
        a = ActiveState.load()
        if a is None:
            return False
        session = Session(Path(a.session_dir))
        if recorder.pid_alive(a.recorder_pid) and recorder.cmdline_contains(a.recorder_pid, 'bag', 'record'):
            self.session, self.active = session, a
            if not recorder.pid_alive(a.monitor_pid):
                a.monitor_pid = self._start_session_monitor(session, a.recorder_pid)
                a.save()
            else:
                self.bridge.expected_pid = a.monitor_pid
            self._start_check_at = 0.0
            self.stop_preview()
            self._set_state(RECORDING)
            self.session_started.emit(str(session.path))
            self.message.emit('info', f'실행 중인 녹화에 다시 연결: {session.id}')
            return True
        if session.status == 'recording':
            m = session.read_manifest()
            session.finalize(None if m.get('stop_reason') else 'unknown_end')
        ActiveState.clear()
        self.message.emit('warn', f'이전 녹화가 GUI 밖에서 종료됨 — 세션 마감: {session.id}')
        return False

    def elapsed_sec(self) -> float | None:
        if self.latest_health and 'elapsed_sec' in self.latest_health:
            return self.latest_health['elapsed_sec']
        return None

    def shutdown(self) -> None:
        self._tick_timer.stop()
        self.stop_preview()

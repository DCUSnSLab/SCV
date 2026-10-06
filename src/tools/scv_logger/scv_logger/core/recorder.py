"""녹화·monitor 프로세스 관리.

ros2 bag record와 세션 monitor는 **새 세션(setsid)으로 분리해** 띄운다. GUI 창을
닫거나 ssh -X 연결이 끊겨 GUI가 SIGHUP으로 죽어도 녹화는 계속된다. GUI를 다시
열면 active.json으로 실행 중인 녹화를 찾아 다시 붙는다.
"""
from __future__ import annotations

import json
import os
import signal
import subprocess
import time
from dataclasses import asdict, dataclass
from pathlib import Path

from ..paths import state_dir

try:
    import psutil
except ImportError:  # pragma: no cover - package.xml에 의존성으로 명시
    psutil = None

# start_detached로 띄운 자식 — poll()로 회수해야 좀비가 남지 않는다
_children: dict[int, subprocess.Popen] = {}


def start_detached(cmd: list[str], log_path: Path, env: dict | None = None,
                   cwd: Path | None = None) -> int:
    log_path = Path(log_path)
    log_path.parent.mkdir(parents=True, exist_ok=True)
    with open(log_path, 'ab') as log:
        log.write(f'$ {" ".join(cmd)}\n'.encode())
        log.flush()
        proc = subprocess.Popen(cmd, stdout=log, stderr=subprocess.STDOUT,
                                stdin=subprocess.DEVNULL, start_new_session=True,
                                env=env, cwd=cwd)
    _children[proc.pid] = proc
    return proc.pid


def _reap(pid: int) -> None:
    proc = _children.get(pid)
    if proc is not None and proc.poll() is not None:
        _children.pop(pid, None)


def pid_alive(pid: int | None) -> bool:
    if not pid:
        return False
    _reap(pid)
    if pid in _children:
        return _children[pid].poll() is None
    if psutil is not None:
        try:
            return psutil.Process(pid).status() != psutil.STATUS_ZOMBIE
        except psutil.Error:
            return False
    try:
        os.kill(pid, 0)
        return True
    except OSError:
        return False


def exit_code(pid: int) -> int | None:
    proc = _children.get(pid)
    return proc.poll() if proc is not None else None


def cmdline_contains(pid: int, *words: str) -> bool:
    if psutil is None:
        return True
    try:
        cmd = psutil.Process(pid).cmdline()
    except psutil.Error:
        return False
    return all(w in cmd for w in words)


def _signal(pid: int, sig: int) -> None:
    try:
        os.killpg(os.getpgid(pid), sig)
    except (ProcessLookupError, PermissionError):
        try:
            os.kill(pid, sig)
        except ProcessLookupError:
            pass


def wait_exit(pid: int, timeout: float) -> bool:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        if not pid_alive(pid):
            return True
        time.sleep(0.1)
    return not pid_alive(pid)


def stop_process(pid: int | None, timeout: float = 20.0) -> str:
    """SIGINT(정상 종료: bag metadata 기록) → SIGTERM → SIGKILL. 블로킹."""
    if not pid_alive(pid):
        return 'not_running'
    _signal(pid, signal.SIGINT)
    if wait_exit(pid, timeout):
        return 'sigint'
    _signal(pid, signal.SIGTERM)
    if wait_exit(pid, 5.0):
        return 'sigterm'
    _signal(pid, signal.SIGKILL)
    wait_exit(pid, 2.0)
    return 'sigkill'


def send_sigint(pid: int) -> None:
    _signal(pid, signal.SIGINT)


@dataclass
class ActiveState:
    """실행 중인 녹화. GUI가 꺼졌다 켜져도 이걸로 다시 붙는다."""
    session_dir: str
    recorder_pid: int
    monitor_pid: int | None = None
    started_at: str = ''

    @staticmethod
    def path() -> Path:
        return state_dir() / 'active.json'

    @classmethod
    def load(cls) -> 'ActiveState | None':
        p = cls.path()
        if not p.exists():
            return None
        try:
            return cls(**json.loads(p.read_text()))
        except (ValueError, TypeError):
            return None

    def save(self) -> None:
        p = self.path()
        p.parent.mkdir(parents=True, exist_ok=True)
        tmp = p.with_suffix('.tmp')
        tmp.write_text(json.dumps(asdict(self), indent=1))
        os.replace(tmp, p)

    @classmethod
    def clear(cls) -> None:
        cls.path().unlink(missing_ok=True)

"""세션 폴더 — 주행 한 번 = 폴더 하나.

    <output_dir>/<YYYYmmdd_HHMMSS>_<profile>[_<label>]/
        manifest.yaml      프로파일·옵션·명령·시각·코드(git)·파라미터 해시·ROS 그래프
        profile.yaml       해석된 프로파일 사본
        params/            파라미터 파일 사본
        bag/               ros2 bag 출력
        health.csv         토픽별 주기 시계열 (monitor가 1초마다)
        system.csv         디스크·녹화 용량 시계열
        markers.jsonl      마커 (수동 + 자동)
        recorder.log, monitor.log

manifest는 GUI와 monitor 두 프로세스가 고친다. 파일 잠금(flock)으로 직렬화하고,
임시 파일 + rename으로 원자적으로 쓴다.
"""
from __future__ import annotations

import fcntl
import getpass
import glob
import hashlib
import json
import os
import re
import shutil
import socket
import subprocess
from contextlib import contextmanager
from datetime import datetime
from pathlib import Path
from typing import Any

from .profile import ResolvedProfile
from .yamlio import load_yaml, write_yaml

SCHEMA = 1

STATUS_RECORDING = 'recording'
STATUS_LABELS = {
    'recording': '녹화 중',
    'completed': '완료',
    'stopped_disk_low': '디스크 부족 자동 정지',
    'recorder_exited': '녹화 프로세스 비정상 종료',
    'unknown_end': '종료 시점 불명',
}
STOP_REASON_STATUS = {'user': 'completed', 'disk_low': 'stopped_disk_low'}

_SLUG_RE = re.compile(r'[^0-9A-Za-z가-힣_-]+')


def slug(text: str, limit: int = 40) -> str:
    return _SLUG_RE.sub('_', text.strip()).strip('_')[:limit]


def make_session_id(profile: str, label: str = '', now: datetime | None = None) -> str:
    now = now or datetime.now()
    sid = f'{now:%Y%m%d_%H%M%S}_{profile}'
    s = slug(label)
    return f'{sid}_{s}' if s else sid


def now_iso() -> str:
    return datetime.now().astimezone().isoformat(timespec='seconds')


def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for chunk in iter(lambda: f.read(1 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


def snapshot_params(ws: Path | None, globs: list[str], dest: Path, max_mb: float) -> list[dict]:
    """파라미터 파일 해시 + 사본. 총량이 max_mb를 넘으면 그 뒤로는 해시만 남긴다."""
    if ws is None:
        return []
    out, copied_bytes, seen = [], 0, set()
    for pattern in globs:
        for p in sorted(glob.glob(str(ws / pattern), recursive=True)):
            path = Path(p)
            rel = path.relative_to(ws)
            if not path.is_file() or rel in seen or any(part in ('build', 'install', 'log') for part in rel.parts):
                continue
            seen.add(rel)
            size = path.stat().st_size
            entry = {'path': str(rel), 'sha256': sha256_file(path), 'size': size, 'copied': False}
            if copied_bytes + size <= max_mb * 1024 * 1024:
                target = dest / rel
                target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(path, target)
                copied_bytes += size
                entry['copied'] = True
            out.append(entry)
    return out


def running_launches() -> list[str]:
    """실행 중인 ros2 launch 명령줄 — '어떤 런치를 켰나'."""
    try:
        import psutil
    except ImportError:
        return []
    out = []
    for p in psutil.process_iter(['cmdline']):
        cmd = p.info.get('cmdline') or []
        joined = ' '.join(cmd)
        if 'ros2' in joined and ' launch ' in f' {joined} ' and 'bag' not in cmd:
            out.append(joined)
    return sorted(set(out))


def fta_status() -> str:
    try:
        r = subprocess.run(['systemctl', 'is-active', 'fta_agent'], capture_output=True,
                           text=True, timeout=3, check=False)
        return r.stdout.strip() or 'unknown'
    except (OSError, subprocess.TimeoutExpired):
        return 'unknown'


class Session:
    def __init__(self, path: Path):
        self.path = Path(path)

    # ---- 경로 ----------------------------------------------------------
    @property
    def id(self) -> str:
        return self.path.name

    manifest_path = property(lambda self: self.path / 'manifest.yaml')
    profile_path = property(lambda self: self.path / 'profile.yaml')
    bag_dir = property(lambda self: self.path / 'bag')
    params_dir = property(lambda self: self.path / 'params')
    health_path = property(lambda self: self.path / 'health.csv')
    system_path = property(lambda self: self.path / 'system.csv')
    markers_path = property(lambda self: self.path / 'markers.jsonl')
    recorder_log = property(lambda self: self.path / 'recorder.log')
    monitor_log = property(lambda self: self.path / 'monitor.log')
    qos_path = property(lambda self: self.path / 'qos_overrides.yaml')
    monitor_config_path = property(lambda self: self.path / 'monitor_config.json')
    _lock_path = property(lambda self: self.path / '.manifest.lock')

    # ---- 생성 ----------------------------------------------------------
    @classmethod
    def create(cls, root: Path, resolved: ResolvedProfile, *, label: str = '', notes: str = '',
               workspace: Path | None = None, git: dict | None = None,
               params: list[dict] | None = None, nodes: list[str] | None = None,
               launches: list[str] | None = None, fta: str | None = None,
               now: datetime | None = None) -> 'Session':
        root = Path(root)
        root.mkdir(parents=True, exist_ok=True)
        sid = make_session_id(resolved.name, label, now)
        path = root / sid
        n = 1
        while path.exists():                 # 같은 초에 두 번 시작한 경우
            n += 1
            path = root / f'{sid}_{n}'
        path.mkdir()
        s = cls(path)
        write_yaml(s.profile_path, {
            'name': resolved.name, 'description': resolved.description, 'chain': resolved.chain,
            'topics': resolved.topics, 'unknown_topics': resolved.unknown_topics,
            'options': resolved.options.to_dict(),
        })
        manifest = {
            'schema': SCHEMA,
            'session_id': s.id,
            'status': STATUS_RECORDING,
            'label': label,
            'notes': notes,
            'operator': getpass.getuser(),
            'host': socket.gethostname(),
            'started_at': now_iso(),
            'ended_at': None,
            'duration_sec': None,
            'profile': {
                'name': resolved.name, 'chain': resolved.chain, 'description': resolved.description,
                'topics': resolved.topics, 'unknown_topics': resolved.unknown_topics,
                'options': resolved.options.to_dict(),
            },
            'environment': {
                'ros_domain_id': os.environ.get('ROS_DOMAIN_ID', '0'),
                'rmw': os.environ.get('RMW_IMPLEMENTATION', '(default)'),
                'workspace': str(workspace) if workspace else None,
            },
            'git': git or {},
            'params': params or [],
            'ros_graph': {'nodes': nodes or [], 'launches': launches or []},
            'fta_agent': fta,
        }
        write_yaml(s.manifest_path, manifest)
        return s

    # ---- manifest ------------------------------------------------------
    @contextmanager
    def _locked(self):
        self.path.mkdir(parents=True, exist_ok=True)
        with open(self._lock_path, 'w') as lock:
            fcntl.flock(lock, fcntl.LOCK_EX)
            try:
                yield
            finally:
                fcntl.flock(lock, fcntl.LOCK_UN)

    def read_manifest(self) -> dict[str, Any]:
        try:
            return load_yaml(self.manifest_path) or {}
        except FileNotFoundError:
            return {}

    def update_manifest(self, **values: Any) -> dict[str, Any]:
        with self._locked():
            m = self.read_manifest()
            m.update(values)
            write_yaml(self.manifest_path, m)
            return m

    @property
    def status(self) -> str:
        return self.read_manifest().get('status', 'unknown_end')

    def finalize(self, status: str | None = None, force: bool = False) -> dict[str, Any]:
        """녹화 종료 처리. 이미 끝난 세션은 force 없이는 건드리지 않는다.

        status를 주지 않으면 manifest의 stop_reason으로 정한다
        (user → completed, disk_low → stopped_disk_low, 없음 → recorder_exited).
        """
        with self._locked():
            m = self.read_manifest()
            if m.get('status') != STATUS_RECORDING and not force:
                return m
            if status is None:
                status = STOP_REASON_STATUS.get(m.get('stop_reason'), 'recorder_exited')
            ended = datetime.now().astimezone()
            duration = None
            try:
                duration = round((ended - datetime.fromisoformat(m['started_at'])).total_seconds(), 1)
            except (KeyError, TypeError, ValueError):
                pass
            files = self.bag_files()
            m.update({
                'status': status,
                'ended_at': ended.isoformat(timespec='seconds'),
                'duration_sec': duration,
                'bag': {'files': files, 'total_bytes': sum(f['size'] for f in files)},
                'markers': self.marker_count(),
            })
            write_yaml(self.manifest_path, m)
            return m

    # ---- 녹화 결과 -----------------------------------------------------
    def bag_files(self) -> list[dict]:
        if not self.bag_dir.is_dir():
            return []
        return [{'name': p.name, 'size': p.stat().st_size}
                for p in sorted(self.bag_dir.iterdir()) if p.is_file()]

    def bag_bytes(self) -> int:
        total = 0
        if self.bag_dir.is_dir():
            for p in self.bag_dir.iterdir():
                try:
                    total += p.stat().st_size
                except FileNotFoundError:   # 분할 중 rename
                    pass
        return total

    # ---- 마커 ----------------------------------------------------------
    def append_marker(self, marker: dict[str, Any]) -> None:
        line = json.dumps(marker, ensure_ascii=False) + '\n'
        with open(self.markers_path, 'a', encoding='utf-8') as f:
            f.write(line)

    def markers(self) -> list[dict]:
        if not self.markers_path.exists():
            return []
        out = []
        for line in self.markers_path.read_text(encoding='utf-8').splitlines():
            try:
                out.append(json.loads(line))
            except json.JSONDecodeError:
                continue
        return out

    def marker_count(self) -> int:
        if not self.markers_path.exists():
            return 0
        with open(self.markers_path, encoding='utf-8') as f:
            return sum(1 for line in f if line.strip())


def list_sessions(root: Path) -> list[Session]:
    root = Path(root)
    if not root.is_dir():
        return []
    sessions = [Session(p.parent) for p in root.glob('*/manifest.yaml')]
    return sorted(sessions, key=lambda s: s.id, reverse=True)

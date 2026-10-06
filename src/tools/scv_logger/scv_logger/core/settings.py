"""사용자(차량)별 설정 — ~/.config/scv_logger/settings.yaml.

프로파일·카탈로그와 달리 git에 들어가지 않는 값(저장 경로 등)만 둔다.
"""
from __future__ import annotations

from dataclasses import asdict, dataclass, field
from pathlib import Path

from ..paths import settings_path
from .yamlio import load_yaml, write_yaml

# 세션 시작 시 해시를 남기고 사본을 params/에 복사할 파일 (워크스페이스 기준 glob)
DEFAULT_PARAM_GLOBS = [
    'src/command_center/**/config/*.yaml',
    'src/localization/robot_localization/params/scv*.yaml',
    'src/localization/SCV_localization_ros2/**/config/*.yaml',
    'src/vehicle/hunter2_description/urdf/tf_mounts.xacro',
    'src/bring_up/launch/*.py',
]


def default_output_dir() -> str:
    # 두 번째 SSD가 있으면 그쪽에 — OS·주행 노드와 디스크 I/O를 분리한다
    ssd = Path('~/ssd2').expanduser()
    base = ssd if ssd.is_dir() else Path('~').expanduser()
    return str(base / 'scv_logs')


@dataclass
class Settings:
    output_dir: str = field(default_factory=default_output_dir)
    hz_tolerance: float = 0.8           # 기준 주기의 이 비율 미만이면 '낮음'
    stop_timeout_sec: float = 20.0      # 녹화 정지 시 SIGINT 후 대기 한도
    param_globs: list[str] = field(default_factory=lambda: list(DEFAULT_PARAM_GLOBS))
    param_copy_max_mb: float = 5.0

    @classmethod
    def load(cls, path: Path | None = None) -> 'Settings':
        path = Path(path or settings_path())
        s = cls()
        if path.exists():
            data = load_yaml(path) or {}
            for k, v in data.items():
                if hasattr(s, k) and v is not None:
                    setattr(s, k, v)
        s.hz_tolerance = min(max(float(s.hz_tolerance), 0.1), 1.0)
        return s

    def save(self, path: Path | None = None) -> None:
        write_yaml(Path(path or settings_path()), asdict(self))

    @property
    def output_path(self) -> Path:
        return Path(self.output_dir).expanduser()

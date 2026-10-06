"""설정·작업공간·상태 파일 경로 탐색.

설정(catalog.yaml, profiles/)은 가능하면 **소스 트리**에서 읽고 쓴다. GUI에서
고친 프로파일이 git으로 추적되고 팀원과 공유되게 하려는 것이다. 설치 경로
(install/share)는 colcon 재빌드 때 덮어써지므로 쓰기 대상으로 쓰지 않는다.
"""
from __future__ import annotations

import os
from pathlib import Path

PACKAGE = 'scv_logger'
SOURCE_REL = Path('src/tools/scv_logger')


def find_workspace_root() -> Path | None:
    """SCV 워크스페이스 루트. SCV_WS > AMENT_PREFIX_PATH > 소스 위치 순."""
    env = os.environ.get('SCV_WS')
    if env:
        return Path(env).expanduser()
    for entry in os.environ.get('AMENT_PREFIX_PATH', '').split(os.pathsep):
        p = Path(entry)
        if p.name == PACKAGE and p.parent.name == 'install':
            return p.parent.parent
    for parent in Path(__file__).resolve().parents:
        if (parent / SOURCE_REL).is_dir():
            return parent
    return None


def find_config_dir(workspace: Path | None = None) -> Path:
    """catalog.yaml과 profiles/가 있는 디렉토리."""
    env = os.environ.get('SCV_LOGGER_CONFIG')
    if env:
        return Path(env).expanduser()
    ws = workspace or find_workspace_root()
    if ws and (ws / SOURCE_REL / 'config').is_dir():
        return ws / SOURCE_REL / 'config'
    try:
        from ament_index_python.packages import get_package_share_directory
        return Path(get_package_share_directory(PACKAGE)) / 'config'
    except Exception:
        return Path(__file__).resolve().parent.parent / 'config'


def state_dir() -> Path:
    """실행 중인 녹화 상태(active.json) 등 런타임 파일 위치."""
    base = Path(os.environ.get('XDG_STATE_HOME', '~/.local/state')).expanduser()
    return base / PACKAGE


def settings_path() -> Path:
    base = Path(os.environ.get('XDG_CONFIG_HOME', '~/.config')).expanduser()
    return base / PACKAGE / 'settings.yaml'

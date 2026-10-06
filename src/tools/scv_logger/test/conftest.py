import sys
from pathlib import Path

import pytest

PKG = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PKG))

from scv_logger.core.catalog import Catalog  # noqa: E402


@pytest.fixture
def catalog() -> Catalog:
    return Catalog.from_dict({
        'heavy_threshold_kb': 500,
        'auto_markers': [{'topic': '/mux', 'label': '모드'}],
        'groups': {
            'lidar': {'topics': {
                '/packets': {'hz': 10, 'size_kb': 200, 'required': True},
                '/points': {'hz': 10, 'size_kb': 1200, 'heavy': True},
            }},
            'camera': {'topics': {
                '/cam/info': {'hz': 15, 'size_kb': 0.5},
                '/cam/image': {'hz': 15, 'size_kb': 2700, 'heavy': True, 'monitor_via': '/cam/info'},
            }},
            'control': {'topics': {
                '/cmd_vel': {'hz': 10, 'size_kb': 0.1},
                '/mux': {},
            }},
            'tf': {'topics': {'/tf_static': {'latched': True}}},
        },
    })


@pytest.fixture
def config_dir() -> Path:
    return PKG / 'config'

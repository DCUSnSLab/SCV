from pathlib import Path

from scv_logger.constants import HEALTH_TOPIC, MARKER_TOPIC
from scv_logger.core.command import (build_record_command, estimate_mb_per_min, monitor_config,
                                     qos_overrides)
from scv_logger.core.profile import RecordOptions, ResolvedProfile


def resolved(topics, unknown=(), **opts):
    return ResolvedProfile('p', '', ['p'], list(topics), RecordOptions(**opts), list(unknown))


def test_command_mcap(catalog):
    r = resolved(['/packets', '/points'], ['/x'], split_duration_sec=300, compression='none')
    cmd = build_record_command(r, Path('/s/bag'), Path('/s/qos.yaml'))
    assert cmd[:4] == ['ros2', 'bag', 'record', '-o']
    assert cmd[cmd.index('-s') + 1] == 'mcap'
    assert cmd[cmd.index('--max-bag-duration') + 1] == '300'
    assert cmd[cmd.index('--storage-preset-profile') + 1] == 'fastwrite'
    assert cmd[cmd.index('--qos-profile-overrides-path') + 1] == '/s/qos.yaml'
    assert cmd[-5:] == ['/packets', '/points', '/x', MARKER_TOPIC, HEALTH_TOPIC]
    assert '--compression-mode' not in cmd


def test_command_sqlite_zstd_no_split(catalog):
    r = resolved(['/packets'], storage='sqlite3', compression='zstd', split_duration_sec=0, split_size_mb=512)
    cmd = build_record_command(r, Path('/b'))
    assert '--max-bag-duration' not in cmd
    assert cmd[cmd.index('--max-bag-size') + 1] == str(512 * 1024 * 1024)
    assert cmd[cmd.index('--compression-mode') + 1] == 'file'
    assert '--storage-preset-profile' not in cmd


def test_qos_overrides_only_heavy(catalog):
    r = resolved(['/packets', '/points', '/cam/image', '/tf_static'])
    assert set(qos_overrides(r, catalog)) == {'/points', '/cam/image'}
    assert qos_overrides(r, catalog)['/points']['reliability'] == 'best_effort'
    assert qos_overrides(resolved(['/points'], heavy_qos='keep'), catalog) == {}


def test_estimate(catalog):
    mb, unknown = estimate_mb_per_min(resolved(['/packets', '/mux', '/tf_static'], ['/x']), catalog)
    assert round(mb, 3) == round(10 * 200 * 60 / 1024, 3)
    assert unknown == ['/x', '/mux']


def test_monitor_config(catalog, tmp_path):
    cfg = monitor_config(resolved(['/cam/image', '/packets'], ['/x']), catalog,
                         hz_tolerance=0.7, output_dir=tmp_path)
    by = {t['name']: t for t in cfg['topics']}
    assert by['/cam/image']['monitor'] == '/cam/info'
    assert by['/packets']['required'] and not by['/x']['required']
    assert by['/x']['monitor'] == '/x' and by['/x']['hz'] is None
    assert cfg['auto_markers'] == [{'topic': '/mux', 'label': '모드'}]

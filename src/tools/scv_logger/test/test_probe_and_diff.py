import pytest

pytest.importorskip('rclpy')

from scv_logger.core.catalog_diff import ScanEntry, apply_items, diff_catalog  # noqa: E402
from scv_logger.ros.monitor_node import extract_field, strip_stamps  # noqa: E402
from scv_logger.ros.probe import evaluate, measure_hz  # noqa: E402


def arrivals(hz, seconds, end=100.0):
    n = int(hz * seconds)
    return [end - seconds + i / hz for i in range(n + 1)]


def test_measure_hz():
    hz, age = measure_hz(arrivals(10, 3), now=100.05, window=3)
    assert abs(hz - 10) < 0.2 and abs(age - 0.05) < 1e-6
    assert measure_hz([], 1.0, 3) == (0.0, None)


@pytest.mark.parametrize('kw, status', [
    (dict(expected=10, arr=arrivals(10, 3), now=100.05, publishers=1), 'ok'),
    (dict(expected=10, arr=arrivals(5, 3), now=100.05, publishers=1), 'low'),
    (dict(expected=10, arr=arrivals(10, 3), now=110.0, publishers=1), 'stale'),
    (dict(expected=10, arr=arrivals(10, 3), now=110.0, publishers=0), 'no_publisher'),
    (dict(expected=10, arr=[], now=1.0, publishers=1), 'waiting'),
    (dict(expected=10, arr=[], now=1.0, publishers=0), 'no_publisher'),
    (dict(expected=None, arr=arrivals(1, 3), now=100.05, publishers=1), 'ok'),
    (dict(expected=10, arr=[], now=1.0, publishers=1, error='type_unavailable: x'), 'type_unavailable'),
    (dict(expected=None, arr=[], now=1.0, publishers=1, latched=True), 'ok'),
    (dict(expected=None, arr=[], now=1.0, publishers=0, latched=True), 'latched_missing'),
])
def test_evaluate(kw, status):
    arr = kw.pop('arr')
    assert evaluate(kw.pop('expected'), arr, kw.pop('now'), **kw)['status'] == status


def test_strip_and_extract():
    msg = {'header': {'stamp': 1}, 'mode': 2, 'inner': {'stamp': 3, 'v': [{'stamp': 4, 'x': 5}]}}
    assert strip_stamps(msg) == {'mode': 2, 'inner': {'v': [{'x': 5}]}}
    assert extract_field(msg, 'inner.v') == [{'stamp': 4, 'x': 5}]
    assert extract_field(msg, 'nope.x') is None


def test_diff_and_apply(catalog):
    entries = [
        ScanEntry('/packets', 'velodyne_msgs/msg/VelodyneScan', hz=10.1, size_kb=210),   # 같음 (type만 채움)
        ScanEntry('/cmd_vel', 'geometry_msgs/msg/Twist', hz=20.0, size_kb=0.1),         # hz 다름
        ScanEntry('/new/img', 'sensor_msgs/msg/Image', hz=15, size_kb=900),             # 새 토픽, heavy 제안
        ScanEntry('/tf_static', 'tf2_msgs/msg/TFMessage', latched=True),
    ]
    items = {i.name: i for i in diff_catalog(catalog, entries)}
    assert items['/new/img'].kind == 'new' and items['/new/img'].suggest_heavy
    assert items['/cmd_vel'].kind == 'changed' and items['/cmd_vel'].changes['hz'] == (10.0, 20.0)
    assert items['/packets'].changes == {'type': (None, 'velodyne_msgs/msg/VelodyneScan')}
    assert items['/points'].kind == 'missing'
    n = apply_items(catalog, [(items['/new/img'], 'camera'), (items['/cmd_vel'], None),
                              (items['/points'], None)], remove_missing=True)
    assert n == 3
    assert catalog.topic('/new/img').heavy and catalog.topic('/new/img').group == 'camera'
    assert catalog.topic('/cmd_vel').hz == 20.0
    assert catalog.topic('/points') is None


def test_round_kb_never_zero(catalog, tmp_path):
    from scv_logger.core.catalog_diff import round_kb
    assert round_kb(0.004) == 0.01 and round_kb(0.123) == 0.12 and round_kb(5.55) == 5.5 and round_kb(1234.4) == 1234.0
    items = diff_catalog(catalog, [ScanEntry('/tiny', 'std_msgs/msg/Bool', hz=1, size_kb=0.001)])
    new = [i for i in items if i.name == '/tiny'][0]
    apply_items(catalog, [(new, 'control')])
    catalog.save(tmp_path / 'c.yaml')   # 저장 전 검증을 통과해야 함

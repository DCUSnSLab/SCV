import pytest

from scv_logger.core.catalog import Catalog, CatalogError, TopicSpec


def test_lookup_and_order(catalog):
    assert catalog.topic('/points').heavy
    assert catalog.topic('/cam/image').monitor_topic == '/cam/info'
    assert catalog.topic('/cmd_vel').monitor_topic == '/cmd_vel'
    assert catalog.group_topics('camera') == ['/cam/info', '/cam/image']
    assert catalog.sort_topics(['/zzz', '/cmd_vel', '/packets']) == ['/packets', '/cmd_vel', '/zzz']


def test_roundtrip(catalog, tmp_path):
    p = tmp_path / 'catalog.yaml'
    catalog.save(p)
    again = Catalog.load(p)
    assert again.to_dict() == catalog.to_dict()
    assert p.read_text(encoding='utf-8').startswith('# SCV Logger')


@pytest.mark.parametrize('data, msg', [
    ({'groups': {'a': {'topics': {'/x': {}}}, 'b': {'topics': {'/x': {}}}}}, '한 그룹에만'),
    ({'groups': {'a': {'topics': {'x': {}}}}}, '토픽 이름'),
    ({'groups': {'a': {'topics': {'/x': {'hz': -1}}}}}, '양수'),
    ({'groups': {'a': {'topics': {'/x': {'hzz': 1}}}}}, '알 수 없는 키'),
    ({'groups': {'A': {}}}, '그룹 이름'),
    ({'groups': {'a': {'topics': {'/x': {'type': 'Imu'}}}}}, 'pkg/msg/Type'),
    ({'groups': {'a': {'topics': {'/x': {'required': 'yes'}}}}}, 'true/false'),
])
def test_validation(data, msg):
    with pytest.raises(CatalogError, match=msg):
        Catalog.from_dict(data)


def test_edit(catalog):
    catalog.add_topic(TopicSpec('/new', 'control', hz=5))
    with pytest.raises(CatalogError):
        catalog.add_topic(TopicSpec('/new', 'control'))
    catalog.update_topic('/cmd_vel', TopicSpec('/cmd_vel2', 'control', hz=20))
    assert catalog.group_topics('control') == ['/cmd_vel2', '/mux', '/new']   # 순서 유지
    catalog.update_topic('/new', TopicSpec('/new', 'lidar'))
    assert '/new' in catalog.group_topics('lidar')
    catalog.remove_topic('/new')
    assert catalog.topic('/new') is None
    with pytest.raises(CatalogError):
        catalog.add_group('lidar')

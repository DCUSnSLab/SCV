"""저장소에 들어 있는 카탈로그·프로파일이 전부 유효한지."""
from scv_logger.core.catalog import Catalog
from scv_logger.core.profile import ProfileStore


def test_shipped_config_resolves(config_dir):
    cat = Catalog.load(config_dir / 'catalog.yaml')
    store = ProfileStore(config_dir / 'profiles')
    names = store.names()
    assert 'drive_standard' in names and 'base' in names
    for n in names:
        r = store.resolve(n, cat)
        assert r.unknown_topics == [], n
        if not r.abstract:
            assert r.topics, n
    # 모든 monitor_via 대상이 카탈로그에 있어야 주기를 잴 수 있다
    for t in cat.topics():
        if t.monitor_via:
            assert cat.topic(t.monitor_via) is not None, t.name
    # drive_standard는 원본 카메라·포인트클라우드를 녹화하지 않는다
    std = store.resolve('drive_standard', cat)
    assert '/velodyne_points' not in std.topics
    assert not any(cat.topic(t).heavy for t in std.topics)

import pytest

from scv_logger.core.profile import (Profile, ProfileError, ProfileStore, RecordOptions,
                                     profile_from_selection)
from scv_logger.core.yamlio import write_yaml


@pytest.fixture
def store(tmp_path):
    d = tmp_path / 'profiles'
    write_yaml(d / 'base.yaml', {'name': 'base', 'abstract': True, 'options': {'split_duration_sec': 300}})
    write_yaml(d / 'std.yaml', {'name': 'std', 'extends': 'base', 'groups': ['lidar', 'camera', 'control']})
    write_yaml(d / 'light.yaml', {'name': 'light', 'extends': 'std', 'exclude_groups': ['camera'],
                                  'exclude': ['/points'], 'topics': ['/extra/topic'],
                                  'options': {'compression': 'zstd'}})
    return ProfileStore(d)


def test_resolve_inheritance(store, catalog):
    r = store.resolve('light', catalog)
    assert r.chain == ['light', 'std', 'base']
    assert r.topics == ['/packets', '/cmd_vel', '/mux']
    assert r.unknown_topics == ['/extra/topic']
    assert r.options.compression == 'zstd'
    assert r.options.split_duration_sec == 300
    assert store.resolve('base', catalog).abstract


def test_cycle_and_unknown_group(store, catalog):
    write_yaml(store.path('a'), {'name': 'a', 'extends': 'b'})
    write_yaml(store.path('b'), {'name': 'b', 'extends': 'a'})
    with pytest.raises(ProfileError, match='순환'):
        store.resolve('a', catalog)
    write_yaml(store.path('bad'), {'name': 'bad', 'groups': ['nope']})
    with pytest.raises(ProfileError, match='없는 그룹'):
        store.resolve('bad', catalog)


@pytest.mark.parametrize('opts, msg', [
    ({'storage': 'bag'}, '선택지'),
    ({'split_duration_sec': -1}, '정수'),
    ({'disk_stop_gb': 50, 'disk_warn_gb': 10}, 'disk_stop_gb'),
    ({'nope': 1}, '알 수 없는'),
])
def test_option_validation(opts, msg):
    with pytest.raises(ProfileError, match=msg):
        RecordOptions.from_dict(opts)


def test_name_must_match_file(store):
    write_yaml(store.path('x'), {'name': 'y'})
    with pytest.raises(ProfileError, match='파일 이름'):
        store.load('x')


def test_delete_refuses_parent(store):
    with pytest.raises(ProfileError, match='상속'):
        store.delete('std')
    store.delete('light')
    assert 'light' not in store.names()


@pytest.mark.parametrize('selection', [
    ['/packets', '/cmd_vel', '/mux'],                     # 그룹 통째 제외 + 토픽 제외
    ['/packets', '/points', '/cam/info', '/cam/image', '/cmd_vel', '/mux', '/tf_static'],  # 그룹 추가
    ['/packets'],
    ['/points', '/cam/info', '/new/one'],                 # 카탈로그 밖 토픽
])
def test_selection_roundtrip(store, catalog, selection):
    """GUI 선택 → 부모 대비 차이로 저장 → 다시 해석하면 같은 선택이 나와야 한다."""
    parent = store.resolve('std', catalog)
    opts = RecordOptions(compression='zstd', split_duration_sec=60)
    prof = profile_from_selection('child', 'desc', selection, opts, catalog, parent)
    store.save(prof, catalog)
    r = store.resolve('child', catalog)
    assert sorted(r.topics + r.unknown_topics) == sorted(selection)
    assert r.options == opts
    assert prof.options == {'compression': 'zstd', 'split_duration_sec': 60}


def test_selection_without_parent_uses_groups(catalog, tmp_path):
    prof = profile_from_selection('p', '', ['/packets', '/points', '/cmd_vel'], RecordOptions(), catalog)
    assert prof.groups == ['lidar'] and prof.topics == ['/cmd_vel'] and prof.options == {}
    store = ProfileStore(tmp_path)
    store.save(prof, catalog)
    assert store.resolve('p', catalog).topics == ['/packets', '/points', '/cmd_vel']


def test_profile_from_dict_rejects_bad_topic():
    with pytest.raises(ProfileError, match='토픽 이름'):
        Profile.from_dict({'name': 'x', 'topics': ['bad']}, 'x')

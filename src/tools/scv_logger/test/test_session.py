import threading
from datetime import datetime

from scv_logger.core.profile import RecordOptions, ResolvedProfile
from scv_logger.core.session import Session, list_sessions, make_session_id, snapshot_params


def make(tmp_path, label='n026 테스트!'):
    r = ResolvedProfile('drive', 'd', ['drive', 'base'], ['/a'], RecordOptions(), ['/x'])
    return Session.create(tmp_path, r, label=label, notes='메모', git={'k': 1},
                          now=datetime(2026, 10, 6, 15, 30, 12))


def test_session_id():
    assert make_session_id('p', '', datetime(2026, 1, 2, 3, 4, 5)) == '20260102_030405_p'
    assert make_session_id('p', 'a b/c', datetime(2026, 1, 2, 3, 4, 5)) == '20260102_030405_p_a_b_c'


def test_create_and_finalize(tmp_path):
    s = make(tmp_path)
    assert s.id == '20261006_153012_drive_n026_테스트'
    m = s.read_manifest()
    assert m['status'] == 'recording' and m['notes'] == '메모'
    assert m['profile']['unknown_topics'] == ['/x']
    s.bag_dir.mkdir()
    (s.bag_dir / 'x_0.mcap').write_bytes(b'12345')
    s.append_marker({'kind': 'note', 'text': 'hi'})
    s.update_manifest(stop_reason='user')
    m = s.finalize()
    assert m['status'] == 'completed'
    assert m['bag']['total_bytes'] == 5 and m['markers'] == 1
    # 이미 끝난 세션은 다시 마감하지 않는다
    assert s.finalize('recorder_exited')['status'] == 'completed'


def test_finalize_status_from_reason(tmp_path):
    a = make(tmp_path, 'a')
    a.update_manifest(stop_reason='disk_low')
    assert a.finalize()['status'] == 'stopped_disk_low'
    b = make(tmp_path, 'b')
    assert b.finalize()['status'] == 'recorder_exited'


def test_same_second_creates_new_dir(tmp_path):
    assert make(tmp_path).path != make(tmp_path).path
    assert len(list_sessions(tmp_path)) == 2


def test_concurrent_manifest_updates(tmp_path):
    s = make(tmp_path)

    def worker(i):
        for j in range(20):
            s.update_manifest(**{f'k{i}': j})

    threads = [threading.Thread(target=worker, args=(i,)) for i in range(4)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()
    m = s.read_manifest()
    assert all(m[f'k{i}'] == 19 for i in range(4))


def test_snapshot_params(tmp_path):
    ws = tmp_path / 'ws'
    (ws / 'src/a/config').mkdir(parents=True)
    (ws / 'src/a/config/p.yaml').write_text('x: 1')
    (ws / 'src/a/config/big.yaml').write_text('y' * 3000)
    (ws / 'build/a/config').mkdir(parents=True)
    (ws / 'build/a/config/p.yaml').write_text('ignored')
    out = snapshot_params(ws, ['src/**/config/*.yaml', 'build/**/*.yaml'], tmp_path / 'params', max_mb=0.001)
    by = {e['path']: e for e in out}
    assert set(by) == {'src/a/config/p.yaml', 'src/a/config/big.yaml'}
    assert by['src/a/config/p.yaml']['copied'] and not by['src/a/config/big.yaml']['copied']
    assert (tmp_path / 'params/src/a/config/p.yaml').read_text() == 'x: 1'

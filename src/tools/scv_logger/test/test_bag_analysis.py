import json
import struct

from scv_logger.core.bag_analysis import analyze, parse_recorder_lost
from scv_logger.core.bag_scan import MAGIC, mcap_types, scan_mcap

S = 1_000_000_000


def _rec(op: int, body: bytes) -> bytes:
    return struct.pack('<BQ', op, len(body)) + body


def _str(s: str) -> bytes:
    b = s.encode()
    return struct.pack('<I', len(b)) + b


def write_mcap(path, topics: dict[str, list[int]]):
    """최소 mcap: Schema·Channel·Message 레코드 (청크 없음 = fastwrite와 같은 구조)."""
    out = bytearray(MAGIC)
    for i, (topic, times) in enumerate(topics.items(), start=1):
        out += _rec(0x03, struct.pack('<H', i) + _str('std_msgs/msg/String') + _str('ros2msg') + _str(''))
        out += _rec(0x04, struct.pack('<HH', i, i) + _str(topic) + _str('cdr') + struct.pack('<I', 0))
    msgs = sorted((t, i) for i, times in enumerate(topics.values(), start=1) for t in times)
    for t, i in msgs:
        out += _rec(0x05, struct.pack('<HIQQ', i, 0, t, t) + b'x' * 300)
    out += _rec(0x0F, struct.pack('<I', 0))
    path.write_bytes(bytes(out))


def test_scan_mcap_and_types(tmp_path):
    p = tmp_path / 'bag_0.mcap'
    write_mcap(p, {'/a': [S, 2 * S, 3 * S], '/b': [S + 5]})
    out = {}
    scan_mcap(p, out)
    assert list(out['/a']) == [S, 2 * S, 3 * S] and list(out['/b']) == [S + 5]
    assert mcap_types([p]) == {'/a': 'std_msgs/msg/String', '/b': 'std_msgs/msg/String'}


def test_parse_recorder_lost(tmp_path):
    log = tmp_path / 'recorder.log'
    log.write_text('[WARN] Cache buffers lost messages per topic: \n\t/a: 3\nTotal lost: 3\n'
                   '[WARN] Cache buffers lost messages per topic: \n\t/a: 10\n\t/b: 2\nTotal lost: 12\n[INFO] x\n')
    assert parse_recorder_lost(log) == ({'/a': 10, '/b': 2}, 12)
    assert parse_recorder_lost(tmp_path / 'none.log') == ({}, 0)


def test_analyze_session(tmp_path):
    """/a: 원본 10 Hz 중 절반만 녹화, /b: 전부 녹화, /c: 원본 자체가 없음."""
    sess = tmp_path / 'sess'
    (sess / 'bag').mkdir(parents=True)
    t0 = 1_000 * S
    a = [t0 + k * S // 5 for k in range(100)]                  # 20초 동안 5 Hz
    b = [t0 + k * S // 10 for k in range(200)]                 # 20초 동안 10 Hz
    write_mcap(sess / 'bag' / 'bag_0.mcap', {'/a': a, '/b': b})
    (sess / 'manifest.yaml').write_text('profile: {name: p, topics: [/a, /b, /c], unknown_topics: []}\nstatus: completed\n')
    (sess / 'monitor_config.json').write_text(json.dumps({'topics': [
        {'name': '/a', 'hz': 10}, {'name': '/b', 'hz': 10}, {'name': '/c', 'hz': 10}]}))
    rows = ['time,topic,hz,age_s,status,issues']
    for k in range(20):
        ts = 1000 + k + 0.5
        b_row = f'{ts},/b,10.0,0.0,abnormal,가속도 크기 {3 + k * 0.1:.1f} m/s² | stamp 역행 {k}회' if k < 3 else f'{ts},/b,10.0,0.0,ok,'
        rows += [f'{ts},/a,10.0,0.0,ok,', b_row, f'{ts},/c,0.0,,no_publisher,']
    (sess / 'health.csv').write_text('\n'.join(rows) + '\n')
    (sess / 'recorder.log').write_text('Cache buffers lost messages per topic: \n\t/a: 100\nTotal lost: 100\n')

    r = analyze(sess, target_bins=4)
    by = {t['name']: t for t in r['topics']}
    assert [t['name'] for t in r['topics']] == ['/a', '/b', '/c']
    assert by['/a']['verdict'] == 'warn' and abs(by['/a']['coverage'] - 0.5) < 0.05 and by['/a']['lost'] == 100
    assert by['/b']['verdict'] == 'good'
    # 값 이상: 3초, 숫자만 다른 문구는 하나로
    assert by['/b']['abnormal_s'] == 3 and len(by['/b']['abnormal_issues']) == 2
    assert by['/a']['abnormal_s'] == 0
    assert by['/c']['verdict'] == 'source' and all(by['/c']['src_off'])
    assert r['lost_total'] == 100 and r['recorder_log']
    assert (sess / 'analysis.json').exists()
    # metadata.yaml·recorder.log가 없어도 분석된다
    (sess / 'recorder.log').unlink()
    r2 = analyze(sess, target_bins=4, use_cache=False)
    assert not r2['recorder_log'] and r2['messages'] == 300

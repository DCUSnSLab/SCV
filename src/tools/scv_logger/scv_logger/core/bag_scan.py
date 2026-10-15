"""bag에서 토픽별 메시지 시각만 뽑는다 (본문은 읽지 않음).

mcap은 레코드 헤더만 읽고 본문은 seek로 건너뛴다. 청크(압축) 파일은 청크를 풀지 않고
청크 뒤의 MessageIndex(채널별 log_time 목록)를 읽는다. sqlite3는 messages 테이블의
timestamp만 조회한다. 외부 라이브러리 없이 동작한다.
"""
from __future__ import annotations

import sqlite3
import struct
from array import array
from pathlib import Path
from typing import Callable

from .yamlio import load_yaml

MAGIC = b'\x89MCAP0\r\n'
OP_CHANNEL, OP_MESSAGE, OP_CHUNK, OP_MESSAGE_INDEX, OP_DATA_END, OP_FOOTER = 0x04, 0x05, 0x06, 0x07, 0x0F, 0x02

Progress = Callable[[int, int], None]        # (읽은 바이트, 전체 바이트)


def _read_str(buf: bytes, pos: int) -> tuple[str, int]:
    n = struct.unpack_from('<I', buf, pos)[0]
    pos += 4
    return buf[pos:pos + n].decode('utf-8', 'replace'), pos + n


def scan_mcap(path: Path, out: dict[str, array], progress: Progress | None = None,
              done_bytes: int = 0, total_bytes: int = 0) -> int:
    """out[topic]에 log_time(ns)을 덧붙인다. 읽은 바이트 수를 돌려준다."""
    channels: dict[int, str] = {}
    chunk_times: dict[int, array] = {}       # 청크 파일: MessageIndex에서 모은 시각
    size = path.stat().st_size
    with open(path, "rb", buffering=1 << 16) as f:      # 작은 버퍼 — 큰 본문은 seek로 건너뛰게
        if f.read(8) != MAGIC:
            raise ValueError(f'mcap 파일이 아님: {path}')
        hdr = struct.Struct('<BQ')
        msg = struct.Struct('<HIQQ')
        last_report = 0
        while True:
            raw = f.read(9)
            if len(raw) < 9:
                break
            op, length = hdr.unpack(raw)
            if op == OP_MESSAGE:
                ch, _seq, log_time, _pub = msg.unpack(f.read(22))
                f.seek(length - 22, 1)
                topic = channels.get(ch)
                if topic is not None:
                    out.setdefault(topic, array('q')).append(log_time)
            elif op == OP_CHANNEL:
                body = f.read(length)
                cid = struct.unpack_from('<H', body, 0)[0]
                topic, _ = _read_str(body, 4)
                channels[cid] = topic
            elif op == OP_MESSAGE_INDEX:
                body = f.read(length)
                cid = struct.unpack_from('<H', body, 0)[0]
                n = struct.unpack_from('<I', body, 2)[0] // 16
                times = struct.unpack_from(f'<{2 * n}Q', body, 6)[0::2]
                chunk_times.setdefault(cid, array('q')).extend(times)
            elif op in (OP_DATA_END, OP_FOOTER):
                break
            else:                                  # 청크·스키마·헤더 등은 건너뜀
                f.seek(length, 1)
            if progress is not None:
                pos = f.tell()
                if pos - last_report > 256 << 20:
                    last_report = pos
                    progress(done_bytes + pos, total_bytes or size)
    for cid, times in chunk_times.items():
        topic = channels.get(cid)
        if topic is not None:
            out.setdefault(topic, array('q')).extend(times)
    return size


def scan_sqlite(path: Path, out: dict[str, array]) -> int:
    con = sqlite3.connect(f'file:{path}?mode=ro', uri=True)
    try:
        names = dict(con.execute('SELECT id, name FROM topics'))
        for tid, ts in con.execute('SELECT topic_id, timestamp FROM messages'):
            out.setdefault(names[tid], array('q')).append(ts)
    finally:
        con.close()
    return path.stat().st_size


def scan_bag(bag_dir: Path, progress: Progress | None = None) -> tuple[dict[str, array], dict[str, str]]:
    """bag 폴더 전체 → ({topic: 정렬된 log_time ns}, {topic: type})."""
    bag_dir = Path(bag_dir)
    meta_path = bag_dir / 'metadata.yaml'
    meta = (load_yaml(meta_path) or {}).get('rosbag2_bagfile_information', {}) if meta_path.exists() else {}
    types = {t['topic_metadata']['name']: t['topic_metadata']['type']
             for t in meta.get('topics_with_message_count', [])}
    files = [bag_dir / p for p in meta.get('relative_file_paths', [])] or \
        sorted(p for p in bag_dir.iterdir() if p.suffix in ('.mcap', '.db3'))
    files = [p for p in files if p.exists()]
    total = sum(p.stat().st_size for p in files)
    out: dict[str, array] = {}
    done = 0
    for p in files:
        if p.suffix == '.db3':
            done += scan_sqlite(p, out)
        else:
            done += scan_mcap(p, out, progress, done, total)
        if progress is not None:
            progress(done, total)
    for topic, times in out.items():
        out[topic] = array('q', sorted(times))
    if not types:
        types = mcap_types(files)
    return out, types


def mcap_types(files: list[Path]) -> dict[str, str]:
    """metadata.yaml이 없을 때 첫 mcap의 Schema·Channel 레코드에서 토픽 타입을 얻는다."""
    schemas: dict[int, str] = {}
    types: dict[str, str] = {}
    for p in files:
        if p.suffix != '.mcap':
            continue
        with open(p, 'rb', buffering=1 << 16) as f:
            if f.read(8) != MAGIC:
                continue
            while True:
                raw = f.read(9)
                if len(raw) < 9:
                    break
                op, length = struct.unpack('<BQ', raw)
                if op == 0x03:                                     # Schema
                    body = f.read(length)
                    sid = struct.unpack_from('<H', body, 0)[0]
                    schemas[sid], _ = _read_str(body, 2)
                elif op == OP_CHANNEL:
                    body = f.read(length)
                    sid = struct.unpack_from('<H', body, 2)[0]
                    topic, _ = _read_str(body, 4)
                    types[topic] = schemas.get(sid, '')
                elif op in (OP_MESSAGE, OP_CHUNK, OP_DATA_END, OP_FOOTER):
                    break                                          # 정의는 앞쪽에 몰려 있다
                else:
                    f.seek(length, 1)
        break
    return types

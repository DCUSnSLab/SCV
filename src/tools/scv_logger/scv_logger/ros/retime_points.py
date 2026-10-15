"""이미 녹화된 bag의 /velodyne_points 녹화 시각을 header stamp로 다시 맞춘 재생용 bag 만들기.

ros2 bag play는 녹화 시각(수신 시각) 기준으로 재생한다. 녹화 중 포인트클라우드가 늦게·몰려서
수신된 구간(2026-10-08 세션에서 최대 1초)이 있으면, 데이터는 10 Hz로 다 있어도 재생이 끊긴다.
이 도구는 모든 토픽을 복사하되 /velodyne_points만 녹화 시각 = header stamp로 바꾸고,
앞당겨진 메시지 때문에 순서가 섞이지 않게 2초 창에서 다시 정렬해 쓴다. 원본은 건드리지 않는다.

    scv_logger_retime_points --session <세션>      → <세션>/bag_retimed/
"""
from __future__ import annotations

import argparse
import heapq
import shutil
import sys
import time
from datetime import datetime
from pathlib import Path

import rosbag2_py

from .lidar_convert import emit, header_stamp, storage_id_of

TOPIC = '/velodyne_points'
WINDOW_NS = 2_000_000_000          # 재정렬 창
MAX_SHIFT_NS = 5_000_000_000       # stamp가 이보다 멀면 손대지 않음 (시계 이상 방어)


def retime(bag: Path, out: Path, topic: str = TOPIC) -> dict:
    reader = rosbag2_py.SequentialReader()
    reader.open(rosbag2_py.StorageOptions(uri=str(bag), storage_id=storage_id_of(bag)),
                rosbag2_py.ConverterOptions('cdr', 'cdr'))
    meta = reader.get_metadata()
    total = meta.message_count
    writer = rosbag2_py.SequentialWriter()
    opts = rosbag2_py.StorageOptions(uri=str(out), storage_id='mcap')
    if hasattr(opts, 'storage_preset_profile'):
        opts.storage_preset_profile = 'zstd_fast'
    writer.open(opts, rosbag2_py.ConverterOptions('cdr', 'cdr'))
    for tm in reader.get_all_topics_and_types():
        writer.create_topic(tm)

    heap: list = []
    seq = done = shifted = kept = 0
    shift_sum = shift_max = 0
    last_report = 0.0
    emit(stage='retime', done=0, total=total)
    while reader.has_next():
        name, data, t = reader.read_next()
        if name == topic:
            sec, ns = header_stamp(data)
            stamp = sec * 1_000_000_000 + ns
            if 0 < t - stamp < MAX_SHIFT_NS or 0 < stamp - t < MAX_SHIFT_NS:
                shift_sum += t - stamp
                shift_max = max(shift_max, t - stamp)
                t = stamp
                shifted += 1
            else:
                kept += 1
        heapq.heappush(heap, (t, seq, name, data))
        seq += 1
        while heap and heap[0][0] < t - WINDOW_NS:
            wt, _, wn, wd = heapq.heappop(heap)
            writer.write(wn, wd, wt)
        done += 1
        now = time.monotonic()
        if now - last_report > 1.0:
            last_report = now
            emit(stage='retime', done=done, total=total)
    while heap:
        wt, _, wn, wd = heapq.heappop(heap)
        writer.write(wn, wd, wt)
    del writer
    emit(stage='retime', done=done, total=total)
    return {'messages': done, 'shifted': shifted, 'kept': kept,
            'mean_shift_ms': round(shift_sum / shifted / 1e6, 1) if shifted else 0,
            'max_shift_ms': round(shift_max / 1e6, 1)}


def main(argv: list[str] | None = None) -> None:
    ap = argparse.ArgumentParser(description='/velodyne_points 녹화 시각을 header stamp로 맞춘 재생용 bag')
    ap.add_argument('--session', required=True)
    ap.add_argument('--topic', default=TOPIC)
    args = ap.parse_args(argv)
    sess = Path(args.session)
    bag, out = sess / 'bag', sess / 'bag_retimed'
    started = time.time()
    try:
        if out.exists():
            raise FileExistsError(f'출력 폴더가 이미 있음: {out}')
        part = out.with_name(out.name + '.partial')
        shutil.rmtree(part, ignore_errors=True)
        result = retime(bag, part, args.topic)
        part.rename(out)
        result.update(retimed_bag=str(out), seconds=round(time.time() - started, 1))
        if (sess / 'manifest.yaml').exists():
            from ..core.session import Session
            Session(sess).update_manifest(points_retime={
                **result, 'created_at': datetime.now().astimezone().isoformat(timespec='seconds')})
        emit(stage='finished', **result)
    except Exception as e:  # noqa: BLE001
        emit(stage='error', error=f'{e.__class__.__name__}: {e}')
        sys.exit(1)


if __name__ == '__main__':
    main()

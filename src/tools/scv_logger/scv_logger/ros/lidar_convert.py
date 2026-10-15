"""녹화된 /velodyne_packets → /velodyne_points 오프라인 변환.

실차 런치(velodyne-all-nodes-VLP32C-launch.py)와 같은 파라미터로 velodyne_transform_node를
따로 띄우고, bag의 패킷을 한 장씩 넣은 뒤 결과 포인트클라우드를 받아 원래 녹화 시각으로
새 bag에 쓴다. 한 장을 넣고 결과를 받은 다음 장을 넣으므로(lockstep) 프레임이 빠지지 않는다.
변환 노드는 임의의 ROS 도메인에서 돌려 실행 중인 스택·rviz와 섞이지 않게 한다.

    scv_logger_lidar_convert --session <세션 폴더> [--merge]
        <세션>/bag_points/   포인트클라우드만 (mcap)
        <세션>/bag_merged/   --merge: 원본 bag + 포인트클라우드 (ros2 bag play 한 번으로 재생)

진행 상황은 stdout에 JSON 한 줄씩: {"stage": ..., "done": n, "total": m}
"""
from __future__ import annotations

import argparse
import json
import os
import random
import shutil
import signal
import subprocess
import sys
import tempfile
import time
from datetime import datetime
from pathlib import Path

import rclpy
import rosbag2_py
import yaml
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy

PACKETS = '/velodyne_packets'
POINTS = '/velodyne_points'
CONVERT_IN = '/scv_convert/packets'
CONVERT_OUT = '/scv_convert/points'
RELIABLE = QoSProfile(history=HistoryPolicy.KEEP_LAST, depth=50, reliability=ReliabilityPolicy.RELIABLE,
                      durability=DurabilityPolicy.VOLATILE)


def emit(**kw) -> None:
    print(json.dumps(kw, ensure_ascii=False), flush=True)


def storage_id_of(bag: Path) -> str:
    meta = bag / 'metadata.yaml'
    if meta.exists():
        info = yaml.safe_load(meta.read_text())['rosbag2_bagfile_information']
        return info.get('storage_identifier', 'mcap')
    return 'sqlite3' if any(bag.glob('*.db3')) else 'mcap'


def header_stamp(cdr: bytes) -> tuple[int, int]:
    """CDR 직렬화 메시지의 std_msgs/Header stamp (encapsulation 4바이트 뒤 sec, nanosec)."""
    return int.from_bytes(cdr[4:8], 'little', signed=True), int.from_bytes(cdr[8:12], 'little')


def transform_params(tmp: Path) -> Path:
    """실차 런치와 같은 방식: 설치된 VLP32C 설정 + calibration 절대 경로."""
    from ament_index_python.packages import get_package_share_directory
    share = Path(get_package_share_directory('velodyne_pointcloud'))
    params = yaml.safe_load((share / 'config' / 'VLP32C-velodyne_transform_node-params.yaml').read_text())
    params = params['velodyne_transform_node']['ros__parameters']
    params['calibration'] = str(share / 'params' / 'VeloView-VLP-32C.yaml')
    out = tmp / 'transform_params.yaml'
    out.write_text(yaml.safe_dump({'/**': {'ros__parameters': params}}))
    return out


def start_transform(params: Path, domain: int, log: Path) -> subprocess.Popen:
    env = dict(os.environ, ROS_DOMAIN_ID=str(domain), ROS_LOCALHOST_ONLY='1')
    cmd = ['ros2', 'run', 'velodyne_pointcloud', 'velodyne_transform_node', '--ros-args',
           '--params-file', str(params), '-r', '__node:=scv_convert_transform',
           '-r', f'velodyne_packets:={CONVERT_IN}', '-r', f'velodyne_points:={CONVERT_OUT}']
    return subprocess.Popen(cmd, env=env, stdout=open(log, 'w'), stderr=subprocess.STDOUT,
                            start_new_session=True)


def convert(bag: Path, out: Path, domain: int, timeout: float = 5.0) -> dict:
    if out.exists():
        raise FileExistsError(f'출력 폴더가 이미 있음: {out}')
    tmp = Path(tempfile.mkdtemp(prefix='scv_lidar_convert_'))
    proc = start_transform(transform_params(tmp), domain, tmp / 'transform.log')
    os.environ['ROS_LOCALHOST_ONLY'] = '1'
    ctx = rclpy.Context()
    rclpy.init(context=ctx, domain_id=domain)
    node = Node('scv_convert_feeder', context=ctx)
    try:
        from sensor_msgs.msg import PointCloud2
        from velodyne_msgs.msg import VelodyneScan
        pub = node.create_publisher(VelodyneScan, CONVERT_IN, RELIABLE)
        clouds: list[bytes] = []
        node.create_subscription(PointCloud2, CONVERT_OUT, clouds.append, RELIABLE, raw=True)

        from rclpy.executors import SingleThreadedExecutor
        executor = SingleThreadedExecutor(context=ctx)
        executor.add_node(node)

        # 변환 노드와 연결될 때까지 대기
        deadline = time.monotonic() + 30
        while time.monotonic() < deadline:
            executor.spin_once(timeout_sec=0.1)
            if pub.get_subscription_count() > 0 and node.count_publishers(CONVERT_OUT) > 0:
                break
            if proc.poll() is not None:
                raise RuntimeError(f'velodyne_transform_node 실행 실패: {(tmp / "transform.log").read_text()[-500:]}')
        else:
            raise RuntimeError('velodyne_transform_node와 연결되지 않음 (30초)')
        time.sleep(0.5)

        sid = storage_id_of(bag)
        reader = rosbag2_py.SequentialReader()
        reader.open(rosbag2_py.StorageOptions(uri=str(bag), storage_id=sid),
                    rosbag2_py.ConverterOptions('cdr', 'cdr'))
        total = next((t.message_count for t in reader.get_metadata().topics_with_message_count
                      if t.topic_metadata.name == PACKETS), 0)
        if total == 0:
            raise ValueError(f'bag에 {PACKETS}가 없음: {bag}')
        reader.set_filter(rosbag2_py.StorageFilter(topics=[PACKETS]))

        writer = rosbag2_py.SequentialWriter()
        writer.open(rosbag2_py.StorageOptions(uri=str(out), storage_id='mcap'),
                    rosbag2_py.ConverterOptions('cdr', 'cdr'))
        writer.create_topic(rosbag2_py.TopicMetadata(name=POINTS, type='sensor_msgs/msg/PointCloud2',
                                                     serialization_format='cdr'))

        done = written = skipped = 0
        pending: dict[tuple[int, int], int] = {}      # 패킷 stamp → 녹화 시각
        last_report = 0.0
        emit(stage='convert', done=0, total=total)
        while reader.has_next():
            _topic, data, t = reader.read_next()
            pending[header_stamp(data)] = t
            pub.publish(bytes(data))
            end = time.monotonic() + timeout
            while not clouds and time.monotonic() < end:
                executor.spin_once(timeout_sec=0.01)
            if not clouds:
                skipped += 1                          # 빈 스캔 등 — 출력 없음
            while clouds:
                cloud = clouds.pop(0)
                writer.write(POINTS, cloud, pending.pop(header_stamp(cloud), t))
                written += 1
            done += 1
            if len(pending) > 100:
                pending = dict(list(pending.items())[-20:])
            now = time.monotonic()
            if now - last_report > 0.5:
                last_report = now
                emit(stage='convert', done=done, total=total)
        del writer                                    # 닫기 → metadata.yaml 작성
        emit(stage='convert', done=done, total=total)
        return {'packets': done, 'clouds': written, 'skipped': skipped}
    finally:
        node.destroy_node()
        rclpy.shutdown(context=ctx)
        if proc.poll() is None:
            os.killpg(proc.pid, signal.SIGINT)
            try:
                proc.wait(5)
            except subprocess.TimeoutExpired:
                os.killpg(proc.pid, signal.SIGKILL)


def merge(inputs: list[Path], out: Path) -> None:
    """ros2 bag convert로 여러 bag을 시각 순서대로 합친다."""
    if out.exists():
        raise FileExistsError(f'출력 폴더가 이미 있음: {out}')
    opts = Path(tempfile.mkdtemp(prefix='scv_merge_')) / 'out.yaml'
    opts.write_text(yaml.safe_dump({'output_bags': [{
        'uri': str(out), 'storage_id': 'mcap', 'all': True, 'storage_preset_profile': 'zstd_fast'}]}))
    cmd = ['ros2', 'bag', 'convert', '-o', str(opts)]
    for b in inputs:
        cmd += ['-i', str(b), storage_id_of(b)]
    emit(stage='merge', done=0, total=1)
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0:
        raise RuntimeError(f'ros2 bag convert 실패: {(r.stderr or r.stdout)[-800:]}')
    emit(stage='merge', done=1, total=1)


def main(argv: list[str] | None = None) -> None:
    ap = argparse.ArgumentParser(description='velodyne_packets → velodyne_points 오프라인 변환')
    ap.add_argument('--session', help='세션 폴더 (bag/ → bag_points/, --merge 시 bag_merged/)')
    ap.add_argument('--bag', help='입력 bag 폴더 (--session 대신)')
    ap.add_argument('--out', help='출력 bag 폴더 (--session 대신)')
    ap.add_argument('--merge', action='store_true', help='원본과 합친 재생용 bag도 만든다')
    ap.add_argument('--domain', type=int, default=None, help='변환용 ROS 도메인 (기본: 150~229 임의)')
    args = ap.parse_args(argv)

    if args.session:
        sess = Path(args.session)
        bag, out = sess / 'bag', sess / 'bag_points'
    elif args.bag and args.out:
        sess, bag, out = None, Path(args.bag), Path(args.out)
    else:
        ap.error('--session 또는 --bag/--out 필요')
    domain = args.domain if args.domain is not None else random.randint(150, 229)
    started = time.time()
    try:
        # 진행 중에는 *.partial 에 쓰고 성공했을 때만 이름을 바꾼다 — 취소·실패 시 완료로 보이지 않게
        if out.exists():
            raise FileExistsError(f'출력 폴더가 이미 있음: {out}')
        part = out.with_name(out.name + '.partial')
        shutil.rmtree(part, ignore_errors=True)
        result = convert(bag, part, domain)
        part.rename(out)
        merged = None
        if args.merge:
            merged = (sess / 'bag_merged') if sess else out.with_name(out.name + '_merged')
            if merged.exists():
                raise FileExistsError(f'출력 폴더가 이미 있음: {merged}')
            mpart = merged.with_name(merged.name + '.partial')
            shutil.rmtree(mpart, ignore_errors=True)
            merge([bag, out], mpart)
            mpart.rename(merged)
        result.update(points_bag=str(out), merged_bag=str(merged) if merged else None,
                      seconds=round(time.time() - started, 1))
        if sess is not None and (sess / 'manifest.yaml').exists():
            from ..core.session import Session
            Session(sess).update_manifest(lidar_conversion={
                **result, 'converted_at': datetime.now().astimezone().isoformat(timespec='seconds')})
        emit(stage='finished', **result)
    except Exception as e:  # noqa: BLE001 — GUI가 그대로 보여준다
        emit(stage='error', error=f'{e.__class__.__name__}: {e}')
        sys.exit(1)


if __name__ == '__main__':
    main()

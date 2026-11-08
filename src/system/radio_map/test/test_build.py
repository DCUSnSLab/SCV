import math

from radio_map.build import build
from rclpy.serialization import serialize_message
import rosbag2_py
from system_monitor_msgs.msg import LinkQuality


def write_bag(path, samples):
    writer = rosbag2_py.SequentialWriter()
    writer.open(
        rosbag2_py.StorageOptions(uri=str(path), storage_id='mcap'),
        rosbag2_py.ConverterOptions('cdr', 'cdr'),
    )
    writer.create_topic(
        rosbag2_py.TopicMetadata(
            id=0,
            name='/link',
            type='system_monitor_msgs/msg/LinkQuality',
            serialization_format='cdr',
        )
    )
    for t, (lat, lon, probes, rtt) in enumerate(samples):
        msg = LinkQuality(latitude=lat, longitude=lon, probes_sent=probes, rtt_p95_ms=rtt)
        writer.write('/link', serialize_message(msg), t * 1_000_000_000)
    del writer


def test_samples_without_fix_or_probes_are_skipped(tmp_path):
    write_bag(
        tmp_path / 'bag',
        [
            (37.0, 127.0, 100, 40.0),
            (math.nan, math.nan, 100, 40.0),
            (37.0, 127.0, 0, math.nan),
            (37.0, 127.0, 100, 80.0),
        ],
    )
    rmap = build([str(tmp_path / 'bag')], '/link', 5.0)
    assert len(rmap.cells) == 1
    assert rmap.stats(next(iter(rmap.cells)))['samples'] == 2

#!/usr/bin/env python3
"""Reads LinkQuality messages from bags and writes link quality per grid cell as GeoJSON."""

import argparse
import json
import math

from radio_map.grid import METRICS
from radio_map.grid import RadioMap
from rclpy.serialization import deserialize_message
import rosbag2_py
from system_monitor_msgs.msg import LinkQuality


def read_links(bag, topic):
    reader = rosbag2_py.SequentialReader()
    reader.open(
        rosbag2_py.StorageOptions(uri=bag, storage_id=''),
        rosbag2_py.ConverterOptions('cdr', 'cdr'),
    )
    reader.set_filter(rosbag2_py.StorageFilter(topics=[topic]))
    while reader.has_next():
        _, data, _ = reader.read_next()
        yield deserialize_message(data, LinkQuality)


def build(bags, topic, cell_m):
    rmap = RadioMap(cell_m)
    for bag in bags:
        for msg in read_links(bag, topic):
            # A sample without a fix or without probes says nothing about a place.
            if math.isnan(msg.latitude) or not msg.probes_sent:
                continue
            rmap.add(msg.latitude, msg.longitude, {m: getattr(msg, m) for m in METRICS})
    return rmap


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('bags', nargs='+')
    p.add_argument('-o', '--output', required=True, help='GeoJSON file to write')
    p.add_argument('--topic', default='/link')
    p.add_argument('--cell-m', type=float, default=5.0)
    args = p.parse_args()
    rmap = build(args.bags, args.topic, args.cell_m)
    with open(args.output, 'w') as f:
        json.dump(rmap.to_geojson(), f)
    samples = sum(len(rows) for rows in rmap.cells.values())
    print(f'{samples} samples in {len(rmap.cells)} cells written to {args.output}')


if __name__ == '__main__':
    main()

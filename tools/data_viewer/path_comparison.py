#!/usr/bin/env python3

import json
import matplotlib.pyplot as plt
import rosbag2_py
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import NavSatFix

json_path = "/home/ssc/SCV/src/command_center/GraphMap_Server/maps/DCU_playground_v2.json"

bag_path = "/home/ssc/ros2bag/0917_dir/rosbag2_2025_09_17-01_54_57"
topic_name = "/ublox_gps_node/fix"

def main():
    with open(json_path, "r", encoding="utf-8") as f:
        json_data = json.load(f)

    nodes = sorted(json_data["Node"], key=lambda n: n["ID"])
    lats = [n["GpsInfo"]["Lat"] for n in nodes]
    lons = [n["GpsInfo"]["Long"] for n in nodes]
    labels = [n["ID"] for n in nodes]

    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id="sqlite3")
    converter_options = rosbag2_py.ConverterOptions("", "")

    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)
    reader.set_filter(rosbag2_py.StorageFilter(topics=[topic_name]))
    bag_lats = []
    bag_lons = []

    while reader.has_next():
        (topic, data, t) = reader.read_next()
        if topic == topic_name:
            msg = deserialize_message(data, NavSatFix)
            bag_lats.append(msg.latitude)
            bag_lons.append(msg.longitude)

    plt.figure()

    plt.plot(lons, lats, marker='o', markersize=4, linewidth=2, label="JSON Nodes (Path)")
    
    for lon, lat, label in zip(lons, lats, labels):
        plt.annotate(label, (lon, lat), textcoords="offset points", xytext=(5, 5))

    plt.scatter(bag_lons, bag_lats, c='r', marker='*', s=20, label="Bag GPS Fix")

    plt.title("JSON Map Nodes + Bag GPS Fix")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.gca().set_aspect('equal', adjustable='box')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
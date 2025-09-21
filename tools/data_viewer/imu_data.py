#!/usr/bin/env python3

import matplotlib.pyplot as plt
import rosbag2_py
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import Imu
from collections import defaultdict

bag_path = "/home/ssc/ros2bag/0917_dir/rosbag2_2025_09_17-01_54_57"
topic_names = ["/zed/zed_node/imu/data", "/iahrs_imu/data"]

def main():
    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id="sqlite3")
    converter_options = rosbag2_py.ConverterOptions("", "")

    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)
    reader.set_filter(rosbag2_py.StorageFilter(topics=topic_names))

    imu_data = defaultdict(lambda: {"t": [], "gyro_x": [], "gyro_y": [], "gyro_z": []})

    while reader.has_next():
        (topic, data, t) = reader.read_next()
        if topic in topic_names:
            msg = deserialize_message(data, Imu)
            imu_data[topic]["t"].append(t * 1e-9)  # ROS2 timestamp → 초 단위
            imu_data[topic]["gyro_x"].append(msg.angular_velocity.x)
            imu_data[topic]["gyro_y"].append(msg.angular_velocity.y)
            imu_data[topic]["gyro_z"].append(msg.angular_velocity.z)

    # === 그래프 그리기 ===
    axes = ["gyro_x", "gyro_y", "gyro_z"]
    labels = ["Angular Velocity X", "Angular Velocity Y", "Angular Velocity Z"]

    for axis, label in zip(axes, labels):
        plt.figure()
        for topic in topic_names:
            plt.plot(imu_data[topic]["t"], imu_data[topic][axis], label=f"{topic} {label}")
        plt.title(f"{label} Comparison")
        plt.xlabel("Time [s]")
        plt.ylabel("Angular Velocity [rad/s]")
        plt.legend()
        plt.grid(True)

    plt.show()

if __name__ == "__main__":
    main()

#!/usr/bin/env python3

import matplotlib.pyplot as plt
import rosbag2_py
from rclpy.serialization import deserialize_message
from nav_msgs.msg import Odometry
import math

bag_path = "/home/ssc/ros2bag/0917_dir/rosbag2_2025_09_17-01_37_08"
topic_name = "/odom"   # 실제 사용하는 토픽으로 수정하세요

def quaternion_to_yaw(x, y, z, w):
    """쿼터니언 -> yaw(rad)"""
    siny_cosp = 2.0 * (w * z + x * y)
    cosy_cosp = 1.0 - 2.0 * (y * y + z * z)
    return math.atan2(siny_cosp, cosy_cosp)

def main():
    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id="sqlite3")
    converter_options = rosbag2_py.ConverterOptions("", "")

    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)
    reader.set_filter(rosbag2_py.StorageFilter(topics=[topic_name]))

    xs, ys, yaws = [], [], []

    while reader.has_next():
        (topic, data, t) = reader.read_next()
        if topic == topic_name:
            msg = deserialize_message(data, Odometry)
            xs.append(msg.pose.pose.position.x)
            ys.append(msg.pose.pose.position.y)

            q = msg.pose.pose.orientation
            yaws.append(quaternion_to_yaw(q.x, q.y, q.z, q.w))

    # === 궤적 및 orientation 시각화 ===
    plt.figure()
    plt.plot(xs, ys, "b-", label="Trajectory")

    # 일정 간격으로 화살표 표시
    step = max(1, len(xs) // 50)  # 최대 50개 화살표만 표시
    for i in range(0, len(xs), step):
        dx = math.cos(yaws[i]) * 0.5  # 화살표 길이 0.5m
        dy = math.sin(yaws[i]) * 0.5
        plt.arrow(xs[i], ys[i], dx, dy,
                  head_width=0.2, head_length=0.2, fc="r", ec="r")

    plt.title("Odometry Trajectory with Orientation")
    plt.xlabel("X [m]")
    plt.ylabel("Y [m]")
    plt.axis("equal")
    plt.grid(True)
    plt.legend()
    plt.show()

if __name__ == "__main__":
    main()

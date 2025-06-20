#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from nav_msgs.msg import Odometry
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import tf.transformations as tft
import math
import numpy as np

# 전역 변수: 각 토픽의 데이터를 저장합니다.
# /zed_node/odom 데이터
zed_timestamps = []    # 상대 시간 (초)
zed_positions = []     # [(x, y), ...]
zed_headings = []      # heading (°)

# /scv_odom 데이터
scv_timestamps = []
scv_positions = []
scv_headings = []

start_time = None  # 첫 데이터 수신 기준 시간

def quaternion_to_heading(q):
    """쿼터니언을 받아 0~360° 범위의 heading 값으로 변환"""
    euler = tft.euler_from_quaternion([q.x, q.y, q.z, q.w])
    yaw = euler[2]  # 라디안 단위
    heading_deg = math.degrees(yaw) % 360
    return heading_deg

def normalize_time(timestamp):
    """첫 데이터 기준으로 상대 시간(초) 반환"""
    global start_time
    if start_time is None:
        start_time = timestamp
    return timestamp - start_time

def zed_callback(msg):
    """/zed_node/odom 토픽 콜백 함수"""
    global zed_timestamps, zed_positions, zed_headings
    timestamp = normalize_time(msg.header.stamp.to_sec())
    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y
    heading = quaternion_to_heading(msg.pose.pose.orientation)
    zed_timestamps.append(timestamp)
    zed_positions.append((x, y))
    zed_headings.append(heading)

def scv_callback(msg):
    """/scv_odom 토픽 콜백 함수"""
    global scv_timestamps, scv_positions, scv_headings
    timestamp = normalize_time(msg.header.stamp.to_sec())
    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y
    heading = quaternion_to_heading(msg.pose.pose.orientation)
    scv_timestamps.append(timestamp)
    scv_positions.append((x, y))
    scv_headings.append(heading)

def interpolate_data(target_times, source_times, source_values):
    """
    target_times 기준으로 source_times의 데이터를 보간하여 반환합니다.
    데이터가 없으면 NaN 배열을 반환합니다.
    """
    if not source_times or not source_values:
        return np.full_like(target_times, np.nan)
    return np.interp(target_times, source_times, source_values)

def animate_positions(i):
    """실시간 position 데이터를 시각화 (figure 1)"""
    plt.figure(1)
    plt.clf()

    # /zed_node/odom 위치 (빨간색)
    if zed_positions:
        xs, ys = zip(*zed_positions)
        plt.scatter(xs, ys, c='r', label='/zed_node/odom')
    
    # /scv_odom 위치 (파란색)
    if scv_positions:
        xs, ys = zip(*scv_positions)
        plt.scatter(xs, ys, c='b', label='/scv_odom')
    
    plt.legend()
    plt.xlabel("X Position")
    plt.ylabel("Y Position")
    plt.title("실시간 Position 시각화")
    plt.grid(True)
    plt.tight_layout()

def animate_heading(i):
    """실시간으로 동기화된 heading 데이터를 시각화 (figure 2)"""
    plt.figure(2)
    plt.clf()

    if zed_timestamps and scv_timestamps:
        # 두 토픽의 최소/최대 상대 시간 구하기
        min_time = min(min(zed_timestamps), min(scv_timestamps))
        max_time = max(max(zed_timestamps), max(scv_timestamps))
        common_times = np.arange(min_time, max_time, 0.1)

        # 보간하여 동기화된 heading 데이터 생성
        zed_interp = interpolate_data(common_times, zed_timestamps, zed_headings)
        scv_interp = interpolate_data(common_times, scv_timestamps, scv_headings)

        plt.plot(common_times, zed_interp, 'r-', label='/zed_node/odom heading')
        plt.plot(common_times, scv_interp, 'b-', label='/scv_odom heading')

    plt.legend()
    plt.xlabel("시간 (초)")
    plt.ylabel("Heading (°)")
    plt.title("실시간 Heading 시각화 (동기화된 시간 기준)")
    plt.ylim(0, 360)
    plt.grid(True)
    plt.tight_layout()

def animate_heading_error(i):
    """두 odom간의 heading 오차를 시간 기준으로 시각화 (figure 3)"""
    plt.figure(3)
    plt.clf()

    if zed_timestamps and scv_timestamps:
        min_time = min(min(zed_timestamps), min(scv_timestamps))
        max_time = max(max(zed_timestamps), max(scv_timestamps))
        common_times = np.arange(min_time, max_time, 0.1)

        # 보간하여 동기화된 heading 데이터 생성
        zed_interp = interpolate_data(common_times, zed_timestamps, zed_headings)
        scv_interp = interpolate_data(common_times, scv_timestamps, scv_headings)

        # 원형 데이터의 특성을 고려하여 heading 오차 계산
        heading_error = (zed_interp - scv_interp + 180) % 360 - 180

        plt.plot(common_times, heading_error, 'g-', label="Heading Error (/zed - /scv)")

    plt.legend()
    plt.xlabel("시간 (초)")
    plt.ylabel("Heading Error (°)")
    plt.title("실시간 Heading Error 시각화")
    plt.grid(True)
    plt.tight_layout()

def main():
    rospy.init_node('real_time_visualization', anonymous=True)
    rospy.Subscriber("/zed_node/odom", Odometry, zed_callback)
    rospy.Subscriber("/scv_odom", Odometry, scv_callback)

    # Figure 1: Position 시각화
    fig1 = plt.figure(1)
    ani1 = animation.FuncAnimation(fig1, animate_positions, interval=100)

    # Figure 2: Heading 시각화
    fig2 = plt.figure(2)
    ani2 = animation.FuncAnimation(fig2, animate_heading, interval=100)

    # Figure 3: Heading 오차 시각화
    fig3 = plt.figure(3)
    ani3 = animation.FuncAnimation(fig3, animate_heading_error, interval=100)

    plt.show()
    rospy.spin()

if __name__ == '__main__':
    main()

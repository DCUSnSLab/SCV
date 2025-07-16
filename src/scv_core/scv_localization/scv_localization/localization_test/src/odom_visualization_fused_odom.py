#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from nav_msgs.msg import Odometry
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import tf.transformations as tft
import math
import numpy as np

# 전역 변수: /odom/ekf 데이터 저장
ekf_timestamps = []   # 상대 시간 (초)
ekf_positions = []    # [(x, y), ...]
ekf_headings = []     # heading (°)

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

def ekf_callback(msg):
    """/odom/ekf 토픽 콜백 함수"""
    global ekf_timestamps, ekf_positions, ekf_headings
    timestamp = normalize_time(msg.header.stamp.to_sec())
    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y
    heading = quaternion_to_heading(msg.pose.pose.orientation)
    ekf_timestamps.append(timestamp)
    ekf_positions.append((x, y))
    ekf_headings.append(heading)

def animate_positions(i):
    """실시간 포지션 데이터를 시각화 (Figure 1)"""
    plt.figure(1)
    plt.clf()

    if ekf_positions:
        xs, ys = zip(*ekf_positions)
        plt.scatter(xs, ys, c='r', label="/odom/ekf position")
    plt.legend()
    plt.xlabel("X Position")
    plt.ylabel("Y Position")
    plt.title("실시간 Position 시각화 (/odom/ekf)")
    plt.grid(True)
    plt.tight_layout()

def animate_heading(i):
    """실시간 heading 데이터를 시각화 (Figure 2)"""
    plt.figure(2)
    plt.clf()

    if ekf_timestamps and ekf_headings:
        # 직접 ekf_timestamps와 ekf_headings를 사용하여 시간에 따른 선 그래프 작성
        plt.plot(ekf_timestamps, ekf_headings, 'b-', label="/odom/ekf heading")
    plt.legend()
    plt.xlabel("시간 (초)")
    plt.ylabel("Heading (°)")
    plt.title("실시간 Heading 시각화 (/odom/ekf)")
    plt.ylim(0, 360)  # y축을 0~360도로 고정
    plt.grid(True)
    plt.tight_layout()

def main():
    rospy.init_node('real_time_ekf_visualization', anonymous=True)
    rospy.Subscriber("/odom/coordinate/imu", Odometry, ekf_callback)

    # Figure 1: Position 시각화
    fig1 = plt.figure(1)
    ani1 = animation.FuncAnimation(fig1, animate_positions, interval=100)

    # Figure 2: Heading 시각화
    fig2 = plt.figure(2)
    ani2 = animation.FuncAnimation(fig2, animate_heading, interval=100)

    plt.show()
    rospy.spin()

if __name__ == '__main__':
    main()

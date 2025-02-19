#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from nav_msgs.msg import Odometry

# 전역 리스트(또는 deque)로 위치 데이터를 저장
gps_x, gps_y = [], []
zed_x, zed_y = [], []
scv_x, scv_y = [], []

def gps_callback(msg):
    gps_x.append(msg.pose.pose.position.x)
    gps_y.append(msg.pose.pose.position.y)

def zed_callback(msg):
    zed_x.append(msg.pose.pose.position.x)
    zed_y.append(msg.pose.pose.position.y)

def scv_callback(msg):
    scv_x.append(msg.pose.pose.position.x)
    scv_y.append(msg.pose.pose.position.y)

def animate(frame):
    # clear 이전 플롯
    plt.cla()
    
    # gps 오돔
    plt.plot(gps_x, gps_y, 'r-', label='GPS Odom')
    
    # zed 오돔
    plt.plot(zed_x, zed_y, 'g-', label='ZED Odom')
    
    # scv 오돔
    plt.plot(scv_x, scv_y, 'b-', label='SCV Odom')
    
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Real-time Odom Comparison')
    plt.legend()
    plt.grid(True)

def main():
    rospy.init_node('odom_plotter', anonymous=True)

    # 토픽 구독
    rospy.Subscriber('/odom/coordinate/gps', Odometry, gps_callback)
    rospy.Subscriber('/zed_node/odom', Odometry, zed_callback)
    rospy.Subscriber('/scv_odom', Odometry, scv_callback)

    # matplotlib figure 준비
    fig = plt.figure()

    # FuncAnimation을 이용해 일정 간격마다 animate 함수를 호출
    ani = animation.FuncAnimation(fig, animate, interval=200)

    plt.show(block=True)

    # ROS 스피너 동작
    rospy.spin()

if __name__ == '__main__':
    main()

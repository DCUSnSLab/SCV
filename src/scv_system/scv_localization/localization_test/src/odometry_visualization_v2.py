#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import math
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from nav_msgs.msg import Odometry
from tf.transformations import euler_from_quaternion

# --------------------
# 위치와 yaw(라디안)를 저장할 리스트
gps_x, gps_y, gps_yaw = [], [], []
zed_x, zed_y, zed_yaw = [], [], []
scv_x, scv_y, scv_yaw = [], [], []

def gps_callback(msg):
    gps_x.append(msg.pose.pose.position.x)
    gps_y.append(msg.pose.pose.position.y)
    q = msg.pose.pose.orientation
    _, _, yaw = euler_from_quaternion([q.x, q.y, q.z, q.w])
    gps_yaw.append(yaw)

def zed_callback(msg):
    zed_x.append(msg.pose.pose.position.x)
    zed_y.append(msg.pose.pose.position.y)
    q = msg.pose.pose.orientation
    _, _, yaw = euler_from_quaternion([q.x, q.y, q.z, q.w])
    zed_yaw.append(yaw)

def scv_callback(msg):
    scv_x.append(msg.pose.pose.position.x)
    scv_y.append(msg.pose.pose.position.y)
    q = msg.pose.pose.orientation
    _, _, yaw = euler_from_quaternion([q.x, q.y, q.z, q.w])
    scv_yaw.append(yaw)


# ------------------------------------------------------------
# (1) 첫 번째 애니메이션: 위치 궤적을 그리는 함수
def animate_map(frame):
    """
    FuncAnimation에 의해 주기적으로 호출되어
    GPS/ZED/SCV의 x,y 궤적을 갱신해서 그려줍니다.
    """
    ax_map.cla()  # 이전 그림 지우기

    # GPS
    if len(gps_x) > 0:
        ax_map.plot(gps_x, gps_y, 'r-', label='GPS Odom')

    # ZED
    if len(zed_x) > 0:
        ax_map.plot(zed_x, zed_y, 'g-', label='ZED Odom')

    # SCV
    if len(scv_x) > 0:
        ax_map.plot(scv_x, scv_y, 'b-', label='SCV Odom')

    ax_map.set_xlabel('X')
    ax_map.set_ylabel('Y')
    ax_map.set_title('Real-time Odom Comparison')
    ax_map.grid(True)
    ax_map.legend()

# ------------------------------------------------------------
# (2) 두 번째 애니메이션: 각 오도메트리의 yaw(도 단위)를 시계열로 그리는 함수
def animate_orientation(frame):
    """
    FuncAnimation에 의해 주기적으로 호출되어
    GPS/ZED/SCV의 yaw(도 단위) 변화를 갱신해서 그려줍니다.
    x축: 데이터 개수(= 샘플 인덱스)
    y축: yaw(deg)
    """
    ax_yaw.cla()  # 이전 그림 지우기

    # yaw를 도(deg) 단위로 변환
    gps_yaw_deg = [math.degrees(y) for y in gps_yaw]
    zed_yaw_deg = [math.degrees(y) for y in zed_yaw]
    scv_yaw_deg = [math.degrees(y) for y in scv_yaw]

    # x축(샘플 인덱스)
    gps_idx = range(len(gps_yaw_deg))
    zed_idx = range(len(zed_yaw_deg))
    scv_idx = range(len(scv_yaw_deg))

    if len(gps_yaw_deg) > 0:
        ax_yaw.plot(gps_idx, gps_yaw_deg, 'r-', label='GPS Yaw (deg)')
    if len(zed_yaw_deg) > 0:
        ax_yaw.plot(zed_idx, zed_yaw_deg, 'g-', label='ZED Yaw (deg)')
    if len(scv_yaw_deg) > 0:
        ax_yaw.plot(scv_idx, scv_yaw_deg, 'b-', label='SCV Yaw (deg)')

    ax_yaw.set_xlabel('Sample Index')
    ax_yaw.set_ylabel('Yaw (degrees)')
    ax_yaw.set_title('Orientation Comparison')
    ax_yaw.grid(True)
    ax_yaw.legend()


def main():
    rospy.init_node('odom_plotter', anonymous=True)

    # --------------------
    # 토픽 구독
    rospy.Subscriber('/odom/coordinate/gps', Odometry, gps_callback)
    rospy.Subscriber('/zed_node/odom', Odometry, zed_callback)
    rospy.Subscriber('/scv_odom', Odometry, scv_callback)

    # --------------------
    # Matplotlib Figure 2개 생성
    global fig_map, ax_map
    global fig_yaw, ax_yaw

    fig_map, ax_map = plt.subplots()
    fig_yaw, ax_yaw = plt.subplots()

    # --------------------
    # FuncAnimation - 첫 번째(fig_map)와 두 번째(fig_yaw)에 대한 애니메이션을 각각 생성
    ani_map = animation.FuncAnimation(fig_map, animate_map, interval=200)
    ani_yaw = animation.FuncAnimation(fig_yaw, animate_orientation, interval=200)

    # plt.show()를 호출하면 figure가 모두 열림
    # block=True로 하면 이 스크립트가 여기서 멈추지만,
    # 아래에서 rospy.spin()도 동작해야 하므로 일반적으로는 False로 쓰고,
    # ROS 메인 루프를 돌리면서 Matplotlib 이벤트도 돌아가게 합니다.
    plt.show(block=False)

    rospy.spin()

if __name__ == '__main__':
    main()

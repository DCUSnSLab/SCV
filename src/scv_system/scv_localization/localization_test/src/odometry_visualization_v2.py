#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
from nav_msgs.msg import Odometry
import matplotlib.pyplot as plt
import math
import threading

from tf.transformations import euler_from_quaternion

class OdomVisualizer:
    def __init__(self):
        rospy.init_node('odom_visualizer', anonymous=True)

        # 실시간 플롯을 위해 interactive mode 켜기
        plt.ion()
        self.fig, self.ax = plt.subplots()
        self.ax.set_title("Real-time Odom Visualization")
        self.ax.set_xlabel("X (m)")
        self.ax.set_ylabel("Y (m)")
        # 좌표계를 동일 비율로 보기 위해 설정
        self.ax.set_aspect('equal', adjustable='box')

        # -------------------- 구독할 토픽 4개 정의 --------------------
        # 실제로 쓰시려는 토픽 이름에 맞게 변경하세요.
        self.topics = {
            '/odom/coordinate/imu': {
                'x': [], 'y': [], 'theta': [], 'color': 'r', 'label': 'IMU'
            },
            '/odom/coordinate/gps': {
                'x': [], 'y': [], 'theta': [], 'color': 'g', 'label': 'GPS'
            },
            '/odom/dwa': {
                'x': [], 'y': [], 'theta': [], 'color': 'b', 'label': 'DWA'
            },
            '/odom/fused': {
                'x': [], 'y': [], 'theta': [], 'color': 'm', 'label': 'FUSED'
            }
        }

        # -------------------- ROS Subscriber 설정 --------------------
        for t in self.topics.keys():
            rospy.Subscriber(t, Odometry, self.odom_callback, callback_args=t)

        # -------------------- Matplotlib 초기 Plot 설정 --------------------
        # 각 토픽별로 저장된 위치 데이터를 시각화하기 위한 라인(혹은 점) 객체
        # (여기서는 사실 points-only로 쓰지만, 형태를 맞춰두었음)
        self.lines = {}
        for t, data in self.topics.items():
            line, = self.ax.plot([], [], color=data['color'], marker='o', linestyle='', label=data['label'])
            self.lines[t] = line

        self.ax.legend()

        # -------------------- Plot 업데이트 스레드 시작 --------------------
        # 메인쓰레드는 rospy.spin() 등으로 콜백을 돌릴 것이고,  
        # 별도 스레드에서 Matplotlib Plot을 주기적으로 업데이트.
        self.update_thread = threading.Thread(target=self.update_loop)
        self.update_thread.daemon = True
        self.update_thread.start()

    def odom_callback(self, msg, topic):
        """ Odometry 메시지가 수신될 때마다, position/orientation을 저장 """
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y

        # orientation에서 (roll, pitch, yaw) 추출
        orientation_q = msg.pose.pose.orientation
        orientation_list = [orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
        (roll, pitch, yaw) = euler_from_quaternion(orientation_list)

        self.topics[topic]['x'].append(x)
        self.topics[topic]['y'].append(y)
        self.topics[topic]['theta'].append(yaw)

    def update_loop(self):
        """ 별도 스레드에서 주기적으로 Plot 업데이트 수행 """
        rate = rospy.Rate(5)  # 5Hz (초당 5회) 업데이트
        while not rospy.is_shutdown():
            self.update_plot()
            plt.pause(0.01)  # Matplotlib 이벤트 루프를 잠시 돌림
            rate.sleep()

    def update_plot(self):
        """ 실제로 Plot의 데이터를 갱신하고, 화살표도 표시 """
        # 축 초기화 (배경 지우기)
        self.ax.clear()
        self.ax.set_title("Real-time Odom Visualization")
        self.ax.set_xlabel("X (m)")
        self.ax.set_ylabel("Y (m)")
        self.ax.set_aspect('equal', adjustable='box')

        # 각 토픽별로 데이터 갱신
        for t, dataset in self.topics.items():
            x_list = dataset['x']
            y_list = dataset['y']
            theta_list = dataset['theta']
            color = dataset['color']
            label = dataset['label']

            # 위치 데이터
            if len(x_list) > 0:
                # 점(point) 모양으로 전체 궤적(plot)
                self.ax.plot(x_list, y_list, color=color, marker='o', linestyle='', label=label)

                # 마지막 점에 대해서는 방향(orientation) 화살표 표시
                arrow_length = 0.3  # 화살표 길이
                last_x = x_list[-1]
                last_y = y_list[-1]
                last_yaw = theta_list[-1]
                
                # (cos(yaw), sin(yaw)) 벡터 방향으로 화살표 그리기
                self.ax.arrow(
                    last_x, last_y,
                    arrow_length*math.cos(last_yaw),
                    arrow_length*math.sin(last_yaw),
                    head_width=0.08, 
                    head_length=0.1,
                    fc=color, ec=color
                )

        self.ax.legend()
        self.ax.relim()
        self.ax.autoscale_view()

def main():
    visualizer = OdomVisualizer()
    # ROS 콜백 무한루프
    rospy.spin()

if __name__ == '__main__':
    main()

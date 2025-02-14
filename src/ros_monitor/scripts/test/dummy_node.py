#!/usr/bin/env python3

import rospy
from std_msgs.msg import String
import json
import random


class DummyNodePublisher:
    def __init__(self):
        rospy.init_node("dummy_node_publisher", anonymous=True)

        # 퍼블리시할 더미 노드 이름 리스트
        self.node_names = [
            "/node_resource_monitor/node1",
            "/node_resource_monitor/node2",
            "/node_resource_monitor/node3",
        ]

        # 퍼블리셔를 저장할 딕셔너리
        self.publishers = {}

        # 각 노드에 대한 퍼블리셔 생성
        for node_name in self.node_names:
            self.publishers[node_name] = rospy.Publisher(node_name, String, queue_size=10)

        # 1초마다 데이터를 퍼블리시
        self.publish_timer = rospy.Timer(rospy.Duration(1), self.publish_dummy_data)

    def publish_dummy_data(self, event):
        """각 노드에 랜덤 데이터를 퍼블리시"""
        for node_name, publisher in self.publishers.items():
            # 랜덤 데이터 생성
            cpu_usage = random.uniform(10, 90)  # 10% ~ 90%
            ram_usage = random.randint(100, 5000)  # 100MB ~ 5000MB

            # JSON 형식 데이터
            resource_data = {
                "node": node_name,
                "cpu": cpu_usage,
                "mem": ram_usage,
            }

            # JSON 데이터를 퍼블리시
            resource_msg = String()
            resource_msg.data = json.dumps(resource_data)
            publisher.publish(resource_msg)

            # 로그 출력
            rospy.loginfo(f"Published to {node_name}: {resource_data}")


if __name__ == "__main__":
    try:
        dummy_node = DummyNodePublisher()
        rospy.spin()
    except rospy.ROSInterruptException:
        rospy.loginfo("Dummy node terminated.")

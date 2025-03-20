#!/usr/bin/python3
# -*- coding: utf-8 -*-
import os
import rospy
import rosgraph.masterapi
from std_msgs.msg import String
import json
import threading
import time
from collections import deque

class TopicMonitor:
    def __init__(self, topic):
        self.topic = topic
        self.timestamps = deque(maxlen=500)
        self.byte_sizes = deque(maxlen=500)
        self.subscriber = rospy.Subscriber(topic, rospy.AnyMsg, self.callback)

    def callback(self, msg):
        now = time.time()
        msg_size = len(msg._buff) if hasattr(msg, '_buff') else len(str(msg))
        self.timestamps.append(now)
        self.byte_sizes.append(msg_size)

    def get_hz_and_bw(self):
        now = time.time()
        
        # 1초가 지난 데이터는 삭제
        while self.timestamps and now - self.timestamps[0] > 1:
            self.timestamps.popleft()
            self.byte_sizes.popleft()
        
        n_1s = len(self.timestamps)  # 최근 1초간 메시지 수
        bw = sum(self.byte_sizes)  # 총 데이터 전송량 (bytes)
        
        return n_1s, bw

class ROSTopicExcludeMonitor:
    def __init__(self):
        self.yaml_path = '/home/pgw/catkin_ws/src/ros_monitor/cfg/exclude_topics.yaml'
        self.excluded_patterns = self.load_yaml()
        
        rospy.init_node("topics_hzbw", anonymous=True)

        try:
            self.master = rosgraph.Master('/rostopic')
        except Exception as e:
            rospy.logerr(f"[monitor] Failed to retrieve published topics: {e}")    
                
        self.topic_monitors = {}  # 현재 구독 중인 토픽 목록

        self.publisher = rospy.Publisher("/topics_hzbw", String, queue_size=100)

        self.lock = threading.Lock()
        self.monitor_thread = threading.Thread(target=self.run_monitoring)
        self.monitor_thread.start()
    
    def load_yaml(self):
        """YAML에서 제외할 토픽 패턴을 불러오기"""
        if not os.path.exists(self.yaml_path):
            rospy.logwarn(f"[monitor] YAML file not found: {self.yaml_path}. All topics will be monitored.")
            return set()

        try:
            with open(self.yaml_path, 'r') as f:
                patterns = {line.strip().rstrip('*') for line in f if line.strip()}
                rospy.loginfo(f"[monitor] Exclusion patterns: {patterns}")
                return patterns
        except Exception as e:
            rospy.logerr(f"[monitor] Error loading YAML file: {e}")
            return set()

    def should_exclude(self, topic):
        """토픽이 제외 패턴과 일치하는지 확인"""
        for pattern in self.excluded_patterns:
            if topic.startswith(pattern):  # 특정 패턴으로 시작하면 제외
                return True
        return False

    def update_subscriptions(self):
        """ROS Master에서 현재 실행 중인 토픽 목록 가져와서 제외할 토픽 필터링"""
        active_topics = {t[0] for t in self.master.getSystemState()[0]}  # 현재 실행 중인 모든 토픽
        
        # 제외할 패턴을 적용하여 남아있는 토픽만 유지
        filtered_topics = {topic for topic in active_topics if not self.should_exclude(topic)}

        new_topics = filtered_topics - set(self.topic_monitors.keys())  # 새로 추가된 토픽
        removed_topics = set(self.topic_monitors.keys()) - filtered_topics  # 제거된 토픽

        # 새로운 토픽 추가
        for topic in new_topics:
            monitor = TopicMonitor(topic)
            self.topic_monitors[topic] = monitor

        # 제거된 토픽 정리
        for topic in removed_topics:
            del self.topic_monitors[topic]

    def calculate_metrics(self):
        """현재 구독 중인 토픽들의 Hz 및 Bandwidth 계산"""
        topic_metrics_list = []
        for topic, monitor in self.topic_monitors.items():
            hz, bw = monitor.get_hz_and_bw()

            topic_metrics = {
                "topic": topic,
                "hz": hz,
                "bw": bw,
            }
            rospy.loginfo(topic_metrics)
            topic_metrics_list.append(topic_metrics)

        if topic_metrics_list:
            self.publisher.publish(json.dumps(topic_metrics_list))        
            
    def run_monitoring(self):
        """주기적으로 구독 상태를 업데이트하고 Hz, BW 발행"""
        rate = rospy.Rate(1)  # 1Hz (1초마다 실행)
        while not rospy.is_shutdown():
            self.update_subscriptions()
            self.calculate_metrics()
            rate.sleep()


if __name__ == "__main__":
    monitor = ROSTopicExcludeMonitor()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        rospy.loginfo("[monitor] Shutting down topic monitoring.")

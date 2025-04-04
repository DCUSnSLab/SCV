#!/usr/bin/python3
# -*- coding: utf-8 -*-
import os
import rospy
import rosgraph.masterapi
from std_msgs.msg import String

import csv
import json

import threading

import time
from collections import deque

class TopicMonitor(threading.Thread):
    def __init__(self, topic):
        super().__init__()
        self.topic = topic
        self.timestamps = deque(maxlen=500)
        self.byte_sizes = deque(maxlen=500)

        self.subscriber = rospy.Subscriber(topic, rospy.AnyMsg, self.callback)

        self.running = True
        
    def callback(self, msg):
        now = time.time()
        msg_size = len(msg._buff) if hasattr(msg, '_buff') else len(str(msg))
        self.timestamps.append(now)
        self.byte_sizes.append(msg_size)

    def get_hz_and_bw(self):
        now = time.time()
        
        #valid_timestamps = [t for t in self.timestamps if now - t <= 1]
        # while self.timestamps and now - self.timestamps[0] > 1:
        #     self.timestamps.popleft()
        #     self.byte_sizes.popleft()

        
        # n = len(self.timestamps)
        
        # if n <= 1:
        #     return 0.0, 0.0; #1hz 미만이면 0리턴
        
        # elapsed_time = max(self.timestamps[-1] - self.timestamps[0], 1e-6) 
        
        # if elapsed_time <= 0:
        #     return 0; #멀티 스레딩으로 인한 시간 역전 방지
        
        #return (n -1) / elapsed_time , sum(self.byte_sizes) / 1024.0 if self.byte_sizes else 0.0


        # 최근 1초 동안의 메시지 개수만 카운트
        # n_1s = sum(1 for t in self.timestamps if now - t <= 1)

        # total_bytes = sum(self.byte_sizes)
        
        # bw = f"{total_bytes:.2f} B/s"  # 바이트 단위
        while self.timestamps and now - self.timestamps[0] > 1:
            self.timestamps.popleft()
            self.byte_sizes.popleft()
        
        n_1s = len(self.timestamps)

        bw = sum(self.byte_sizes)
        
        return n_1s, bw
    # def get_bw(self):
    #     now = time.time()
        
    #     #valid_byte_sizes = [size for t, size in zip(self.timestamps, self.byte_sizes) if now - t <= 1]
    #     while self.timestamps and now - self.timestamps[0] > 1:
    #         self.timestamps.popleft()
    #         self.byte_sizes.popleft()
            
    #     return sum(self.byte_sizes) / 1024.0 if self.byte_sizes else 0.0  #convert kb
    
    def run(self):
        while self.running and not rospy.is_shutdown():
            time.sleep(0.1)  # 불필요한 CPU 사용을 줄이기 위해 sleep
        
    def stop(self):
        self.running = False

class ROSTopicMonitor:
    def __init__(self):
        self.yaml_path = '/home/pgw/catkin_ws/src/ros_monitor/cfg/topic_lst.yaml'
        self.monitored_topics = self.load_yaml()
        
        rospy.init_node("topics_hzbw", anonymous=True)
        
        #self.master = rosgraph.masterapi.Master('/roscore')
        try:
            self.master = rosgraph.Master('/rostopic')
        except Exception as e:
            rospy.logerr(f"[monitor] Failed to retrieve published topics: {e}")    
                
        self.topic_monitors = {} #토픽 객체
        self.previous_topics = set()  # 이전 실행된 토픽 목록 저장

        self.publisher = rospy.Publisher("/topics_hzbw", String, queue_size=100)

        self.lock = threading.Lock()
        self.monitor_thread = threading.Thread(target=self.run_monitoring)
        self.monitor_thread.start()
    
        
    def load_yaml(self):
        if not os.path.exists(self.yaml_path):
            rospy.logerr(f"[monitor] yaml fiel not found: {self.yaml_path}")
            return None

        try:
            with open(self.yaml_path, 'r') as f:
                topics = {line.strip() for line in f if line.strip()}
                
                rospy.loginfo(f"[monitor] list of topics to monitor: {topics}")
                return topics
        except Exception as e:
            rospy.logerr(f"[monitor] Error loading yaml file: {e}")
            return None
        
    def update_subscriptions(self):
        active_topics = {t[0] for t in self.master.getSystemState()[0]}  #현재 실행 중인 토픽 목록
        
        new_topics = active_topics - set(self.topic_monitors.keys())#새로 추가된 토픽들
        
        if self.monitored_topics is not None:
            active_topics &= self.monitored_topics
            new_topics &= self.monitored_topics
        
        removed_topics = set(self.topic_monitors.keys()) - active_topics  # 삭제된 토픽들들

        # #토픽 삭제
        # removed_topics = set(self.topic_monitors.keys()) - active_topics
        
        # for topic in removed_topics:
        #     self.topic_monitors[topic].stop()
        #     self.topic_monitors[topic].join()
        #     del self.topic_monitors[topic]
        # 노드 목록이 변경된 경우에만 정렬 수행
        if new_topics or removed_topics:
            sorted_topics = sorted(active_topics)  # 이름 기준 오름차순 정렬

            # 기존 토픽 리스트 업데이트
            self.previous_topics = set(sorted_topics)

            # 새 토픽 추가
            for topic in new_topics:
                monitor = TopicMonitor(topic)
                self.topic_monitors[topic] = monitor
                monitor.start()

            # 삭제된 토픽 정리
            for topic in removed_topics:
                self.topic_monitors[topic].stop()
                self.topic_monitors[topic].join()
                del self.topic_monitors[topic]

    def calculate_metrics(self):
        topic_metrics_list = []
        for topic in sorted(self.topic_monitors.keys()):
            monitor = self.topic_monitors[topic]
            hz , bw = monitor.get_hz_and_bw()

            topic_metrics = {
                "topic": topic,
                "hz": hz,
                "bw": bw,
            }
            print(topic_metrics)
            topic_metrics_list.append(topic_metrics)

        if topic_metrics_list:
            self.publisher.publish(json.dumps(topic_metrics_list))        
            
    def run_monitoring(self):
        rate = rospy.Rate(1)  # 1Hz
        while not rospy.is_shutdown():
            self.update_subscriptions()
            self.calculate_metrics()
            rate.sleep()


if __name__ == "__main__":
    monitor = ROSTopicMonitor()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        for topic_monitor in monitor.topic_monitors.values():
            topic_monitor.stop()
            topic_monitor.join()

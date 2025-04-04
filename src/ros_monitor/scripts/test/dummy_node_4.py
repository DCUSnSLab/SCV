#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from ros_monitor_common.latency_tracker import LatencyTracker

class NodeD:
    def __init__(self):
        self.tracker = LatencyTracker()
        rospy.init_node('node_d')
        rospy.Subscriber('topic_c', String, self.callback)
        rospy.spin()

    def callback(self, msg):
        latency = self.tracker.track(msg)
        rospy.loginfo(f"[D] Final Received. Latency from A: {latency:.4f}s")

if __name__ == '__main__':
    NodeD()

#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from ros_monitor_common.latency_tracker import LatencyTracker

class NodeC:
    def __init__(self):
        self.tracker = LatencyTracker()
        rospy.init_node('node_c')
        self.pub = rospy.Publisher('topic_c', String, queue_size=10)
        rospy.Subscriber('topic_b', String, self.callback)
        rospy.spin()

    def callback(self, msg):
        latency = self.tracker.track(msg)
        rospy.loginfo(f"[C] Received. Latency from A: {latency:.4f}s")
        self.pub.publish(msg)

if __name__ == '__main__':
    NodeC()

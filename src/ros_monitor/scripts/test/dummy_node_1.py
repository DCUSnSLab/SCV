#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
import time

rospy.init_node('node_a')
pub = rospy.Publisher('topic_a', String, queue_size=10)
rate = rospy.Rate(1)

while not rospy.is_shutdown():
    msg = String()
    msg.data = f"{time.time()}"
    pub.publish(msg)
    rospy.loginfo(f"[A] Published: {msg.data}")
    rate.sleep()

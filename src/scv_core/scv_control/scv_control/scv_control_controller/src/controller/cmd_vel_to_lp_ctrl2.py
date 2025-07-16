#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist
from morai_msgs.msg import CtrlCmd
import math

def speed_callback(data):
    dwa_cmd = CtrlCmd()

    dwa_cmd.velocity = data.linear.x
    dwa_cmd.steering = data.angular.z 

    speed_pub.publish(dwa_cmd)

if __name__ == '__main__':
    rospy.init_node("speedpub")
    rospy.Subscriber('/cmd_vel', Twist, speed_callback)
    speed_pub = rospy.Publisher('/lp_ctrl', CtrlCmd, queue_size=1)
    rospy.spin()
#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist
from morai_msgs.msg import CtrlCmd
import math

def speed_callback(data):
    dwa_cmd = CtrlCmd()

    # m/s -> km/h 변환
    linear_x_kmh = data.linear.x * 3.6  # 1 m/s = 3.6 km/h
    dwa_cmd.velocity = linear_x_kmh

    # rad/s -> deg 변환
    angular_z_deg = data.angular.z * 180.0 / math.pi
    dwa_cmd.steering = -angular_z_deg 

    speed_pub.publish(dwa_cmd)

if __name__ == '__main__':
    rospy.init_node("speedpub")
    rospy.Subscriber('/cmd_vel', Twist, speed_callback)
    speed_pub = rospy.Publisher('/lp_ctrl', CtrlCmd, queue_size=1)
    rospy.spin()
#!/usr/bin/env python3
import rospy
import tf2_ros
from geometry_msgs.msg import TransformStamped
from nav_msgs.msg import Odometry

def handle_odom_pose(msg, br):
    t = TransformStamped()
    t.header.stamp = msg.header.stamp
    t.header.frame_id = "odom_utm"
    t.child_frame_id = "base_link"
    t.transform.translation.x = msg.pose.pose.position.x
    t.transform.translation.y = msg.pose.pose.position.y
    t.transform.translation.z = msg.pose.pose.position.z
    t.transform.rotation = msg.pose.pose.orientation

    br.sendTransform(t)

if __name__ == '__main__':
    rospy.init_node('odom_to_base_link_broadcaster')
    br = tf2_ros.TransformBroadcaster()
    rospy.Subscriber('/odom/coordinate/gps', Odometry, handle_odom_pose, br)
    #rospy.Subscriber('/odom/ekf', Odometry, handle_odom_pose, br)
    #rospy.Subscriber('scv_odom', Odometry, handle_odom_pose, br)
    #rospy.Subscriber('zed_node/odom', Odometry, handle_odom_pose, br)
    #rospy.Subscriber('/odom/coordinate/imu', Odometry, handle_odom_pose, br)
    rospy.spin()
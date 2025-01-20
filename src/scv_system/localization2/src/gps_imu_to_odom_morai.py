#!/usr/bin/env python3
import rospy
from message_filters import Subscriber, ApproximateTimeSynchronizer
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Point, Vector3, PoseStamped, Twist
from sensor_msgs.msg import Imu, NavSatFix
from morai_msgs.msg import EgoVehicleStatus, GPSMessage
from std_msgs.msg import Float64
import math
import tf
import utm
import time

class IMUGPSToOdometry:
    def __init__(self):
        rospy.init_node('odom_converter')
        #목표 좌표 발행
        # self.local_goal_pub = rospy.Publisher('/local_goal', PoseStamped, queue_size=10) # rviz goal 사용시 주석 해제
        # rospy.Subscriber('/move_base_simple/goal', PoseStamped, self.goal_pub)
        # 현재 utm좌표 발행
        self.current_utm_position = rospy.Publisher('/current_utm_relative_position', Point, queue_size=10)

        self.init_position_flag = True
        self.init_position = Point()

        # 목표 속력 발행
        # self.target_velocity_pub = rospy.Publisher('/target_velocity', Twist, queue_size=10)


        self.odom_for_coordinate_pub = rospy.Publisher('/odom/coordinate', Odometry, queue_size=50)
        self.odom_for_dwa_pub = rospy.Publisher('/odom/dwa', Odometry, queue_size=50)

        self.sub_gps = Subscriber('/gps', GPSMessage)
        self.imu_sub = Subscriber('/imu', Imu)
        self.Ego_status_sub = Subscriber('/Ego_topic', EgoVehicleStatus)
        self.ts = ApproximateTimeSynchronizer(
            [self.imu_sub, self.Ego_status_sub, self.sub_gps], 
            queue_size=10, 
            slop=0.1,  # 더 엄격한 시간 허용 범위 설정
            allow_headerless=True
        )
        self.ts.registerCallback(self.callback)
        self.local_goal = PoseStamped()
        self.local_goal_flag = False
    # def goal_pub(self, msg):      # rviz goal 사용시 주석 해제
    #     self.local_goal_flag = True
    #     self.local_goal = msg
    #     self.local_goal_pub.publish(msg)
    def callback(self, imu_data, ego_data, gps_data) :
        
        utm_coords = utm.from_latlon(gps_data.latitude, gps_data.longitude)
        easting, northing, zone_number, zone_letter = utm_coords
        if self.init_position_flag :
            time.sleep(2) # 다른 노드들 켜질 때 까지 기다림
            self.init_position.x = easting
            self.init_position.y = northing
            self.init_position.z = 0
            point_dict = {'x' : float(self.init_position.x), 'y' : float(self.init_position.y)}
            rospy.set_param('/init_position', point_dict) # ros parameter server에 init position값 저장
            rospy.loginfo("Set init position")
            self.init_position_flag = False

        # if self.local_goal_flag :      # rviz goal 사용시 주석 해제
        #     self.local_goal_pub.publish(self.local_goal)  

        # 현재 위치 (UTM 상대 좌표)
        current_utm_relative_position = Point()
        current_utm_relative_position.x = easting - self.init_position.x
        current_utm_relative_position.y = northing - self.init_position.y
        current_utm_relative_position.z = 0

        # dwa용 odom
        odom_for_dwa = Odometry()
        odom_for_dwa.header.stamp = rospy.Time.now()
        odom_for_dwa.twist.twist.linear.x = ego_data.velocity.x # 수정 필요 => imu에서 속도값을 받아와야 함
        odom_for_dwa.twist.twist.angular = imu_data.angular_velocity
        # 좌표계용 odom
        odom_coordinate = Odometry()
        odom_coordinate.header.stamp = rospy.Time.now()
        odom_coordinate.header.frame_id = "odom_utm"
        
        odom_coordinate.twist.twist.angular = imu_data.angular_velocity         
        odom_coordinate.twist.twist.linear.x = ego_data.velocity.x # 수정 필요 => imu에서 속도값을 받아와야 함
        odom_coordinate.pose.pose.orientation = imu_data.orientation 

        # 현재 위치 odom에 대입
        odom_coordinate.pose.pose.position.x = current_utm_relative_position.x
        odom_coordinate.pose.pose.position.y = current_utm_relative_position.y
        odom_coordinate.pose.pose.position.z = 0

        target_velocity = Twist()

        target_velocity.linear.x = 1.4
        target_velocity.linear.y = 0
        target_velocity.linear.z = 0
        # publish
        
        self.current_utm_position.publish(current_utm_relative_position)
        self.odom_for_coordinate_pub.publish(odom_coordinate)
        self.odom_for_dwa_pub.publish(odom_for_dwa)


if __name__ == '__main__':

    synced_publisher = IMUGPSToOdometry()
    rospy.spin()

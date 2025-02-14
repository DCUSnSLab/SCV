#!/usr/bin/env python3
import rospy
import message_filters
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Point, Vector3, PoseStamped, Twist
from sensor_msgs.msg import Imu, NavSatFix
from morai_msgs.msg import EgoVehicleStatus, GPSMessage
from std_msgs.msg import Float64, UInt32
from ublox_msgs.msg import NavPVT
import math
import tf
import utm
import time
from tf.transformations import quaternion_multiply

class IMUGPSToOdometry:
    def __init__(self):
        rospy.init_node('odom_converter')
        #목표 좌표 발행
        # self.local_goal_pub = rospy.Publisher('/local_goal', PoseStamped, queue_size=10) # rviz goal 사용시 주석 해제
        # rospy.Subscriber('/move_base_simple/goal', PoseStamped, self.goal_pub)
        # 현재 utm좌표 발행
        self.current_utm_position = rospy.Publisher('/current_utm_relative_position', Point, queue_size=10)
        self.add = 0
        self.init_position_flag = True
        self.init_position = Point()

        
        self.distance = 0
        self.odom_for_coordinate_pub_imu = rospy.Publisher('/odom/coordinate/imu', Odometry, queue_size=50)
        self.odom_for_coordinate_pub_gps = rospy.Publisher('/odom/coordinate/gps', Odometry, queue_size=50)
        self.odom_for_dwa_pub = rospy.Publisher('/odom/dwa', Odometry, queue_size=50)

        self.sub_gps = message_filters.Subscriber('/ublox_gps/fix', NavSatFix)
        self.imu_sub = message_filters.Subscriber('/imu/data', Imu)
        self.heading_sub = message_filters.Subscriber('/ublox_gps/navpvt', NavPVT)
        self.current_motor_RPM = message_filters.Subscriber('/current_motor_RPM', UInt32)
        
        self.ts = message_filters.ApproximateTimeSynchronizer([self.heading_sub, self.imu_sub, self.sub_gps, self.current_motor_RPM], queue_size=10, slop=0.5, allow_headerless=True)
        self.ts.registerCallback(self.callback)
        self.local_goal = PoseStamped()
        self.local_goal_flag = False
    # def goal_pub(self, msg):      # rviz goal 사용시 주석 해제
    #     self.local_goal_flag = True
    #     self.local_goal = msg
    #     self.local_goal_pub.publish(msg)
    def degrees_to_quaternion(self, degrees):  # gps heading 사용시 해제
        # 북쪽 기준의 각도를 동쪽 기준으로 변환
        east_based_degrees = degrees - 90
        radians = math.radians(-east_based_degrees)
        w = math.cos(radians / 2)
        z = math.sin(radians / 2)
        print("heading (east-based):", east_based_degrees)
        return (0, 0, z, w)


    def north_quaternion_to_east_quaternion(self, q):
        """
        북쪽 기준의 쿼터니언을 동쪽 기준 반시계 방향 쿼터니언으로 변환
        2차원 평면에서의 Z축 기준 회전만 고려
        Args:
        q (Quaternion): 북쪽 기준의 쿼터니언
        Returns:
        Quaternion: 동쪽 기준 반시계 방향 쿼터니언 (Z축 회전만 사용)
        """
        # 현재 쿼터니언에서 X, Y는 무시하고 Z, W만 사용
        q_current = [0, 0, q.z, q.w]  

        # Z축을 중심으로 90도 회전하는 쿼터니언 생성 (2D 평면에서의 변환)
        q_rotate = [0, 0, math.sin(math.radians(90) / 2), math.cos(math.radians(90) / 2)]

        # 새로운 쿼터니언 계산 (회전 적용)
        q_new = quaternion_multiply(q_rotate, q_current)

        # Z축 회전만 사용하므로 X, Y는 0으로 설정
        q_result = Quaternion()
        q_result.x = 0
        q_result.y = 0
        q_result.z = q_new[2]
        q_result.w = q_new[3]

        # 단위 쿼터니언 조건을 만족하도록 정규화
        norm = math.sqrt(q_result.x**2 + q_result.y**2 + q_result.z**2 + q_result.w**2)
        q_result.z /= norm
        q_result.w /= norm

        return q_result

    def rpm2ms(self, rpm) :
        return 0.01094 * rpm.data + 0.02143 if rpm.data > 5 else 0
    def get_driving_option(self):
        if rospy.get_param("/driving_option"): return rospy.get_param("/driving_option")
        else :
            rospy.loginfo("Driving option parameter does not exist ")
            return "0" # return value is foward
    def callback(self, heading_data, imu_data, gps_data, RPM_data) :
        current_speed = self.rpm2ms(RPM_data)
        if self.get_driving_option() == "1" or self.get_driving_option() == "9" : # 후진시 현재 속도를 -로 받아와야 함
            current_speed *= -1

        utm_coords = utm.from_latlon(gps_data.latitude, gps_data.longitude)
        easting, northing, zone_number, zone_letter = utm_coords
        if self.init_position_flag :
            time.sleep(2) # 다른 노드들 켜질 때 까지 기다림
            self.init_position.x = easting
            self.init_position.y = northing
            self.init_position.z = 0
            #print(self.init_position.x, self.init_position.y)
            point_dict = {'x' : float(self.init_position.x), 'y' : float(self.init_position.y)}
            rospy.set_param('/init_position', point_dict) # ros parameter server에 init position값 저장
            rospy.loginfo("Set init position")
            self.init_position_flag = False
        # if self.local_goal_flag :      # rviz goal 사용시 주석 해제
        #     self.local_goal_pub.publish(self.local_goal)
        # self.add += 0.1
        # northing+= self.add
        heading_gps = heading_data.heading/(10**5)        # gps heading 사용시 해제
        heading_gps_quaternion = self.degrees_to_quaternion(heading_gps)      # gps heading 사용시 해제
        heading_imu_quaternion = self.north_quaternion_to_east_quaternion(imu_data.orientation)
        # 현재 위치 (UTM 상대 좌표)
        current_utm_relative_position = Point()
        current_utm_relative_position.x = easting - self.init_position.x
        current_utm_relative_position.y = northing - self.init_position.y
        current_utm_relative_position.z = 0

        # dwa용 odom
        odom_for_dwa = Odometry()
        odom_for_dwa.header.stamp = rospy.Time.now()
        odom_for_dwa.twist.twist.linear.x = current_speed # 수정 필요 => imu에서 속도값을 받아와야 함
        odom_for_dwa.twist.twist.angular = imu_data.angular_velocity


        # odom imu
        odom_coordinate_imu = Odometry()
        odom_coordinate_imu.header.stamp = rospy.Time.now()
        odom_coordinate_imu.header.frame_id = "odom_utm"
        odom_coordinate_imu.twist.twist.angular = imu_data.angular_velocity
        odom_coordinate_imu.twist.twist.linear.x = current_speed # 수정 필요 => imu에서 속도값을 받아와야 함
        odom_coordinate_imu.pose.pose.orientation = heading_imu_quaternion

        # 현재 위치 odom에 대입
        odom_coordinate_imu.pose.pose.position.x = current_utm_relative_position.x
        odom_coordinate_imu.pose.pose.position.y = current_utm_relative_position.y
        odom_coordinate_imu.pose.pose.position.z = 0

        # odom gps
        odom_coordinate_gps = Odometry()
        odom_coordinate_gps.header.stamp = rospy.Time.now()
        odom_coordinate_gps.header.frame_id = "odom_utm"
        odom_coordinate_gps.twist.twist.angular = imu_data.angular_velocity
        odom_coordinate_gps.twist.twist.linear.x = current_speed # 수정 필요 => imu에서 속도값을 받아와야 함
        odom_coordinate_gps.pose.pose.orientation.x = heading_gps_quaternion[0]
        odom_coordinate_gps.pose.pose.orientation.y = heading_gps_quaternion[1]
        odom_coordinate_gps.pose.pose.orientation.z = heading_gps_quaternion[2]
        odom_coordinate_gps.pose.pose.orientation.w = heading_gps_quaternion[3]
        # 현재 위치 odom에 대입
        odom_coordinate_gps.pose.pose.position.x = current_utm_relative_position.x
        odom_coordinate_gps.pose.pose.position.y = current_utm_relative_position.y
        odom_coordinate_gps.pose.pose.position.z = 0

        # publish
        
        self.current_utm_position.publish(current_utm_relative_position)
        self.odom_for_coordinate_pub_imu.publish(odom_coordinate_imu)
        self.odom_for_coordinate_pub_gps.publish(odom_coordinate_gps)
        self.odom_for_dwa_pub.publish(odom_for_dwa)


if __name__ == '__main__':

    synced_publisher = IMUGPSToOdometry()
    rospy.spin()
#!/usr/bin/env python3
import rospy
import math
import time
import utm

from sensor_msgs.msg import Imu, NavSatFix
from ublox_msgs.msg import NavPVT
from hunter_msgs.msg import HunterStatus
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Point
from tf.transformations import quaternion_from_euler

class IMUGPSToOdometry:
    def __init__(self):
        rospy.init_node('odom_converter_ekf', anonymous=True)

        # ------------------- Publisher -------------------
        self.current_utm_position_pub  = rospy.Publisher('/current_utm_relative_position', Point, queue_size=10)
        self.odom_for_coordinate_pub_imu   = rospy.Publisher('/odom/coordinate/imu', Odometry, queue_size=50)
        self.odom_for_coordinate_pub_gps   = rospy.Publisher('/odom/coordinate/gps', Odometry, queue_size=50)
        self.odom_for_dwa_pub             = rospy.Publisher('/odom/dwa', Odometry, queue_size=50)  # DWA는 GPS 속도 기반

        # ------------------- Subscriber -------------------
        self.gps_fix_sub = rospy.Subscriber('/ublox_gps/fix', NavSatFix, self.gps_fix_callback)
        self.navpvt_sub  = rospy.Subscriber('/ublox_gps/navpvt', NavPVT, self.navpvt_callback)
        self.imu_sub     = rospy.Subscriber('/vectornav/IMU', Imu, self.imu_callback)
        self.speed_sub   = rospy.Subscriber('/hunter_status', HunterStatus, self.hunter_status_callback)

        # ------------------- 내부 상태 변수 -------------------
        # GPS Fix
        self.gps_fix_msg = None
        self.init_position_flag = True
        self.init_position = Point()  # UTM 기준 초기 위치 저장

        # NavPVT (GPS Heading)
        self.navpvt_msg = None         # 최신 GPS 헤딩 메시지 저장
        self.last_gps_heading = None   # 이전 GPS 헤딩 (도 단위)
        self.previous_gps_heading = None

        # IMU
        self.imu_msg = None
        self.last_time = None  # 이전 IMU 콜백 시각

        # Hunter Status (속도)
        self.hunter_status_msg = None
        self.current_speed = 0.0

        # ------------------- EKF 변수 (Heading 융합) -------------------
        self.ekf_initialized = False
        self.ekf_heading = None   # EKF로 추정한 heading (라디안)
        self.ekf_P = None         # 상태 오차 공분산
        self.Q = 0.001            # 프로세스 노이즈 (필요에 따라 조정)
        self.R = 0.01             # 측정 노이즈 (필요에 따라 조정)
        self.gps_heading_meas = None      # 신뢰할 수 있는 GPS heading (라디안, 동쪽 기준)
        self.gps_heading_updated = False  # 새로운 GPS 관측이 도착했는지 플래그

        rospy.loginfo("IMUGPSToOdometry node (with EKF) initialized.")

    # ------------------- 콜백 함수들 -------------------
    def gps_fix_callback(self, msg):
        """
        /ublox_gps/fix (NavSatFix) 콜백:
          - UTM 좌표로 변환하여 초기 위치 설정 및 최신 위치 업데이트
        """
        self.gps_fix_msg = msg

        # UTM 변환
        easting, northing, zone_number, zone_letter = utm.from_latlon(msg.latitude, msg.longitude)

        # 초기 위치 설정
        if self.init_position_flag:
            rospy.loginfo("Initializing position with first GPS fix...")
            time.sleep(2.0)  # 다른 노드 초기화를 위한 대기
            self.init_position.x = easting
            self.init_position.y = northing
            self.init_position.z = 0
            rospy.set_param('/init_position', {'x': float(easting), 'y': float(northing)})
            self.init_position_flag = False
            rospy.loginfo("Initial UTM position set.")

    def navpvt_callback(self, msg):
        """
        /ublox_gps/navpvt (NavPVT) 콜백:
          - GPS로부터 Heading(deg)을 받아서 처리 (헤딩 x 1e-5)
          - 동쪽 기준 라디안으로 변환하여 EKF 측정값 갱신
          - 단, 현재 속도가 0.6 이상일 때만 신뢰할 수 있다고 판단
        """
        self.navpvt_msg = msg
        heading_deg = msg.heading / 1e5  # 도 단위

        reversed_heading_deg = heading_deg

        self.last_gps_heading = heading_deg
        self.previous_gps_heading = heading_deg

        # 동쪽 기준 라디안으로 변환 (north_degree_to_east_radians 함수 사용)
        # navpvt에서 나오는 헤딩은 북쪽 기준으로 나왔음
        gps_heading_rad = self.north_degree_to_east_radians(reversed_heading_deg)
        # 속도가 0.6 이상일 때만 업데이트 (그 미만은 신뢰도가 낮다고 판단)
        if self.current_speed >= 0.6:
            self.gps_heading_meas = gps_heading_rad
            self.gps_heading_updated = True

    def hunter_status_callback(self, msg):
        """
        /hunter_status (HunterStatus) 콜백:
          - 차량의 선속도(전/후진)를 업데이트
        """
        self.hunter_status_msg = msg
        self.current_speed = msg.linear_velocity  # 전진: 양수, 후진: 음수

    def imu_callback(self, msg):
        """
        /vectornav/IMU 콜백:
          - 주기가 빠른 IMU 데이터를 바탕으로 EKF를 통한 heading 추정 및 오도메트리 계산/발행
        """
        self.imu_msg = msg
        current_time = msg.header.stamp.to_sec()

        # 초기화: GPS fix가 아직 없거나 초기 위치 미설정 시 return
        if self.init_position_flag or self.gps_fix_msg is None:
            return

        if self.last_time is None:
            self.last_time = current_time
            # EKF 초기화: navpvt로부터 받은 GPS heading 사용
            if (not self.ekf_initialized) and (self.gps_heading_meas is not None):
                self.ekf_heading = self.gps_heading_meas
                self.ekf_P = 1.0  # 초기 오차 공분산 (필요에 따라 조정)
                self.ekf_initialized = True
                rospy.loginfo("EKF heading initialized with GPS measurement.")
            return

        dt = current_time - self.last_time
        self.last_time = current_time

        omega_z = msg.angular_velocity.z  # IMU의 Z축 각속도

        # EKF Prediction 단계: IMU의 yaw rate 적분
        if not self.ekf_initialized:
            if self.gps_heading_meas is not None:
                self.ekf_heading = self.gps_heading_meas
                self.ekf_P = 1.0
                self.ekf_initialized = True
                rospy.loginfo("EKF heading initialized with GPS measurement.")
            else:
                return

        # 예측 단계
        predicted_heading = self.normalize_angle(self.ekf_heading + omega_z * dt)
        self.ekf_P = self.ekf_P + self.Q * dt  # dt에 비례하여 프로세스 노이즈 추가

        # EKF Update 단계: 속도가 0.6 이상일 때만 GPS 측정을 사용하여 업데이트
        if self.current_speed >= 0.6 and self.gps_heading_updated and (self.gps_heading_meas is not None):
            innovation = self.angle_diff(self.gps_heading_meas, predicted_heading)
            K = self.ekf_P / (self.ekf_P + self.R)
            updated_heading = predicted_heading + K * innovation
            self.ekf_heading = self.normalize_angle(updated_heading)
            self.ekf_P = (1 - K) * self.ekf_P
            self.gps_heading_updated = False
        else:
            # 속도가 낮으면 측정 업데이트 없이 단순히 예측값을 사용
            self.ekf_heading = predicted_heading

        # --------- 위치 (GPS Fix) 처리 ---------
        # UTM 변환
        easting, northing, _, _ = utm.from_latlon(self.gps_fix_msg.latitude, self.gps_fix_msg.longitude)
        current_utm_relative_position = Point()
        current_utm_relative_position.x = easting - self.init_position.x
        current_utm_relative_position.y = northing - self.init_position.y
        current_utm_relative_position.z = 0.0

        # --------- Quaternion 변환 및 메시지 구성 ---------
        # IMU 기준 오리엔테이션 (north_quaternion_to_east_quaternion 이용)
        heading_imu_quaternion = self.north_quaternion_to_east_quaternion(msg.orientation)

        # EKF로 추정한 heading (라디안)을 이용하여 쿼터니언 생성 (동쪽 기준)
        ekf_quat_tuple = quaternion_from_euler(0, 0, self.ekf_heading)
        ekf_quat = Quaternion(*ekf_quat_tuple)

        # Odometry 메시지 구성
        # (1) IMU 기준 오도메트리
        odom_imu = Odometry()
        odom_imu.header.stamp = msg.header.stamp
        odom_imu.header.frame_id = "odom_utm"
        odom_imu.pose.pose.position = current_utm_relative_position
        odom_imu.pose.pose.orientation = heading_imu_quaternion
        odom_imu.twist.twist.linear.x = self.current_speed
        odom_imu.twist.twist.angular = msg.angular_velocity

        # (2) EKF 기반 GPS 헤딩 오도메트리
        odom_gps = Odometry()
        odom_gps.header.stamp = msg.header.stamp
        odom_gps.header.frame_id = "odom_utm"
        odom_gps.pose.pose.position = current_utm_relative_position
        odom_gps.pose.pose.orientation = ekf_quat
        odom_gps.twist.twist.linear.x = self.current_speed
        odom_gps.twist.twist.angular.z = 0.0  # GPS 기반은 각속도 0으로 설정

        # (3) DWA용 오도메트리 (GPS 속도 기반)
        odom_dwa = Odometry()
        odom_dwa.header.stamp = msg.header.stamp
        odom_dwa.twist.twist.linear.x = self.current_speed
        odom_dwa.twist.twist.angular.z = 0.0

        # --------- Publish ---------
        self.current_utm_position_pub.publish(current_utm_relative_position)
        self.odom_for_coordinate_pub_imu.publish(odom_imu)
        self.odom_for_coordinate_pub_gps.publish(odom_gps)
        self.odom_for_dwa_pub.publish(odom_dwa)

    # ------------------- 유틸 함수들 -------------------
    def normalize_angle(self, angle):
        """ -pi ~ pi 범위로 정규화 (라디안) """
        return math.atan2(math.sin(angle), math.cos(angle))

    def normalize_degree(self, degree):
        """ 0 ~ 360 범위로 정규화 (각도) """
        return degree % 360

    def angle_diff(self, a, b):
        """
        두 각도 a, b (라디안)의 차이를 [-pi, pi] 범위로 계산
        (a - b)를 올바르게 wrap-around
        """
        diff = a - b
        return math.atan2(math.sin(diff), math.cos(diff))

    def north_degree_to_east_radians(self, degrees):
        """
        북쪽 기준(deg) → 동쪽 기준(radians) 변환  
        (북쪽 0도는 동쪽 0도로 취급하기 위해, '-(degrees - 90)' 적용)
        """
        east_based_degrees = degrees - 90.0
        return math.radians(-east_based_degrees)

    def north_quaternion_to_east_quaternion(self, q):
        """
        북쪽 기준의 IMU orientation을 동쪽 기준으로 변환  
        (Z축 회전만 고려, roll/pitch는 무시)
        """
        import tf
        from tf.transformations import quaternion_multiply

        q_current = [0, 0, q.z, q.w]
        # 90도 회전을 위한 쿼터니언 (z축 회전)
        q_rotate = [0, 0, math.sin(math.radians(90) / 2), math.cos(math.radians(90) / 2)]
        q_new = quaternion_multiply(q_rotate, q_current)

        # geometry_msgs/Quaternion 형태로 변환
        q_result = Quaternion()
        q_result.x = 0
        q_result.y = 0
        q_result.z = q_new[2]
        q_result.w = q_new[3]

        # 정규화
        norm = math.sqrt(q_result.x**2 + q_result.y**2 + q_result.z**2 + q_result.w**2)
        if norm > 1e-10:
            q_result.z /= norm
            q_result.w /= norm
        return q_result

if __name__ == '__main__':
    try:
        node = IMUGPSToOdometry()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

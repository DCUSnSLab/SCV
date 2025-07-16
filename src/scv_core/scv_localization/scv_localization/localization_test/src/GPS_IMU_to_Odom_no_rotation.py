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
from tf.transformations import quaternion_from_euler, euler_from_quaternion

class IMUGPSToOdometry:
    def __init__(self):
        rospy.init_node('odom_converter_separate_callbacks', anonymous=True)

        # ------------------- Publisher -------------------
        self.current_utm_position_pub  = rospy.Publisher('/current_utm_relative_position', Point, queue_size=10)
        self.odom_for_coordinate_pub_imu   = rospy.Publisher('/odom/coordinate/imu', Odometry, queue_size=50)
        self.odom_for_coordinate_pub_gps   = rospy.Publisher('/odom/coordinate/gps', Odometry, queue_size=50)
        self.odom_for_dwa_pub             = rospy.Publisher('/odom/dwa', Odometry, queue_size=50) # DWA는 이제 퓨즈드 대신 GPS 속도 기반으로 사용

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
        self.navpvt_msg = None  # 최신 GPS 헤딩을 저장
        self.last_gps_heading = None  # (도 단위)
        self.previous_gps_heading = None # 이전 GPS 헤딩 저장 (반전 감지용)
        self.last_gps_heading_reversed = None # 반전 처리된 GPS 헤딩 저장

        # IMU
        self.imu_msg = None
        self.last_time = None  # 이전 IMU 콜백 시각

        # Hunter Status (속도)
        self.hunter_status_msg = None
        self.current_speed = 0.0
        self.reverse_driving = False # 현재 reverse_driving 상태 저장

        # GPS Odometry Heading Integration
        self.gps_odom_heading = None # GPS 오도메트리에 IMU 각속도 적분해서 사용할 헤딩 값
        self.previous_slow_or_reverse = False # 이전 상태 저장 (저속/후진 여부)

        rospy.loginfo("IMUGPSToOdometry node initialized.")

    # ------------------- 콜백 함수들 -------------------
    def gps_fix_callback(self, msg):
        """
        /ublox_gps/fix (NavSatFix) 콜백:
          - 초기에 UTM 좌표계로 변환해서 init_position 설정
          - 이후부터는 최신 위치를 저장
        """
        self.gps_fix_msg = msg

        # UTM 변환
        easting, northing, zone_number, zone_letter = utm.from_latlon(msg.latitude, msg.longitude)

        # 초기 위치 설정
        if self.init_position_flag:
            rospy.loginfo("Initializing position with first GPS fix...")
            time.sleep(2.0)  # 다른 노드가 초기화될 시간 확보
            self.init_position.x = easting
            self.init_position.y = northing
            self.init_position.z = 0
            rospy.set_param('/init_position', {'x': float(easting), 'y': float(northing)})
            self.init_position_flag = False
            rospy.loginfo("Initial UTM position set.")

    def navpvt_callback(self, msg):
        """
        /ublox_gps/navpvt (NavPVT) 콜백:
          - GPS로부터 Heading(deg)을 받아 저장 (heading x 1e-5)
        """
        self.navpvt_msg = msg
        heading_deg = msg.heading / 1e5  # 도 단위

        # 급격한 헤딩 변화 감지 및 180도 반전 처리
        reversed_heading_deg = heading_deg # 기본값은 그대로
        if self.last_gps_heading is not None:
            heading_diff = abs(heading_deg - self.last_gps_heading)
            if heading_diff > 120 and heading_diff < 240: # 급격한 변화 threshold (120~240도 변화)
                reversed_heading_deg = self.normalize_degree(heading_deg + 180) # 180도 반전

        self.last_gps_heading = heading_deg # 현재 heading을 이전 값으로 저장 (다음 콜백에서 비교용)
        self.previous_gps_heading = heading_deg # 이전 GPS 헤딩 업데이트 (매번 업데이트)
        self.last_gps_heading_reversed = reversed_heading_deg # 반전 처리된 헤딩 저장

    def hunter_status_callback(self, msg):
        """
        /hunter_status (HunterStatus) 콜백:
          - 속도(m/s) 등을 받아 저장
        """
        self.hunter_status_msg = msg
        self.current_speed = msg.linear_velocity  # 전/후진 시 음수/양수
        self.reverse_driving = (self.current_speed < -0.1) # 후진 기준 속도 -0.1 m/s

    def imu_callback(self, msg):
        """
        /vectornav/IMU 콜백:
          - 가장 주기가 빠른(40Hz) 토픽이므로 여기서 오도메트리 계산 및 발행
        """
        self.imu_msg = msg
        current_time = msg.header.stamp.to_sec()

        # 초기화가 안 되었거나, GPS fix가 아직 없다면 진행 불가
        if self.init_position_flag or self.gps_fix_msg is None:
            return

        # -- dt 계산 --
        if self.last_time is None:
            # 첫 IMU 콜백 도착 시점
            self.last_time = current_time
            # 초기 GPS 오도메트리 헤딩 값 설정 (GPS heading으로)
            if self.last_gps_heading_reversed is not None:
                self.gps_odom_heading = self.north_degree_to_east_radians(self.last_gps_heading_reversed)
                rospy.loginfo("GPS Odometry Heading Initialized with GPS Heading.")
            return

        dt = current_time - self.last_time
        self.last_time = current_time

        # -- 속도 / 후진 판단 --
        speed = self.current_speed
        reverse_driving = self.reverse_driving # self.hunter_status_callback 에서 업데이트 됨
        slow_driving = (abs(speed) < 0.6)
        current_slow_or_reverse = slow_driving or reverse_driving

        # --------- 위치 (GPS Fix) 처리 ---------
        # UTM 변환
        easting, northing, _, _ = utm.from_latlon(self.gps_fix_msg.latitude, self.gps_fix_msg.longitude)
        current_utm_relative_position = Point()
        current_utm_relative_position.x = easting - self.init_position.x
        current_utm_relative_position.y = northing - self.init_position.y
        current_utm_relative_position.z = 0.0

        # --------- GPS Odometry Heading 계산 ---------
        omega_z = msg.angular_velocity.z  # IMU Z축 각속도

        if not current_slow_or_reverse:
            # 정상 속도 전진 시: GPS Heading 사용
            if self.last_gps_heading_reversed is not None:
                self.gps_odom_heading = self.north_degree_to_east_radians(self.last_gps_heading_reversed)
            self.previous_slow_or_reverse = False

        else:
            # 느리거나 후진 시: IMU 각속도 적분
            if not self.previous_slow_or_reverse:
                # 정상 속도 → 저속/후진으로 전환 시, GPS Heading으로 초기화
                if self.last_gps_heading_reversed is not None:
                    self.gps_odom_heading = self.north_degree_to_east_radians(self.last_gps_heading_reversed)
                rospy.loginfo("Switching to slow/reverse driving for GPS odom heading. Initializing with GPS heading.")

            if self.gps_odom_heading is not None: # gps_odom_heading이 초기화 된 후에 적분 시작
                self.gps_odom_heading += omega_z * dt
                self.gps_odom_heading = self.normalize_angle(self.gps_odom_heading)

            self.previous_slow_or_reverse = current_slow_or_reverse


        # --------- Quaternion 변환 및 메시지 구성 ---------

        # -- IMU 오리엔테이션(북→동 변환은 메시지에서 직접 함) --
        heading_imu_quaternion = self.north_quaternion_to_east_quaternion(msg.orientation)

        # -- GPS 헤딩(쿼터니언) - 반전 처리 적용, IMU 적분 적용 --
        gps_quat = (0, 0, 0, 1) # 기본값
        if self.gps_odom_heading is not None:
            gps_quat = quaternion_from_euler(0, 0, self.gps_odom_heading) # IMU 적분된 헤딩 사용
            gps_quat = Quaternion(*gps_quat)


        # --------- Odometry 메시지들 ---------
        # (1) IMU 기준 오도메트리
        odom_imu = Odometry()
        odom_imu.header.stamp = msg.header.stamp
        odom_imu.header.frame_id = "odom_utm" # 프레임 ID 통일
        odom_imu.pose.pose.position = current_utm_relative_position # GPS 위치 사용
        odom_imu.pose.pose.orientation = heading_imu_quaternion
        odom_imu.twist.twist.linear.x = self.current_speed # HunterStatus 속도 사용
        odom_imu.twist.twist.angular = msg.angular_velocity # IMU 각속도 사용

        # (2) GPS 헤딩 기준 오도메트리
        odom_gps = Odometry()
        odom_gps.header.stamp = msg.header.stamp
        odom_gps.header.frame_id = "odom_utm" # 프레임 ID 통일
        odom_gps.pose.pose.position = current_utm_relative_position # GPS 위치 사용
        if self.gps_odom_heading is not None: # gps_odom_heading이 초기화 된 경우에만 방향 정보 publish
            odom_gps.pose.pose.orientation = gps_quat
        odom_gps.twist.twist.linear.x = self.current_speed # HunterStatus 속도 사용
        odom_gps.twist.twist.angular.z = 0.0 # GPS 기반은 각속도 0으로 설정 (혹은 NavPVT의 courseOverGround 사용 가능)

        # (3) DWA용 오도메트리 (GPS 속도 기반)
        odom_dwa = Odometry()
        odom_dwa.header.stamp = msg.header.stamp
        odom_dwa.twist.twist.linear.x = self.current_speed # HunterStatus 속도 사용
        odom_dwa.twist.twist.angular.z = 0.0 # 각속도 0으로 설정 (DWA는 twist.angular.z 만 사용)


        # --------- Publish ---------
        self.current_utm_position_pub.publish(current_utm_relative_position)
        self.odom_for_coordinate_pub_imu.publish(odom_imu)
        self.odom_for_coordinate_pub_gps.publish(odom_gps)
        self.odom_for_dwa_pub.publish(odom_dwa)

    # ------------------- 유틸 함수들 -------------------
    def normalize_angle(self, angle):
        """ -pi ~ pi 범위로 정규화 (라디안)"""
        return math.atan2(math.sin(angle), math.cos(angle))

    def normalize_degree(self, degree):
        """ 0 ~ 360 범위로 정규화 (각도)"""
        if degree > 360:
            degree -= 360
        elif degree < 0:
            degree += 360
        return degree


    def degrees_to_quaternion(self, degrees):
        """
        GPS가 주는 Heading(deg)가 북쪽 기준이므로,
        동쪽 기준(radians)으로 바꾼 뒤 쿼터니언으로 변환
        """
        radians = self.north_degree_to_east_radians(degrees)
        q = quaternion_from_euler(0, 0, radians)
        return q  # (x, y, z, w)

    def north_degree_to_east_radians(self, degrees):
        """
        북쪽 기준(deg) → 동쪽 기준(radians) 변환
        북쪽 0도 → 동쪽 0도 이므로, 실제로는 '-(degrees - 90)도'에 해당
        """
        east_based_degrees = degrees - 90.0
        return math.radians(-east_based_degrees)

    def north_quaternion_to_east_quaternion(self, q):
        """
        원래는 IMU orientation을 NED -> ENU로 90도 회전시키던 함수를
        회전 없이 그대로 반환하도록 수정.
        """
        # 그대로 반환할 때, 혹시 모를 쿼터니언 정규화만 간단히 해줄 수 있음
        from geometry_msgs.msg import Quaternion
        q_result = Quaternion()
        q_result.x = q.x
        q_result.y = q.y
        q_result.z = q.z
        q_result.w = q.w

        # 정규화 (원하지 않으면 아래 두 줄은 제거 가능)
        norm = math.sqrt(q_result.x**2 + q_result.y**2 + q_result.z**2 + q_result.w**2)
        if norm > 1e-10:
            q_result.x /= norm
            q_result.y /= norm
            q_result.z /= norm
            q_result.w /= norm

        return q_result


if __name__ == '__main__':
    try:
        node = IMUGPSToOdometry()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
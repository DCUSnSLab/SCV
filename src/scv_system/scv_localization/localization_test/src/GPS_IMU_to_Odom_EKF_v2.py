#!/usr/bin/env python3
import rospy
import math
import time
import utm
import numpy as np

from sensor_msgs.msg import Imu, NavSatFix
from ublox_msgs.msg import NavPVT
from hunter_msgs.msg import HunterStatus
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Point
from tf.transformations import quaternion_from_euler, euler_from_quaternion

class IMUGPSToOdometryEKF:
    def __init__(self):
        rospy.init_node('odom_converter_ekf', anonymous=True)

        # ------------------- Publisher -------------------
        self.current_utm_position_pub  = rospy.Publisher('/current_utm_relative_position', Point, queue_size=10)
        self.odom_pub_ekf   = rospy.Publisher('/odom/coordinate/gps', Odometry, queue_size=50)

        # ------------------- Subscriber -------------------
        self.gps_fix_sub = rospy.Subscriber('/ublox_gps/fix', NavSatFix, self.gps_fix_callback)
        self.navpvt_sub  = rospy.Subscriber('/ublox_gps/navpvt', NavPVT, self.navpvt_callback)
        self.imu_sub     = rospy.Subscriber('/vectornav/IMU', Imu, self.imu_callback)
        self.speed_sub   = rospy.Subscriber('/hunter_status', HunterStatus, self.hunter_status_callback)

        # ------------------- 내부 상태 변수 -------------------
        # GPS Fix
        self.gps_fix_msg = None
        self.init_position_flag = True
        self.init_position_utm = Point()  # UTM 기준 초기 위치 저장

        # GPS Heading
        self.gps_heading_deg = None  # GPS에서 받은 Heading(deg, 북쪽 기준)
        self.gps_heading_meas = None # EKF 업데이트용 Heading(radian, 동쪽 기준)

        # IMU
        self.imu_msg = None
        self.last_time = None

        # 속도
        self.current_speed = 0.0

        # ------------------- EKF 상태 정의 -------------------
        # 상태 벡터: X = [x, y, yaw]
        #  - x, y  : UTM 기준으로 로봇의 상대 좌표 (초기 위치를 (0,0)이라 가정)
        #  - yaw   : 동쪽 기준(rad)
        #
        # 공분산 P (3x3)
        self.X = np.zeros((3,1))  # [x, y, yaw]^T
        self.P = np.eye(3) * 1.0  # 초기 공분산 크게 잡음

        self.ekf_initialized = False

        # ------------------- 노이즈 공분산 설정 (예시) -------------------
        # Q: 프로세스 노이즈 (예: IMU 각속도 및 속도 모델의 불확실성 반영)
        #   - 단위: 대략 (m^2), (rad^2)에 맞춰서 조정
        self.Q = np.diag([0.05, 0.05, 0.001])  # 예시값

        # R_position: GPS 위치 측정 노이즈 (m^2)
        self.R_pos = np.diag([0.1, 0.1])  # x, y 좌표 측정 오차
        # R_heading: GPS heading 측정 노이즈 (rad^2)
        self.R_heading = np.array([[0.7]])  # heading 오차 (라디안^2)

        # flag: 새로운 GPS 측정이 들어왔는지
        self.new_gps_position = False
        self.new_gps_heading  = False

        rospy.loginfo("IMUGPSToOdometry node (EKF with position & heading) initialized.")

    # ------------------- 콜백 함수들 -------------------
    def gps_fix_callback(self, msg):
        """ /ublox_gps/fix (NavSatFix) 콜백 """
        self.gps_fix_msg = msg

        # UTM 변환
        easting, northing, _, _ = utm.from_latlon(msg.latitude, msg.longitude)

        # 초기 위치 설정
        if self.init_position_flag:
            rospy.loginfo("Initializing position with first GPS fix...")
            time.sleep(1.0)  # 다른 노드 초기화를 위한 대기
            self.init_position_utm.x = easting
            self.init_position_utm.y = northing
            self.init_position_utm.z = 0
            rospy.set_param('/init_position', {'x': float(easting), 'y': float(northing)})
            self.init_position_flag = False
            rospy.loginfo("Initial UTM position set.")
            # EKF도 초기화 시도 (heading은 navpvt에서 받아와야 정확)
            # 위치는 [0, 0], heading은 아직 모름 -> heading은 GPS heading 들어오면 세팅

        # 위치 업데이트 (GPS)
        self.new_gps_position = True

    def navpvt_callback(self, msg):
        """ /ublox_gps/navpvt (NavPVT) 콜백 - GPS Heading """
        heading_deg = msg.heading / 1e5  # 도 단위 (북쪽 기준)
        self.gps_heading_deg = heading_deg
        # 동쪽 기준 라디안 변환
        gps_heading_rad = self.north_degree_to_east_radians(heading_deg)

        # 속도가 0.6 이상일 때만 업데이트 (그 미만은 신뢰도가 낮다고 판단)
        if self.current_speed >= 0.6:
            self.gps_heading_meas = gps_heading_rad
            self.new_gps_heading  = True

    def hunter_status_callback(self, msg):
        """ /hunter_status (HunterStatus) 콜백 - 차량의 선속도 """
        self.current_speed = msg.linear_velocity  # 전진: 양수, 후진: 음수

    def imu_callback(self, msg):
        """
        /vectornav/IMU 콜백:
         - 주기가 빠른 IMU 데이터를 바탕으로 EKF Prediction
         - GPS 데이터가 있으면 Update
        """
        self.imu_msg = msg
        current_time = msg.header.stamp.to_sec()

        # 초기화 체크
        if self.init_position_flag or (self.gps_fix_msg is None):
            return

        if self.last_time is None:
            self.last_time = current_time
            # EKF 초기화 시도
            if not self.ekf_initialized:
                # 위치는 (0,0)으로 초기화
                self.X[0,0] = 0.0
                self.X[1,0] = 0.0
                # Heading 초기화: GPS heading이 있으면 사용
                if self.gps_heading_meas is not None:
                    self.X[2,0] = self.gps_heading_meas
                    rospy.loginfo("EKF heading initialized with GPS measurement.")
                else:
                    # GPS heading도 아직 없으면, IMU orientation에서 추출(참고)할 수도 있음
                    # 간단히 0으로 초기화
                    self.X[2,0] = 0.0
                self.ekf_initialized = True
            return

        dt = current_time - self.last_time
        self.last_time = current_time

        if not self.ekf_initialized:
            return

        # ------------------- EKF Prediction 단계 -------------------
        # 상태: X = [x, y, yaw]
        # 입력: 선속도 v = self.current_speed, yaw_rate = omega_z(IMU)
        v = self.current_speed
        omega_z = msg.angular_velocity.z

        # 1) 상태 예측
        #   x' = x + v*cos(yaw)*dt
        #   y' = y + v*sin(yaw)*dt
        #   yaw' = yaw + omega_z*dt
        yaw = self.X[2,0]
        predicted_x   = self.X[0,0] + v * math.cos(yaw) * dt
        predicted_y   = self.X[1,0] + v * math.sin(yaw) * dt
        predicted_yaw = self.normalize_angle(yaw + omega_z * dt)

        X_pred = np.array([[predicted_x],
                           [predicted_y],
                           [predicted_yaw]])

        # 2) 선형화 행렬 F (3x3)
        #    F = d(f)/dX
        #    f(X) = [ x + v*cos(yaw)*dt,
        #              y + v*sin(yaw)*dt,
        #              yaw + w*dt ]
        #    yaw = X[2]
        F = np.eye(3)
        F[0,2] = -v * math.sin(yaw) * dt
        F[1,2] =  v * math.cos(yaw) * dt

        # 3) 공분산 예측
        P_pred = F @ self.P @ F.T + self.Q

        # ------------------- EKF Update 단계 -------------------
        # (a) GPS Position Update
        if self.new_gps_position:
            # 측정: GPS로부터 (x_gps, y_gps)
            #   - x_gps = (easting - init_easting)
            #   - y_gps = (northing - init_northing)
            easting, northing, _, _ = utm.from_latlon(self.gps_fix_msg.latitude, self.gps_fix_msg.longitude)
            meas_x = easting - self.init_position_utm.x
            meas_y = northing - self.init_position_utm.y

            Z_pos = np.array([[meas_x],
                              [meas_y]])  # 2x1
            # H_pos: 상태 X = [x, y, yaw] => 측정 z = [x, y]
            #        z = H_pos * X => [ x, y ]
            H_pos = np.array([
                [1, 0, 0],
                [0, 1, 0]
            ])

            # 예측값
            Z_pos_pred = H_pos @ X_pred  # 2x1

            # 잔차(innovation)
            Y_pos = Z_pos - Z_pos_pred  # 2x1
            # 혁신 공분산
            S_pos = H_pos @ P_pred @ H_pos.T + self.R_pos  # 2x2
            # 칼만 이득
            K_pos = P_pred @ H_pos.T @ np.linalg.inv(S_pos)  # 3x2

            # 사후 상태
            X_upd = X_pred + K_pos @ Y_pos
            # 사후 공분산
            P_upd = (np.eye(3) - K_pos @ H_pos) @ P_pred

            X_pred = X_upd
            P_pred = P_upd

            # 위치 측정 사용 완료
            self.new_gps_position = False

        # (b) GPS Heading Update (속도 0.6 이상일 때만)
        if self.new_gps_heading and (self.gps_heading_meas is not None):
            # 측정: heading (동쪽 기준 라디안)
            Z_hdg = np.array([[self.gps_heading_meas]])  # 1x1
            # H_hdg: z = yaw => [0, 0, 1]
            H_hdg = np.array([[0, 0, 1]])

            Z_hdg_pred = H_hdg @ X_pred  # 1x1

            # heading은 원형특성이 있으므로 angle_diff를 사용해 잔차를 구하는 것이 바람직
            innov = self.angle_diff(Z_hdg[0,0], Z_hdg_pred[0,0])
            Y_hdg = np.array([[innov]])  # 1x1

            S_hdg = H_hdg @ P_pred @ H_hdg.T + self.R_heading  # (1x1)
            K_hdg = P_pred @ H_hdg.T @ np.linalg.inv(S_hdg)    # (3x1)

            X_upd = X_pred + K_hdg @ Y_hdg
            # yaw normalization
            X_upd[2,0] = self.normalize_angle(X_upd[2,0])

            P_upd = (np.eye(3) - K_hdg @ H_hdg) @ P_pred

            X_pred = X_upd
            P_pred = P_upd

            self.new_gps_heading = False

        # ------------------- EKF 결과 갱신 -------------------
        self.X = X_pred
        self.P = P_pred

        # ------------------- 최종 Odometry 메시지 발행 -------------------
        # 위치
        ekf_odom = Odometry()
        ekf_odom.header.stamp = msg.header.stamp
        ekf_odom.header.frame_id = "odom_utm" 
        ekf_odom.child_frame_id = "base_link"

        ekf_odom.pose.pose.position.x = self.X[0,0]
        ekf_odom.pose.pose.position.y = self.X[1,0]
        ekf_odom.pose.pose.position.z = 0.0

        # 쿼터니언 변환 (동쪽기준 yaw)
        yaw_ekf = self.X[2,0]
        q_ekf = quaternion_from_euler(0, 0, yaw_ekf)  # roll=0, pitch=0, yaw(동쪽 기준)
        ekf_odom.pose.pose.orientation = Quaternion(*q_ekf)

        # 속도 (twist)
        #  - EKF 상에서 x축을 "동쪽" 방향이라고 보면, EKF의 바디프레임 속도와는 다를 수 있으니
        #    여기서는 단순히 "전진속도"를 x에 담았다고 가정
        ekf_odom.twist.twist.linear.x = self.current_speed
        ekf_odom.twist.twist.angular.z = omega_z

        # 공분산도 적절히 할당(예시)
        # pose 공분산 6x6 중 x,y,yaw 부분만 대략 설정
        ekf_odom.pose.covariance[0] = self.P[0,0]  # x
        ekf_odom.pose.covariance[7] = self.P[1,1]  # y
        ekf_odom.pose.covariance[35] = self.P[2,2] # yaw

        # 퍼블리시
        self.odom_pub_ekf.publish(ekf_odom)

        # 현재 UTM 위치도 퍼블리시 (시각화/디버그용)
        current_utm_relative_position = Point()
        current_utm_relative_position.x = self.X[0,0]
        current_utm_relative_position.y = self.X[1,0]
        current_utm_relative_position.z = 0.0
        self.current_utm_position_pub.publish(current_utm_relative_position)

    # ------------------- 유틸 함수들 -------------------
    def normalize_angle(self, angle):
        """ -pi ~ pi 범위로 정규화 """
        return math.atan2(math.sin(angle), math.cos(angle))

    def angle_diff(self, a, b):
        """ 두 라디안 a, b의 차를 -pi ~ pi 범위로 계산 """
        diff = a - b
        return math.atan2(math.sin(diff), math.cos(diff))

    def north_degree_to_east_radians(self, degrees):
        """
        북쪽 기준(deg) → 동쪽 기준(radians) 변환  
        navpvt에서 나온 heading은 북쪽 기준 0도.  
        동쪽 기준으로 바꾸려면,  동쪽0도 = 북쪽90도 이므로
          θ_east = - (deg - 90) (도 단위)
        """
        east_based_degrees = degrees - 90.0
        return math.radians(-east_based_degrees)

if __name__ == '__main__':
    try:
        node = IMUGPSToOdometryEKF()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

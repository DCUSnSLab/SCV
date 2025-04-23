#!/usr/bin/env python3
"""multi_gps_imu_odometry.py ‑ 동기화 개선 버전

* /odom/gps          : F9K GPS 단독 위치 + heading + yaw_rate (5 Hz 예상)
* /odom/ekf_single   : F9K GPS + IMU EKF (Predict 100 Hz, Update 5 Hz)
* /odom/ekf_dual     : F9K (좌) + F9P (우) GPS + IMU EKF (Predict 100 Hz, Update 5 Hz)

설계 핵심
---------
1. **IMU** (100 Hz 가정): EKF.predict()에만 사용 → 고주파 유지
2. **GPS Fix + NavPVT** (≈5 Hz): message_filters.ApproximateTimeSynchronizer 로 동기화 시 EKF.update() 수행 → 완전 동기화
3. **Dual‑GPS**: 좌(F9K)·우(F9P) Fix 동기화하여 중점 위치 + baseline heading 산출 → EKF.update()

필요 토픽
---------
* /ublox_f9k/fix      (NavSatFix)
* /ublox_f9k/navpvt   (NavPVT)
* /ublox_f9p/fix      (NavSatFix)
* /vectornav/IMU      (Imu)
* /hunter_status      (HunterStatus) – 선속도 (m/s)

파라미터
---------
* ~baseline_offset_deg : 오른쪽 안테나가 +X(east) 축일 때 차량 전방까지의 보정 각도 (기본 90°)
* ~sync_slop           : ApproximateTimeSynchronizer 허용 시간차 (기본 0.05 s)
"""

import rospy
import math
import utm
import numpy as np
import message_filters
from sensor_msgs.msg import Imu, NavSatFix
from ublox_msgs.msg import NavPVT
from hunter_msgs.msg import HunterStatus
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion
from tf.transformations import quaternion_from_euler

# -----------------------------------------------------------------------------
#                               Helper functions
# -----------------------------------------------------------------------------

def normalize_angle(a):
    """wrap radian angle to (-pi, pi]"""
    return math.atan2(math.sin(a), math.cos(a))

def angle_diff(a, b):
    return normalize_angle(a - b)

def north_deg_to_east_rad(deg):
    east = deg - 90.0
    return math.radians(-east)

def utm_relative(msg, e0, n0):
    e, n, _, _ = utm.from_latlon(msg.latitude, msg.longitude)
    return e - e0, n - n0

# -----------------------------------------------------------------------------
#                                     EKF 2‑D
# -----------------------------------------------------------------------------
class EKF2D:
    """State: [x, y, yaw] (ENU)"""
    def __init__(self, q_xyz=(0.05, 0.05, 0.001), r_pos=(0.1, 0.1), r_yaw=0.01):
        self.X = np.zeros((3, 1))
        self.P = np.eye(3) * 1.0
        self.Q = np.diag(q_xyz)
        self.Rp = np.diag(r_pos)
        self.Rh = np.array([[r_yaw]])

    def predict(self, v, omega, dt):
        x, y, yaw = self.X.flatten()
        x_ = x + v * math.cos(yaw) * dt
        y_ = y + v * math.sin(yaw) * dt
        yaw_ = normalize_angle(yaw + omega * dt)
        self.X = np.array([[x_], [y_], [yaw_]])
        F = np.eye(3)
        F[0, 2] = -v * math.sin(yaw) * dt
        F[1, 2] =  v * math.cos(yaw) * dt
        self.P = F @ self.P @ F.T + self.Q

    def update_pos(self, x_meas, y_meas):
        Z = np.array([[x_meas], [y_meas]])
        H = np.array([[1, 0, 0], [0, 1, 0]])
        Y = Z - H @ self.X
        S = H @ self.P @ H.T + self.Rp
        K = self.P @ H.T @ np.linalg.inv(S)
        self.X += K @ Y
        self.P = (np.eye(3) - K @ H) @ self.P

    def update_yaw(self, yaw_meas):
        H = np.array([[0, 0, 1]])
        innov = angle_diff(yaw_meas, (H @ self.X)[0, 0])
        Y = np.array([[innov]])
        S = H @ self.P @ H.T + self.Rh
        K = self.P @ H.T @ np.linalg.inv(S)
        self.X += K @ Y
        self.X[2, 0] = normalize_angle(self.X[2, 0])
        self.P = (np.eye(3) - K @ H) @ self.P

# -----------------------------------------------------------------------------
#                                  Main Node
# -----------------------------------------------------------------------------
class MultiOdomNode:
    def __init__(self):
        rospy.init_node('multi_gps_imu_odometry')

        # Params
        self.baseline_offset_deg = rospy.get_param('~baseline_offset_deg', 90.0)
        self.sync_slop           = rospy.get_param('~sync_slop', 0.05)

        # Publishers
        self.pub_gps   = rospy.Publisher('/odom/gps',        Odometry, queue_size=20)
        self.pub_e1    = rospy.Publisher('/odom/ekf_single', Odometry, queue_size=20)
        self.pub_e2    = rospy.Publisher('/odom/ekf_dual',   Odometry, queue_size=20)

        # State
        self.origin_set = False
        self.e0 = self.n0 = 0.0
        self.speed = 0.0
        self.last_imu_time = None
        # heading & yaw_rate 저장
        self.latest_nav_heading = 0.0    # degrees
        self.latest_imu_yaw_rate = 0.0   # rad/s

        # EKF
        self.ekf_single = EKF2D()
        self.ekf_dual   = EKF2D()

        # Subscribers & Sync
        rospy.Subscriber('/vectornav/IMU', Imu, self.cb_imu)
        rospy.Subscriber('/hunter_status', HunterStatus, self.cb_speed)

        fix_single_sub = message_filters.Subscriber('/ublox_f9k/fix', NavSatFix)
        navpvt_sub     = message_filters.Subscriber('/ublox_f9k/navpvt', NavPVT)
        self.sync_single = message_filters.ApproximateTimeSynchronizer(
            [fix_single_sub, navpvt_sub], 20, self.sync_slop, allow_headerless=True)
        self.sync_single.registerCallback(self.cb_single_sync)

        fix_left_sub  = message_filters.Subscriber('/ublox_f9k/fix', NavSatFix)
        fix_right_sub = message_filters.Subscriber('/ublox_f9p/fix', NavSatFix)
        self.sync_dual = message_filters.ApproximateTimeSynchronizer(
            [fix_left_sub, fix_right_sub], 20, self.sync_slop, allow_headerless=True)
        self.sync_dual.registerCallback(self.cb_dual_sync)

        rospy.loginfo('multi_gps_imu_odometry node ready')

    def cb_speed(self, msg):
        self.speed = msg.linear_velocity

    def cb_imu(self, msg):
        if not self.origin_set:
            return
        now = msg.header.stamp.to_sec()
        if self.last_imu_time is None:
            self.last_imu_time = now
        dt = now - self.last_imu_time
        self.last_imu_time = now

        # yaw rate 저장
        self.latest_imu_yaw_rate = msg.angular_velocity.z

        self.ekf_single.predict(self.speed, self.latest_imu_yaw_rate, dt)
        self.ekf_dual.predict(  self.speed, self.latest_imu_yaw_rate, dt)
        self.publish_ekf(msg.header.stamp)

    def cb_single_sync(self, fix_msg, navpvt_msg):
        if not self.origin_set:
            self.e0, self.n0, _, _ = utm.from_latlon(
                fix_msg.latitude, fix_msg.longitude)
            self.origin_set = True
            rospy.loginfo("UTM origin fixed: %.3f, %.3f", self.e0, self.n0)

        x, y = utm_relative(fix_msg, self.e0, self.n0)
        self.ekf_single.update_pos(x, y)

        # heading 저장
        self.latest_nav_heading = navpvt_msg.heading / 1e5  # degrees
        if self.speed >= 0.6:
            yaw_rad = north_deg_to_east_rad(self.latest_nav_heading)
            self.ekf_single.update_yaw(yaw_rad)

        # GPS-only odometry에 heading, yaw_rate 포함
        yaw_rad = north_deg_to_east_rad(self.latest_nav_heading)
        odom_gps = self.build_odom(
            fix_msg.header.stamp, x, y,
            yaw_rad, self.latest_imu_yaw_rate)
        self.pub_gps.publish(odom_gps)

    def cb_dual_sync(self, left_fix, right_fix):
        if not self.origin_set:
            self.e0, self.n0, _, _ = utm.from_latlon(
                left_fix.latitude, left_fix.longitude)
            self.origin_set = True
            rospy.loginfo("UTM origin fixed (dual): %.3f, %.3f", self.e0, self.n0)

        xl, yl = utm_relative(left_fix,  self.e0, self.n0)
        xr, yr = utm_relative(right_fix, self.e0, self.n0)
        xm, ym = (xl + xr)/2.0, (yl + yr)/2.0
        self.ekf_dual.update_pos(xm, ym)

        de, dn = xr - xl, yr - yl
        baseline_yaw = math.atan2(dn, de)
        vehicle_yaw  = normalize_angle(
            baseline_yaw + math.radians(self.baseline_offset_deg))
        self.ekf_dual.update_yaw(vehicle_yaw)

    def build_odom(self, stamp, x, y, yaw, yaw_rate=0.0):
        o = Odometry()
        o.header.stamp    = stamp
        o.header.frame_id = "odom_utm"
        o.child_frame_id  = "base_link"
        o.pose.pose.position.x = x
        o.pose.pose.position.y = y
        q = quaternion_from_euler(0, 0, yaw)
        o.pose.pose.orientation = Quaternion(*q)
        o.twist.twist.angular.z = yaw_rate
        return o

    def publish_ekf(self, stamp):
        xs = self.ekf_single.X.flatten()
        od1 = self.build_odom(stamp, xs[0], xs[1], xs[2])
        od1.pose.covariance[0]  = self.ekf_single.P[0,0]
        od1.pose.covariance[7]  = self.ekf_single.P[1,1]
        od1.pose.covariance[35] = self.ekf_single.P[2,2]
        od1.twist.twist.linear.x  = self.speed
        self.pub_e1.publish(od1)

        xd = self.ekf_dual.X.flatten()
        od2 = self.build_odom(stamp, xd[0], xd[1], xd[2])
        od2.pose.covariance[0]  = self.ekf_dual.P[0,0]
        od2.pose.covariance[7]  = self.ekf_dual.P[1,1]
        od2.pose.covariance[35] = self.ekf_dual.P[2,2]
        od2.twist.twist.linear.x  = self.speed
        self.pub_e2.publish(od2)

if __name__ == '__main__':
    try:
        MultiOdomNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

#!/usr/bin/env python3
"""Multi‑Odometry publisher node

Generates three odometry streams from the same sensor set –­­
  1. /odom/gps               : single‑antenna (F9K) GPS‑only odometry
  2. /odom/ekf_single        : single‑antenna (F9K) + IMU EKF odometry
  3. /odom/ekf_dual          : dual‑antenna (F9K left + F9P right) + IMU EKF odometry

Assumptions
-----------
* Two u‑blox receivers are mounted laterally:
    – left   : F9K   topic /ublox_f9k/fix (+ /ublox_f9k/navpvt)
    – right  : F9P   topic /ublox_f9p/fix
* Vehicle forward axis is +90° CCW from the left‑>right baseline vector.
  (If your baseline is aligned differently, change parameter
   `~baseline_offset_deg` in the launch file.)
* UTM/ENU coordinates are used everywhere.
* Linear speed (m/s) is provided by /hunter_status (HunterStatus message).
* IMU orientation & angular velocity is provided by /vectornav/IMU.

Author : ChatGPT‑o3 – 2025‑04‑22
"""

import rospy, math, utm, numpy as np, message_filters, time
from sensor_msgs.msg import Imu, NavSatFix
from ublox_msgs.msg     import NavPVT
from hunter_msgs.msg    import HunterStatus
from nav_msgs.msg       import Odometry
from geometry_msgs.msg  import Quaternion, Point
from tf.transformations import quaternion_from_euler

# ------------------------------------------------------------
#                      Small utility helpers
# ------------------------------------------------------------

def normalize_angle(a):
    """wrap radian angle to (‑pi, pi]"""
    return math.atan2(math.sin(a), math.cos(a))

def angle_diff(a,b):
    """shortest difference a‑b in (‑pi,pi]"""
    return normalize_angle(a-b)

def north_deg_to_east_rad(deg):
    """convert u‑blox heading (0°=North, CW positive) -> east‑based CCW rad"""
    east_deg = deg - 90.0
    return math.radians(-east_deg)

def latlon_to_utm_xy(msg, origin_easting, origin_northing):
    e,n,_,_ = utm.from_latlon(msg.latitude, msg.longitude)
    return e-origin_easting, n-origin_northing


# ------------------------------------------------------------
#                        Simple 2‑D EKF
# ------------------------------------------------------------
class EKF2D:
    """ State: x, y, yaw  (east‑north‑up ENU) """
    def __init__(self, q_xyz=(0.05,0.05,0.001),
                       r_pos=(0.1,0.1), r_yaw=0.01):
        self.X = np.zeros((3,1))
        self.P = np.eye(3)*1.0
        self.Q = np.diag(q_xyz)
        self.R_pos = np.diag(r_pos)
        self.R_yaw = np.array([[r_yaw]])
        self.initialized=False

    # ---------------- prediction -----------------
    def predict(self, v, omega_z, dt):
        x,y,yaw = self.X.flatten()
        x_ = x + v*math.cos(yaw)*dt
        y_ = y + v*math.sin(yaw)*dt
        yaw_ = normalize_angle(yaw + omega_z*dt)
        X_pred = np.array([[x_],[y_],[yaw_]])
        F = np.eye(3)
        F[0,2] = -v*math.sin(yaw)*dt
        F[1,2] =  v*math.cos(yaw)*dt
        P_pred = F@self.P@F.T + self.Q
        self.X, self.P = X_pred, P_pred

    # ---------------- gps position update --------
    def update_position(self, meas_x, meas_y):
        Z = np.array([[meas_x],[meas_y]])
        H = np.array([[1,0,0],[0,1,0]])
        Y = Z - H@self.X
        S = H@self.P@H.T + self.R_pos
        K = self.P@H.T@np.linalg.inv(S)
        self.X += K@Y
        self.P = (np.eye(3)-K@H)@self.P

    # ---------------- heading update -------------
    def update_heading(self, yaw_meas):
        Z = np.array([[yaw_meas]])
        H = np.array([[0,0,1]])
        innov = angle_diff(Z[0,0], H@self.X[2,0])
        Y = np.array([[innov]])
        S = H@self.P@H.T + self.R_yaw
        K = self.P@H.T@np.linalg.inv(S)
        self.X += K@Y
        self.X[2,0] = normalize_angle(self.X[2,0])
        self.P = (np.eye(3)-K@H)@self.P



# ------------------------------------------------------------
#                  Main combined odometry node
# ------------------------------------------------------------
class MultiOdometryNode:
    def __init__(self):
        rospy.init_node('multi_odometry_node')

        # ---- parameters ----
        self.baseline_offset_deg = rospy.get_param('~baseline_offset_deg', 90.0)
        self.sync_slop           = rospy.get_param('~sync_slop', 0.1)

        # ---- publishers ----
        self.odom_gps_pub        = rospy.Publisher('/odom/gps', Odometry, queue_size=20)
        self.odom_ekf_pub        = rospy.Publisher('/odom/ekf_single', Odometry, queue_size=20)
        self.odom_dual_pub       = rospy.Publisher('/odom/ekf_dual',  Odometry, queue_size=20)

        # ---- state ----
        self.origin_set = False
        self.origin_easting = 0.0
        self.origin_northing= 0.0

        # speed
        self.current_speed = 0.0

        # EKF instances
        self.ekf_single = EKF2D()
        self.ekf_dual   = EKF2D()

        self.last_imu_time = None

        # ---- subscribers & synchronizers ----
        self.fix_left_sub  = message_filters.Subscriber('/ublox_f9k/fix', NavSatFix)
        self.fix_right_sub = message_filters.Subscriber('/ublox_f9p/fix', NavSatFix)
        self.sync_fix      = message_filters.ApproximateTimeSynchronizer(
                                [self.fix_left_sub, self.fix_right_sub],
                                queue_size=20, slop=self.sync_slop)
        self.sync_fix.registerCallback(self.dual_fix_callback)

        # single antenna gps & navpvt
        self.single_fix_sub = rospy.Subscriber('/ublox_f9k/fix',
                                               NavSatFix, self.single_fix_callback)
        self.navpvt_sub     = rospy.Subscriber('/ublox_f9k/navpvt',
                                               NavPVT, self.navpvt_callback)

        # dynamic inputs
        self.imu_sub        = rospy.Subscriber('/vectornav/IMU',
                                               Imu, self.imu_callback)
        self.speed_sub      = rospy.Subscriber('/hunter_status',
                                               HunterStatus, self.speed_callback)

        rospy.loginfo('multi_odometry_node initialised')

    # --------------------------------------------------------
    #                   basic callbacks
    # --------------------------------------------------------
    def speed_callback(self, msg):
        self.current_speed = msg.linear_velocity

    def navpvt_callback(self, msg):
        # heading in 1e-5 deg north-based
        hdg_deg = msg.heading/1e5
        hdg_rad = north_deg_to_east_rad(hdg_deg)
        if self.current_speed >= 0.6:
            self.ekf_single.update_heading(hdg_rad)

    # ---- Single antenna position update ----
    def single_fix_callback(self, msg):
        if not self.origin_set:
            self.origin_easting, self.origin_northing,_,_ = utm.from_latlon(msg.latitude,msg.longitude)
            self.origin_set = True
            rospy.loginfo('Origin fixed (UTM): %.3f, %.3f', self.origin_easting, self.origin_northing)

        x,y = latlon_to_utm_xy(msg, self.origin_easting, self.origin_northing)

        # Publish GPS‑only odom
        odom_msg = self._build_odom(msg.header.stamp, x, y, 0.0,
                                    frame_id='odom_utm', child='base_link')
        self.odom_gps_pub.publish(odom_msg)

        # EKF position update
        self.ekf_single.update_position(x,y)

    # ---- Dual fix synchronized ----
    def dual_fix_callback(self, left_fix, right_fix):
        if not self.origin_set:
            self.origin_easting, self.origin_northing,_,_ = utm.from_latlon(left_fix.latitude,left_fix.longitude)
            self.origin_set = True
            rospy.loginfo('Origin fixed (UTM) via dual: %.3f, %.3f', self.origin_easting, self.origin_northing)

        # positions
        xl,yl = latlon_to_utm_xy(left_fix,  self.origin_easting, self.origin_northing)
        xr,yr = latlon_to_utm_xy(right_fix, self.origin_easting, self.origin_northing)

        # Midpoint as vehicle position
        xm,ym = (xl+xr)/2.0, (yl+yr)/2.0
        self.ekf_dual.update_position(xm,ym)

        # Baseline vector & yaw
        delta_e = xr - xl
        delta_n = yr - yl
        baseline_yaw = math.atan2(delta_n, delta_e)  # east‑based rad (right from left)
        vehicle_yaw  = normalize_angle(baseline_yaw + math.radians(self.baseline_offset_deg))
        self.ekf_dual.update_heading(vehicle_yaw)

    # ---- IMU prediction common for both EKFs ----
    def imu_callback(self, msg):
        if not self.origin_set: return

        now = msg.header.stamp.to_sec()
        if self.last_imu_time is None:
            self.last_imu_time = now
            # initialise yaw of EKFs with navpvt or baseline if available
            return
        dt = now - self.last_imu_time
        self.last_imu_time = now

        omega_z = msg.angular_velocity.z

        # predict both filters
        self.ekf_single.predict(self.current_speed, omega_z, dt)
        self.ekf_dual.predict(  self.current_speed, omega_z, dt)

        # publish outputs
        self.publish_ekf

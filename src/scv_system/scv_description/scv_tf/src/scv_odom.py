#!/usr/bin/env python3
import rospy
import tf
from sensor_msgs.msg import NavSatFix, Imu
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Twist
import numpy as np
from hunter_msgs.msg import HunterStatus 

class OdometryNode:
    def __init__(self):
        rospy.init_node('odometry_node')
        
        # TF 브로드캐스터 초기화
        self.tf_broadcaster = tf.TransformBroadcaster()

        self.odom_pub = rospy.Publisher('/odom', Odometry, queue_size=10)

        rospy.Subscriber('/ublox_gps/fix', NavSatFix, self.gps_callback)
        rospy.Subscriber('/imu/imu', Imu, self.imu_callback)
        rospy.Subscriber('/hunter_status', HunterStatus, self.wheel_encoder_callback)

        self.odom = Odometry()
        self.prev_time = rospy.Time.now()

        # 상태 변수 (x, y, vx, vy)
        self.state = np.zeros(4)  # [x, y, vx, vy]
        self.prev_time = rospy.Time.now()

        # 칼만 필터 초기화
        self.P = np.eye(4)  # 상태 공분산 행렬
        self.Q = np.eye(4) * 0.1  # 프로세스 노이즈 공분산
        self.R = np.eye(2) * 0.5  # 측정 노이즈 공분산

        self.imu_orientation = Quaternion()

    def gps_callback(self, data):
        # GPS 데이터를 이용하여 위치 정보 업데이트
        gps_measurement = np.array([data.latitude, data.longitude])
        self.update(gps_measurement)

    def imu_callback(self, data):
        # IMU 데이터를 이용하여 자세 및 각속도 정보 업데이트
        self.imu_orientation = data.orientation
        euler = tf.transformations.euler_from_quaternion([data.orientation.x, data.orientation.y, data.orientation.z, data.orientation.w])
        yaw = euler[2]  # yaw 값 추출

    def wheel_encoder_callback(self, data):
        current_time = rospy.Time.now()
        dt = (current_time - self.prev_time).to_sec()
        self.prev_time = current_time

        # Wheel encoder 데이터를 이용하여 속도 정보 업데이트
        self.state[2] = data.linear_velocity  # vx
        self.state[3] = data.steering_angle   # vy
        # 상태 예측
        self.predict(dt)

        # 오도메트리 퍼블리시
        self.publish_odometry(current_time)

        # TF 브로드캐스트
        self.broadcast_transform(current_time)

    def predict(self, dt):
        # 상태 예측
        self.state[0] += self.state[2] * dt  # x 업데이트
        self.state[1] += self.state[3] * dt  # y 업데이트

        # 공분산 행렬 업데이트
        self.P = self.P + self.Q

    def update(self, measurement):
        # 칼만 필터 업데이트
        H = np.array([[1, 0, 0, 0], [0, 1, 0, 0]])  # 측정 행렬
        z = measurement.reshape(-1, 1)  # 측정값

        # 예측 단계
        y = z - H @ self.state.reshape(-1, 1)  # 잔차
        S = H @ self.P @ H.T + self.R  # 공분산
        K = self.P @ H.T @ np.linalg.inv(S)  # 칼만 이득

        # 상태 업데이트
        self.state = self.state + (K @ y).flatten()
        
        # 공분산 업데이트
        I = np.eye(4)
        self.P = (I - K @ H) @ self.P

    def publish_odometry(self, current_time):
        self.odom.header.stamp = current_time
        self.odom.header.frame_id = "odom"
        
        self.odom.pose.pose.position.x = self.state[0]
        self.odom.pose.pose.position.y = self.state[1]
        self.odom.pose.pose.position.z = 0.0
        self.odom.pose.pose.orientation = self.imu_orientation
        
        self.odom.child_frame_id = "base_link"
        self.odom.twist.twist.linear.x = self.state[2]
        self.odom.twist.twist.linear.y = self.state[3]
        self.odom.twist.twist.angular.z = 0.0  # 각속도는 별도로 처리
        
        self.odom_pub.publish(self.odom)

    def broadcast_transform(self, current_time):
        # TF 브로드캐스트
        yaw = tf.transformations.euler_from_quaternion([self.imu_orientation.x, self.imu_orientation.y, self.imu_orientation.z, self.imu_orientation.w])[2]
        self.tf_broadcaster.sendTransform(
            (self.state[0], self.state[1], 0),  # 위치 (x, y, z)
            tf.transformations.quaternion_from_euler(0, 0, yaw),  # 쿼터니언 (roll, pitch, yaw)
            current_time,
            "base_link",  # 자식 프레임
            "odom"  # 부모 프레임
        )

if __name__ == '__main__':
    try:
        odom_node = OdometryNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

#!/usr/bin/env python3
import rospy
import math
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion

def imu_callback(msg):
    # IMU 메시지에서 orientation (quaternion) 추출
    q = msg.orientation
    quaternion = [q.x, q.y, q.z, q.w]
    
    # quaternion을 오일러 각(roll, pitch, yaw)로 변환
    roll, pitch, yaw = euler_from_quaternion(quaternion)
    
    # 기본적으로 tf의 euler_from_quaternion은 yaw를 counterclockwise (반시계 방향)로 증가하는 값으로 반환합니다.
    # ROS에서는 일반적으로 로봇의 x축이 북쪽을 가리키고 있다고 가정하면,
    # yaw = 0 이면 북쪽, 양의 yaw (반시계)는 서쪽, 음의 yaw (시계)는 동쪽이 됩니다.
    #
    # 우리가 원하는 것은 북쪽을 0도로 하고, 시계방향(즉, 음의 yaw)을 양의 각도로 표현하는 것입니다.
    # 따라서 다음과 같이 변환합니다:
    heading_deg = (360 - math.degrees(yaw)) % 360

    rospy.loginfo("Heading: {:.2f} deg".format(heading_deg))

def main():
    rospy.init_node("imu_heading_node", anonymous=True)
    rospy.Subscriber("/vectornav/IMU", Imu, imu_callback)
    rospy.spin()

if __name__ == '__main__':
    main()

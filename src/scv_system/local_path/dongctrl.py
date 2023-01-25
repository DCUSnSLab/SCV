import time
from threading import Thread
from test_package.hello import Hello
from moraictrl import moraiCtrl
import rospy
import ros_numpy
from morai_msgs.msg import CtrlCmd
import numpy as np
#from ackermann_msgs.msg import AckermannDriveStamped
from sensor_msgs.msg import LaserScan , PointCloud2, PointField
from sensor_msgs import point_cloud2
from std_msgs.msg import Float64 , Header
#from hunterctrl import hunterCtrl
import math


class Car_Follower():
    def __init__(self):
        self.sub3D = rospy.Subscriber("/lidar3D", PointCloud2, self.callback3D)
        self.lidar_pub3D = rospy.Publisher("/refined_lidar3D", PointCloud2, queue_size=10)  # velodyne
        self.send = rospy.Publisher("/lp_ctrl", CtrlCmd, queue_size=1)

    def callback3D(self, msg):
        scan = PointCloud2()
        scan.header = msg.header
        scan.height = msg.height
        scan.width = msg.width
        scan.fields = msg.fields
        scan.is_bigendian = msg.is_bigendian
        scan.point_step = msg.point_step
        scan.row_step = msg.row_step
        scan.data = msg.data
        scan.is_dense = msg.is_dense

        pc = ros_numpy.numpify(scan)
        points = np.zeros((pc.shape[0], 3))

        points[:, 0] = pc['x']
        points[:, 1] = pc['y']
        points[:, 2] = pc['z']

        roi = {"x": [-5,5], "y": [-5, 5], "z": [-0.69, 20]}  # z값 수정, X 값 수정으로 전,후방 범위 조절

        x_range = np.logical_and(points[:, 0] >= roi["x"][0], points[:, 0] <= roi["x"][1])
        y_range = np.logical_and(points[:, 1] >= roi["y"][0], points[:, 1] <= roi["y"][1])
        z_range = np.logical_and(points[:, 2] >= roi["z"][0], points[:, 2] <= roi["z"][1])

        pass_through_filter = np.where(np.logical_and(x_range, np.logical_and(y_range, z_range)) == True)[0]
        points = points[pass_through_filter, :]
        # points[:, 0] = x축 값 , points[:, 1] = y축 값 , points[:, 2] = z축 값

        #z축 값 추출 1차원 배열로 재배열
        # Zaxis=points[:,2].reshape(-1)

        '''
        x,y 축 만 추출 후 0값을 inf로 바꾸는 코드 (23.01.08) 추후 의미없으면 삭제 예정 
        xyaxis = np.delete(points, 2, axis=1)
        print("자료형 : ", type(xyaxis))
        print("개수 \n",xyaxis)
        # 0값을 inf처리
        refined_xyaxis = np.where(xyaxis == 0, float("inf"), xyaxis)
        print("정제 자료형 : ", type(refined_xyaxis))
        print("정제 개수 \n", refined_xyaxis)
        '''

        '''re_xaxis, re_yaxis = 0 값 제외한 좌표 측 실제로 물체가 인식되는 라이다 값만 존재하는 1차원 np.array (기울기를 구하기 위해서)'''
        xaxis = np.delete(points, [1, 2], axis=1)
        yaxis = np.delete(points, [0, 2], axis=1)
        re_xaxis= np.delete(xaxis,np.where(xaxis==0))
        re_yaxis = np.delete(yaxis, np.where(yaxis == 0))
        # print("정제된 x값\n", re_xaxis)
        # print("정제된 y값", re_yaxis)
        # print("x 크기",re_xaxis.size)
        # print("y 크기", re_yaxis.size)
        '''xy는 각 인덱스 별 (0,0)과 인덱스의 x,y좌표 기울기 계산 결과 저장
        xypoint는 각 인덱스 별 원점(0,0)과 x,y좌표 사이의 거리'''
        xy=[]
        xypoint=[]

        for i in range(re_xaxis.size and re_yaxis.size):
            xy.append(re_yaxis[i]/re_xaxis[i])
            xypoint.append(math.sqrt((re_xaxis[i]**2)+(re_yaxis[i]**2)))
        if min(xypoint) < 1.5:
            pass

        # print("최소 기울기 ", min(xy))
        # print("최대 기울기 ", max(xy))
        # print("최소 거리 ", min(xypoint))
        # print("최대 거리 ", max(xypoint))

        steering = 0
        # print(steering, center_dist, left_curv, right_curv)


        send = CtrlCmd()
        send.velocity = 0
        send.steering = steering

        header = Header()
        header.frame_id = "velodyne"
        scan = point_cloud2.create_cloud_xyz32(header, points)
        scan.header.stamp = rospy.Time.now()
        self.lidar_pub3D.publish(scan)
        self.send.publish(send)


if __name__ == '__main__':
    mct = moraiCtrl()
    Car_Follower()
    #mct = hunterCtrl()
    mct.runCtrl()

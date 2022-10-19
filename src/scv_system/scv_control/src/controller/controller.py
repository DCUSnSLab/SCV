import sys
from math import pi

import rospy
from morai_msgs.msg import CtrlCmd, EgoVehicleStatus
from utils import pidController

class moraiCtrl:
    def __init__(self):
        rospy.init_node('morai_ctrl', anonymous=True)
        #vehicle status
        self.velocity = 0
        self.acceleration = 0

        #long/lat control
        self.targetVel = 0
        self.targetAcc = 0

        #kph/mps rate
        self.mpsrate = 3.6

        # time rate
        self.rate = rospy.Rate(30)  # 30hz

        self.__initCtrl()
        self.emergencyBrake(True)

    def __initCtrl(self):
        #morai ERP42 info
        #max accel = 1.4m/s
        #max velocity = 6.38m/s(23km/h)
        # publisher
        self.ctrl_pub = rospy.Publisher('/ctrl_cmd', CtrlCmd, queue_size=1)

        #subscribe
        rospy.Subscriber("/Ego_topic", EgoVehicleStatus, self.EgoStatusUpdate)

        self.ctrl_msg = CtrlCmd()
        self.status_msg = EgoVehicleStatus()
        self.isStatus = False
        self.pid = pidController(p=9, i=0.1, d=2.0, rate=30)

    def runCtrl(self):
        while not rospy.is_shutdown():
            # if self.isStatus is True:
            #     print('speed: {}, acc: {}, brake: {}'.format(self.velocity*3.6, self.acceleration, self.status_msg.brake))
            # self.ctrl_msg.steering = -30 / 180 * pi
            ctl_accel = self.pid.pid_1(self.targetVel, self.status_msg.velocity)
            self.ctrl_msg.velocity = self.targetVel

            if abs(self.targetVel - self.status_msg.velocity.x) < 0.2 or ctl_accel > 0:
                self.ctrl_msg.accel = ctl_accel
                self.ctrl_msg.brake = 0
            else:
                self.ctrl_msg.accel = 0
                self.ctrl_msg.brake = -ctl_accel

            #print(self.status_msg.velocity.x)
            if self.status_msg.velocity.x < 1.0 and self.targetVel <= 0.0:
                self.ctrl_msg.accel = 0
                self.ctrl_msg.brake = 1
            self.ctrl_pub.publish(self.ctrl_msg)
            #print('target vel {}, acc {}'.format(self.ctrl_msg.velocity, self.ctrl_msg.accel))
            self.rate.sleep()

    def EgoStatusUpdate(self, msg):
        self.status_msg = msg
        self.isStatus = True
        self.velocity = 0 if abs(self.status_msg.velocity.x) < 0.0001 else self.status_msg.velocity.x
        self.acceleration = 0 if abs(self.status_msg.acceleration.x) < 0.0001 else self.status_msg.acceleration.x

    def setRate(self, r: int):
        self.rate = rospy.Rate(r)

    def setTargetSpeed(self, speed:float=0, acc:float=0):
        self.targetVel = speed / self.mpsrate
        self.targetAcc = acc

    def emergencyBrake(self, isBrake):
        if isBrake is True:
            self.ctrl_msg.brake = 1.0
            self.ctrl_msg.accel = 0
        else:
            self.ctrl_msg.brake = 0.0

    def setBrake(self, mps: float):
        self.ctrl_msg.brake = mps

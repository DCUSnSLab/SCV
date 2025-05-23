from math import pi

import rospy
from cv_bridge import CvBridgeError
from morai_msgs.msg import CtrlCmd, EgoVehicleStatus
from sensor_msgs.msg import CompressedImage

import scv_control_controller
from controller import Controller, MsgModule
from utils import pidController


class moraiCtrl(Controller):
    def __init__(self):
        super().__init__('moraiCtrl', MsgModule(CtrlCmd, CtrlCmd(), '/ctrl_cmd'), MsgModule(EgoVehicleStatus, EgoVehicleStatus(), '/Ego'))

        # morai ERP42 info
        # max accel = 1.4m/s
        # max velocity = 6.38m/s(23km/h)

        # subscribe
        #rospy.Subscriber("/Ego_topic", EgoVehicleStatus, self.EgoStatusUpdate)
        self.pid = pidController(p=9, i=0.1, d=2.0, rate=30)

    def _acceptLongCtrl(self, ctrl_msg):
        ctl_accel = self.pid.pid_1(self.targetVel, self.status_msg.velocity)
        ctrl_msg.velocity = self.targetVel

        if abs(self.targetVel - self.status_msg.velocity.x) < 0.3 or ctl_accel > 0:
            ctrl_msg.accel = ctl_accel
            ctrl_msg.brake = 0
        else:
            ctrl_msg.accel = 0
            ctrl_msg.brake = -ctl_accel

        #print(self.status_msg.velocity.x)
        if self.status_msg.velocity.x < 1.0 and self.targetVel <= 0.0:
            ctrl_msg.accel = 0
            ctrl_msg.brake = 1
        #print('target vel {}, acc {}'.format(self.ctrl_msg.velocity, self.ctrl_msg.accel))
        return ctrl_msg

    def _acceptLatCtrl(self, ctrl_msg):
        ctrl_msg.steering = -self.targetAngle / 180 * pi
        return ctrl_msg

    def emergencyBrake(self, isBrake):
        if isBrake is True:
            self.ctrl_msg.brake = 1.0
            self.ctrl_msg.accel = 0
        else:
            self.ctrl_msg.brake = 0.0

    def _getEgoVelocity(self, msg):
        return 0 if abs(self.status_msg.velocity.x) < 0.0001 else self.status_msg.velocity.x

    def _getEgoAcceleration(self, msg):
        return 0 if abs(self.status_msg.acceleration.x) < 0.0001 else self.status_msg.acceleration.x

    def setBrake(self, mps: float):
        self.ctrl_msg.brake = mps

    def setCmd(self, CmdType: int):
        self.ctrl_msg.longlCmdType = CmdType

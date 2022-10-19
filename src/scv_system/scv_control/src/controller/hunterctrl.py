from math import pi

from geometry_msgs.msg import Twist
from hunter_msgs.msg import HunterStatus

from controller import Controller, MsgModule


class hunterCtrl(Controller):
    def __init__(self):
        super().__init__('hunterCtrl', MsgModule(Twist, Twist(), '/cmd_vel'), MsgModule(HunterStatus, HunterStatus(), '/hunter_status'))

    def _acceptLongCtrl(self, ctrl_msg:Twist):
        ctrl_msg.linear.x = self.targetVel
        return ctrl_msg

    def _acceptLatCtrl(self, ctrl_msg:Twist):
        ctrl_msg.angular.z = self.targetAngle / 180 * pi
        return ctrl_msg

    def _getEgoVelocity(self, msg:HunterStatus):
        return msg.linear_velocity

    def _getEgoAcceleration(self, msg:HunterStatus):
        return msg.steering_angle

    def emergencyBrake(self, isBrake):
        print('emergency brake')
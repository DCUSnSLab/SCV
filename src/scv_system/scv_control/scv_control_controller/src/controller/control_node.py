import rospy

import time
from threading import Thread

from visualization_msgs.msg import Marker, MarkerArray
from nav_msgs.msg import Odometry
import scv_control_controller
from moraictrl import moraiCtrl
from hunterctrl import hunterCtrl
from std_msgs.msg import Float64, Header

import scv_control_msgs
from scv_control_msgs.msg import SCVControl

class Controller:
    def __init__(self):
        print("Controller __init__ called.")

        self.path_sub = rospy.Subscriber("/scv_control", SCVControl, self.callback)

        self.mc = moraiCtrl()
        self.hc = hunterCtrl()

    def callback(self, msg):
        '''
        SCV_control Msg

        int8    command
        float64 steering
        float64 speed

        etc..
        '''
        command = msg.command

        if command == -1:
            flag = False
        elif command == 0:
            self.hc.emergencyBrake(True)
            self.hc.setTargetSpeed(0)
        elif command == 1:
            self.hc.emergencyBrake(False)
            self.hc.setTargetSpeed(msg.speed)
        elif command == 2:
            self.hc.setSteeringAngle(msg.steering)


if __name__=="__main__":
        rospy.init_node("SCV_Controller")
        try:
            Controller()
            rospy.spin()
        except:
            pass

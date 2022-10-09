import sys
from math import pi

import rospy
from morai_msgs.msg import CtrlCmd

class moraiCtrl:
    def __init__(self):
        rospy.init_node('morai_ctrl', anonymous=True)

        #arg = rospy.myargv(argv=sys.argv)

        #publisher
        self.ctrl_pub = rospy.Publisher('/ctrl_cmd', CtrlCmd, queue_size=1)

        self.ctrl_msg = CtrlCmd()

        #time rate
        self.rate = rospy.Rate(30) #30hz
        self.runCtrl()

    def runCtrl(self):
        while not rospy.is_shutdown():
            self.ctrl_msg.velocity = 0.1
            self.ctrl_msg.accel = 0.3
            self.ctrl_msg.acceleration = 0
            #self.ctrl_msg.steering = -30 / 180 * pi
            self.ctrl_pub.publish(self.ctrl_msg)
            print('target vel {}, acc {}'.format(self.ctrl_msg.velocity, self.ctrl_msg.accel))
            self.rate.sleep()

if __name__ == '__main__':
    mct = moraiCtrl()
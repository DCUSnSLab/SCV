import rospy
from abc import *

class MsgModule:
    def __init__(self, msgtype, msgfunc, topic):
        self.msgType = msgtype
        self.msgFunc = msgfunc
        self.topic = topic

class Controller(metaclass=ABCMeta):
    def __init__(self, nodeName, ctrlMsgModule:MsgModule, statusMsgModule:MsgModule):
        rospy.init_node(nodeName, anonymous=True)

        # Command publisher
        self.ctrl_pub = rospy.Publisher(ctrlMsgModule.topic, ctrlMsgModule.msgType, queue_size=1)

        # Ego Vehicle Status Subscriber
        rospy.Subscriber(statusMsgModule.topic, statusMsgModule.msgType, self.__EgoStatusUpdate)
        self.isStatus = False

        #msgs
        self.ctrl_msg = ctrlMsgModule.msgFunc
        self.status_msg = statusMsgModule.msgFunc

        # vehicle status
        self.velocity = 0
        self.acceleration = 0

        # long/lat control
        self.targetVel = 0
        self.targetAcc = 0
        self.targetAngle = 0

        # kph/mps rate
        self.mpsrate = 3.6

        # time rate
        self.rate = rospy.Rate(30)  # 30hz

        self.emergencyBrake(True)

    def runCtrl(self):
        while not rospy.is_shutdown():
            self.ctrl_msg = self._acceptLongCtrl(self.ctrl_msg)
            self.ctrl_msg = self._acceptLatCtrl(self.ctrl_msg)
            self.ctrl_pub.publish(self.ctrl_msg)
            self.rate.sleep()

    @abstractmethod
    def _acceptLongCtrl(self, ctrl_msg):
        return None

    @abstractmethod
    def _acceptLatCtrl(self, ctrl_msg):
        return None

    def __EgoStatusUpdate(self, msg):
        self.status_msg = msg
        self.isStatus = True
        self.velocity = self._getEgoVelocity(msg)
        self.acceleration = self._getEgoAcceleration(msg)

    @abstractmethod
    def _getEgoVelocity(self, msg):
        pass

    @abstractmethod
    def _getEgoAcceleration(self, msg):
        pass

    @abstractmethod
    def emergencyBrake(self, isBrake):
        pass

    def setRate(self, r: int):
        self.rate = rospy.Rate(r)

    def setTargetSpeed(self, speed:float=0, acc:float=0):
        self.targetVel = speed / self.mpsrate
        self.targetAcc = acc

    def setSteeringAngle(self, angle:float=0, rate:float=0):
        self.targetAngle = angle
import rospy
from std_msgs.msg import Float64
from hunter_msgs.msg import HunterStatus

def hunter_status_callback(msg):
    # linear_velocity를 추출하여 퍼블리시
    speed_pub.publish(msg.linear_velocity)

def main():
    rospy.init_node('hunter_status_to_speed')
    
    # /hunter_status 토픽 구독
    rospy.Subscriber('/hunter_status', HunterStatus, hunter_status_callback)
    
    # /speed 토픽 퍼블리셔
    global speed_pub
    speed_pub = rospy.Publisher('/vehicle/velocity', Float64, queue_size=10)
    
    rospy.spin()

if __name__ == '__main__':
    main()

from test_package.hello import Hello
import rospy

he = Hello()
he.say('test')
rospy.init_node('test_node', anonymous=True)
rate = rospy.Rate(30)
while not rospy.is_shutdown():
    rate.sleep()
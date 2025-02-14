#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import PolygonStamped, Point32
from std_msgs.msg import Header

# Initialize the ROS node
rospy.init_node('footprint_publisher')

# Create a PolygonStamped message
polygon_stamped = PolygonStamped()

# Create a Header and populate it
polygon_stamped.header = Header()
polygon_stamped.header.stamp = rospy.Time.now()
polygon_stamped.header.frame_id = "base_link"

# Define the points of the rectangle representing the robot footprint
polygon_stamped.polygon.points = [
    Point32(x=0.80, y=0.7, z=0.0),
    Point32(x=0.80, y=-0.7, z=0.0),
    Point32(x=-0.80, y=-0.7, z=0.0),
    Point32(x=-0.80, y=0.7, z=0.0)
]

# Create a publisher for the PolygonStamped message on the 'footprint' topic
pub = rospy.Publisher('footprint', PolygonStamped, queue_size=10)

# Wait for the publisher to establish connection to subscribers
rospy.sleep(1)

# Publish the message once
pub.publish(polygon_stamped)

# Optionally, log a message
rospy.loginfo("Published the footprint")

# Wait a bit for the message to be sent and then exit
rospy.sleep(1)
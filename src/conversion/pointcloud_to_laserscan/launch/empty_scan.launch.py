from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import math


def generate_launch_description():
    return LaunchDescription([
        # Launch arguments
        DeclareLaunchArgument(
            name='frame_id',
            default_value='base_link',
            description='Frame ID for the laser scan'
        ),
        DeclareLaunchArgument(
            name='scan_topic',
            default_value='ptl/scan',
            description='Output laser scan topic'
        ),
        DeclareLaunchArgument(
            name='publish_rate',
            default_value='10.0',
            description='Publishing rate in Hz'
        ),

        # Empty scan publisher node
        Node(
            package='pointcloud_to_laserscan',
            executable='empty_scan_publisher',
            name='empty_scan_publisher',
            remappings=[
                ('scan', LaunchConfiguration('scan_topic'))
            ],
            parameters=[{
                'frame_id': LaunchConfiguration('frame_id'),
                'publish_rate': LaunchConfiguration('publish_rate'),
                'angle_min': -math.pi,
                'angle_max': math.pi,
                'angle_increment': math.pi / 180.0,  # 1 degree
                'range_min': 0.1,
                'range_max': 10.0
            }],
            output='screen'
        )
    ])
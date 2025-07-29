from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import math


def generate_launch_description():
    return LaunchDescription([
        # Launch arguments
        DeclareLaunchArgument(
            name='cloud_topic', 
            default_value='/velodyne_points',
            description='Input pointcloud topic from velodyne'
        ),
        DeclareLaunchArgument(
            name='scan_topic', 
            default_value='/scan',
            description='Output laserscan topic'
        ),
        DeclareLaunchArgument(
            name='target_frame', 
            default_value='base_link',
            description='Target frame for the conversion'
        ),

        # Pointcloud to laserscan conversion node
        Node(
            package='pointcloud_to_laserscan', 
            executable='pointcloud_to_laserscan_node',
            name='velodyne_to_scan',
            remappings=[
                ('cloud_in', LaunchConfiguration('cloud_topic')),
                ('scan', LaunchConfiguration('scan_topic'))
            ],
            parameters=[{
                'target_frame': LaunchConfiguration('target_frame'),
                'transform_tolerance': 0.01,
                'queue_size': 10,
                'min_height': 0.1,
                'max_height': 2.0,
                'angle_min': -math.pi / 1.5,
                'angle_max': math.pi / 1.5,
                'angle_increment': math.pi / 180.0,  # 1 degree
                'scan_time': 1.0 / 10.0,  # 10Hz
                'range_min': 0.1,
                'range_max': 100.0,
                'use_inf': True,
                'inf_epsilon': 1.0
            }],
            output='screen'
        )
    ])
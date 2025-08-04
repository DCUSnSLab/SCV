#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    """Launch Simple Behavior Planner Node"""
    
    return LaunchDescription([
        # Simple Behavior Planner Node
        Node(
            package='simple_behavior_planner',
            executable='simple_behavior_planner_node.py',
            name='simple_behavior_planner',
            output='screen',
            parameters=[
                # Add any parameters here if needed
            ],
            remappings=[
                # Add any topic remappings here if needed
            ]
        ),
    ])
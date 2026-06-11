from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, ExecuteProcess, DeclareLaunchArgument, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node

def generate_launch_description():
    hunter_base_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('hunter_base'),
                'launch',
                'hunter_base.launch.py'
            ])
        ])
    )

    hunter_teleop_mux = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('hunter_teleop_mux'),
                'launch',
                'mux_node.launch.py'
            ])
        ])
    )

    robot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('hunter2_description'),
                'launch',
                'display.launch.py'
            ])
        ])
    )
    
    return LaunchDescription([
        hunter_base_launch,
        hunter_teleop_mux,
        robot_launch
    ])
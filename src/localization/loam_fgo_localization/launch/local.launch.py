#!/usr/bin/env python3
# LOCAL 계층만: local_odometry (odom->base_link).
#   ros2 launch loam_fgo_localization local.launch.py env:=real use_sim_time:=false
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare("loam_fgo_localization")
    return LaunchDescription([
        DeclareLaunchArgument("use_sim_time", default_value="false"),
        DeclareLaunchArgument("env", default_value="real", choices=["sim", "real"]),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([pkg, "launch", "temp", "local_odometry.launch.py"])),
            launch_arguments={
                "use_sim_time": LaunchConfiguration("use_sim_time"),
                "env": LaunchConfiguration("env"),
            }.items(),
        ),
    ])

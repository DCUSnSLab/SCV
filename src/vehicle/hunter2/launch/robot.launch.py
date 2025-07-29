#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    # Declare arguments
    declared_arguments = [
        DeclareLaunchArgument(
            "description_file",
            default_value="robot.urdf.xacro",
            description="URDF/XACRO description file with the robot.",
        ),
        DeclareLaunchArgument(
            "jsp_gui",
            default_value="true",
            description="Start Joint State Publisher GUI for manual joint control.",
        ),
        DeclareLaunchArgument(
            "gps_latitude",
            default_value="37.5665",
            description="GPS reference latitude (Seoul default).",
        ),
        DeclareLaunchArgument(
            "gps_longitude", 
            default_value="126.9780",
            description="GPS reference longitude (Seoul default).",
        ),
        DeclareLaunchArgument(
            "gps_altitude",
            default_value="50.0",
            description="GPS reference altitude.",
        ),
    ]

    # Initialize Arguments
    jsp_gui = LaunchConfiguration("jsp_gui")
    description_file = LaunchConfiguration("description_file")
    gps_latitude = LaunchConfiguration("gps_latitude")
    gps_longitude = LaunchConfiguration("gps_longitude")
    gps_altitude = LaunchConfiguration("gps_altitude")
    
    # Get URDF via xacro
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [FindPackageShare("hunter2"), "urdf", description_file]
            ),
            " gps_latitude:=", gps_latitude,
            " gps_longitude:=", gps_longitude, 
            " gps_altitude:=", gps_altitude,
        ]
    )
    robot_description = {
        "robot_description": ParameterValue(robot_description_content, value_type=str),
        'use_sim_time': ParameterValue(False, value_type=bool),
    }

    # Joint State Publisher GUI (default enabled)
    joint_state_publisher_gui_node = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
        parameters=[{'use_sim_time': False}],
        condition=IfCondition(jsp_gui)
    )
    
    # Robot State Publisher
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description],
        arguments=["--ros-args", "--log-level", "info"]
    )

    nodes = [
        joint_state_publisher_gui_node,
        robot_state_publisher_node,
    ]

    return LaunchDescription(declared_arguments + nodes)

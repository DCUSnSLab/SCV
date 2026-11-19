"""The vehicle of the e2e pipeline: the dummy Hunter and camera, hunter_mux, teleop and fleet_telemetry.

ros2 launch e2e/vehicle.launch.py video_params:=<file>

The chain is teleop_bringup's, with sensor_dummy in place of hunter_base and the cameras:
teleop_control -> /remote/teleop_cmd -> hunter_mux -> /final_cmd -> sensor_sim -> /odom.
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def include(package, launch_file, arguments):
    path = os.path.join(get_package_share_directory(package), 'launch', launch_file)
    return IncludeLaunchDescription(path, launch_arguments=arguments.items())


def generate_launch_description():
    mux_params = os.path.join(
        get_package_share_directory('hunter_mux'), 'config', 'hunter_mux.param.yaml'
    )
    # As hunter_base.launch.py with remote_status:=true.
    mux = ComposableNodeContainer(
        package='rclcpp_components',
        executable='component_container',
        name='mux_container',
        namespace='',
        composable_node_descriptions=[
            ComposableNode(
                package='hunter_mux',
                plugin='hunter_mux::MuxNode',
                name='hunter_mux',
                parameters=[mux_params, {'remote_status': True}],
                remappings=[
                    ('~/input/cmd_vel', '/cmd_vel'),
                    ('~/input/teleop_cmd', '/remote/teleop_cmd'),
                    ('~/input/estop_status', '/remote/estop_status'),
                    ('~/input/estop', '/remote/estop'),
                    ('~/input/estop_reset', '/remote/estop_reset'),
                    ('~/input/cmd_mode', '/remote/cmd_mode'),
                    ('~/output/final_cmd', '/final_cmd'),
                    ('~/output/mux_status', '/vehicle/mux_status'),
                    ('~/output/estop_status', '/vehicle/estop_status'),
                ],
            )
        ],
        output='screen',
    )
    return LaunchDescription(
        [
            DeclareLaunchArgument('video_params'),
            include(
                'sensor_dummy',
                'sensor_dummy.launch.py',
                {'cameras': 'd435i', 'robot_model': 'false'},
            ),
            mux,
            include(
                'teleop_epoch',
                'teleop.launch.py',
                {
                    'input_image': '/camera/d435i/color/image_raw',
                    'cmd_vel': '/remote/teleop_cmd',
                    'video_params': LaunchConfiguration('video_params'),
                },
            ),
            include('fleet_telemetry', 'fleet_telemetry.launch.py', {}),
        ]
    )

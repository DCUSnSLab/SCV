"""Remote driving on the Hunter: base and hunter_mux, teleop, monitoring agent and blackbox.

ros2 launch bring_up teleop_start.launch.py input_image:=<camera topic> \
    [port_name:=can0] [telemetry:=true] [blackbox:=true] [blackbox_dir:=~/blackbox]
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def include(package, launch_file, arguments, **kwargs):
    return IncludeLaunchDescription(
        PathJoinSubstitution([FindPackageShare(package), 'launch', launch_file]),
        launch_arguments=arguments.items(),
        **kwargs,
    )


def generate_launch_description():
    blackbox_config = PathJoinSubstitution([FindPackageShare('bring_up'), 'config', 'blackbox'])
    return LaunchDescription(
        [
            DeclareLaunchArgument('input_image'),
            DeclareLaunchArgument('port_name', default_value='can0'),
            DeclareLaunchArgument('telemetry', default_value='true'),
            DeclareLaunchArgument('blackbox', default_value='true'),
            DeclareLaunchArgument('blackbox_dir', default_value='~/blackbox'),
            include(
                'hunter_base',
                'hunter_base.launch.py',
                {'port_name': LaunchConfiguration('port_name'), 'remote_status': 'true'},
            ),
            include(
                'teleop_epoch',
                'teleop.launch.py',
                {
                    'input_image': LaunchConfiguration('input_image'),
                    'cmd_vel': '/remote/teleop_cmd',
                },
            ),
            include(
                'fleet_telemetry',
                'fleet_telemetry.launch.py',
                {},
                condition=IfCondition(LaunchConfiguration('telemetry')),
            ),
            include(
                'rosbag_recorder',
                'recorder.launch.py',
                {
                    'config_dir': blackbox_config,
                    'profile': 'blackbox',
                    'autostart': 'true',
                    'label': 'blackbox',
                    'output_dir': LaunchConfiguration('blackbox_dir'),
                },
                condition=IfCondition(LaunchConfiguration('blackbox')),
            ),
        ]
    )

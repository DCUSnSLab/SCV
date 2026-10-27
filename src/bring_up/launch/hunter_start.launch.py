from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    hunter_base_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('hunter_base'),
                'launch',
                'hunter_base.launch.py'
            ])
        ]),
        launch_arguments={'port_name': LaunchConfiguration('port_name')}.items(),
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
        DeclareLaunchArgument('port_name', default_value='can0', description='CAN interface, e.g. can0 or vcan0'),
        hunter_base_launch,
        robot_launch,
    ])

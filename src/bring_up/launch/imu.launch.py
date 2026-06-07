# IMU bringup (VectorNav VN-시리즈).
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    vectornav_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('vectornav'),
                'launch',
                'vectornav.launch.py',
            ])
        ])
    )
    return LaunchDescription([vectornav_launch])

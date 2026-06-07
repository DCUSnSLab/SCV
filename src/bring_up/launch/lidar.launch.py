# Velodyne LiDAR bringup.
# lidar_model 인자로 VLP16 / VLP32C / VLS128 중 선택 (velodyne 패키지의 all-nodes launch 포함).
import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.substitutions import FindPackageShare


def _include_velodyne(context, *args, **kwargs):
    model = LaunchConfiguration('lidar_model').perform(context)
    pkg_share = FindPackageShare('velodyne').perform(context)
    launch_file = os.path.join(
        pkg_share, 'launch', f'velodyne-all-nodes-{model}-launch.py'
    )
    if not os.path.exists(launch_file):
        raise RuntimeError(
            f'[lidar.launch] velodyne launch 파일 없음: {launch_file} '
            f'(lidar_model 은 VLP16/VLP32C/VLS128 중 하나여야 함)'
        )
    return [IncludeLaunchDescription(PythonLaunchDescriptionSource(launch_file))]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'lidar_model',
            default_value='VLP32C',
            description='Velodyne 모델: VLP16 | VLP32C | VLS128',
        ),
        OpaqueFunction(function=_include_velodyne),
    ])

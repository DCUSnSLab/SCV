# 전체 센서 bringup: LiDAR + IMU + GNSS(RTK) + 카메라.
# 각 센서는 use_* 인자로 개별 on/off (기본 전부 on).
#
#   ros2 launch bring_up sensors.launch.py use_cameras:=false lidar_model:=VLP32C
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def _include(this_pkg_launch, condition_arg, extra_args=None):
    inc = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('bring_up'), 'launch', this_pkg_launch
            ])
        ]),
        condition=IfCondition(LaunchConfiguration(condition_arg)),
        launch_arguments=(extra_args.items() if extra_args else None),
    )
    return inc


def generate_launch_description():
    args = [
        DeclareLaunchArgument('use_lidar', default_value='true'),
        DeclareLaunchArgument('use_imu', default_value='true'),
        DeclareLaunchArgument('use_gnss', default_value='true'),
        DeclareLaunchArgument('use_cameras', default_value='true'),
        DeclareLaunchArgument(
            'lidar_model', default_value='VLP32C',
            description='Velodyne 모델: VLP16 | VLP32C | VLS128',
        ),
    ]

    lidar = _include(
        'lidar.launch.py', 'use_lidar',
        {'lidar_model': LaunchConfiguration('lidar_model')},
    )
    imu = _include('imu.launch.py', 'use_imu')
    gnss = _include('gnss_start.launch.py', 'use_gnss')
    cameras = _include('rs_dual.launch.py', 'use_cameras')

    return LaunchDescription(args + [lidar, imu, gnss, cameras])

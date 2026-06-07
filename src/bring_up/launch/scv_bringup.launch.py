# SCV 최상위 통합 bringup: 차량 + 센서 + 측위를 한 번에 기동.
#
# 자율주행 두뇌(전역경로/행동계획/제어/맵서버)는 command_center 패키지가 담당하며
# 이 launch 이후 별도로 실행한다:  ros2 launch command_center_launch system.launch.py
#
# 예)
#   전체:                 ros2 launch bring_up scv_bringup.launch.py
#   센서 제외, 차량만:     ros2 launch bring_up scv_bringup.launch.py use_sensors:=false use_localization:=false
#   카메라 빼고 32C 라이다: ros2 launch bring_up scv_bringup.launch.py use_cameras:=false lidar_model:=VLP32C
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def _bringup(launch_file, condition_arg, forwarded=None):
    return IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('bring_up'), 'launch', launch_file
            ])
        ]),
        condition=IfCondition(LaunchConfiguration(condition_arg)),
        launch_arguments=(forwarded.items() if forwarded else None),
    )


def generate_launch_description():
    args = [
        # 서브시스템 토글
        DeclareLaunchArgument('use_vehicle', default_value='true',
                              description='Hunter 베이스 + teleop mux + URDF'),
        DeclareLaunchArgument('use_sensors', default_value='true',
                              description='LiDAR + IMU + GNSS + 카메라'),
        DeclareLaunchArgument('use_localization', default_value='true',
                              description='dual-EKF 측위'),
        # 센서 세부 토글 (sensors.launch.py 로 전달)
        DeclareLaunchArgument('use_lidar', default_value='true'),
        DeclareLaunchArgument('use_imu', default_value='true'),
        DeclareLaunchArgument('use_gnss', default_value='true'),
        DeclareLaunchArgument('use_cameras', default_value='true'),
        DeclareLaunchArgument('lidar_model', default_value='VLP32C',
                              description='Velodyne 모델: VLP16 | VLP32C | VLS128'),
        # 측위 세부 토글 (localization.launch.py 로 전달)
        DeclareLaunchArgument('use_fast_lio', default_value='false'),
    ]

    vehicle = _bringup('hunter_start.launch.py', 'use_vehicle')

    sensors = _bringup('sensors.launch.py', 'use_sensors', {
        'use_lidar': LaunchConfiguration('use_lidar'),
        'use_imu': LaunchConfiguration('use_imu'),
        'use_gnss': LaunchConfiguration('use_gnss'),
        'use_cameras': LaunchConfiguration('use_cameras'),
        'lidar_model': LaunchConfiguration('lidar_model'),
    })

    localization = _bringup('localization.launch.py', 'use_localization', {
        'use_fast_lio': LaunchConfiguration('use_fast_lio'),
    })

    return LaunchDescription(args + [vehicle, sensors, localization])

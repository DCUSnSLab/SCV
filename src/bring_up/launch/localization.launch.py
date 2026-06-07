# Localization bringup: dual-EKF(robot_localization) + 선택적 LiDAR odom(fast_lio) + pointcloud→laserscan.
#
# 융합 구조(docs/localization_study.md 참고):
#   GPS + IMU + 휠오돔 + (fast_lio LiDAR odom) -> ekf_odom/ekf_map -> odometry/local, odometry/global
#
#   ros2 launch bring_up localization.launch.py use_fast_lio:=true
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    args = [
        DeclareLaunchArgument('use_ekf', default_value='true',
                              description='robot_localization dual-EKF + navsat'),
        DeclareLaunchArgument('use_fast_lio', default_value='false',
                              description='FAST-LIO LiDAR-관성 오도메트리 (LiDAR 필요)'),
        DeclareLaunchArgument('use_pc2scan', default_value='false',
                              description='velodyne pointcloud -> laserscan 변환'),
    ]

    # robot_localization: SCV dual EKF + navsat_transform
    ekf = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('robot_localization'),
                'launch', 'dual_ekf_navsat.launch.py',
            ])
        ]),
        condition=IfCondition(LaunchConfiguration('use_ekf')),
    )

    # FAST-LIO (LiDAR odometry) - 선택
    fast_lio = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('fast_lio'), 'launch', 'mapping.launch.py',
            ])
        ]),
        condition=IfCondition(LaunchConfiguration('use_fast_lio')),
    )

    # pointcloud -> laserscan - 선택
    pc2scan = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('pointcloud_to_laserscan'),
                'launch', 'velodyne_to_scan.launch.py',
            ])
        ]),
        condition=IfCondition(LaunchConfiguration('use_pc2scan')),
    )

    return LaunchDescription(args + [ekf, fast_lio, pc2scan])

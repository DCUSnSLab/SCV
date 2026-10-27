#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time')
    env = LaunchConfiguration('env')
    config_file = LaunchConfiguration('config_file')

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time', default_value='true',
            description='bag/시뮬레이션 재생 시 true'),
        DeclareLaunchArgument(
            'env', default_value='real', choices=['sim', 'real'],
            description="파라미터 프로파일: 'sim'(Gazebo) 또는 'real'(실환경 bag). "
                        "config/local_odometry_<env>.yaml 을 로드."),
        DeclareLaunchArgument(
            'config_file',
            # env 로 자동 선택. 전체 경로를 직접 넘기면 이 값을 오버라이드.
            default_value=PathJoinSubstitution(
                [FindPackageShare('loam_fgo_localization'), 'config',
                 ['local_odometry_', env, '.yaml']]),
            description='파라미터 파일 경로 (기본: env 로 선택)'),

        Node(
            package='loam_fgo_localization',
            executable='local_odometry_node',
            name='local_odometry_node',
            output='screen',
            parameters=[config_file, {'use_sim_time': use_sim_time}],
        ),
    ])

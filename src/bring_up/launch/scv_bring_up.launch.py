from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, ExecuteProcess, DeclareLaunchArgument, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node

def generate_launch_description():
    # ZED Camera Launch
    zed_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('zed_wrapper'),
                'launch',
                'zed_camera.launch.py'
            ])
        ]),
        launch_arguments={
            'camera_model': 'zed2i'
        }.items()
    )
    
    # uBlox GPS Launch
    ublox_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ublox_gps'),
                'launch',
                'ublox_gps_node-launch.py'
            ])
        ])
    )
    
    # NMEA Init Publisher
    nmea_init = Node(
        package='ntrip_client',
        executable='nmea_init_pub.py'
    )
    
    ntrip_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ntrip_client'),
                'launch',
                'ntrip_client_launch.py'
            ])
        ])
    )

    # Velodyne LiDAR Launch
    velodyne_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('velodyne'),
                'launch',
                'velodyne-all-nodes-VLP32C-launch.py'
            ])
        ])
    )

    # VectorNav IMU Launch
    vectornav_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('vectornav'),
                'launch',
                'vectornav.launch.py'
            ])
        ])
    )

    # Hunter Base Launch
    hunter_base_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('hunter_base'),
                'launch',
                'hunter_base.launch.py'
            ])
        ])
    )

    robot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('hunter2'),
                'launch',
                'robot.launch.py'
            ])
        ])
    )
    
    return LaunchDescription([
        zed_launch,
        ublox_launch,
        nmea_init,
        ntrip_launch,
        velodyne_launch,
        vectornav_launch,
        hunter_base_launch,
        robot_launch
    ])
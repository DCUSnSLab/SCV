from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
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

    # NMEA Init Publisher
    nmea_init = Node(
        package='ntrip_client',
        executable='nmea_init_pub.py'
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
    
    # NTRIP Client Launch
    ntrip_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ntrip_client'),
                'ntrip_client_launch.py'
            ])
        ])
    )
    
    robot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('SSC_description'),
                'launch',
                'SSC_robot.launch.py'
            ])
        ])
    )
    
    return LaunchDescription([
        ublox_launch,
        robot_launch,
        zed_launch,
        nmea_init,
        ntrip_launch,
    ])
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    def inc(pkg, launch_file):
        return IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([
                    FindPackageShare(pkg), 'launch', launch_file
                ])
            )
        )

    vectornav = inc('vectornav', 'vectornav.launch.py')
    velodyne = inc('velodyne', 'velodyne-all-nodes-VLP32C-launch.py')
    vehicle_tf = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare('hunter2_description'), 'launch',
                'display.launch.py'
            ])
        ),
        condition=IfCondition(LaunchConfiguration('enable_vehicle_tf')),
        launch_arguments={
            'use_tf_mounts': 'true',
            'use_realsense': 'false',
            'jsp_gui': 'false',
        }.items(),
    )
    d555 = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare('bring_up'), 'launch',
                                  'd555.launch.py'])
        ),
        condition=IfCondition(LaunchConfiguration('enable_d555')),
        launch_arguments={
            'serial_no': LaunchConfiguration('d555_serial_no'),
        }.items(),
    )
    d435 = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare('bring_up'), 'launch',
                                  'd435_tri.launch.py'])
        ),
        condition=IfCondition(LaunchConfiguration('enable_d435')),
    )
    sllidar = inc('sllidar_ros2', 'sllidar_dual_c1_launch.py')
    bev = Node(
        package='d555_velodyne_bev',
        executable='d555_velodyne_bev_node',
        output='screen',
        condition=IfCondition(LaunchConfiguration('enable_bev')),
    )

    return LaunchDescription([
        DeclareLaunchArgument('enable_d555', default_value='true'),
        DeclareLaunchArgument('d555_serial_no', default_value=''),
        DeclareLaunchArgument('enable_bev', default_value='true'),
        DeclareLaunchArgument('enable_d435', default_value='true'),
        DeclareLaunchArgument('enable_vehicle_tf', default_value='true'),
        vehicle_tf,
        vectornav,
        velodyne,
        d555,
        d435,
        sllidar,
        bev,
    ])

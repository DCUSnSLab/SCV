from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    rs_launch = PathJoinSubstitution([
        FindPackageShare('realsense2_camera'), 'launch', 'rs_launch.py'
    ])

    front = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(rs_launch),
        launch_arguments={
            'serial_no': "'239122073045'",
            'camera_name': 'camera_front',
            'camera_namespace': 'front',
        }.items(),
    )

    rear = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(rs_launch),
        launch_arguments={
            'serial_no': "'233522076130'",
            'camera_name': 'camera_rear',
            'camera_namespace': 'rear',
        }.items(),
    )

    return LaunchDescription([front, rear])

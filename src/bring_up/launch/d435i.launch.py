from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    realsense_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('realsense2_camera'),
                'launch',
                'rs_launch.py'
            ])
        ]),
        launch_arguments={
            'camera_name': 'd435i',
            'camera_namespace': 'camera',
            'enable_color': 'true',
            'enable_depth': 'true',
            'enable_gyro': 'true',
            'enable_accel': 'true',
            'unite_imu_method': '2',
            'align_depth.enable': 'true',
            'pointcloud.enable': 'true',
            'enable_rgbd': 'true',
            'enable_sync': 'true',
            'spatial_filter.enable': 'false',
            'temporal_filter.enable': 'false',
            'hole_filling_filter.enable': 'false',
        }.items()
    )

    return LaunchDescription([
        realsense_launch
    ])

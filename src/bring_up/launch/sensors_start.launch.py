from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    def inc(pkg, launch_file):
        return IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([FindPackageShare(pkg), 'launch', launch_file])
            )
        )

    vectornav = inc('vectornav', 'vectornav.launch.py')
    velodyne = inc('velodyne', 'velodyne-all-nodes-VLP32C-launch.py')
    realsense = inc('realsense2_camera', 'rs_launch.py')
    sllidar = inc('sllidar_ros2', 'sllidar_dual_c1_launch.py')

    return LaunchDescription([
        vectornav,
        velodyne,
        realsense,
        sllidar,
    ])

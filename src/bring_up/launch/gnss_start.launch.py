from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    ublox_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [FindPackageShare('ublox_gps'), 'launch', 'ublox_gps_node-launch.py']
                )
            ]
        )
    )
    ntrip_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [FindPackageShare('ntrip_client'), 'launch', 'ntrip_client_launch.py']
                )
            ]
        ),
        # The caster places its virtual reference station at the receiver's own fix.
        launch_arguments={'fix_topic': '/ublox_gps_node/fix'}.items(),
    )

    return LaunchDescription([ublox_launch, ntrip_launch])

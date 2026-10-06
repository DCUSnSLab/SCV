"""Launch the calibrated D555 plus Velodyne BEV renderer."""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    defaults = {
        'target_frame': 'velodyne',
        'x_min': '-5.0',
        'x_max': '20.0',
        'y_min': '-10.0',
        'y_max': '10.0',
        'z_min': '-1.5',
        'z_max': '2.0',
        'resolution': '0.05',
        'publish_rate': '10.0',
        'stale_timeout': '1.0',
        'camera_stride': '2',
        'velodyne_stride': '1',
    }
    arguments = [
        DeclareLaunchArgument(name, default_value=value)
        for name, value in defaults.items()
    ]
    float_names = {
        'x_min', 'x_max', 'y_min', 'y_max', 'z_min', 'z_max',
        'resolution', 'publish_rate', 'stale_timeout'
    }
    float_parameters = {
        name: ParameterValue(LaunchConfiguration(name), value_type=float)
        for name in float_names
    }
    integer_parameters = {
        name: ParameterValue(LaunchConfiguration(name), value_type=int)
        for name in ('camera_stride', 'velodyne_stride')
    }
    node = Node(
        package='d555_velodyne_bev',
        executable='d555_velodyne_bev_node',
        output='screen',
        parameters=[float_parameters, integer_parameters, {
            'target_frame': LaunchConfiguration('target_frame'),
        }],
    )
    return LaunchDescription(arguments + [node])

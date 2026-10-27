import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import ComposableNodeContainer, Node
from launch_ros.descriptions import ComposableNode
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    mux_params = os.path.join(get_package_share_directory('hunter_mux'), 'config', 'mux_params.yaml')
    intra = [{'use_intra_process_comms': True}]

    vehicle_container = ComposableNodeContainer(
        name='vehicle_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        output='screen',
        emulate_tty=True,
        composable_node_descriptions=[
            ComposableNode(
                package='hunter_base',
                plugin='westonrobot::HunterBaseRos',
                name='hunter',
                parameters=[{
                    'port_name': 'can0',
                    'odom_frame': 'odom',
                    'base_frame': 'base_link',
                    'odom_topic_name': 'odometry/wheel',
                    'publish_tf': False,
                    'simulated_robot': False,
                    'control_rate': 50,
                }],
                extra_arguments=intra,
            ),
            ComposableNode(
                package='hunter_mux',
                plugin='hunter_mux::MuxNode',
                name='mux_node',
                parameters=[mux_params],
                extra_arguments=intra,
            ),
        ],
    )

    velocity_extractor_node = Node(
        package='hunter_base',
        executable='velocity_extractor_node',
        output='screen',
        emulate_tty=True)

    hunter_state_parser_node = Node(
        package='hunter_base',
        executable='hunter_state_parser_node',
        output='screen',
        emulate_tty=True)

    robot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('hunter2_description'),
                'launch',
                'display.launch.py'
            ])
        ])
    )

    return LaunchDescription([
        vehicle_container,
        velocity_extractor_node,
        hunter_state_parser_node,
        robot_launch,
    ])

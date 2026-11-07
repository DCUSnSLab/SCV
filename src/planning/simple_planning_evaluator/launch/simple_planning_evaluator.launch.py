"""simple_planning_evaluator, on the topics of the SCV stack.

ros2 launch simple_planning_evaluator simple_planning_evaluator.launch.py [param_file:=<path>]
    [summary_path:=<path>]

The default parameters match the ackermann config of simple_mppi_planner. For its diff config pass
config/simple_planning_evaluator_diff.param.yaml.
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def launch_setup(context):
    overrides = {}
    summary_path = LaunchConfiguration('summary_path').perform(context)
    if summary_path:
        overrides['summary_path'] = summary_path
    return [
        Node(
            package='simple_planning_evaluator',
            executable='simple_planning_evaluator_node',
            name='simple_planning_evaluator',
            parameters=[LaunchConfiguration('param_file'), overrides],
            remappings=[
                ('~/input/route', '/route'),
                ('~/input/trajectory', '/simple_mppi_planner/debug/trajectory'),
                ('~/input/grid', '/costmap'),
                ('~/input/odometry', '/odometry/global'),
                ('~/input/cmd_vel', '/cmd_vel'),
                ('~/output/metrics', '/planning/metrics'),
            ],
            output='screen',
        )
    ]


def generate_launch_description():
    default_params = PathJoinSubstitution(
        [
            FindPackageShare('simple_planning_evaluator'),
            'config',
            'simple_planning_evaluator.param.yaml',
        ]
    )
    return LaunchDescription(
        [
            DeclareLaunchArgument('param_file', default_value=default_params),
            # Empty keeps summary_path of the parameter file.
            DeclareLaunchArgument('summary_path', default_value=''),
            OpaqueFunction(function=launch_setup),
        ]
    )

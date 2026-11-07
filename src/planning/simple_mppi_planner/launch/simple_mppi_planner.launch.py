"""simple_mppi_planner, on the topics of the SCV stack.

ros2 launch simple_mppi_planner simple_mppi_planner.launch.py [param_file:=<path>]

The default parameters are the Hunter 2 with the ackermann model. For a differential-drive base
pass config/simple_mppi_planner_diff.param.yaml.
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    default_params = PathJoinSubstitution(
        [FindPackageShare("simple_mppi_planner"), "config", "simple_mppi_planner.param.yaml"]
    )
    planner = Node(
        package="simple_mppi_planner",
        executable="simple_mppi_planner_node",
        name="simple_mppi_planner",
        parameters=[
            LaunchConfiguration("param_file"),
            {"use_sim_time": ParameterValue(LaunchConfiguration("use_sim_time"), value_type=bool)},
        ],
        remappings=[
            ("~/input/route", "/route"),
            ("~/input/odometry", "/odometry/global"),
            ("~/input/grid", "/costmap"),
            ("~/output/cmd_vel", "/cmd_vel"),
            ("~/output/diagnostics", "/diagnostics"),
        ],
        output="screen",
    )
    return LaunchDescription(
        [
            DeclareLaunchArgument("param_file", default_value=default_params),
            DeclareLaunchArgument("use_sim_time", default_value="false"),
            planner,
        ]
    )

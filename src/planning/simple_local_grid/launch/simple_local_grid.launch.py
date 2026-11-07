"""simple_local_grid, on the topics of the SCV stack.

ros2 launch simple_local_grid simple_local_grid.launch.py [transport:=flux] \
    [container:=/<running container>] [param_file:=<path>]

Without container it starts its own capa_component_container, which flux needs.
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import ComposableNodeContainer
from launch_ros.actions import LoadComposableNodes
from launch_ros.descriptions import ComposableNode
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def launch_setup(context):
    use_sim_time = ParameterValue(LaunchConfiguration("use_sim_time"), value_type=bool)
    grid = ComposableNode(
        package="simple_local_grid",
        plugin="simple_local_grid::SimpleLocalGrid",
        name="simple_local_grid",
        parameters=[
            LaunchConfiguration("param_file"),
            {"transport": LaunchConfiguration("transport"), "use_sim_time": use_sim_time},
        ],
        remappings=[
            ("~/input/points", "/velodyne_points"),
            ("~/output/grid", "/costmap"),
        ],
    )
    container = LaunchConfiguration("container").perform(context)
    if container:
        return [
            LoadComposableNodes(target_container=container, composable_node_descriptions=[grid])
        ]
    return [
        ComposableNodeContainer(
            package="capa_ros",
            executable="capa_component_container",
            name="simple_local_grid_container",
            namespace="",
            composable_node_descriptions=[grid],
            output="screen",
        )
    ]


def generate_launch_description():
    default_params = PathJoinSubstitution(
        [FindPackageShare("simple_local_grid"), "config", "simple_local_grid.param.yaml"]
    )
    return LaunchDescription(
        [
            # The same value as transport of bring_up lidar.launch.py.
            DeclareLaunchArgument("transport", default_value="dds", choices=["dds", "flux"]),
            DeclareLaunchArgument("use_sim_time", default_value="false"),
            DeclareLaunchArgument("container", default_value=""),
            DeclareLaunchArgument("param_file", default_value=default_params),
            OpaqueFunction(function=launch_setup),
        ]
    )

import os

from ament_index_python.packages import get_package_prefix
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import yaml


def sd_map_parameters():
    """simple_sd_map.param.yaml, with osm_file taken from the workspace's maps/ directory."""
    path = os.path.join(
        get_package_share_directory('simple_sd_map'), 'config', 'simple_sd_map.param.yaml'
    )
    with open(path) as stream:
        parameters = next(iter(yaml.safe_load(stream).values()))['ros__parameters']
    # The isolated install layout puts the package prefix at <workspace>/install/<package>.
    workspace = os.path.dirname(os.path.dirname(get_package_prefix('bring_up')))
    osm_file = os.path.join(workspace, 'maps', parameters['osm_file'])
    return [path, {'osm_file': osm_file}]


def generate_launch_description():
    sd_map = Node(
        package='simple_sd_map',
        executable='simple_sd_map_node',
        parameters=sd_map_parameters(),
        remappings=[
            ('~/output/sd_map', '/sd_map'),
            ('~/output/markers', '/sd_map/markers'),
        ],
    )
    mission_planner = Node(
        package='simple_mission_planner',
        executable='simple_mission_planner_node',
        remappings=[
            ('~/input/sd_map', '/sd_map'),
            ('~/input/odometry', '/odometry/global'),
            ('~/input/goal_pose', '/goal_pose'),
            ('~/output/route', '/route'),
        ],
    )
    return LaunchDescription([sd_map, mission_planner])

from launch import LaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    sd_map = Node(
        package='simple_sd_map',
        executable='simple_sd_map_node',
        parameters=[PathJoinSubstitution([
            FindPackageShare('simple_sd_map'), 'config', 'simple_sd_map.param.yaml'])],
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

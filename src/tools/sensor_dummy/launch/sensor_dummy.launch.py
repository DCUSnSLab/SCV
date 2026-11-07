"""Dummy sensors and vehicle. Any subset starts by arguments; see doc/sensor_dummy.md.

  ros2 launch sensor_dummy sensor_dummy.launch.py [sim:=true] [outputs:=lidar,imu,gnss] \
      [cameras:=d435i,zed2i,zedxone] [motion_model:=diff] [ground_truth:=true]
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.actions import OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import ComposableNodeContainer
from launch_ros.actions import Node
from launch_ros.descriptions import ComposableNode
from sensor_dummy.launch_helpers import camera_frames_urdf
from sensor_dummy.launch_helpers import camera_node_config
from sensor_dummy.launch_helpers import resolve_instances
from sensor_dummy.launch_helpers import urdf_mounts
import xacro
import yaml

SHARE = get_package_share_directory("sensor_dummy")
BASE_FRAME = "base_link"
MOUNTED_SENSORS = ("velodyne", "vectornav", "gnss_antenna")
SIM_TOPICS = {
    "~/input/final_cmd": "/final_cmd",
    "~/output/velodyne_points": "/velodyne_points",
    "~/output/imu": "/vectornav/imu",
    "~/output/pose": "/vectornav/pose",
    "~/output/fix": "/ublox_gps_node/fix",
    "~/output/fix_velocity": "/ublox_gps_node/fix_velocity",
    "~/output/navpvt": "/ublox_gps_node/navpvt",
    "~/output/navpvt_catalog": "/navpvt",
    "~/output/rxmrtcm": "/rxmrtcm",
    "~/output/hunter_status": "/hunter_status",
    "~/output/velocity": "/hunter/velocity",
    "~/output/current_speed": "/current_speed",
    "~/output/current_steer_angle": "/current_steer_angle",
    "~/output/odometry_global": "/odometry/global",
    "~/output/tf": "/tf",
}


def config_path(name):
    return os.path.join(SHARE, "config", name)


def split_list(text):
    return [item.strip() for item in text.split(",") if item.strip()]


def sim_component(argument):
    urdf = xacro.process_file(
        os.path.join(get_package_share_directory("hunter2_description"), "urdf", "robot.urdf.xacro")
    ).toxml()
    mounts = urdf_mounts(urdf, BASE_FRAME, MOUNTED_SENSORS)
    overrides = {
        "map_file": argument("map_file"),
        "outputs": split_list(argument("outputs")),
        "vehicle.motion_model": argument("motion_model"),
        "ground_truth.enable": argument("ground_truth") == "true",
        "lidar.calibration_file": config_path("VeloView-VLP-32C.yaml"),
    }
    overrides.update({f"mount.{frame}": value for frame, value in mounts.items()})
    return ComposableNode(
        package="sensor_dummy",
        plugin="sensor_dummy::SensorSim",
        name="sensor_sim",
        parameters=[config_path("sensor_sim.param.yaml"), overrides],
        remappings=list(SIM_TOPICS.items()) + [("~/output/odom", argument("odom_topic"))],
    )


def camera_component(config, name):
    parameters, remappings = camera_node_config(config, name)
    return ComposableNode(
        package="sensor_dummy",
        plugin="sensor_dummy::CameraDummy",
        name=f"{name}_dummy",
        parameters=[config_path("camera_dummy.param.yaml"), parameters],
        remappings=remappings,
    )


def launch_setup(context):
    def argument(name):
        return LaunchConfiguration(name).perform(context)

    with open(config_path("cameras.yaml")) as f:
        config = yaml.safe_load(f)
    cameras = resolve_instances(config, split_list(argument("cameras")))
    sim = argument("sim") == "true"

    components = [sim_component(argument)] if sim else []
    components += [camera_component(config, name) for name in cameras]
    actions = [
        # Isolated: one thread per node, so raycasting and big images do not delay each other.
        ComposableNodeContainer(
            name="sensor_dummy_container",
            namespace="",
            package="rclcpp_components",
            executable="component_container_isolated",
            composable_node_descriptions=components,
            output="screen",
        )
    ]
    if sim and argument("robot_model") == "true":
        actions.append(
            IncludeLaunchDescription(
                os.path.join(
                    get_package_share_directory("hunter2_description"),
                    "launch",
                    "display.launch.py",
                )
            )
        )
    frames = camera_frames_urdf(config, cameras, BASE_FRAME)
    if frames is not None:
        actions.append(
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                name="dummy_camera_state_publisher",
                parameters=[{"robot_description": frames}],
                remappings=[("robot_description", "dummy_camera_description")],
            )
        )
    return actions


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument("sim", default_value="true", description="Vehicle and lidar sim"),
            DeclareLaunchArgument(
                "outputs",
                default_value="lidar,imu,gnss,hunter,odom,tf",
                description="sim outputs to start. Leave out tf under the real localization EKFs",
            ),
            DeclareLaunchArgument(
                "cameras",
                default_value="",
                description="Instances or groups of config/cameras.yaml, comma separated",
            ),
            DeclareLaunchArgument(
                "motion_model", default_value="ackermann", choices=["ackermann", "diff"]
            ),
            DeclareLaunchArgument("map_file", default_value=config_path("sidewalk_map.yaml")),
            DeclareLaunchArgument(
                "odom_topic",
                default_value="/odom",
                description="/odometry/wheel is what bring_up hunter_start.launch.py publishes",
            ),
            DeclareLaunchArgument(
                "ground_truth",
                default_value="false",
                description="true: publish the true pose on /odometry/global",
            ),
            DeclareLaunchArgument(
                "robot_model",
                default_value="true",
                description="true: hunter2_description display.launch.py (static sensor TF)",
            ),
            OpaqueFunction(function=launch_setup),
        ]
    )

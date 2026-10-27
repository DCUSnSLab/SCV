#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare("loam_fgo_localization")
    use_sim_time = LaunchConfiguration("use_sim_time")
    map_dir = LaunchConfiguration("map_dir")
    localizer_config = LaunchConfiguration("localizer_config")
    lio_sam_config = LaunchConfiguration("lio_sam_config")
    start_lio_preprocessing = LaunchConfiguration("start_lio_preprocessing")

    return LaunchDescription([
        DeclareLaunchArgument("use_sim_time", default_value="false"),
        DeclareLaunchArgument(
            "map_dir",
            description=(
                "Map bundle directory containing full_corner.pcd and full_surf.pcd. "
                "The map files are runtime data and are not stored in this repository."
            ),
        ),
        DeclareLaunchArgument(
            "localizer_config",
            default_value=PathJoinSubstitution(
                [pkg, "config", "fixed_map_localization_bundle.yaml"]),
        ),
        DeclareLaunchArgument(
            "lio_sam_config",
            default_value=PathJoinSubstitution(
                [pkg, "config", "lio_sam_real.yaml"]),
        ),
        DeclareLaunchArgument(
            "start_lio_preprocessing",
            default_value="true",
            description="Start LIO-SAM image projection and feature extraction.",
        ),
        DeclareLaunchArgument("lookup_backend", default_value="cuda"),
        DeclareLaunchArgument("require_initial_pose", default_value="false"),
        DeclareLaunchArgument("publish_map_features", default_value="false"),
        DeclareLaunchArgument("publish_registered_cloud", default_value="false"),
        DeclareLaunchArgument("profile_timings", default_value="false"),
        DeclareLaunchArgument("global_pose_topic", default_value="/global_pose"),
        DeclareLaunchArgument(
            "map_to_odom_candidate_topic", default_value="/pcd/map_to_odom"),
        DeclareLaunchArgument(
            "processing_enable_topic", default_value="/localization/pcd_enabled"),
        DeclareLaunchArgument("processing_enabled_at_start", default_value="true"),
        DeclareLaunchArgument("publish_map_to_odom", default_value="true"),
        DeclareLaunchArgument("scan_corner_leaf", default_value="0.2"),
        DeclareLaunchArgument("scan_surf_leaf", default_value="0.4"),
        DeclareLaunchArgument("local_map_radius", default_value="35.0"),
        DeclareLaunchArgument("max_iterations", default_value="20"),

        Node(
            package="lio_sam",
            executable="lio_sam_imageProjection",
            name="lio_sam_imageProjection",
            parameters=[lio_sam_config, {
                "use_sim_time": use_sim_time,
                "profile_timings": LaunchConfiguration("profile_timings"),
            }],
            output="screen",
            condition=IfCondition(start_lio_preprocessing),
        ),
        Node(
            package="lio_sam",
            executable="lio_sam_featureExtraction",
            name="lio_sam_featureExtraction",
            parameters=[lio_sam_config, {
                "use_sim_time": use_sim_time,
                "profile_timings": LaunchConfiguration("profile_timings"),
            }],
            output="screen",
            condition=IfCondition(start_lio_preprocessing),
        ),
        Node(
            package="loam_fgo_localization",
            executable="lio_feature_map_localizer_node",
            name="lio_feature_map_localizer",
            output="screen",
            parameters=[
                localizer_config,
                {
                    "corner_map_path": PathJoinSubstitution(
                        [map_dir, "full_corner.pcd"]),
                    "surf_map_path": PathJoinSubstitution(
                        [map_dir, "full_surf.pcd"]),
                    "lookup_backend": LaunchConfiguration("lookup_backend"),
                    "require_initial_pose": LaunchConfiguration(
                        "require_initial_pose"),
                    "publish_map_features": LaunchConfiguration(
                        "publish_map_features"),
                    "publish_registered_cloud": LaunchConfiguration(
                        "publish_registered_cloud"),
                    "profile_timings": LaunchConfiguration("profile_timings"),
                    "global_pose_topic": LaunchConfiguration("global_pose_topic"),
                    "map_to_odom_candidate_topic": LaunchConfiguration(
                        "map_to_odom_candidate_topic"),
                    "processing_enable_topic": LaunchConfiguration(
                        "processing_enable_topic"),
                    "processing_enabled_at_start": ParameterValue(
                        LaunchConfiguration("processing_enabled_at_start"),
                        value_type=bool),
                    "publish_map_to_odom": ParameterValue(
                        LaunchConfiguration("publish_map_to_odom"), value_type=bool),
                    "scan_corner_leaf": ParameterValue(
                        LaunchConfiguration("scan_corner_leaf"), value_type=float),
                    "scan_surf_leaf": ParameterValue(
                        LaunchConfiguration("scan_surf_leaf"), value_type=float),
                    "local_map_radius": ParameterValue(
                        LaunchConfiguration("local_map_radius"), value_type=float),
                    "max_iterations": ParameterValue(
                        LaunchConfiguration("max_iterations"), value_type=int),
                    "use_sim_time": use_sim_time,
                },
            ],
        ),
    ])

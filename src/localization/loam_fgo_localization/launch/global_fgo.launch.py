#!/usr/bin/env python3
# GLOBAL 계층 (FGO 버전): fixed-map PCD localizer + GPS frontend + FGO 융합.
#   두 측정 소스를 FGO 가 공분산 가중으로 연속 융합 -> map->odom.
#   local(odom->base_link)은 별도(local.launch.py / fgo_localization.launch.py).
#
#   ros2 launch loam_fgo_localization global_fgo.launch.py use_sim_time:=true
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare("loam_fgo_localization")
    use_sim_time = LaunchConfiguration("use_sim_time")
    fgo_config = LaunchConfiguration("fgo_config")

    fixed_map = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([pkg, "launch", "temp", "fixed_map_localization.launch.py"])),
        launch_arguments={
            "use_sim_time": use_sim_time,
            "map_dir": LaunchConfiguration("map_dir"),
            "localizer_config": LaunchConfiguration("localizer_config"),
            "lookup_backend": LaunchConfiguration("lookup_backend"),
            "require_initial_pose": "true",
            "global_pose_topic": "/pcd/global_pose",
            "map_to_odom_candidate_topic": "/pcd/map_to_odom",
            "processing_enable_topic": "/localization/pcd_enabled",
            # FGO 스택에는 mode manager 가 없으므로 시작부터 처리 활성.
            "processing_enabled_at_start": "true",
            "publish_map_to_odom": "false",
            "profile_timings": LaunchConfiguration("profile_timings"),
            "scan_corner_leaf": LaunchConfiguration("scan_corner_leaf"),
            "scan_surf_leaf": LaunchConfiguration("scan_surf_leaf"),
            "local_map_radius": LaunchConfiguration("local_map_radius"),
            "max_iterations": LaunchConfiguration("max_iterations"),
        }.items(),
    )

    return LaunchDescription([
        DeclareLaunchArgument("use_sim_time", default_value="false"),
        DeclareLaunchArgument("env", default_value="real", choices=["sim", "real"]),
        DeclareLaunchArgument("map_dir", default_value="/home/nev/VNR_devel/SCV/maps/d2_20260813_v2",
                              description="Map bundle directory (full_corner.pcd, full_surf.pcd)"),
        DeclareLaunchArgument(
            "localizer_config",
            default_value=PathJoinSubstitution(
                [pkg, "config", "fixed_map_localization_bundle.yaml"])),
        DeclareLaunchArgument(
            "fgo_config",
            default_value=PathJoinSubstitution([pkg, "config", "fgo_fusion.yaml"])),
        DeclareLaunchArgument("lookup_backend", default_value="cuda"),
        DeclareLaunchArgument("profile_timings", default_value="false"),
        DeclareLaunchArgument("scan_corner_leaf", default_value="0.2"),
        DeclareLaunchArgument("scan_surf_leaf", default_value="0.4"),
        DeclareLaunchArgument("local_map_radius", default_value="35.0"),
        DeclareLaunchArgument("max_iterations", default_value="20"),

        fixed_map,
        Node(
            package="loam_fgo_localization", executable="gps_measurement_node",
            name="gps_measurement", output="screen",
            parameters=[fgo_config, {"use_sim_time": use_sim_time}],
        ),
        Node(
            package="loam_fgo_localization", executable="fgo_fusion_node",
            name="fgo_fusion", output="screen",
            parameters=[fgo_config, {"use_sim_time": use_sim_time}],
        ),
    ])

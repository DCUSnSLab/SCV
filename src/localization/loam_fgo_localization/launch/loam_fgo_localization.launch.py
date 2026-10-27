#!/usr/bin/env python3
# 전체 파이프라인: LOCAL(local.launch.py) + GLOBAL(기본 FGO).
#   fusion_mode:=anchor selects the anchor fusion instead of FGO.
#   REP-105:  map --(global: FGO)--> odom --(local)--> base_link
#
#   ros2 launch loam_fgo_localization loam_fgo_localization.launch.py \
#       env:=real use_sim_time:=false
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, PythonExpression
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare("loam_fgo_localization")
    use_sim_time = LaunchConfiguration("use_sim_time")
    env = LaunchConfiguration("env")
    global_launch = PythonExpression([
        "{'fgo': 'global_fgo.launch.py', 'anchor': 'global_anchor.launch.py'}['", LaunchConfiguration("fusion_mode"), "']"])

    def inc(name, extra=None):
        args = {"use_sim_time": use_sim_time, "env": env}
        if extra:
            args.update(extra)
        return IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([pkg, "launch", name])),
            launch_arguments=args.items())

    return LaunchDescription([
        DeclareLaunchArgument("use_sim_time", default_value="false"),
        DeclareLaunchArgument("env", default_value="real", choices=["sim", "real"]),
        DeclareLaunchArgument("fusion_mode", default_value="fgo",
                              choices=["fgo", "anchor"]),
        DeclareLaunchArgument("map_dir", default_value="/home/nev/VNR_devel/SCV/maps/d2_20260813_v2",
                              description="Map bundle directory (full_corner.pcd, full_surf.pcd)"),
        DeclareLaunchArgument(
            "localizer_config",
            default_value=PathJoinSubstitution(
                [pkg, "config", "fixed_map_localization_bundle.yaml"])),
        DeclareLaunchArgument(
            "fgo_config",
            default_value=PathJoinSubstitution([pkg, "config", "fgo_fusion.yaml"])),
        DeclareLaunchArgument(
            "anchor_config",
            default_value=PathJoinSubstitution([pkg, "config", "anchor_fusion.yaml"])),
        DeclareLaunchArgument("pcd_prepare_node_id", default_value=""),
        DeclareLaunchArgument("pcd_entry_node_id", default_value=""),
        DeclareLaunchArgument("pcd_exit_node_id", default_value=""),

        # LOCAL: odom->base_link
        inc("local.launch.py"),
        # GLOBAL은 하나만 실행하여 map->odom 발행자가 겹치지 않게 한다.
        inc(global_launch, {
            "map_dir": LaunchConfiguration("map_dir"),
            "localizer_config": LaunchConfiguration("localizer_config"),
            "fgo_config": LaunchConfiguration("fgo_config"),
            "anchor_config": LaunchConfiguration("anchor_config"),
            "pcd_prepare_node_id": LaunchConfiguration("pcd_prepare_node_id"),
            "pcd_entry_node_id": LaunchConfiguration("pcd_entry_node_id"),
            "pcd_exit_node_id": LaunchConfiguration("pcd_exit_node_id"),
        }),
    ])

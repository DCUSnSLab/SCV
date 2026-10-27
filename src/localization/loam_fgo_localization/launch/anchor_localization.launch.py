#!/usr/bin/env python3
# 전체 파이프라인 (앵커링 버전): LOCAL(local.launch.py) + GLOBAL(global_anchor.launch.py).
#   REP-105:  map --(global: anchor[RTK EKF + PCD 이벤트 앵커])--> odom --(local ESKF)--> base_link
#   FGO 버전(fgo_localization.launch.py) 의 대체 (A/B 비교용으로 둘 다 유지).
#
#   ros2 launch loam_fgo_localization anchor_localization.launch.py \
#       env:=real use_sim_time:=true
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare("loam_fgo_localization")
    use_sim_time = LaunchConfiguration("use_sim_time")
    env = LaunchConfiguration("env")

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
        DeclareLaunchArgument("map_dir", default_value="/home/nev/VNR_devel/SCV/maps/d2_20260813_v2",
                              description="Map bundle directory (full_corner.pcd, full_surf.pcd)"),
        DeclareLaunchArgument(
            "localizer_config",
            default_value=PathJoinSubstitution(
                [pkg, "config", "fixed_map_localization_bundle.yaml"])),
        DeclareLaunchArgument(
            "anchor_config",
            default_value=PathJoinSubstitution([pkg, "config", "anchor_fusion.yaml"])),

        # LOCAL: odom->base_link (기존 그대로)
        inc("local.launch.py"),
        # GLOBAL: map->odom (앵커링: RTK EKF + 검증된 PCD 이벤트 앵커)
        inc("global_anchor.launch.py", {
            "map_dir": LaunchConfiguration("map_dir"),
            "localizer_config": LaunchConfiguration("localizer_config"),
            "anchor_config": LaunchConfiguration("anchor_config"),
        }),
    ])

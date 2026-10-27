#!/usr/bin/env python3
# GLOBAL 계층 (앵커링 버전): fixed-map PCD localizer + GPS frontend + anchor manager.
#   FGO(global_fgo.launch.py) 의 대체 — RTK 주 소스 3-상태 EKF, RTK 상실 시
#   검증된 PCD 만 이벤트성 map->odom 앵커. RTK 구간에도 PCD 연산은 유지하며
#   신뢰 캘리브레이션 수행. local(odom->base_link)은 별도.
#
#   ros2 launch loam_fgo_localization global_anchor.launch.py use_sim_time:=true
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare("loam_fgo_localization")
    use_sim_time = LaunchConfiguration("use_sim_time")
    anchor_config = LaunchConfiguration("anchor_config")

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
            # 앵커링 스택에도 mode manager 가 없으므로 시작부터 처리 활성.
            # RTK 구간에도 PCD 연산 유지 (신뢰 캘리브레이션) — 끄지 않는다.
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
            "anchor_config",
            default_value=PathJoinSubstitution([pkg, "config", "anchor_fusion.yaml"])),
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
            parameters=[anchor_config, {"use_sim_time": use_sim_time}],
        ),
        Node(
            package="loam_fgo_localization", executable="anchor_manager_node",
            name="anchor_manager", output="screen",
            parameters=[anchor_config, {"use_sim_time": use_sim_time}],
        ),
    ])

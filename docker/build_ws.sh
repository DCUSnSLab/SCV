#!/usr/bin/env bash
# 컨테이너 내부에서 SCV 워크스페이스를 빌드한다.
# - rosdep 으로 의존성 자동 설치
# - 워크스페이스에 포함되지 않은 외부 드라이버/메시지(--skip-keys)는 건너뜀
# - ZED SDK 미설치 시 zed_* 패키지 제외
# - 첫 실패에서 멈추지 않고 끝까지 빌드(--continue-on-error)
set -e

WS=/ws
cd "$WS"

source /opt/ros/humble/setup.bash

# --- ZED SDK 가 없으면 zed 패키지를 건너뛴다 ---------------------------------
ZED_PKGS=""
if [ ! -d /usr/local/zed ]; then
    echo "[build_ws] ZED SDK 미감지 -> zed_wrapper / zed_components / zed_ros2 제외"
    ZED_PKGS="zed_wrapper zed_components zed_ros2"
fi

# --- 워크스페이스에 소스가 없는 외부 의존성(rosdep 미해결 키) -----------------
# livox_ros_driver2 : fast_lio (Livox LiDAR 드라이버, 미포함)
# nev_teleop_bot_msgs: hunter_teleop_mux (nev_teleop_bot 저장소 클론 실패)
# iahrs_ros2        : bring_up (iAHRS IMU 드라이버, 미포함 / launch 전용)
# ament_python      : 일부 perception 패키지의 잘못된 <depend> 표기(무해)
MISSING_KEYS="livox_ros_driver2 nev_teleop_bot_msgs iahrs_ros2 ament_python"

echo "[build_ws] rosdep 의존성 설치..."
sudo apt-get update
rosdep install --from-paths src --ignore-src -r -y \
    --skip-keys "librealsense2 ${ZED_PKGS} ${MISSING_KEYS}" || true

echo "[build_ws] colcon build..."
IGNORE_ARG=""
[ -n "$ZED_PKGS" ] && IGNORE_ARG="--packages-ignore $ZED_PKGS"

colcon build --symlink-install --continue-on-error \
    --cmake-args -DCMAKE_BUILD_TYPE=Release \
    $IGNORE_ARG

echo "[build_ws] 완료. 'source install/setup.bash' 로 사용하세요."

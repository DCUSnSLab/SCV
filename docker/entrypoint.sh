#!/usr/bin/env bash
# ROS 2 환경을 source 한 뒤 전달된 명령을 실행한다.
set -e

source /opt/ros/humble/setup.bash

# 워크스페이스가 이미 빌드되어 있으면 overlay 도 source
if [ -f /ws/install/setup.bash ]; then
    source /ws/install/setup.bash
fi

exec "$@"

# SCV (Self-driving Campus Vehicle) - ROS 2 Humble 개발 컨테이너
# base: desktop-full (RViz2/RQt/Gazebo 포함) + NVIDIA GPU 런타임
FROM osrf/ros:humble-desktop-full

ARG DEBIAN_FRONTEND=noninteractive

# 호스트 사용자와 UID/GID를 맞춰 마운트된 워크스페이스 파일 권한 문제 방지
ARG USERNAME=scv
ARG USER_UID=1001
ARG USER_GID=1002

# ---------------------------------------------------------------------------
# 1) 기본 빌드/개발 도구 + ROS 개발 도구
# ---------------------------------------------------------------------------
RUN apt-get update && apt-get install -y --no-install-recommends \
        locales sudo curl gnupg2 lsb-release ca-certificates \
        build-essential cmake git wget vim nano tmux \
        usbutils iproute2 can-utils udev \
        python3-pip python3-colcon-common-extensions \
        python3-rosdep python3-vcstool \
        ros-dev-tools \
        libeigen3-dev libpcl-dev nlohmann-json3-dev \
    && locale-gen en_US en_US.UTF-8 \
    && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 \
    && rm -rf /var/lib/apt/lists/*

ENV LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8

# ---------------------------------------------------------------------------
# 2) Intel RealSense SDK (librealsense2) - realsense-ros 4.56.x 페어링
#    RealSense AI 분리 후 교체된 신규 서명키(2025-11)를 빌드 컨텍스트에서 주입.
#    (librealsense.intel.com 의 librealsense.pgp 는 아직 구 키를 서빙하여 검증 실패함)
# ---------------------------------------------------------------------------
COPY keys/librealsense.gpg /etc/apt/keyrings/librealsense.gpg
RUN echo "deb [signed-by=/etc/apt/keyrings/librealsense.gpg] https://librealsense.intel.com/Debian/apt-repo $(lsb_release -cs) main" \
        > /etc/apt/sources.list.d/librealsense.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
        librealsense2-dev librealsense2-utils \
    && rm -rf /var/lib/apt/lists/*

# ---------------------------------------------------------------------------
# 3) 호스트 UID/GID와 일치하는 비루트 사용자 생성 (sudo 무비번)
# ---------------------------------------------------------------------------
RUN (getent group ${USER_GID} || groupadd --gid ${USER_GID} ${USERNAME}) \
    && (id -u ${USER_UID} >/dev/null 2>&1 \
        || useradd --uid ${USER_UID} --gid ${USER_GID} -m -s /bin/bash ${USERNAME}) \
    && usermod -aG dialout,plugdev,video,sudo $(id -un ${USER_UID}) \
    && echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/${USERNAME} \
    && chmod 0440 /etc/sudoers.d/${USERNAME}

# ---------------------------------------------------------------------------
# 4) NVIDIA GPU + OpenGL(RViz/Gazebo 하드웨어 가속) 환경 변수
# ---------------------------------------------------------------------------
ENV NVIDIA_VISIBLE_DEVICES=all \
    NVIDIA_DRIVER_CAPABILITIES=all \
    QT_X11_NO_MITSHM=1

# rosdep 초기화 (이미 base 이미지에서 init 되어 있을 수 있으므로 실패 무시)
RUN rosdep init 2>/dev/null || true

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

USER ${USERNAME}
WORKDIR /ws
RUN rosdep update || true

# bash 진입 시 ROS 환경 자동 source
RUN echo "source /opt/ros/humble/setup.bash" >> /home/${USERNAME}/.bashrc \
    && echo "[ -f /ws/install/setup.bash ] && source /ws/install/setup.bash" >> /home/${USERNAME}/.bashrc

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]

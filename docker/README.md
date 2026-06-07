# SCV Docker 개발 환경 (ROS 2 Humble)

호스트에 ROS 2 를 설치하지 않고, 컨테이너 안에서 SCV 워크스페이스를 빌드/실행하기 위한 환경입니다.

- **베이스**: `osrf/ros:humble-desktop-full` (RViz2 / RQt / Gazebo 포함)
- **GPU**: NVIDIA 런타임 (RViz·Gazebo 가속, perception)
- **센서 SDK**: Intel RealSense(librealsense2), Velodyne, GNSS(ublox/ntrip), CAN(can-utils)
- **제외**: ZED SDK (미설치) → `zed_*` 패키지는 빌드에서 자동 제외. 사용하려면 아래 "ZED" 절 참고.

```
docker/
├── Dockerfile          # 이미지 정의
├── docker-compose.yml  # 컨테이너 실행 정의 (네트워크/GPU/디바이스/X11/볼륨)
├── entrypoint.sh       # ROS 환경 source 후 명령 실행
├── build_ws.sh         # 컨테이너 내부 워크스페이스 빌드 헬퍼
└── README.md
```

저장소 루트(`/ws`)가 컨테이너에 마운트되므로, **소스 편집은 호스트에서, 빌드/실행은 컨테이너에서** 합니다.

---

## 0. 사전 준비 (호스트, 최초 1회)

현재 사용자가 `docker` 그룹에 없어 daemon 접근이 막혀 있습니다. 아래를 **호스트에서** 실행하세요:

```bash
sudo usermod -aG docker $USER
# 그룹 반영을 위해 재로그인하거나:
newgrp docker
docker ps   # 권한 OK 확인
```

GUI(RViz 등)를 띄우려면 X11 접근 허용:

```bash
xhost +local:docker
```

---

## 1. 이미지 빌드

```bash
cd docker
# 호스트 UID/GID 를 이미지에 전달 (마운트 파일 권한 일치)
HOST_UID=$(id -u) HOST_GID=$(id -g) docker compose build
```

## 2. 컨테이너 진입

```bash
cd docker
docker compose up -d
docker compose exec scv bash
```

## 3. 워크스페이스 빌드 (컨테이너 내부)

```bash
# 컨테이너 쉘에서
/ws/docker/build_ws.sh
# 또는 수동으로
source /opt/ros/humble/setup.bash
rosdep install --from-paths src --ignore-src -r -y --skip-keys "librealsense2 zed_wrapper zed_components zed_ros2"
colcon build --symlink-install --packages-ignore zed_wrapper zed_components zed_ros2
source install/setup.bash
```

## 4. 실행 예시

```bash
# 차량 베이스 + teleop mux + URDF
ros2 launch bring_up hunter_start.launch.py
# GNSS(RTK)
ros2 launch bring_up gnss_start.launch.py
# RealSense 듀얼 카메라
ros2 launch bring_up rs_dual.launch.py
# RViz
rviz2 -d /ws/config/rviz/test_rviz.rviz
```

## 종료

```bash
docker compose down
```

---

## 디바이스 / 네트워크 메모

- `network_mode: host` + `ipc: host` : ROS 2 DDS 디스커버리와 센서 통신용.
- `privileged: true` + `/dev` 마운트 : LiDAR(USB/이더넷), CAN, GNSS/IMU 시리얼 접근용.
- **CAN(Hunter 차량)** 은 컨테이너가 아니라 **호스트에서** 인터페이스를 올려야 합니다:
  ```bash
  sudo ip link set can0 type can bitrate 500000
  sudo ip link set up can0
  ```
  (host 네트워크 모드라 컨테이너에서 그대로 `can0` 사용 가능)

## ZED 카메라를 쓰려면

1. 호스트/이미지에 맞는 [ZED SDK](https://www.stereolabs.com/developers/release) 설치 후 `/usr/local/zed` 존재
2. `build_ws.sh` 가 자동 감지하여 `zed_*` 패키지를 빌드에 포함
   - 또는 Dockerfile 에 ZED SDK 설치 단계를 추가

## 누락된 submodule

- `src/teleop/nev_teleop_bot` : 원격 저장소(`github.com/nevlife/nev_teleop_bot`)가 존재하지 않아 클론 실패.
  비어 있어 colcon 빌드에는 영향 없음. 저장소 접근 권한/새 URL 확인 필요.

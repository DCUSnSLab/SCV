# SCV — Self-driving Campus Vehicle

대구가톨릭대 SnSLab의 **Hunter 2.0 UGV 기반 자율주행 ROS 2 (Humble)** 메타 워크스페이스입니다.
센서·차량·측위·인지·제어 스택을 git submodule 로 묶고, 최상위 `bring_up` 패키지가
이들을 조립(integration)합니다.

```
호스트(ROS2 미설치) ──> Docker 컨테이너(ROS 2 Humble) ──> colcon 워크스페이스(/ws)
```

---

## 빠른 시작 (Quickstart)

```bash
# 1) 저장소 + submodule
git clone https://github.com/DCUSnSLab/SCV.git
cd SCV
./tools/init_workspace.sh            # submodule 초기화(소실 모듈 자동 skip)

# 2) Docker 이미지 빌드 & 진입
cd docker
HOST_UID=$(id -u) HOST_GID=$(id -g) docker compose build
docker compose up -d && docker compose exec scv bash

# 3) 워크스페이스 빌드 (컨테이너 내부)
/ws/docker/build_ws.sh
source /ws/install/setup.bash
```

자세한 컨테이너/디바이스/GPU/ZED 사용법은 **[`docker/README.md`](docker/README.md)** 참고.

---

## 아키텍처

시스템은 두 계층으로 나뉩니다.

```
┌───────────────────────── 하드웨어 계층 (bring_up) ─────────────────────────┐
│  차량(Hunter)   센서(LiDAR/IMU/GNSS/Camera)   측위(dual-EKF, fast_lio)       │
└───────────────────────────────────────────────────────────────────────────┘
                                   │  odometry/global, TF, 센서 토픽
                                   ▼
┌──────────────────── 자율주행 두뇌 (command_center) ────────────────────────┐
│  맵서버(gmserver)  전역경로(scv_global_planner)  행동계획  제어(MPPI)         │
└───────────────────────────────────────────────────────────────────────────┘
```

- **하드웨어 계층** = 이 저장소의 `bring_up` 패키지가 담당 (아래 "통합 launch").
- **자율주행 두뇌** = `command_center` submodule. 하드웨어 기동 후 별도 실행:
  `ros2 launch command_center_launch system.launch.py`

### 저장소 레이아웃

```
src/
├── bring_up/            # ★ 통합 launch (이 저장소 직접 관리)
├── sensor_pkg/          # velodyne, vectornav, ublox, ntrip, realsense, multi_fisheye, zed
├── vehicle/             # hunter_ros2(base/teleop_mux/msgs), hunter2_description, ugv_sdk
├── localization/        # robot_localization(dual-EKF), FAST_LIO_ROS2, tiny_localization
├── perception/          # SCV_Perception (탐지/추적/신호등 ROI 등)
├── command_center/      # 맵/전역경로/행동계획/제어 (자율주행 두뇌)
├── conversion/          # pointcloud_to_laserscan
├── monitoring/          # system_monitor
└── teleop/              # nev_teleop_bot (※ 원격 저장소 소실, DEPENDENCIES.md 참고)
config/                  # 설정 인덱스 (config/README.md)
docs/                    # localization_study.md
docker/                  # 개발 컨테이너
tools/                   # init_workspace.sh, manage-submodules.sh, data_viewer/
```

---

## 통합 launch (bring_up)

| launch | 내용 |
|--------|------|
| `scv_bringup.launch.py` | **최상위**: 차량 + 센서 + 측위 일괄 기동 (서브시스템 토글) |
| `sensors.launch.py` | LiDAR + IMU + GNSS + 카메라 (`use_*` 토글) |
| `localization.launch.py` | dual-EKF + 선택적 fast_lio + pointcloud→laserscan |
| `lidar.launch.py` | Velodyne (`lidar_model:=VLP16\|VLP32C\|VLS128`) |
| `imu.launch.py` | VectorNav |
| `hunter_start.launch.py` | Hunter base + teleop mux + URDF |
| `gnss_start.launch.py` | ublox_gps + ntrip(RTK) + nmea_init |
| `rs_dual.launch.py` | RealSense 듀얼(전/후방) |

```bash
# 전체 기동
ros2 launch bring_up scv_bringup.launch.py

# 차량만 (센서/측위 제외)
ros2 launch bring_up scv_bringup.launch.py use_sensors:=false use_localization:=false

# 카메라 제외 + VLP32C 라이다 + fast_lio 사용
ros2 launch bring_up scv_bringup.launch.py use_cameras:=false lidar_model:=VLP32C use_fast_lio:=true
```

---

## 의존성 / 빌드 메모

- 대부분의 의존성은 컨테이너에서 `rosdep` 으로 자동 해결됩니다.
- ZED SDK, Livox 드라이버(`livox_ros_driver2`), iAHRS IMU 등 **워크스페이스에 없는 외부 의존성**과
  **소실된 submodule(`nev_teleop_bot`)** 처리는 **[`DEPENDENCIES.md`](DEPENDENCIES.md)** 참고.
- `docker/build_ws.sh` 가 ZED 패키지 제외 및 미해결 rosdep 키 skip 을 자동 처리합니다.
  현재 51개 중 48개 패키지가 빌드됩니다(ZED 3개 제외).

## 측위 설계 문서

EKF/UKF/CKF/PF 비교, GPS 품질 등급별 융합 전략, 시스템 취약점 분석:
**[`docs/localization_study.md`](docs/localization_study.md)**

## 라이선스

각 submodule 은 자체 라이선스를 따릅니다. 본 메타 저장소의 직접 관리 코드(`bring_up`, `tools` 등)는
Apache-2.0 를 따릅니다.

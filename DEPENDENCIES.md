# 외부 의존성 (External Dependencies)

워크스페이스(`src/`)에 **소스가 포함되지 않은** 외부 의존성 목록입니다.
`docker/Dockerfile` 과 `docker/build_ws.sh` 가 대부분을 처리하지만, 일부는
하드웨어/SDK 사정상 수동 설치 또는 의도적 제외가 필요합니다.

> 대부분의 ROS 패키지 의존성은 컨테이너에서 `rosdep install` 로 자동 해결됩니다.
> 아래는 rosdep 으로 해결되지 **않거나** 별도 처리가 필요한 항목만 정리합니다.

## 요약

| 의존성 | 필요한 패키지 | 상태 | 처리 방식 |
|--------|--------------|------|-----------|
| `librealsense2` | realsense2_camera | apt(Intel repo) | Dockerfile 에서 설치 (신규 서명키 주입) |
| `nlohmann_json` | gmserver (command_center) | apt | Dockerfile 에 `nlohmann-json3-dev` 추가 |
| `livox_ros_driver2` | fast_lio | **미포함** | Velodyne 사용 시 불필요 → build 시 skip-keys |
| `iahrs_ros2` | bring_up (launch 전용) | **미포함** | IMU로 iAHRS 사용 시에만 필요. 현재 vectornav 사용 |
| ZED SDK | zed_wrapper/components/ros2 | **미설치** | 무거움/CUDA 의존 → 기본 빌드 제외. 아래 절 참고 |
| `nev_teleop_bot_msgs` | hunter_teleop_mux | **저장소 소실** | nev_teleop_bot submodule 클론 불가. 아래 절 참고 |

`docker/build_ws.sh` 는 위 미해결 키들을 `rosdep --skip-keys` 로 우회하고,
ZED 패키지는 `--packages-ignore` 로 제외하여 나머지 48개 패키지를 빌드합니다.

---

## 소실된 submodule: `nev_teleop_bot`

- `.gitmodules` 의 `src/teleop/nev_teleop_bot`
  (`github.com/nevlife/nev_teleop_bot`, branch `main`) 는 현재 **"Repository not found"**.
- 영향: 일반 `git submodule update --init --recursive` 가 이 지점에서 중단됨.
  → **`./tools/init_workspace.sh`** 를 사용하면 이 모듈을 건너뛰고 나머지를 초기화.
- 빌드 영향: `hunter_teleop_mux` 가 `nev_teleop_bot_msgs` 를 찾지 못함(빌드는 skip-keys로 우회).
  teleop mux 를 실제로 쓰려면 저장소를 복구하고 `.gitmodules` 의 URL/접근권한을 갱신해야 함.
- **권장**: 이 저장소를 조직 계정(DCUSnSLab)으로 이전/복구하여 `.gitmodules` URL 을 갱신.

## 개인 계정에 의존하는 submodule (가용성 위험)

17개 submodule 중 5개가 개인 계정(`nevlife`) 소속이라, 계정/저장소 정책에 따라
가용성이 흔들릴 수 있습니다(실제로 `nev_teleop_bot` 이 그 사례). 장기적으로 조직 계정으로의
이전(fork-in-org)을 권장합니다.

| submodule | 출처 |
|-----------|------|
| src/sensor_pkg/multi_fisheye | nevlife |
| src/localization/robot_localization | nevlife |
| src/localization/FAST_LIO_ROS2 | nevlife |
| src/monitoring/system_monitor | nevlife |
| src/teleop/nev_teleop_bot | nevlife (소실) |

---

## ZED 카메라를 사용하려면

기본 환경에서는 ZED SDK 가 무겁고 CUDA 버전에 강하게 의존하므로 제외했습니다.
사용하려면:

1. 컨테이너 베이스 CUDA 와 맞는 [ZED SDK](https://www.stereolabs.com/developers/release) 설치
   (Dockerfile 에 설치 단계를 추가하거나, 컨테이너 안에서 직접 설치 후 `/usr/local/zed` 생성).
2. `docker/build_ws.sh` 가 `/usr/local/zed` 존재를 감지하면 `zed_*` 패키지를 자동으로 빌드에 포함합니다.

## fast_lio + Livox LiDAR 를 사용하려면

현재는 Velodyne 기준이라 `livox_ros_driver2` 가 없어도 빌드됩니다.
Livox LiDAR 를 쓰려면 [`livox_ros_driver2`](https://github.com/Livox-SDK/livox_ros_driver2) 와
Livox-SDK2 를 워크스페이스/시스템에 추가하고, `build_ws.sh` 의 skip-keys 에서 제거하세요.

## iAHRS IMU 를 사용하려면

`bring_up/package.xml` 에 `iahrs_ros2` exec_depend 가 있으나 현재 워크스페이스에는 없습니다.
기본 IMU 는 vectornav(VN-시리즈)입니다. iAHRS 를 쓰려면 해당 드라이버 패키지를 추가하세요.

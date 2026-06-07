# config — 설정 인덱스

SCV는 메타 저장소 구조라, **각 서브시스템의 실제 파라미터는 해당 submodule 안에**
버전관리됩니다. 이 디렉토리는 (1) 최상위에서 공유하는 설정과 (2) 흩어진 설정의
**위치 인덱스**를 제공합니다.

## 최상위 설정

| 파일 | 용도 |
|------|------|
| `realsense_config.yaml` | RealSense 공통 파라미터(global_time/sync 비활성) |

## 서브시스템별 실제 파라미터 위치

| 서브시스템 | 경로 | 핵심 파일 |
|-----------|------|-----------|
| 측위(EKF/GPS) | `src/localization/robot_localization/params/` | `dual_ekf_navsat.yaml`, `navsat_transform.yaml`, `ekf.yaml`, `gps_manager.yaml` |
| LiDAR odom | `src/localization/FAST_LIO_ROS2/config/` | velodyne/livox 프로파일 |
| tiny_localization | `src/localization/tiny_localization/config/` | `config.yaml`, `config_sim.yaml` |
| IMU(VectorNav) | `src/sensor_pkg/vectornav/vectornav/config/` | `vectornav.yaml` |
| GNSS(ublox) | `src/sensor_pkg/ublox/ublox_gps/config/` | ublox 디바이스 설정 |
| LiDAR(Velodyne) | `src/sensor_pkg/velodyne/velodyne_*/config/` | 모델별 calibration |
| 차량(Hunter) | `src/vehicle/hunter_ros2/hunter_base/` | base/teleop mux 설정 |
| command_center | `src/command_center/{controller,costmap,...}/` | MPPI/costmap/planner 파라미터 |

> 측위 튜닝 배경과 GPS 품질 전략은 [`../docs/localization_study.md`](../docs/localization_study.md) 참고.

## 통합 bringup 과의 관계

`bring_up` 의 launch(`scv_bringup.launch.py` 등)는 위 submodule launch 를 포함하며,
각 submodule launch 가 자신의 config 디렉토리에서 파라미터를 읽습니다. 최상위에서
오버라이드가 필요하면 해당 launch 의 `*_params_file` 류 인자를 통해 이 디렉토리의
파일을 지정하세요(서브시스템마다 지원 여부 상이).

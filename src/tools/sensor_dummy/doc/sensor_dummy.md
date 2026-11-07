# sensor_dummy

하드웨어 없이 스택을 돌리기 위한 더미 센서와 더미 차량이다. 토픽 이름, 메시지 타입, `frame_id`, 주기는 실제 드라이버 코드에서 가져왔다.

| 노드                          | 내용                                                                                     |
| ----------------------------- | ---------------------------------------------------------------------------------------- |
| `sensor_sim` (C++ 컴포넌트)   | 차량 상태 하나를 2D 지도 위에서 적분하고, 그 상태로 라이다, IMU, GNSS, Hunter, TF를 낸다 |
| `camera_dummy` (C++ 컴포넌트) | 카메라 하나의 형식으로 테스트 패턴을 낸다. 어떤 카메라인지는 전부 파라미터다             |

두 컴포넌트는 `component_container_isolated` 하나에 뜬다. 노드마다 스레드가 따로 있어 raycasting이 카메라를 늦추지 않는다.

## 실행

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 launch sensor_dummy sensor_dummy.launch.py ground_truth:=true cameras:=d435i
```

| 인자           | 기본                            | 내용                                                                                           |
| -------------- | ------------------------------- | ---------------------------------------------------------------------------------------------- |
| `sim`          | `true`                          | `false`면 카메라만 띄운다                                                                      |
| `outputs`      | `lidar,imu,gnss,hunter,odom,tf` | 켤 `sensor_sim` 출력이다                                                                       |
| `cameras`      | 없음                            | `config/cameras.yaml`의 인스턴스나 그룹이다. 쉼표로 구분한다. 그룹은 `d435_tri`, `zedxone`이다 |
| `motion_model` | `ackermann`                     | `ackermann` 또는 `diff`다                                                                      |
| `map_file`     | `config/sidewalk_map.yaml`      | 벽과 상자가 있는 지도다                                                                        |
| `ground_truth` | `false`                         | `true`면 참값을 `/odometry/global`로 낸다. localization 없이 시험할 때 쓴다                    |
| `odom_topic`   | `/odom`                         | catalog의 이름이다. `hunter_start.launch.py`의 실제 이름은 `/odometry/wheel`이다               |
| `robot_model`  | `true`                          | `hunter2_description`의 `display.launch.py`를 함께 띄워 장착 TF를 낸다                         |

- 실제 EKF를 같이 띄울 때는 `outputs`에서 `tf`를 뺀다. EKF가 `map -> odom -> base_link`를 내기 때문이다. 이때 `ground_truth`도 `false`로 둔다.
- 다른 빌드 위치에서는 `colcon build --symlink-install --packages-up-to sensor_dummy`로 빌드한다. `flux`와 `realsense2_camera_msgs`까지 함께 빌드된다. `hunter2_description`이 `realsense2_description`에 실행 의존하기 때문이다.

## 토픽

### sensor_sim

| 토픽                                 | 타입                                       | `frame_id`                 | Hz  | 근거                                 |
| ------------------------------------ | ------------------------------------------ | -------------------------- | --- | ------------------------------------ |
| `/velodyne_points`                   | `sensor_msgs/PointCloud2`                  | `velodyne`                 | 10  | `lidar.param.yaml` rpm 600           |
| `/vectornav/imu`                     | `sensor_msgs/Imu`                          | `vectornav`                | 20  | catalog                              |
| `/vectornav/pose`                    | `geometry_msgs/PoseWithCovarianceStamped`  | `earth`                    | 20  | catalog, `vn_sensor_msgs.cc`         |
| `/ublox_gps_node/fix`                | `sensor_msgs/NavSatFix`                    | `gnss_antenna`             | 10  | `zed_f9p.yaml`                       |
| `/ublox_gps_node/fix_velocity`       | `geometry_msgs/TwistWithCovarianceStamped` | `gnss_antenna`             | 10  | `ublox_firmware7plus.hpp`            |
| `/ublox_gps_node/navpvt`, `/navpvt`  | `ublox_msgs/NavPVT`                        | 없음                       | 10  | 코드는 앞쪽, catalog는 뒤쪽 이름이다 |
| `/rxmrtcm`                           | `ublox_msgs/RxmRTCM`                       | 없음                       | 1   | 주기는 가정이다                      |
| `/hunter_status`                     | `hunter_msgs/HunterStatus`                 | 빈 문자열                  | 50  | `hunter_messenger.hpp`               |
| `/hunter/velocity`, `/current_speed` | `std_msgs/Float64`                         | 없음                       | 50  | `hunter_base`의 변환 노드            |
| `/current_steer_angle`               | `std_msgs/Float64` (deg)                   | 없음                       | 50  | `hunter_state_parser_node.cpp`       |
| `/odom`                              | `nav_msgs/Odometry`                        | `odom`, child `base_link`  | 50  | `hunter_messenger.hpp`               |
| `/odometry/global`                   | `nav_msgs/Odometry`                        | `map`, child `base_link`   | 30  | `ground_truth:=true`일 때만 낸다     |
| `/tf`                                | `tf2_msgs/TFMessage`                       | `map -> odom -> base_link` | 50  |                                      |

입력은 `/final_cmd`(`geometry_msgs/Twist`) 하나다. 마지막 명령을 계속 유지한다. 실제 펌웨어의 명령 시간 초과는 코드에서 확인할 수 없어 넣지 않았다.

### camera_dummy

| 인스턴스                         | 토픽 접두사                | 스트림                                                                                                                        | Hz          |
| -------------------------------- | -------------------------- | ----------------------------------------------------------------------------------------------------------------------------- | ----------- |
| `d435i`                          | `/camera/d435i`            | `color/image_raw` 640x480 rgb8, `depth/image_rect_raw` 848x480 16UC1, `aligned_depth_to_color/image_raw` 640x480 16UC1, `imu` | 30, IMU 200 |
| `d435_left`, `_center`, `_right` | `/d435_<위치>/d435_<위치>` | `color/image_raw` 1280x720 rgb8, `depth/image_rect_raw` 848x480 16UC1                                                         | 15          |
| `zed2i`                          | `/zed/zed_node`            | `rgb/color/rect/image` 1280x720 bgra8, `depth/depth_registered` 1280x720 32FC1, `imu/data`                                    | 60, IMU 100 |
| `cam0`..`cam7`                   | `/cam<i>/zed_node`         | `rgb/color/rect/image` 1920x1200 bgra8, `imu/data`                                                                            | 30, IMU 100 |

- 영상마다 같은 주기의 `camera_info`가 있다. 위치는 `config/cameras.yaml`의 `info_topic`이다.
- `frame_id`는 실제 드라이버 규칙을 따른다. `d435i_color_optical_frame`, `zed_left_camera_frame_optical`, `cam<i>_camera_frame_optical`이다.
- 실제 드라이버처럼 구독자가 없는 영상은 만들지 않는다. `camera_info`와 IMU는 항상 낸다.
- 큰 영상은 reliable로 구독한다. best-effort에서는 UDP 조각 하나를 잃으면 영상 전체가 사라진다. 이 작업의 측정에서 1280x720 영상이 15 Hz에서 6 Hz로 떨어졌다.

## 차량 모델

```text
/final_cmd -> cmd_delay_s -> 한계 clamp -> dead band -> steer_bias_rad -> 1차 지연(speed_tau_s, steer_tau_s) -> 적분
```

- `ackermann`: 조향은 `hunter_messenger.hpp`의 `AngelVelocity2Angel`과 `ConvertInnerAngleToCentral`을 그대로 옮겼다. 안쪽 바퀴 각을 `max_steer_angle`로 자르는 것은 펌웨어 동작이라고 가정했다. 적분 기준점은 뒤차축이고, `base_link`는 그보다 0.28 m 앞이다.
- `diff`: `linear.x`와 `angular.z`를 그대로 따른다. 기준점은 `base_link`다.
- `track`, `wheelbase`, `max_steer_angle`, `max_linear_speed`는 `hunter_params.hpp`의 `HunterV2Params`다. launch 시험이 헤더와 yaml을 비교한다.
- `cmd_delay_s`, `speed_tau_s`, `steer_tau_s`는 측정값이 아니다. `hunter_ros2`에 지연 수치가 없다. 실제 차량의 step 응답으로 바꾼다.
- `speed_dead_band_mps`보다 작은 속도 명령과 `steer_dead_band_rad`보다 작은 중심 조향각은 0이 된다. 띠 밖의 값은 그대로 지난다. `speed_dead_band_mps`는 두 모델에 모두 적용한다.
- `steer_bias_rad`는 dead band 뒤의 조향 목표에 더한다. 조향 limit로 다시 자르지 않으므로 bias만큼 limit를 넘을 수 있다. `ackermann`만 쓴다.
- 세 값 모두 측정값이 아니다. 설정의 0은 "없음"을 뜻하는 자리값이고, 0이면 이전과 동작이 같다. 실제 차량의 값은 재지 않았다.
- 충돌은 없다. 차량은 벽을 통과한다. `/odom`의 pose는 참값이고, `twist.linear.y`는 실제 드라이버처럼 0이다.

## 지도와 라이다

`config/sidewalk_map.yaml` 형식은 다음과 같다. `base_link`가 지면에 있으므로 지면은 `z = 0`이다.

```yaml
ground: { z: 0.0, intensity: 20.0 }
walls:
  - { start: [x, y], end: [x, y], height: 2.5, thickness: 0.2, intensity: 60.0 }
boxes:
  - { center: [x, y], size: [lx, ly], yaw: 0.0, height: 1.2, intensity: 90.0 }
```

- 빔 각도는 `velodyne_pointcloud/params/VeloView-VLP-32C.yaml`을 빌드할 때 그대로 설치해 읽는다.
- 구름 형식은 `organize_cloud: true`의 실제 출력과 같다. width 32, height 1812, `point_step` 22, 필드는 `x y z intensity ring time`이다. 반환이 없으면 `x y z intensity`가 NaN이다.
- `header.stamp`는 스캔 시작 시각이다(`timestamp_first_packet: true`). 행마다 그 순간의 자세로 raycasting하므로 움직임 왜곡도 실제와 같은 방향으로 들어간다.
- `/velodyne_packets`는 내지 않는다.

`config/low_barrier_map.yaml`은 x = 12 m에서 보도를 막는 높이 0.30 m 턱이다. 가까이 서면 모든 빔이 그 위로 지나가므로 격자의 기억을 시험할 때 쓴다.

## GNSS와 IMU

- 실제 지도는 UTM에서 원점을 뺀 좌표다(`navsat_transform.param.yaml`). 위경도 변환도 UTM을 거친다. 실제 `navsat_transform_node`에 넣어 2 mm 안에서 참값과 맞는 것을 확인했다.
- VectorNav는 `use_enu: true`의 축이다. `vectornav` 프레임은 오른쪽-앞-위고, 자세는 ENU 기준이다. map에서 ENU로 meridian convergence만큼 돌린다.
- VN-100에는 INS가 없다. 그래서 `/vectornav/pose`의 위치는 항상 0이고, 자세는 위경도 0으로 계산한 ECEF 값이다. 드라이버 코드를 그대로 따른 결과다.

## 고장 주입

파라미터로 넣고 뺀다. 실행 중에 바꿀 수 있다.

```bash
ros2 param set /sensor_sim fault.imu.mode dropout
ros2 param set /sensor_sim fault.gnss.latency_s 0.5
ros2 param set /sensor_sim fault.gnss.mode latency
ros2 param set /d435i_dummy fault.mode freeze
ros2 param set /sensor_sim fault.imu.mode none
```

| `mode`    | 동작                                                              |
| --------- | ----------------------------------------------------------------- |
| `dropout` | 아무것도 내지 않는다                                              |
| `latency` | `latency_s`만큼 늦게 낸다. stamp는 원래 시각 그대로다             |
| `nan`     | 값을 NaN으로 바꾼다. 정수 메시지와 영상은 그 형식의 무효값을 쓴다 |
| `freeze`  | 값은 고정하고 stamp만 계속 갱신한다                               |

| 채널           | 묶인 토픽                                                                      |
| -------------- | ------------------------------------------------------------------------------ |
| `lidar`        | `/velodyne_points`                                                             |
| `imu`          | `/vectornav/imu`, `/vectornav/pose`                                            |
| `gnss`         | `/ublox_gps_node/*`, `/navpvt`, `/rxmrtcm`                                     |
| `hunter`       | `/hunter_status`, `/hunter/velocity`, `/current_speed`, `/current_steer_angle` |
| `odom`         | `/odom`                                                                        |
| `tf`           | `/tf`                                                                          |
| `ground_truth` | `/odometry/global`                                                             |

`nan`의 무효값은 다음과 같다. `NavPVT`는 fix 없음, `RxmRTCM`은 CRC 실패 표시, 8비트 영상과 16UC1 깊이는 0이다.

## 시험

```bash
colcon test --packages-select sensor_dummy
colcon test-result --verbose
```

| 시험                                        | 내용                                                                                                          |
| ------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| `test_sensor_dummy_core` (gtest)            | 차량 모델, raycasting, 구름 형식, IMU, GNSS, 고장, 테스트 패턴                                                |
| `test_launch_helpers` (pytest)              | URDF 장착값, 카메라 설정 해석                                                                                 |
| `test_sensor_dummy_launch` (launch_testing) | 실제 launch를 띄워 토픽별 타입, `frame_id`, 주기, TF, 폐루프, 고장 주입을 확인한다. `ROS_DOMAIN_ID=87`을 쓴다 |

## 안 되는 것

- `/velodyne_packets`, `/front/scan`, `/rear/scan`을 내지 않는다.
- RealSense의 `rgbd`, `depth/color/points`, `gyro/sample`, `accel/sample`, `metadata`, `extrinsics`, 압축 영상과 ZED의 point cloud를 내지 않는다.
- flux 경로가 없다. DDS만 지원한다.
- 잡음과 드리프트가 없다. 값은 결정적이다.
- `config/cameras.yaml`의 intrinsics는 크기만 맞춘 값이다. ZED 2i와 D435i의 장착 위치도 자리값이다.

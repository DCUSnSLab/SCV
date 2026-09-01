# SCV (Service Co-operation Vehicle)

캠퍼스 주행·서비스를 목표로 하는 자율주행 차량 스택. 이 저장소는 차량 탑재 워크스페이스의
**슈퍼프로젝트**로, 각 구성 요소(command_center, localization, perception, vehicle 등)를
서브모듈로 관리한다.

## 빌드

```bash
git clone --recurse-submodules https://github.com/DCUSnSLab/SCV
cd SCV
source /opt/ros/humble/setup.bash
colcon build   # 주의: --symlink-install 혼용 금지 (기존 빌드 캐시와 충돌)
source install/setup.bash
```

## Gazebo 시뮬레이션 내 차량 스폰

Gazebo용 차량 모델·스폰 구조는 별도 저장소
[**SCV_hunter_gazebo**](https://github.com/DCUSnSLab/SCV_hunter_gazebo)
(기본 브랜치 `gazebo_workspace`)에 명세되어 있다. 이 슈퍼프로젝트의 서브모듈이 아니므로
별도로 클론한다. 실차 URDF(`src/vehicle/hunter2_description`)와 가제보용
URDF(`hunter_description`)는 서로 다른 모델이다.

### 설치

```bash
sudo apt install -y ros-humble-gazebo-ros-pkgs ros-humble-gazebo-ros2-control \
  ros-humble-ros2-control ros-humble-ros2-controllers

git clone --recursive https://github.com/DCUSnSLab/SCV_hunter_gazebo
cd SCV_hunter_gazebo
rosdep install --from-paths src --ignore-src -r -y
colcon build && source install/setup.bash
```

### 스폰 실행

```bash
# 빈 월드(GPS 플러그인 포함)에 스폰 — 위치·방위 인자 지정 가능
ros2 launch scv_robot_gazebo hunter_empty_world.launch.py \
  spawn_x:=0.0 spawn_y:=0.0 spawn_z:=0.3 spawn_yaw:=0.0

# 캠퍼스 맵(OSM 유래 월드)에 스폰
ros2 launch scv_robot_gazebo hunter_test.launch.py
```

### 스폰 동작 구조

1. `hunter_with_one_box.urdf.xacro`를 xacro로 전개해 `robot_description` 토픽으로 발행
   (`robot_state_publisher`)
2. `gazebo_ros`의 `spawn_entity.py`가 해당 토픽을 읽어 엔티티 `hunter_only`를
   `spawn_x/y/z/yaw` 위치에 스폰
3. 스폰 완료 이벤트에 연동해 ros2_control 컨트롤러가 순차 활성화:
   `joint_state_broadcaster` → `ackermann_like_controller`

### 제어 토픽

구동 명령은 `/ackermann_like_controller/cmd_vel` (geometry_msgs/Twist).
main 계열 smppi 컨트롤러의 기본 cmd_vel 토픽이 이것과 일치하므로, 실스택 연동 시
별도 리매핑 없이 접속된다. 키보드 수동 제어:

```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard \
  --ros-args --remap cmd_vel:=/ackermann_like_controller/cmd_vel
```

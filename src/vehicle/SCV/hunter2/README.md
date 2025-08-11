# Hunter2 Robot Package - Single File Version

Hunter2는 4륜 Ackermann 조향 방식의 자율주행 로봇용 ROS2 패키지입니다. **단일 URDF 파일**로 GPS, IMU, VLP-32C 라이다 센서가 통합되어 있습니다.

## 🎯 **단일 파일 구조**

모든 로봇 정의가 **`robot_complete.urdf.xacro`** 한 파일에 포함되어 있습니다:

```
robot.urdf.xacro (메인 진입점)
└── robot_complete.urdf.xacro (모든 것이 포함된 단일 파일)
    ├── robot_core.xacro include
    ├── ros2_control.xacro include  
    ├── VLP-32C 매크로 (인라인 정의)
    ├── 센서 링크들 (GPS, IMU, 라이다)
    └── 박스 모델들 (front_box, back_box)
```

## 🚗 **패키지 특징**

- **4륜 Ackermann 조향** 방식
- **ROS2 Control** 통합
- **센서 통합**: GPS, IMU, VLP-32C LiDAR
- **RViz 시각화** 지원
- **단일 파일 구조** - 관리 편의성

## 📦 **포함된 센서**

1. **VLP-32C LiDAR**: 전면 박스에 장착 (`-0.036 0 0.162`)
2. **GNSS 안테나**: 후면 박스에 장착 (`0 0 0.15`)
3. **IMU 센서**: 섀시 중앙에 장착 (`0 0 0.05`)

## 🔧 **사용법**

### **🖥️ RViz 포함 실행**
```bash
# 기본 실행 (RViz + Joint State Publisher)
ros2 launch hunter2 display.launch.py

# Joint State Publisher GUI와 함께 실행
ros2 launch hunter2 display.launch.py jsp_gui:=true

# GPS 좌표 설정하여 실행
ros2 launch hunter2 display.launch.py gps_latitude:=37.5665 gps_longitude:=126.9780 gps_altitude:=50.0
```

### **🤖 로봇만 실행 (RViz 없이)**
```bash
# 기본 로봇 실행 (Joint State Publisher GUI 포함)
ros2 launch hunter2 robot.launch.py

# 로봇만 실행 (GUI 없이)
ros2 launch hunter2 robot_only.launch.py

# Joint State Publisher GUI와 함께
ros2 launch hunter2 robot_only.launch.py jsp_gui:=true
```

### **🧪 테스트 실행**
```bash
# 단일 파일 테스트
ros2 launch hunter2 test_single_file.launch.py
```

## 📋 **런치 파일별 기능**

| 런치 파일 | RViz | JSP GUI | 용도 |
|-----------|------|---------|------|
| `display.launch.py` | ✅ | ❌ (옵션) | 시각화 + 로봇 |
| `robot.launch.py` | ❌ | ✅ (기본) | 로봇 + GUI 제어 |
| `robot_only.launch.py` | ❌ | ❌ (옵션) | 순수 로봇만 |
| `test_single_file.launch.py` | ✅ | ❌ (옵션) | 테스트용 |

## 📋 **런치 파라미터**

| 파라미터 | 기본값 | 설명 |
|----------|--------|------|
| `description_file` | `robot.urdf.xacro` | URDF 파일명 |
| `jsp_gui` | 파일별 상이 | Joint State Publisher GUI 실행 여부 |
| `use_sim_time` | `false` | 시뮬레이션 시간 사용 여부 |
| `gps_latitude` | `37.5665` | GPS 기준 위도 (서울) |
| `gps_longitude` | `126.9780` | GPS 기준 경도 (서울) |
| `gps_altitude` | `50.0` | GPS 기준 고도 |

## 🎮 **제어 인터페이스**

### ROS2 Control 조인트
- **조향**: `front_left_steering_joint` (position control)
- **구동**: `rear_left_wheel_joint` (velocity control)
- **업데이트 주기**: 50Hz

### 토픽
- **조향 제어**: `/ackermann_like_controller/reference`
- **오도메트리**: `/ackermann_like_controller/odom`
- **조인트 상태**: `/joint_states`

## 📊 **로봇 스펙**

- **휠베이스**: 0.65m
- **트랙 폭**: 0.585m
- **최대 조향각**: ±26.4도 (0.461 rad)
- **휠 반지름**: 0.165m
- **전체 질량**: ~87kg (섀시 72kg + 바퀴 28kg + 센서)

## 📁 **파일 구조**

```
hunter2/
├── urdf/                    
│   ├── robot.urdf.xacro        # 메인 진입점
│   ├── robot_complete.urdf.xacro # 🎯 모든 것이 포함된 단일 파일
│   ├── robot_core.xacro        # 기본 로봇 구조
│   ├── ros2_control.xacro      # ROS2 Control 설정
│   ├── meshes.xacro           # 메시 매크로
│   └── inertial_macros.xacro  # 관성 데이터
├── meshes/                  # 3D 메시 파일들
├── launch/                  
│   ├── display.launch.py      # RViz 포함 실행
│   ├── robot.launch.py        # 로봇 + GUI 제어
│   ├── robot_only.launch.py   # 🆕 순수 로봇만 실행
│   └── test_single_file.launch.py # 테스트용
├── config/                  
│   └── ackermann_like_controller.yaml
└── rviz/                   
    └── robot_view.rviz
```

## 🔍 **센서 프레임**

- `base_footprint`: 지면 투영점
- `base_link`: 로봇 베이스
- `chassis`: 섀시
- `front_box`: 전면 박스
- `back_box`: 후면 박스
- `imu_link`: IMU 센서
- `gnss_antenna`: GPS 안테나
- `velodyne_base_link`: 라이다 베이스
- `velodyne`: 라이다 센서

## ✨ **장점**

1. **단일 파일 관리**: 모든 센서와 구조가 한 파일에
2. **의존성 최소화**: 외부 xacro 파일 의존성 감소
3. **배포 편의성**: 하나의 완전한 파일로 쉬운 공유
4. **디버깅 용이**: 한 곳에서 모든 정의 확인 가능
5. **다양한 실행 옵션**: RViz 유무, GUI 유무 선택 가능

## 🚀 **빌드 및 실행**

```bash
# 워크스페이스로 이동
cd ~/your_workspace

# 빌드
colcon build --packages-select hunter2

# 환경 설정
source install/setup.bash

# 용도별 실행
ros2 launch hunter2 display.launch.py      # 시각화
ros2 launch hunter2 robot.launch.py        # 로봇 + GUI
ros2 launch hunter2 robot_only.launch.py   # 로봇만
```

## 🎯 **사용 시나리오**

- **개발/디버깅**: `display.launch.py` (RViz 포함)
- **수동 제어**: `robot.launch.py` (GUI 포함)
- **자율 운행**: `robot_only.launch.py` (순수 로봇만)
- **테스트**: `test_single_file.launch.py`

이제 **용도에 맞는 런치 파일**을 선택해서 Hunter2 로봇을 실행할 수 있습니다! 🎯

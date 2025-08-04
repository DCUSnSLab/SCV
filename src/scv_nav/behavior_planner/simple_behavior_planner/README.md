# Simple Behavior Planner

간단한 행동 계획 모듈로 경로 옵션에 따른 차량 행동을 제어합니다.

## 기능

- **경로 옵션 처리**: SIGNAL, ACCELERATION, DECELERATION, NORMAL 옵션 지원
- **MPPI 파라미터 조정**: 상황에 따른 제어기 파라미터 동적 변경
- **신호등 대응**: 신호등 상태에 따른 정지/진행 판단
- **긴급 정지**: Perception에서 긴급 상황 감지 시 즉시 정지

## 토픽 인터페이스

### 구독 토픽
- `/path_list` (PathList): Global planner에서 전송하는 경로 리스트
- `/goal_reached` (Bool): Controller에서 목표 도달 신호
- `/traffic_light_state` (TrafficLightState): 신호등 상태 정보
- `/emergency_stop` (Bool): 긴급 정지 신호

### 발행 토픽  
- `/goal_pose` (PoseStamped): Controller에게 전송하는 목표점
- `/behavior_control` (BehaviorControl): Controller 파라미터 제어 명령

## 사용법

### 빌드
```bash
cd /home/d2-521-30/repo/SCV
colcon build --packages-select simple_behavior_planner
source install/setup.bash
```

### 실행
```bash
ros2 launch simple_behavior_planner simple_behavior_planner.launch.py
```

## 메시지 타입

- **PathOption**: 단일 경로 옵션 (위치, 옵션 타입, 목표 속도)
- **PathList**: 경로 옵션 리스트
- **BehaviorControl**: 제어기 파라미터 조정 명령
- **MPPIParams**: MPPI 제어기 파라미터
- **TrafficLightState**: 신호등 상태 정보

## 옵션 타입별 동작

- **NORMAL**: 기본 주행 파라미터 사용
- **ACCELERATION**: 속도 증가, 적극적 제어
- **DECELERATION**: 속도 감소, 안전 우선 제어  
- **SIGNAL**: 신호등 대기, 천천히 접근 후 신호 확인
# scv_logger

주행 로깅 GUI (녹화 프로파일, 토픽 상태 감시, 세션 기록).

```bash
# 빌드
cd ~/SCV
source /opt/ros/humble/setup.bash
colcon build --packages-select scv_logger scv_logger_monitor   # 감시 노드는 C++ (없으면 파이썬으로 대체)
source install/setup.bash

# GUI 실행
ros2 run scv_logger scv_logger

# 카탈로그 스캔 (지금 떠 있는 토픽·주기·크기)
ros2 run scv_logger scv_logger_scan --duration 5

# 테스트
cd src/tools/scv_logger && /usr/bin/python3 -m pytest test -q
```

- 설정: `config/catalog.yaml`, `config/profiles/*.yaml`
- 값 검사 (C++ 감시 노드만): 모든 토픽 header stamp(지연·역행·반복), IMU(전부 0·NaN/Inf), GNSS(위치 공분산),
  TF(NaN/Inf·쿼터니언). 기준은 카탈로그 `value_checks`.
  문제가 있으면 상태 `값 이상`, 녹화 중이면 자동 마커. 끄기: 감시 노드에 `--no-value-checks`
- 녹화 저장 경로: `~/ssd2/scv_logs` (GUI 설정 탭에서 변경)

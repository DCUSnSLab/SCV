# scv_logger

주행 로깅 GUI (녹화 프로파일, 토픽 상태 감시, 세션 기록).

```bash
# 빌드
cd ~/SCV
source /opt/ros/humble/setup.bash
colcon build --packages-select scv_logger
source install/setup.bash

# GUI 실행
ros2 run scv_logger scv_logger

# 카탈로그 스캔 (지금 떠 있는 토픽·주기·크기)
ros2 run scv_logger scv_logger_scan --duration 5

# 테스트
cd src/tools/scv_logger && /usr/bin/python3 -m pytest test -q
```

- 설정: `config/catalog.yaml`, `config/profiles/*.yaml`
- 녹화 저장 경로: `~/ssd2/scv_logs` (GUI 설정 탭에서 변경)

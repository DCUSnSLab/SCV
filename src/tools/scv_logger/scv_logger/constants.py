"""프로세스 간에 공유하는 이름."""

MARKER_TOPIC = '/scv_logger/marker'
HEALTH_TOPIC = '/scv_logger/health'

# 카탈로그 스캔에서 제외할 토픽 (ROS 기본 토픽과 이 도구 자신의 토픽)
SCAN_IGNORE_PREFIXES = ('/scv_logger/', '/rosout', '/parameter_events')

"""토픽 수신 측정 (monitor·scan 공용).

구독은 raw=True(역직렬화 없음) + best-effort. 콜백에서는 도착 시각과 크기만
기록하고 바로 반환한다. 판정 함수 evaluate()는 ROS와 무관해 단위 테스트한다.
"""
from __future__ import annotations

import time
from collections import deque

from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy

BEST_EFFORT_QOS = QoSProfile(history=HistoryPolicy.KEEP_LAST, depth=10,
                             reliability=ReliabilityPolicy.BEST_EFFORT,
                             durability=DurabilityPolicy.VOLATILE)
LATCHED_QOS = QoSProfile(history=HistoryPolicy.KEEP_LAST, depth=1,
                         reliability=ReliabilityPolicy.RELIABLE,
                         durability=DurabilityPolicy.TRANSIENT_LOCAL)


class Probe:
    """토픽 구독 하나. 같은 토픽을 여러 항목이 대신 재더라도 구독은 하나만."""

    def __init__(self, topic: str):
        self.topic = topic
        self.arrivals: deque[float] = deque(maxlen=4000)
        self.sizes: deque[int] = deque(maxlen=50)
        self.count = 0
        self.sub = None
        self.type_name: str | None = None
        self.error = ''
        self.latched = False
        self.publishers = 0

    def on_msg(self, data: bytes) -> None:
        self.arrivals.append(time.monotonic())
        self.sizes.append(len(data))
        self.count += 1

    def avg_size_kb(self) -> float | None:
        return sum(self.sizes) / len(self.sizes) / 1024 if self.sizes else None


def window_for(expected: float | None) -> float:
    return max(3.0, 4.0 / expected) if expected else 5.0


def measure_hz(arrivals, now: float, window: float) -> tuple[float, float | None]:
    """창 안의 도착 간격으로 주기 계산. (hz, 마지막 수신 후 경과초)."""
    if not arrivals:
        return 0.0, None
    last = arrivals[-1]
    recent = [t for t in arrivals if t >= now - window]
    hz = 0.0
    if len(recent) >= 2 and recent[-1] > recent[0]:
        hz = (len(recent) - 1) / (recent[-1] - recent[0])
    return hz, now - last


def evaluate(expected: float | None, arrivals, now: float, *, publishers: int,
             latched: bool = False, error: str = '', count: int = 0,
             tolerance: float = 0.8) -> dict:
    """상태 판정.

    ok / low(기준의 tolerance 미만) / stale(끊김) / waiting(발행자는 있는데 아직 미수신)
    / no_publisher / type_unavailable / latched_missing
    """
    hz, age = measure_hz(arrivals, now, window_for(expected))
    if error:
        status = 'type_unavailable'
    elif latched:
        status = 'ok' if (count > 0 or publishers > 0) else 'latched_missing'
    elif age is None:
        status = 'waiting' if publishers > 0 else 'no_publisher'
    elif age > (max(2.0, 3.0 / expected) if expected else 5.0):
        status = 'stale' if publishers > 0 else 'no_publisher'
    elif expected and hz < expected * tolerance:
        status = 'low'
    else:
        status = 'ok'
    return {'hz': round(hz, 2), 'age': None if age is None else round(age, 2), 'status': status}

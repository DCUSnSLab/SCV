"""GUI 공통: 표시 문자열, 색, 비동기 실행."""
from __future__ import annotations

import traceback
from typing import Any, Callable

from PyQt5.QtCore import QObject, QRunnable, QThreadPool, pyqtSignal
from PyQt5.QtGui import QColor

STATUS_TEXT = {
    'ok': '정상',
    'low': '주기 낮음',
    'stale': '끊김',
    'waiting': '수신 대기',
    'no_publisher': '발행자 없음',
    'type_unavailable': '타입 없음',
    'latched_missing': '없음',
}
STATUS_BG = {
    'ok': QColor('#d9f2d9'),
    'low': QColor('#fff0b3'),
    'stale': QColor('#f7c6c6'),
    'waiting': QColor('#e8e8e8'),
    'no_publisher': QColor('#e8e8e8'),
    'type_unavailable': QColor('#f2dcf2'),
    'latched_missing': QColor('#f7c6c6'),
}
LEVEL_ICON = {'ok': '✓', 'info': '·', 'warn': '⚠', 'error': '✗'}
LEVEL_COLOR = {'ok': '#2e7d32', 'info': '#555555', 'warn': '#b26a00', 'error': '#c62828'}


def fmt_bytes(n: float | None) -> str:
    if n is None:
        return '-'
    for unit in ('B', 'KB', 'MB', 'GB', 'TB'):
        if abs(n) < 1024 or unit == 'TB':
            return f'{n:.0f} {unit}' if unit == 'B' else f'{n:.1f} {unit}'
        n /= 1024
    return '-'


def fmt_duration(sec: float | None) -> str:
    if sec is None:
        return '-'
    sec = int(sec)
    h, rem = divmod(sec, 3600)
    m, s = divmod(rem, 60)
    return f'{h:d}:{m:02d}:{s:02d}'


def fmt_minutes(minutes: float | None) -> str:
    if minutes is None:
        return '-'
    if minutes >= 60:
        return f'약 {minutes / 60:.0f}시간 {minutes % 60:.0f}분'
    return f'약 {minutes:.0f}분'


def fmt_num(v: Any, digits: int = 1) -> str:
    if v is None or v == '':
        return '-'
    try:
        return f'{float(v):.{digits}f}'
    except (TypeError, ValueError):
        return str(v)


def fmt_kb(v: Any) -> str:
    """메시지 크기 — 1 KB 미만은 소수 둘째 자리까지."""
    if v is None or v == '':
        return '-'
    return fmt_num(v, 2 if float(v) < 1 else 1)


class _Signals(QObject):
    done = pyqtSignal(object)
    failed = pyqtSignal(str)


class _Job(QRunnable):
    def __init__(self, fn: Callable[[], Any]):
        super().__init__()
        self.fn = fn
        self.signals = _Signals()

    def run(self) -> None:
        try:
            result = self.fn()
        except Exception as e:  # noqa: BLE001 — GUI에 그대로 보여준다
            self.signals.failed.emit(f'{e}\n\n{traceback.format_exc()}')
        else:
            self.signals.done.emit(result)


_jobs: set[_Job] = set()


def run_async(fn: Callable[[], Any], on_done: Callable[[Any], None] | None = None,
              on_error: Callable[[str], None] | None = None) -> None:
    """블로킹 작업(git 스냅샷, 프로세스 정지 대기)을 스레드 풀에서. 콜백은 GUI 스레드."""
    job = _Job(fn)
    job.setAutoDelete(False)
    _jobs.add(job)

    def finish(cb, value):
        _jobs.discard(job)
        if cb:
            cb(value)

    job.signals.done.connect(lambda r: finish(on_done, r))
    job.signals.failed.connect(lambda e: finish(on_error, e))
    QThreadPool.globalInstance().start(job)

"""녹화 시작 전 점검. GUI는 결과를 그대로 목록으로 보여준다."""
from __future__ import annotations

import os
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import Any

from .profile import ResolvedProfile

OK, INFO, WARN, ERROR = 'ok', 'info', 'warn', 'error'


@dataclass
class Check:
    level: str
    text: str


def disk_free_gb(path: Path) -> float | None:
    p = Path(path)
    while not p.exists() and p != p.parent:
        p = p.parent
    try:
        return shutil.disk_usage(p).free / 1024 ** 3
    except OSError:
        return None


def run_checks(resolved: ResolvedProfile, output_dir: Path, health: dict[str, Any] | None,
               recording_active: bool = False) -> list[Check]:
    checks: list[Check] = []
    o = resolved.options

    if recording_active:
        checks.append(Check(ERROR, '이미 녹화 중인 세션이 있음'))

    # 저장 경로
    out = Path(output_dir)
    probe = out if out.exists() else out.parent
    if not probe.exists() or not os.access(probe, os.W_OK):
        checks.append(Check(ERROR, f'저장 경로에 쓸 수 없음: {out}'))
    free = disk_free_gb(out)
    if free is None:
        checks.append(Check(WARN, '디스크 여유를 확인할 수 없음'))
    elif free < o.disk_stop_gb:
        checks.append(Check(ERROR, f'디스크 여유 {free:.0f} GB — 자동 정지 기준 {o.disk_stop_gb:.0f} GB 미만'))
    elif free < o.disk_warn_gb:
        checks.append(Check(WARN, f'디스크 여유 {free:.0f} GB — 경고 기준 {o.disk_warn_gb:.0f} GB 미만'))
    else:
        checks.append(Check(OK, f'디스크 여유 {free:.0f} GB ({out})'))

    if resolved.unknown_topics:
        checks.append(Check(WARN, f'카탈로그에 없는 토픽 {len(resolved.unknown_topics)}개 — 상태 기준 없음'))

    # 토픽 상태 (preview monitor)
    if health is None:
        checks.append(Check(WARN, '토픽 상태 수신 대기 중 (monitor 기동 중)'))
        return checks
    topics = health.get('topics', {})
    required = {n: t for n, t in topics.items() if t.get('required')}
    bad_req = [n for n, t in required.items() if t.get('status') != 'ok']
    if required:
        if bad_req:
            checks.append(Check(WARN, f'필수 토픽 {len(required) - len(bad_req)}/{len(required)} 정상 — '
                                      f'문제: {", ".join(bad_req[:4])}{" 외" if len(bad_req) > 4 else ""}'))
        else:
            checks.append(Check(OK, f'필수 토픽 {len(required)}/{len(required)} 정상'))
    no_type = [n for n, t in topics.items() if t.get('status') == 'type_unavailable']
    if no_type:
        checks.append(Check(WARN, f'메시지 타입을 못 불러온 토픽 {len(no_type)}개 (워크스페이스 source 확인): '
                                  f'{", ".join(no_type[:3])}'))
    silent = [n for n, t in topics.items() if t.get('status') in ('no_publisher', 'waiting', 'stale')]
    if silent:
        checks.append(Check(INFO, f'데이터가 안 들어오는 토픽 {len(silent)}/{len(topics)}개'))
    for w in health.get('warnings', []):
        checks.append(Check(WARN, w))
    return checks


def required_ready(health: dict[str, Any] | None) -> tuple[bool, list[str]]:
    if not health:
        return False, ['(상태 미수신)']
    bad = [n for n, t in health.get('topics', {}).items()
           if t.get('required') and t.get('status') != 'ok']
    return not bad, bad

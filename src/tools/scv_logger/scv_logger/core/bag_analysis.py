"""세션 녹화 점검 — "이 녹화가 전체적으로 잘 됐나".

녹화된 메시지 시각(bag)과 녹화 중 감시 노드가 잰 원본 주기(health.csv)를 시간 구간별로
맞춰 본다. 원본이 끊긴 구간과 녹화기가 버린 구간을 구분하는 것이 핵심이다.

결과는 세션 폴더의 analysis.json에 캐시한다 (bag 파일 크기·수정 시각이 같으면 재사용).
"""
from __future__ import annotations

import csv
import json
import math
import re
import statistics
from array import array
from pathlib import Path
from typing import Any, Callable

from .bag_scan import scan_bag
from .yamlio import load_yaml

CACHE_VERSION = 5
GOOD, WARN = 0.9, 0.5          # 녹화율 판정 기준
_DIGITS_RE = re.compile(r'[-+]?\d+(\.\d+)?')
SOURCE_DOWN = ('no_publisher', 'stale', 'waiting')

VERDICT_TEXT = {'good': '양호', 'warn': '일부 손실', 'bad': '손실 큼', 'source': '원본 없음',
                'missing': '녹화 안 됨', 'noref': '기준 없음', 'latched': '1회성'}


def find_bag_dir(path: Path) -> tuple[Path, Path | None]:
    """세션 폴더나 bag 폴더 → (bag 폴더, 세션 폴더 또는 None)."""
    path = Path(path)

    def is_bag(d: Path) -> bool:
        return d.is_dir() and ((d / 'metadata.yaml').exists()
                               or any(p.suffix in ('.mcap', '.db3') for p in d.iterdir()))
    if is_bag(path / 'bag'):
        return path / 'bag', path
    if is_bag(path):
        parent = path.parent
        return path, parent if (parent / 'manifest.yaml').exists() else None
    raise FileNotFoundError(f'bag을 찾을 수 없음 (metadata.yaml·mcap·db3 없음): {path}')


def _cache_key(bag_dir: Path) -> list:
    return [[p.name, p.stat().st_size, int(p.stat().st_mtime)] for p in sorted(bag_dir.iterdir()) if p.is_file()]


def parse_recorder_lost(log: Path) -> tuple[dict[str, int], int]:
    """recorder.log의 마지막 'Cache buffers lost messages' 블록 (누적값)."""
    if not log.exists():
        return {}, 0
    text = log.read_text(errors='replace')
    blocks = text.split('Cache buffers lost messages per topic:')
    if len(blocks) < 2:
        return {}, 0
    per, total = {}, 0
    for line in blocks[-1].splitlines()[1:]:
        m = re.match(r'\s+(/\S+): (\d+)\s*$', line)
        if m:
            per[m.group(1)] = int(m.group(2))
            continue
        m = re.match(r'Total lost: (\d+)', line.strip())
        if m:
            total = int(m.group(1))
        break
    return per, total or sum(per.values())


def _read_csv(path: Path) -> list[dict]:
    if not path.exists():
        return []
    with open(path, newline='', encoding='utf-8') as f:
        return list(csv.DictReader(f))


def _float(v: Any) -> float | None:
    try:
        return float(v)
    except (TypeError, ValueError):
        return None


def analyze(path: Path, progress: Callable[[int, int], None] | None = None, *,
            target_bins: int = 240, use_cache: bool = True,
            catalog_hint: dict[str, dict] | None = None) -> dict[str, Any]:
    """catalog_hint: {토픽: {'hz', 'latched'}} — 세션의 monitor_config.json이 없을 때 대신 쓴다."""
    bag_dir, session = find_bag_dir(path)
    cache = (session or bag_dir) / 'analysis.json'
    key = _cache_key(bag_dir)
    if use_cache and cache.exists():
        try:
            data = json.loads(cache.read_text(encoding='utf-8'))
            if data.get('version') == CACHE_VERSION and data.get('key') == key:
                return data
        except (OSError, ValueError):
            pass

    times, types = scan_bag(bag_dir, progress)
    result = build(times, types, bag_dir, session, target_bins, catalog_hint)
    result['key'] = key
    try:
        cache.write_text(json.dumps(result, ensure_ascii=False), encoding='utf-8')
    except OSError:
        pass                          # 읽기 전용 위치면 캐시 없이
    return result


def build(times: dict[str, array], types: dict[str, str], bag_dir: Path, session: Path | None,
          target_bins: int = 240, catalog_hint: dict[str, dict] | None = None) -> dict[str, Any]:
    manifest = load_yaml(session / 'manifest.yaml') if session else {}
    manifest = manifest or {}
    mon_cfg = {}
    if session and (session / 'monitor_config.json').exists():
        mon_cfg = {t['name']: t for t in json.loads((session / 'monitor_config.json').read_text()).get('topics', [])}
    for name, hint in (catalog_hint or {}).items():
        mon_cfg.setdefault(name, {'name': name, **hint})

    firsts = [v[0] for v in times.values() if len(v)]
    lasts = [v[-1] for v in times.values() if len(v)]
    if not firsts:
        raise ValueError('bag에 메시지가 없음')
    t0, t1 = min(firsts), max(lasts)
    duration = max((t1 - t0) / 1e9, 1e-3)
    bin_sec = max(1, math.ceil(duration / target_bins))
    nbins = max(1, math.ceil(duration / bin_sec))
    bin_ns = bin_sec * 1_000_000_000

    # ---- 원본 주기 (녹화 중 감시 노드) --------------------------------------
    mon_bins: dict[str, list[list[float]]] = {}
    mon_down: dict[str, list[int]] = {}
    mon_all: dict[str, list[float]] = {}
    abnormal: dict[str, int] = {}               # 값 이상으로 판정된 감시 횟수 (≈초)
    abnormal_issues: dict[str, dict[str, str]] = {}   # 숫자를 뺀 문구 → 처음 본 원문
    for r in _read_csv(session / 'health.csv') if session else []:
        t, hz = _float(r.get('time')), _float(r.get('hz'))
        if t is None:
            continue
        b = int((t * 1e9 - t0) // bin_ns)
        if not 0 <= b < nbins:
            continue
        name = r['topic']
        mon_bins.setdefault(name, [[] for _ in range(nbins)])[b].append(hz or 0.0)
        if r.get('status') in SOURCE_DOWN:
            mon_down.setdefault(name, [0] * nbins)[b] += 1
        if hz and r.get('status') not in SOURCE_DOWN:
            mon_all.setdefault(name, []).append(hz)
        if r.get('status') == 'abnormal':
            abnormal[name] = abnormal.get(name, 0) + 1
            kinds = abnormal_issues.setdefault(name, {})
            for issue in (r.get('issues') or '').split(' | '):
                key = _DIGITS_RE.sub('#', issue.strip())
                if key and key not in kinds and len(kinds) < 5:
                    kinds[key] = issue.strip()

    lost, lost_total = parse_recorder_lost(session / 'recorder.log') if session else ({}, 0)

    # ---- 토픽 순서: 프로파일 순서 → bag에만 있는 토픽 -------------------------
    prof_topics = (manifest.get('profile') or {}).get('topics', []) + \
        (manifest.get('profile') or {}).get('unknown_topics', [])
    order = list(prof_topics) + sorted(t for t in times if t not in prof_topics)

    topics = []
    for name in order:
        ts = times.get(name, array('q'))
        cfg = mon_cfg.get(name, {})
        expected = cfg.get('hz')
        latched = bool(cfg.get('latched'))
        count = len(ts)
        rec_hz = (count - 1) / ((ts[-1] - ts[0]) / 1e9) if count > 1 and ts[-1] > ts[0] else None
        max_gap, gap_at = 0.0, None
        bins = [0] * nbins
        prev = None
        for t in ts:
            bins[min(int((t - t0) // bin_ns), nbins - 1)] += 1
            if prev is not None and t - prev > max_gap * 1e9:
                max_gap, gap_at = (t - prev) / 1e9, (prev - t0) / 1e9
            prev = t
        src_hz = statistics.median(mon_all[name]) if mon_all.get(name) else None
        ref = src_hz or expected
        mb = mon_bins.get(name)
        down = mon_down.get(name, [0] * nbins)
        ratios: list[float | None] = []
        src_off: list[bool] = []
        for b in range(nbins):
            span = min(bin_sec, duration - b * bin_sec)
            vals = mb[b] if mb else []
            bin_ref = (sum(vals) / len(vals)) if vals else ref
            off = bool(vals) and down[b] >= len(vals) / 2
            src_off.append(off)
            if latched or not bin_ref or span <= 0:
                ratios.append(None)
            else:
                ratios.append(round(min(bins[b] / (bin_ref * span), 1.5), 3))
        if latched:
            verdict, coverage = ('latched' if count else 'missing'), None
        elif count == 0:
            verdict, coverage = ('source' if mb and all(src_off) else 'missing'), 0.0
        elif not ref:
            verdict, coverage = 'noref', None
        else:
            coverage = min(count / (ref * duration), 1.5)
            verdict = 'good' if coverage >= GOOD else 'warn' if coverage >= WARN else 'bad'
        topics.append({
            'name': name, 'type': types.get(name), 'count': count,
            'rec_hz': None if rec_hz is None else round(rec_hz, 2),
            'src_hz': None if src_hz is None else round(src_hz, 2),
            'expected': expected, 'coverage': None if coverage is None else round(coverage, 3),
            'max_gap': round(max_gap, 2), 'gap_at': None if gap_at is None else round(gap_at, 1),
            'lost': lost.get(name, 0), 'verdict': verdict, 'latched': latched,
            'abnormal_s': abnormal.get(name, 0), 'abnormal_issues': list(abnormal_issues.get(name, {}).values()),
            'bins': bins, 'ratios': ratios, 'src_off': src_off,
        })

    # ---- 디스크·녹화 속도 ------------------------------------------------
    sys_bins = {'mbps': [None] * nbins, 'free_gb': [None] * nbins}
    acc: dict[int, list[tuple[float, float]]] = {}
    for r in _read_csv(session / 'system.csv') if session else []:
        t = _float(r.get('time'))
        if t is None:
            continue
        b = int((t * 1e9 - t0) // bin_ns)
        if 0 <= b < nbins:
            acc.setdefault(b, []).append((_float(r.get('write_mbps')) or 0.0, _float(r.get('disk_free_gb')) or 0.0))
    for b, vals in acc.items():
        sys_bins['mbps'][b] = round(sum(v[0] for v in vals) / len(vals), 1)
        sys_bins['free_gb'][b] = round(vals[-1][1], 1)

    markers = []
    if session and (session / 'markers.jsonl').exists():
        for line in (session / 'markers.jsonl').read_text(encoding='utf-8').splitlines():
            try:
                m = json.loads(line)
            except ValueError:
                continue
            ts = _float(m.get('ts'))
            if ts is not None:
                markers.append({'t': round((ts * 1e9 - t0) / 1e9, 1), 'kind': m.get('kind'), 'text': m.get('text', '')})

    covs = [t['coverage'] for t in topics if t['coverage'] is not None]
    size = sum(p.stat().st_size for p in bag_dir.iterdir() if p.is_file())
    return {
        'version': CACHE_VERSION,
        'bag_dir': str(bag_dir), 'session': str(session) if session else None,
        'profile': (manifest.get('profile') or {}).get('name'), 'status': manifest.get('status'),
        'start_ns': t0, 'duration': round(duration, 1), 'bin_sec': bin_sec, 'nbins': nbins,
        'size_bytes': size, 'messages': sum(t['count'] for t in topics),
        'lost_total': lost_total,
        'recorder_log': bool(session and (session / 'recorder.log').exists()),
        'coverage_median': round(statistics.median(covs), 3) if covs else None,
        'coverage_min': round(min(covs), 3) if covs else None,
        'counts': {v: sum(1 for t in topics if t['verdict'] == v) for v in VERDICT_TEXT},
        'topics': topics, 'system': sys_bins, 'markers': markers,
    }

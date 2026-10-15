"""ros2 bag record 명령, QoS override, monitor 설정 생성."""
from __future__ import annotations

import json
from pathlib import Path
from typing import Any

from ..constants import HEALTH_TOPIC, MARKER_TOPIC
from .catalog import Catalog
from .profile import ResolvedProfile
from .yamlio import write_yaml

# mcap 저장 프리셋 (rosbag2_storage_mcap 0.15):
#   fastwrite — 청크·압축·CRC 없음. CPU 최소. 대신 청크 인덱스가 없어 탐색이 느리다.
#   zstd_fast — 청크 + zstd 최저 레벨.
MCAP_PRESET = {'none': 'fastwrite', 'zstd': 'zstd_fast'}

HEAVY_QOS = {'history': 'keep_last', 'depth': 10, 'reliability': 'best_effort',
             'durability': 'volatile'}


def qos_overrides(resolved: ResolvedProfile, catalog: Catalog) -> dict[str, dict]:
    """heavy_qos=best_effort일 때만 큰 토픽의 녹화 구독을 best-effort로 바꾼다.

    기본값은 keep(원래 QoS). 실측(2026-10-08, VLP-32C /velodyne_points 1.2 MB): reliable 구독은
    10 Hz를 다 받았지만 best-effort 구독은 4.5 Hz(그 전 녹화에서는 1.2 Hz)만 받았다.
    Fast DDS는 큰 메시지를 조각으로 보내는데 best-effort는 조각 하나만 빠져도 재전송 없이 버린다.
    """
    if resolved.options.heavy_qos != 'best_effort':
        return {}
    out = {}
    for name in resolved.topics:
        spec = catalog.topic(name)
        if spec and spec.heavy and not spec.latched:
            out[name] = dict(HEAVY_QOS)
    return out


def build_record_command(resolved: ResolvedProfile, bag_dir: Path,
                         qos_path: Path | None = None,
                         extra_topics: tuple[str, ...] = (MARKER_TOPIC, HEALTH_TOPIC)) -> list[str]:
    o = resolved.options
    cmd = ['ros2', 'bag', 'record', '-o', str(bag_dir), '-s', o.storage,
           '--max-cache-size', str(o.max_cache_mb * 1024 * 1024)]
    if o.split_duration_sec > 0:
        cmd += ['--max-bag-duration', str(o.split_duration_sec)]
    if o.split_size_mb > 0:
        cmd += ['--max-bag-size', str(o.split_size_mb * 1024 * 1024)]
    if o.storage == 'mcap':
        cmd += ['--storage-preset-profile', MCAP_PRESET[o.compression]]
    elif o.compression == 'zstd':
        cmd += ['--compression-mode', 'file', '--compression-format', 'zstd']
    if qos_path is not None:
        cmd += ['--qos-profile-overrides-path', str(qos_path)]
    topics = list(resolved.topics) + list(resolved.unknown_topics)
    topics += [t for t in extra_topics if t not in topics]
    return cmd + topics


def write_qos_file(path: Path, overrides: dict[str, dict]) -> Path | None:
    if not overrides:
        return None
    write_yaml(path, overrides)
    return path


def estimate_mb_per_min(resolved: ResolvedProfile, catalog: Catalog) -> tuple[float, list[str]]:
    """카탈로그의 hz × size_kb 합. 값이 없는 토픽 목록도 돌려준다."""
    total_kb_s = 0.0
    unknown = list(resolved.unknown_topics)
    for name in resolved.topics:
        spec = catalog.topic(name)
        if spec is None or spec.latched:
            continue
        if spec.hz and spec.size_kb:
            total_kb_s += spec.hz * spec.size_kb
        else:
            unknown.append(name)
    return total_kb_s * 60 / 1024, unknown


def monitor_config(resolved: ResolvedProfile, catalog: Catalog, *, hz_tolerance: float,
                   output_dir: Path) -> dict[str, Any]:
    topics = []
    for name in list(resolved.topics) + list(resolved.unknown_topics):
        spec = catalog.topic(name)
        topics.append({
            'name': name,
            'monitor': spec.monitor_topic if spec else name,
            'hz': spec.hz if spec else None,
            'required': bool(spec and spec.required),
            'latched': bool(spec and spec.latched),
            'heavy': bool(spec and spec.heavy),
        })
    o = resolved.options
    return {
        'profile': resolved.name,
        'topics': topics,
        'auto_markers': [m.to_dict() for m in catalog.auto_markers],
        'value_checks': catalog.value_checks,
        'hz_tolerance': hz_tolerance,
        'output_dir': str(output_dir),
        'disk_warn_gb': o.disk_warn_gb,
        'disk_stop_gb': o.disk_stop_gb,
    }


def write_json(path: Path, data: Any) -> Path:
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding='utf-8')
    return path

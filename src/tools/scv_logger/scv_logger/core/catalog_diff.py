"""카탈로그 스캔 결과와 현재 카탈로그 비교·반영."""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any

from .catalog import Catalog, TopicSpec

KIND_LABELS = {'new': '새 토픽', 'missing': '그래프에 없음', 'changed': '값 다름', 'same': '같음'}


@dataclass
class ScanEntry:
    name: str
    type: str | None = None
    hz: float | None = None
    size_kb: float | None = None
    latched: bool = False
    publishers: int = 0
    count: int = 0
    error: str = ''

    @classmethod
    def from_dict(cls, d: dict[str, Any]) -> 'ScanEntry':
        return cls(**{k: d.get(k) for k in cls.__dataclass_fields__ if k in d})


@dataclass
class DiffItem:
    kind: str
    name: str
    spec: TopicSpec | None = None
    scan: ScanEntry | None = None
    changes: dict[str, tuple] = field(default_factory=dict)
    suggest_heavy: bool = False


def round_hz(hz: float | None) -> float | None:
    if not hz:
        return None
    return round(hz, 1) if hz < 10 else float(round(hz))


def round_kb(kb: float | None) -> float | None:
    if not kb:
        return None
    if kb < 1:
        return max(round(kb, 2), 0.01)     # 카탈로그는 양수만 허용 — 0으로 반올림되지 않게
    return round(kb, 1) if kb < 10 else float(round(kb))


def _rel_diff(a: float | None, b: float | None) -> float:
    if not a or not b:
        return 0.0 if a == b else 1.0
    return abs(a - b) / max(a, b)


def diff_catalog(catalog: Catalog, entries: list[ScanEntry], hz_tol: float = 0.3,
                 size_tol: float = 0.5) -> list[DiffItem]:
    items: list[DiffItem] = []
    scanned = {e.name: e for e in entries}
    for e in entries:
        spec = catalog.topic(e.name)
        heavy = bool(e.size_kb and e.size_kb >= catalog.heavy_threshold_kb)
        if spec is None:
            items.append(DiffItem('new', e.name, scan=e, suggest_heavy=heavy))
            continue
        ch: dict[str, tuple] = {}
        if e.type and spec.type != e.type:
            ch['type'] = (spec.type, e.type)
        if e.hz and not spec.latched and _rel_diff(spec.hz, e.hz) > hz_tol:
            ch['hz'] = (spec.hz, round_hz(e.hz))
        if e.size_kb and _rel_diff(spec.size_kb, e.size_kb) > size_tol:
            ch['size_kb'] = (spec.size_kb, round_kb(e.size_kb))
        if e.latched != spec.latched:
            ch['latched'] = (spec.latched, e.latched)
        items.append(DiffItem('changed' if ch else 'same', e.name, spec=spec, scan=e,
                              changes=ch, suggest_heavy=heavy and not spec.heavy))
    for spec in catalog.topics():
        if spec.name not in scanned:
            items.append(DiffItem('missing', spec.name, spec=spec))
    order = {'new': 0, 'changed': 1, 'missing': 2, 'same': 3}
    return sorted(items, key=lambda i: (order[i.kind], i.name))


def apply_items(catalog: Catalog, items: list[tuple[DiffItem, str | None]],
                remove_missing: bool = False) -> int:
    """선택한 항목 반영. (item, new 토픽을 넣을 그룹) 목록. 반영 개수를 돌려준다."""
    n = 0
    for item, group in items:
        if item.kind == 'new' and item.scan is not None:
            if not group:
                continue
            e = item.scan
            catalog.add_topic(TopicSpec(
                name=e.name, group=group, type=e.type, hz=None if e.latched else round_hz(e.hz),
                size_kb=round_kb(e.size_kb), latched=e.latched, heavy=item.suggest_heavy))
            n += 1
        elif item.kind == 'changed' and item.spec is not None:
            for key, (_, new) in item.changes.items():
                setattr(item.spec, key, new)
            if item.suggest_heavy:
                item.spec.heavy = True
            n += 1
        elif item.kind == 'missing' and remove_missing and item.spec is not None:
            catalog.remove_topic(item.name)
            n += 1
    return n

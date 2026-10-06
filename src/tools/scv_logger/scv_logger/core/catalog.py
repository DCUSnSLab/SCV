"""토픽 카탈로그 — "이 차량에 어떤 토픽이 있고 정상 상태는 어떤가".

차량당 하나. 녹화 프로파일은 카탈로그의 그룹·토픽을 골라 쓰고, 상태 감시는
카탈로그의 기준 주기(hz)·필수 여부(required)로 판정한다.
"""
from __future__ import annotations

import re
from dataclasses import dataclass, field, fields
from pathlib import Path
from typing import Any

from .yamlio import load_yaml, write_yaml

TOPIC_NAME_RE = re.compile(r'^(/[A-Za-z_][A-Za-z0-9_]*)+$')
GROUP_NAME_RE = re.compile(r'^[a-z][a-z0-9_]*$')

CATALOG_HEADER = (
    'SCV Logger 토픽 카탈로그 — GUI(카탈로그 탭)에서 저장하면 이 파일이 다시 쓰인다.\n'
    '주석은 보존되지 않으니 설명은 description 필드에 적을 것.\n'
    '\n'
    'topic 필드: type, hz(기준 주기), required(필수), heavy(큰 메시지 — 녹화 시 best-effort),\n'
    '            size_kb(평균 크기, 용량 추정용), monitor_via(주기를 대신 잴 가벼운 토픽),\n'
    '            latched(transient_local — 주기 판정 제외), description'
)


class CatalogError(ValueError):
    pass


@dataclass
class TopicSpec:
    name: str
    group: str
    type: str | None = None
    hz: float | None = None
    required: bool = False
    heavy: bool = False
    size_kb: float | None = None
    monitor_via: str | None = None
    latched: bool = False
    description: str = ''

    FIELDS = ('type', 'hz', 'required', 'heavy', 'size_kb', 'monitor_via', 'latched', 'description')

    def to_dict(self) -> dict[str, Any]:
        defaults = {f.name: f.default for f in fields(TopicSpec)}
        return {k: getattr(self, k) for k in self.FIELDS if getattr(self, k) != defaults[k]}

    @property
    def monitor_topic(self) -> str:
        return self.monitor_via or self.name


@dataclass
class Group:
    name: str
    description: str = ''
    topics: dict[str, TopicSpec] = field(default_factory=dict)


@dataclass
class AutoMarker:
    """값이 바뀔 때 자동으로 마커를 찍을 토픽 (예: 수동/자율 전환)."""
    topic: str
    label: str = ''
    field: str | None = None      # 비교할 필드 경로 (a.b.c). 없으면 header를 뺀 전체
    kind: str = 'auto'

    def to_dict(self) -> dict[str, Any]:
        d: dict[str, Any] = {'topic': self.topic}
        if self.label:
            d['label'] = self.label
        if self.field:
            d['field'] = self.field
        if self.kind != 'auto':
            d['kind'] = self.kind
        return d


def _check_keys(data: dict, allowed: set[str], where: str) -> None:
    unknown = set(data) - allowed
    if unknown:
        raise CatalogError(f'{where}: 알 수 없는 키 {sorted(unknown)} (허용: {sorted(allowed)})')


def _check_topic_name(name: Any, where: str) -> str:
    if not isinstance(name, str) or not TOPIC_NAME_RE.match(name):
        raise CatalogError(f'{where}: 토픽 이름 형식 오류 {name!r} (예: /velodyne_points)')
    return name


def _opt_number(value: Any, where: str) -> float | None:
    if value is None:
        return None
    if isinstance(value, bool) or not isinstance(value, (int, float)) or value <= 0:
        raise CatalogError(f'{where}: 양수여야 함 (값 {value!r})')
    return float(value)


def _opt_bool(value: Any, where: str) -> bool:
    if value is None:
        return False
    if not isinstance(value, bool):
        raise CatalogError(f'{where}: true/false여야 함 (값 {value!r})')
    return value


@dataclass
class Catalog:
    groups: dict[str, Group] = field(default_factory=dict)
    auto_markers: list[AutoMarker] = field(default_factory=list)
    heavy_threshold_kb: float = 500.0
    version: int = 1

    # ---- 조회 ----------------------------------------------------------
    def topics(self) -> list[TopicSpec]:
        return [t for g in self.groups.values() for t in g.topics.values()]

    def topic(self, name: str) -> TopicSpec | None:
        for g in self.groups.values():
            if name in g.topics:
                return g.topics[name]
        return None

    def group_topics(self, group: str) -> list[str]:
        if group not in self.groups:
            raise CatalogError(f'카탈로그에 없는 그룹: {group}')
        return list(self.groups[group].topics)

    def order_index(self) -> dict[str, int]:
        return {t.name: i for i, t in enumerate(self.topics())}

    def sort_topics(self, names) -> list[str]:
        """카탈로그 순서로 정렬, 카탈로그에 없는 토픽은 뒤에 이름순."""
        idx = self.order_index()
        known = sorted((n for n in names if n in idx), key=idx.__getitem__)
        unknown = sorted(n for n in names if n not in idx)
        return known + unknown

    # ---- 편집 ----------------------------------------------------------
    def add_group(self, name: str, description: str = '') -> Group:
        if not GROUP_NAME_RE.match(name):
            raise CatalogError(f'그룹 이름은 영문 소문자·숫자·_ 만: {name!r}')
        if name in self.groups:
            raise CatalogError(f'이미 있는 그룹: {name}')
        self.groups[name] = Group(name, description)
        return self.groups[name]

    def add_topic(self, spec: TopicSpec) -> None:
        _check_topic_name(spec.name, '토픽 추가')
        if self.topic(spec.name):
            raise CatalogError(f'이미 카탈로그에 있는 토픽: {spec.name}')
        if spec.group not in self.groups:
            raise CatalogError(f'카탈로그에 없는 그룹: {spec.group}')
        self.groups[spec.group].topics[spec.name] = spec

    def remove_topic(self, name: str) -> None:
        spec = self.topic(name)
        if spec:
            del self.groups[spec.group].topics[name]

    def update_topic(self, old_name: str, spec: TopicSpec) -> None:
        """이름·그룹 변경 포함 교체. 같은 그룹이면 순서를 유지한다."""
        old = self.topic(old_name)
        if old is None:
            raise CatalogError(f'카탈로그에 없는 토픽: {old_name}')
        _check_topic_name(spec.name, '토픽 수정')
        if spec.name != old_name and self.topic(spec.name):
            raise CatalogError(f'이미 카탈로그에 있는 토픽: {spec.name}')
        if spec.group not in self.groups:
            raise CatalogError(f'카탈로그에 없는 그룹: {spec.group}')
        if spec.group == old.group:
            items = [(spec.name, spec) if k == old_name else (k, v)
                     for k, v in self.groups[old.group].topics.items()]
            self.groups[old.group].topics = dict(items)
        else:
            del self.groups[old.group].topics[old_name]
            self.groups[spec.group].topics[spec.name] = spec

    # ---- 직렬화 --------------------------------------------------------
    @classmethod
    def from_dict(cls, data: Any, source: str = 'catalog') -> 'Catalog':
        if not isinstance(data, dict):
            raise CatalogError(f'{source}: 최상위가 매핑이 아님')
        _check_keys(data, {'version', 'heavy_threshold_kb', 'groups', 'auto_markers'}, source)
        cat = cls(version=int(data.get('version', 1)),
                  heavy_threshold_kb=_opt_number(data.get('heavy_threshold_kb'), f'{source}.heavy_threshold_kb') or 500.0)
        groups = data.get('groups') or {}
        if not isinstance(groups, dict):
            raise CatalogError(f'{source}.groups: 매핑이어야 함')
        seen: dict[str, str] = {}
        for gname, gdata in groups.items():
            where = f'{source}.groups.{gname}'
            if not isinstance(gname, str) or not GROUP_NAME_RE.match(gname):
                raise CatalogError(f'{where}: 그룹 이름은 영문 소문자·숫자·_ 만')
            gdata = gdata or {}
            if not isinstance(gdata, dict):
                raise CatalogError(f'{where}: 매핑이어야 함')
            _check_keys(gdata, {'description', 'topics'}, where)
            group = Group(gname, str(gdata.get('description') or ''))
            for tname, tdata in (gdata.get('topics') or {}).items():
                twhere = f'{where}.{tname}'
                _check_topic_name(tname, twhere)
                if tname in seen:
                    raise CatalogError(f'{twhere}: 토픽이 그룹 {seen[tname]}에도 있음 (토픽은 한 그룹에만)')
                seen[tname] = gname
                tdata = tdata or {}
                if not isinstance(tdata, dict):
                    raise CatalogError(f'{twhere}: 매핑이어야 함')
                _check_keys(tdata, set(TopicSpec.FIELDS), twhere)
                via = tdata.get('monitor_via')
                if via is not None:
                    _check_topic_name(via, f'{twhere}.monitor_via')
                ttype = tdata.get('type')
                if ttype is not None and (not isinstance(ttype, str) or ttype.count('/') != 2):
                    raise CatalogError(f'{twhere}.type: pkg/msg/Type 형식이어야 함 (값 {ttype!r})')
                group.topics[tname] = TopicSpec(
                    name=tname, group=gname, type=ttype,
                    hz=_opt_number(tdata.get('hz'), f'{twhere}.hz'),
                    required=_opt_bool(tdata.get('required'), f'{twhere}.required'),
                    heavy=_opt_bool(tdata.get('heavy'), f'{twhere}.heavy'),
                    size_kb=_opt_number(tdata.get('size_kb'), f'{twhere}.size_kb'),
                    monitor_via=via,
                    latched=_opt_bool(tdata.get('latched'), f'{twhere}.latched'),
                    description=str(tdata.get('description') or ''),
                )
            cat.groups[gname] = group
        for i, m in enumerate(data.get('auto_markers') or []):
            where = f'{source}.auto_markers[{i}]'
            if not isinstance(m, dict):
                raise CatalogError(f'{where}: 매핑이어야 함')
            _check_keys(m, {'topic', 'label', 'field', 'kind'}, where)
            cat.auto_markers.append(AutoMarker(
                topic=_check_topic_name(m.get('topic'), where),
                label=str(m.get('label') or ''), field=m.get('field') or None,
                kind=str(m.get('kind') or 'auto')))
        return cat

    def to_dict(self) -> dict[str, Any]:
        return {
            'version': self.version,
            'heavy_threshold_kb': self.heavy_threshold_kb,
            'auto_markers': [m.to_dict() for m in self.auto_markers],
            'groups': {
                g.name: {'description': g.description,
                         'topics': {t.name: t.to_dict() for t in g.topics.values()}}
                for g in self.groups.values()
            },
        }

    @classmethod
    def load(cls, path: Path) -> 'Catalog':
        path = Path(path)
        if not path.exists():
            raise CatalogError(f'카탈로그 파일 없음: {path}')
        return cls.from_dict(load_yaml(path), source=path.name)

    def save(self, path: Path) -> None:
        # 저장 전 왕복 검증 — 잘못된 상태를 파일로 남기지 않는다
        Catalog.from_dict(self.to_dict())
        write_yaml(Path(path), self.to_dict(), header=CATALOG_HEADER)

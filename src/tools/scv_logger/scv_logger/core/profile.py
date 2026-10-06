"""녹화 프로파일 — "이번 주행에서 무엇을, 어떻게 녹화할까".

프로파일은 extends로 상속한다. 자식은 부모와의 차이만 적는다.

    name: long_transit
    extends: drive_standard
    exclude_groups: [camera_compressed]
    options: {compression: zstd}

해석 순서: 부모 결과(또는 빈 집합) → groups(있으면 교체) → add_groups 추가
→ exclude_groups 제거 → topics 추가 → exclude 제거. options는 부모 위에 덮어쓴다.
"""
from __future__ import annotations

import re
from dataclasses import asdict, dataclass, field, fields
from pathlib import Path
from typing import Any

from .catalog import TOPIC_NAME_RE, Catalog
from .yamlio import load_yaml, write_yaml

PROFILE_NAME_RE = re.compile(r'^[a-z0-9][a-z0-9_]*$')
MAX_DEPTH = 8

PROFILE_HEADER = (
    'SCV Logger 녹화 프로파일 — GUI(프로파일 탭)에서 저장하면 이 파일이 다시 쓰인다.\n'
    'extends로 부모를 지정하면 부모와의 차이만 적는다.'
)

OPTION_CHOICES: dict[str, tuple[str, ...]] = {
    'storage': ('mcap', 'sqlite3'),
    'compression': ('none', 'zstd'),
    'heavy_qos': ('best_effort', 'keep'),
    'start_mode': ('wait_ready', 'delay', 'immediate'),
}

# GUI 표시용
OPTION_LABELS: dict[str, str] = {
    'storage': '저장 형식',
    'compression': '압축',
    'split_duration_sec': '파일 분할 (초, 0=안 함)',
    'split_size_mb': '파일 분할 (MB, 0=안 함)',
    'heavy_qos': '큰 토픽 QoS',
    'start_mode': '시작 조건',
    'wait_ready_sec': '준비 대기 한도 (초)',
    'start_delay_sec': '지연 시작 (초)',
    'disk_warn_gb': '디스크 경고 (GB)',
    'disk_stop_gb': '디스크 자동 정지 (GB)',
    'max_cache_mb': '녹화 캐시 (MB)',
}

CHOICE_LABELS: dict[str, str] = {
    'mcap': 'mcap', 'sqlite3': 'sqlite3',
    'none': '없음', 'zstd': 'zstd',
    'best_effort': 'best-effort (주행 노드 보호)', 'keep': '원래 QoS 유지',
    'wait_ready': '필수 토픽 준비 후', 'delay': 'N초 지연 후', 'immediate': '즉시',
}


class ProfileError(ValueError):
    pass


@dataclass
class RecordOptions:
    storage: str = 'mcap'
    compression: str = 'none'
    split_duration_sec: int = 300
    split_size_mb: int = 0
    heavy_qos: str = 'best_effort'
    start_mode: str = 'wait_ready'
    wait_ready_sec: int = 30
    start_delay_sec: int = 5
    disk_warn_gb: float = 30.0
    disk_stop_gb: float = 10.0
    max_cache_mb: int = 100

    @classmethod
    def names(cls) -> list[str]:
        return [f.name for f in fields(cls)]

    @classmethod
    def from_dict(cls, data: dict[str, Any], where: str = 'options') -> 'RecordOptions':
        unknown = set(data) - set(cls.names())
        if unknown:
            raise ProfileError(f'{where}: 알 수 없는 옵션 {sorted(unknown)}')
        values = asdict(cls())
        for k, v in data.items():
            default = values[k]
            if k in OPTION_CHOICES:
                if v not in OPTION_CHOICES[k]:
                    raise ProfileError(f'{where}.{k}: {v!r} — 선택지 {list(OPTION_CHOICES[k])}')
            elif isinstance(default, int) and not isinstance(default, bool):
                if isinstance(v, bool) or not isinstance(v, int) or v < 0:
                    raise ProfileError(f'{where}.{k}: 0 이상의 정수여야 함 (값 {v!r})')
            elif isinstance(default, float):
                if isinstance(v, bool) or not isinstance(v, (int, float)) or v < 0:
                    raise ProfileError(f'{where}.{k}: 0 이상의 숫자여야 함 (값 {v!r})')
                v = float(v)
            values[k] = v
        opts = cls(**values)
        opts.validate(where)
        return opts

    def validate(self, where: str = 'options') -> None:
        if self.disk_stop_gb > self.disk_warn_gb:
            raise ProfileError(f'{where}: disk_stop_gb({self.disk_stop_gb})가 disk_warn_gb({self.disk_warn_gb})보다 큼')
        if self.max_cache_mb < 1:
            raise ProfileError(f'{where}.max_cache_mb: 1 이상이어야 함')
        if self.start_mode == 'wait_ready' and self.wait_ready_sec < 1:
            raise ProfileError(f'{where}.wait_ready_sec: 1 이상이어야 함')

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)

    def diff(self, base: 'RecordOptions') -> dict[str, Any]:
        """base와 다른 값만."""
        mine, theirs = asdict(self), asdict(base)
        return {k: v for k, v in mine.items() if v != theirs[k]}


@dataclass
class Profile:
    """파일에 적힌 그대로의 프로파일."""
    name: str
    description: str = ''
    extends: str | None = None
    abstract: bool = False
    groups: list[str] | None = None
    add_groups: list[str] = field(default_factory=list)
    exclude_groups: list[str] = field(default_factory=list)
    topics: list[str] = field(default_factory=list)
    exclude: list[str] = field(default_factory=list)
    options: dict[str, Any] = field(default_factory=dict)

    KEYS = ('name', 'description', 'extends', 'abstract', 'groups', 'add_groups',
            'exclude_groups', 'topics', 'exclude', 'options')

    @classmethod
    def from_dict(cls, data: Any, where: str) -> 'Profile':
        if not isinstance(data, dict):
            raise ProfileError(f'{where}: 최상위가 매핑이 아님')
        unknown = set(data) - set(cls.KEYS)
        if unknown:
            raise ProfileError(f'{where}: 알 수 없는 키 {sorted(unknown)}')
        name = data.get('name')
        if not isinstance(name, str) or not PROFILE_NAME_RE.match(name):
            raise ProfileError(f'{where}: name은 영문 소문자·숫자·_ 만 ({name!r})')

        def str_list(key: str) -> list[str]:
            v = data.get(key) or []
            if not isinstance(v, list) or not all(isinstance(x, str) for x in v):
                raise ProfileError(f'{where}.{key}: 문자열 목록이어야 함')
            return list(v)

        for key in ('topics', 'exclude'):
            for t in str_list(key):
                if not TOPIC_NAME_RE.match(t):
                    raise ProfileError(f'{where}.{key}: 토픽 이름 형식 오류 {t!r}')
        options = data.get('options') or {}
        if not isinstance(options, dict):
            raise ProfileError(f'{where}.options: 매핑이어야 함')
        unknown_opts = set(options) - set(RecordOptions.names())
        if unknown_opts:
            raise ProfileError(f'{where}.options: 알 수 없는 옵션 {sorted(unknown_opts)}')
        # 값 검증은 상속을 합친 뒤(resolve)에 한다 — 자식은 일부 옵션만 적기 때문
        return cls(
            name=name,
            description=str(data.get('description') or ''),
            extends=data.get('extends') or None,
            abstract=bool(data.get('abstract', False)),
            groups=str_list('groups') if data.get('groups') is not None else None,
            add_groups=str_list('add_groups'),
            exclude_groups=str_list('exclude_groups'),
            topics=str_list('topics'),
            exclude=str_list('exclude'),
            options=dict(options),
        )

    def to_dict(self) -> dict[str, Any]:
        d: dict[str, Any] = {'name': self.name, 'description': self.description}
        if self.extends:
            d['extends'] = self.extends
        if self.abstract:
            d['abstract'] = True
        if self.groups is not None:
            d['groups'] = list(self.groups)
        for key in ('add_groups', 'exclude_groups', 'topics', 'exclude'):
            if getattr(self, key):
                d[key] = list(getattr(self, key))
        if self.options:
            d['options'] = dict(self.options)
        return d


@dataclass
class ResolvedProfile:
    name: str
    description: str
    chain: list[str]                 # [자기, 부모, 조부모, ...]
    topics: list[str]                # 카탈로그 순서
    options: RecordOptions
    unknown_topics: list[str]        # 카탈로그에 없는 토픽 (녹화는 하지만 상태 기준 없음)
    abstract: bool = False


class ProfileStore:
    def __init__(self, directory: Path):
        self.dir = Path(directory)

    def path(self, name: str) -> Path:
        return self.dir / f'{name}.yaml'

    def names(self) -> list[str]:
        if not self.dir.is_dir():
            return []
        return sorted(p.stem for p in self.dir.glob('*.yaml'))

    def load(self, name: str) -> Profile:
        p = self.path(name)
        if not p.exists():
            raise ProfileError(f'프로파일 없음: {name} ({p})')
        prof = Profile.from_dict(load_yaml(p), p.name)
        if prof.name != name:
            raise ProfileError(f'{p.name}: 파일 이름과 name({prof.name})이 다름')
        return prof

    def load_all(self) -> dict[str, Profile]:
        return {n: self.load(n) for n in self.names()}

    def children(self, name: str) -> list[str]:
        out = []
        for n in self.names():
            try:
                if self.load(n).extends == name:
                    out.append(n)
            except ProfileError:
                continue
        return out

    def save(self, profile: Profile, catalog: Catalog | None = None) -> None:
        Profile.from_dict(profile.to_dict(), profile.name)
        if catalog is not None:
            # 저장 전에 해석까지 해본다 (그룹 오타·상속 순환 차단)
            self._resolve(profile, catalog, [profile.name])
        write_yaml(self.path(profile.name), profile.to_dict(), header=PROFILE_HEADER)

    def delete(self, name: str) -> None:
        kids = self.children(name)
        if kids:
            raise ProfileError(f'{name}을(를) 상속하는 프로파일이 있어 삭제할 수 없음: {kids}')
        self.path(name).unlink()

    def resolve(self, name: str, catalog: Catalog) -> ResolvedProfile:
        return self._resolve(self.load(name), catalog, [name])

    def _resolve(self, prof: Profile, catalog: Catalog, stack: list[str]) -> ResolvedProfile:
        if len(stack) > MAX_DEPTH:
            raise ProfileError(f'상속 깊이 초과: {" → ".join(stack)}')
        if prof.extends:
            if prof.extends in stack:
                raise ProfileError(f'상속 순환: {" → ".join(stack + [prof.extends])}')
            parent = self._resolve(self.load(prof.extends), catalog, stack + [prof.extends])
            topics = set(parent.topics) | set(parent.unknown_topics)
            options = parent.options.to_dict()
            chain = [prof.name] + parent.chain
        else:
            topics, options, chain = set(), {}, [prof.name]

        def group_set(names: list[str], key: str) -> set[str]:
            out: set[str] = set()
            for g in names:
                if g not in catalog.groups:
                    raise ProfileError(f'{prof.name}.{key}: 카탈로그에 없는 그룹 {g!r}')
                out |= set(catalog.group_topics(g))
            return out

        if prof.groups is not None:
            topics = group_set(prof.groups, 'groups')
        topics |= group_set(prof.add_groups, 'add_groups')
        topics -= group_set(prof.exclude_groups, 'exclude_groups')
        topics |= set(prof.topics)
        topics -= set(prof.exclude)
        options.update(prof.options)
        opts = RecordOptions.from_dict(options, f'{prof.name}.options')
        ordered = catalog.sort_topics(topics)
        idx = catalog.order_index()
        return ResolvedProfile(
            name=prof.name, description=prof.description, chain=chain,
            topics=[t for t in ordered if t in idx],
            options=opts,
            unknown_topics=[t for t in ordered if t not in idx],
            abstract=prof.abstract,
        )


def profile_from_selection(name: str, description: str, selected: list[str],
                           options: RecordOptions, catalog: Catalog,
                           parent: ResolvedProfile | None = None) -> Profile:
    """GUI에서 고른 최종 토픽·옵션을 '부모와의 차이' 형태의 프로파일로 만든다.

    그룹이 통째로 추가/제거된 경우는 그룹 단위로, 나머지는 토픽 단위로 적는다.
    """
    sel = set(selected)
    group_sets = {g: set(catalog.group_topics(g)) for g in catalog.groups}
    if parent is not None:
        base = set(parent.topics) | set(parent.unknown_topics)
        add, rem = sel - base, base - sel
        add_groups = [g for g, s in group_sets.items() if s and s <= add]
        for g in add_groups:
            add -= group_sets[g]
        exclude_groups = [g for g, s in group_sets.items() if s and s <= rem]
        for g in exclude_groups:
            rem -= group_sets[g]
        return Profile(
            name=name, description=description, extends=parent.name,
            add_groups=add_groups, exclude_groups=exclude_groups,
            topics=catalog.sort_topics(add), exclude=catalog.sort_topics(rem),
            options=options.diff(parent.options),
        )
    groups = [g for g, s in group_sets.items() if s and s <= sel]
    covered = set().union(*(group_sets[g] for g in groups)) if groups else set()
    return Profile(
        name=name, description=description, groups=groups,
        topics=catalog.sort_topics(sel - covered),
        options=options.diff(RecordOptions()),
    )

"""YAML 읽기/쓰기 공통 처리.

GUI가 저장하는 파일은 PyYAML로 다시 쓰기 때문에 주석이 보존되지 않는다.
설명은 주석 대신 description 필드에 적는다.
"""
from __future__ import annotations

import os
from pathlib import Path
from typing import Any

import yaml


class _Dumper(yaml.SafeDumper):
    pass


def _represent_none(dumper, _):
    return dumper.represent_scalar('tag:yaml.org,2002:null', '')


_Dumper.add_representer(type(None), _represent_none)


def load_yaml(path: Path) -> Any:
    with open(path, encoding='utf-8') as f:
        return yaml.safe_load(f)


def dump_yaml(data: Any) -> str:
    return yaml.dump(data, Dumper=_Dumper, allow_unicode=True, sort_keys=False,
                     default_flow_style=False, width=100)


def write_yaml(path: Path, data: Any, header: str = '') -> None:
    """임시 파일에 쓴 뒤 rename — 저장 도중 죽어도 원본이 깨지지 않게."""
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    text = dump_yaml(data)
    if header:
        text = ''.join(f'# {line}\n' if line else '#\n' for line in header.splitlines()) + text
    tmp = path.with_name(f'.{path.name}.tmp{os.getpid()}')
    tmp.write_text(text, encoding='utf-8')
    os.replace(tmp, path)

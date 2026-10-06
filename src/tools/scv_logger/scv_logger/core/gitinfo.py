"""워크스페이스 git 스냅샷 — "어떤 코드로 달렸나".

슈퍼프로젝트와 .gitmodules의 서브모듈 전부를 기록한다. 서브모듈이 슈퍼프로젝트에
기록된 커밋과 다른 커밋에 있으면(matches_superproject: false) 그 주행은 커밋된
조합으로 재현되지 않는다.
"""
from __future__ import annotations

import subprocess
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import Any

MAX_CHANGES = 50


def _git(args: list[str], cwd: Path, timeout: float) -> str:
    try:
        r = subprocess.run(['git', *args], cwd=cwd, capture_output=True, text=True,
                           timeout=timeout, check=False)
        return r.stdout if r.returncode == 0 else ''
    except (OSError, subprocess.TimeoutExpired):
        return ''


def repo_info(path: Path, timeout: float = 10.0) -> dict[str, Any]:
    if not (path / '.git').exists():
        return {'missing': True}
    branch = _git(['rev-parse', '--abbrev-ref', 'HEAD'], path, timeout).strip()
    commit = _git(['rev-parse', 'HEAD'], path, timeout).strip()
    changes = _git(['status', '--porcelain', '--ignore-submodules=all'], path, timeout).splitlines()
    info: dict[str, Any] = {
        'branch': branch if branch != 'HEAD' else '(detached)',
        'commit': commit,
        'dirty': bool(changes),
    }
    if changes:
        info['changes'] = changes[:MAX_CHANGES]
        info['changes_total'] = len(changes)
    return info


def submodule_paths(ws: Path, timeout: float = 10.0) -> list[str]:
    out = _git(['config', '-f', '.gitmodules', '--get-regexp', r'^submodule\..*\.path$'], ws, timeout)
    return [line.split(None, 1)[1] for line in out.splitlines() if ' ' in line]


def recorded_commits(ws: Path, paths: list[str], timeout: float = 10.0) -> dict[str, str]:
    """슈퍼프로젝트 HEAD에 기록된 서브모듈 커밋."""
    if not paths:
        return {}
    out = _git(['ls-tree', 'HEAD', '--', *paths], ws, timeout)
    rec = {}
    for line in out.splitlines():
        meta, _, p = line.partition('\t')
        parts = meta.split()
        if len(parts) == 3 and parts[1] == 'commit':
            rec[p] = parts[2]
    return rec


def snapshot(ws: Path | None, timeout: float = 10.0) -> dict[str, Any]:
    if ws is None or not (ws / '.git').exists():
        return {'error': f'git 저장소가 아님: {ws}'}
    paths = submodule_paths(ws, timeout)
    rec = recorded_commits(ws, paths, timeout)
    with ThreadPoolExecutor(max_workers=8) as ex:
        top = ex.submit(repo_info, ws, timeout)
        subs = {p: ex.submit(repo_info, ws / p, timeout) for p in paths}
        result: dict[str, Any] = {'workspace': str(ws), 'superproject': top.result(), 'submodules': []}
        for p, fut in subs.items():
            info = {'path': p, **fut.result()}
            if 'commit' in info and p in rec:
                info['matches_superproject'] = info['commit'] == rec[p]
            result['submodules'].append(info)
    return result

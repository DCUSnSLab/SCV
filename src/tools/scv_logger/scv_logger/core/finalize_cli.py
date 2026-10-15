"""C++ 감시 노드가 녹화 종료를 감지했을 때 호출하는 manifest 마감.

    python3 -m scv_logger.core.finalize_cli <세션 폴더>
"""
from __future__ import annotations

import sys
from pathlib import Path

from .session import Session


def main(argv: list[str] | None = None) -> None:
    args = sys.argv[1:] if argv is None else argv
    if len(args) != 1:
        print('사용법: python3 -m scv_logger.core.finalize_cli <세션 폴더>', file=sys.stderr)
        sys.exit(2)
    m = Session(Path(args[0])).finalize()
    print(m.get('status', ''))


if __name__ == '__main__':
    main()

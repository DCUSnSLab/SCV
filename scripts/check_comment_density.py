#!/usr/bin/env python3
"""Hold the comment budget of the repository this runs in.

The budget is scripts/comment_budget/<repository>.txt in SCV, next to this script; a
repository with no budget file has no budget, and the check passes it by. The file names the
packages measured, the directories under them and the suffixes counted as well as the limits.

`file` caps the comment/code ratio of every file. `density` and `block` are ratchets. Whole-tree comment density may not rise, and no file may grow a
comment block longer than the limit. Neither says a comment is wrong; they say the tree may not
accumulate more of them than it has, which is the only thing a checker can decide without
reading them. Why the numbers exist at all is in the budget file.

A file listed as block-exempt records the block it already has. That number may only shrink,
so an exemption decays rather than becoming permission.
"""

import ast
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(
    subprocess.run(
        ["git", "rev-parse", "--show-toplevel"], capture_output=True, text=True, check=True
    ).stdout.strip()
)
BUDGET = Path(__file__).resolve().parent / "comment_budget" / f"{ROOT.name}.txt"
# A line that is only a comment. A trailing comment after code is not counted: it annotates
# the line it sits on rather than standing in for prose.
SLASH = re.compile(r"^\s*//")
HASH = re.compile(r"^\s*#")
HASH_SUFFIXES = {".py", ".yaml", ".yml", ".sh", ".cmake"}


def sources(packages, subdirs, suffixes):
    for pkg in packages:
        for sub in subdirs:
            d = ROOT / pkg / sub
            if not d.is_dir():
                continue
            for path in sorted(d.rglob("*")):
                if path.suffix in suffixes:
                    yield path


def docstring_lines(text):
    lines = set()
    for node in ast.walk(ast.parse(text)):
        if isinstance(node, (ast.Module, ast.ClassDef, ast.FunctionDef, ast.AsyncFunctionDef)):
            if ast.get_docstring(node) is not None:
                doc = node.body[0]
                lines.update(range(doc.lineno, doc.end_lineno + 1))
    return lines


def measure(path):
    """(comment lines, code lines, longest run of consecutive comment lines)."""
    text = path.read_text()
    comment = HASH if path.suffix in HASH_SUFFIXES else SLASH
    docs = docstring_lines(text) if path.suffix == ".py" else set()
    comments = code = longest = run = 0
    for lineno, line in enumerate(text.splitlines(), 1):
        stripped = line.strip()
        if not stripped:
            run = 0  # a blank line ends a block, so two paragraphs are not read as one
            continue
        if (comment.match(line) and not line.startswith("#!")) or lineno in docs:
            comments += 1
            run += 1
            longest = max(longest, run)
        else:
            code += 1
            run = 0
    return comments, code, longest


def budget():
    density = None
    file_ratio = None
    block = None
    exempt = {}
    packages = []
    subdirs = []
    suffixes = set()
    for lineno, line in enumerate(BUDGET.read_text().splitlines(), 1):
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        parts = line.split()
        if parts[0] == "density" and len(parts) == 2:
            density = float(parts[1])
        elif parts[0] == "file" and len(parts) == 2:
            file_ratio = float(parts[1])
        elif parts[0] == "subdirs" and len(parts) > 1:
            subdirs += parts[1:]
        elif parts[0] == "block" and len(parts) == 2:
            block = int(parts[1])
        elif parts[0] == "block-exempt" and len(parts) == 3:
            exempt[parts[1]] = int(parts[2])
        elif parts[0] == "packages" and len(parts) > 1:
            packages += parts[1:]
        elif parts[0] == "suffixes" and len(parts) > 1:
            suffixes.update(parts[1:])
        else:
            raise SystemExit(f"{BUDGET}:{lineno}: cannot read '{line}'")
    if (density is None and file_ratio is None) or block is None or not packages or not suffixes:
        raise SystemExit(
            f"{BUDGET}: 'density' or 'file', and 'block', 'packages', 'suffixes' must be set"
        )
    return density, file_ratio, block, exempt, packages, subdirs or ["src", "include"], suffixes


def main():
    if not BUDGET.is_file():
        return 0
    max_density, max_file, max_block, exempt, packages, subdirs, suffixes = budget()
    errors = []
    total_comments = total_code = 0
    seen = set()

    for path in sources(packages, subdirs, suffixes):
        rel = path.relative_to(ROOT).as_posix()
        comments, code, longest = measure(path)
        if max_file is not None and code and comments / code > max_file:
            errors.append(
                f"{rel}: comment ratio {comments / code:.2f} ({comments}/{code}) is above "
                f"{max_file:.2f}; delete a comment or say it in code"
            )
        total_comments += comments
        total_code += code
        limit = exempt.get(rel, max_block)
        if rel in exempt:
            seen.add(rel)
        if longest > limit:
            where = "its recorded exemption" if rel in exempt else "the limit"
            errors.append(
                f"{rel}: a comment block of {longest} lines exceeds {where} of {limit}; "
                "move the prose to docs/ or shorten it"
            )

    for rel in sorted(set(exempt) - seen):
        errors.append(
            f"{BUDGET}: block-exempt names {rel}, which is not a source file here -- "
            "drop the row rather than leaving an exemption nothing applies to"
        )

    if total_code == 0:
        raise SystemExit("no sources measured -- the layout changed")
    density = total_comments / total_code
    # Rounded to the recorded precision so a one-line edit does not trip on a third decimal.
    if max_density is not None and round(density, 3) > max_density:
        errors.append(
            f"comment density {density:.3f} ({total_comments}/{total_code}) is above the budget "
            f"of {max_density:.3f}; this number is a ratchet, so lower it or delete a comment"
        )

    for e in errors:
        print(e, file=sys.stderr)
    if errors:
        return 1
    print(
        f"comment density {density:.3f} ({total_comments}/{total_code}), "
        "every file and block within budget"
    )
    return 0


if __name__ == "__main__":
    sys.exit(main())

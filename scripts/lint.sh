#!/usr/bin/env bash
# Runs this repository's linters and formatters on the files under the given paths, including a
# repository from dependencies.repos. Those are in .gitignore, so ruff, prettier and yamllint would
# skip them; this run lifts that.
# Usage: scripts/lint.sh PATH...
set -eu
root=$(cd "$(dirname "$0")/.." && pwd)
[ $# -gt 0 ] || {
  echo "usage: scripts/lint.sh PATH..."
  exit 2
}

files=()
for path in "$@"; do
  path=$(realpath "$path")
  dir=$path
  [ -d "$dir" ] || dir=$(dirname "$path")
  top=$(git -C "$dir" rev-parse --show-toplevel)
  while IFS= read -r file; do
    # Vendored code keeps the style of the project it came from.
    case /$file in */thirdparty/*) continue ;; esac
    files+=("$(realpath --relative-to="$root" "$top/$file")")
  done < <(git -C "$top" ls-files -co --exclude-standard -- "$(realpath --relative-to="$top" "$path")")
done
[ ${#files[@]} -gt 0 ] || {
  echo "no files under $*"
  exit 0
}

work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT
sed 's/^ignore-from-file: .*/ignore-from-file: .yamllintignore/' "$root/.yamllint.yaml" >"$work/yamllint.yaml"
python3 - "$root" "$work" <<'EOF'
import sys

import yaml

root, work = sys.argv[1:]
with open(f"{root}/.pre-commit-config.yaml") as stream:
    config = yaml.safe_load(stream)
extra = {
    "ruff-format": ["--no-force-exclude"],
    "prettier": ["--ignore-path", ".prettierignore"],
}
for repo in config["repos"]:
    for hook in repo["hooks"]:
        if hook["id"] == "yamllint":
            hook["args"] = ["-c", f"{work}/yamllint.yaml"]
        hook["args"] = hook.get("args", []) + extra.get(hook["id"], [])
with open(f"{work}/pre-commit-config.yaml", "w") as stream:
    yaml.safe_dump(config, stream, sort_keys=False)
EOF

cd "$root"
export SCV_ROOT="$root"
status=0
pre-commit run -c "$work/pre-commit-config.yaml" --files "${files[@]}" || status=1
pre-commit run -c "$root/.pre-commit-workspace.yaml" --files "${files[@]}" || status=1
exit "$status"

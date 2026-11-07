#!/usr/bin/env bash
# Point git's hooks of SCV and the named repositories under it (default: SCV) at
# githooks/. Open-source forks keep their upstream style and get no hooks. Local git configuration
# only; nothing is committed to the repositories.
set -eu
root=$(cd "$(dirname "$0")/.." && pwd)
repos=("$@")
[ ${#repos[@]} -eq 0 ] && repos=(.)
for r in "${repos[@]}"; do
  git -C "$root/$r" config core.hooksPath "$root/githooks"
  echo "$r: core.hooksPath -> $root/githooks"
done

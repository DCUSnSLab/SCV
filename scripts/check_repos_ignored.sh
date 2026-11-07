#!/usr/bin/env bash
# Every repository in dependencies.repos must be in .gitignore, or SCV would start tracking its files.
set -u
repos=${1:-dependencies.repos}
status=0
while read -r path; do
  if ! git check-ignore -q --no-index "src/$path/"; then
    echo "src/$path is in $repos but not in .gitignore"
    status=1
  fi
done < <(sed -n 's/^  \([^ ][^:]*\):$/\1/p' "$repos")
exit "$status"

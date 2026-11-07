#!/usr/bin/env bash
# Every file under docs/ must be tracked. An untracked document looks finished in the working tree
# and does not exist for anyone who clones. .gitignore still wins: an ignored file is not reported.
set -euo pipefail

cd "$(git rev-parse --show-toplevel)"

untracked=$(git ls-files --others --exclude-standard -- docs/)
if [ -n "$untracked" ]; then
  echo "untracked files under docs/ -- git add them, or ignore them deliberately:" >&2
  echo "${untracked//$'\n'/$'\n'  }" | sed '1s/^/  /' >&2
  exit 1
fi

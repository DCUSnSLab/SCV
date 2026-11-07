#!/usr/bin/env bash
# Hangul belongs in .md files only. Code, scripts, configuration and their comments, strings and
# messages are English, so a reader of any non-document file needs one language.
set -u

files=("$@")
if [ ${#files[@]} -eq 0 ]; then
  mapfile -t files < <(git ls-files | grep -v '^thirdparty/' | while IFS= read -r f; do [ -e "$f" ] && printf '%s\n' "$f"; done)
fi
targets=()
for f in "${files[@]}"; do
  case "$f" in
  *.md) ;;
  *) targets+=("$f") ;;
  esac
done
[ ${#targets[@]} -eq 0 ] && exit 0

if locale -a 2>/dev/null | grep -qx 'C.utf8'; then
  export LC_ALL=C.utf8
fi
stderr=$(mktemp)
hits=$(grep -InP -d skip '[\x{AC00}-\x{D7A3}\x{1100}-\x{11FF}\x{3130}-\x{318F}]' "${targets[@]}" 2>"$stderr")
rc=$?
if [ "$rc" -ge 2 ]; then
  echo "check_hangul_md_only.sh could not run (grep exit $rc) -- treating as failure:"
  sed 's/^/  /' "$stderr"
  rm -f "$stderr"
  exit 1
fi
rm -f "$stderr"
if [ -n "$hits" ]; then
  echo "hangul outside .md files (scripts/check_hangul_md_only.sh):"
  echo "$hits" | head -40 | sed 's/^/  /'
  exit 1
fi
exit 0

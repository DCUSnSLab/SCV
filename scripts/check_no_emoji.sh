#!/usr/bin/env bash
# Allow-list, not a block-list. The block-list this replaced named three Dingbats ranges and four
# singletons, so it let through everything else in Dingbats and Miscellaneous Symbols and Arrows
# -- U+2714, U+2757, U+27A1 and U+2B50 among them. A list of what is banned is only ever as good
# as the last person who thought of a character; a list of what is allowed fails closed.
#
# What is allowed: ASCII, Hangul (syllables and jamo), and the typographic characters this
# repository already uses. Adding a row is a decision, and the diff shows it.
set -u

allowed='\x00-\x7F'                           # ascii
allowed+='\x{AC00}-\x{D7A3}'                  # hangul syllables
allowed+='\x{1100}-\x{11FF}\x{3130}-\x{318F}' # hangul jamo
allowed+='\x{00A7}'                           # section sign, for doc cross-references
allowed+='\x{00B2}\x{00B7}\x{00D7}'           # superscript two, middle dot, multiplication sign
allowed+='\x{03A3}\x{03BC}'                   # sigma, mu
allowed+='\x{2014}'                           # em dash
allowed+='\x{2192}\x{2194}\x{21D2}'           # arrows used in tables
allowed+='\x{2500}\x{2502}\x{251C}\x{2514}'   # box drawing, for directory trees and diagrams
allowed+='\x{25B3}'                           # white up-pointing triangle, in support tables

files=("$@")
if [ ${#files[@]} -eq 0 ]; then
  # No arguments means every tracked file. The previous script read stdin here, so a bare run
  # checked nothing and said so by printing nothing -- a gate that passes by not running.
  # A tracked file deleted in the working tree is still listed, and grep exits 2 on it. Skip
  # what is not there to read.
  mapfile -t files < <(git ls-files | while IFS= read -r f; do [ -e "$f" ] && printf '%s\n' "$f"; done)
fi
[ ${#files[@]} -eq 0 ] && exit 0

# -I so a binary blob is not reported as a wall of disallowed bytes.
#
# grep exits 2 when it cannot run the pattern at all, and PCRE refuses the \x{...} classes above
# U+00FF unless the locale is UTF-8. Discarding that exit made this gate report success in the C
# locale -- it passed by not running. Distinguish it from 1 ("no match"), and ask for a UTF-8
# locale first so the common case does not depend on the caller's environment.
# The locale is this check's own business, not the caller's: which characters are allowed does
# not depend on how the invoking shell is set up.
if locale -a 2>/dev/null | grep -qx 'C.utf8'; then
  export LC_ALL=C.utf8
fi
# -d skip: git ls-files reports a submodule as one directory entry, and grep exits 2 on it. The
# submodule's files are checked by the same hook when the submodule commits.
stderr=$(mktemp)
hits=$(grep -InP -d skip "[^${allowed}]" "${files[@]}" 2>"$stderr")
rc=$?
if [ "$rc" -ge 2 ]; then
  echo "check_no_emoji.sh could not run (grep exit $rc) -- treating as failure, not as clean:"
  sed 's/^/  /' "$stderr"
  rm -f "$stderr"
  exit 1
fi
rm -f "$stderr"
if [ -n "$hits" ]; then
  echo "characters outside the allow-list (scripts/check_no_emoji.sh):"
  echo "$hits" | head -40 | sed 's/^/  /'
  exit 1
fi
exit 0

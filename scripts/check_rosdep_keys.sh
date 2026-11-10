#!/usr/bin/env bash
# Every dependency in the given package.xml files must be a package under src/ or a rosdep key.
# rosdep install stops at the first unknown key and installs nothing, so a wrong name such as
# <buildtool_depend>ament_python</buildtool_depend> breaks the setup of every new machine.
set -u
[ $# -eq 0 ] && exit 0
workspace=$(colcon list --base-paths src --names-only | tr '\n' ' ')
dirs=()
for f in "$@"; do dirs+=("$(dirname "$f")"); done
if ! rosdep install --simulate --rosdistro jazzy --ignore-src --from-paths "${dirs[@]}" \
  --skip-keys "$workspace" >/dev/null 2> >(grep -v -e DeprecationWarning -e pkg_resources >&2); then
  echo "rosdep cannot resolve the keys above; packages from dependencies.repos need vcs import first"
  exit 1
fi

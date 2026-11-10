#!/usr/bin/env bash
# realsense-ros needs librealsense 2.59, and ros-jazzy-librealsense2 is 2.58. Add the RealSense apt
# repository and point the rosdep key librealsense2 at its librealsense2-dev. The 2.58 package is
# removed because its headers in /opt/ros/jazzy/include would mix with the 2.59 library.
set -euo pipefail
yaml="$(cd "$(dirname "$0")" && pwd)/rosdep.yaml"
keyring=/etc/apt/keyrings/librealsenseai.gpg

sudo mkdir -p /etc/apt/keyrings
curl -sSf https://librealsense.realsenseai.com/Debian/librealsenseai.asc | gpg --dearmor | sudo tee "$keyring" >/dev/null
echo "deb [signed-by=$keyring] https://librealsense.realsenseai.com/Debian/apt-repo $(lsb_release -cs) main" |
  sudo tee /etc/apt/sources.list.d/librealsense.list >/dev/null
echo "yaml file://$yaml" | sudo tee /etc/ros/rosdep/sources.list.d/10-scv.list >/dev/null
sudo apt-get update
if dpkg-query -W -f='${db:Status-Abbrev}' ros-jazzy-librealsense2 2>/dev/null | grep -q '^.i'; then
  sudo apt-get remove -y ros-jazzy-librealsense2
fi
rosdep update

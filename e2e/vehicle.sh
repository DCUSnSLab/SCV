#!/bin/bash
# The vehicle container's entry: tierlink_edge toward the server, then the vehicle's nodes.
set -eo pipefail
# shellcheck source=/dev/null
source /opt/ros/jazzy/setup.bash
# shellcheck source=/dev/null
source "$E2E/.work/install/setup.bash"

# x265enc: the container has no GPU encoder.
share=$(ros2 pkg prefix teleop_epoch)/share/teleop_epoch/config
sed 's/element: "nvcudah265enc"/element: "x265enc"/' "$share/teleop_video.param.yaml" >/tmp/teleop_video.param.yaml

"$(ros2 pkg prefix tierlink)/lib/tierlink/tierlink_edge" \
  --params "$(ros2 pkg prefix tierlink)/share/tierlink/config/params.yaml" \
  --prefix scv/r01 --listen tcp/127.0.0.1:7447 \
  --connect "tcp/$SERVER:7447?rel=1" --connect "udp/$SERVER:7447?rel=0" &
exec ros2 launch "$E2E/vehicle.launch.py" video_params:=/tmp/teleop_video.param.yaml

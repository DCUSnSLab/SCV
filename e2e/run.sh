#!/bin/bash
# Builds the commits checked out under src/, starts the e2e pipeline (compose.yaml) and runs the
# operator's checks, on a clean link and then on shaped ones. Exit status 1 if a check failed.
#
# e2e/run.sh [--no-build] [--keep]
set -eo pipefail
cd "$(dirname "$0")/.."
export SCV=$PWD
export TIERLINK=$SCV/src/system/tierlink
build=1
keep=0
for a in "$@"; do
  case $a in
  --no-build) build=0 ;;
  --keep) keep=1 ;;
  *)
    echo "unknown argument $a" >&2
    exit 2
    ;;
  esac
done

if [ $build = 1 ]; then
  # A build of its own on ROS 2 alone: the workspace's build/ and install/ and whatever the
  # calling shell sourced stay out of it.
  rm -rf e2e/.work/install
  env -i HOME="$HOME" PATH=/usr/bin:/bin:"$HOME/.cargo/bin" bash -c '
    source /opt/ros/jazzy/setup.bash
    colcon --log-base e2e/.work/log build --build-base e2e/.work/build \
      --install-base e2e/.work/install --event-handlers console_cohesion- status- \
      --packages-up-to teleop_epoch fleet_telemetry hunter_mux sensor_dummy tierlink \
      --cmake-args -DBUILD_TESTING=OFF' >e2e/.work/build.log 2>&1 ||
    {
      tail -30 e2e/.work/build.log
      exit 1
    }
  cargo build --release --quiet --manifest-path "$TIERLINK/operator/Cargo.toml" --bin operator_check
fi

compose=(docker compose -p scv-e2e -f e2e/compose.yaml)
logs=e2e/.work/logs
mkdir -p "$logs"
# shellcheck disable=SC2329 # run by the EXIT trap
finish() {
  for s in zenohd fleetd vehicle; do "${compose[@]}" logs --no-color "$s" >"$logs/$s.log" 2>&1 || true; done
  [ "$keep" = 1 ] || "${compose[@]}" down -v --remove-orphans >/dev/null 2>&1
}
trap finish EXIT
"${compose[@]}" up -d --build --quiet-pull >"$logs/up.log" 2>&1 || {
  cat "$logs/up.log"
  exit 1
}

check=$TIERLINK/operator/target/release/operator_check
operator() {
  "${compose[@]}" exec -T operator "$check" \
    --connect "tcp/172.31.77.10:7447?rel=1,udp/172.31.77.10:7447?rel=0" "$@"
}
shape() {
  "${compose[@]}" exec -T vehicle tc qdisc replace dev eth0 root netem "$@"
  echo "-- vehicle uplink: netem $*"
}
clear_shape() {
  "${compose[@]}" exec -T vehicle tc qdisc del dev eth0 root 2>/dev/null || true
  echo "-- vehicle uplink: clean"
}

status=0
echo "-- clean link"
operator fleet video drive limit watchdog takeover stop estop lidar history || status=1
shape delay 200ms
operator degrade || status=1
clear_shape
shape loss 2%
operator loss || status=1
clear_shape
[ $status = 0 ] && echo "ALL PASSED" || echo "FAILED (logs in $logs)"
exit $status

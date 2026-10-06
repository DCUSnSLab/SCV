# D555 bringup

The SCV uses one Intel RealSense D555. The camera publishes synchronized color
and depth images, color-aligned depth, and a colorized point cloud.

```bash
cd /home/scv/SCV
source /opt/ros/humble/setup.bash
colcon build --symlink-install --packages-select bring_up
source install/setup.bash
ros2 launch bring_up d555.launch.py
```

Use `serial_no:=<serial>` when more than one RealSense device is connected.
Profiles can be selected with `depth_profile:=640,480,30` and
`color_profile:=640,480,30`.

Main outputs:

- `/camera/camera/color/image_raw`
- `/camera/camera/depth/image_rect_raw`
- `/camera/camera/aligned_depth_to_color/image_raw`
- `/camera/camera/depth/color/points`

The node publishes a TF tree rooted at `camera_link`. The fixed transform from
`camera_link` to the vehicle and `velodyne` frames is provided by
`hunter2_description/urdf/tf_mounts.xacro`; run the vehicle description with
`use_tf_mounts:=true` when visualizing both point clouds.

The full sensor launch also starts this D555 configuration by default:

```bash
ros2 launch bring_up sensors_start.launch.py
```

Pass `enable_d555:=false` to omit it, or `d555_serial_no:=<serial>` to select
a specific device.

## D555 + Velodyne BEV

`sensors_start.launch.py` also starts the fused BEV renderer. It transforms both
point clouds into the calibrated `velodyne` frame and publishes:

- `/bev/d555_velodyne/image` (`bgr8`)
- `/bev/d555_velodyne/mask` (`mono8`)

The image uses the D555's measured RGB and a height colormap for Velodyne. Image
up is vehicle forward (`+x`) and image left is vehicle left (`+y`). The full
sensor launch publishes the calibrated vehicle TF by default. If it is already
published by `hunter_start.launch.py`, avoid a duplicate publisher with:

```bash
ros2 launch bring_up sensors_start.launch.py enable_vehicle_tf:=false
```

When both sensor drivers and the vehicle TF are already running, launch only the
renderer with:

```bash
ros2 launch bring_up d555_velodyne_bev.launch.py
```

For efficiency, the D555 depth processing uses 2x decimation before publishing
the point cloud. The C++ BEV renderer samples every second remaining camera
point, accesses PointCloud2 data without Python copies, and renders each sensor
layer only when a new cloud arrives. Set `camera_stride:=1` on the standalone
BEV launch for maximum point density if CPU headroom permits.

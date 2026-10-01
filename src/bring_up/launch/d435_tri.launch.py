"""Launch the three upside-down D435if cameras of the front fan mount.

Frames: each node publishes images in d435_<pos>_color_optical_frame. Those
frames are defined by hunter2_description/urdf/tf_mounts.xacro (VLP-32C
extrinsic calibration, 2026-09-30) for the 180-degree rotated (upright)
images, so the driver's own TF is disabled (publish_tf: False).

Note: with rotation_filter enabled, realsense-ros publishes the color
CameraInfo of the un-rotated sensor (principal point not mirrored). Images and
TF are consistent; anything that projects with K should mirror cx/cy first
(cx' = width - 1 - cx, cy' = height - 1 - cy).
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

# position -> default serial number (mount positions confirmed 2026-09-29)
CAMERAS = (
    ('left', '239722073611'),
    ('center', '233522076130'),
    ('right', '239122073045'),
)


def generate_launch_description():
    # Argument names are prefixed with d435_: sensors_start.launch.py also
    # includes d555.launch.py, whose color_profile/depth_profile/initial_reset
    # would otherwise win (first declaration sets a launch configuration).
    # All three share one USB3 hub on the SCV (bus 4-2): at 30 fps the depth
    # streams starve (tested 2026-10-01). 1280x720 color + 848x480 depth at
    # 15 fps runs all three with no frame timeouts; 640x480 @ 30 fps also works.
    arguments = [
        DeclareLaunchArgument(
            'd435_color_profile', default_value='1280,720,15',
            description='Color profile formatted as width,height,fps.'),
        DeclareLaunchArgument(
            'd435_depth_profile', default_value='848,480,15',
            description='Depth profile formatted as width,height,fps.'),
        DeclareLaunchArgument('d435_enable_depth', default_value='true'),
        DeclareLaunchArgument('d435_initial_reset', default_value='false'),
    ]
    for pos, serial in CAMERAS:
        arguments.append(DeclareLaunchArgument(
            f'{pos}_serial_no', default_value=serial,
            description=f'Serial number of the {pos} D435if.'))

    actions = []
    # Stagger start-up; three D435 opening at once on one USB controller is a
    # common cause of power-state / busy errors.
    for i, (pos, _) in enumerate(CAMERAS):
        name = f'd435_{pos}'
        camera = Node(
            package='realsense2_camera',
            executable='realsense2_camera_node',
            namespace=name,
            name=name,
            output='screen',
            emulate_tty=True,
            parameters=[{
                # realsense-ros 4.56 builds frame ids from camera_name (not the
                # node name): d435_<pos>_color_optical_frame.
                'camera_name': name,
                'serial_no': ParameterValue(
                    LaunchConfiguration(f'{pos}_serial_no'), value_type=str),
                'initial_reset': ParameterValue(
                    LaunchConfiguration('d435_initial_reset'), value_type=bool),
                'enable_color': True,
                # This SCV wrapper revision enables IR and IMU by default; with
                # three cameras on one USB hub that starves the depth stream.
                'enable_infra1': False,
                'enable_infra2': False,
                'enable_gyro': False,
                'enable_accel': False,
                'enable_depth': ParameterValue(
                    LaunchConfiguration('d435_enable_depth'), value_type=bool),
                'align_depth.enable': ParameterValue(
                    LaunchConfiguration('d435_enable_depth'), value_type=bool),
                'rgb_camera.color_profile': ParameterValue(
                    LaunchConfiguration('d435_color_profile'), value_type=str),
                'depth_module.depth_profile': ParameterValue(
                    LaunchConfiguration('d435_depth_profile'), value_type=str),
                # Cameras are mounted upside down: publish upright images.
                'rotation_filter.enable': True,
                'rotation_filter.rotation': 180.0,
                # TF comes from tf_mounts.xacro (calibrated optical frames).
                'publish_tf': False,
            }],
        )
        actions.append(TimerAction(period=3.0 * i, actions=[camera]))

    return LaunchDescription(arguments + actions)

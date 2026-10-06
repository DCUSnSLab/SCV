"""Launch the calibrated front Intel RealSense D555."""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    arguments = [
        DeclareLaunchArgument(
            'serial_no', default_value='',
            description=(
                'D555 serial number. Empty selects the connected D555.')),
        DeclareLaunchArgument('initial_reset', default_value='false'),
        DeclareLaunchArgument(
            'depth_profile', default_value='0,0,0',
            description='Depth profile formatted as width,height,fps.'),
        DeclareLaunchArgument(
            'color_profile', default_value='0,0,0',
            description='Color profile formatted as width,height,fps.'),
        DeclareLaunchArgument(
            'allow_no_texture_points', default_value='false',
            description='Keep depth points outside the color image FOV.'),
    ]

    # The camera name intentionally produces /camera/camera topics and a
    # camera_link root frame. camera_link is calibrated to Velodyne in
    # hunter2_description/urdf/tf_mounts.xacro.
    camera = Node(
        package='realsense2_camera',
        executable='realsense2_camera_node',
        namespace='camera',
        name='camera',
        output='screen',
        emulate_tty=True,
        parameters=[{
            # This wrapper revision reads the selection filter using its
            # internal parameter name (with a leading underscore).
            '_device_type': 'd555',
            'serial_no': ParameterValue(
                LaunchConfiguration('serial_no'), value_type=str),
            'initial_reset': ParameterValue(
                LaunchConfiguration('initial_reset'), value_type=bool),
            'enable_color': True,
            'enable_depth': True,
            'enable_sync': True,
            'align_depth.enable': True,
            # Quarter the depth/point-cloud pixel count before DDS transport.
            # At 5 cm/pixel BEV resolution this retains ample spatial detail.
            'decimation_filter.enable': True,
            'decimation_filter.filter_magnitude': 2,
            'pointcloud.enable': True,
            # Explicitly texture the depth cloud with the RGB camera. D555's
            # runtime defaults can otherwise select stream 0/index -1 and
            # publish XYZ-only PointCloud2 messages without an rgb field.
            'pointcloud.stream_filter': 2,
            'pointcloud.stream_index_filter': 0,
            'pointcloud.allow_no_texture_points': ParameterValue(
                LaunchConfiguration('allow_no_texture_points'),
                value_type=bool),
            'depth_module.depth_profile': ParameterValue(
                LaunchConfiguration('depth_profile'), value_type=str),
            'rgb_camera.color_profile': ParameterValue(
                LaunchConfiguration('color_profile'), value_type=str),
            'publish_tf': True,
            'base_frame_id': 'link',
        }],
    )

    return LaunchDescription(arguments + [camera])

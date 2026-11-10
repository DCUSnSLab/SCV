"""depth_anything3_multiview_trt on several cameras.

ros2 launch depth_anything3_multiview_trt depth_anything3_multiview_trt.launch.py \
    param_file:=<model>.param.yaml input_images:=<topic0>,<topic1>,... \
    [container:=/<running container>]

input_images: one topic per view, view 0 first.
Copy config/depth_anything3_multiview_trt.param.yaml and set tensorrt.onnx_path. Without container it starts
a capa_component_container, which flux needs.
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import ComposableNodeContainer, LoadComposableNodes
from launch_ros.descriptions import ComposableNode
from launch_ros.substitutions import FindPackageShare


def launch_setup(context):
    topics = LaunchConfiguration('input_images').perform(context).split(',')
    node = ComposableNode(
        package='depth_anything3_multiview_trt',
        plugin='depth_anything3_multiview_trt::DepthAnything3MultiviewTrt',
        name='depth_anything3_multiview_trt',
        parameters=[LaunchConfiguration('param_file')],
        remappings=[(f'~/input/image_{i}', t) for i, t in enumerate(topics)],
    )
    container = LaunchConfiguration('container').perform(context)
    if container:
        return [
            LoadComposableNodes(target_container=container, composable_node_descriptions=[node])
        ]
    return [
        ComposableNodeContainer(
            package='capa_ros',
            executable='capa_component_container',
            name='depth_anything3_multiview_trt_container',
            namespace='',
            composable_node_descriptions=[node],
            output='screen',
        )
    ]


def generate_launch_description():
    default_params = PathJoinSubstitution(
        [
            FindPackageShare('depth_anything3_multiview_trt'),
            'config',
            'depth_anything3_multiview_trt.param.yaml',
        ]
    )
    return LaunchDescription(
        [
            DeclareLaunchArgument('input_images'),
            DeclareLaunchArgument('container', default_value=''),
            DeclareLaunchArgument('param_file', default_value=default_params),
            OpaqueFunction(function=launch_setup),
        ]
    )

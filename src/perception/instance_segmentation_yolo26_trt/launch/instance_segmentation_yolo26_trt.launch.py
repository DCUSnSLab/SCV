"""instance_segmentation_yolo26_trt on one camera.

ros2 launch instance_segmentation_yolo26_trt instance_segmentation_yolo26_trt.launch.py \
    param_file:=<model>.param.yaml input_image:=<topic> \
    [container:=/<running container>]

Copy config/instance_segmentation_yolo26_trt.param.yaml and set tensorrt.onnx_path. Without container it starts
a capa_component_container, which flux needs.
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import ComposableNodeContainer, LoadComposableNodes
from launch_ros.descriptions import ComposableNode
from launch_ros.substitutions import FindPackageShare


def launch_setup(context):
    node = ComposableNode(
        package='instance_segmentation_yolo26_trt',
        plugin='instance_segmentation_yolo26_trt::InstanceSegmentationYolo26Trt',
        name='instance_segmentation_yolo26_trt',
        parameters=[LaunchConfiguration('param_file')],
        remappings=[('~/input/image', LaunchConfiguration('input_image'))],
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
            name='instance_segmentation_yolo26_trt_container',
            namespace='',
            composable_node_descriptions=[node],
            output='screen',
        )
    ]


def generate_launch_description():
    default_params = PathJoinSubstitution(
        [
            FindPackageShare('instance_segmentation_yolo26_trt'),
            'config',
            'instance_segmentation_yolo26_trt.param.yaml',
        ]
    )
    return LaunchDescription(
        [
            DeclareLaunchArgument('input_image'),
            DeclareLaunchArgument('container', default_value=''),
            DeclareLaunchArgument('param_file', default_value=default_params),
            OpaqueFunction(function=launch_setup),
        ]
    )

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Declare launch arguments
    input_topic_arg = DeclareLaunchArgument(
        'input_topic',
        default_value='/ackermann_like_controller/odom',
        description='Input odometry topic from gazebo controller'
    )
    
    output_topic_arg = DeclareLaunchArgument(
        'output_topic',
        default_value='/odom',
        description='Output odometry topic'
    )
    
    odom_frame_id_arg = DeclareLaunchArgument(
        'odom_frame_id',
        default_value='odom',
        description='Odometry frame ID'
    )
    
    base_frame_id_arg = DeclareLaunchArgument(
        'base_frame_id',
        default_value='base_link',
        description='Base frame ID'
    )
    
    publish_tf_arg = DeclareLaunchArgument(
        'publish_tf',
        default_value='true',
        description='Whether to publish TF transform'
    )

    # Create the gazebo_odom_node
    gazebo_odom_node = Node(
        package='gazebo_odom',
        executable='gazebo_odom_node',
        name='gazebo_odom_node',
        output='screen',
        parameters=[{
            'input_topic': LaunchConfiguration('input_topic'),
            'output_topic': LaunchConfiguration('output_topic'),
            'odom_frame_id': LaunchConfiguration('odom_frame_id'),
            'base_frame_id': LaunchConfiguration('base_frame_id'),
            'publish_tf': LaunchConfiguration('publish_tf')
        }]
    )

    # Static transform publisher: map -> odom
    map_to_odom_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='map_to_odom_tf',
        arguments=['0', '0', '0', '0', '0', '0', 'map', 'odom'],
        output='screen'
    )

    return LaunchDescription([
        input_topic_arg,
        output_topic_arg,
        odom_frame_id_arg,
        base_frame_id_arg,
        publish_tf_arg,
        gazebo_odom_node,
        map_to_odom_tf
    ])
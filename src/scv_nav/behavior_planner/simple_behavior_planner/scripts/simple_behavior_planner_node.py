#!/usr/bin/env python3
"""
Simple Behavior Planner Node
Handles path option execution and MPPI parameter control
"""
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

# ROS2 messages
from std_msgs.msg import Bool, Header, String
from geometry_msgs.msg import PoseStamped

# Custom messages
from simple_behavior_planner.msg import (
    PathList, PathOption, BehaviorControl, MPPIParams, TrafficLightState
)


class SimpleBehaviorPlannerNode(Node):
    """Simple behavior planner for path execution and controller parameter management"""
    
    def __init__(self):
        super().__init__('simple_behavior_planner')
        
        # QoS profiles
        reliable_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=5
        )
        
        transient_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            depth=1
        )
        
        # === State Variables ===
        self.path_list = None
        self.current_path_idx = 0
        self.traffic_light_state = None
        self.controller_goal_state = True # True = 도착, false = 진행중
        
        # Flags
        self.emergency_stop_flag = False

        # === Subscribers ===
        self.path_list_sub = self.create_subscription(
            PathList, '/path_list', self.path_list_callback, transient_qos)
        
        # self.traffic_light_sub = self.create_subscription(
        #     TrafficLightState, '/traffic_light_state', self.traffic_light_callback, reliable_qos)
        
        self.controller_goal_state_sub = self.create_subscription(
            Bool, '/controller_goal_state', self.controller_goal_state_callback, reliable_qos)
        
        # === Publishers ===
        self.goal_pub = self.create_publisher(
            PoseStamped, '/goal_pose', reliable_qos)

        self.behavior_control_pub = self.create_publisher(
            BehaviorControl, '/behavior_control', reliable_qos)
        
        # main callback
        self.control_timer = self.create_timer(0.05, self.control_callback)  # 20Hz
        
        self.get_logger().info('Simple Behavior Planner Node initialized - 20Hz control loop')
    
    def path_list_callback(self, msg: PathList):
        """Update path list from global planner"""
        self.path_list = msg
        self.current_path_idx = 0
        self.mission_completed = False
        self.get_logger().info(f'Received path list with {len(msg.paths)} paths')
    
    def traffic_light_callback(self, msg: TrafficLightState):
        """Update traffic light state from perception"""
        self.traffic_light_state = msg
    
    def controller_goal_state_callback(self, msg: String):
        self.controller_goal_state = msg.data
    
    def control_callback(self):
        """Main control loop - runs at 20Hz"""
        # TODO: Implement main behavior planning logic
        pass
    
    def process_current_path_option(self):
        """Process current path based on its option type"""
        # TODO: Implement path option processing
        pass
    
    def handle_normal_option(self):
        """Handle normal driving option"""
        # TODO: Implement normal driving logic
        pass

def main(args=None):
    rclpy.init(args=args)
    
    node = SimpleBehaviorPlannerNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
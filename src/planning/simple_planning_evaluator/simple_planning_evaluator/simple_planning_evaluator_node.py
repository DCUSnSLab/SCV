import json
import math
import signal

from diagnostic_msgs.msg import DiagnosticArray
from diagnostic_msgs.msg import DiagnosticStatus
from diagnostic_msgs.msg import KeyValue
from geometry_msgs.msg import Twist
from nav_msgs.msg import OccupancyGrid
from nav_msgs.msg import Odometry
from nav_msgs.msg import Path
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.qos import DurabilityPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import ReliabilityPolicy
from rclpy.signals import SignalHandlerOptions

from .evaluator import Evaluator


def yaw_of(q):
    return math.atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))


def seconds(stamp):
    return stamp.sec + 1e-9 * stamp.nanosec


class SimplePlanningEvaluator(Node):
    def __init__(self):
        super().__init__('simple_planning_evaluator')
        p = {
            name: self.declare_parameter(name, kind).value
            for name, kind in (
                ('footprint.circle_x', Parameter.Type.DOUBLE_ARRAY),
                ('footprint.radius', Parameter.Type.DOUBLE),
                ('occupied_threshold', Parameter.Type.INTEGER),
                ('curvature_min_step', Parameter.Type.DOUBLE),
                ('turn_deadband', Parameter.Type.DOUBLE),
                ('stuck.min_progress', Parameter.Type.DOUBLE),
                ('stuck.window_sec', Parameter.Type.DOUBLE),
                ('goal_tolerance', Parameter.Type.DOUBLE),
                ('publish_period_sec', Parameter.Type.DOUBLE),
                ('summary_path', Parameter.Type.STRING),
            )
        }
        self.occupied_threshold = p['occupied_threshold']
        self.period = p['publish_period_sec']
        self.summary_path = p['summary_path']
        self.evaluator = Evaluator(
            list(p['footprint.circle_x']),
            p['footprint.radius'],
            p['curvature_min_step'],
            p['turn_deadband'],
            (p['stuck.min_progress'], p['stuck.window_sec'], p['goal_tolerance']),
        )
        latched = QoSProfile(
            depth=1,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
        )
        self.create_subscription(Path, '~/input/route', self.on_route, latched)
        self.create_subscription(Path, '~/input/trajectory', self.on_trajectory, 1)
        self.create_subscription(OccupancyGrid, '~/input/grid', self.on_grid, 1)
        self.create_subscription(Odometry, '~/input/odometry', self.on_odometry, 10)
        self.create_subscription(Twist, '~/input/cmd_vel', self.on_cmd_vel, 10)
        self.metrics_pub = self.create_publisher(DiagnosticArray, '~/output/metrics', 1)
        self.create_timer(self.period, self.on_timer)

    def now(self):
        return self.get_clock().now().nanoseconds * 1e-9

    def on_route(self, msg):
        if len(msg.poses) < 2:
            self.get_logger().warn('ignoring a route of fewer than two poses')
            return
        self.evaluator.set_route(
            np.array([[p.pose.position.x, p.pose.position.y] for p in msg.poses])
        )

    def on_grid(self, msg):
        info = msg.info
        cells = np.asarray(msg.data, dtype=np.int8).reshape(info.height, info.width)
        rows, cols = np.nonzero(cells >= self.occupied_threshold)
        centers = np.column_stack(
            (
                info.origin.position.x + (cols + 0.5) * info.resolution,
                info.origin.position.y + (rows + 0.5) * info.resolution,
            )
        )
        self.evaluator.set_grid(centers)

    def on_trajectory(self, msg):
        if len(msg.poses) < 2:
            return
        t = np.array([seconds(p.header.stamp) for p in msg.poses])
        xy = np.array([[p.pose.position.x, p.pose.position.y] for p in msg.poses])
        yaw = np.array([yaw_of(p.pose.orientation) for p in msg.poses])
        self.evaluator.on_trajectory(t, xy, yaw)

    def on_odometry(self, msg):
        pose = msg.pose.pose
        self.evaluator.on_pose(
            seconds(msg.header.stamp), pose.position.x, pose.position.y, yaw_of(pose.orientation)
        )

    def on_cmd_vel(self, msg):
        self.evaluator.on_command(self.now(), msg.linear.x, msg.angular.z)

    def on_timer(self):
        self.evaluator.tick(self.now(), self.period)
        array = DiagnosticArray()
        array.header.stamp = self.get_clock().now().to_msg()
        for group, stats in self.evaluator.stats.items():
            status = DiagnosticStatus(
                name=f'{self.get_name()}: {group}', level=DiagnosticStatus.OK
            )
            status.message = f'{len(stats)} metrics'
            for name, stat in stats.items():
                for field, value in stat.summary().items():
                    status.values.append(KeyValue(key=f'{name}.{field}', value=f'{value:.6g}'))
            array.status.append(status)
        self.metrics_pub.publish(array)

    def write_summary(self):
        with open(self.summary_path, 'w') as out:
            json.dump(self.evaluator.summary(), out, indent=2)


def interrupt(signum, frame):
    raise KeyboardInterrupt


def main():
    # The rclpy handler can shut the context down inside spin, which then fails before the
    # summary is written. Both signals are set here: a background start inherits SIGINT ignored,
    # and launch follows SIGINT with SIGTERM.
    rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    signal.signal(signal.SIGINT, interrupt)
    signal.signal(signal.SIGTERM, interrupt)
    node = SimplePlanningEvaluator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        signal.signal(signal.SIGINT, signal.SIG_IGN)
        signal.signal(signal.SIGTERM, signal.SIG_IGN)
    node.write_summary()
    node.destroy_node()
    rclpy.try_shutdown()

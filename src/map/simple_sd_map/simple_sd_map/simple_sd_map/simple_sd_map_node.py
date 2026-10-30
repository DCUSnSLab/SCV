#!/usr/bin/env python3
from diagnostic_msgs.msg import KeyValue
from geometry_msgs.msg import Point
import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from simple_sd_map import osm
from simple_sd_map_msgs.msg import SdEdge, SdMap, SdNode
from std_msgs.msg import ColorRGBA, Header
from visualization_msgs.msg import Marker, MarkerArray


def key_values(tags):
    return [KeyValue(key=k, value=v) for k, v in tags.items()]


def to_msg(header, nodes, edges):
    return SdMap(
        header=header,
        nodes=[
            SdNode(id=n.id, x=n.x, y=n.y, latitude=n.latitude, longitude=n.longitude,
                   tags=key_values(n.tags))
            for n in nodes
        ],
        edges=[
            SdEdge(way_id=e.way_id, from_id=e.from_id, to_id=e.to_id, length=e.length,
                   tags=key_values(e.tags))
            for e in edges
        ],
    )


def markers(header, sd_map):
    def point(n):
        return Point(x=n.x, y=n.y, z=0.0)

    by_id = {n.id: n for n in sd_map.nodes}

    def base():
        m = Marker(header=header, ns="sd_map", action=Marker.ADD)
        m.pose.orientation.w = 1.0
        return m

    edges = base()
    edges.id = 0
    edges.type = Marker.LINE_LIST
    edges.scale.x = 0.3
    edges.color = ColorRGBA(r=0.1, g=0.8, b=0.3, a=1.0)
    edges.points = [point(by_id[i]) for e in sd_map.edges for i in (e.from_id, e.to_id)]

    nodes = base()
    nodes.id = 1
    nodes.type = Marker.SPHERE_LIST
    nodes.scale.x = nodes.scale.y = nodes.scale.z = 0.8
    nodes.color = ColorRGBA(r=1.0, g=1.0, b=1.0, a=1.0)
    nodes.points = [point(n) for n in sd_map.nodes]

    return MarkerArray(markers=[edges, nodes])


class SdMapNode(Node):
    def __init__(self):
        super().__init__("simple_sd_map")
        osm_file = self.declare_parameter("osm_file", rclpy.Parameter.Type.STRING).value
        frame_id = self.declare_parameter("frame_id", rclpy.Parameter.Type.STRING).value
        zone = self.declare_parameter("utm_zone", rclpy.Parameter.Type.INTEGER).value
        easting = self.declare_parameter("origin_easting", rclpy.Parameter.Type.DOUBLE).value
        northing = self.declare_parameter("origin_northing", rclpy.Parameter.Type.DOUBLE).value

        nodes, edges = osm.load(osm_file, zone, (easting, northing))
        header = Header(stamp=self.get_clock().now().to_msg(), frame_id=frame_id)
        sd_map = to_msg(header, nodes, edges)
        # Published once; transient local hands the map to subscribers that start later.
        latched = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE,
                             durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.map_pub = self.create_publisher(SdMap, "~/output/sd_map", latched)
        self.marker_pub = self.create_publisher(MarkerArray, "~/output/markers", latched)
        self.marker_pub.publish(markers(header, sd_map))
        self.map_pub.publish(sd_map)
        self.get_logger().info(f"{osm_file}: {len(nodes)} nodes, {len(edges)} edges")


def main():
    rclpy.init()
    try:
        rclpy.spin(SdMapNode())
    except (KeyboardInterrupt, ExternalShutdownException):
        pass


if __name__ == "__main__":
    main()

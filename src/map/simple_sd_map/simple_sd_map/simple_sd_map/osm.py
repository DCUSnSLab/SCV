"""OSM file -> SD map nodes and edges in a UTM frame shifted by origin."""

from dataclasses import dataclass
from dataclasses import field
import math
import xml.etree.ElementTree as ET

from pyproj import Transformer


@dataclass
class Node:
    id: int
    x: float
    y: float
    latitude: float
    longitude: float
    tags: dict = field(default_factory=dict)


@dataclass
class Edge:
    way_id: int
    from_id: int
    to_id: int
    length: float
    tags: dict = field(default_factory=dict)


def tags(el):
    return {t.get("k"): t.get("v") for t in el.findall("tag")}


def load(path, zone, origin):
    root = ET.parse(path).getroot()
    to_utm = Transformer.from_crs("EPSG:4326", f"EPSG:326{zone:02d}", always_xy=True)
    # JOSM keeps objects deleted from downloaded data in the file, marked action='delete'.
    live = lambda el: el.get("action") != "delete"  # noqa: E731

    nodes = {}
    for el in filter(live, root.findall("node")):
        lat, lon = float(el.get("lat")), float(el.get("lon"))
        easting, northing = to_utm.transform(lon, lat)
        node = Node(int(el.get("id")), easting - origin[0], northing - origin[1], lat, lon, tags(el))
        nodes[node.id] = node

    edges = []
    for way in filter(live, root.findall("way")):
        refs = [int(nd.get("ref")) for nd in way.findall("nd")]
        for a_id, b_id in zip(refs, refs[1:]):
            a, b = nodes[a_id], nodes[b_id]
            edges.append(
                Edge(int(way.get("id")), a_id, b_id, math.hypot(b.x - a.x, b.y - a.y), tags(way))
            )
    return list(nodes.values()), edges

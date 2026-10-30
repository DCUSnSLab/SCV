import math

from pyproj import Transformer
from simple_sd_map import osm

# Three live nodes about 11 m apart along a meridian, one node and one way deleted in JOSM.
OSM = """<?xml version='1.0' encoding='UTF-8'?>
<osm version='0.6' generator='JOSM'>
  <node id='-1' lat='35.9130' lon='128.8040'><tag k='kind' v='corner' /></node>
  <node id='-2' lat='35.9131' lon='128.8040' />
  <node id='-3' lat='35.9132' lon='128.8040' />
  <node id='-4' action='delete' lat='35.9140' lon='128.8040' />
  <way id='-10'><nd ref='-1' /><nd ref='-2' /><nd ref='-3' /><tag k='highway' v='footway' /></way>
  <way id='-11' action='delete'><nd ref='-3' /><nd ref='-4' /></way>
</osm>
"""


def load(tmp_path):
    path = tmp_path / "map.osm"
    path.write_text(OSM)
    to_utm = Transformer.from_crs("EPSG:4326", "EPSG:32652", always_xy=True)
    return osm.load(str(path), 52, to_utm.transform(128.8040, 35.9130))


def test_skips_what_josm_deleted(tmp_path):
    nodes, edges = load(tmp_path)
    assert [n.id for n in nodes] == [-1, -2, -3]
    assert [(e.from_id, e.to_id) for e in edges] == [(-1, -2), (-2, -3)]


def test_places_nodes_relative_to_the_origin(tmp_path):
    nodes, edges = load(tmp_path)
    assert math.hypot(nodes[0].x, nodes[0].y) < 1e-6
    assert 10.0 < nodes[1].y < 12.0
    assert edges[0].length == math.hypot(nodes[1].x - nodes[0].x, nodes[1].y - nodes[0].y)


def test_keeps_tags(tmp_path):
    nodes, edges = load(tmp_path)
    assert nodes[0].tags == {"kind": "corner"}
    assert edges[0].tags == {"highway": "footway"}

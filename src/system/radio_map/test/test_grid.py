import math

import pytest
from radio_map.grid import RadioMap

GOOD = {
    'rtt_p95_ms': 60.0,
    'loss_percent': 0.0,
    'longest_outage_ms': 80.0,
    'uplink_queue_p95_ms': 10.0,
}
BAD = {
    'rtt_p95_ms': 500.0,
    'loss_percent': 10.0,
    'longest_outage_ms': 900.0,
    'uplink_queue_p95_ms': math.nan,
}
LAT0, LON0 = 37.0, 127.0


def north(m):
    return LAT0 + m / 111320.0


def test_cells_keep_their_own_samples():
    rmap = RadioMap(cell_m=5.0, origin=(LAT0, LON0))
    for m in range(20):
        rmap.add(north(m + 0.5), LON0, BAD if 10 <= m < 15 else GOOD)
    bad = rmap.stats(rmap.cell_of(north(12), LON0))
    assert bad['rtt_p95_ms'] == 500.0
    assert bad['uplink_queue_p95_ms'] is None
    assert rmap.stats(rmap.cell_of(north(3), LON0))['rtt_p95_ms'] == 60.0
    assert rmap.stats(rmap.cell_of(north(30), LON0)) is None


def test_cell_outline_contains_its_samples():
    rmap = RadioMap(cell_m=5.0)
    rmap.add(north(7), LON0 + 0.0001, GOOD)
    rmap.add(north(17), LON0, BAD)
    features = rmap.to_geojson()['features']
    assert len(features) == 2
    for feature in features:
        ring = feature['geometry']['coordinates'][0]
        assert ring[0] == ring[-1]
        lats = [lat for _, lat in ring]
        assert max(lats) - min(lats) == pytest.approx(5.0 / 111320.0)

"""
Link samples grouped by grid cell of latitude and longitude, as drive tests map coverage.

The grid is flat around the first sample, which is accurate to well under a cell over a few km.
"""

import math

METRICS = ('rtt_p95_ms', 'loss_percent', 'longest_outage_ms', 'uplink_queue_p95_ms')
EARTH_M_PER_DEG = 111320.0


class RadioMap:
    def __init__(self, cell_m, origin=None):
        self.cell_m = cell_m
        self.origin = origin
        self.cells = {}

    def _m_per_deg_lon(self):
        return EARTH_M_PER_DEG * math.cos(math.radians(self.origin[0]))

    def cell_of(self, lat, lon):
        lat0, lon0 = self.origin
        x = (lon - lon0) * self._m_per_deg_lon()
        y = (lat - lat0) * EARTH_M_PER_DEG
        return math.floor(x / self.cell_m), math.floor(y / self.cell_m)

    def add(self, lat, lon, link):
        if self.origin is None:
            self.origin = (lat, lon)
        self.cells.setdefault(self.cell_of(lat, lon), []).append([link[m] for m in METRICS])

    def stats(self, key):
        """Return the sample count and the 90th percentile of each metric, or None."""
        rows = self.cells.get(key)
        if not rows:
            return None
        out = {'samples': len(rows)}
        for i, m in enumerate(METRICS):
            values = sorted(r[i] for r in rows if not math.isnan(r[i]))
            out[m] = values[min(len(values) - 1, int(0.9 * len(values)))] if values else None
        return out

    def corners(self, key):
        """Return the cell's outline as a closed ring of (lon, lat), as GeoJSON orders them."""
        lat0, lon0 = self.origin
        i, j = key
        ring = [(i, j), (i + 1, j), (i + 1, j + 1), (i, j + 1), (i, j)]
        return [
            (
                lon0 + a * self.cell_m / self._m_per_deg_lon(),
                lat0 + b * self.cell_m / EARTH_M_PER_DEG,
            )
            for a, b in ring
        ]

    def to_geojson(self):
        features = [
            {
                'type': 'Feature',
                'geometry': {'type': 'Polygon', 'coordinates': [self.corners(key)]},
                'properties': self.stats(key),
            }
            for key in sorted(self.cells)
        ]
        return {'type': 'FeatureCollection', 'features': features}

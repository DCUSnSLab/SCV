"""Planning metrics on numpy arrays, without ROS. Units are SI: m, s, rad."""

from collections import deque
import math

import numpy as np
from scipy.spatial import cKDTree


class Stat:
    def __init__(self):
        self.count = 0
        self.total = 0.0
        self.min = math.inf
        self.max = -math.inf

    def add(self, value):
        self.count += 1
        self.total += value
        self.min = min(self.min, value)
        self.max = max(self.max, value)

    def summary(self):
        if self.count == 0:
            return {'min': None, 'max': None, 'mean': None, 'count': 0}
        return {
            'min': self.min,
            'max': self.max,
            'mean': self.total / self.count,
            'count': self.count,
        }


def wrap(angle):
    return (angle + np.pi) % (2.0 * np.pi) - np.pi


def peak(values):
    return float(np.max(np.abs(values))) if len(values) else None


class Route:
    def __init__(self, xy):
        keep = np.concatenate(([True], np.linalg.norm(np.diff(xy, axis=0), axis=1) > 0.0))
        xy = xy[keep]
        self.start = xy[:-1]
        self.segment = np.diff(xy, axis=0)
        self.segment_length = np.linalg.norm(self.segment, axis=1)
        self.heading = np.arctan2(self.segment[:, 1], self.segment[:, 0])
        self.arc = np.concatenate(([0.0], np.cumsum(self.segment_length)))
        self.length = float(self.arc[-1])

    def project(self, points):
        """Arc length [m], signed lateral offset [m, left positive] and route heading [rad] of the
        nearest route point to each of points (M, 2)."""
        rel = points[:, None, :] - self.start[None, :, :]
        along = np.einsum('msk,sk->ms', rel, self.segment) / self.segment_length**2
        along = np.clip(along, 0.0, 1.0)
        gap = rel - along[:, :, None] * self.segment[None, :, :]
        nearest = np.argmin(np.einsum('msk,msk->ms', gap, gap), axis=1)
        rows = np.arange(len(points))
        g = gap[rows, nearest]
        seg = self.segment[nearest]
        side = np.sign(seg[:, 0] * g[:, 1] - seg[:, 1] * g[:, 0])
        lateral = np.where(side == 0.0, 1.0, side) * np.linalg.norm(g, axis=1)
        arc = self.arc[nearest] + along[rows, nearest] * self.segment_length[nearest]
        return arc, lateral, self.heading[nearest]


def trajectory_shape(t, xy, yaw, min_step):
    """Per-trajectory peaks. Speed is the segment length over the segment time; curvature is the
    yaw change over the segment length, left undefined on segments shorter than min_step."""
    dt = np.diff(t)
    ds = np.linalg.norm(np.diff(xy, axis=0), axis=1)
    speed = ds / dt
    moving = ds > min_step
    curvature = wrap(np.diff(yaw))[moving] / ds[moving]
    mid = 0.5 * (t[1:] + t[:-1])
    accel = np.diff(speed) / np.diff(mid)
    jerk = np.diff(accel) / np.diff(0.5 * (mid[1:] + mid[:-1]))
    return {
        'max_curvature': peak(curvature),
        'max_lateral_accel': peak(speed[moving] ** 2 * curvature),
        'max_longitudinal_accel': peak(accel),
        'max_jerk': peak(jerk),
        'length': float(ds.sum()),
        'duration': float(t[-1] - t[0]),
    }


def lateral_difference(prev_t, prev_xy, prev_yaw, t, xy):
    """Mean and max distance [m] of xy from prev at the same times, across the heading of prev,
    over the times both cover. None when they do not overlap."""
    overlap = (t >= prev_t[0]) & (t <= prev_t[-1])
    if not overlap.any():
        return None
    times = t[overlap]
    px = np.interp(times, prev_t, prev_xy[:, 0])
    py = np.interp(times, prev_t, prev_xy[:, 1])
    pyaw = np.interp(times, prev_t, np.unwrap(prev_yaw))
    dx = xy[overlap, 0] - px
    dy = xy[overlap, 1] - py
    lateral = np.abs(-np.sin(pyaw) * dx + np.cos(pyaw) * dy)
    return float(lateral.mean()), float(lateral.max())


class Obstacles:
    def __init__(self, cells):
        self.tree = cKDTree(cells) if len(cells) else None

    def clearance(self, points, radius):
        """Distance [m] from each circle of radius at points (M, 2) to the nearest occupied cell
        center, negative inside. inf without occupied cells."""
        if self.tree is None:
            return np.full(len(points), math.inf)
        distance, _ = self.tree.query(points)
        return distance - radius


def footprint_centers(xy, yaw, circle_x):
    """Circle centers (N, C, 2) of the footprint at each pose."""
    offsets = np.asarray(circle_x)[None, :]
    return np.stack(
        (
            xy[:, 0:1] + offsets * np.cos(yaw)[:, None],
            xy[:, 1:2] + offsets * np.sin(yaw)[:, None],
        ),
        axis=2,
    )


class TurnSignFlips:
    def __init__(self, deadband):
        self.deadband = deadband
        self.last_sign = 0

    def update(self, turn):
        """True when turn changes side, skipping values within the deadband around zero."""
        if abs(turn) <= self.deadband:
            return False
        sign = 1 if turn > 0.0 else -1
        flipped = self.last_sign != 0 and sign != self.last_sign
        self.last_sign = sign
        return flipped


class Rates:
    def __init__(self):
        self.last = None

    def update(self, t, values):
        """Rates of change of values since the previous call, or None on the first call."""
        previous, self.last = self.last, (t, values)
        if previous is None or t <= previous[0]:
            return None
        return [(v - p) / (t - previous[0]) for v, p in zip(values, previous[1])]


class Progress:
    """Arc length over time and stuck intervals: windows of window_sec in which the arc length
    grew less than min_progress, while more than goal_tolerance of the route remained."""

    def __init__(self, min_progress, window_sec, goal_tolerance, route_length):
        self.min_progress = min_progress
        self.window_sec = window_sec
        self.goal_tolerance = goal_tolerance
        self.route_length = route_length
        self.history = deque()
        self.stuck_since = None
        self.last_t = None

    def finished(self, arc):
        return self.route_length - arc <= self.goal_tolerance

    def update(self, t, arc):
        """Returns (rate over the window [m/s] or None, duration of a stuck interval that ended
        here [s] or None)."""
        self.history.append((t, arc))
        self.last_t = t
        while len(self.history) > 1 and self.history[1][0] <= t - self.window_sec:
            self.history.popleft()
        t0, arc0 = self.history[0]
        if t - t0 < self.window_sec or self.finished(arc):
            return None, self.close(t)
        rate = (arc - arc0) / (t - t0)
        if arc - arc0 < self.min_progress:
            if self.stuck_since is None:
                self.stuck_since = t0
            return rate, None
        return rate, self.close(t)

    def close(self, t):
        if self.stuck_since is None:
            return None
        duration, self.stuck_since = t - self.stuck_since, None
        return duration

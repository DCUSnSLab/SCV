"""Metric state for one run, without ROS. Times are seconds on one clock."""

import math

import numpy as np

from .metrics import footprint_centers
from .metrics import lateral_difference
from .metrics import Obstacles
from .metrics import peak
from .metrics import Progress
from .metrics import Rates
from .metrics import Route
from .metrics import Stat
from .metrics import trajectory_shape
from .metrics import TurnSignFlips
from .metrics import wrap

GROUPS = ('trajectory', 'deviation', 'stability', 'obstacle', 'command', 'progress')


class Evaluator:
    def __init__(self, circle_x, radius, min_step, turn_deadband, progress_params):
        self.circle_x = circle_x
        self.radius = radius
        self.min_step = min_step
        self.progress_params = progress_params
        self.stats = {group: {} for group in GROUPS}
        self.flips = TurnSignFlips(turn_deadband)
        self.flip_count = 0
        self.flips_at_tick = 0
        self.commands_since_tick = 0
        self.rates = Rates()
        self.route = None
        self.obstacles = None
        self.previous = None
        self.progress = None
        self.arc = None
        self.started_at = None
        self.goal_reached_sec = None
        self.timeline = []

    def add(self, group, name, value):
        if value is not None and math.isfinite(value):
            self.stats[group].setdefault(name, Stat()).add(float(value))

    def set_route(self, xy):
        self.route = Route(xy)
        self.progress = Progress(*self.progress_params, self.route.length)
        self.arc = None
        self.started_at = None
        self.goal_reached_sec = None
        self.timeline = []

    def set_grid(self, cells):
        self.obstacles = Obstacles(cells)

    def on_trajectory(self, t, xy, yaw):
        for name, value in trajectory_shape(t, xy, yaw, self.min_step).items():
            self.add('trajectory', name, value)
        if self.route is not None:
            _, lateral, heading = self.route.project(xy)
            self.add('deviation', 'trajectory_max_lateral', peak(lateral))
            self.add('deviation', 'trajectory_max_heading', peak(wrap(yaw - heading)))
        if self.obstacles is not None:
            centers = footprint_centers(xy, yaw, self.circle_x)
            clearance = self.obstacles.clearance(centers.reshape(-1, 2), self.radius)
            per_pose = clearance.reshape(len(t), -1).min(axis=1)
            self.add('obstacle', 'min_clearance', per_pose.min())
            hits = np.flatnonzero(per_pose <= 0.0)
            if len(hits):
                self.add('obstacle', 'time_to_collision', t[hits[0]] - t[0])
        if self.previous is not None:
            difference = lateral_difference(*self.previous, t, xy)
            if difference is not None:
                self.add('stability', 'lateral_mean', difference[0])
                self.add('stability', 'lateral_max', difference[1])
        self.previous = (t, xy, yaw)

    def on_pose(self, t, x, y, yaw):
        if self.route is None:
            return
        arc, lateral, heading = self.route.project(np.array([[x, y]]))
        self.add('deviation', 'vehicle_lateral', abs(lateral[0]))
        self.add('deviation', 'vehicle_heading', abs(wrap(yaw - heading[0])))
        self.arc = float(arc[0])
        if self.started_at is None:
            self.started_at = t
        rate, stuck = self.progress.update(t, self.arc)
        self.add('progress', 'rate', rate)
        self.add('progress', 'stuck_interval', stuck)
        if self.goal_reached_sec is None and self.progress.finished(self.arc):
            self.goal_reached_sec = t - self.started_at

    def on_command(self, t, speed, turn):
        self.add('command', 'speed', speed)
        self.add('command', 'turn_rate', abs(turn))
        rates = self.rates.update(t, (speed, turn))
        if rates is not None:
            self.add('command', 'speed_change_rate', abs(rates[0]))
            self.add('command', 'turn_rate_change_rate', abs(rates[1]))
        self.flip_count += self.flips.update(turn)
        self.commands_since_tick += 1

    def tick(self, t, period):
        if self.commands_since_tick:
            self.add(
                'stability',
                'turn_sign_flips_per_sec',
                (self.flip_count - self.flips_at_tick) / period,
            )
        self.flips_at_tick = self.flip_count
        self.commands_since_tick = 0
        if self.arc is not None:
            self.timeline.append([round(t - self.started_at, 3), round(self.arc, 3)])

    def summary(self):
        if self.progress is not None and self.progress.last_t is not None:
            self.add('progress', 'stuck_interval', self.progress.close(self.progress.last_t))
        return {
            'metrics': {
                group: {name: stat.summary() for name, stat in stats.items()}
                for group, stats in self.stats.items()
            },
            'turn_sign_flips': self.flip_count,
            'route_length': None if self.route is None else self.route.length,
            'final_arc_length': self.arc,
            'goal_reached_sec': self.goal_reached_sec,
            'arc_length_over_time': self.timeline,
        }

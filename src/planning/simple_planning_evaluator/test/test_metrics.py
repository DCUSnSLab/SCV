import json
import math

import numpy as np
import pytest
from simple_planning_evaluator.evaluator import Evaluator
from simple_planning_evaluator.metrics import Obstacles
from simple_planning_evaluator.metrics import Progress
from simple_planning_evaluator.metrics import Rates
from simple_planning_evaluator.metrics import Route
from simple_planning_evaluator.metrics import Stat
from simple_planning_evaluator.metrics import TurnSignFlips
from simple_planning_evaluator.metrics import footprint_centers
from simple_planning_evaluator.metrics import lateral_difference
from simple_planning_evaluator.metrics import trajectory_shape

STEP = 0.1


def straight(speed, start_t=0.0, y=0.0, steps=30, start_x=0.0):
    t = start_t + STEP * np.arange(steps + 1)
    xy = np.column_stack((start_x + speed * (t - start_t), np.full(len(t), y)))
    return t, xy, np.zeros(len(t))


def test_stat_keeps_min_max_mean_and_count():
    stat = Stat()
    assert stat.summary() == {"min": None, "max": None, "mean": None, "count": 0}
    for value in (1.0, 3.0, None, 2.0):
        stat.add(value)
    assert stat.summary() == {"min": 1.0, "max": 3.0, "mean": 2.0, "count": 3}


def test_route_projection_gives_arc_signed_lateral_and_heading():
    route = Route(np.array([[0.0, 0.0], [5.0, 0.0], [5.0, 0.0], [5.0, 5.0]]))
    assert route.length == pytest.approx(10.0)
    arc, lateral, heading = route.project(np.array([[3.0, 0.5], [3.0, -0.5], [5.5, 2.0]]))
    assert arc == pytest.approx([3.0, 3.0, 7.0])
    assert lateral == pytest.approx([0.5, -0.5, -0.5])
    assert heading == pytest.approx([0.0, 0.0, math.pi / 2])


def test_shape_of_a_circle_at_constant_speed():
    radius, speed = 2.0, 1.5
    t = STEP * np.arange(31)
    angle = speed * t / radius
    xy = np.column_stack((radius * np.sin(angle), radius * (1.0 - np.cos(angle))))
    shape = trajectory_shape(t, xy, angle, 0.01)
    # The chord of each step is a little shorter than its arc.
    assert shape["max_curvature"] == pytest.approx(1.0 / radius, rel=1e-3)
    assert shape["max_lateral_accel"] == pytest.approx(speed**2 / radius, rel=1e-3)
    assert shape["max_longitudinal_accel"] == pytest.approx(0.0, abs=1e-9)
    assert shape["length"] == pytest.approx(speed * 3.0, rel=1e-3)
    assert shape["duration"] == pytest.approx(3.0)


def test_shape_of_constant_acceleration_and_of_a_stop():
    t = STEP * np.arange(31)
    xy = np.column_stack((0.5 * 0.8 * t**2, np.zeros(len(t))))
    shape = trajectory_shape(t, xy, np.zeros(len(t)), 0.01)
    assert shape["max_longitudinal_accel"] == pytest.approx(0.8)
    assert shape["max_jerk"] == pytest.approx(0.0, abs=1e-6)
    standing = trajectory_shape(t, np.zeros((31, 2)), np.zeros(31), 0.01)
    assert standing["max_curvature"] is None
    assert standing["length"] == 0.0


def test_lateral_difference_compares_at_the_same_times():
    prev = straight(1.0)
    t, xy, _ = straight(1.0, start_t=0.5, y=0.2, start_x=0.5)
    mean, peak = lateral_difference(*prev, t, xy)
    assert mean == pytest.approx(0.2)
    assert peak == pytest.approx(0.2)
    # Running ahead along the old plan is no lateral difference.
    t, xy, _ = straight(1.0, start_t=0.5, start_x=1.0)
    assert lateral_difference(*prev, t, xy)[1] == pytest.approx(0.0)
    t, xy, _ = straight(1.0, start_t=5.0)
    assert lateral_difference(*prev, t, xy) is None


def test_clearance_and_footprint_centers():
    obstacles = Obstacles(np.array([[2.0, 0.0]]))
    assert obstacles.clearance(np.array([[0.0, 0.0]]), 0.5) == pytest.approx([1.5])
    assert Obstacles(np.zeros((0, 2))).clearance(np.zeros((1, 2)), 0.5)[0] == math.inf
    centers = footprint_centers(np.array([[1.0, 1.0]]), np.array([math.pi / 2]), [-1.0, 1.0])
    assert centers[0].ravel() == pytest.approx([1.0, 0.0, 1.0, 2.0])


def test_turn_sign_flips_skip_the_deadband():
    flips = TurnSignFlips(0.05)
    assert [flips.update(w) for w in (0.2, 0.01, -0.01, 0.3, -0.2, 0.0, 0.1)] == [
        False,
        False,
        False,
        False,
        True,
        False,
        True,
    ]


def test_rates_of_change():
    rates = Rates()
    assert rates.update(0.0, (1.0, 0.0)) is None
    assert rates.update(0.5, (2.0, -1.0)) == pytest.approx([2.0, -2.0])


def test_progress_reports_a_stuck_interval_once_it_ends():
    progress = Progress(0.27, 5.0, 0.3, 30.0)
    results = [progress.update(0.1 * i, 0.5 * min(0.1 * i, 2.0)) for i in range(121)]
    assert all(stuck is None for _, stuck in results)
    assert progress.stuck_since == pytest.approx(1.5)
    rate, stuck = progress.update(12.1, 1.5)
    assert rate == pytest.approx(0.1, rel=0.05)
    assert stuck == pytest.approx(10.6)
    assert progress.stuck_since is None


def test_progress_is_not_stuck_at_the_goal():
    progress = Progress(0.3, 5.0, 0.3, 1.0)
    for i in range(100):
        assert progress.update(0.1 * i, 0.9) == (None, None)


def evaluator():
    return Evaluator([0.0], 0.5, 0.01, 0.05, (0.3, 5.0, 0.3))


def test_time_to_collision_is_the_first_pose_in_contact():
    e = evaluator()
    e.set_grid(np.array([[2.05, 0.0]]))
    e.on_trajectory(*straight(1.0))
    assert e.stats["obstacle"]["time_to_collision"].max == pytest.approx(1.6)
    assert e.stats["obstacle"]["min_clearance"].min == pytest.approx(-0.45)
    e.set_grid(np.array([[0.0, 5.0]]))
    e.on_trajectory(*straight(1.0, start_t=0.1))
    assert e.stats["obstacle"]["time_to_collision"].count == 1
    assert e.stats["stability"]["lateral_max"].max == pytest.approx(0.0)


def test_summary_is_json():
    e = evaluator()
    e.set_route(np.array([[0.0, 0.0], [10.0, 0.0]]))
    e.on_pose(0.0, 1.0, 0.2, 0.1)
    e.on_command(0.0, 1.0, 0.2)
    e.on_command(0.05, 1.0, -0.2)
    e.tick(1.0, 1.0)
    summary = json.loads(json.dumps(e.summary()))
    deviation = summary["metrics"]["deviation"]
    assert deviation["vehicle_lateral"]["max"] == pytest.approx(0.2)
    assert deviation["vehicle_heading"]["max"] == pytest.approx(0.1)
    assert summary["metrics"]["stability"]["turn_sign_flips_per_sec"]["max"] == 1.0
    assert summary["metrics"]["command"]["turn_rate_change_rate"]["max"] == pytest.approx(8.0)
    assert summary["arc_length_over_time"] == [[1.0, 1.0]]

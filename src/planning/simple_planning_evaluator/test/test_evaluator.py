import json
import math

import numpy as np
import pytest
from simple_planning_evaluator.evaluator import Evaluator

STEP = 0.1


def straight(speed, start_t=0.0, steps=30):
    t = start_t + STEP * np.arange(steps + 1)
    xy = np.column_stack((speed * (t - start_t), np.zeros(len(t))))
    return t, xy, np.zeros(len(t))


def evaluator():
    return Evaluator([0.0], 0.5, 0.01, 0.05, (0.3, 5.0, 0.3))


def test_add_skips_missing_and_non_finite_values():
    e = evaluator()
    for value in (1.0, None, math.nan, math.inf, 3.0):
        e.add('command', 'speed', value)
    assert e.stats['command']['speed'].summary() == {
        'min': 1.0,
        'max': 3.0,
        'mean': 2.0,
        'count': 2,
    }


def test_time_to_collision_is_the_first_pose_in_contact():
    e = evaluator()
    e.set_grid(np.array([[2.05, 0.0]]))
    e.on_trajectory(*straight(1.0))
    assert e.stats['obstacle']['time_to_collision'].max == pytest.approx(1.6)
    assert e.stats['obstacle']['min_clearance'].min == pytest.approx(-0.45)
    e.set_grid(np.array([[0.0, 5.0]]))
    e.on_trajectory(*straight(1.0, start_t=0.1))
    assert e.stats['obstacle']['time_to_collision'].count == 1
    assert e.stats['stability']['lateral_max'].max == pytest.approx(0.0)


def test_summary_is_json():
    e = evaluator()
    e.set_route(np.array([[0.0, 0.0], [10.0, 0.0]]))
    e.on_pose(0.0, 1.0, 0.2, 0.1)
    e.on_command(0.0, 1.0, 0.2)
    e.on_command(0.05, 1.0, -0.2)
    e.tick(1.0, 1.0)
    summary = json.loads(json.dumps(e.summary()))
    deviation = summary['metrics']['deviation']
    assert deviation['vehicle_lateral']['max'] == pytest.approx(0.2)
    assert deviation['vehicle_heading']['max'] == pytest.approx(0.1)
    assert summary['metrics']['stability']['turn_sign_flips_per_sec']['max'] == 1.0
    assert summary['metrics']['command']['turn_rate_change_rate']['max'] == pytest.approx(8.0)
    assert summary['arc_length_over_time'] == [[1.0, 1.0]]

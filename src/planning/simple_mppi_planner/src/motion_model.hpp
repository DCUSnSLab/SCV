#ifndef MOTION_MODEL_HPP_
#define MOTION_MODEL_HPP_

#include <algorithm>
#include <cmath>

namespace simple_mppi_planner
{

enum class MotionModel { Ackermann, Diff };

struct VehicleParams
{
  MotionModel model = MotionModel::Ackermann;
  double min_speed = 0.0;
  double max_speed = 0.0;
  double max_accel = 0.0;
  double max_decel = 0.0;
  // Pose frame x of the point that moves along its heading: the rear axle or the wheel axis.
  double kinematic_center_x = 0.0;

  // Ackermann only.
  double wheelbase = 0.0;
  double max_steer = 0.0;
  double steer_time_constant = 0.0;

  // Diff only.
  double max_angular_speed = 0.0;
  double max_angular_accel = 0.0;
};

// x, y and yaw describe the kinematic center. turn is the central steering angle [rad] for
// Ackermann and the yaw rate [rad/s] for diff.
struct State
{
  double x = 0.0;
  double y = 0.0;
  double yaw = 0.0;
  double speed = 0.0;
  double turn = 0.0;
};

struct Control
{
  double speed = 0.0;
  double turn = 0.0;
};

struct Twist2d
{
  double linear = 0.0;
  double angular = 0.0;
};

inline double max_turn(const VehicleParams & vehicle)
{
  return vehicle.model == MotionModel::Ackermann ? vehicle.max_steer : vehicle.max_angular_speed;
}

// The input pair bicycle model plus speed, integrated with its first-order steer
// lag. Upstream models a center of gravity; here the state is the rear axle, so there is no slip.
inline void step(const VehicleParams & vehicle, const Control & control, double dt, State * state)
{
  state->speed +=
    std::clamp(control.speed - state->speed, -vehicle.max_decel * dt, vehicle.max_accel * dt);
  double yaw_rate;
  if (vehicle.model == MotionModel::Ackermann) {
    state->turn += (control.turn - state->turn) * dt / vehicle.steer_time_constant;
    yaw_rate = state->speed * std::tan(state->turn) / vehicle.wheelbase;
  } else {
    const double limit = vehicle.max_angular_accel * dt;
    state->turn += std::clamp(control.turn - state->turn, -limit, limit);
    yaw_rate = state->turn;
  }
  state->x += state->speed * std::cos(state->yaw) * dt;
  state->y += state->speed * std::sin(state->yaw) * dt;
  state->yaw += yaw_rate * dt;
}

// angular is a yaw rate for both models. hunter_base turns it back into a steering angle from the
// ratio linear / angular, so the turning radius survives at any speed.
inline Twist2d to_twist(const VehicleParams & vehicle, const Control & control)
{
  if (vehicle.model == MotionModel::Ackermann) {
    return {control.speed, control.speed * std::tan(control.turn) / vehicle.wheelbase};
  }
  return {control.speed, control.turn};
}

// The turn state that matches measured motion. Below min_observable_speed the yaw rate says
// nothing about the steering angle, and a stopped Hunter holds its wheels straight.
inline double measured_turn(
  const VehicleParams & vehicle, double speed, double yaw_rate, double min_observable_speed)
{
  if (vehicle.model == MotionModel::Diff) {
    return yaw_rate;
  }
  if (std::abs(speed) < min_observable_speed) {
    return 0.0;
  }
  const double steer = std::atan(yaw_rate * vehicle.wheelbase / speed);
  return std::clamp(steer, -vehicle.max_steer, vehicle.max_steer);
}

}  // namespace simple_mppi_planner

#endif  // MOTION_MODEL_HPP_

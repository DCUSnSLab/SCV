#include "vehicle_model.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>

namespace sensor_dummy
{
namespace
{
constexpr double kSteerAngleTolerance = 0.005;  // hunter_messenger.hpp steer_angle_tolerance

double lag(double value, double target, double tau, double dt)
{
  return tau <= 0.0 ? target : value + (target - value) * (1.0 - std::exp(-dt / tau));
}
}  // namespace

MotionModel parse_motion_model(const std::string & name)
{
  if (name == "ackermann") {
    return MotionModel::Ackermann;
  }
  if (name == "diff") {
    return MotionModel::Diff;
  }
  throw std::invalid_argument("unknown motion model: " + name);
}

double twist_to_inner_steer(
  double linear, double angular, double wheelbase, double track, double max_steer_angle)
{
  if (angular == 0.0) {
    return 0.0;
  }
  const double radius = std::abs(linear) / std::abs(angular);
  const double sign = std::copysign(1.0, angular);
  if (radius - wheelbase < 0.0) {
    return sign * max_steer_angle;
  }
  double inner = std::atan(wheelbase / (radius - track / 2.0));
  if (linear < 0.0) {
    inner = -inner;
  }
  return sign * inner;
}

double inner_to_central_steer(double inner, double wheelbase, double track)
{
  if (std::abs(inner) <= kSteerAngleTolerance) {
    return 0.0;
  }
  const double radius = wheelbase / std::tan(std::abs(inner)) + track / 2.0;
  return std::copysign(std::atan(wheelbase / radius), inner);
}

double apply_dead_band(double value, double band)
{
  return std::abs(value) < band ? 0.0 : value;
}

VehicleModel::VehicleModel(const VehicleParams & params, const Pose2d & base_pose)
: params_(params), reference_(base_pose)
{
  const double offset = reference_offset();
  reference_.x += offset * std::cos(base_pose.yaw);
  reference_.y += offset * std::sin(base_pose.yaw);
}

double VehicleModel::reference_offset() const
{
  return params_.model == MotionModel::Ackermann ? params_.rear_axle_x : 0.0;
}

void VehicleModel::command(double t, double linear, double angular)
{
  pending_.push_back({t + params_.cmd_delay_s, linear, angular});
}

void VehicleModel::apply_due_commands(double t)
{
  while (!pending_.empty() && pending_.front().apply_t <= t) {
    target_linear_ = pending_.front().linear;
    target_angular_ = pending_.front().angular;
    pending_.pop_front();
  }
}

void VehicleModel::update_ackermann(double dt)
{
  const double limit = params_.max_steer_angle;
  const double inner = std::clamp(
    twist_to_inner_steer(target_linear_, target_angular_, params_.wheelbase, params_.track, limit),
    -limit, limit);
  const double central = inner_to_central_steer(inner, params_.wheelbase, params_.track);
  const double target =
    apply_dead_band(central, params_.steer_dead_band_rad) + params_.steer_bias_rad;
  steering_ = lag(steering_, target, params_.steer_tau_s, dt);
  yaw_rate_ = speed_ / params_.wheelbase * std::tan(steering_);
}

void VehicleModel::update_diff(double dt)
{
  const double limit = params_.max_linear_speed / (params_.track / 2.0);
  angular_ = lag(angular_, std::clamp(target_angular_, -limit, limit), params_.steer_tau_s, dt);
  yaw_rate_ = angular_;
}

void VehicleModel::step(double t, double dt)
{
  apply_due_commands(t);
  const double target_speed = apply_dead_band(
    std::clamp(target_linear_, -params_.max_linear_speed, params_.max_linear_speed),
    params_.speed_dead_band_mps);
  const double previous_speed = speed_;
  speed_ = lag(speed_, target_speed, params_.speed_tau_s, dt);
  acceleration_ = dt > 0.0 ? (speed_ - previous_speed) / dt : 0.0;

  if (params_.model == MotionModel::Ackermann) {
    update_ackermann(dt);
  } else {
    update_diff(dt);
  }

  const double mid_yaw = reference_.yaw + 0.5 * yaw_rate_ * dt;
  reference_.x += speed_ * std::cos(mid_yaw) * dt;
  reference_.y += speed_ * std::sin(mid_yaw) * dt;
  reference_.yaw = std::remainder(reference_.yaw + yaw_rate_ * dt, 2.0 * M_PI);
}

Pose2d VehicleModel::base_pose() const
{
  const double offset = -reference_offset();
  return {
    reference_.x + offset * std::cos(reference_.yaw),
    reference_.y + offset * std::sin(reference_.yaw), reference_.yaw};
}

}  // namespace sensor_dummy

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "distance_map.hpp"
#include "mppi_solver.hpp"

#include <cstdint>
#include <vector>

namespace simple_mppi_planner
{

// The values of config/simple_mppi_planner*.param.yaml.
inline VehicleParams hunter()
{
  VehicleParams v;
  v.model = MotionModel::Ackermann;
  v.max_speed = 1.5;
  v.max_accel = 0.8;
  v.max_decel = 1.0;
  v.kinematic_center_x = -0.28;
  v.wheelbase = 0.65;
  v.max_steer = 0.461;
  v.steer_time_constant = 0.2;
  return v;
}

inline VehicleParams diff_base()
{
  VehicleParams v;
  v.model = MotionModel::Diff;
  v.max_speed = 1.5;
  v.max_accel = 0.8;
  v.max_decel = 1.0;
  v.max_angular_speed = 1.5;
  v.max_angular_accel = 3.0;
  return v;
}

inline Footprint footprint_of(const VehicleParams & v)
{
  if (v.model == MotionModel::Ackermann) {
    return {{-0.298, -0.069, 0.161, 0.39}, 0.40};
  }
  return {{0.0}, 0.45};
}

inline MppiParams mppi_of(const VehicleParams & v, int threads)
{
  MppiParams m;
  m.sample_count = 1500;
  m.horizon_steps = 30;
  m.step_sec = 0.1;
  m.lambda = 0.3;
  m.alpha = 0.9;
  m.non_biased_rate = 0.1;
  m.noise_correlation = 0.9;
  m.speed_std = 0.4;
  m.turn_std = v.model == MotionModel::Ackermann ? 0.3 : 0.6;
  m.smoothing_half_window = 4;
  m.thread_count = threads;
  m.seed = 1;
  return m;
}

inline CostParams cost_params(const VehicleParams & v)
{
  CostParams c;
  c.terminal_heading = v.model == MotionModel::Ackermann ? 20.0 : 0.0;
  c.path_distance = 0.2;
  c.path_heading = 0.2;
  c.speed = 2.0;
  c.progress = 10.0;
  c.clearance = 20.0;
  c.clearance_margin = 0.5;
  c.collision = 1000.0;
  return c;
}

constexpr double kRouteSpacing = 0.2;
constexpr double kCruiseSpeed = 1.0;
constexpr double kStopDecel = 0.5;

// A fixed 40 x 40 m world around the origin at the resolution of the local grid.
class World
{
public:
  static constexpr int kSize = 400;
  static constexpr double kResolution = 0.1;
  static constexpr double kOrigin = -20.0;

  World() : cells_(std::size_t(kSize) * kSize, 0) {}

  void add_box(double min_x, double min_y, double max_x, double max_y)
  {
    for (int row = 0; row < kSize; ++row) {
      for (int col = 0; col < kSize; ++col) {
        const double x = kOrigin + (col + 0.5) * kResolution;
        const double y = kOrigin + (row + 0.5) * kResolution;
        if (x >= min_x && x <= max_x && y >= min_y && y <= max_y) {
          cells_[std::size_t(row) * kSize + col] = 100;
        }
      }
    }
  }

  DistanceMap distance_map() const
  {
    DistanceMap map;
    map.build({cells_.data(), kSize, kSize, kResolution, kOrigin, kOrigin, 50});
    return map;
  }

private:
  std::vector<std::int8_t> cells_;
};

}  // namespace simple_mppi_planner

#endif  // SCENE_HPP_

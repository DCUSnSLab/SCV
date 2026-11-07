#include "mppi_solver.hpp"

#include <omp.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

constexpr int kControlDim = 2;

}  // namespace

MppiSolver::MppiSolver(
  const MppiParams & mppi, const CostParams & cost, const VehicleParams & vehicle,
  const Footprint & footprint)
: mppi_(mppi),
  cost_(cost),
  vehicle_(vehicle),
  radius_(footprint.radius),
  // A rollout facing away from the route must not score better for standing still than for
  // driving, or a vehicle that cannot turn at zero speed never starts its turn. Diff can.
  min_speed_alignment_(vehicle.model == MotionModel::Ackermann ? 0.0 : -1.0),
  smoother_(mppi.smoothing_half_window),
  mean_(std::size_t(mppi.horizon_steps) * kControlDim, 0.0),
  issued_(std::size_t(mppi.smoothing_half_window) * kControlDim, 0.0),
  samples_(std::size_t(mppi.sample_count) * mppi.horizon_steps * kControlDim),
  scores_(mppi.sample_count),
  weights_(mppi.sample_count)
{
  for (const double x : footprint.circle_x) {
    circle_offsets_.push_back(x - vehicle.kinematic_center_x);
  }
  for (int i = 0; i < mppi.thread_count; ++i) {
    generators_.emplace_back(mppi.seed + i);
  }
}

void MppiSolver::reset()
{
  std::fill(mean_.begin(), mean_.end(), 0.0);
  std::fill(issued_.begin(), issued_.end(), 0.0);
}

void MppiSolver::sample_controls()
{
  const int biased_count = static_cast<int>((1.0 - mppi_.non_biased_rate) * mppi_.sample_count);
  const int length = mppi_.horizon_steps * kControlDim;
  const double turn_limit = max_turn(vehicle_);
  // Upstream draws each step independently, and its steer lag then averages the noise away: the
  // samples stay near the warm start and never reach around an obstacle. AR(1) noise holds a
  // turn long enough to matter, at the same variance.
  const double keep = mppi_.noise_correlation;
  const double fresh = std::sqrt(1.0 - keep * keep);
#pragma omp parallel for num_threads(mppi_.thread_count) schedule(static)
  for (int k = 0; k < mppi_.sample_count; ++k) {
    std::mt19937 & generator = generators_[omp_get_thread_num()];
    std::normal_distribution<double> normal(0.0, 1.0);
    double * u = samples_.data() + std::size_t(k) * length;
    // The non-biased samples ignore the warm start, which can hold the wrong side of an obstacle.
    const double bias = k < biased_count ? 1.0 : 0.0;
    double speed_noise = normal(generator);
    double turn_noise = normal(generator);
    for (int i = 0; i < length; i += kControlDim) {
      u[i] = std::clamp(
        bias * mean_[i] + mppi_.speed_std * speed_noise, vehicle_.min_speed, vehicle_.max_speed);
      u[i + 1] =
        std::clamp(bias * mean_[i + 1] + mppi_.turn_std * turn_noise, -turn_limit, turn_limit);
      speed_noise = keep * speed_noise + fresh * normal(generator);
      turn_noise = keep * turn_noise + fresh * normal(generator);
    }
  }
}

double MppiSolver::obstacle_cost(
  double x, double y, double c, double s, const DistanceMap & map, bool * hit) const
{
  double clearance = std::numeric_limits<double>::infinity();
  for (const double offset : circle_offsets_) {
    clearance = std::min(clearance, map.at(x + offset * c, y + offset * s) - radius_);
  }
  if (clearance <= 0.0) {
    *hit = true;
    return cost_.collision;
  }
  const double intrusion = std::max(0.0, cost_.clearance_margin - clearance);
  return cost_.clearance * intrusion * intrusion;
}

MppiSolver::Score MppiSolver::score(const double * controls, const Scene & scene) const
{
  Score result;
  State state = scene.start;
  int index = scene.route_index;
  double alignment = 1.0;
  for (int t = 0; t < mppi_.horizon_steps; ++t) {
    const double * u = controls + t * kControlDim;
    step(vehicle_, {u[0], u[1]}, mppi_.step_sec, &state);
    const double c = std::cos(state.yaw);
    const double s = std::sin(state.yaw);
    // The route is tracked by the pose frame origin, as the goal tolerance is.
    const double x = state.x - vehicle_.kinematic_center_x * c;
    const double y = state.y - vehicle_.kinematic_center_x * s;
    const auto squared_distance = [&](int i) {
      const RoutePoint & p = scene.route.point(i);
      return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
    };
    double best = squared_distance(index);
    while (index + 1 < scene.route.size()) {
      const double next = squared_distance(index + 1);
      if (next > best) {
        break;
      }
      best = next;
      ++index;
    }
    const RoutePoint & p = scene.route.point(index);
    alignment = c * p.cos_heading + s * p.sin_heading;
    // Speed along the route: plain speed would reward circling in front of a blocked route
    // over stopping there.
    const double speed_error = state.speed * std::max(alignment, min_speed_alignment_) - p.speed;
    result.cost += cost_.path_distance * best + cost_.path_heading * (1.0 - alignment) +
                   cost_.speed * speed_error * speed_error;
    result.cost += obstacle_cost(state.x, state.y, c, s, scene.map, &result.collided);
  }
  result.cost += cost_.progress * (scene.progress_goal - scene.route.point(index).arc);
  result.cost += cost_.terminal_heading * (1.0 - alignment);
  return result;
}

void MppiSolver::average_controls()
{
  // The control term covers turn only: on speed it would pull the vehicle to a stop,
  // which the zero nominal speed does not mean here.
  const double control_gain =
    mppi_.lambda * (1.0 - mppi_.alpha) / (mppi_.turn_std * mppi_.turn_std);
  const std::size_t length = std::size_t(mppi_.horizon_steps) * kControlDim;
  double min_cost = std::numeric_limits<double>::infinity();
  for (int k = 0; k < mppi_.sample_count; ++k) {
    const double * u = samples_.data() + k * length;
    double control_cost = 0.0;
    for (std::size_t i = 0; i < length; i += kControlDim) {
      control_cost += mean_[i + 1] * u[i + 1];
    }
    weights_[k] = scores_[k].cost + control_gain * control_cost;
    min_cost = std::min(min_cost, weights_[k]);
  }
  double total = 0.0;
  for (double & w : weights_) {
    w = std::exp(-(w - min_cost) / mppi_.lambda);
    total += w;
  }
  std::fill(mean_.begin(), mean_.end(), 0.0);
  for (int k = 0; k < mppi_.sample_count; ++k) {
    const double w = weights_[k] / total;
    const double * u = samples_.data() + k * length;
    for (std::size_t i = 0; i < length; ++i) {
      mean_[i] += w * u[i];
    }
  }
}

void MppiSolver::smooth_mean()
{
  const double * past = issued_.data();
  smoother_.smooth(past, mean_.data(), mppi_.horizon_steps, kControlDim);
  smoother_.smooth(past + 1, mean_.data() + 1, mppi_.horizon_steps, kControlDim);
  // The fit overshoots the limits that the samples were clamped to.
  const double turn_limit = max_turn(vehicle_);
  for (std::size_t i = 0; i < mean_.size(); i += kControlDim) {
    mean_[i] = std::clamp(mean_[i], vehicle_.min_speed, vehicle_.max_speed);
    mean_[i + 1] = std::clamp(mean_[i + 1], -turn_limit, turn_limit);
  }
}

void MppiSolver::remember(const Control & control)
{
  if (issued_.empty()) {
    return;
  }
  std::rotate(issued_.begin(), issued_.begin() + kControlDim, issued_.end());
  issued_[issued_.size() - kControlDim] = control.speed;
  issued_[issued_.size() - kControlDim + 1] = control.turn;
}

void MppiSolver::rollout(const State & start, std::vector<State> * states) const
{
  states->assign(1, start);
  State state = start;
  for (int t = 0; t < mppi_.horizon_steps; ++t) {
    step(vehicle_, {mean_[t * kControlDim], mean_[t * kControlDim + 1]}, mppi_.step_sec, &state);
    states->push_back(state);
  }
}

bool MppiSolver::adopt_best_safe_sample()
{
  int best = -1;
  double best_cost = std::numeric_limits<double>::infinity();
  for (int k = 0; k < mppi_.sample_count; ++k) {
    if (!scores_[k].collided && scores_[k].cost < best_cost) {
      best_cost = scores_[k].cost;
      best = k;
    }
  }
  if (best < 0) {
    return false;
  }
  const std::size_t length = std::size_t(mppi_.horizon_steps) * kControlDim;
  std::copy_n(samples_.begin() + best * length, length, mean_.begin());
  return true;
}

Solution MppiSolver::solve(
  const State & start, const ReferencePath & route, int route_index, const DistanceMap & map)
{
  const double reach = vehicle_.max_speed * mppi_.step_sec * mppi_.horizon_steps;
  const double progress_goal = std::min(route.point(route_index).arc + reach, route.length());
  const Scene scene{start, route, route_index, map, progress_goal};

  sample_controls();
  const std::size_t length = std::size_t(mppi_.horizon_steps) * kControlDim;
#pragma omp parallel for num_threads(mppi_.thread_count) schedule(static)
  for (int k = 0; k < mppi_.sample_count; ++k) {
    scores_[k] = score(samples_.data() + k * length, scene);
  }
  average_controls();
  smooth_mean();

  // The average of two ways around an obstacle can run straight into it, and so can the filter
  // bend a clear plan into one. A sample replaces the plan unfiltered: it is known to be clear.
  if (score(mean_.data(), scene).collided && !adopt_best_safe_sample()) {
    reset();
    return {};
  }
  const Control control{mean_[0], mean_[1]};
  remember(control);
  return {true, control};
}

}  // namespace simple_mppi_planner

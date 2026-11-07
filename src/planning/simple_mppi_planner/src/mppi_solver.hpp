#ifndef MPPI_SOLVER_HPP_
#define MPPI_SOLVER_HPP_

#include "distance_map.hpp"
#include "motion_model.hpp"
#include "reference_path.hpp"
#include "savitzky_golay.hpp"

#include <random>
#include <vector>

namespace simple_mppi_planner
{

struct MppiParams
{
  int sample_count = 0;
  int horizon_steps = 0;
  double step_sec = 0.0;
  double lambda = 0.0;
  double alpha = 0.0;
  double non_biased_rate = 0.0;
  double noise_correlation = 0.0;
  double speed_std = 0.0;
  double turn_std = 0.0;
  int smoothing_half_window = 0;
  int thread_count = 0;
  unsigned int seed = 0;
};

struct CostParams
{
  double path_distance = 0.0;
  double path_heading = 0.0;
  double speed = 0.0;
  double progress = 0.0;
  double clearance = 0.0;
  double clearance_margin = 0.0;
  double collision = 0.0;
  // Ackermann only; 0 for diff, which can turn where it stands.
  double terminal_heading = 0.0;
};

// Circles in the pose frame along its x axis.
struct Footprint
{
  std::vector<double> circle_x;
  double radius = 0.0;
};

struct Solution
{
  bool feasible = false;
  Control control;
};

class MppiSolver
{
public:
  MppiSolver(
    const MppiParams & mppi, const CostParams & cost, const VehicleParams & vehicle,
    const Footprint & footprint);

  // Drops the warm start, for a restart after a stop.
  void reset();

  Solution solve(
    const State & start, const ReferencePath & route, int route_index, const DistanceMap & map);

  // The kept plan: speed, turn, speed, turn, ... over the horizon, after the last solve.
  const std::vector<double> & plan() const { return mean_; }

  // The kinematic center along the kept plan from start: horizon_steps + 1 states, step_sec apart.
  void rollout(const State & start, std::vector<State> * states) const;

  double step_sec() const { return mppi_.step_sec; }

private:
  struct Score
  {
    double cost = 0.0;
    bool collided = false;
  };

  struct Scene
  {
    const State & start;
    const ReferencePath & route;
    int route_index;
    const DistanceMap & map;
    double progress_goal;
  };

  void sample_controls();
  Score score(const double * controls, const Scene & scene) const;
  double obstacle_cost(
    double x, double y, double c, double s, const DistanceMap & map, bool * hit) const;
  void average_controls();
  void smooth_mean();
  void remember(const Control & control);
  bool adopt_best_safe_sample();

  MppiParams mppi_;
  CostParams cost_;
  VehicleParams vehicle_;
  std::vector<double> circle_offsets_;
  double radius_;
  // cos(heading error) below this counts as this in the speed term.
  double min_speed_alignment_;
  SavitzkyGolay smoother_;

  std::vector<std::mt19937> generators_;
  std::vector<double> mean_;
  // The last issued controls, oldest first, in the layout of mean_.
  std::vector<double> issued_;
  std::vector<double> samples_;
  std::vector<Score> scores_;
  std::vector<double> weights_;
};

}  // namespace simple_mppi_planner

#endif  // MPPI_SOLVER_HPP_

#ifndef REFERENCE_PATH_HPP_
#define REFERENCE_PATH_HPP_

#include <utility>
#include <vector>

namespace simple_mppi_planner
{

struct RoutePoint
{
  double x = 0.0;
  double y = 0.0;
  // Direction to the next point, kept as cos and sin for the rollout.
  double cos_heading = 1.0;
  double sin_heading = 0.0;
  double arc = 0.0;
  double speed = 0.0;
};

// The route resampled at a fixed spacing, since simple_mission_planner sends only SD map nodes,
// which can be many meters apart.
class ReferencePath
{
public:
  ReferencePath() = default;
  ReferencePath(
    const std::vector<std::pair<double, double>> & waypoints, double spacing, double cruise_speed,
    double stop_decel);

  bool empty() const { return points_.empty(); }
  int size() const { return static_cast<int>(points_.size()); }
  const RoutePoint & point(int index) const { return points_[index]; }
  double length() const { return points_.back().arc; }

  int nearest(double x, double y) const;
  // Nearest index in [from, from + window]. The bound keeps a route that passes the same place
  // twice from jumping to the later pass.
  int advance(int from, double x, double y, int window) const;
  bool at_goal(int index, double x, double y, double tolerance) const;

private:
  std::vector<RoutePoint> points_;
};

}  // namespace simple_mppi_planner

#endif  // REFERENCE_PATH_HPP_

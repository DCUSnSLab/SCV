#include "reference_path.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

std::vector<RoutePoint> resample(
  const std::vector<std::pair<double, double>> & waypoints, double spacing)
{
  std::vector<RoutePoint> points;
  double walked = 0.0;
  for (std::size_t i = 0; i + 1 < waypoints.size(); ++i) {
    const auto [x0, y0] = waypoints[i];
    const auto [x1, y1] = waypoints[i + 1];
    const double length = std::hypot(x1 - x0, y1 - y0);
    while (points.size() * spacing < walked + length) {
      const double along = (points.size() * spacing - walked) / length;
      RoutePoint p;
      p.x = x0 + along * (x1 - x0);
      p.y = y0 + along * (y1 - y0);
      points.push_back(p);
    }
    walked += length;
  }
  RoutePoint last;
  last.x = waypoints.back().first;
  last.y = waypoints.back().second;
  points.push_back(last);
  return points;
}

}  // namespace

ReferencePath::ReferencePath(
  const std::vector<std::pair<double, double>> & waypoints, double spacing, double cruise_speed,
  double stop_decel)
: points_(resample(waypoints, spacing))
{
  for (std::size_t i = 1; i < points_.size(); ++i) {
    const double dx = points_[i].x - points_[i - 1].x;
    const double dy = points_[i].y - points_[i - 1].y;
    const double length = std::hypot(dx, dy);
    points_[i].arc = points_[i - 1].arc + length;
    points_[i - 1].cos_heading = dx / length;
    points_[i - 1].sin_heading = dy / length;
    points_[i].cos_heading = points_[i - 1].cos_heading;
    points_[i].sin_heading = points_[i - 1].sin_heading;
  }
  for (RoutePoint & p : points_) {
    p.speed = std::min(cruise_speed, std::sqrt(2.0 * stop_decel * (length() - p.arc)));
  }
}

int ReferencePath::nearest(double x, double y) const
{
  return advance(0, x, y, size());
}

int ReferencePath::advance(int from, double x, double y, int window) const
{
  int best = from;
  double best_distance = std::numeric_limits<double>::infinity();
  const int last = std::min(from + window, size() - 1);
  for (int i = from; i <= last; ++i) {
    const double distance = std::hypot(points_[i].x - x, points_[i].y - y);
    if (distance < best_distance) {
      best_distance = distance;
      best = i;
    }
  }
  return best;
}

bool ReferencePath::at_goal(int index, double x, double y, double tolerance) const
{
  const RoutePoint & goal = points_.back();
  return length() - points_[index].arc <= tolerance &&
         std::hypot(goal.x - x, goal.y - y) <= tolerance;
}

}  // namespace simple_mppi_planner

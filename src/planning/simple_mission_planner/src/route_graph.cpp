#include "route_graph.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

namespace simple_mission_planner
{

RouteGraph::RouteGraph(const std::vector<GraphNode> & nodes, const std::vector<GraphEdge> & edges)
{
  for (const auto & n : nodes) {
    pos_[n.id] = {n.x, n.y};
  }
  // OSM ways are stored in drawing order; the robot can drive a sidewalk both ways.
  for (const auto & e : edges) {
    neighbors_[e.from].emplace_back(e.to, e.length);
    neighbors_[e.to].emplace_back(e.from, e.length);
  }
}

std::optional<std::int64_t> RouteGraph::nearest(double x, double y) const
{
  std::optional<std::int64_t> best;
  double best_distance = std::numeric_limits<double>::infinity();
  for (const auto & [id, p] : pos_) {
    const double d = std::hypot(p.first - x, p.second - y);
    if (!best || d < best_distance) {
      best = id;
      best_distance = d;
    }
  }
  return best;
}

std::optional<std::vector<std::int64_t>> RouteGraph::astar(
  std::int64_t start, std::int64_t goal) const
{
  const auto & goal_pos = pos_.at(goal);
  const auto h = [&](std::int64_t id) {
    const auto & p = pos_.at(id);
    return std::hypot(goal_pos.first - p.first, goal_pos.second - p.second);
  };
  std::unordered_map<std::int64_t, double> cost{{start, 0.0}};
  std::unordered_map<std::int64_t, std::int64_t> parent;
  using Open = std::pair<double, std::int64_t>;
  std::priority_queue<Open, std::vector<Open>, std::greater<>> open;
  open.emplace(h(start), start);
  while (!open.empty()) {
    const std::int64_t id = open.top().second;
    open.pop();
    if (id == goal) {
      std::vector<std::int64_t> route{goal};
      for (auto p = parent.find(goal); p != parent.end(); p = parent.find(route.back())) {
        route.push_back(p->second);
      }
      std::reverse(route.begin(), route.end());
      return route;
    }
    const auto edges = neighbors_.find(id);
    if (edges == neighbors_.end()) {
      continue;
    }
    for (const auto & [next, length] : edges->second) {
      const double c = cost.at(id) + length;
      const auto known = cost.find(next);
      if (known == cost.end() || c < known->second) {
        cost[next] = c;
        parent[next] = id;
        open.emplace(c + h(next), next);
      }
    }
  }
  return std::nullopt;
}

}  // namespace simple_mission_planner

#ifndef ROUTE_GRAPH_HPP_
#define ROUTE_GRAPH_HPP_

#include <cstdint>
#include <optional>
#include <unordered_map>
#include <utility>
#include <vector>

namespace simple_mission_planner
{

struct GraphNode
{
  std::int64_t id;
  double x;
  double y;
};

struct GraphEdge
{
  std::int64_t from;
  std::int64_t to;
  double length;
};

// The SD map as a graph of node positions and edge lengths.
class RouteGraph
{
public:
  RouteGraph(const std::vector<GraphNode> & nodes, const std::vector<GraphEdge> & edges);

  // Empty for a map without nodes.
  std::optional<std::int64_t> nearest(double x, double y) const;
  // Node ids of the shortest route from start to goal, empty if goal is unreachable.
  std::optional<std::vector<std::int64_t>> astar(std::int64_t start, std::int64_t goal) const;

  const std::pair<double, double> & position(std::int64_t id) const { return pos_.at(id); }

private:
  std::unordered_map<std::int64_t, std::pair<double, double>> pos_;
  std::unordered_map<std::int64_t, std::vector<std::pair<std::int64_t, double>>> neighbors_;
};

}  // namespace simple_mission_planner

#endif  // ROUTE_GRAPH_HPP_

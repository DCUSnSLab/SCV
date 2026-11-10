#include "simple_mission_planner.hpp"

#include <rclcpp_components/register_node_macro.hpp>

#include <std_msgs/msg/header.hpp>

#include <cinttypes>
#include <vector>

namespace simple_mission_planner
{
namespace
{

using geometry_msgs::msg::PoseStamped;
using nav_msgs::msg::Odometry;
using nav_msgs::msg::Path;
using simple_sd_map_msgs::msg::SdMap;

constexpr std::size_t depth = 10;

Path to_path(
  const std_msgs::msg::Header & header, const RouteGraph & graph,
  const std::vector<std::int64_t> & ids, const geometry_msgs::msg::Pose & goal)
{
  Path path;
  path.header = header;
  for (const std::int64_t id : ids) {
    PoseStamped p;
    p.header = header;
    p.pose.position.x = graph.position(id).first;
    p.pose.position.y = graph.position(id).second;
    p.pose.orientation.w = 1.0;
    path.poses.push_back(p);
  }
  PoseStamped last;
  last.header = header;
  last.pose = goal;
  path.poses.push_back(last);
  return path;
}

}  // namespace

SimpleMissionPlanner::SimpleMissionPlanner(const rclcpp::NodeOptions & options)
: Node("simple_mission_planner", options)
{
  // sd_map and route change rarely; transient local hands them to late joiners.
  const auto latched = rclcpp::QoS(depth).reliable().transient_local();
  route_pub_ = create_publisher<Path>("~/output/route", latched);
  map_sub_ = create_subscription<SdMap>(
    "~/input/sd_map", latched, [this](const SdMap & msg) { on_map(msg); });
  odom_sub_ = create_subscription<Odometry>(
    "~/input/odometry", depth, [this](const Odometry & msg) { on_odom(msg); });
  goal_sub_ = create_subscription<PoseStamped>(
    "~/input/goal_pose", depth, [this](const PoseStamped & msg) { on_goal(msg); });
}

void SimpleMissionPlanner::on_map(const SdMap & msg)
{
  std::vector<GraphNode> nodes;
  for (const auto & n : msg.nodes) {
    nodes.push_back({n.id, n.x, n.y});
  }
  std::vector<GraphEdge> edges;
  for (const auto & e : msg.edges) {
    edges.push_back({e.from_id, e.to_id, e.length});
  }
  graph_.emplace(nodes, edges);
  map_frame_ = msg.header.frame_id;
}

void SimpleMissionPlanner::on_odom(const Odometry & msg)
{
  pose_ = msg.pose.pose;
}

void SimpleMissionPlanner::on_goal(const PoseStamped & goal)
{
  if (auto route = plan(goal)) {
    route_pub_->publish(*route);
  }
}

std::optional<Path> SimpleMissionPlanner::plan(const PoseStamped & goal)
{
  if (!graph_ || !pose_) {
    RCLCPP_WARN(get_logger(), "goal ignored: no sd_map or pose yet");
    return std::nullopt;
  }
  if (goal.header.frame_id != map_frame_) {
    RCLCPP_WARN(
      get_logger(), "goal ignored: frame %s, sd_map is in %s", goal.header.frame_id.c_str(),
      map_frame_.c_str());
    return std::nullopt;
  }
  const auto start = graph_->nearest(pose_->position.x, pose_->position.y);
  const auto end = graph_->nearest(goal.pose.position.x, goal.pose.position.y);
  if (!start || !end) {
    RCLCPP_WARN(get_logger(), "goal ignored: sd_map has no nodes");
    return std::nullopt;
  }
  const auto ids = graph_->astar(*start, *end);
  if (!ids) {
    RCLCPP_WARN(get_logger(), "no route from node %" PRId64 " to node %" PRId64, *start, *end);
    return std::nullopt;
  }
  RCLCPP_INFO(get_logger(), "route: %zu nodes, %" PRId64 " -> %" PRId64, ids->size(), *start, *end);
  std_msgs::msg::Header header = goal.header;
  header.stamp = now();
  return to_path(header, *graph_, *ids, goal.pose);
}

}  // namespace simple_mission_planner

RCLCPP_COMPONENTS_REGISTER_NODE(simple_mission_planner::SimpleMissionPlanner)

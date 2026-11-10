#ifndef SIMPLE_MISSION_PLANNER_HPP_
#define SIMPLE_MISSION_PLANNER_HPP_

#include "route_graph.hpp"

#include <rclcpp/rclcpp.hpp>

#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>
#include <simple_sd_map_msgs/msg/sd_map.hpp>

#include <optional>
#include <string>

namespace simple_mission_planner
{

class SimpleMissionPlanner : public rclcpp::Node
{
public:
  explicit SimpleMissionPlanner(const rclcpp::NodeOptions & options);

private:
  void on_map(const simple_sd_map_msgs::msg::SdMap & msg);
  void on_odom(const nav_msgs::msg::Odometry & msg);
  void on_goal(const geometry_msgs::msg::PoseStamped & goal);
  std::optional<nav_msgs::msg::Path> plan(const geometry_msgs::msg::PoseStamped & goal);

  std::optional<RouteGraph> graph_;
  std::string map_frame_;
  std::optional<geometry_msgs::msg::Pose> pose_;

  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr route_pub_;
  rclcpp::Subscription<simple_sd_map_msgs::msg::SdMap>::SharedPtr map_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_sub_;
};

}  // namespace simple_mission_planner

#endif  // SIMPLE_MISSION_PLANNER_HPP_

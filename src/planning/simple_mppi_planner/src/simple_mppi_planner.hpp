#ifndef SIMPLE_MPPI_PLANNER_HPP_
#define SIMPLE_MPPI_PLANNER_HPP_

#include "distance_map.hpp"
#include "mppi_solver.hpp"
#include "progress_monitor.hpp"
#include "reference_path.hpp"

#include <rclcpp/rclcpp.hpp>

#include <diagnostic_msgs/msg/diagnostic_array.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>

#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace simple_mppi_planner
{

class SimpleMppiPlanner : public rclcpp::Node
{
public:
  explicit SimpleMppiPlanner(const rclcpp::NodeOptions & options);

private:
  void on_route(const nav_msgs::msg::Path & msg);
  void on_grid(const nav_msgs::msg::OccupancyGrid & msg);
  void on_odometry(nav_msgs::msg::Odometry::ConstSharedPtr msg);
  void on_timer();

  // Why the vehicle may not move now, or nullptr when every input is usable.
  const char * stop_reason();
  void plan();
  void publish(const Twist2d & twist);
  void publish_trajectory(const State & start);
  void stop(const char * reason);
  void watch_progress();
  void publish_diagnostics();

  VehicleParams vehicle_;
  std::unique_ptr<MppiSolver> solver_;
  double route_spacing_;
  double cruise_speed_;
  double stop_decel_;
  double goal_tolerance_;
  int route_search_points_;
  int occupied_threshold_;
  double pose_timeout_sec_;
  double grid_timeout_sec_;
  double min_observable_speed_;

  ReferencePath route_;
  std::string route_frame_;
  int route_index_ = 0;
  bool goal_reached_ = false;
  ProgressMonitor progress_;
  bool stuck_ = false;
  DistanceMap distance_map_;
  std::string grid_frame_;
  std::optional<rclcpp::Time> grid_stamp_;
  nav_msgs::msg::Odometry::ConstSharedPtr odometry_;
  std::vector<State> trajectory_;

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_pub_;
  rclcpp::Publisher<diagnostic_msgs::msg::DiagnosticArray>::SharedPtr diagnostics_pub_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr trajectory_pub_;
  rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr route_sub_;
  rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr grid_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odometry_sub_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::TimerBase::SharedPtr diagnostics_timer_;
};

}  // namespace simple_mppi_planner

#endif  // SIMPLE_MPPI_PLANNER_HPP_

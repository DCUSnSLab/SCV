#include "simple_mppi_planner.hpp"

#include <rclcpp_components/register_node_macro.hpp>

#include <chrono>
#include <cmath>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

constexpr int throttle_ms = 5000;
constexpr std::chrono::seconds diagnostics_period{1};

VehicleParams read_vehicle(rclcpp::Node & node)
{
  VehicleParams v;
  const std::string model = node.declare_parameter<std::string>("motion_model");
  v.min_speed = node.declare_parameter<double>("vehicle.min_speed");
  v.max_speed = node.declare_parameter<double>("vehicle.max_speed");
  v.max_accel = node.declare_parameter<double>("vehicle.max_accel");
  v.max_decel = node.declare_parameter<double>("vehicle.max_decel");
  v.kinematic_center_x = node.declare_parameter<double>("vehicle.kinematic_center_x");
  if (model == "ackermann") {
    v.model = MotionModel::Ackermann;
    v.wheelbase = node.declare_parameter<double>("ackermann.wheelbase");
    v.max_steer = node.declare_parameter<double>("ackermann.max_steer");
    v.steer_time_constant = node.declare_parameter<double>("ackermann.steer_time_constant");
  } else if (model == "diff") {
    v.model = MotionModel::Diff;
    v.max_angular_speed = node.declare_parameter<double>("diff.max_angular_speed");
    v.max_angular_accel = node.declare_parameter<double>("diff.max_angular_accel");
  } else {
    throw std::invalid_argument("motion_model must be ackermann or diff, got " + model);
  }
  return v;
}

MppiParams read_mppi(rclcpp::Node & node)
{
  MppiParams m;
  m.sample_count = node.declare_parameter<int>("mppi.sample_count");
  m.horizon_steps = node.declare_parameter<int>("mppi.horizon_steps");
  m.step_sec = node.declare_parameter<double>("mppi.step_sec");
  m.lambda = node.declare_parameter<double>("mppi.lambda");
  m.alpha = node.declare_parameter<double>("mppi.alpha");
  m.non_biased_rate = node.declare_parameter<double>("mppi.non_biased_rate");
  m.noise_correlation = node.declare_parameter<double>("mppi.noise_correlation");
  m.speed_std = node.declare_parameter<double>("mppi.speed_std");
  m.turn_std = node.declare_parameter<double>("mppi.turn_std");
  m.smoothing_half_window = node.declare_parameter<int>("mppi.smoothing_half_window");
  m.thread_count = node.declare_parameter<int>("mppi.thread_count");
  m.seed = static_cast<unsigned int>(node.declare_parameter<int>("mppi.seed"));
  return m;
}

CostParams read_cost(rclcpp::Node & node, MotionModel model)
{
  CostParams c;
  c.path_distance = node.declare_parameter<double>("cost.path_distance");
  c.path_heading = node.declare_parameter<double>("cost.path_heading");
  c.speed = node.declare_parameter<double>("cost.speed");
  c.progress = node.declare_parameter<double>("cost.progress");
  c.clearance = node.declare_parameter<double>("cost.clearance");
  c.clearance_margin = node.declare_parameter<double>("cost.clearance_margin");
  c.collision = node.declare_parameter<double>("cost.collision");
  if (model == MotionModel::Ackermann) {
    c.terminal_heading = node.declare_parameter<double>("ackermann.terminal_heading");
  }
  return c;
}

Footprint read_footprint(rclcpp::Node & node)
{
  Footprint f;
  f.circle_x = node.declare_parameter<std::vector<double>>("footprint.circle_x");
  f.radius = node.declare_parameter<double>("footprint.radius");
  return f;
}

double yaw_of(const geometry_msgs::msg::Quaternion & q)
{
  return std::atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z));
}

}  // namespace

SimpleMppiPlanner::SimpleMppiPlanner(const rclcpp::NodeOptions & options)
: Node("simple_mppi_planner", options),
  vehicle_(read_vehicle(*this)),
  route_spacing_(declare_parameter<double>("route.spacing")),
  cruise_speed_(declare_parameter<double>("route.cruise_speed")),
  stop_decel_(declare_parameter<double>("route.stop_decel")),
  goal_tolerance_(declare_parameter<double>("route.goal_tolerance")),
  route_search_points_(declare_parameter<int>("route.search_points")),
  occupied_threshold_(declare_parameter<int>("occupied_threshold")),
  pose_timeout_sec_(declare_parameter<double>("pose_timeout_sec")),
  grid_timeout_sec_(declare_parameter<double>("grid_timeout_sec")),
  min_observable_speed_(declare_parameter<double>("min_observable_speed")),
  progress_(
    declare_parameter<double>("stuck.min_progress"), declare_parameter<double>("stuck.window_sec"))
{
  solver_ = std::make_unique<MppiSolver>(
    read_mppi(*this), read_cost(*this, vehicle_.model), vehicle_, read_footprint(*this));

  cmd_pub_ = create_publisher<geometry_msgs::msg::Twist>("~/output/cmd_vel", 1);
  diagnostics_pub_ =
    create_publisher<diagnostic_msgs::msg::DiagnosticArray>("~/output/diagnostics", 1);
  trajectory_pub_ = create_publisher<nav_msgs::msg::Path>("~/debug/trajectory", 1);
  route_sub_ = create_subscription<nav_msgs::msg::Path>(
    "~/input/route", rclcpp::QoS(1).reliable().transient_local(),
    [this](const nav_msgs::msg::Path & msg) { on_route(msg); });
  grid_sub_ = create_subscription<nav_msgs::msg::OccupancyGrid>(
    "~/input/grid", 1, [this](const nav_msgs::msg::OccupancyGrid & msg) { on_grid(msg); });
  odometry_sub_ = create_subscription<nav_msgs::msg::Odometry>(
    "~/input/odometry", 1,
    [this](nav_msgs::msg::Odometry::ConstSharedPtr msg) { on_odometry(std::move(msg)); });
  timer_ = create_wall_timer(
    std::chrono::duration<double>(1.0 / declare_parameter<double>("control_rate_hz")),
    [this]() { on_timer(); });
  diagnostics_timer_ = create_wall_timer(diagnostics_period, [this]() { publish_diagnostics(); });
}

void SimpleMppiPlanner::on_route(const nav_msgs::msg::Path & msg)
{
  if (msg.poses.empty()) {
    route_ = ReferencePath();
    return;
  }
  std::vector<std::pair<double, double>> waypoints;
  waypoints.reserve(msg.poses.size());
  for (const auto & pose : msg.poses) {
    waypoints.emplace_back(pose.pose.position.x, pose.pose.position.y);
  }
  route_ = ReferencePath(waypoints, route_spacing_, cruise_speed_, stop_decel_);
  route_frame_ = msg.header.frame_id;
  route_index_ = -1;
  goal_reached_ = false;
  progress_.reset();
  RCLCPP_INFO(get_logger(), "route: %.1f m in %s", route_.length(), route_frame_.c_str());
}

void SimpleMppiPlanner::on_grid(const nav_msgs::msg::OccupancyGrid & msg)
{
  GridView view;
  view.cells = msg.data.data();
  view.width = static_cast<int>(msg.info.width);
  view.height = static_cast<int>(msg.info.height);
  view.resolution = msg.info.resolution;
  view.origin_x = msg.info.origin.position.x;
  view.origin_y = msg.info.origin.position.y;
  view.occupied_threshold = occupied_threshold_;
  distance_map_.build(view);
  grid_frame_ = msg.header.frame_id;
  grid_stamp_ = rclcpp::Time(msg.header.stamp, get_clock()->get_clock_type());
}

void SimpleMppiPlanner::on_odometry(nav_msgs::msg::Odometry::ConstSharedPtr msg)
{
  odometry_ = std::move(msg);
}

const char * SimpleMppiPlanner::stop_reason()
{
  if (route_.empty()) {
    return "no route";
  }
  if (!odometry_ || !grid_stamp_) {
    return "waiting for pose and grid";
  }
  const rclcpp::Time now = get_clock()->now();
  const rclcpp::Time pose_stamp(odometry_->header.stamp, now.get_clock_type());
  if ((now - pose_stamp).seconds() > pose_timeout_sec_) {
    return "stale pose";
  }
  if ((now - *grid_stamp_).seconds() > grid_timeout_sec_) {
    return "stale grid";
  }
  // Without TF here, a frame mismatch would put the route or the obstacles in the wrong place.
  if (grid_frame_ != odometry_->header.frame_id || route_frame_ != odometry_->header.frame_id) {
    return "pose, grid and route are in different frames";
  }
  return nullptr;
}

void SimpleMppiPlanner::on_timer()
{
  const char * reason = stop_reason();
  if (reason) {
    // Stale inputs have their own warning, and the route position is not known without a pose.
    progress_.reset();
    stuck_ = false;
    stop(reason);
  } else if (!goal_reached_) {
    plan();
  } else {
    publish({});
  }
}

void SimpleMppiPlanner::plan()
{
  const auto & pose = odometry_->pose.pose;
  const auto & twist = odometry_->twist.twist;
  const double yaw = yaw_of(pose.orientation);
  route_index_ =
    route_index_ < 0
      ? route_.nearest(pose.position.x, pose.position.y)
      : route_.advance(route_index_, pose.position.x, pose.position.y, route_search_points_);
  if (route_.at_goal(route_index_, pose.position.x, pose.position.y, goal_tolerance_)) {
    RCLCPP_INFO(get_logger(), "goal reached");
    goal_reached_ = true;
    solver_->reset();
    progress_.reset();
    stuck_ = false;
    publish({});
    return;
  }
  watch_progress();

  State start;
  start.x = pose.position.x + vehicle_.kinematic_center_x * std::cos(yaw);
  start.y = pose.position.y + vehicle_.kinematic_center_x * std::sin(yaw);
  start.yaw = yaw;
  start.speed = twist.linear.x;
  start.turn = measured_turn(vehicle_, twist.linear.x, twist.angular.z, min_observable_speed_);
  const Solution solution = solver_->solve(start, route_, route_index_, distance_map_);
  if (!solution.feasible) {
    stop("no collision-free solution");
    return;
  }
  publish(to_twist(vehicle_, solution.control));
  if (trajectory_pub_->get_subscription_count() > 0) {
    publish_trajectory(start);
  }
}

void SimpleMppiPlanner::publish_trajectory(const State & start)
{
  solver_->rollout(start, &trajectory_);
  auto msg = std::make_unique<nav_msgs::msg::Path>();
  msg->header.stamp = get_clock()->now();
  msg->header.frame_id = odometry_->header.frame_id;
  msg->poses.resize(trajectory_.size());
  const rclcpp::Time stamp(msg->header.stamp, get_clock()->get_clock_type());
  for (std::size_t i = 0; i < trajectory_.size(); ++i) {
    const State & s = trajectory_[i];
    auto & pose = msg->poses[i];
    // The stamp of each pose is when the plan reaches it, step_sec apart from the header stamp.
    pose.header.stamp =
      stamp + rclcpp::Duration::from_seconds(static_cast<double>(i) * solver_->step_sec());
    pose.header.frame_id = msg->header.frame_id;
    pose.pose.position.x = s.x - vehicle_.kinematic_center_x * std::cos(s.yaw);
    pose.pose.position.y = s.y - vehicle_.kinematic_center_x * std::sin(s.yaw);
    pose.pose.orientation.z = std::sin(0.5 * s.yaw);
    pose.pose.orientation.w = std::cos(0.5 * s.yaw);
  }
  trajectory_pub_->publish(std::move(msg));
}

void SimpleMppiPlanner::watch_progress()
{
  const double arc = route_.point(route_index_).arc;
  const bool stuck = progress_.update(get_clock()->now().seconds(), arc);
  if (stuck != stuck_) {
    RCLCPP_WARN(
      get_logger(), "%s at %.1f m of %.1f m of route", stuck ? "no progress" : "progress again",
      arc, route_.length());
  }
  stuck_ = stuck;
}

void SimpleMppiPlanner::publish_diagnostics()
{
  diagnostic_msgs::msg::DiagnosticStatus status;
  status.name = get_name();
  status.level = stuck_ ? diagnostic_msgs::msg::DiagnosticStatus::WARN
                        : diagnostic_msgs::msg::DiagnosticStatus::OK;
  status.message = stuck_ ? "no progress along the route" : "ok";
  diagnostic_msgs::msg::DiagnosticArray array;
  array.header.stamp = get_clock()->now();
  array.status.push_back(status);
  diagnostics_pub_->publish(array);
}

void SimpleMppiPlanner::publish(const Twist2d & twist)
{
  auto msg = std::make_unique<geometry_msgs::msg::Twist>();
  msg->linear.x = twist.linear;
  msg->angular.z = twist.angular;
  cmd_pub_->publish(std::move(msg));
}

void SimpleMppiPlanner::stop(const char * reason)
{
  solver_->reset();
  RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), throttle_ms, "stopping: %s", reason);
  publish({});
}

}  // namespace simple_mppi_planner

RCLCPP_COMPONENTS_REGISTER_NODE(simple_mppi_planner::SimpleMppiPlanner)

#include "simple_mppi_planner.hpp"

#include <gtest/gtest.h>

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <thread>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

using diagnostic_msgs::msg::DiagnosticArray;
using diagnostic_msgs::msg::DiagnosticStatus;
using geometry_msgs::msg::Twist;
using nav_msgs::msg::OccupancyGrid;
using nav_msgs::msg::Odometry;
using nav_msgs::msg::Path;

rclcpp::NodeOptions planner_options(const std::string & model)
{
  rclcpp::NodeOptions options;
  options.arguments(
    {"--ros-args", "-r", "~/input/route:=/test/route", "-r", "~/input/odometry:=/test/odometry",
     "-r", "~/input/grid:=/test/grid", "-r", "~/output/cmd_vel:=/test/cmd_vel", "-r",
     "~/output/diagnostics:=/test/diagnostics", "-r", "~/debug/trajectory:=/test/trajectory"});
  std::vector<rclcpp::Parameter> p = {
    {"motion_model", model},
    {"control_rate_hz", 20.0},
    {"pose_timeout_sec", 0.3},
    {"grid_timeout_sec", 0.3},
    {"occupied_threshold", 50},
    {"min_observable_speed", 0.1},
    {"vehicle.min_speed", 0.0},
    {"vehicle.max_speed", 1.5},
    {"vehicle.max_accel", 0.8},
    {"vehicle.max_decel", 1.0},
    {"vehicle.kinematic_center_x", 0.0},
    {"footprint.circle_x", std::vector<double>{0.0}},
    {"footprint.radius", 0.45},
    {"route.spacing", 0.2},
    {"route.cruise_speed", 1.0},
    {"route.stop_decel", 0.5},
    {"route.goal_tolerance", 0.3},
    {"route.search_points", 25},
    {"stuck.min_progress", 0.3},
    {"stuck.window_sec", 0.5},
    {"mppi.sample_count", 500},
    {"mppi.horizon_steps", 30},
    {"mppi.step_sec", 0.1},
    {"mppi.lambda", 0.3},
    {"mppi.alpha", 0.9},
    {"mppi.non_biased_rate", 0.1},
    {"mppi.noise_correlation", 0.9},
    {"mppi.smoothing_half_window", 4},
    {"mppi.speed_std", 0.4},
    {"mppi.turn_std", 0.3},
    {"mppi.thread_count", 1},
    {"mppi.seed", 1},
    {"cost.path_distance", 0.2},
    {"cost.path_heading", 0.2},
    {"cost.speed", 2.0},
    {"cost.progress", 10.0},
    {"cost.clearance", 20.0},
    {"cost.clearance_margin", 0.5},
    {"cost.collision", 1000.0},
  };
  if (model == "ackermann") {
    p.emplace_back("ackermann.wheelbase", 0.65);
    p.emplace_back("ackermann.max_steer", 0.461);
    p.emplace_back("ackermann.steer_time_constant", 0.2);
    p.emplace_back("ackermann.terminal_heading", 20.0);
  } else {
    p.emplace_back("diff.max_angular_speed", 1.5);
    p.emplace_back("diff.max_angular_accel", 3.0);
  }
  options.parameter_overrides(p);
  return options;
}

class PlannerNodeTest : public ::testing::TestWithParam<std::string>
{
protected:
  static void SetUpTestSuite() { rclcpp::init(0, nullptr); }
  static void TearDownTestSuite() { rclcpp::shutdown(); }

  void SetUp() override
  {
    planner_ = std::make_shared<SimpleMppiPlanner>(planner_options(GetParam()));
    probe_ = std::make_shared<rclcpp::Node>("probe");
    route_pub_ =
      probe_->create_publisher<Path>("/test/route", rclcpp::QoS(1).reliable().transient_local());
    odometry_pub_ = probe_->create_publisher<Odometry>("/test/odometry", 1);
    grid_pub_ = probe_->create_publisher<OccupancyGrid>("/test/grid", 1);
    cmd_sub_ = probe_->create_subscription<Twist>("/test/cmd_vel", 1, [this](const Twist & msg) {
      last_cmd_ = msg;
      ++cmd_count_;
    });
    diagnostics_sub_ = probe_->create_subscription<DiagnosticArray>(
      "/test/diagnostics", 10, [this](const DiagnosticArray & msg) {
        last_level_ = msg.status.at(0).level;
        ++diagnostics_count_;
      });
    trajectory_sub_ = probe_->create_subscription<Path>(
      "/test/trajectory", 1, [this](const Path & msg) { last_trajectory_ = msg; });
    executor_.add_node(planner_);
    executor_.add_node(probe_);
  }

  Path route(double length, const std::string & frame = "map")
  {
    Path path;
    path.header.frame_id = frame;
    path.poses.resize(2);
    path.poses[1].pose.position.x = length;
    return path;
  }

  void publish_pose(double x)
  {
    Odometry odometry;
    odometry.header.frame_id = "map";
    odometry.header.stamp = probe_->now();
    odometry.pose.pose.position.x = x;
    odometry.pose.pose.orientation.w = 1.0;
    odometry_pub_->publish(odometry);
  }

  void publish_grid(bool blocked)
  {
    OccupancyGrid grid;
    grid.header.frame_id = "map";
    grid.header.stamp = probe_->now();
    grid.info.width = 200;
    grid.info.height = 200;
    grid.info.resolution = 0.1F;
    grid.info.origin.position.x = -10.0;
    grid.info.origin.position.y = -10.0;
    grid.data.assign(40000, 0);
    if (blocked) {
      grid.data[100 * 200 + 100] = 100;
    }
    grid_pub_->publish(grid);
  }

  // Spins for the duration with inputs live, then returns the last command.
  Twist spin_for(double seconds, const std::function<void()> & each_cycle = [] {})
  {
    const auto end = std::chrono::steady_clock::now() + std::chrono::duration<double>(seconds);
    while (std::chrono::steady_clock::now() < end) {
      each_cycle();
      executor_.spin_all(std::chrono::milliseconds(20));
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    return last_cmd_;
  }

  std::shared_ptr<SimpleMppiPlanner> planner_;
  rclcpp::Node::SharedPtr probe_;
  rclcpp::Publisher<Path>::SharedPtr route_pub_;
  rclcpp::Publisher<Odometry>::SharedPtr odometry_pub_;
  rclcpp::Publisher<OccupancyGrid>::SharedPtr grid_pub_;
  rclcpp::Subscription<Twist>::SharedPtr cmd_sub_;
  rclcpp::Subscription<DiagnosticArray>::SharedPtr diagnostics_sub_;
  rclcpp::Subscription<Path>::SharedPtr trajectory_sub_;
  rclcpp::executors::SingleThreadedExecutor executor_;
  Twist last_cmd_;
  Path last_trajectory_;
  std::uint8_t last_level_ = DiagnosticStatus::OK;
  int diagnostics_count_ = 0;
  int cmd_count_ = 0;
};

void expect_zero(const Twist & cmd)
{
  EXPECT_EQ(cmd.linear.x, 0.0);
  EXPECT_EQ(cmd.angular.z, 0.0);
}

TEST_P(PlannerNodeTest, MovesWithLiveInputsAndStopsWhenThePoseGoesStale)
{
  route_pub_->publish(route(10.0));
  const Twist moving = spin_for(1.5, [this] {
    publish_pose(0.0);
    publish_grid(false);
  });
  EXPECT_GT(moving.linear.x, 0.1);
  const Twist stale = spin_for(0.8, [this] { publish_grid(false); });
  expect_zero(stale);
}

TEST_P(PlannerNodeTest, PublishesThePlannedTrajectoryWithItsTimes)
{
  route_pub_->publish(route(10.0));
  spin_for(1.0, [this] {
    publish_pose(0.0);
    publish_grid(false);
  });
  const Path & path = last_trajectory_;
  ASSERT_EQ(path.poses.size(), 31U);
  EXPECT_EQ(path.header.frame_id, "map");
  const rclcpp::Time start(path.header.stamp);
  for (std::size_t i = 0; i < path.poses.size(); ++i) {
    const double offset = (rclcpp::Time(path.poses[i].header.stamp) - start).seconds();
    EXPECT_NEAR(offset, 0.1 * static_cast<double>(i), 1e-9);
  }
  EXPECT_NEAR(path.poses.front().pose.position.x, 0.0, 1e-9);
  EXPECT_GT(path.poses.back().pose.position.x, 0.5);
}

TEST_P(PlannerNodeTest, StopsWhenTheGridGoesStale)
{
  route_pub_->publish(route(10.0));
  spin_for(1.0, [this] {
    publish_pose(0.0);
    publish_grid(false);
  });
  expect_zero(spin_for(0.8, [this] { publish_pose(0.0); }));
}

TEST_P(PlannerNodeTest, StaysStoppedWithoutARoute)
{
  expect_zero(spin_for(0.5, [this] {
    publish_pose(0.0);
    publish_grid(false);
  }));
  EXPECT_GT(cmd_count_, 0);
}

TEST_P(PlannerNodeTest, StopsWhenThereIsNoCollisionFreeSolution)
{
  route_pub_->publish(route(10.0));
  const Twist cmd = spin_for(1.0, [this] {
    publish_pose(0.0);
    publish_grid(true);
  });
  expect_zero(cmd);
}

TEST_P(PlannerNodeTest, StopsOnARouteInAnotherFrame)
{
  route_pub_->publish(route(10.0, "odom"));
  expect_zero(spin_for(1.0, [this] {
    publish_pose(0.0);
    publish_grid(false);
  }));
}

TEST_P(PlannerNodeTest, StopsAtTheGoal)
{
  route_pub_->publish(route(10.0));
  expect_zero(spin_for(1.0, [this] {
    publish_pose(9.9);
    publish_grid(false);
  }));
}

TEST_P(PlannerNodeTest, ReportsNoProgressWhileTheRouteIsActive)
{
  route_pub_->publish(route(10.0));
  // The pose never moves, whatever the planner commands.
  spin_for(2.5, [this] {
    publish_pose(0.0);
    publish_grid(false);
  });
  EXPECT_GT(diagnostics_count_, 0);
  EXPECT_EQ(last_level_, DiagnosticStatus::WARN);
}

TEST_P(PlannerNodeTest, ReportsNoStuckVehicleWhileItAdvances)
{
  route_pub_->publish(route(10.0));
  double x = 0.0;
  spin_for(2.5, [this, &x] {
    x += 0.03;
    publish_pose(x);
    publish_grid(false);
  });
  EXPECT_GT(diagnostics_count_, 0);
  EXPECT_EQ(last_level_, DiagnosticStatus::OK);
}

TEST_P(PlannerNodeTest, ReportsNoStuckVehicleAtTheGoal)
{
  route_pub_->publish(route(10.0));
  spin_for(2.5, [this] {
    publish_pose(9.9);
    publish_grid(false);
  });
  EXPECT_EQ(last_level_, DiagnosticStatus::OK);
}

INSTANTIATE_TEST_SUITE_P(Models, PlannerNodeTest, ::testing::Values("ackermann", "diff"));

}  // namespace
}  // namespace simple_mppi_planner

#include "simple_mission_planner.hpp"

#include <gtest/gtest.h>

#include <chrono>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <thread>

namespace simple_mission_planner
{
namespace
{

using geometry_msgs::msg::PoseStamped;
using nav_msgs::msg::Odometry;
using nav_msgs::msg::Path;
using simple_sd_map_msgs::msg::SdMap;

rclcpp::NodeOptions planner_options()
{
  rclcpp::NodeOptions options;
  options.arguments(
    {"--ros-args", "-r", "~/input/sd_map:=/test/sd_map", "-r", "~/input/odometry:=/test/odometry",
     "-r", "~/input/goal_pose:=/test/goal_pose", "-r", "~/output/route:=/test/route"});
  return options;
}

// Nodes 1 (0, 0), 2 (1, 0), 3 (1, 2), 4 (2, 0); 1 - 2 - 4 is shorter than 1 - 3 - 4.
SdMap diamond_map()
{
  SdMap map;
  map.header.frame_id = "map";
  const double xy[][2] = {{0.0, 0.0}, {1.0, 0.0}, {1.0, 2.0}, {2.0, 0.0}};
  for (int i = 0; i < 4; ++i) {
    simple_sd_map_msgs::msg::SdNode n;
    n.id = i + 1;
    n.x = xy[i][0];
    n.y = xy[i][1];
    map.nodes.push_back(n);
  }
  const double edges[][3] = {{1, 2, 1.0}, {2, 4, 1.0}, {1, 3, 2.0}, {3, 4, 2.0}};
  for (const auto & e : edges) {
    simple_sd_map_msgs::msg::SdEdge edge;
    edge.from_id = static_cast<std::int64_t>(e[0]);
    edge.to_id = static_cast<std::int64_t>(e[1]);
    edge.length = e[2];
    map.edges.push_back(edge);
  }
  return map;
}

class PlannerNodeTest : public ::testing::Test
{
protected:
  static void SetUpTestSuite() { rclcpp::init(0, nullptr); }
  static void TearDownTestSuite() { rclcpp::shutdown(); }

  void SetUp() override
  {
    planner_ = std::make_shared<SimpleMissionPlanner>(planner_options());
    probe_ = std::make_shared<rclcpp::Node>("probe");
    const auto latched = rclcpp::QoS(10).reliable().transient_local();
    map_pub_ = probe_->create_publisher<SdMap>("/test/sd_map", latched);
    odometry_pub_ = probe_->create_publisher<Odometry>("/test/odometry", 10);
    goal_pub_ = probe_->create_publisher<PoseStamped>("/test/goal_pose", 10);
    route_sub_ = probe_->create_subscription<Path>(
      "/test/route", latched, [this](const Path & msg) { route_ = msg; });
    executor_.add_node(planner_);
    executor_.add_node(probe_);
  }

  // Publishes the inputs until a route arrives or the time runs out.
  void spin_with_goal(const std::string & goal_frame, double seconds)
  {
    map_pub_->publish(diamond_map());
    Odometry odometry;
    odometry.pose.pose.position.x = 0.1;
    odometry.pose.pose.position.y = 0.1;
    PoseStamped goal;
    goal.header.frame_id = goal_frame;
    goal.pose.position.x = 2.1;
    goal.pose.orientation.z = 1.0;
    const auto end = std::chrono::steady_clock::now() + std::chrono::duration<double>(seconds);
    while (!route_ && std::chrono::steady_clock::now() < end) {
      odometry_pub_->publish(odometry);
      goal_pub_->publish(goal);
      executor_.spin_all(std::chrono::milliseconds(100));
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
  }

  std::shared_ptr<SimpleMissionPlanner> planner_;
  rclcpp::Node::SharedPtr probe_;
  rclcpp::Publisher<SdMap>::SharedPtr map_pub_;
  rclcpp::Publisher<Odometry>::SharedPtr odometry_pub_;
  rclcpp::Publisher<PoseStamped>::SharedPtr goal_pub_;
  rclcpp::Subscription<Path>::SharedPtr route_sub_;
  rclcpp::executors::SingleThreadedExecutor executor_;
  std::optional<Path> route_;
};

TEST_F(PlannerNodeTest, PublishesTheRouteThroughTheNearestNodesAndEndsAtTheGoal)
{
  spin_with_goal("map", 10.0);
  ASSERT_TRUE(route_);
  EXPECT_EQ(route_->header.frame_id, "map");
  ASSERT_EQ(route_->poses.size(), 4U);
  const double xs[] = {0.0, 1.0, 2.0};
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(route_->poses[i].header.frame_id, "map");
    EXPECT_EQ(route_->poses[i].pose.position.x, xs[i]);
    EXPECT_EQ(route_->poses[i].pose.position.y, 0.0);
    EXPECT_EQ(route_->poses[i].pose.orientation.w, 1.0);
  }
  EXPECT_EQ(route_->poses[3].pose.position.x, 2.1);
  EXPECT_EQ(route_->poses[3].pose.orientation.z, 1.0);
}

TEST_F(PlannerNodeTest, IgnoresAGoalInAnotherFrame)
{
  spin_with_goal("odom", 1.0);
  EXPECT_FALSE(route_);
}

}  // namespace
}  // namespace simple_mission_planner

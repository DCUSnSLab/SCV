#include "simple_local_grid.hpp"

#include <geometry_msgs/msg/transform_stamped.hpp>
#include <sensor_msgs/point_cloud2_iterator.hpp>

#include <gtest/gtest.h>
#include <tf2_ros/static_transform_broadcaster.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <memory>
#include <string>
#include <vector>

namespace simple_local_grid
{
namespace
{

using nav_msgs::msg::OccupancyGrid;
using sensor_msgs::msg::PointCloud2;

rclcpp::NodeOptions grid_options()
{
  rclcpp::NodeOptions options;
  options.arguments(
    {"--ros-args", "-r", "~/input/points:=/test/points", "-r", "~/output/grid:=/test/grid"});
  options.parameter_overrides({
    {"transport", "dds"},
    {"grid_frame", "map"},
    {"base_frame", "base_link"},
    {"tf_timeout_sec", 0.1},
    {"resolution", 0.1},
    {"size_cells", 200},
    {"clear_stride", 1},
    {"min_height", 0.2},
    {"max_height", 1.8},
    {"self_box.min_x", -0.5},
    {"self_box.max_x", 0.6},
    {"self_box.min_y", -0.4},
    {"self_box.max_y", 0.4},
  });
  return options;
}

geometry_msgs::msg::TransformStamped transform(
  const std::string & parent, const std::string & child, double x, double y, double z,
  const rclcpp::Time & stamp)
{
  geometry_msgs::msg::TransformStamped t;
  t.header.stamp = stamp;
  t.header.frame_id = parent;
  t.child_frame_id = child;
  t.transform.translation.x = x;
  t.transform.translation.y = y;
  t.transform.translation.z = z;
  t.transform.rotation.w = 1.0;
  return t;
}

PointCloud2 cloud_in_sensor(
  const std::vector<std::array<float, 3>> & points, const rclcpp::Time & stamp)
{
  PointCloud2 msg;
  msg.header.frame_id = "velodyne";
  msg.header.stamp = stamp;
  sensor_msgs::PointCloud2Modifier modifier(msg);
  modifier.setPointCloud2FieldsByString(1, "xyz");
  modifier.resize(points.size());
  sensor_msgs::PointCloud2Iterator<float> x(msg, "x");
  sensor_msgs::PointCloud2Iterator<float> y(msg, "y");
  sensor_msgs::PointCloud2Iterator<float> z(msg, "z");
  for (const auto & p : points) {
    *x = p[0];
    *y = p[1];
    *z = p[2];
    ++x;
    ++y;
    ++z;
  }
  return msg;
}

class GridNodeTest : public ::testing::Test
{
protected:
  static void SetUpTestSuite() { rclcpp::init(0, nullptr); }
  static void TearDownTestSuite() { rclcpp::shutdown(); }
};

TEST_F(GridNodeTest, PublishesTheObstacleAndNotTheGroundInTheGridFrame)
{
  auto grid_node = std::make_shared<SimpleLocalGrid>(grid_options());
  auto probe = std::make_shared<rclcpp::Node>("probe");
  tf2_ros::StaticTransformBroadcaster tf(probe);
  const rclcpp::Time stamp = probe->now();
  tf.sendTransform({
    transform("map", "base_link", 5.0, 2.0, 0.0, stamp),
    transform("base_link", "velodyne", 0.2, 0.0, 0.9, stamp),
  });

  OccupancyGrid::SharedPtr received;
  auto sub = probe->create_subscription<OccupancyGrid>(
    "/test/grid", 1, [&](OccupancyGrid::SharedPtr msg) { received = msg; });
  auto pub = probe->create_publisher<PointCloud2>("/test/points", rclcpp::SensorDataQoS());

  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(grid_node);
  executor.add_node(probe);
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(10);
  while (!received && std::chrono::steady_clock::now() < deadline) {
    // Obstacle 2.8 m ahead of the sensor, and one ground return.
    pub->publish(cloud_in_sensor({{2.8F, 0.0F, -0.4F}, {3.8F, 0.0F, -0.9F}}, stamp));
    executor.spin_all(std::chrono::milliseconds(100));
  }
  ASSERT_TRUE(received);

  EXPECT_EQ(received->header.frame_id, "map");
  EXPECT_EQ(received->info.width, 200U);
  EXPECT_NEAR(received->info.origin.position.x, 5.0 - 10.0, 1e-6);
  EXPECT_NEAR(received->info.origin.position.y, 2.0 - 10.0, 1e-6);
  int occupied = 0;
  for (const std::int8_t cell : received->data) {
    occupied += cell == 100;
  }
  EXPECT_EQ(occupied, 1);
  const std::size_t col = (5.0 + 3.0 - received->info.origin.position.x) / 0.1;
  const std::size_t row = (2.0 - received->info.origin.position.y) / 0.1;
  EXPECT_EQ(received->data[row * 200 + col], 100);
}

}  // namespace
}  // namespace simple_local_grid

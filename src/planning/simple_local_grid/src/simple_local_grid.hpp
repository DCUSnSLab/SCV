#ifndef SIMPLE_LOCAL_GRID_HPP_
#define SIMPLE_LOCAL_GRID_HPP_

#include "rolling_grid.hpp"

#include <flux/subscription.hpp>
#include <rclcpp/rclcpp.hpp>

#include <nav_msgs/msg/occupancy_grid.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include <memory>
#include <string>

namespace simple_local_grid
{

class SimpleLocalGrid : public rclcpp::Node
{
public:
  explicit SimpleLocalGrid(const rclcpp::NodeOptions & options);

private:
  void subscribe_points(const std::string & transport);
  void subscribe_flux_points();
  void subscribe_dds_points();
  void on_points(
    const RawCloud & cloud, const std::string & sensor_frame, const rclcpp::Time & stamp);
  void publish_grid(const rclcpp::Time & stamp);

  std::string grid_frame_;
  std::string base_frame_;
  rclcpp::Duration tf_timeout_;
  ObstacleFilter filter_;
  RollingGrid grid_;
  int clear_stride_;

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
  rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr grid_pub_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr dds_sub_;
  std::shared_ptr<flux::Subscription> flux_sub_;
};

}  // namespace simple_local_grid

#endif  // SIMPLE_LOCAL_GRID_HPP_

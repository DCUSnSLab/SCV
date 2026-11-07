#include "simple_local_grid.hpp"

#include <rclcpp_components/register_node_macro.hpp>
#include <tf2_eigen/tf2_eigen.hpp>

#include "sensor_msgs/flux/point_cloud2.hpp"

#include <tf2/exceptions.h>

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

namespace simple_local_grid
{
namespace
{

using FluxCloud = sensor_msgs::flux_msg::PointCloud2;

constexpr int throttle_ms = 5000;

ObstacleFilter read_filter(rclcpp::Node & node)
{
  ObstacleFilter filter;
  filter.min_height = node.declare_parameter<double>("min_height");
  filter.max_height = node.declare_parameter<double>("max_height");
  filter.self_min_x = node.declare_parameter<double>("self_box.min_x");
  filter.self_max_x = node.declare_parameter<double>("self_box.max_x");
  filter.self_min_y = node.declare_parameter<double>("self_box.min_y");
  filter.self_max_y = node.declare_parameter<double>("self_box.max_y");
  return filter;
}

}  // namespace

SimpleLocalGrid::SimpleLocalGrid(const rclcpp::NodeOptions & options)
: Node("simple_local_grid", options),
  grid_frame_(declare_parameter<std::string>("grid_frame")),
  base_frame_(declare_parameter<std::string>("base_frame")),
  tf_timeout_(rclcpp::Duration::from_seconds(declare_parameter<double>("tf_timeout_sec"))),
  filter_(read_filter(*this)),
  grid_(declare_parameter<double>("resolution"), declare_parameter<int>("size_cells")),
  clear_stride_(declare_parameter<int>("clear_stride")),
  tf_buffer_(get_clock()),
  tf_listener_(tf_buffer_)
{
  grid_pub_ = create_publisher<nav_msgs::msg::OccupancyGrid>("~/output/grid", 1);
  subscribe_points(declare_parameter<std::string>("transport"));
}

void SimpleLocalGrid::subscribe_points(const std::string & transport)
{
  if (transport == "flux") {
    subscribe_flux_points();
    return;
  }
  if (transport != "dds") {
    throw std::invalid_argument("transport must be dds or flux, got " + transport);
  }
  subscribe_dds_points();
}

void SimpleLocalGrid::subscribe_flux_points()
{
  flux_sub_ = std::make_shared<flux::Subscription>(
    *this, "~/input/points", FluxCloud::kFingerprint, flux::QoS{},
    [this](const flux::FrameView & frame) {
      const FluxCloud::View v{frame};
      RawCloud cloud;
      for (std::size_t i = 0; i < v.fields__size(); ++i) {
        set_field_offset(cloud, v.fields(i).name(), v.fields(i).offset());
      }
      cloud.data = v.data().data();
      cloud.count = std::size_t{v.width()} * v.height();
      cloud.step = v.point_step();
      on_points(
        cloud, std::string(v.header__frame_id()),
        rclcpp::Time(v.header__sec(), v.header__nanosec(), get_clock()->get_clock_type()));
    });
  flux_sub_->add_to_callback_group(*this);
}

void SimpleLocalGrid::subscribe_dds_points()
{
  // Best effort matches both a reliable and a best-effort publisher. The cells outlast a lost scan.
  dds_sub_ = create_subscription<sensor_msgs::msg::PointCloud2>(
    "~/input/points", rclcpp::SensorDataQoS().keep_last(1),
    [this](const sensor_msgs::msg::PointCloud2 & msg) {
      RawCloud cloud;
      for (const auto & field : msg.fields) {
        set_field_offset(cloud, field.name, field.offset);
      }
      cloud.data = msg.data.data();
      cloud.count = std::size_t{msg.width} * msg.height;
      cloud.step = msg.point_step;
      on_points(
        cloud, msg.header.frame_id, rclcpp::Time(msg.header.stamp, get_clock()->get_clock_type()));
    });
}

void SimpleLocalGrid::on_points(
  const RawCloud & cloud, const std::string & sensor_frame, const rclcpp::Time & stamp)
{
  Eigen::Isometry3d grid_from_base;
  Eigen::Isometry3d base_from_sensor;
  try {
    grid_from_base = tf2::transformToEigen(
      tf_buffer_.lookupTransform(grid_frame_, base_frame_, stamp, tf_timeout_));
    base_from_sensor = tf2::transformToEigen(
      tf_buffer_.lookupTransform(base_frame_, sensor_frame, stamp, tf_timeout_));
  } catch (const tf2::TransformException & e) {
    RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), throttle_ms, "scan dropped: %s", e.what());
    return;
  }
  grid_.center_on(grid_from_base.translation().x(), grid_from_base.translation().y());
  const Eigen::Isometry3f sensor_to_base = base_from_sensor.cast<float>();
  grid_.insert(cloud, sensor_to_base, grid_from_base, filter_, clear_stride_);
  publish_grid(stamp);
}

void SimpleLocalGrid::publish_grid(const rclcpp::Time & stamp)
{
  auto msg = std::make_unique<nav_msgs::msg::OccupancyGrid>();
  msg->header.stamp = stamp;
  msg->header.frame_id = grid_frame_;
  msg->info.map_load_time = stamp;
  msg->info.resolution = static_cast<float>(grid_.resolution());
  msg->info.width = grid_.size_cells();
  msg->info.height = grid_.size_cells();
  msg->info.origin.position.x = grid_.origin_x();
  msg->info.origin.position.y = grid_.origin_y();
  msg->info.origin.orientation.w = 1.0;
  msg->data = grid_.occupancy();
  grid_pub_->publish(std::move(msg));
}

}  // namespace simple_local_grid

RCLCPP_COMPONENTS_REGISTER_NODE(simple_local_grid::SimpleLocalGrid)

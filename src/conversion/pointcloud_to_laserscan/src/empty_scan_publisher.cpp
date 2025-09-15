#include <chrono>
#include <memory>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;

class EmptyScanPublisher : public rclcpp::Node
{
public:
  EmptyScanPublisher()
  : Node("empty_scan_publisher")
  {
    publisher_ = this->create_publisher<sensor_msgs::msg::LaserScan>("scan", 10);

    frame_id_ = this->declare_parameter("frame_id", "base_link");
    publish_rate_ = this->declare_parameter("publish_rate", 10.0);
    angle_min_ = this->declare_parameter("angle_min", -M_PI);
    angle_max_ = this->declare_parameter("angle_max", M_PI);
    angle_increment_ = this->declare_parameter("angle_increment", M_PI / 180.0);
    range_min_ = this->declare_parameter("range_min", 0.1);
    range_max_ = this->declare_parameter("range_max", 10.0);

    int ms = static_cast<int>(1000.0 / publish_rate_);
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(ms),
      std::bind(&EmptyScanPublisher::publish_empty_scan, this));

    RCLCPP_INFO(this->get_logger(), "Empty scan publisher started");
  }

private:
  void publish_empty_scan()
  {
    auto scan_msg = std::make_unique<sensor_msgs::msg::LaserScan>();

    scan_msg->header.stamp = this->get_clock()->now();
    scan_msg->header.frame_id = frame_id_;

    scan_msg->angle_min = angle_min_;
    scan_msg->angle_max = angle_max_;
    scan_msg->angle_increment = angle_increment_;
    scan_msg->time_increment = 0.0;
    scan_msg->scan_time = 1.0 / publish_rate_;
    scan_msg->range_min = range_min_;
    scan_msg->range_max = range_max_;

    uint32_t ranges_size = std::ceil((angle_max_ - angle_min_) / angle_increment_);
    scan_msg->ranges.assign(ranges_size, std::numeric_limits<float>::infinity());
    scan_msg->intensities.assign(ranges_size, 0.0);

    publisher_->publish(std::move(scan_msg));
  }

  rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;

  std::string frame_id_;
  double publish_rate_;
  double angle_min_;
  double angle_max_;
  double angle_increment_;
  double range_min_;
  double range_max_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EmptyScanPublisher>());
  rclcpp::shutdown();
  return 0;
}
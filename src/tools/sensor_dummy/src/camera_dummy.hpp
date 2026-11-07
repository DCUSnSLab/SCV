#ifndef CAMERA_DUMMY_HPP_
#define CAMERA_DUMMY_HPP_

#include "fault.hpp"
#include "test_pattern.hpp"

#include <rclcpp/rclcpp.hpp>

#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace sensor_dummy
{

// Test pattern frames in the format of one camera. Which camera it mimics is all parameters.
class CameraDummy : public rclcpp::Node
{
public:
  explicit CameraDummy(const rclcpp::NodeOptions & options);

private:
  struct Stream
  {
    std::unique_ptr<TestPattern> pattern;
    sensor_msgs::msg::Image image;
    sensor_msgs::msg::CameraInfo info;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub;
    rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr info_pub;
    std::unique_ptr<FaultFilter<sensor_msgs::msg::Image>> image_output;
    std::unique_ptr<FaultFilter<sensor_msgs::msg::CameraInfo>> info_output;
    std::uint64_t seq{0};
  };

  void add_stream(const std::string & name);
  void setup_imu();
  void on_stream_tick(Stream & stream);
  void on_imu_tick();
  void on_flush_tick();
  rcl_interfaces::msg::SetParametersResult on_parameters(
    const std::vector<rclcpp::Parameter> & parameters);

  FaultSpec fault_;
  std::vector<std::unique_ptr<Stream>> streams_;
  sensor_msgs::msg::Imu imu_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
  std::unique_ptr<FaultFilter<sensor_msgs::msg::Imu>> imu_output_;
  std::vector<rclcpp::TimerBase::SharedPtr> timers_;
  OnSetParametersCallbackHandle::SharedPtr parameter_handle_;
};

}  // namespace sensor_dummy

#endif  // CAMERA_DUMMY_HPP_

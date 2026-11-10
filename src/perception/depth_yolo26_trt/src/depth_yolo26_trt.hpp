#ifndef DEPTH_YOLO26_TRT_HPP_
#define DEPTH_YOLO26_TRT_HPP_

#include <flux_wrapper/flux_wrapper.hpp>
#include <opencv2/core.hpp>
#include <rclcpp/rclcpp.hpp>
#include <tensorrt_common/depth.hpp>
#include <tensorrt_common/engine.hpp>

#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace depth_yolo26_trt
{

// The parameters that may change while the node runs.
struct Settings
{
  bool cloud = false;
  int cloud_downsample = 1;
  bool cloud_colorize = false;
};

class DepthYolo26Trt : public rclcpp::Node
{
public:
  explicit DepthYolo26Trt(const rclcpp::NodeOptions & options);

private:
  void on_image(const flux_wrapper::View<sensor_msgs::msg::Image> & image);
  void publish_cloud(
    const std_msgs::msg::Header & header, const cv::Mat & depth,
    const flux_wrapper::View<sensor_msgs::msg::Image> & image);
  rcl_interfaces::msg::SetParametersResult on_set_parameters(
    const std::vector<rclcpp::Parameter> & parameters);

  Settings settings_;

  bool gpu_preprocess_;
  tensorrt_common::Engine engine_;
  std::string input_;
  std::string output_;
  std::vector<float> input_chw_;
  std::vector<float> output_map_;
  // The depth for the point cloud when the depth loan got no slot.
  cv::Mat fallback_;
  // The colors of the cloud when the image is on the device.
  std::vector<std::uint8_t> color_host_;

  std::unique_ptr<flux_wrapper::Publisher<sensor_msgs::msg::Image>> depth_pub_;
  // The latest camera_info, in the pixels of the camera image.
  std::optional<tensorrt_common::Intrinsics> camera_;
  std::unique_ptr<flux_wrapper::Publisher<sensor_msgs::msg::PointCloud2>> cloud_pub_;
  rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr info_sub_;
  std::unique_ptr<flux_wrapper::Subscription<sensor_msgs::msg::Image>> image_sub_;
  OnSetParametersCallbackHandle::SharedPtr parameters_handle_;
};

}  // namespace depth_yolo26_trt

#endif  // DEPTH_YOLO26_TRT_HPP_

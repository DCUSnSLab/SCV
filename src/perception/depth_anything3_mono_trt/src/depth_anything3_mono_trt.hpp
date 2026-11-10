#ifndef DEPTH_ANYTHING3_MONO_TRT_HPP_
#define DEPTH_ANYTHING3_MONO_TRT_HPP_

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
#include <vector>

namespace depth_anything3_mono_trt
{

// The parameters that may change while the node runs.
struct Settings
{
  float sky_threshold = 0.0F;
  // false: the sky is +inf. true: the sky_quantile of the ground depth, at most sky_depth_cap.
  bool sky_fill = false;
  float sky_quantile = 0.0F;
  float sky_depth_cap = 0.0F;
  bool cloud = false;
  int cloud_downsample = 1;
  bool cloud_colorize = false;
};

class DepthAnything3MonoTrt : public rclcpp::Node
{
public:
  explicit DepthAnything3MonoTrt(const rclcpp::NodeOptions & options);

private:
  void on_image(const flux_wrapper::View<sensor_msgs::msg::Image> & image);
  // `out` has the source size.
  void to_depth(cv::Size input, cv::Mat & out);
  void publish_cloud(
    const std_msgs::msg::Header & header, const cv::Mat & depth,
    const flux_wrapper::View<sensor_msgs::msg::Image> & image);
  rcl_interfaces::msg::SetParametersResult on_set_parameters(
    const std::vector<rclcpp::Parameter> & parameters);

  bool metric_;
  Settings settings_;
  bool gpu_preprocess_;
  tensorrt_common::Engine engine_;
  std::vector<float> input_chw_;
  std::vector<float> depth_;
  std::vector<float> sky_;
  // The depth for the point cloud when the depth loan got no slot.
  cv::Mat fallback_;
  // The colors of the cloud when the image is on the device.
  std::vector<std::uint8_t> color_host_;
  // The latest camera_info, in the pixels of the camera image.
  std::optional<tensorrt_common::Intrinsics> camera_;

  std::unique_ptr<flux_wrapper::Publisher<sensor_msgs::msg::Image>> depth_pub_;
  std::unique_ptr<flux_wrapper::Publisher<sensor_msgs::msg::PointCloud2>> cloud_pub_;
  rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr info_sub_;
  std::unique_ptr<flux_wrapper::Subscription<sensor_msgs::msg::Image>> image_sub_;
  OnSetParametersCallbackHandle::SharedPtr parameters_handle_;
};

}  // namespace depth_anything3_mono_trt

#endif  // DEPTH_ANYTHING3_MONO_TRT_HPP_

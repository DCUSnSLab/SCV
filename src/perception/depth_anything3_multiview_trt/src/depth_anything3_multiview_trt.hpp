#ifndef DEPTH_ANYTHING3_MULTIVIEW_TRT_HPP_
#define DEPTH_ANYTHING3_MULTIVIEW_TRT_HPP_

#include "views.hpp"

#include <flux_wrapper/flux_wrapper.hpp>
#include <opencv2/core.hpp>
#include <rclcpp/rclcpp.hpp>
#include <tensorrt_common/engine.hpp>

#include <geometry_msgs/msg/pose_array.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace depth_anything3_multiview_trt
{

// The parameters that may change while the node runs.
struct Settings
{
  bool cloud = false;
  int cloud_downsample = 1;
};

class DepthAnything3MultiviewTrt : public rclcpp::Node
{
public:
  explicit DepthAnything3MultiviewTrt(const rclcpp::NodeOptions & options);

private:
  void on_image(std::size_t view, const flux_wrapper::View<sensor_msgs::msg::Image> & image);
  void infer(const std_msgs::msg::Header & header);
  void publish_cloud(std::size_t view, const std_msgs::msg::Header & header, const cv::Mat & depth);
  rcl_interfaces::msg::SetParametersResult on_set_parameters(
    const std::vector<rclcpp::Parameter> & parameters);

  Settings settings_;

  bool gpu_preprocess_;
  tensorrt_common::Engine engine_;
  std::size_t views_;
  cv::Size input_;
  ViewSet set_;
  // Source size and frame of each view, from its latest image.
  std::vector<cv::Size> sizes_;
  std::vector<std::string> frames_;
  std::vector<float> input_chw_;
  std::vector<float> depth_;
  std::vector<float> pose_;
  // The depth for the point cloud when a depth loan got no slot.
  cv::Mat fallback_;

  std::vector<std::unique_ptr<flux_wrapper::Publisher<sensor_msgs::msg::Image>>> depth_pubs_;
  std::vector<std::unique_ptr<flux_wrapper::Publisher<sensor_msgs::msg::PointCloud2>>> cloud_pubs_;
  rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr poses_pub_;
  std::vector<std::unique_ptr<flux_wrapper::Subscription<sensor_msgs::msg::Image>>> image_subs_;
  OnSetParametersCallbackHandle::SharedPtr parameters_handle_;
};

}  // namespace depth_anything3_multiview_trt

#endif  // DEPTH_ANYTHING3_MULTIVIEW_TRT_HPP_

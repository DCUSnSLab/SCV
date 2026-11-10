#ifndef SEMANTIC_SEGMENTATION_YOLO26_TRT_HPP_
#define SEMANTIC_SEGMENTATION_YOLO26_TRT_HPP_

#include <flux_wrapper/flux_wrapper.hpp>
#include <rclcpp/rclcpp.hpp>
#include <tensorrt_common/engine.hpp>

#include <sensor_msgs/msg/image.hpp>

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace semantic_segmentation_yolo26_trt
{

class SemanticSegmentationYolo26Trt : public rclcpp::Node
{
public:
  explicit SemanticSegmentationYolo26Trt(const rclcpp::NodeOptions & options);

private:
  void on_image(const flux_wrapper::View<sensor_msgs::msg::Image> & image);

  bool gpu_preprocess_;
  tensorrt_common::Engine engine_;
  std::string input_;
  std::string output_;
  std::vector<float> input_chw_;
  std::vector<std::uint8_t> output_map_;

  std::unique_ptr<flux_wrapper::Publisher<sensor_msgs::msg::Image>> classes_pub_;
  std::unique_ptr<flux_wrapper::Subscription<sensor_msgs::msg::Image>> image_sub_;
};

}  // namespace semantic_segmentation_yolo26_trt

#endif  // SEMANTIC_SEGMENTATION_YOLO26_TRT_HPP_

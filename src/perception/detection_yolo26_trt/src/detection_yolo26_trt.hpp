#ifndef DETECTION_YOLO26_TRT_HPP_
#define DETECTION_YOLO26_TRT_HPP_

#include <flux_wrapper/flux_wrapper.hpp>
#include <rclcpp/rclcpp.hpp>
#include <tensorrt_common/engine.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <vision_msgs/msg/detection2_d_array.hpp>

#include <memory>
#include <string>
#include <vector>

namespace detection_yolo26_trt
{

class DetectionYolo26Trt : public rclcpp::Node
{
public:
  explicit DetectionYolo26Trt(const rclcpp::NodeOptions & options);

private:
  void on_image(const flux_wrapper::View<sensor_msgs::msg::Image> & image);

  rcl_interfaces::msg::SetParametersResult on_set_parameters(
    const std::vector<rclcpp::Parameter> & parameters);

  float score_threshold_;
  std::vector<std::string> class_names_;
  bool gpu_preprocess_;
  tensorrt_common::Engine engine_;
  std::string input_;
  std::string output_;
  std::vector<float> input_chw_;
  std::vector<float> output_rows_;

  rclcpp::Publisher<vision_msgs::msg::Detection2DArray>::SharedPtr objects_pub_;
  std::unique_ptr<flux_wrapper::Subscription<sensor_msgs::msg::Image>> image_sub_;
  OnSetParametersCallbackHandle::SharedPtr parameters_handle_;
};

}  // namespace detection_yolo26_trt

#endif  // DETECTION_YOLO26_TRT_HPP_

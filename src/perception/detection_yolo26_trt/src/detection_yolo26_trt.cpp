#include "detection_yolo26_trt.hpp"

#include <rclcpp_components/register_node_macro.hpp>
#include <tensorrt_common/image.hpp>
#include <tensorrt_common/messages.hpp>
#include <tensorrt_common/parameters.hpp>
#include <tensorrt_common/yolo.hpp>

#include <cstddef>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace detection_yolo26_trt
{
namespace
{

}  // namespace

DetectionYolo26Trt::DetectionYolo26Trt(const rclcpp::NodeOptions & options)
: Node("detection_yolo26_trt", options),
  score_threshold_(static_cast<float>(declare_parameter<double>("score_threshold"))),
  class_names_(declare_parameter<std::vector<std::string>>("class_names")),
  gpu_preprocess_(tensorrt_common::declare_gpu_preprocess(*this)),
  engine_(tensorrt_common::declare_engine_options(*this)),
  input_(engine_.input_names().at(0)),
  output_(engine_.output_names().at(0))
{
  const auto & in = engine_.info(input_).shape;
  const auto & out = engine_.info(output_).shape;
  if (in.size() != 4 || in[0] != 1 || in[1] != 3 || out.size() != 3 || out[2] < 6) {
    throw std::runtime_error("expected a YOLO26 detect model exported with nms=False");
  }
  output_rows_.resize(engine_.info(output_).elements);

  objects_pub_ = create_publisher<vision_msgs::msg::Detection2DArray>("~/output/objects", 1);
  image_sub_ = std::make_unique<flux_wrapper::Subscription<sensor_msgs::msg::Image>>(
    *this, "~/input/image", rclcpp::SensorDataQoS().keep_last(1),
    [this](const flux_wrapper::View<sensor_msgs::msg::Image> & image) { on_image(image); },
    tensorrt_common::image_subscription(gpu_preprocess_));
  parameters_handle_ = add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & p) { return on_set_parameters(p); });
}

rcl_interfaces::msg::SetParametersResult DetectionYolo26Trt::on_set_parameters(
  const std::vector<rclcpp::Parameter> & parameters)
{
  rcl_interfaces::msg::SetParametersResult result;
  for (const auto & p : parameters) {
    if (p.get_name() != "score_threshold") {
      result.reason = p.get_name() + " takes effect only at start";
      return result;
    }
  }
  for (const auto & p : parameters) {
    score_threshold_ = static_cast<float>(p.as_double());
  }
  result.successful = true;
  return result;
}

void DetectionYolo26Trt::on_image(const flux_wrapper::View<sensor_msgs::msg::Image> & image)
{
  const int width = static_cast<int>(image.width());
  const int height = static_cast<int>(image.height());
  const auto view = tensorrt_common::view_of(image);
  const auto box = tensorrt_common::upload_yolo_input(
    engine_, input_, view, tensorrt_common::YoloFit::Letterbox, gpu_preprocess_, input_chw_);
  engine_.infer();
  engine_.download_float(output_, output_rows_.data());

  const auto & out = engine_.info(output_).shape;
  const auto detections = tensorrt_common::decode_end2end(
    output_rows_.data(), static_cast<std::size_t>(out[1]), static_cast<std::size_t>(out[2]), box,
    width, height, score_threshold_);

  auto msg = std::make_unique<vision_msgs::msg::Detection2DArray>();
  msg->header.stamp = image.stamp();
  msg->header.frame_id = std::string(image.frame_id());
  for (const auto & d : detections) {
    vision_msgs::msg::Detection2D det;
    det.header = msg->header;
    det.bbox.center.position.x = (d.x1 + d.x2) / 2.0;
    det.bbox.center.position.y = (d.y1 + d.y2) / 2.0;
    det.bbox.size_x = d.x2 - d.x1;
    det.bbox.size_y = d.y2 - d.y1;
    vision_msgs::msg::ObjectHypothesisWithPose hypothesis;
    const auto id = static_cast<std::size_t>(d.class_id);
    hypothesis.hypothesis.class_id =
      id < class_names_.size() ? class_names_[id] : std::to_string(d.class_id);
    hypothesis.hypothesis.score = d.score;
    det.results.push_back(hypothesis);
    msg->detections.push_back(std::move(det));
  }
  objects_pub_->publish(std::move(msg));
}

}  // namespace detection_yolo26_trt

RCLCPP_COMPONENTS_REGISTER_NODE(detection_yolo26_trt::DetectionYolo26Trt)

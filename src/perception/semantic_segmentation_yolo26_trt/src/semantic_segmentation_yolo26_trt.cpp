#include "semantic_segmentation_yolo26_trt.hpp"

#include <opencv2/imgproc.hpp>
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

namespace semantic_segmentation_yolo26_trt
{

SemanticSegmentationYolo26Trt::SemanticSegmentationYolo26Trt(const rclcpp::NodeOptions & options)
: Node("semantic_segmentation_yolo26_trt", options),
  gpu_preprocess_(tensorrt_common::declare_gpu_preprocess(*this)),
  engine_(tensorrt_common::declare_engine_options(*this)),
  input_(engine_.input_names().at(0)),
  output_(engine_.output_names().at(0))
{
  const auto & in = engine_.info(input_).shape;
  const auto & out = engine_.info(output_);
  if (
    in.size() != 4 || in[0] != 1 || in[1] != 3 || out.type != tensorrt_common::TensorType::UInt8 ||
    out.shape.size() != 3) {
    throw std::runtime_error(
      "expected a YOLO26 semantic model exported to ONNX (a uint8 class map)");
  }
  output_map_.resize(out.elements);

  flux_wrapper::PublisherOptions out_options;
  out_options.max_message_size =
    static_cast<std::uint32_t>(declare_parameter<std::int64_t>("output_slot_mb")) << 20;
  classes_pub_ = std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::Image>>(
    *this, "~/output/classes", rclcpp::QoS(1), out_options);
  image_sub_ = std::make_unique<flux_wrapper::Subscription<sensor_msgs::msg::Image>>(
    *this, "~/input/image", rclcpp::SensorDataQoS().keep_last(1),
    [this](const flux_wrapper::View<sensor_msgs::msg::Image> & image) { on_image(image); },
    tensorrt_common::image_subscription(gpu_preprocess_));
}

void SemanticSegmentationYolo26Trt::on_image(
  const flux_wrapper::View<sensor_msgs::msg::Image> & image)
{
  const int width = static_cast<int>(image.width());
  const int height = static_cast<int>(image.height());
  const auto & in = engine_.info(input_).shape;
  const int in_h = static_cast<int>(in[2]);
  const int in_w = static_cast<int>(in[3]);
  const auto view = tensorrt_common::view_of(image);
  const auto box = tensorrt_common::upload_yolo_input(
    engine_, input_, view, tensorrt_common::YoloFit::Letterbox, gpu_preprocess_, input_chw_);
  engine_.infer();
  engine_.download_raw(output_, output_map_.data());
  const cv::Mat map(in_h, in_w, CV_8UC1, output_map_.data());

  std_msgs::msg::Header header;
  header.stamp = image.stamp();
  header.frame_id = std::string(image.frame_id());
  auto loan = classes_pub_->loan();
  cv::Mat out = tensorrt_common::loan_image(loan, header, {width, height}, CV_8UC1, "mono8");
  if (out.empty()) {
    RCLCPP_WARN_THROTTLE(
      get_logger(), *get_clock(), 5000, "classes not sent; is output_slot_mb too small?");
    return;
  }
  tensorrt_common::unletterbox(map, box, out, cv::INTER_NEAREST);
  classes_pub_->publish(std::move(loan));
}

}  // namespace semantic_segmentation_yolo26_trt

RCLCPP_COMPONENTS_REGISTER_NODE(semantic_segmentation_yolo26_trt::SemanticSegmentationYolo26Trt)

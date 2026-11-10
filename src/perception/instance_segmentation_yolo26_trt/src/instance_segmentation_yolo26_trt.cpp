#include "instance_segmentation_yolo26_trt.hpp"

#include "instance_mask.hpp"

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

namespace instance_segmentation_yolo26_trt
{
namespace
{

// The detection output has rank 3 (1, rows, cols), the prototypes rank 4 (1, count, h, w).
std::string output_of_rank(const tensorrt_common::Engine & engine, std::size_t rank)
{
  for (const auto & name : engine.output_names()) {
    if (engine.info(name).shape.size() == rank) {
      return name;
    }
  }
  throw std::runtime_error("expected a YOLO26 segment model exported with nms=False");
}

// Detection i carries id i + 1, its value in ~/output/instances.
std::unique_ptr<vision_msgs::msg::Detection2DArray> to_objects(
  const std::vector<tensorrt_common::Detection> & detections, const std_msgs::msg::Header & header,
  const std::vector<std::string> & class_names)
{
  auto objects = std::make_unique<vision_msgs::msg::Detection2DArray>();
  objects->header = header;
  for (std::size_t i = 0; i < detections.size(); ++i) {
    const auto & d = detections[i];
    vision_msgs::msg::Detection2D det;
    det.header = header;
    det.id = std::to_string(i + 1);
    det.bbox.center.position.x = (d.x1 + d.x2) / 2.0;
    det.bbox.center.position.y = (d.y1 + d.y2) / 2.0;
    det.bbox.size_x = d.x2 - d.x1;
    det.bbox.size_y = d.y2 - d.y1;
    vision_msgs::msg::ObjectHypothesisWithPose hypothesis;
    const auto id = static_cast<std::size_t>(d.class_id);
    hypothesis.hypothesis.class_id =
      id < class_names.size() ? class_names[id] : std::to_string(d.class_id);
    hypothesis.hypothesis.score = d.score;
    det.results.push_back(hypothesis);
    objects->detections.push_back(std::move(det));
  }
  return objects;
}

}  // namespace

InstanceSegmentationYolo26Trt::InstanceSegmentationYolo26Trt(const rclcpp::NodeOptions & options)
: Node("instance_segmentation_yolo26_trt", options),
  score_threshold_(static_cast<float>(declare_parameter<double>("score_threshold"))),
  class_names_(declare_parameter<std::vector<std::string>>("class_names")),
  gpu_preprocess_(tensorrt_common::declare_gpu_preprocess(*this)),
  engine_(tensorrt_common::declare_engine_options(*this)),
  input_(engine_.input_names().at(0)),
  rows_output_(output_of_rank(engine_, 3)),
  protos_output_(output_of_rank(engine_, 4))
{
  rows_.resize(engine_.info(rows_output_).elements);
  protos_.resize(engine_.info(protos_output_).elements);

  flux_wrapper::PublisherOptions mask_options;
  mask_options.max_message_size =
    static_cast<std::uint32_t>(declare_parameter<std::int64_t>("output_slot_mb")) << 20;
  objects_pub_ = create_publisher<vision_msgs::msg::Detection2DArray>("~/output/objects", 1);
  mask_pub_ = std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::Image>>(
    *this, "~/output/instances", rclcpp::QoS(1), mask_options);
  image_sub_ = std::make_unique<flux_wrapper::Subscription<sensor_msgs::msg::Image>>(
    *this, "~/input/image", rclcpp::SensorDataQoS().keep_last(1),
    [this](const flux_wrapper::View<sensor_msgs::msg::Image> & image) { on_image(image); },
    tensorrt_common::image_subscription(gpu_preprocess_));
  parameters_handle_ = add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & p) { return on_set_parameters(p); });
}

rcl_interfaces::msg::SetParametersResult InstanceSegmentationYolo26Trt::on_set_parameters(
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

void InstanceSegmentationYolo26Trt::on_image(
  const flux_wrapper::View<sensor_msgs::msg::Image> & image)
{
  const int width = static_cast<int>(image.width());
  const int height = static_cast<int>(image.height());
  const auto & in = engine_.info(input_).shape;
  const cv::Size input(static_cast<int>(in[3]), static_cast<int>(in[2]));
  const auto view = tensorrt_common::view_of(image);
  const auto box = tensorrt_common::upload_yolo_input(
    engine_, input_, view, tensorrt_common::YoloFit::Letterbox, gpu_preprocess_, input_chw_);
  engine_.infer();
  engine_.download_float(rows_output_, rows_.data());

  const auto & rs = engine_.info(rows_output_).shape;
  const auto & ps = engine_.info(protos_output_).shape;
  const auto cols = static_cast<std::size_t>(rs[2]);
  const auto detections = tensorrt_common::decode_end2end(
    rows_.data(), static_cast<std::size_t>(rs[1]), cols, box, width, height, score_threshold_);

  std_msgs::msg::Header header;
  header.stamp = image.stamp();
  header.frame_id = std::string(image.frame_id());
  objects_pub_->publish(to_objects(detections, header, class_names_));
  auto loan = mask_pub_->loan();
  cv::Mat mask = tensorrt_common::loan_image(loan, header, {width, height}, CV_16UC1, "mono16");
  if (mask.empty()) {
    RCLCPP_WARN_THROTTLE(
      get_logger(), *get_clock(), 5000, "instance mask not sent; is output_slot_mb too small?");
    return;
  }
  // With no detection the mask is all background and the prototypes are not needed.
  if (!detections.empty()) {
    engine_.download_float(protos_output_, protos_.data());
  }
  const Prototypes protos{
    protos_.data(), static_cast<int>(ps[1]), static_cast<int>(ps[2]), static_cast<int>(ps[3])};
  instance_mask(detections, rows_.data(), cols, protos, box, input, mask);
  mask_pub_->publish(std::move(loan));
}

}  // namespace instance_segmentation_yolo26_trt

RCLCPP_COMPONENTS_REGISTER_NODE(instance_segmentation_yolo26_trt::InstanceSegmentationYolo26Trt)

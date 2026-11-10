#include "depth_yolo26_trt.hpp"

#include <opencv2/imgproc.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <tensorrt_common/depth.hpp>
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

namespace depth_yolo26_trt
{
namespace
{

// False when the parameter cannot change while the node runs.
bool apply(Settings & s, const rclcpp::Parameter & p)
{
  const auto & n = p.get_name();
  if (n == "point_cloud.enabled") {
    s.cloud = p.as_bool();
  } else if (n == "point_cloud.downsample") {
    if (p.as_int() < 1) {
      throw std::invalid_argument("point_cloud.downsample must be 1 or more");
    }
    s.cloud_downsample = static_cast<int>(p.as_int());
  } else if (n == "point_cloud.colorize") {
    s.cloud_colorize = p.as_bool();
  } else {
    return false;
  }
  return true;
}

Settings declare_settings(rclcpp::Node & node)
{
  Settings s;
  for (const auto * name : {"point_cloud.enabled", "point_cloud.colorize"}) {
    apply(s, rclcpp::Parameter(name, node.declare_parameter<bool>(name)));
  }
  apply(
    s, rclcpp::Parameter(
         "point_cloud.downsample", node.declare_parameter<std::int64_t>("point_cloud.downsample")));
  return s;
}

}  // namespace

DepthYolo26Trt::DepthYolo26Trt(const rclcpp::NodeOptions & options)
: Node("depth_yolo26_trt", options),
  settings_(declare_settings(*this)),
  gpu_preprocess_(tensorrt_common::declare_gpu_preprocess(*this)),
  engine_(tensorrt_common::declare_engine_options(*this)),
  input_(engine_.input_names().at(0)),
  output_(engine_.output_names().at(0))
{
  const auto & in = engine_.info(input_).shape;
  const auto & out = engine_.info(output_);
  if (in.size() != 4 || in[0] != 1 || in[1] != 3 || out.shape.size() != 4 || out.shape[1] != 1) {
    throw std::runtime_error("expected a YOLO26 depth model exported to ONNX (1, 1, H, W)");
  }
  output_map_.resize(out.elements);

  flux_wrapper::PublisherOptions out_options;
  out_options.max_message_size =
    static_cast<std::uint32_t>(declare_parameter<std::int64_t>("output_slot_mb")) << 20;
  depth_pub_ = std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::Image>>(
    *this, "~/output/depth", rclcpp::QoS(1), out_options);
  flux_wrapper::PublisherOptions cloud_options;
  cloud_options.max_message_size =
    static_cast<std::uint32_t>(declare_parameter<std::int64_t>("point_cloud.slot_mb")) << 20;
  cloud_pub_ = std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::PointCloud2>>(
    *this, "~/output/points", rclcpp::QoS(1), cloud_options);
  info_sub_ = create_subscription<sensor_msgs::msg::CameraInfo>(
    "~/input/camera_info", rclcpp::SensorDataQoS().keep_last(1),
    [this](const sensor_msgs::msg::CameraInfo & info) {
      camera_ = tensorrt_common::Intrinsics{info.k[0], info.k[4], info.k[2], info.k[5]};
    });
  image_sub_ = std::make_unique<flux_wrapper::Subscription<sensor_msgs::msg::Image>>(
    *this, "~/input/image", rclcpp::SensorDataQoS().keep_last(1),
    [this](const flux_wrapper::View<sensor_msgs::msg::Image> & image) { on_image(image); },
    tensorrt_common::image_subscription(gpu_preprocess_));
  parameters_handle_ = add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & p) { return on_set_parameters(p); });
}

rcl_interfaces::msg::SetParametersResult DepthYolo26Trt::on_set_parameters(
  const std::vector<rclcpp::Parameter> & parameters)
{
  rcl_interfaces::msg::SetParametersResult result;
  Settings next = settings_;
  try {
    for (const auto & p : parameters) {
      if (!apply(next, p)) {
        result.reason = p.get_name() + " takes effect only at start";
        return result;
      }
    }
  } catch (const std::exception & e) {
    result.reason = e.what();
    return result;
  }
  settings_ = next;
  result.successful = true;
  return result;
}

void DepthYolo26Trt::on_image(const flux_wrapper::View<sensor_msgs::msg::Image> & image)
{
  const int width = static_cast<int>(image.width());
  const int height = static_cast<int>(image.height());
  const auto & in = engine_.info(input_).shape;
  const int in_h = static_cast<int>(in[2]);
  const int in_w = static_cast<int>(in[3]);
  const auto view = tensorrt_common::view_of(image);
  tensorrt_common::upload_yolo_input(
    engine_, input_, view, tensorrt_common::YoloFit::Stretch, gpu_preprocess_, input_chw_);
  engine_.infer();
  engine_.download_float(output_, output_map_.data());
  const cv::Mat map(in_h, in_w, CV_32FC1, output_map_.data());

  std_msgs::msg::Header header;
  header.stamp = image.stamp();
  header.frame_id = std::string(image.frame_id());
  auto loan = depth_pub_->loan();
  cv::Mat out = tensorrt_common::loan_image(loan, header, {width, height}, CV_32FC1, "32FC1");
  if (out.empty()) {
    RCLCPP_WARN_THROTTLE(
      get_logger(), *get_clock(), 5000, "depth not sent; is output_slot_mb too small?");
    if (!settings_.cloud) {
      return;
    }
    fallback_.create(height, width, CV_32FC1);
    out = fallback_;
  }
  // DepthPredictor.postprocess: bilinear with align_corners=True to the image size.
  tensorrt_common::resize_align_corners(map, out);
  // The cloud is made first: the depth in the loan is not ours once it is published.
  if (settings_.cloud) {
    publish_cloud(header, out, image);
  }
  if (loan) {
    depth_pub_->publish(std::move(loan));
  }
}

void DepthYolo26Trt::publish_cloud(
  const std_msgs::msg::Header & header, const cv::Mat & depth,
  const flux_wrapper::View<sensor_msgs::msg::Image> & image)
{
  if (!camera_) {
    RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000, "no camera_info yet: no point cloud");
    return;
  }
  const auto layout = tensorrt_common::cloud_layout(
    depth.size(), settings_.cloud_downsample, settings_.cloud_colorize);
  auto loan = cloud_pub_->loan();
  auto * data = tensorrt_common::loan_cloud(loan, header, layout);
  if (data == nullptr) {
    RCLCPP_WARN_THROTTLE(
      get_logger(), *get_clock(), 5000, "point cloud not sent; is point_cloud.slot_mb too small?");
    return;
  }
  // A frame on the device is copied to the host for the colors only.
  const auto color = layout.rgb
                       ? tensorrt_common::host_copy(tensorrt_common::view_of(image), color_host_)
                       : tensorrt_common::ImageView{};
  tensorrt_common::depth_to_cloud(
    depth, *camera_, settings_.cloud_downsample, layout.rgb ? &color : nullptr, layout, data);
  cloud_pub_->publish(std::move(loan));
}

}  // namespace depth_yolo26_trt

RCLCPP_COMPONENTS_REGISTER_NODE(depth_yolo26_trt::DepthYolo26Trt)

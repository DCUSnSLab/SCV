#include "depth_anything3_mono_trt.hpp"

#include "depth_map.hpp"

#include <opencv2/imgproc.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <tensorrt_common/image.hpp>
#include <tensorrt_common/messages.hpp>
#include <tensorrt_common/parameters.hpp>

#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace depth_anything3_mono_trt
{
namespace
{

// False when the parameter cannot change while the node runs.
bool apply(Settings & s, const rclcpp::Parameter & p)
{
  const auto & n = p.get_name();
  if (n == "sky_threshold") {
    s.sky_threshold = static_cast<float>(p.as_double());
  } else if (n == "sky_mode") {
    const auto mode = p.as_string();
    if (mode != "inf" && mode != "fill") {
      throw std::invalid_argument("sky_mode must be inf or fill, got " + mode);
    }
    s.sky_fill = mode == "fill";
  } else if (n == "sky_quantile") {
    s.sky_quantile = static_cast<float>(p.as_double());
  } else if (n == "sky_depth_cap") {
    s.sky_depth_cap = static_cast<float>(p.as_double());
  } else if (n == "point_cloud.enabled") {
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
  for (const auto * name : {"sky_threshold", "sky_quantile", "sky_depth_cap"}) {
    apply(s, rclcpp::Parameter(name, node.declare_parameter<double>(name)));
  }
  apply(s, rclcpp::Parameter("sky_mode", node.declare_parameter<std::string>("sky_mode")));
  for (const auto * name : {"point_cloud.enabled", "point_cloud.colorize"}) {
    apply(s, rclcpp::Parameter(name, node.declare_parameter<bool>(name)));
  }
  apply(
    s, rclcpp::Parameter(
         "point_cloud.downsample", node.declare_parameter<std::int64_t>("point_cloud.downsample")));
  return s;
}

flux_wrapper::PublisherOptions slot(rclcpp::Node & node, const std::string & name)
{
  flux_wrapper::PublisherOptions o;
  o.max_message_size = static_cast<std::uint32_t>(node.declare_parameter<std::int64_t>(name)) << 20;
  return o;
}

}  // namespace

DepthAnything3MonoTrt::DepthAnything3MonoTrt(const rclcpp::NodeOptions & options)
: Node("depth_anything3_mono_trt", options),
  metric_(declare_parameter<bool>("metric")),
  settings_(declare_settings(*this)),
  gpu_preprocess_(tensorrt_common::declare_gpu_preprocess(*this)),
  engine_(tensorrt_common::declare_engine_options(*this))
{
  const auto & in = engine_.info("image").shape;
  if (in.size() != 4 || in[0] != 1 || in[1] != 3) {
    throw std::runtime_error("expected the ONNX file of scripts/export_onnx.py");
  }
  input_chw_.resize(engine_.info("image").elements);
  depth_.resize(engine_.info("depth").elements);
  sky_.resize(engine_.info("sky").elements);

  depth_pub_ = std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::Image>>(
    *this, "~/output/depth", rclcpp::QoS(1), slot(*this, "output_slot_mb"));
  cloud_pub_ = std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::PointCloud2>>(
    *this, "~/output/points", rclcpp::QoS(1), slot(*this, "point_cloud.slot_mb"));
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

rcl_interfaces::msg::SetParametersResult DepthAnything3MonoTrt::on_set_parameters(
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

void DepthAnything3MonoTrt::on_image(const flux_wrapper::View<sensor_msgs::msg::Image> & image)
{
  if (metric_ && !camera_) {
    RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000, "no camera_info yet: image dropped");
    return;
  }
  const cv::Size source(static_cast<int>(image.width()), static_cast<int>(image.height()));
  const auto & in = engine_.info("image").shape;
  const cv::Size input(static_cast<int>(in[3]), static_cast<int>(in[2]));
  if (gpu_preprocess_) {
    // The Depth Anything 3 resize: area when shrinking, cubic when enlarging.
    const auto resize =
      input.width < source.width ? tensorrt_common::Resize::Area : tensorrt_common::Resize::Cubic;
    engine_.upload_image(
      "image", 0, tensorrt_common::view_of(image), {0, 0, input.width, input.height, 0.0F}, resize,
      kMean, kStd);
  } else {
    const cv::Mat rgb = tensorrt_common::to_rgb(
      image.encoding(), image.data().data(), source.width, source.height, image.step());
    tensorrt_common::to_chw(resize_for_network(rgb, input), kMean, kStd, input_chw_.data());
    engine_.upload_float("image", input_chw_.data());
  }
  engine_.infer();
  engine_.download_float("depth", depth_.data());
  engine_.download_float("sky", sky_.data());

  std_msgs::msg::Header header;
  header.stamp = image.stamp();
  header.frame_id = std::string(image.frame_id());
  auto loan = depth_pub_->loan();
  cv::Mat depth = tensorrt_common::loan_image(loan, header, source, CV_32FC1, "32FC1");
  if (depth.empty()) {
    RCLCPP_WARN_THROTTLE(
      get_logger(), *get_clock(), 5000, "depth not sent; is output_slot_mb too small?");
    if (!settings_.cloud) {
      return;
    }
    fallback_.create(source, CV_32FC1);
    depth = fallback_;
  }
  to_depth(input, depth);
  // The cloud is made first: the depth in the loan is not ours once it is published.
  if (settings_.cloud) {
    publish_cloud(header, depth, image);
  }
  if (loan) {
    depth_pub_->publish(std::move(loan));
  }
}

void DepthAnything3MonoTrt::to_depth(cv::Size input, cv::Mat & out)
{
  const cv::Size source = out.size();
  cv::Mat depth(input, CV_32FC1, depth_.data());
  const cv::Mat sky(input, CV_32FC1, sky_.data());
  if (metric_) {
    to_meters(depth, camera_->fx, camera_->fy, source);
  }
  if (settings_.sky_fill) {
    // Filled at network size, as Depth Anything 3 does, then resized like the ground. Like
    // _process_mono_sky_estimation, 10 sky pixels or fewer are left as they are.
    const int sky_pixels = cv::countNonZero(sky >= settings_.sky_threshold);
    if (sky_pixels > 10 && static_cast<int>(sky.total()) - sky_pixels > 10) {
      mark_sky(
        depth, sky, settings_.sky_threshold,
        tensorrt_common::sky_fill_value(
          depth, sky, settings_.sky_threshold, settings_.sky_quantile, settings_.sky_depth_cap));
    }
    cv::resize(depth, out, source, 0, 0, cv::INTER_LINEAR);
    return;
  }
  // Resized before the sky is marked, so that the +inf does not spread into its neighbors.
  cv::Mat sky_at_source;
  cv::resize(depth, out, source, 0, 0, cv::INTER_LINEAR);
  cv::resize(sky, sky_at_source, source, 0, 0, cv::INTER_LINEAR);
  mark_sky(out, sky_at_source, settings_.sky_threshold, std::numeric_limits<float>::infinity());
}

void DepthAnything3MonoTrt::publish_cloud(
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

}  // namespace depth_anything3_mono_trt

RCLCPP_COMPONENTS_REGISTER_NODE(depth_anything3_mono_trt::DepthAnything3MonoTrt)

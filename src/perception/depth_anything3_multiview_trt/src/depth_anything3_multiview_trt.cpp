#include "depth_anything3_multiview_trt.hpp"

#include <opencv2/imgproc.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <tensorrt_common/image.hpp>
#include <tensorrt_common/messages.hpp>
#include <tensorrt_common/parameters.hpp>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace depth_anything3_multiview_trt
{
namespace
{

std::size_t view_count(const tensorrt_common::Engine & engine)
{
  const auto & in = engine.info("images").shape;
  if (in.size() != 5 || in[0] != 1 || in[2] != 3) {
    throw std::runtime_error("expected the ONNX file of scripts/export_onnx.py");
  }
  return static_cast<std::size_t>(in[1]);
}

geometry_msgs::msg::PoseArray to_pose_array(
  const std_msgs::msg::Header & header, const std::vector<tf2::Transform> & transforms)
{
  geometry_msgs::msg::PoseArray poses;
  poses.header = header;
  for (const auto & t : transforms) {
    geometry_msgs::msg::Pose p;
    p.position.x = t.getOrigin().x();
    p.position.y = t.getOrigin().y();
    p.position.z = t.getOrigin().z();
    const auto q = t.getRotation();
    p.orientation.x = q.x();
    p.orientation.y = q.y();
    p.orientation.z = q.z();
    p.orientation.w = q.w();
    poses.poses.push_back(p);
  }
  return poses;
}

// False when the parameter cannot change while the node runs.
bool apply(Settings & s, const rclcpp::Parameter & p)
{
  if (p.get_name() == "point_cloud.enabled") {
    s.cloud = p.as_bool();
  } else if (p.get_name() == "point_cloud.downsample") {
    if (p.as_int() < 1) {
      throw std::invalid_argument("point_cloud.downsample must be 1 or more");
    }
    s.cloud_downsample = static_cast<int>(p.as_int());
  } else {
    return false;
  }
  return true;
}

Settings declare_settings(rclcpp::Node & node)
{
  Settings s;
  apply(
    s,
    rclcpp::Parameter("point_cloud.enabled", node.declare_parameter<bool>("point_cloud.enabled")));
  apply(
    s, rclcpp::Parameter(
         "point_cloud.downsample", node.declare_parameter<std::int64_t>("point_cloud.downsample")));
  return s;
}

}  // namespace

DepthAnything3MultiviewTrt::DepthAnything3MultiviewTrt(const rclcpp::NodeOptions & options)
: Node("depth_anything3_multiview_trt", options),
  settings_(declare_settings(*this)),
  gpu_preprocess_(tensorrt_common::declare_gpu_preprocess(*this)),
  engine_(tensorrt_common::declare_engine_options(*this)),
  views_(view_count(engine_)),
  input_(
    static_cast<int>(engine_.info("images").shape[4]),
    static_cast<int>(engine_.info("images").shape[3])),
  set_(views_, static_cast<std::int64_t>(declare_parameter<double>("max_skew_sec") * 1e9)),
  sizes_(views_),
  frames_(views_),
  input_chw_(engine_.info("images").elements),
  depth_(engine_.info("depth").elements),
  pose_(engine_.info("pose").elements)
{
  flux_wrapper::PublisherOptions out_options;
  out_options.max_message_size =
    static_cast<std::uint32_t>(declare_parameter<std::int64_t>("output_slot_mb")) << 20;
  flux_wrapper::PublisherOptions cloud_options;
  cloud_options.max_message_size =
    static_cast<std::uint32_t>(declare_parameter<std::int64_t>("point_cloud.slot_mb")) << 20;
  poses_pub_ = create_publisher<geometry_msgs::msg::PoseArray>("~/output/poses", 1);
  for (std::size_t i = 0; i < views_; ++i) {
    const auto n = std::to_string(i);
    depth_pubs_.push_back(std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::Image>>(
      *this, "~/output/depth_" + n, rclcpp::QoS(1), out_options));
    cloud_pubs_.push_back(std::make_unique<flux_wrapper::Publisher<sensor_msgs::msg::PointCloud2>>(
      *this, "~/output/points_" + n, rclcpp::QoS(1), cloud_options));
    image_subs_.push_back(std::make_unique<flux_wrapper::Subscription<sensor_msgs::msg::Image>>(
      *this, "~/input/image_" + n, rclcpp::SensorDataQoS().keep_last(1),
      [this, i](const flux_wrapper::View<sensor_msgs::msg::Image> & image) { on_image(i, image); },
      tensorrt_common::image_subscription(gpu_preprocess_)));
  }
  parameters_handle_ = add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & p) { return on_set_parameters(p); });
}

rcl_interfaces::msg::SetParametersResult DepthAnything3MultiviewTrt::on_set_parameters(
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

void DepthAnything3MultiviewTrt::on_image(
  std::size_t view, const flux_wrapper::View<sensor_msgs::msg::Image> & image)
{
  const cv::Size source(static_cast<int>(image.width()), static_cast<int>(image.height()));
  const rclcpp::Time stamp(image.stamp());
  // Preprocessed now: a flux image is valid only during this callback. The GPU path writes the
  // slot of this view in the network input; the CPU path keeps the smaller resized copy.
  if (gpu_preprocess_) {
    const auto resize =
      input_.width < source.width ? tensorrt_common::Resize::Area : tensorrt_common::Resize::Cubic;
    engine_.upload_image(
      "images", view, tensorrt_common::view_of(image), {0, 0, input_.width, input_.height, 0.0F},
      resize, kMean, kStd);
    set_.put(view, stamp.nanoseconds(), cv::Mat());
  } else {
    set_.put(
      view, stamp.nanoseconds(),
      resize_for_network(
        tensorrt_common::to_rgb(
          image.encoding(), image.data().data(), source.width, source.height, image.step()),
        input_));
  }
  sizes_[view] = source;
  frames_[view] = std::string(image.frame_id());
  // View 0 sets the pace; the other views supply their latest image.
  if (view == 0 && set_.complete()) {
    std_msgs::msg::Header header;
    header.stamp = image.stamp();
    header.frame_id = frames_[0];
    infer(header);
  }
}

void DepthAnything3MultiviewTrt::infer(const std_msgs::msg::Header & header)
{
  if (!gpu_preprocess_) {
    const std::size_t chw = 3 * static_cast<std::size_t>(input_.area());
    for (std::size_t i = 0; i < views_; ++i) {
      tensorrt_common::to_chw(set_.image(i), kMean, kStd, input_chw_.data() + i * chw);
    }
    engine_.upload_float("images", input_chw_.data());
  }
  engine_.infer();
  engine_.download_float("depth", depth_.data());
  engine_.download_float("pose", pose_.data());

  poses_pub_->publish(to_pose_array(header, poses_in_view0(pose_.data(), views_)));

  for (std::size_t i = 0; i < views_; ++i) {
    const cv::Mat at_input(input_, CV_32FC1, depth_.data() + i * input_.area());
    std_msgs::msg::Header view_header = header;
    view_header.frame_id = frames_[i];
    auto loan = depth_pubs_[i]->loan();
    cv::Mat out = tensorrt_common::loan_image(loan, view_header, sizes_[i], CV_32FC1, "32FC1");
    if (out.empty()) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 5000, "depth not sent; is output_slot_mb too small?");
      if (!settings_.cloud) {
        continue;
      }
      fallback_.create(sizes_[i], CV_32FC1);
      out = fallback_;
    }
    cv::resize(at_input, out, sizes_[i], 0, 0, cv::INTER_LINEAR);
    // The cloud is made first: the depth in the loan is not ours once it is published.
    if (settings_.cloud) {
      publish_cloud(i, view_header, out);
    }
    if (loan) {
      depth_pubs_[i]->publish(std::move(loan));
    }
  }
}

void DepthAnything3MultiviewTrt::publish_cloud(
  std::size_t view, const std_msgs::msg::Header & header, const cv::Mat & depth)
{
  // In the scale of the model, like the depth: no camera_info, the intrinsics are predicted.
  const auto k = tensorrt_common::scale_intrinsics(
    intrinsics_of_view(pose_.data(), view, input_), input_, depth.size());
  const auto layout =
    tensorrt_common::cloud_layout(depth.size(), settings_.cloud_downsample, false);
  auto loan = cloud_pubs_[view]->loan();
  auto * data = tensorrt_common::loan_cloud(loan, header, layout);
  if (data == nullptr) {
    RCLCPP_WARN_THROTTLE(
      get_logger(), *get_clock(), 5000, "point cloud not sent; is point_cloud.slot_mb too small?");
    return;
  }
  tensorrt_common::depth_to_cloud(depth, k, settings_.cloud_downsample, nullptr, layout, data);
  cloud_pubs_[view]->publish(std::move(loan));
}

}  // namespace depth_anything3_multiview_trt

RCLCPP_COMPONENTS_REGISTER_NODE(depth_anything3_multiview_trt::DepthAnything3MultiviewTrt)

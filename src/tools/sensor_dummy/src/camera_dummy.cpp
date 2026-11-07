#include "camera_dummy.hpp"

#include "fault_params.hpp"
#include "fault_traits.hpp"

#include <rclcpp_components/register_node_macro.hpp>

#include <chrono>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace sensor_dummy
{
namespace
{
std::chrono::nanoseconds period_of(double rate_hz)
{
  return std::chrono::duration_cast<std::chrono::nanoseconds>(
    std::chrono::duration<double>(1.0 / rate_hz));
}
}  // namespace

CameraDummy::CameraDummy(const rclcpp::NodeOptions & options)
: rclcpp::Node("camera_dummy", options), fault_(declare_fault(*this, "fault"))
{
  for (const auto & name : declare_parameter<std::vector<std::string>>("streams")) {
    add_stream(name);
  }
  if (declare_parameter<bool>("imu.enable")) {
    setup_imu();
  }
  timers_.push_back(create_wall_timer(
    period_of(declare_parameter<double>("flush_rate_hz")), [this]() { on_flush_tick(); }));
  parameter_handle_ =
    add_on_set_parameters_callback([this](const std::vector<rclcpp::Parameter> & parameters) {
      return on_parameters(parameters);
    });
}

void CameraDummy::add_stream(const std::string & name)
{
  const std::string prefix = "stream." + name + ".";
  const auto width = declare_parameter<std::int64_t>(prefix + "width");
  const auto height = declare_parameter<std::int64_t>(prefix + "height");
  const auto encoding = declare_parameter<std::string>(prefix + "encoding");
  const auto frame_id = declare_parameter<std::string>(prefix + "frame_id");
  const auto rate_hz = declare_parameter<double>(prefix + "rate_hz");
  const auto fx = declare_parameter<double>(prefix + "fx");
  const auto fy = declare_parameter<double>(prefix + "fy");
  const auto cx = declare_parameter<double>(prefix + "cx");
  const auto cy = declare_parameter<double>(prefix + "cy");

  auto stream = std::make_unique<Stream>();
  stream->pattern = std::make_unique<TestPattern>(
    width, height, encoding, declare_parameter<double>(prefix + "plane_m"),
    declare_parameter<double>(prefix + "bar_m"));

  stream->image.header.frame_id = frame_id;
  stream->image.width = width;
  stream->image.height = height;
  stream->image.encoding = encoding;
  stream->image.step = stream->pattern->step();

  auto & info = stream->info;
  info.header.frame_id = frame_id;
  info.width = width;
  info.height = height;
  info.distortion_model = declare_parameter<std::string>(prefix + "distortion_model");
  info.d.assign(declare_parameter<std::int64_t>(prefix + "distortion_size"), 0.0);
  info.k = {fx, 0.0, cx, 0.0, fy, cy, 0.0, 0.0, 1.0};
  info.r = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  info.p = {fx, 0.0, cx, 0.0, 0.0, fy, cy, 0.0, 0.0, 0.0, 1.0, 0.0};

  const std::string output = "~/output/" + name;
  stream->image_pub = create_publisher<sensor_msgs::msg::Image>(output + "/image", 10);
  stream->info_pub = create_publisher<sensor_msgs::msg::CameraInfo>(output + "/camera_info", 10);
  stream->image_output = std::make_unique<FaultFilter<sensor_msgs::msg::Image>>(
    fault_, [pub = stream->image_pub](const sensor_msgs::msg::Image & msg) { pub->publish(msg); });
  stream->info_output = std::make_unique<FaultFilter<sensor_msgs::msg::CameraInfo>>(
    fault_,
    [pub = stream->info_pub](const sensor_msgs::msg::CameraInfo & msg) { pub->publish(msg); });

  Stream * raw = stream.get();
  timers_.push_back(create_wall_timer(period_of(rate_hz), [this, raw]() { on_stream_tick(*raw); }));
  streams_.push_back(std::move(stream));
}

void CameraDummy::setup_imu()
{
  const auto acceleration = declare_parameter<std::vector<double>>("imu.linear_acceleration");
  imu_.header.frame_id = declare_parameter<std::string>("imu.frame_id");
  imu_.linear_acceleration.x = acceleration.at(0);
  imu_.linear_acceleration.y = acceleration.at(1);
  imu_.linear_acceleration.z = acceleration.at(2);
  imu_.orientation.w = 1.0;
  imu_pub_ = create_publisher<sensor_msgs::msg::Imu>("~/output/imu", 10);
  imu_output_ = std::make_unique<FaultFilter<sensor_msgs::msg::Imu>>(
    fault_, [pub = imu_pub_](const sensor_msgs::msg::Imu & msg) { pub->publish(msg); });
  timers_.push_back(create_wall_timer(
    period_of(declare_parameter<double>("imu.rate_hz")), [this]() { on_imu_tick(); }));
}

void CameraDummy::on_stream_tick(Stream & stream)
{
  const rclcpp::Time time = now();
  const std::int64_t now_ns = time.nanoseconds();
  stream.image.header.stamp = time;
  stream.info.header.stamp = time;
  // Both real drivers skip the conversion when nobody listens; a ring of 8 needs that here too.
  if (stream.image_pub->get_subscription_count() > 0) {
    stream.pattern->render(stream.seq, stream.image.data);
    stream.image_output->push(stream.image, now_ns);
  }
  ++stream.seq;
  auto info = stream.info;
  stream.info_output->push(info, now_ns);
}

void CameraDummy::on_imu_tick()
{
  const rclcpp::Time time = now();
  imu_.header.stamp = time;
  auto imu = imu_;
  imu_output_->push(imu, time.nanoseconds());
}

void CameraDummy::on_flush_tick()
{
  const std::int64_t now_ns = now().nanoseconds();
  for (auto & stream : streams_) {
    stream->image_output->flush(now_ns);
    stream->info_output->flush(now_ns);
  }
  if (imu_output_) {
    imu_output_->flush(now_ns);
  }
}

rcl_interfaces::msg::SetParametersResult CameraDummy::on_parameters(
  const std::vector<rclcpp::Parameter> & parameters)
{
  rcl_interfaces::msg::SetParametersResult result;
  result.successful = true;
  try {
    for (const auto & parameter : parameters) {
      update_fault(fault_, "fault", parameter);
    }
  } catch (const std::invalid_argument & e) {
    result.successful = false;
    result.reason = e.what();
  }
  return result;
}

}  // namespace sensor_dummy

RCLCPP_COMPONENTS_REGISTER_NODE(sensor_dummy::CameraDummy)

#ifndef TENSORRT_COMMON__MESSAGES_HPP_
#define TENSORRT_COMMON__MESSAGES_HPP_

#include "tensorrt_common/depth.hpp"
#include "tensorrt_common/engine.hpp"

#include <flux_wrapper/flux_wrapper.hpp>
#include <opencv2/core.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/msg/point_field.hpp>

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace tensorrt_common
{

// A frame that a subscription with flux_wrapper::Device::Cuda kept on the device is read in
// place; one in host memory as before.
inline auto view_of(const flux_wrapper::View<sensor_msgs::msg::Image> & image) -> ImageView
{
  ImageView view{
    image.encoding(), image.data().data(), static_cast<int>(image.width()),
    static_cast<int>(image.height()), image.step()};
#ifdef FLUX_WRAPPER_CUDA
  if (image.on_device()) {
    view.data = static_cast<const std::uint8_t *>(image.device_ptr());
    view.on_device = true;
    view.stream = image.stream();
  }
#endif
  return view;
}

// What to ask a subscription for: device frames only for the GPU preprocessing.
inline auto image_subscription(bool gpu_preprocess) -> flux_wrapper::SubscriptionOptions
{
  flux_wrapper::SubscriptionOptions options;
  options.device = gpu_preprocess ? flux_wrapper::Device::Cuda : flux_wrapper::Device::Host;
  return options;
}

// The data is allocated before any string field. A flux frame appends its variable fields in
// the order they are set, and the fixed part of an Image (48 bytes) or a PointCloud2 (56 bytes)
// ends on an 8-byte boundary of the page-aligned frame: the data starts aligned for floats.

// The image of `loan`, to be written in place before it is published. Empty when the loan has no
// slot or the image does not fit the slot.
inline auto loan_image(
  flux_wrapper::Loan<sensor_msgs::msg::Image> & loan, const std_msgs::msg::Header & header,
  cv::Size size, int type, const std::string & encoding) -> cv::Mat
{
  if (!loan) {
    return {};
  }
  const std::size_t step = static_cast<std::size_t>(size.width) * CV_ELEM_SIZE(type);
  auto data = loan.alloc_data(step * static_cast<std::size_t>(size.height));
  if (data.empty()) {
    return {};
  }
  loan.set_header(header);
  loan.set_height(static_cast<std::uint32_t>(size.height));
  loan.set_width(static_cast<std::uint32_t>(size.width));
  loan.set_encoding(encoding);
  loan.set_is_bigendian(0);
  loan.set_step(static_cast<std::uint32_t>(step));
  return cv::Mat(size, type, data.data(), step);
}

// The point data of `loan` in `layout`, to be written by depth_to_cloud. Null when the loan has
// no slot or the cloud does not fit the slot.
inline auto loan_cloud(
  flux_wrapper::Loan<sensor_msgs::msg::PointCloud2> & loan, const std_msgs::msg::Header & header,
  const CloudLayout & layout) -> std::uint8_t *
{
  if (!loan) {
    return nullptr;
  }
  const std::uint32_t row_step = layout.point_step * static_cast<std::uint32_t>(layout.width);
  auto data = loan.alloc_data(static_cast<std::size_t>(row_step) * layout.height);
  if (data.empty()) {
    return nullptr;
  }
  std::vector<sensor_msgs::msg::PointField> fields;
  for (const auto * name : {"x", "y", "z", "rgb"}) {
    if (fields.size() == 3 && !layout.rgb) {
      break;
    }
    sensor_msgs::msg::PointField f;
    f.name = name;
    f.offset = static_cast<std::uint32_t>(4 * fields.size());
    f.datatype = sensor_msgs::msg::PointField::FLOAT32;
    f.count = 1;
    fields.push_back(f);
  }
  loan.set_header(header);
  loan.set_height(static_cast<std::uint32_t>(layout.height));
  loan.set_width(static_cast<std::uint32_t>(layout.width));
  loan.set_fields(fields);
  loan.set_is_bigendian(false);
  loan.set_point_step(layout.point_step);
  loan.set_row_step(row_step);
  loan.set_is_dense(false);
  return data.data();
}

}  // namespace tensorrt_common

#endif  // TENSORRT_COMMON__MESSAGES_HPP_

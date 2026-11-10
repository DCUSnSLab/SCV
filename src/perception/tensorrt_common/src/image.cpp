#include "tensorrt_common/image.hpp"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

namespace tensorrt_common
{

auto channel_layout(std::string_view encoding) -> ChannelLayout
{
  if (encoding == "rgb8") {
    return {0, 1, 2, 3};
  }
  if (encoding == "bgr8") {
    return {2, 1, 0, 3};
  }
  if (encoding == "rgba8") {
    return {0, 1, 2, 4};
  }
  if (encoding == "bgra8") {
    return {2, 1, 0, 4};
  }
  if (encoding == "mono8") {
    return {0, 0, 0, 1};
  }
  throw std::invalid_argument("unsupported image encoding " + std::string(encoding));
}

auto to_rgb(
  std::string_view encoding, const std::uint8_t * data, int width, int height,
  std::size_t step) -> cv::Mat
{
  auto * raw = const_cast<std::uint8_t *>(data);
  cv::Mat rgb;
  if (encoding == "rgb8") {
    cv::Mat(height, width, CV_8UC3, raw, step).copyTo(rgb);
  } else if (encoding == "bgr8") {
    cv::cvtColor(cv::Mat(height, width, CV_8UC3, raw, step), rgb, cv::COLOR_BGR2RGB);
  } else if (encoding == "rgba8") {
    cv::cvtColor(cv::Mat(height, width, CV_8UC4, raw, step), rgb, cv::COLOR_RGBA2RGB);
  } else if (encoding == "bgra8") {
    cv::cvtColor(cv::Mat(height, width, CV_8UC4, raw, step), rgb, cv::COLOR_BGRA2RGB);
  } else if (encoding == "mono8") {
    cv::cvtColor(cv::Mat(height, width, CV_8UC1, raw, step), rgb, cv::COLOR_GRAY2RGB);
  } else {
    throw std::invalid_argument("unsupported image encoding " + std::string(encoding));
  }
  return rgb;
}

auto fit_letterbox(int width, int height, int out_width, int out_height) -> Letterbox
{
  // Rounding follows ultralytics.data.augment.LetterBox (Python round is half to even, as
  // nearbyint).
  Letterbox box;
  box.scale =
    std::min(static_cast<double>(out_height) / height, static_cast<double>(out_width) / width);
  box.width = std::max(static_cast<int>(std::nearbyint(width * box.scale)), 1);
  box.height = std::max(static_cast<int>(std::nearbyint(height * box.scale)), 1);
  box.left = static_cast<int>(std::nearbyint((out_width - box.width) / 2.0 - 0.1));
  box.top = static_cast<int>(std::nearbyint((out_height - box.height) / 2.0 - 0.1));
  return box;
}

auto letterbox(const cv::Mat & rgb, int out_width, int out_height, cv::Mat & out) -> Letterbox
{
  const auto box = fit_letterbox(rgb.cols, rgb.rows, out_width, out_height);
  cv::Mat resized = rgb;
  if (rgb.cols != box.width || rgb.rows != box.height) {
    cv::resize(rgb, resized, cv::Size(box.width, box.height), 0, 0, cv::INTER_LINEAR);
  }
  cv::copyMakeBorder(
    resized, out, box.top, out_height - box.height - box.top, box.left,
    out_width - box.width - box.left, cv::BORDER_CONSTANT, cv::Scalar(114, 114, 114));
  return box;
}

void to_chw(
  const cv::Mat & rgb, const std::array<float, 3> & mean, const std::array<float, 3> & stddev,
  float * dst)
{
  const std::size_t plane = static_cast<std::size_t>(rgb.rows) * rgb.cols;
  for (int y = 0; y < rgb.rows; ++y) {
    const auto * row = rgb.ptr<cv::Vec3b>(y);
    for (int x = 0; x < rgb.cols; ++x) {
      const std::size_t i = static_cast<std::size_t>(y) * rgb.cols + x;
      for (int c = 0; c < 3; ++c) {
        dst[c * plane + i] = (row[x][c] / 255.0F - mean[c]) / stddev[c];
      }
    }
  }
}

void unletterbox(const cv::Mat & map, const Letterbox & box, cv::Mat & out, int interpolation)
{
  cv::resize(
    map(cv::Rect(box.left, box.top, box.width, box.height)), out, out.size(), 0, 0, interpolation);
}

void resize_align_corners(const cv::Mat & map, cv::Mat & out)
{
  const cv::Size size = out.size();
  // Written out: cv::remap rounds its coordinates to 1/32 pixel.
  const float sx = size.width > 1 ? (map.cols - 1.0F) / (size.width - 1) : 0.0F;
  const float sy = size.height > 1 ? (map.rows - 1.0F) / (size.height - 1) : 0.0F;
  std::vector<int> x0(size.width);
  std::vector<float> ax(size.width);
  for (int x = 0; x < size.width; ++x) {
    const float f = x * sx;
    x0[x] = std::min(static_cast<int>(f), map.cols - 1);
    ax[x] = f - x0[x];
  }
  for (int y = 0; y < size.height; ++y) {
    const float f = y * sy;
    const int y0 = std::min(static_cast<int>(f), map.rows - 1);
    const int y1 = std::min(y0 + 1, map.rows - 1);
    const float ay = f - y0;
    const auto * r0 = map.ptr<float>(y0);
    const auto * r1 = map.ptr<float>(y1);
    auto * o = out.ptr<float>(y);
    for (int x = 0; x < size.width; ++x) {
      const int x1 = std::min(x0[x] + 1, map.cols - 1);
      const float top = r0[x0[x]] + (r0[x1] - r0[x0[x]]) * ax[x];
      const float bottom = r1[x0[x]] + (r1[x1] - r1[x0[x]]) * ax[x];
      o[x] = top + (bottom - top) * ay;
    }
  }
}

}  // namespace tensorrt_common

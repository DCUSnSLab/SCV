#ifndef TENSORRT_COMMON__IMAGE_HPP_
#define TENSORRT_COMMON__IMAGE_HPP_

#include <opencv2/core.hpp>

#include <array>
#include <cstddef>
#include <cstdint>
#include <string_view>

namespace tensorrt_common
{

struct ChannelLayout
{
  int r = 0;
  int g = 0;
  int b = 0;
  int bytes = 0;
};

// Encodings: rgb8, bgr8, rgba8, bgra8, mono8.
auto channel_layout(std::string_view encoding) -> ChannelLayout;

auto to_rgb(
  std::string_view encoding, const std::uint8_t * data, int width, int height,
  std::size_t step) -> cv::Mat;

struct Letterbox
{
  double scale = 1.0;
  int left = 0;
  int top = 0;
  int width = 0;
  int height = 0;
};

// As ultralytics.data.augment.LetterBox, also its rounding; the padding is 114.
auto fit_letterbox(int width, int height, int out_width, int out_height) -> Letterbox;

auto letterbox(const cv::Mat & rgb, int out_width, int out_height, cv::Mat & out) -> Letterbox;

void to_chw(
  const cv::Mat & rgb, const std::array<float, 3> & mean, const std::array<float, 3> & stddev,
  float * dst);

// `out` has the source size; it may wrap memory that the caller owns, such as a loan.
void unletterbox(const cv::Mat & map, const Letterbox & box, cv::Mat & out, int interpolation);

// torch interpolate(align_corners=True), which cv::resize does not offer. `out` is CV_32FC1 of
// the target size.
void resize_align_corners(const cv::Mat & map, cv::Mat & out);

}  // namespace tensorrt_common

#endif  // TENSORRT_COMMON__IMAGE_HPP_

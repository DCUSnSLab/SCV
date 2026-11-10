#ifndef TENSORRT_COMMON__DEPTH_HPP_
#define TENSORRT_COMMON__DEPTH_HPP_

#include "tensorrt_common/engine.hpp"

#include <opencv2/core.hpp>

#include <cstddef>
#include <cstdint>

namespace tensorrt_common
{

struct Intrinsics
{
  double fx = 0.0;
  double fy = 0.0;
  double cx = 0.0;
  double cy = 0.0;
};

auto scale_intrinsics(const Intrinsics & k, cv::Size from, cv::Size to) -> Intrinsics;

// The sky depth of Depth Anything 3: a quantile of the ground (sky < threshold), at most `cap`.
auto sky_fill_value(
  const cv::Mat & depth, const cv::Mat & sky, float threshold, float quantile, float cap) -> float;

// float32 x, y, z at 0, 4, 8 and the PCL "rgb" at 12; no finite, positive depth gives NaN.
struct CloudLayout
{
  int width = 0;
  int height = 0;
  std::uint32_t point_step = 0;
  bool rgb = false;
};

auto cloud_layout(cv::Size depth, int downsample, bool rgb) -> CloudLayout;

// In the optical frame (z forward). `color` is null or the image of the size of `depth`.
void depth_to_cloud(
  const cv::Mat & depth, const Intrinsics & k, int downsample, const ImageView * color,
  const CloudLayout & layout, std::uint8_t * out);

}  // namespace tensorrt_common

#endif  // TENSORRT_COMMON__DEPTH_HPP_

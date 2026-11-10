#include "tensorrt_common/depth.hpp"

#include "tensorrt_common/image.hpp"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <vector>

namespace tensorrt_common
{

auto scale_intrinsics(const Intrinsics & k, cv::Size from, cv::Size to) -> Intrinsics
{
  const double sx = static_cast<double>(to.width) / from.width;
  const double sy = static_cast<double>(to.height) / from.height;
  // Pixel centers: x' + 0.5 = (x + 0.5) * s.
  return {k.fx * sx, k.fy * sy, (k.cx + 0.5) * sx - 0.5, (k.cy + 0.5) * sy - 0.5};
}

auto sky_fill_value(
  const cv::Mat & depth, const cv::Mat & sky, float threshold, float quantile, float cap) -> float
{
  std::vector<float> values;
  values.reserve(depth.total());
  for (int y = 0; y < depth.rows; ++y) {
    const auto * d = depth.ptr<float>(y);
    const auto * s = sky.ptr<float>(y);
    for (int x = 0; x < depth.cols; ++x) {
      if (s[x] < threshold && std::isfinite(d[x]) && d[x] > 0.0F) {
        values.push_back(d[x]);
      }
    }
  }
  if (values.empty()) {
    return cap;
  }
  const auto k = static_cast<std::size_t>(quantile * (values.size() - 1));
  std::nth_element(values.begin(), values.begin() + k, values.end());
  return std::min(values[k], cap);
}

auto cloud_layout(cv::Size depth, int downsample, bool rgb) -> CloudLayout
{
  if (downsample < 1) {
    throw std::invalid_argument("downsample must be 1 or more");
  }
  CloudLayout l;
  l.width = (depth.width + downsample - 1) / downsample;
  l.height = (depth.height + downsample - 1) / downsample;
  l.point_step = rgb ? 16 : 12;
  l.rgb = rgb;
  return l;
}

void depth_to_cloud(
  const cv::Mat & depth, const Intrinsics & k, int downsample, const ImageView * color,
  const CloudLayout & layout, std::uint8_t * out)
{
  const float nan = std::numeric_limits<float>::quiet_NaN();
  const ChannelLayout c = color ? channel_layout(color->encoding) : ChannelLayout{};
  std::uint8_t * p = out;
  for (int v = 0; v < depth.rows; v += downsample) {
    const auto * row = depth.ptr<float>(v);
    for (int u = 0; u < depth.cols; u += downsample, p += layout.point_step) {
      const float z = row[u];
      const bool valid = std::isfinite(z) && z > 0.0F;
      const float xyz[3] = {
        valid ? static_cast<float>((u - k.cx) * z / k.fx) : nan,
        valid ? static_cast<float>((v - k.cy) * z / k.fy) : nan, valid ? z : nan};
      std::memcpy(p, xyz, sizeof(xyz));
      if (layout.rgb) {
        const std::uint8_t * px = color->data + v * color->step + u * c.bytes;
        const std::uint32_t rgb =
          (std::uint32_t{px[c.r]} << 16) | (std::uint32_t{px[c.g]} << 8) | std::uint32_t{px[c.b]};
        std::memcpy(p + 12, &rgb, sizeof(rgb));
      }
    }
  }
}

}  // namespace tensorrt_common

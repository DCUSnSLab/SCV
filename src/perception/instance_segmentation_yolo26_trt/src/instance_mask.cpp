#include "instance_mask.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace instance_segmentation_yolo26_trt
{
namespace
{

struct Tap
{
  int i0 = 0;
  int i1 = 0;
  float w0 = 1.0F;
  float w1 = 0.0F;
};

// The samples and weights of cv::resize INTER_LINEAR from `from` to `to` samples, for the output
// samples [begin, end). Upscaling only: cv::resize switches to INTER_AREA at exactly half size.
std::vector<Tap> linear_taps(int from, int to, int begin, int end, int offset)
{
  const double scale = 1.0 / (static_cast<double>(to) / from);
  std::vector<Tap> taps;
  taps.reserve(static_cast<std::size_t>(end - begin));
  for (int d = begin; d < end; ++d) {
    float f = static_cast<float>((d + 0.5) * scale - 0.5);
    int s = static_cast<int>(std::floor(f));
    f -= static_cast<float>(s);
    if (s < 0) {
      s = 0;
      f = 0.0F;
    }
    if (s >= from - 1) {
      s = from - 1;
      f = 0.0F;
    }
    taps.push_back({s + offset, std::min(s + 1, from - 1) + offset, 1.0F - f, f});
  }
  return taps;
}

// Rows then columns of the taps, as cv::resize; `src` holds the samples from (row0, col0) on.
cv::Mat resample(
  const cv::Mat & src, int row0, int col0, const std::vector<Tap> & ty, const std::vector<Tap> & tx)
{
  const int rmin = ty.front().i0;
  const int rmax = ty.back().i1;
  cv::Mat h(rmax - rmin + 1, static_cast<int>(tx.size()), CV_32F);
  for (int r = rmin; r <= rmax; ++r) {
    const auto * s = src.ptr<float>(r - row0);
    auto * o = h.ptr<float>(r - rmin);
    for (std::size_t j = 0; j < tx.size(); ++j) {
      o[j] = s[tx[j].i0 - col0] * tx[j].w0 + s[tx[j].i1 - col0] * tx[j].w1;
    }
  }
  cv::Mat out(static_cast<int>(ty.size()), static_cast<int>(tx.size()), CV_32F);
  for (std::size_t i = 0; i < ty.size(); ++i) {
    const auto * a = h.ptr<float>(ty[i].i0 - rmin);
    const auto * b = h.ptr<float>(ty[i].i1 - rmin);
    auto * o = out.ptr<float>(static_cast<int>(i));
    for (std::size_t j = 0; j < tx.size(); ++j) {
      o[j] = a[j] * ty[i].w0 + b[j] * ty[i].w1;
    }
  }
  return out;
}

}  // namespace

void instance_mask(
  const std::vector<tensorrt_common::Detection> & detections, const float * rows, std::size_t cols,
  const Prototypes & protos, const tensorrt_common::Letterbox & box, cv::Size input, cv::Mat & mask)
{
  if (cols != 6 + static_cast<std::size_t>(protos.count)) {
    throw std::invalid_argument("a row needs one coefficient per prototype after six box columns");
  }
  mask.setTo(0);
  const cv::Size source = mask.size();
  // Lowest score first, so that a higher score overwrites it.
  for (std::size_t i = detections.size(); i-- > 0;) {
    const auto & d = detections[i];
    const int x1 = static_cast<int>(std::floor(d.x1));
    const int y1 = static_cast<int>(std::floor(d.y1));
    const int x2 = std::min(static_cast<int>(std::ceil(d.x2)), source.width);
    const int y2 = std::min(static_cast<int>(std::ceil(d.y2)), source.height);
    if (x2 <= x1 || y2 <= y1) {
      continue;
    }
    // Only the box goes through the two resizes: prototypes to input, letterbox to source.
    const auto sx = linear_taps(box.width, source.width, x1, x2, box.left);
    const auto sy = linear_taps(box.height, source.height, y1, y2, box.top);
    const int ix0 = sx.front().i0;
    const int iy0 = sy.front().i0;
    const auto px = linear_taps(protos.width, input.width, ix0, sx.back().i1 + 1, 0);
    const auto py = linear_taps(protos.height, input.height, iy0, sy.back().i1 + 1, 0);
    const int px0 = px.front().i0;
    const int py0 = py.front().i0;
    const cv::Rect rect(px0, py0, px.back().i1 - px0 + 1, py.back().i1 - py0 + 1);

    cv::Mat logits(rect.size(), CV_32F, cv::Scalar(0));
    const float * coefficients = rows + d.row * cols + 6;
    for (int c = 0; c < protos.count; ++c) {
      const cv::Mat proto(
        protos.height, protos.width, CV_32F,
        const_cast<float *>(protos.data) +
          static_cast<std::size_t>(c) * protos.height * protos.width);
      cv::scaleAdd(proto(rect), coefficients[c], logits, logits);
    }
    const cv::Mat at_input = resample(logits, py0, px0, py, px);
    const cv::Mat at_source = resample(at_input, iy0, ix0, sy, sx);
    // A logit above 0 is a sigmoid above 0.5, the Ultralytics mask threshold.
    mask(cv::Rect(x1, y1, x2 - x1, y2 - y1))
      .setTo(static_cast<std::uint16_t>(i + 1), at_source > 0.0F);
  }
}

}  // namespace instance_segmentation_yolo26_trt

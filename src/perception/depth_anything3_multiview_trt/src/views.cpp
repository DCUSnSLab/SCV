#include "views.hpp"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <vector>

namespace depth_anything3_multiview_trt
{

auto resize_for_network(const cv::Mat & rgb, cv::Size input) -> cv::Mat
{
  const bool shrink = input.width < rgb.cols;
  cv::Mat out;
  cv::resize(rgb, out, input, 0, 0, shrink ? cv::INTER_AREA : cv::INTER_CUBIC);
  return out;
}

auto poses_in_view0(const float * encodings, std::size_t n) -> std::vector<tf2::Transform>
{
  std::vector<tf2::Transform> camera_to_world;
  for (std::size_t i = 0; i < n; ++i) {
    const float * e = encodings + i * 9;
    tf2::Quaternion q(e[3], e[4], e[5], e[6]);
    q.normalize();
    camera_to_world.emplace_back(q, tf2::Vector3(e[0], e[1], e[2]));
  }
  const tf2::Transform world_to_view0 = camera_to_world.front().inverse();
  std::vector<tf2::Transform> poses;
  for (const auto & t : camera_to_world) {
    poses.push_back(world_to_view0 * t);
  }
  return poses;
}

auto intrinsics_of_view(const float * encodings, std::size_t i, cv::Size input)
  -> tensorrt_common::Intrinsics
{
  const float * e = encodings + i * 9;
  const double fov_h = e[7];
  const double fov_w = e[8];
  return {
    (input.width / 2.0) / std::max(std::tan(fov_w / 2.0), 1e-6),
    (input.height / 2.0) / std::max(std::tan(fov_h / 2.0), 1e-6), input.width / 2.0,
    input.height / 2.0};
}

ViewSet::ViewSet(std::size_t n, std::int64_t max_skew_ns) : slots_(n), max_skew_ns_(max_skew_ns)
{
}

void ViewSet::put(std::size_t view, std::int64_t stamp_ns, cv::Mat rgb)
{
  slots_.at(view) = Slot{stamp_ns, std::move(rgb)};
}

auto ViewSet::complete() const -> bool
{
  if (!slots_.front()) {
    return false;
  }
  for (const auto & s : slots_) {
    if (!s || std::llabs(s->stamp_ns - slots_.front()->stamp_ns) > max_skew_ns_) {
      return false;
    }
  }
  return true;
}

auto ViewSet::image(std::size_t view) const -> const cv::Mat &
{
  return slots_.at(view)->rgb;
}

}  // namespace depth_anything3_multiview_trt

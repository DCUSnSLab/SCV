#ifndef VIEWS_HPP_
#define VIEWS_HPP_

#include <opencv2/core.hpp>
#include <tensorrt_common/depth.hpp>
#include <tf2/LinearMath/Transform.hpp>

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

namespace depth_anything3_multiview_trt
{

inline constexpr std::array<float, 3> kMean = {0.485F, 0.456F, 0.406F};
inline constexpr std::array<float, 3> kStd = {0.229F, 0.224F, 0.225F};

auto resize_for_network(const cv::Mat & rgb, cv::Size input) -> cv::Mat;

// Encodings of 9: camera-to-world translation, quaternion xyzw, field of view (h, w).
auto poses_in_view0(const float * encodings, std::size_t n) -> std::vector<tf2::Transform>;

// As pose_encoding_to_extri_intri of Depth Anything 3, in pixels of `input`.
auto intrinsics_of_view(const float * encodings, std::size_t i, cv::Size input)
  -> tensorrt_common::Intrinsics;

// Complete when every view has an image within max_skew_ns of the stamp of view 0.
class ViewSet
{
public:
  ViewSet(std::size_t n, std::int64_t max_skew_ns);

  void put(std::size_t view, std::int64_t stamp_ns, cv::Mat rgb);
  [[nodiscard]] auto complete() const -> bool;
  [[nodiscard]] auto image(std::size_t view) const -> const cv::Mat &;

private:
  struct Slot
  {
    std::int64_t stamp_ns = 0;
    cv::Mat rgb;
  };
  std::vector<std::optional<Slot>> slots_;
  std::int64_t max_skew_ns_;
};

}  // namespace depth_anything3_multiview_trt

#endif  // VIEWS_HPP_

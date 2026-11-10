#ifndef DEPTH_MAP_HPP_
#define DEPTH_MAP_HPP_

#include <opencv2/core.hpp>

#include <array>

namespace depth_anything3_mono_trt
{

inline constexpr std::array<float, 3> kMean = {0.485F, 0.456F, 0.406F};
inline constexpr std::array<float, 3> kStd = {0.229F, 0.224F, 0.225F};

auto resize_for_network(const cv::Mat & rgb, cv::Size input) -> cv::Mat;

// focal * output / 300 (Depth Anything 3 README), the focal length at network size; fx, fy at
// `source`.
void to_meters(cv::Mat & depth, double fx, double fy, cv::Size source);

void mark_sky(cv::Mat & depth, const cv::Mat & sky, float threshold, float value);

}  // namespace depth_anything3_mono_trt

#endif  // DEPTH_MAP_HPP_

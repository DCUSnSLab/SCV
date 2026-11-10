#include "depth_map.hpp"

#include <opencv2/imgproc.hpp>

namespace depth_anything3_mono_trt
{

auto resize_for_network(const cv::Mat & rgb, cv::Size input) -> cv::Mat
{
  const bool shrink = input.width < rgb.cols;
  cv::Mat out;
  cv::resize(rgb, out, input, 0, 0, shrink ? cv::INTER_AREA : cv::INTER_CUBIC);
  return out;
}

void to_meters(cv::Mat & depth, double fx, double fy, cv::Size source)
{
  const double focal = (fx * depth.cols / source.width + fy * depth.rows / source.height) / 2.0;
  depth *= focal / 300.0;
}

void mark_sky(cv::Mat & depth, const cv::Mat & sky, float threshold, float value)
{
  depth.setTo(value, sky >= threshold);
}

}  // namespace depth_anything3_mono_trt

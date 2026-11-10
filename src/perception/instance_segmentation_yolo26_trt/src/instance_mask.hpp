#ifndef INSTANCE_MASK_HPP_
#define INSTANCE_MASK_HPP_

#include <opencv2/core.hpp>
#include <tensorrt_common/image.hpp>
#include <tensorrt_common/yolo.hpp>

#include <cstddef>
#include <vector>

namespace instance_segmentation_yolo26_trt
{

// The prototype output of a YOLO26 segment model: `count` maps of height x width.
struct Prototypes
{
  const float * data = nullptr;
  int count = 0;
  int height = 0;
  int width = 0;
};

// Writes `mask`, CV_16UC1 of the source size: detection i is i + 1 inside its box, 0 is
// background. `rows` is the detection output with `cols` floats per row; the mask coefficients
// follow the six box columns. Where instances overlap, the one with the higher score wins.
void instance_mask(
  const std::vector<tensorrt_common::Detection> & detections, const float * rows, std::size_t cols,
  const Prototypes & protos, const tensorrt_common::Letterbox & box, cv::Size input,
  cv::Mat & mask);

}  // namespace instance_segmentation_yolo26_trt

#endif  // INSTANCE_MASK_HPP_

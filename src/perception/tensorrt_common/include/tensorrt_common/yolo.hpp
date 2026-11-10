#ifndef TENSORRT_COMMON__YOLO_HPP_
#define TENSORRT_COMMON__YOLO_HPP_

#include "tensorrt_common/engine.hpp"
#include "tensorrt_common/image.hpp"

#include <cstddef>
#include <string>
#include <vector>

namespace tensorrt_common
{

struct Detection
{
  float x1 = 0.0F;
  float y1 = 0.0F;
  float x2 = 0.0F;
  float y2 = 0.0F;
  float score = 0.0F;
  int class_id = 0;
  // The output row, for the mask coefficients after the class column.
  std::size_t row = 0;
};

// Ultralytics stretches for depth (DepthPredictor.scale_fill) and letterboxes the other tasks.
enum class YoloFit { Letterbox, Stretch };

// gpu false: cv::resize on the CPU, the reference that the kernel is tested against.
auto upload_yolo_input(
  Engine & engine, const std::string & name, const ImageView & image, YoloFit fit, bool gpu,
  std::vector<float> & cpu_chw) -> Letterbox;

// Export with nms=False: rows of [x1, y1, x2, y2, score, class, extra...] in input pixels.
auto decode_end2end(
  const float * out, std::size_t rows, std::size_t cols, const Letterbox & box, int width,
  int height, float score_threshold) -> std::vector<Detection>;

}  // namespace tensorrt_common

#endif  // TENSORRT_COMMON__YOLO_HPP_

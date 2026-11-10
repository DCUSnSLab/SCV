#include "tensorrt_common/yolo.hpp"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace tensorrt_common
{

auto upload_yolo_input(
  Engine & engine, const std::string & name, const ImageView & image, YoloFit fit, bool gpu,
  std::vector<float> & cpu_chw) -> Letterbox
{
  const auto & shape = engine.info(name).shape;
  const int in_h = static_cast<int>(shape.at(2));
  const int in_w = static_cast<int>(shape.at(3));
  Letterbox box{1.0, 0, 0, in_w, in_h};
  if (fit == YoloFit::Letterbox) {
    box = fit_letterbox(image.width, image.height, in_w, in_h);
  }
  if (gpu) {
    engine.upload_image(
      name, 0, image, {box.left, box.top, box.width, box.height, 114.0F}, Resize::Linear,
      {0.0F, 0.0F, 0.0F}, {1.0F, 1.0F, 1.0F});
    return box;
  }
  const cv::Mat rgb = to_rgb(image.encoding, image.data, image.width, image.height, image.step);
  cv::Mat resized;
  if (fit == YoloFit::Letterbox) {
    letterbox(rgb, in_w, in_h, resized);
  } else {
    cv::resize(rgb, resized, cv::Size(in_w, in_h), 0, 0, cv::INTER_LINEAR);
  }
  cpu_chw.resize(engine.info(name).elements);
  to_chw(resized, {0.0F, 0.0F, 0.0F}, {1.0F, 1.0F, 1.0F}, cpu_chw.data());
  engine.upload_float(name, cpu_chw.data());
  return box;
}

auto decode_end2end(
  const float * out, std::size_t rows, std::size_t cols, const Letterbox & box, int width,
  int height, float score_threshold) -> std::vector<Detection>
{
  if (cols < 6) {
    throw std::invalid_argument("a YOLO26 end-to-end row has at least 6 columns");
  }
  const auto to_x = [&](float v) {
    return std::clamp(
      static_cast<float>((v - box.left) / box.scale), 0.0F, static_cast<float>(width));
  };
  const auto to_y = [&](float v) {
    return std::clamp(
      static_cast<float>((v - box.top) / box.scale), 0.0F, static_cast<float>(height));
  };
  std::vector<Detection> detections;
  for (std::size_t r = 0; r < rows; ++r) {
    const float * row = out + r * cols;
    if (row[4] < score_threshold) {
      continue;
    }
    Detection d;
    d.x1 = to_x(row[0]);
    d.y1 = to_y(row[1]);
    d.x2 = to_x(row[2]);
    d.y2 = to_y(row[3]);
    d.score = row[4];
    d.class_id = static_cast<int>(row[5]);
    d.row = r;
    detections.push_back(d);
  }
  return detections;
}

}  // namespace tensorrt_common

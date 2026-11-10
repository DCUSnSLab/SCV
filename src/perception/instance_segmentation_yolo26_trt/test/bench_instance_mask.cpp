// Not a test: prints the time of instance_mask for one frame. Pin it to a core with taskset.

#include "instance_mask.hpp"

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <vector>

int main()
{
  const cv::Size input(640, 640);
  const cv::Size source(1280, 720);
  const auto box = tensorrt_common::fit_letterbox(source.width, source.height, 640, 640);
  cv::Mat proto(32, 160 * 160, CV_32F);
  cv::randn(proto, 0.0, 1.0);
  const instance_segmentation_yolo26_trt::Prototypes protos{proto.ptr<float>(), 32, 160, 160};
  for (const int n : {1, 5, 20}) {
    std::vector<float> rows(static_cast<std::size_t>(n) * 38);
    cv::randn(cv::Mat(1, static_cast<int>(rows.size()), CV_32F, rows.data()), 0.0, 0.2);
    std::vector<tensorrt_common::Detection> detections;
    for (int i = 0; i < n; ++i) {
      tensorrt_common::Detection d;
      d.x1 = static_cast<float>(60 * i % 1000);
      d.y1 = static_cast<float>(25 * i % 400);
      d.x2 = d.x1 + 200.0F;
      d.y2 = d.y1 + 250.0F;
      d.score = 0.9F - 0.01F * static_cast<float>(i);
      d.row = static_cast<std::size_t>(i);
      detections.push_back(d);
    }
    std::vector<double> ms;
    for (int r = 0; r < 100; ++r) {
      const auto t0 = std::chrono::steady_clock::now();
      cv::Mat mask(source, CV_16UC1);
      instance_segmentation_yolo26_trt::instance_mask(
        detections, rows.data(), 38, protos, box, input, mask);
      ms.push_back(
        std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count());
    }
    std::sort(ms.begin(), ms.end());
    std::printf(
      "%2d detections of 200x250: p50 %7.2f ms  p99 %7.2f ms\n", n, ms[ms.size() / 2],
      ms[ms.size() * 99 / 100]);
  }
  return 0;
}

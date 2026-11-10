// Not a test: prints the time of the CPU and the GPU preprocessing of one frame. Pin it to a core
// with taskset.
//   bench_preprocess <width> <height>

#include "tensorrt_common/engine.hpp"
#include "tensorrt_common/image.hpp"

#include <opencv2/imgproc.hpp>

#include <cuda_runtime_api.h>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>
#include <vector>

namespace
{

void report(const char * name, const std::function<void()> & run)
{
  std::vector<double> ms;
  for (int i = 0; i < 300; ++i) {
    const auto t0 = std::chrono::steady_clock::now();
    run();
    ms.push_back(
      std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count());
  }
  std::sort(ms.begin(), ms.end());
  std::printf(
    "%-36s p50 %6.2f ms  p99 %6.2f ms\n", name, ms[ms.size() / 2], ms[ms.size() * 99 / 100]);
}

}  // namespace

int main(int argc, char ** argv)
{
  const int w = argc > 2 ? std::atoi(argv[1]) : 1280;
  const int h = argc > 2 ? std::atoi(argv[2]) : 720;
  cv::Mat bgr(h, w, CV_8UC3);
  cv::randu(bgr, 0, 255);
  std::vector<float> yolo(3 * 640 * 640);
  std::vector<float> da3(3 * 280 * 504);
  report("yolo letterbox 640 + chw", [&] {
    cv::Mat boxed;
    const auto rgb = tensorrt_common::to_rgb("bgr8", bgr.data, w, h, bgr.step);
    tensorrt_common::letterbox(rgb, 640, 640, boxed);
    tensorrt_common::to_chw(boxed, {0, 0, 0}, {1, 1, 1}, yolo.data());
  });
  report("da3 area 504x280 + chw", [&] {
    cv::Mat small;
    const auto rgb = tensorrt_common::to_rgb("bgr8", bgr.data, w, h, bgr.step);
    cv::resize(rgb, small, cv::Size(504, 280), 0, 0, cv::INTER_AREA);
    tensorrt_common::to_chw(small, {0.485F, 0.456F, 0.406F}, {0.229F, 0.224F, 0.225F}, da3.data());
  });
  tensorrt_common::EngineOptions o;
  o.workspace_bytes = 64 << 20;
  o.onnx_path = std::string(TEST_DATA_DIR) + "/identity_640x640.onnx";
  o.engine_path = "/tmp/bench_identity_640x640.engine";
  tensorrt_common::Engine yolo_engine(o);
  o.onnx_path = std::string(TEST_DATA_DIR) + "/identity_280x504.onnx";
  o.engine_path = "/tmp/bench_identity_280x504.engine";
  tensorrt_common::Engine da3_engine(o);
  const tensorrt_common::ImageView view{"bgr8", bgr.data, w, h, bgr.step};
  const auto box = tensorrt_common::fit_letterbox(w, h, 640, 640);
  // Synchronized, so that the time includes the copy of the raw image and the kernel.
  report("gpu yolo letterbox 640", [&] {
    yolo_engine.upload_image(
      "image", 0, view, {box.left, box.top, box.width, box.height, 114.0F},
      tensorrt_common::Resize::Linear, {0, 0, 0}, {1, 1, 1});
    cudaDeviceSynchronize();
  });
  report("gpu da3 area 504x280", [&] {
    da3_engine.upload_image(
      "image", 0, view, {0, 0, 504, 280, 0.0F}, tensorrt_common::Resize::Area,
      {0.485F, 0.456F, 0.406F}, {0.229F, 0.224F, 0.225F});
    cudaDeviceSynchronize();
  });
  // A camera frame already in GPU memory: no copy of the raw image.
  void * device = nullptr;
  std::size_t pitch = 0;
  cudaMallocPitch(&device, &pitch, static_cast<std::size_t>(w) * 3, h);
  cudaMemcpy2D(
    device, pitch, bgr.data, bgr.step, static_cast<std::size_t>(w) * 3, h, cudaMemcpyHostToDevice);
  const tensorrt_common::ImageView on_device{
    "bgr8", static_cast<const std::uint8_t *>(device), w, h, pitch, true, nullptr};
  report("gpu yolo letterbox 640, gpu frame", [&] {
    yolo_engine.upload_image(
      "image", 0, on_device, {box.left, box.top, box.width, box.height, 114.0F},
      tensorrt_common::Resize::Linear, {0, 0, 0}, {1, 1, 1});
    cudaDeviceSynchronize();
  });
  report("gpu da3 area 504x280, gpu frame", [&] {
    da3_engine.upload_image(
      "image", 0, on_device, {0, 0, 504, 280, 0.0F}, tensorrt_common::Resize::Area,
      {0.485F, 0.456F, 0.406F}, {0.229F, 0.224F, 0.225F});
    cudaDeviceSynchronize();
  });
  cudaFree(device);
  report("cpu chw upload 640 (for scale)", [&] {
    yolo_engine.upload_float("image", yolo.data());
    cudaDeviceSynchronize();
  });
  return 0;
}

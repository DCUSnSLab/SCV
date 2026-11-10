#include "tensorrt_common/engine.hpp"
#include "tensorrt_common/image.hpp"

#include <opencv2/imgproc.hpp>

#include <cuda_runtime_api.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

using tensorrt_common::Engine;
using tensorrt_common::EngineOptions;
using tensorrt_common::ImageView;
using tensorrt_common::Placement;
using tensorrt_common::Resize;

namespace
{

// An engine that copies its input to its output, so that the kernel output can be read back.
Engine identity(int h, int w)
{
  const std::string name = "identity_" + std::to_string(h) + "x" + std::to_string(w);
  EngineOptions o;
  o.onnx_path = std::string(TEST_DATA_DIR) + "/" + name + ".onnx";
  o.engine_path = testing::TempDir() + name + ".engine";
  o.workspace_bytes = 64 << 20;
  return Engine(o);
}

cv::Mat random_bgr(int w, int h)
{
  cv::Mat bgr(h, w, CV_8UC3);
  cv::randu(bgr, 0, 256);
  return bgr;
}

ImageView view(const cv::Mat & bgr)
{
  return {"bgr8", bgr.data, bgr.cols, bgr.rows, bgr.step};
}

struct Difference
{
  float max_levels = 0.0F;
  double off_by_one = 0.0;
};

// In uint8 levels; the kernel computes in float where cv::resize uses fixed point.
Difference compare(const std::vector<float> & gpu, const std::vector<float> & cpu)
{
  Difference d;
  std::size_t off = 0;
  for (std::size_t i = 0; i < gpu.size(); ++i) {
    const float levels = std::abs(gpu[i] - cpu[i]) * 255.0F;
    d.max_levels = std::max(d.max_levels, levels);
    off += levels > 0.5F;
  }
  d.off_by_one = static_cast<double>(off) / gpu.size();
  std::printf("max %.2f levels, %.3f%% of values off by one\n", d.max_levels, 100 * d.off_by_one);
  return d;
}

std::vector<float> run(Engine & e, const cv::Mat & bgr, const Placement & place, Resize resize)
{
  e.upload_image("image", 0, view(bgr), place, resize, {0, 0, 0}, {1, 1, 1});
  e.infer();
  std::vector<float> out(e.info("copy").elements);
  e.download_float("copy", out.data());
  return out;
}

}  // namespace

void expect_letterbox_matches(int width, int height)
{
  auto e = identity(640, 640);
  const cv::Mat bgr = random_bgr(width, height);
  cv::Mat boxed;
  const auto box = tensorrt_common::letterbox(
    tensorrt_common::to_rgb("bgr8", bgr.data, bgr.cols, bgr.rows, bgr.step), 640, 640, boxed);
  std::vector<float> cpu(3 * 640 * 640);
  tensorrt_common::to_chw(boxed, {0, 0, 0}, {1, 1, 1}, cpu.data());
  const auto gpu = run(e, bgr, {box.left, box.top, box.width, box.height, 114.0F}, Resize::Linear);
  EXPECT_EQ(compare(gpu, cpu).max_levels, 0.0F);
}

// 1280 x 720 halves exactly, which cv::resize computes as INTER_AREA.
TEST(Preprocess, LetterboxOfAHalvingMatchesTheCpuPath)
{
  expect_letterbox_matches(1280, 720);
}

TEST(Preprocess, LetterboxMatchesTheCpuPath)
{
  expect_letterbox_matches(810, 1080);
}

TEST(Preprocess, AreaMatchesCvResize)
{
  auto e = identity(280, 504);
  const cv::Mat bgr = random_bgr(1280, 720);
  cv::Mat small;
  cv::resize(
    tensorrt_common::to_rgb("bgr8", bgr.data, bgr.cols, bgr.rows, bgr.step), small,
    cv::Size(504, 280), 0, 0, cv::INTER_AREA);
  std::vector<float> cpu(3 * 280 * 504);
  tensorrt_common::to_chw(small, {0, 0, 0}, {1, 1, 1}, cpu.data());
  const auto d = compare(run(e, bgr, {0, 0, 504, 280, 0.0F}, Resize::Area), cpu);
  // Float sums in another order than cv::resize: measured 0.06 % off by one at ties.
  EXPECT_LE(d.max_levels, 1.01F);
  EXPECT_LT(d.off_by_one, 0.002);
}

TEST(Preprocess, CubicMatchesCvResize)
{
  auto e = identity(280, 504);
  const cv::Mat bgr = random_bgr(320, 180);
  cv::Mat large;
  cv::resize(
    tensorrt_common::to_rgb("bgr8", bgr.data, bgr.cols, bgr.rows, bgr.step), large,
    cv::Size(504, 280), 0, 0, cv::INTER_CUBIC);
  std::vector<float> cpu(3 * 280 * 504);
  tensorrt_common::to_chw(large, {0, 0, 0}, {1, 1, 1}, cpu.data());
  const auto d = compare(run(e, bgr, {0, 0, 504, 280, 0.0F}, Resize::Cubic), cpu);
  // The column sum is fused multiply-add, as on most SIMD targets: a few ties round apart.
  EXPECT_LE(d.max_levels, 1.01F);
  EXPECT_LT(d.off_by_one, 0.0002);
}

TEST(Preprocess, NormalizationAndChannelOrder)
{
  auto e = identity(280, 504);
  const cv::Mat bgr(280, 504, CV_8UC3, cv::Scalar(0, 128, 255));
  e.upload_image(
    "image", 0, view(bgr), {0, 0, 504, 280, 0.0F}, Resize::Linear, {0.5F, 0.5F, 0.5F},
    {0.25F, 0.5F, 1.0F});
  e.infer();
  std::vector<float> out(e.info("copy").elements);
  e.download_float("copy", out.data());
  const std::size_t plane = 280 * 504;
  EXPECT_NEAR(out[0], (1.0F - 0.5F) / 0.25F, 1e-5);  // R plane holds the 255 of bgr8 byte 2
  EXPECT_NEAR(out[plane], (128 / 255.0F - 0.5F) / 0.5F, 1e-5);
  EXPECT_NEAR(out[2 * plane], -0.5F, 1e-5);
}

TEST(Preprocess, DeviceImageWithRowPaddingMatchesTheHostPath)
{
  // A camera's GPU image is pitched: each row is padded past width * pixel size.
  auto e = identity(640, 640);
  const cv::Mat bgr = random_bgr(810, 1080);
  void * device = nullptr;
  std::size_t pitch = 0;
  ASSERT_EQ(cudaMallocPitch(&device, &pitch, bgr.cols * 3, bgr.rows), cudaSuccess);
  ASSERT_GT(pitch, static_cast<std::size_t>(bgr.cols * 3));
  ASSERT_EQ(
    cudaMemcpy2D(device, pitch, bgr.data, bgr.step, bgr.cols * 3, bgr.rows, cudaMemcpyHostToDevice),
    cudaSuccess);
  cudaStream_t stream = nullptr;
  ASSERT_EQ(cudaStreamCreate(&stream), cudaSuccess);
  const auto box = tensorrt_common::fit_letterbox(bgr.cols, bgr.rows, 640, 640);
  const Placement place{box.left, box.top, box.width, box.height, 114.0F};
  const ImageView on_device{
    "bgr8", static_cast<const std::uint8_t *>(device), bgr.cols, bgr.rows, pitch, true, stream};

  e.upload_image("image", 0, on_device, place, Resize::Linear, {0, 0, 0}, {1, 1, 1});
  e.infer();
  std::vector<float> gpu(e.info("copy").elements);
  e.download_float("copy", gpu.data());

  std::vector<std::uint8_t> buffer;
  const auto back = tensorrt_common::host_copy(on_device, buffer);
  EXPECT_EQ(
    cv::countNonZero(cv::Mat(bgr.rows, bgr.cols * 3, CV_8UC1, buffer.data()) != bgr.reshape(1)), 0);
  EXPECT_FALSE(back.on_device);
  EXPECT_EQ(compare(gpu, run(e, bgr, place, Resize::Linear)).max_levels, 0.0F);
  cudaStreamDestroy(stream);
  cudaFree(device);
}

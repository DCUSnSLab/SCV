// Not a test: prints the time of the CPU depth postprocessing of one frame. Pin it to a core
// with taskset.

#include "tensorrt_common/depth.hpp"
#include "tensorrt_common/image.hpp"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <limits>
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
    "%-40s p50 %6.2f ms  p99 %6.2f ms\n", name, ms[ms.size() / 2], ms[ms.size() * 99 / 100]);
}

}  // namespace

int main()
{
  const cv::Size input(504, 280);
  const cv::Size source(1280, 720);
  cv::Mat depth(input, CV_32FC1);
  cv::Mat sky(input, CV_32FC1);
  cv::randu(depth, 1.0F, 50.0F);
  cv::randu(sky, 0.0F, 0.4F);
  cv::Mat bgr(source, CV_8UC3);
  cv::randu(bgr, 0, 255);
  const tensorrt_common::ImageView color{"bgr8", bgr.data, source.width, source.height, bgr.step};
  cv::Mat out;
  report("da3 resize depth + sky, mark sky (inf)", [&] {
    cv::Mat s;
    cv::resize(depth, out, source, 0, 0, cv::INTER_LINEAR);
    cv::resize(sky, s, source, 0, 0, cv::INTER_LINEAR);
    out.setTo(std::numeric_limits<float>::infinity(), s >= 0.3F);
  });
  report("da3 sky fill value (quantile)", [&] {
    tensorrt_common::sky_fill_value(depth, sky, 0.3F, 0.99F, 200.0F);
  });
  report("yolo align-corners resize 768 -> 1280", [&] {
    cv::Mat m(768, 768, CV_32FC1, cv::Scalar(3.0F));
    out.create(source, CV_32FC1);
    tensorrt_common::resize_align_corners(m, out);
  });
  const tensorrt_common::Intrinsics k{700, 700, 639.5, 359.5};
  for (const int ds : {1, 2}) {
    const auto layout = tensorrt_common::cloud_layout(source, ds, true);
    std::vector<std::uint8_t> cloud(layout.point_step * layout.width * layout.height);
    report(ds == 1 ? "cloud with color, downsample 1" : "cloud with color, downsample 2", [&] {
      tensorrt_common::depth_to_cloud(out, k, ds, &color, layout, cloud.data());
    });
  }
  return 0;
}

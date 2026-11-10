#include "instance_mask.hpp"

#include <opencv2/imgproc.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

using instance_segmentation_yolo26_trt::instance_mask;
using instance_segmentation_yolo26_trt::Prototypes;
using tensorrt_common::Detection;
using tensorrt_common::Letterbox;

namespace
{

Detection box(float x1, float y1, float x2, float y2, float score, std::size_t row)
{
  Detection d;
  d.x1 = x1;
  d.y1 = y1;
  d.x2 = x2;
  d.y2 = y2;
  d.score = score;
  d.row = row;
  return d;
}

Letterbox identity()
{
  Letterbox b;
  b.width = 8;
  b.height = 8;
  return b;
}

cv::Mat mask_of(
  const std::vector<Detection> & detections, const std::vector<float> & rows, std::size_t cols,
  const Prototypes & protos, const Letterbox & b, cv::Size input, cv::Size source)
{
  cv::Mat mask(source, CV_16UC1, cv::Scalar(7));
  instance_mask(detections, rows.data(), cols, protos, b, input, mask);
  return mask;
}

// The whole-image method: every logit map resized to the input, then to the source.
cv::Mat reference(
  const std::vector<Detection> & detections, const std::vector<float> & rows, std::size_t cols,
  const Prototypes & protos, const Letterbox & b, cv::Size input, cv::Size source)
{
  cv::Mat mask(source, CV_16UC1, cv::Scalar(0));
  const cv::Mat proto(
    protos.count, protos.height * protos.width, CV_32F, const_cast<float *>(protos.data));
  for (std::size_t i = detections.size(); i-- > 0;) {
    const auto & d = detections[i];
    const cv::Mat coefficients(
      1, protos.count, CV_32F, const_cast<float *>(rows.data() + d.row * cols + 6));
    const cv::Mat product = coefficients * proto;
    cv::Mat at_input;
    cv::resize(product.reshape(1, protos.height), at_input, input, 0, 0, cv::INTER_LINEAR);
    cv::Mat at_source(source, CV_32F);
    tensorrt_common::unletterbox(at_input, b, at_source, cv::INTER_LINEAR);
    const int x1 = static_cast<int>(std::floor(d.x1));
    const int y1 = static_cast<int>(std::floor(d.y1));
    const int x2 = std::min(static_cast<int>(std::ceil(d.x2)), source.width);
    const int y2 = std::min(static_cast<int>(std::ceil(d.y2)), source.height);
    const cv::Rect roi(x1, y1, x2 - x1, y2 - y1);
    mask(roi).setTo(static_cast<std::uint16_t>(i + 1), at_source(roi) > 0.0F);
  }
  return mask;
}

}  // namespace

TEST(InstanceMask, NegativeLogitsStayBackground)
{
  const std::vector<float> proto(4 * 4, 1.0F);
  const Prototypes protos{proto.data(), 1, 4, 4};
  const std::vector<float> rows = {0, 0, 8, 8, 0.9F, 0, -1.0F};
  const auto mask =
    mask_of({box(0, 0, 8, 8, 0.9F, 0)}, rows, 7, protos, identity(), {8, 8}, {8, 8});
  EXPECT_EQ(cv::countNonZero(mask), 0);
}

TEST(InstanceMask, MaskStaysInsideTheBox)
{
  const std::vector<float> proto(4 * 4, 1.0F);
  const Prototypes protos{proto.data(), 1, 4, 4};
  const std::vector<float> rows = {0, 0, 4, 4, 0.9F, 0, 1.0F};
  const auto mask =
    mask_of({box(0, 0, 4, 4, 0.9F, 0)}, rows, 7, protos, identity(), {8, 8}, {8, 8});
  EXPECT_EQ(cv::countNonZero(mask), 16);
  EXPECT_EQ(mask.at<std::uint16_t>(3, 3), 1);
  EXPECT_EQ(mask.at<std::uint16_t>(4, 4), 0);
}

TEST(InstanceMask, HigherScoreWinsWhereInstancesOverlap)
{
  const std::vector<float> proto(4 * 4, 1.0F);
  const Prototypes protos{proto.data(), 1, 4, 4};
  const std::vector<float> rows = {0, 0, 6, 6, 0.9F, 0, 1.0F,  //
                                   2, 2, 8, 8, 0.5F, 0, 1.0F};
  const auto mask = mask_of(
    {box(0, 0, 6, 6, 0.9F, 0), box(2, 2, 8, 8, 0.5F, 1)}, rows, 7, protos, identity(), {8, 8},
    {8, 8});
  EXPECT_EQ(mask.at<std::uint16_t>(3, 3), 1);
  EXPECT_EQ(mask.at<std::uint16_t>(7, 7), 2);
}

TEST(InstanceMask, WrongColumnCountThrows)
{
  const std::vector<float> proto(4, 1.0F);
  const Prototypes protos{proto.data(), 2, 1, 2};
  const std::vector<float> rows(7);
  EXPECT_THROW(mask_of({}, rows, 7, protos, identity(), {8, 8}, {8, 8}), std::invalid_argument);
}

TEST(InstanceMask, MatchesTheWholeImageMethod)
{
  // 1280x720 and 1920x1080 cameras, and a 640x480 one that is padded left and right.
  for (const cv::Size source : {cv::Size(1280, 720), cv::Size(1920, 1080), cv::Size(640, 480)}) {
    const cv::Size input(640, 640);
    const auto b = tensorrt_common::fit_letterbox(source.width, source.height, 640, 640);
    cv::Mat proto(32, 160 * 160, CV_32F);
    cv::randn(proto, 0.0, 1.0);
    const Prototypes protos{proto.ptr<float>(), 32, 160, 160};
    std::vector<float> rows(8 * 38);
    cv::randn(cv::Mat(1, static_cast<int>(rows.size()), CV_32F, rows.data()), 0.0, 0.3);
    std::vector<Detection> detections;
    const float sw = static_cast<float>(source.width);
    const float sh = static_cast<float>(source.height);
    for (std::size_t i = 0; i < 8; ++i) {
      const float f = static_cast<float>(i) / 8.0F;
      // Boxes at the edges too, where the taps are clamped.
      detections.push_back(box(
        f * sw * 0.9F - 3.0F, f * sh * 0.5F, f * sw * 0.9F + 0.3F * sw, sh - f * 7.0F,
        0.9F - f * 0.1F, i));
      detections.back().x1 = std::max(detections.back().x1, 0.0F);
      detections.back().x2 = std::min(detections.back().x2, sw);
    }
    const auto got = mask_of(detections, rows, 38, protos, b, input, source);
    const auto want = reference(detections, rows, 38, protos, b, input, source);
    // The sums run in another order, so a logit within rounding of 0 may flip.
    EXPECT_LE(cv::countNonZero(got != want), static_cast<int>(source.area() / 100000)) << source;
  }
}

#include "tensorrt_common/image.hpp"

#include <opencv2/imgproc.hpp>

#include <gtest/gtest.h>

#include <array>
#include <cstdint>
#include <vector>

using tensorrt_common::letterbox;
using tensorrt_common::resize_align_corners;
using tensorrt_common::to_chw;
using tensorrt_common::to_rgb;
using tensorrt_common::unletterbox;

TEST(Image, BgrBecomesRgb)
{
  const std::vector<std::uint8_t> bgr = {1, 2, 3, 4, 5, 6};
  const cv::Mat rgb = to_rgb("bgr8", bgr.data(), 2, 1, 6);
  EXPECT_EQ(rgb.at<cv::Vec3b>(0, 0), cv::Vec3b(3, 2, 1));
  EXPECT_EQ(rgb.at<cv::Vec3b>(0, 1), cv::Vec3b(6, 5, 4));
}

TEST(Image, RowPaddingIsSkipped)
{
  const std::vector<std::uint8_t> padded = {10, 20, 30, 0, 40, 50, 60, 0};
  const cv::Mat rgb = to_rgb("rgb8", padded.data(), 1, 2, 4);
  EXPECT_EQ(rgb.at<cv::Vec3b>(1, 0), cv::Vec3b(40, 50, 60));
}

TEST(Image, UnknownEncodingThrows)
{
  const std::vector<std::uint8_t> data(4);
  EXPECT_THROW(to_rgb("yuv422", data.data(), 1, 1, 4), std::invalid_argument);
}

TEST(Image, WideImageIsPaddedTopAndBottom)
{
  const cv::Mat rgb(720, 1280, CV_8UC3, cv::Scalar(0, 0, 0));
  cv::Mat out;
  const auto box = letterbox(rgb, 640, 640, out);
  EXPECT_DOUBLE_EQ(box.scale, 0.5);
  EXPECT_EQ(box.width, 640);
  EXPECT_EQ(box.height, 360);
  EXPECT_EQ(box.left, 0);
  EXPECT_EQ(box.top, 140);
  EXPECT_EQ(out.size(), cv::Size(640, 640));
  EXPECT_EQ(out.at<cv::Vec3b>(0, 0), cv::Vec3b(114, 114, 114));
  EXPECT_EQ(out.at<cv::Vec3b>(320, 320), cv::Vec3b(0, 0, 0));
}

TEST(Image, ChwNormalizesEachChannel)
{
  const cv::Mat rgb(1, 2, CV_8UC3, cv::Scalar(255, 0, 51));
  std::vector<float> chw(6);
  to_chw(rgb, {0.0F, 0.0F, 0.0F}, {1.0F, 1.0F, 0.5F}, chw.data());
  EXPECT_FLOAT_EQ(chw[0], 1.0F);
  EXPECT_FLOAT_EQ(chw[1], 1.0F);
  EXPECT_FLOAT_EQ(chw[2], 0.0F);
  EXPECT_FLOAT_EQ(chw[4], 0.4F);
}

TEST(Image, UnletterboxDropsThePadding)
{
  const cv::Mat rgb(720, 1280, CV_8UC3, cv::Scalar(0, 0, 0));
  cv::Mat out;
  const auto box = letterbox(rgb, 640, 640, out);
  cv::Mat map(640, 640, CV_8UC1, cv::Scalar(9));
  map(cv::Rect(0, 0, 640, box.top)).setTo(1);
  // Written in place, as into a loan.
  std::vector<std::uint8_t> memory(1280 * 720);
  cv::Mat back(720, 1280, CV_8UC1, memory.data());
  unletterbox(map, box, back, cv::INTER_NEAREST);
  EXPECT_EQ(back.data, memory.data());
  EXPECT_EQ(cv::countNonZero(back != 9), 0);
}

TEST(Image, AlignCornersKeepsTheCornerValues)
{
  // torch interpolate(align_corners=True) of [[0, 3]] to width 4 is [[0, 1, 2, 3]].
  const cv::Mat map = (cv::Mat_<float>(1, 2) << 0.0F, 3.0F);
  cv::Mat out(2, 4, CV_32FC1);
  resize_align_corners(map, out);
  for (int x = 0; x < 4; ++x) {
    EXPECT_NEAR(out.at<float>(1, x), static_cast<float>(x), 1e-4);
  }
}

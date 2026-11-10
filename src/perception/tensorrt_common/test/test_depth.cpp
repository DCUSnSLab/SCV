#include "tensorrt_common/depth.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>
#include <vector>

using tensorrt_common::cloud_layout;
using tensorrt_common::depth_to_cloud;
using tensorrt_common::ImageView;
using tensorrt_common::Intrinsics;
using tensorrt_common::scale_intrinsics;
using tensorrt_common::sky_fill_value;

TEST(Depth, IntrinsicsFollowTheResize)
{
  const auto k = scale_intrinsics({600, 500, 639.5, 359.5}, {1280, 720}, {640, 360});
  EXPECT_DOUBLE_EQ(k.fx, 300.0);
  EXPECT_DOUBLE_EQ(k.fy, 250.0);
  EXPECT_DOUBLE_EQ(k.cx, 319.5);
  EXPECT_DOUBLE_EQ(k.cy, 179.5);
}

TEST(Depth, SkyFillIsTheQuantileOfTheGround)
{
  cv::Mat depth(1, 5, CV_32FC1);
  depth.at<float>(0, 0) = 1.0F;
  depth.at<float>(0, 1) = 2.0F;
  depth.at<float>(0, 2) = 3.0F;
  depth.at<float>(0, 3) = 1000.0F;  // sky
  depth.at<float>(0, 4) = std::numeric_limits<float>::infinity();
  const cv::Mat sky = (cv::Mat_<float>(1, 5) << 0.0F, 0.0F, 0.0F, 0.9F, 0.0F);
  EXPECT_FLOAT_EQ(sky_fill_value(depth, sky, 0.3F, 1.0F, 200.0F), 3.0F);
  EXPECT_FLOAT_EQ(sky_fill_value(depth, sky, 0.3F, 1.0F, 2.5F), 2.5F);
  EXPECT_FLOAT_EQ(sky_fill_value(depth, cv::Mat(1, 5, CV_32FC1, 1.0F), 0.3F, 0.99F, 7.0F), 7.0F);
}

TEST(Depth, CloudBackProjectsAndColors)
{
  cv::Mat depth(2, 2, CV_32FC1, cv::Scalar(2.0F));
  depth.at<float>(1, 1) = std::numeric_limits<float>::infinity();
  const std::vector<std::uint8_t> bgr = {10, 20, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  const ImageView color{"bgr8", bgr.data(), 2, 2, 6};
  const auto layout = cloud_layout({2, 2}, 1, true);
  ASSERT_EQ(layout.point_step, 16U);
  std::vector<std::uint8_t> out(4 * layout.point_step);
  depth_to_cloud(depth, {2.0, 2.0, 0.0, 0.0}, 1, &color, layout, out.data());
  float p[3];
  std::memcpy(p, out.data() + 16, sizeof(p));  // pixel (1, 0)
  EXPECT_FLOAT_EQ(p[0], 1.0F);
  EXPECT_FLOAT_EQ(p[1], 0.0F);
  EXPECT_FLOAT_EQ(p[2], 2.0F);
  std::uint32_t rgb = 0;
  std::memcpy(&rgb, out.data() + 12, sizeof(rgb));  // pixel (0, 0)
  EXPECT_EQ(rgb, (30U << 16) | (20U << 8) | 10U);
  std::memcpy(p, out.data() + 48, sizeof(p));  // pixel (1, 1), infinite depth
  EXPECT_TRUE(std::isnan(p[2]));
}

TEST(Depth, DownsampleKeepsEveryNthPixel)
{
  const auto layout = cloud_layout({5, 3}, 2, false);
  EXPECT_EQ(layout.width, 3);
  EXPECT_EQ(layout.height, 2);
  EXPECT_EQ(layout.point_step, 12U);
  EXPECT_THROW(cloud_layout({5, 3}, 0, false), std::invalid_argument);
}

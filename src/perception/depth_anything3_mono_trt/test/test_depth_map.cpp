#include "depth_map.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <limits>

using depth_anything3_mono_trt::mark_sky;
using depth_anything3_mono_trt::resize_for_network;
using depth_anything3_mono_trt::to_meters;

TEST(DepthMap, MetersUseTheFocalLengthAtNetworkSize)
{
  // A 1280-wide camera with fx = fy = 600 seen at 640 x 360: the focal length there is 300.
  cv::Mat depth(360, 640, CV_32FC1, cv::Scalar(2.0F));
  to_meters(depth, 600.0, 600.0, cv::Size(1280, 720));
  EXPECT_FLOAT_EQ(depth.at<float>(0, 0), 2.0F);

  cv::Mat same(720, 1280, CV_32FC1, cv::Scalar(3.0F));
  to_meters(same, 600.0, 600.0, cv::Size(1280, 720));
  EXPECT_FLOAT_EQ(same.at<float>(0, 0), 6.0F);
}

TEST(DepthMap, SkyBecomesInfinity)
{
  cv::Mat depth(1, 2, CV_32FC1, cv::Scalar(5.0F));
  cv::Mat sky = (cv::Mat_<float>(1, 2) << 0.1F, 0.3F);
  mark_sky(depth, sky, 0.3F, std::numeric_limits<float>::infinity());
  EXPECT_FLOAT_EQ(depth.at<float>(0, 0), 5.0F);
  EXPECT_TRUE(std::isinf(depth.at<float>(0, 1)));
}

TEST(DepthMap, ResizeReachesTheNetworkSize)
{
  const cv::Mat rgb(720, 1280, CV_8UC3, cv::Scalar(1, 2, 3));
  EXPECT_EQ(resize_for_network(rgb, cv::Size(504, 280)).size(), cv::Size(504, 280));
  EXPECT_EQ(resize_for_network(rgb, cv::Size(1932, 1092)).size(), cv::Size(1932, 1092));
}

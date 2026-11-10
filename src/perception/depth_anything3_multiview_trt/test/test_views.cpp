#include "views.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <vector>

using depth_anything3_multiview_trt::intrinsics_of_view;
using depth_anything3_multiview_trt::poses_in_view0;
using depth_anything3_multiview_trt::ViewSet;

TEST(Views, View0IsTheOrigin)
{
  // View 0 at (1, 0, 0) turned 90 degrees about z; view 1 at (1, 1, 0) with the same rotation.
  const float s = std::sqrt(0.5F);
  const std::vector<float> enc = {1, 0, 0, 0, 0, s, s, 1, 1,  //
                                  1, 1, 0, 0, 0, s, s, 1, 1};
  const auto poses = poses_in_view0(enc.data(), 2);
  ASSERT_EQ(poses.size(), 2U);
  EXPECT_NEAR(poses[0].getOrigin().length(), 0.0, 1e-6);
  // One unit along world y is one unit along x of view 0.
  EXPECT_NEAR(poses[1].getOrigin().x(), 1.0, 1e-6);
  EXPECT_NEAR(poses[1].getOrigin().y(), 0.0, 1e-6);
  EXPECT_NEAR(poses[1].getRotation().getAngle(), 0.0, 1e-6);
}

TEST(Views, UnnormalizedQuaternionsAreNormalized)
{
  const std::vector<float> enc = {0, 0, 0, 0, 0, 0, 2, 1, 1};
  const auto poses = poses_in_view0(enc.data(), 1);
  EXPECT_NEAR(poses[0].getRotation().length(), 1.0, 1e-6);
}

TEST(Views, SetNeedsEveryViewWithinTheSkew)
{
  ViewSet set(2, 10);
  const cv::Mat img(1, 1, CV_8UC3);
  EXPECT_FALSE(set.complete());
  set.put(0, 100, img);
  EXPECT_FALSE(set.complete());
  set.put(1, 120, img);
  EXPECT_FALSE(set.complete());
  set.put(1, 105, img);
  EXPECT_TRUE(set.complete());
}

TEST(Views, IntrinsicsComeFromTheFieldOfView)
{
  // 90 degrees across a 504 x 280 input: the focal length is half the side.
  const float q = static_cast<float>(M_PI / 2);
  const std::vector<float> enc = {0, 0, 0, 0, 0, 0, 1, q, q};
  const auto k = intrinsics_of_view(enc.data(), 0, cv::Size(504, 280));
  EXPECT_NEAR(k.fx, 252.0, 1e-3);
  EXPECT_NEAR(k.fy, 140.0, 1e-3);
  EXPECT_DOUBLE_EQ(k.cx, 252.0);
  EXPECT_DOUBLE_EQ(k.cy, 140.0);
}

#include "frames.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace sensor_dummy
{
namespace
{

TEST(FramesTest, MountTurnsWithTheBase)
{
  const Eigen::Vector3d p = map_position({1.0, 2.0, M_PI / 2.0}, {0.5, 0.2, 0.9});
  EXPECT_NEAR(p.x(), 0.8, 1e-12);
  EXPECT_NEAR(p.y(), 2.5, 1e-12);
  EXPECT_DOUBLE_EQ(p.z(), 0.9);
}

TEST(FramesTest, RelativePoseIsInTheOriginFrame)
{
  const Pose2d pose = relative_pose({1.0, 2.0, M_PI / 2.0}, {1.0, 3.0, M_PI / 2.0 + 0.3});
  EXPECT_NEAR(pose.x, 1.0, 1e-12);
  EXPECT_NEAR(pose.y, 0.0, 1e-12);
  EXPECT_NEAR(pose.yaw, 0.3, 1e-12);
}

TEST(FramesTest, RelativePoseUndoesMapPosition)
{
  const Pose2d origin{-3.0, 4.0, 0.7};
  const Eigen::Vector3d p = map_position(origin, {2.0, -1.0, 0.0});
  const Pose2d pose = relative_pose(origin, {p.x(), p.y(), 0.0});
  EXPECT_NEAR(pose.x, 2.0, 1e-12);
  EXPECT_NEAR(pose.y, -1.0, 1e-12);
}

}  // namespace
}  // namespace sensor_dummy

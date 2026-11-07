#include "world_map.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <string>
#include <vector>

namespace sensor_dummy
{
namespace
{
WorldMap one_box(double yaw)
{
  return WorldMap(
    0.0, 20.0f,
    {{Eigen::Vector2d(5.0, 0.0), Eigen::Vector2d(0.5, 1.0), std::cos(yaw), std::sin(yaw), 2.0f,
      90.0f}});
}

TEST(WorldMapTest, DownwardRayHitsTheGround)
{
  const WorldMap map(0.0, 20.0f, {});
  RayHit hit{};
  const Eigen::Vector3d direction = Eigen::Vector3d(1.0, 0.0, -1.0).normalized();
  ASSERT_TRUE(map.raycast({0.0, 0.0, 1.0}, direction, 100.0, hit));
  EXPECT_NEAR(hit.range, std::sqrt(2.0), 1e-9);
  EXPECT_FLOAT_EQ(hit.intensity, 20.0f);
}

TEST(WorldMapTest, UpwardRayEscapes)
{
  const WorldMap map(0.0, 20.0f, {});
  RayHit hit{};
  EXPECT_FALSE(map.raycast({0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, 100.0, hit));
}

TEST(WorldMapTest, HorizontalRayHitsTheNearFace)
{
  RayHit hit{};
  ASSERT_TRUE(one_box(0.0).raycast({0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}, 100.0, hit));
  EXPECT_NEAR(hit.range, 4.5, 1e-9);
  EXPECT_FLOAT_EQ(hit.intensity, 90.0f);
}

TEST(WorldMapTest, RayOverTheTopMisses)
{
  RayHit hit{};
  EXPECT_FALSE(one_box(0.0).raycast({0.0, 0.0, 3.0}, {1.0, 0.0, 0.0}, 100.0, hit));
}

TEST(WorldMapTest, YawTurnsTheBox)
{
  RayHit hit{};
  ASSERT_TRUE(one_box(M_PI / 2.0).raycast({0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}, 100.0, hit));
  EXPECT_NEAR(hit.range, 4.0, 1e-9);
}

TEST(WorldMapTest, MaxRangeLimitsTheHit)
{
  RayHit hit{};
  EXPECT_FALSE(one_box(0.0).raycast({0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}, 3.0, hit));
}

TEST(WorldMapTest, LoadsWallsAndBoxes)
{
  const std::string path = ::testing::TempDir() + "/sensor_dummy_map.yaml";
  std::ofstream(path)
    << "ground: {z: 0.0, intensity: 20.0}\n"
       "walls:\n"
       "  - {start: [10.0, -5.0], end: [10.0, 5.0], height: 2.0, thickness: 0.2, intensity: 60.0}\n"
       "boxes:\n"
       "  - {center: [5.0, 3.0], size: [1.0, 1.0], yaw: 0.0, height: 1.0, intensity: 90.0}\n";
  const WorldMap map = WorldMap::load(path);
  RayHit hit{};
  ASSERT_TRUE(map.raycast({0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}, 100.0, hit));
  EXPECT_NEAR(hit.range, 9.9, 1e-9);
  ASSERT_TRUE(map.raycast({0.0, 3.0, 0.5}, {1.0, 0.0, 0.0}, 100.0, hit));
  EXPECT_NEAR(hit.range, 4.5, 1e-9);
}

}  // namespace
}  // namespace sensor_dummy

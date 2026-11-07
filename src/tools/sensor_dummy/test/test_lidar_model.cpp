#include "lidar_model.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <vector>

namespace sensor_dummy
{
namespace
{
constexpr LidarConfig lidar_config{600.0, 1812, 55.296e-6, 2.304e-6, 0.9, 200.0};

float read_float(const std::uint8_t * data, std::size_t offset)
{
  float value = 0.0f;
  std::memcpy(&value, data + offset, sizeof(value));
  return value;
}

Eigen::Isometry3d lidar_mount()
{
  Eigen::Isometry3d mount = Eigen::Isometry3d::Identity();
  mount.translation() = Eigen::Vector3d(0.21, 0.0, 0.905);
  return mount;
}

TEST(LoadBeamsTest, ReadsThe32RealAngles)
{
  const auto beams = load_beams(VLP32C_CALIBRATION, lidar_config.firing_step_s);
  ASSERT_EQ(beams.size(), 32u);
  std::vector<double> vertical;
  for (const auto & beam : beams) {
    vertical.push_back(std::atan2(beam.sin_vertical, beam.cos_vertical) * 180.0 / M_PI);
  }
  EXPECT_NEAR(*std::min_element(vertical.begin(), vertical.end()), -25.0, 1e-6);
  EXPECT_NEAR(*std::max_element(vertical.begin(), vertical.end()), 15.0, 1e-6);
  // laser 0 is the lowest beam, laser 25 is not the highest: ring ranks by angle, not by id.
  EXPECT_EQ(beams[0].ring, 0);
  EXPECT_EQ(beams[29].ring, 31);
  EXPECT_DOUBLE_EQ(beams[2].firing_s, lidar_config.firing_step_s);
}

class RenderScanTest : public ::testing::Test
{
protected:
  void render(const Pose2d & start, const Pose2d & end)
  {
    render_scan(lidar_config, beams, map, start, end, lidar_mount(), data);
  }

  const std::uint8_t * point(int row, int ring) const
  {
    return &data[(row * beams.size() + ring) * point_step];
  }

  std::vector<LaserBeam> beams = load_beams(VLP32C_CALIBRATION, lidar_config.firing_step_s);
  WorldMap map{
    0.0, 20.0f, {{Eigen::Vector2d(10.2, 0.0), Eigen::Vector2d(0.1, 50.0), 1.0, 0.0, 3.0f, 60.0f}}};
  std::vector<std::uint8_t> data;
};

TEST_F(RenderScanTest, CloudHasTheSizeOfTheRealOrganizedCloud)
{
  render({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
  EXPECT_EQ(data.size(), 1812u * 32u * 22u);
}

TEST_F(RenderScanTest, GroundReturnsSitBelowTheSensor)
{
  render({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
  // ring 0 at -25 deg from 0.905 m reaches the ground 1.94 m away.
  const auto * p = point(900, 0);
  EXPECT_NEAR(read_float(p, 8), -0.905, 1e-3);
  EXPECT_FLOAT_EQ(read_float(p, 12), 20.0f);
}

TEST_F(RenderScanTest, FirstRowLooksForwardAndHitsTheWall)
{
  render({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
  // ring 31 is +15 deg, too high for the wall top at this range: use a level beam.
  const auto * p = point(0, 19);
  EXPECT_NEAR(read_float(p, 0), 9.89, 1e-2);
  EXPECT_FLOAT_EQ(read_float(p, 12), 60.0f);
}

TEST_F(RenderScanTest, SensorSpinsClockwise)
{
  render({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
  // A quarter of a turn later a level beam looks at -y. There is no wall there: the ground ring.
  const int quarter = static_cast<int>(0.025 / lidar_config.block_period_s);
  EXPECT_LT(read_float(point(quarter, 0), 4), -1.0f);
}

TEST_F(RenderScanTest, RaysThatEscapeBecomeNanButKeepRingAndTime)
{
  render({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
  const int behind = static_cast<int>(0.05 / lidar_config.block_period_s);
  const auto * p = point(behind, 31);
  EXPECT_TRUE(std::isnan(read_float(p, 0)));
  std::uint16_t ring = 0;
  std::memcpy(&ring, p + ring_offset, sizeof(ring));
  EXPECT_EQ(ring, 31);
  EXPECT_NEAR(read_float(p, time_offset), 0.05, 1e-3);
}

TEST_F(RenderScanTest, TimeGrowsWithTheRow)
{
  render({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
  EXPECT_FLOAT_EQ(read_float(point(0, 0), time_offset), 0.0f);
  EXPECT_NEAR(read_float(point(1811, 0), time_offset), 0.1002, 1e-4);
}

TEST_F(RenderScanTest, MotionShortensTheRangeToTheWall)
{
  render({1.0, 0.0, 0.0}, {1.0, 0.0, 0.0});
  EXPECT_NEAR(read_float(point(0, 19), 0), 8.89, 1e-2);
}

TEST_F(RenderScanTest, LaterRowsSeeTheLaterPose)
{
  render({0.0, 0.0, 0.0}, {2.0, 0.0, 0.0});
  // The last row is one rotation on, again looking forward, from almost x = 2.
  EXPECT_NEAR(read_float(point(1811, 19), 0), 7.89, 2e-2);
}

}  // namespace
}  // namespace sensor_dummy

#include "rolling_grid.hpp"

#include <gtest/gtest.h>

#include <array>
#include <cmath>
#include <cstring>
#include <limits>
#include <vector>

namespace simple_local_grid
{
namespace
{

constexpr double grid_resolution = 0.1;
constexpr int grid_size = 100;

ObstacleFilter filter()
{
  ObstacleFilter f;
  f.min_height = 0.2;
  f.max_height = 1.8;
  f.self_min_x = -0.5;
  f.self_max_x = 0.6;
  f.self_min_y = -0.4;
  f.self_max_y = 0.4;
  return f;
}

int occupied_count(const std::vector<std::int8_t> & cells)
{
  int count = 0;
  for (const std::int8_t cell : cells) {
    count += cell == 100;
  }
  return count;
}

bool occupied_at(const RollingGrid & grid, double x, double y)
{
  const int col = static_cast<int>(std::floor((x - grid.origin_x()) / grid.resolution()));
  const int row = static_cast<int>(std::floor((y - grid.origin_y()) / grid.resolution()));
  return grid.occupancy()[std::size_t(row) * grid.size_cells() + col] == 100;
}

RawCloud cloud_of(const std::vector<std::array<float, 4>> & points)
{
  RawCloud cloud;
  set_field_offset(cloud, "x", 0);
  set_field_offset(cloud, "y", 4);
  set_field_offset(cloud, "z", 8);
  cloud.data = reinterpret_cast<const std::uint8_t *>(points.data());
  cloud.count = points.size();
  cloud.step = sizeof(points[0]);
  return cloud;
}

TEST(ObstacleFilter, KeepsThePointsBetweenTheHeightsAndOffTheVehicle)
{
  EXPECT_TRUE(is_obstacle(filter(), {2.0F, 0.0F, 0.5F}));
  EXPECT_FALSE(is_obstacle(filter(), {2.0F, 0.0F, 0.05F}));
  EXPECT_FALSE(is_obstacle(filter(), {2.0F, 0.0F, 2.5F}));
  EXPECT_FALSE(is_obstacle(filter(), {0.2F, 0.3F, 0.5F}));
}

TEST(ObstacleFilter, RejectsNan)
{
  const float nan = std::numeric_limits<float>::quiet_NaN();
  EXPECT_FALSE(is_obstacle(filter(), {nan, nan, nan}));
  EXPECT_FALSE(is_obstacle(filter(), {1.0F, 1.0F, nan}));
}

TEST(RollingGrid, CentersOnTheVehicleAndSnapsToCells)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(12.34, -5.67);
  EXPECT_NEAR(grid.origin_x(), 12.3 - 5.0, 1e-9);
  EXPECT_NEAR(grid.origin_y(), -5.7 - 5.0, 1e-9);
}

TEST(RollingGrid, HitKeepsItsWorldPositionAndTopWhenTheWindowMoves)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(3.05, -2.05, 0.3F);
  ASSERT_TRUE(occupied_at(grid, 3.05, -2.05));

  grid.center_on(1.53, 0.77);
  EXPECT_TRUE(occupied_at(grid, 3.05, -2.05));
  EXPECT_EQ(occupied_count(grid.occupancy()), 1);

  grid.center_on(-1.2, -2.4);
  EXPECT_TRUE(occupied_at(grid, 3.05, -2.05));
  EXPECT_EQ(occupied_count(grid.occupancy()), 1);

  grid.clear_beam({0.05, -2.05, 0.9}, {5.05, -2.05, 0.1});
  EXPECT_TRUE(occupied_at(grid, 3.05, -2.05));
  grid.clear_beam({2.05, -2.05, 0.2}, {4.05, -2.05, 0.2});
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
}

TEST(RollingGrid, HitLeavesWithTheWindowAndDoesNotReturn)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(4.0, 4.0, 0.3F);
  grid.center_on(20.0, 20.0);
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
  grid.center_on(0.0, 0.0);
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
}

TEST(RollingGrid, HitOutsideTheWindowIsIgnored)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(5.05, 0.0, 0.3F);
  grid.add_hit(-5.05, 0.0, 0.3F);
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
}

TEST(RollingGrid, BeamBelowTheTopClearsTheCell)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(1.05, 0.05, 0.5F);
  grid.clear_beam({0.05, 0.05, 0.4}, {3.05, 0.05, 0.4});
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
}

TEST(RollingGrid, BeamAboveTheTopLeavesTheCell)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(1.05, 0.05, 0.3F);
  grid.clear_beam({0.05, 0.05, 0.9}, {3.05, 0.05, 0.4});
  EXPECT_EQ(occupied_count(grid.occupancy()), 1);
}

TEST(RollingGrid, CellKeepsTheHighestHit)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(1.05, 0.05, 0.3F);
  grid.add_hit(1.05, 0.05, 0.8F);
  grid.add_hit(1.05, 0.05, 0.25F);
  grid.clear_beam({0.05, 0.05, 0.7}, {3.05, 0.05, 0.7});
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
}

TEST(RollingGrid, DescendingBeamClearsOnlyWhereItHasFallenBelowTheTop)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(0.55, 0.05, 0.3F);
  grid.add_hit(2.55, 0.05, 0.3F);
  // From 0.9 m at x = 0 down to the ground at x = 3: 0.3 m high at x = 2.
  grid.clear_beam({0.0, 0.05, 0.9}, {3.0, 0.05, 0.0});
  EXPECT_TRUE(occupied_at(grid, 0.55, 0.05));
  EXPECT_FALSE(occupied_at(grid, 2.55, 0.05));
}

TEST(RollingGrid, TheReturnCellOfABeamStays)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(2.05, 0.05, 1.0F);
  grid.clear_beam({0.05, 0.05, 0.5}, {2.05, 0.05, 0.5});
  EXPECT_EQ(occupied_count(grid.occupancy()), 1);
}

TEST(RollingGrid, DiagonalBeamClearsAlongItsLine)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(1.05, -1.05, 1.0F);
  grid.add_hit(1.05, 1.05, 1.0F);
  grid.clear_beam({0.05, -0.05, 0.5}, {2.05, -2.05, 0.5});
  EXPECT_FALSE(occupied_at(grid, 1.05, -1.05));
  EXPECT_TRUE(occupied_at(grid, 1.05, 1.05));
}

TEST(RollingGrid, BeamStopsAtTheEdgeOfTheWindow)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(4.95, 0.05, 1.0F);
  grid.clear_beam({0.05, 0.05, 0.5}, {50.0, 0.05, 0.5});
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
}

TEST(RollingGrid, HitNeverExpiresWithoutABeam)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  grid.add_hit(1.05, 0.05, 0.3F);
  const std::vector<std::array<float, 4>> nothing;
  const Eigen::Isometry3d here = Eigen::Isometry3d::Identity();
  for (int scan = 0; scan < 10000; ++scan) {
    grid.insert(cloud_of(nothing), Eigen::Isometry3f::Identity(), here, filter(), 1);
  }
  EXPECT_EQ(occupied_count(grid.occupancy()), 1);
}

TEST(RollingGrid, ClearsTheCellsUnderTheVehicleOnly)
{
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(2.0, 1.0);
  // The vehicle at (2, 1) faces +y, so the box reaches 0.6 along +y and 0.4 along x.
  const Eigen::Isometry3d grid_from_base =
    Eigen::Translation3d(2.0, 1.0, 0.0) * Eigen::AngleAxisd(M_PI_2, Eigen::Vector3d::UnitZ());
  grid.add_hit(2.05, 1.05, 0.3F);
  grid.add_hit(2.05, 1.55, 0.3F);
  grid.add_hit(2.35, 1.05, 0.3F);
  grid.add_hit(2.05, 1.75, 0.3F);
  grid.add_hit(2.55, 1.05, 0.3F);
  grid.clear_vehicle(filter(), grid_from_base);
  EXPECT_EQ(occupied_count(grid.occupancy()), 2);
  EXPECT_TRUE(occupied_at(grid, 2.05, 1.75));
  EXPECT_TRUE(occupied_at(grid, 2.55, 1.05));
}

TEST(RollingGrid, InsertTransformsThePointsAndDropsTheGround)
{
  // x, y, z and one padding float, the shape of a real cloud whose step exceeds the three fields.
  const std::vector<std::array<float, 4>> points = {
    {3.0F, 0.0F, -0.4F, 0.0F},
    {3.0F, 0.0F, -0.9F, 0.0F},
    {std::nanf(""), std::nanf(""), std::nanf(""), 0.0F},
  };

  // The sensor is 0.9 m above the base; the base is at (2, 1) and turned 90 degrees.
  const Eigen::Isometry3f base_from_sensor(Eigen::Translation3f(0.0F, 0.0F, 0.9F));
  const Eigen::Isometry3d grid_from_base =
    Eigen::Translation3d(2.0, 1.0, 0.0) * Eigen::AngleAxisd(M_PI_2, Eigen::Vector3d::UnitZ());

  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(2.0, 1.0);
  grid.insert(cloud_of(points), base_from_sensor, grid_from_base, filter(), 1);

  EXPECT_EQ(occupied_count(grid.occupancy()), 1);
  EXPECT_TRUE(occupied_at(grid, 2.0, 4.0));
}

TEST(RollingGrid, InsertClearsAnOldMarkAlongAGroundReturnAndKeepsTheNewHit)
{
  const std::vector<std::array<float, 4>> ground = {
    {4.0F, 0.0F, -0.9F, 0.0F},
    {2.0F, 1.0F, -0.4F, 0.0F},
  };
  const Eigen::Isometry3f base_from_sensor(Eigen::Translation3f(0.0F, 0.0F, 0.9F));
  const Eigen::Isometry3d grid_from_base = Eigen::Isometry3d::Identity();

  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  // At x = 3.05 the beam to the ground return is about 0.22 m high.
  grid.add_hit(3.05, 0.05, 0.3F);
  grid.insert(cloud_of(ground), base_from_sensor, grid_from_base, filter(), 1);
  EXPECT_FALSE(occupied_at(grid, 3.05, 0.05));
  EXPECT_TRUE(occupied_at(grid, 2.05, 1.05));
}

TEST(RollingGrid, StrideReachesEveryBeamOverSuccessiveScans)
{
  // Five ground returns, and halfway along each beam a mark that only that beam passes under.
  const Eigen::Isometry3f base_from_sensor(Eigen::Translation3f(0.05F, 0.05F, 0.9F));
  std::vector<std::array<float, 4>> ground;
  RollingGrid grid(grid_resolution, grid_size);
  grid.center_on(0.0, 0.0);
  for (int i = -2; i <= 2; ++i) {
    ground.push_back({4.0F, static_cast<float>(i), -0.9F, 0.0F});
    grid.add_hit(2.05, 0.05 + 0.5 * i, 0.8F);
  }
  const Eigen::Isometry3d here = Eigen::Isometry3d::Identity();
  grid.insert(cloud_of(ground), base_from_sensor, here, filter(), 5);
  EXPECT_EQ(occupied_count(grid.occupancy()), 4);
  for (int scan = 1; scan < 5; ++scan) {
    grid.insert(cloud_of(ground), base_from_sensor, here, filter(), 5);
  }
  EXPECT_EQ(occupied_count(grid.occupancy()), 0);
}

}  // namespace
}  // namespace simple_local_grid

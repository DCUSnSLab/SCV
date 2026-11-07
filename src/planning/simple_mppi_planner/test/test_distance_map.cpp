#include "distance_map.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <random>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

constexpr int grid_size = 40;
constexpr double grid_resolution = 0.1;

TEST(DistanceMap, MatchesBruteForceOnRandomCells)
{
  std::mt19937 generator(7);
  std::vector<std::int8_t> cells(grid_size * grid_size, 0);
  std::vector<std::pair<int, int>> occupied;
  for (int i = 0; i < 30; ++i) {
    const int col = generator() % grid_size;
    const int row = generator() % grid_size;
    cells[row * grid_size + col] = 100;
    occupied.emplace_back(col, row);
  }
  DistanceMap map;
  map.build({cells.data(), grid_size, grid_size, grid_resolution, 2.0, -1.0, 50});

  for (int row = 0; row < grid_size; ++row) {
    for (int col = 0; col < grid_size; ++col) {
      double expected = 1e9;
      for (const auto & [c, r] : occupied) {
        expected = std::min(expected, std::hypot(c - col, r - row) * grid_resolution);
      }
      const double x = 2.0 + (col + 0.5) * grid_resolution;
      const double y = -1.0 + (row + 0.5) * grid_resolution;
      ASSERT_NEAR(map.at(x, y), expected, 1e-5);
    }
  }
}

TEST(DistanceMap, ReturnsZeroOutsideTheGrid)
{
  std::vector<std::int8_t> cells(grid_size * grid_size, 0);
  DistanceMap map;
  map.build({cells.data(), grid_size, grid_size, grid_resolution, 0.0, 0.0, 50});
  EXPECT_GT(map.at(1.0, 1.0), 100.0);
  EXPECT_EQ(map.at(-0.01, 1.0), 0.0);
  EXPECT_EQ(map.at(1.0, -0.01), 0.0);
  EXPECT_EQ(map.at(4.01, 1.0), 0.0);
  EXPECT_EQ(map.at(1.0, 4.01), 0.0);
}

TEST(DistanceMap, TreatsUnknownAsBelowTheThreshold)
{
  std::vector<std::int8_t> cells(grid_size * grid_size, -1);
  cells[0] = 50;
  DistanceMap map;
  map.build({cells.data(), grid_size, grid_size, grid_resolution, 0.0, 0.0, 50});
  EXPECT_EQ(map.at(0.05, 0.05), 0.0);
  EXPECT_NEAR(map.at(0.25, 0.05), 0.2, 1e-5);
}

}  // namespace
}  // namespace simple_mppi_planner

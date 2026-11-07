#include "reference_path.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <utility>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

using Waypoints = std::vector<std::pair<double, double>>;

TEST(ReferencePath, ResamplesSparseWaypointsAcrossCorners)
{
  const ReferencePath route(Waypoints{{0.0, 0.0}, {3.0, 0.0}, {3.0, 3.0}}, 0.2, 1.0, 0.5);
  EXPECT_EQ(route.size(), 31);
  EXPECT_NEAR(route.length(), 6.0, 0.1);
  for (int i = 1; i < route.size(); ++i) {
    const double gap =
      std::hypot(route.point(i).x - route.point(i - 1).x, route.point(i).y - route.point(i - 1).y);
    ASSERT_LE(gap, 0.2 + 1e-9);
  }
  EXPECT_EQ(route.point(route.size() - 1).x, 3.0);
  EXPECT_EQ(route.point(route.size() - 1).y, 3.0);
  EXPECT_NEAR(route.point(5).cos_heading, 1.0, 1e-9);
  EXPECT_NEAR(route.point(25).sin_heading, 1.0, 1e-9);
}

TEST(ReferencePath, SkipsRepeatedWaypoints)
{
  const ReferencePath route(Waypoints{{0.0, 0.0}, {1.0, 0.0}, {1.0, 0.0}}, 0.2, 1.0, 0.5);
  EXPECT_NEAR(route.length(), 1.0, 1e-9);
  for (int i = 0; i < route.size(); ++i) {
    ASSERT_TRUE(std::isfinite(route.point(i).cos_heading));
  }
}

TEST(ReferencePath, SpeedFallsToZeroAtTheGoal)
{
  const ReferencePath route(Waypoints{{0.0, 0.0}, {10.0, 0.0}}, 0.2, 1.0, 0.5);
  EXPECT_EQ(route.point(0).speed, 1.0);
  EXPECT_EQ(route.point(route.size() - 1).speed, 0.0);
  const RoutePoint & near_goal = route.point(route.size() - 6);
  EXPECT_NEAR(near_goal.speed, std::sqrt(2.0 * 0.5 * 1.0), 1e-6);
}

TEST(ReferencePath, AdvanceStaysOnThePassItIsOn)
{
  // Out along y = 0 and back over the same line.
  const ReferencePath route(Waypoints{{0.0, 0.0}, {10.0, 0.0}, {0.0, 0.0}}, 0.2, 1.0, 0.5);
  const int index = route.advance(10, 3.0, 0.0, 25);
  EXPECT_NEAR(route.point(index).arc, 3.0, 0.2);
}

TEST(ReferencePath, AdvanceNeverGoesBack)
{
  const ReferencePath route(Waypoints{{0.0, 0.0}, {10.0, 0.0}}, 0.2, 1.0, 0.5);
  EXPECT_EQ(route.advance(20, 0.0, 0.0, 25), 20);
}

TEST(ReferencePath, GoalNeedsBothProgressAndPosition)
{
  const Waypoints loop{{0.0, 0.0}, {4.0, 0.0}, {4.0, 4.0}, {0.0, 0.2}};
  const ReferencePath route(loop, 0.2, 1.0, 0.5);
  EXPECT_FALSE(route.at_goal(0, 0.0, 0.0, 0.3));
  EXPECT_TRUE(route.at_goal(route.size() - 1, 0.0, 0.2, 0.3));
  EXPECT_FALSE(route.at_goal(route.size() - 1, 1.0, 1.0, 0.3));
}

}  // namespace
}  // namespace simple_mppi_planner

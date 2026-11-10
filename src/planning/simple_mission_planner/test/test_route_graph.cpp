#include "route_graph.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <optional>
#include <vector>

namespace simple_mission_planner
{
namespace
{

using Route = std::vector<std::int64_t>;

// 1 - 2 - 4 is 2 m long; 1 - 3 - 4 is 4 m; 5 stands apart.
RouteGraph diamond()
{
  return RouteGraph(
    {{1, 0.0, 0.0}, {2, 1.0, 0.0}, {3, 1.0, 2.0}, {4, 2.0, 0.0}, {5, 9.0, 9.0}},
    {{1, 2, 1.0}, {2, 4, 1.0}, {1, 3, 2.0}, {3, 4, 2.0}});
}

TEST(RouteGraph, TakesTheShorterBranch)
{
  EXPECT_EQ(diamond().astar(1, 4), Route({1, 2, 4}));
}

TEST(RouteGraph, DrivesAnEdgeAgainstItsDrawingOrder)
{
  EXPECT_EQ(diamond().astar(4, 1), Route({4, 2, 1}));
}

TEST(RouteGraph, ReportsAnUnreachableGoal)
{
  EXPECT_EQ(diamond().astar(1, 5), std::nullopt);
}

TEST(RouteGraph, SnapsToTheNearestNode)
{
  EXPECT_EQ(diamond().nearest(1.1, 1.8), 3);
}

TEST(RouteGraph, AnEmptyMapHasNoNearestNode)
{
  EXPECT_EQ(RouteGraph({}, {}).nearest(0.0, 0.0), std::nullopt);
}

TEST(RouteGraph, ARouteToTheStartIsTheStartAlone)
{
  EXPECT_EQ(diamond().astar(2, 2), Route({2}));
}

TEST(RouteGraph, FollowsEdgeLengthsNotStraightLines)
{
  // The 1 - 2 - 4 road runs straight but is 10 m long; 1 - 3 - 4 bends and is 3 m.
  const RouteGraph graph(
    {{1, 0.0, 0.0}, {2, 1.0, 0.0}, {3, 1.0, 1.0}, {4, 2.0, 0.0}},
    {{1, 2, 5.0}, {2, 4, 5.0}, {1, 3, 1.5}, {3, 4, 1.5}});
  EXPECT_EQ(graph.astar(1, 4), Route({1, 3, 4}));
}

TEST(RouteGraph, FindsARouteOverSeveralHops)
{
  const RouteGraph graph(
    {{10, 0.0, 0.0}, {11, 1.0, 0.0}, {12, 2.0, 0.0}, {13, 2.0, 1.0}, {14, 3.0, 1.0}},
    {{10, 11, 1.0}, {12, 11, 1.0}, {12, 13, 1.0}, {14, 13, 1.0}});
  EXPECT_EQ(graph.astar(14, 10), Route({14, 13, 12, 11, 10}));
}

}  // namespace
}  // namespace simple_mission_planner

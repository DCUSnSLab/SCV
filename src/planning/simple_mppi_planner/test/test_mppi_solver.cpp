#include "mppi_solver.hpp"
#include "scene.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <string>
#include <utility>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

using Waypoints = std::vector<std::pair<double, double>>;

constexpr double kControlPeriod = 0.05;
constexpr double kMinObservableSpeed = 0.1;

struct Outcome
{
  bool reached_goal = false;
  bool ever_infeasible = false;
  double min_clearance = std::numeric_limits<double>::infinity();
  double max_speed = 0.0;
  double max_curvature = 0.0;
  double final_speed = 0.0;
  State last;
};

// The model of the planner stands in for the vehicle, fed the published twist.
class ClosedLoop
{
public:
  ClosedLoop(const VehicleParams & vehicle, const World & world, const Waypoints & waypoints)
  : vehicle_(vehicle),
    footprint_(footprint_of(vehicle)),
    map_(world.distance_map()),
    route_(waypoints, kRouteSpacing, kCruiseSpeed, kStopDecel),
    solver_(mppi_of(vehicle, 1), cost_params(vehicle), vehicle, footprint_)
  {
    state_.x = waypoints.front().first + vehicle.kinematic_center_x;
    state_.y = waypoints.front().second;
  }

  // Puts the pose frame at (x, y) with the heading yaw.
  void place(double x, double y, double yaw)
  {
    state_.x = x + vehicle_.kinematic_center_x * std::cos(yaw);
    state_.y = y + vehicle_.kinematic_center_x * std::sin(yaw);
    state_.yaw = yaw;
  }

  Outcome run(double duration_sec)
  {
    Outcome result;
    int index = route_.nearest(
      state_.x - vehicle_.kinematic_center_x * std::cos(state_.yaw),
      state_.y - vehicle_.kinematic_center_x * std::sin(state_.yaw));
    for (double t = 0.0; t < duration_sec && !result.reached_goal; t += kControlPeriod) {
      const double x = state_.x - vehicle_.kinematic_center_x * std::cos(state_.yaw);
      const double y = state_.y - vehicle_.kinematic_center_x * std::sin(state_.yaw);
      index = route_.advance(index, x, y, 25);
      result.reached_goal = route_.at_goal(index, x, y, 0.3);
      const Solution solution = solver_.solve(state_, route_, index, map_);
      result.ever_infeasible |= !solution.feasible;
      const Control control = solution.feasible ? solution.control : Control{};
      const Twist2d twist = to_twist(vehicle_, control);
      result.max_speed = std::max(result.max_speed, std::abs(twist.linear));
      if (std::abs(twist.linear) > 1e-3) {
        const double curvature = std::abs(twist.angular / twist.linear);
        result.max_curvature = std::max(result.max_curvature, curvature);
      }
      step(vehicle_, control, kControlPeriod, &state_);
      result.min_clearance = std::min(result.min_clearance, clearance());
    }
    result.final_speed = state_.speed;
    result.last = state_;
    return result;
  }

private:
  double clearance() const
  {
    double best = std::numeric_limits<double>::infinity();
    for (const double circle : footprint_.circle_x) {
      const double offset = circle - vehicle_.kinematic_center_x;
      best = std::min(
        best,
        map_.at(
          state_.x + offset * std::cos(state_.yaw), state_.y + offset * std::sin(state_.yaw)) -
          footprint_.radius);
    }
    return best;
  }

  VehicleParams vehicle_;
  Footprint footprint_;
  DistanceMap map_;
  ReferencePath route_;
  MppiSolver solver_;
  State state_;
};

class BothModels : public ::testing::TestWithParam<MotionModel>
{
protected:
  VehicleParams vehicle() const
  {
    return GetParam() == MotionModel::Ackermann ? hunter() : diff_base();
  }
};

TEST_P(BothModels, FollowsAStraightRouteToTheGoal)
{
  const Outcome run = ClosedLoop(vehicle(), World(), Waypoints{{0.0, 0.0}, {10.0, 0.0}}).run(30.0);
  EXPECT_TRUE(run.reached_goal);
  EXPECT_FALSE(run.ever_infeasible);
  EXPECT_LE(run.max_speed, 1.5);
  EXPECT_NEAR(run.last.y, 0.0, 0.3);
}

TEST_P(BothModels, FollowsARouteAroundACorner)
{
  const Waypoints route{{0.0, 0.0}, {6.0, 0.0}, {6.0, 6.0}};
  const Outcome run = ClosedLoop(vehicle(), World(), route).run(40.0);
  EXPECT_TRUE(run.reached_goal);
  EXPECT_NEAR(run.last.x, 6.0, 0.6);
}

TEST_P(BothModels, DrivesAroundAnObstacleOnThePath)
{
  World world;
  world.add_box(5.7, -0.4, 6.3, 0.4);
  const Outcome run = ClosedLoop(vehicle(), world, Waypoints{{0.0, 0.0}, {12.0, 0.0}}).run(40.0);
  EXPECT_TRUE(run.reached_goal);
  EXPECT_FALSE(run.ever_infeasible);
  EXPECT_GT(run.min_clearance, 0.0);
}

TEST_P(BothModels, ChoosesTheOpenSideOfACorridor)
{
  World world;
  world.add_box(-5.0, 1.6, 20.0, 2.0);
  world.add_box(-5.0, -2.0, 20.0, -1.6);
  world.add_box(5.7, -1.6, 6.3, 0.4);
  const Outcome run = ClosedLoop(vehicle(), world, Waypoints{{0.0, 0.0}, {12.0, 0.0}}).run(40.0);
  EXPECT_TRUE(run.reached_goal);
  EXPECT_GT(run.min_clearance, 0.0);
}

TEST_P(BothModels, StopsShortOfAWallThatClosesTheRoute)
{
  World world;
  world.add_box(5.0, -10.0, 5.4, 10.0);
  const Outcome run = ClosedLoop(vehicle(), world, Waypoints{{0.0, 0.0}, {12.0, 0.0}}).run(30.0);
  EXPECT_FALSE(run.reached_goal);
  EXPECT_GT(run.min_clearance, 0.0);
  EXPECT_LT(run.final_speed, 0.1);
}

TEST_P(BothModels, ReportsNoSolutionWhenTheFootprintIsAlreadyInCollision)
{
  World world;
  world.add_box(-0.3, -0.3, 0.3, 0.3);
  const VehicleParams v = vehicle();
  MppiSolver solver(mppi_of(v, 1), cost_params(v), v, footprint_of(v));
  const ReferencePath route(
    Waypoints{{0.0, 0.0}, {12.0, 0.0}}, kRouteSpacing, kCruiseSpeed, kStopDecel);
  State start;
  start.x = v.kinematic_center_x;
  const DistanceMap map = world.distance_map();
  EXPECT_FALSE(solver.solve(start, route, 0, map).feasible);
}

TEST_P(BothModels, ReportsNoSolutionOutsideTheGrid)
{
  const VehicleParams v = vehicle();
  MppiSolver solver(mppi_of(v, 1), cost_params(v), v, footprint_of(v));
  const ReferencePath route(
    Waypoints{{0.0, 0.0}, {12.0, 0.0}}, kRouteSpacing, kCruiseSpeed, kStopDecel);
  State start;
  start.x = 100.0;
  const DistanceMap map = World().distance_map();
  EXPECT_FALSE(solver.solve(start, route, 0, map).feasible);
}

bool collides(
  const VehicleParams & v, const Footprint & footprint, const DistanceMap & map,
  const State & start, const std::vector<double> & plan, double step_sec)
{
  State rollout = start;
  for (std::size_t i = 0; i < plan.size(); i += 2) {
    step(v, {plan[i], plan[i + 1]}, step_sec, &rollout);
    for (const double circle : footprint.circle_x) {
      const double offset = circle - v.kinematic_center_x;
      const double x = rollout.x + offset * std::cos(rollout.yaw);
      const double y = rollout.y + offset * std::sin(rollout.yaw);
      if (map.at(x, y) <= footprint.radius) {
        return true;
      }
    }
  }
  return false;
}

TEST_P(BothModels, TheFilteredPlanIsTheOneCheckedForCollision)
{
  // A tight chicane, where filtering a clear plan bends it into a wall on many cycles: run the
  // check before the filter and this scene keeps colliding plans.
  const VehicleParams v = vehicle();
  const MppiParams mppi = mppi_of(v, 1);
  const Footprint footprint = footprint_of(v);
  World world;
  world.add_box(2.5, -0.3, 3.1, 6.0);
  world.add_box(4.1, -6.0, 4.7, 0.3);
  const DistanceMap map = world.distance_map();
  const ReferencePath route(
    Waypoints{{0.0, 0.0}, {12.0, 0.0}}, kRouteSpacing, kCruiseSpeed, kStopDecel);
  MppiSolver solver(mppi, cost_params(v), v, footprint);

  State state;
  state.x = v.kinematic_center_x;
  int index = 0;
  for (int cycle = 0; cycle < 500; ++cycle) {
    const double x = state.x - v.kinematic_center_x * std::cos(state.yaw);
    const double y = state.y - v.kinematic_center_x * std::sin(state.yaw);
    index = route.advance(index, x, y, 25);
    if (route.at_goal(index, x, y, 0.3)) {
      break;
    }
    const Solution solution = solver.solve(state, route, index, map);
    ASSERT_TRUE(solution.feasible) << "cycle " << cycle;
    ASSERT_FALSE(collides(v, footprint, map, state, solver.plan(), mppi.step_sec))
      << "cycle " << cycle;
    step(v, solution.control, kControlPeriod, &state);
  }
}

INSTANTIATE_TEST_SUITE_P(
  Models, BothModels, ::testing::Values(MotionModel::Ackermann, MotionModel::Diff),
  [](const ::testing::TestParamInfo<MotionModel> & info) {
    return std::string(info.param == MotionModel::Ackermann ? "Ackermann" : "Diff");
  });

TEST_P(BothModels, RolloutFollowsTheKeptPlanFromTheStart)
{
  const VehicleParams v = vehicle();
  const MppiParams m = mppi_of(v, 1);
  MppiSolver solver(m, cost_params(v), v, footprint_of(v));
  const ReferencePath route(
    Waypoints{{0.0, 0.0}, {10.0, 0.0}}, kRouteSpacing, kCruiseSpeed, kStopDecel);
  State start;
  start.speed = 0.5;
  ASSERT_TRUE(solver.solve(start, route, 0, World().distance_map()).feasible);

  std::vector<State> states;
  solver.rollout(start, &states);
  ASSERT_EQ(states.size(), std::size_t(m.horizon_steps) + 1);
  EXPECT_EQ(states.front().x, start.x);
  EXPECT_EQ(states.front().speed, start.speed);
  State expected = start;
  for (int t = 0; t < m.horizon_steps; ++t) {
    step(v, {solver.plan()[2 * t], solver.plan()[2 * t + 1]}, m.step_sec, &expected);
  }
  EXPECT_DOUBLE_EQ(states.back().x, expected.x);
  EXPECT_DOUBLE_EQ(states.back().y, expected.y);
  EXPECT_GT(states.back().x, 1.0);
}

TEST(Ackermann, NeverCommandsATighterCircleThanTheVehicleCanDrive)
{
  World world;
  world.add_box(5.7, -0.4, 6.3, 0.4);
  const VehicleParams v = hunter();
  const Outcome run = ClosedLoop(v, world, Waypoints{{0.0, 0.0}, {12.0, 0.0}}).run(40.0);
  EXPECT_LE(run.max_curvature, std::tan(v.max_steer) / v.wheelbase + 1e-9);
}

// The poses of the stall: heading more than 90 degrees off a route in open space.
class OffRouteStart : public ::testing::TestWithParam<std::array<double, 3>>
{
};

TEST_P(OffRouteStart, AckermannTurnsBackOntoTheRoute)
{
  const auto [x, y, yaw] = GetParam();
  ClosedLoop loop(hunter(), World(), Waypoints{{0.0, 0.0}, {15.0, 0.0}});
  loop.place(x, y, yaw);
  EXPECT_TRUE(loop.run(60.0).reached_goal);
}

TEST_P(OffRouteStart, DiffTurnsBackOntoTheRoute)
{
  const auto [x, y, yaw] = GetParam();
  ClosedLoop loop(diff_base(), World(), Waypoints{{0.0, 0.0}, {15.0, 0.0}});
  loop.place(x, y, yaw);
  EXPECT_TRUE(loop.run(60.0).reached_goal);
}

INSTANTIATE_TEST_SUITE_P(
  Poses, OffRouteStart,
  ::testing::Values(
    std::array<double, 3>{0.0, 0.0, M_PI}, std::array<double, 3>{3.0, 2.0, 2.5},
    std::array<double, 3>{3.0, -2.0, -2.5}, std::array<double, 3>{5.0, 3.0, 1.8}));

}  // namespace
}  // namespace simple_mppi_planner

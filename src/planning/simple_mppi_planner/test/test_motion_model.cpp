#include "motion_model.hpp"
#include "scene.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace simple_mppi_planner
{
namespace
{

TEST(MotionModel, AckermannTurnsAtTheBicycleRadius)
{
  const VehicleParams v = hunter();
  State s;
  s.speed = 1.0;
  s.turn = 0.461;
  // A steady circle at full lock: 2 pi r of travel closes it.
  const double radius = v.wheelbase / std::tan(v.max_steer);
  const double dt = 0.001;
  const int steps = static_cast<int>(2.0 * M_PI * radius / dt);
  for (int i = 0; i < steps; ++i) {
    step(v, {1.0, 0.461}, dt, &s);
  }
  EXPECT_NEAR(radius, 1.31, 0.01);
  EXPECT_NEAR(s.yaw, 2.0 * M_PI, 0.01);
  EXPECT_NEAR(s.x, 0.0, 0.01);
  EXPECT_NEAR(s.y, 0.0, 0.01);
}

TEST(MotionModel, AckermannSteeringLagsItsCommand)
{
  const VehicleParams v = hunter();
  State s;
  for (int i = 0; i < 20; ++i) {
    step(v, {0.0, 0.4}, 0.01, &s);
  }
  EXPECT_NEAR(s.turn, 0.4 * (1.0 - std::exp(-1.0)), 0.01);
  EXPECT_EQ(s.yaw, 0.0);
}

TEST(MotionModel, DiffTurnsInPlaceWithinItsAngularAcceleration)
{
  const VehicleParams v = diff_base();
  State s;
  step(v, {0.0, 1.0}, 0.1, &s);
  EXPECT_NEAR(s.turn, 0.3, 1e-9);
  EXPECT_NEAR(s.yaw, 0.03, 1e-9);
  EXPECT_EQ(s.x, 0.0);
}

TEST(MotionModel, SpeedFollowsTheAccelerationLimits)
{
  const VehicleParams v = diff_base();
  State s;
  step(v, {1.5, 0.0}, 0.1, &s);
  EXPECT_NEAR(s.speed, 0.08, 1e-9);
  s.speed = 1.0;
  step(v, {0.0, 0.0}, 0.1, &s);
  EXPECT_NEAR(s.speed, 0.9, 1e-9);
}

TEST(MotionModel, AckermannTwistIsAYawRateOfTheBicycle)
{
  const VehicleParams v = hunter();
  const Twist2d twist = to_twist(v, {1.0, 0.3});
  EXPECT_EQ(twist.linear, 1.0);
  EXPECT_NEAR(twist.angular, std::tan(0.3) / 0.65, 1e-12);
  EXPECT_EQ(to_twist(v, {0.0, 0.3}).angular, 0.0);
}

TEST(MotionModel, DiffTwistPassesThrough)
{
  const Twist2d twist = to_twist(diff_base(), {0.5, 0.7});
  EXPECT_EQ(twist.linear, 0.5);
  EXPECT_EQ(twist.angular, 0.7);
}

TEST(MotionModel, MeasuredTurnInvertsTheTwist)
{
  const VehicleParams v = hunter();
  const Twist2d twist = to_twist(v, {1.2, -0.3});
  EXPECT_NEAR(measured_turn(v, twist.linear, twist.angular, 0.1), -0.3, 1e-9);
  EXPECT_EQ(measured_turn(v, 0.05, 0.1, 0.1), 0.0);
  EXPECT_EQ(measured_turn(v, 0.2, 5.0, 0.1), v.max_steer);
  EXPECT_EQ(measured_turn(diff_base(), 0.0, 0.7, 0.1), 0.7);
}

}  // namespace
}  // namespace simple_mppi_planner

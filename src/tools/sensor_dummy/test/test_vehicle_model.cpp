#include "vehicle_model.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace sensor_dummy
{
namespace
{
constexpr double time_step = 0.005;

VehicleParams hunter_v2(MotionModel model)
{
  return {model, 0.605, 0.650, -0.28, 0.58, 1.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
}

void run(VehicleModel & vehicle, double start, double duration)
{
  const int steps = static_cast<int>(duration / time_step);
  for (int i = 0; i < steps; ++i) {
    vehicle.step(start + i * time_step, time_step);
  }
}

TEST(SteerTest, MatchesMessengerFormulas)
{
  EXPECT_DOUBLE_EQ(twist_to_inner_steer(1.0, 0.0, 0.65, 0.605, 0.58), 0.0);
  // radius 2: atan(l / (r - w / 2))
  EXPECT_NEAR(twist_to_inner_steer(1.0, 0.5, 0.65, 0.605, 0.58), std::atan(0.65 / 1.6975), 1e-12);
  EXPECT_NEAR(twist_to_inner_steer(1.0, -0.5, 0.65, 0.605, 0.58), -std::atan(0.65 / 1.6975), 1e-12);
  EXPECT_NEAR(twist_to_inner_steer(-1.0, 0.5, 0.65, 0.605, 0.58), -std::atan(0.65 / 1.6975), 1e-12);
  // radius below the wheelbase, zero speed included: full lock.
  EXPECT_DOUBLE_EQ(twist_to_inner_steer(0.0, 0.5, 0.65, 0.605, 0.58), 0.58);
}

TEST(SteerTest, InnerAtLockGivesCentralLockOfHunterParams)
{
  EXPECT_NEAR(inner_to_central_steer(0.58, 0.65, 0.605), 0.461, 0.01);
  EXPECT_DOUBLE_EQ(inner_to_central_steer(0.001, 0.65, 0.605), 0.0);
}

TEST(VehicleModelTest, StraightLineSpeedIsClampedToMaximum)
{
  VehicleModel vehicle(hunter_v2(MotionModel::Ackermann), {1.0, 2.0, 0.0});
  vehicle.command(0.0, 5.0, 0.0);
  run(vehicle, 0.0, 1.0);
  EXPECT_NEAR(vehicle.base_pose().x, 2.5, 0.02);
  EXPECT_DOUBLE_EQ(vehicle.base_pose().y, 2.0);
  EXPECT_DOUBLE_EQ(vehicle.speed(), 1.5);
}

TEST(VehicleModelTest, AckermannYawRateFollowsTheCommand)
{
  VehicleModel vehicle(hunter_v2(MotionModel::Ackermann), {0.0, 0.0, 0.0});
  vehicle.command(0.0, 1.0, 0.5);
  run(vehicle, 0.0, 1.0);
  EXPECT_NEAR(vehicle.yaw_rate(), 0.5, 1e-9);
  EXPECT_NEAR(vehicle.base_pose().yaw, 0.5, 0.01);
}

TEST(VehicleModelTest, AckermannSteeringIsLimited)
{
  VehicleModel vehicle(hunter_v2(MotionModel::Ackermann), {0.0, 0.0, 0.0});
  vehicle.command(0.0, 0.1, 2.0);
  run(vehicle, 0.0, 0.5);
  EXPECT_NEAR(vehicle.steering(), inner_to_central_steer(0.58, 0.65, 0.605), 1e-9);
}

TEST(VehicleModelTest, BaseLinkSwingsWideOfTheRearAxle)
{
  VehicleModel vehicle(hunter_v2(MotionModel::Ackermann), {0.0, 0.0, 0.0});
  vehicle.command(0.0, 1.0, 0.5);
  run(vehicle, 0.0, std::acos(-1.0) / 0.5);  // half a turn of radius 2
  const Pose2d pose = vehicle.base_pose();
  // The rear axle reaches (-0.28, 4); base_link is 0.28 ahead of it, now pointing -x.
  EXPECT_NEAR(pose.x, -0.56, 0.05);
  EXPECT_NEAR(pose.y, 4.0, 0.05);
}

TEST(VehicleModelTest, DiffTurnsOnTheSpot)
{
  VehicleModel vehicle(hunter_v2(MotionModel::Diff), {0.0, 0.0, 0.0});
  vehicle.command(0.0, 0.0, 1.0);
  run(vehicle, 0.0, 1.0);
  EXPECT_DOUBLE_EQ(vehicle.base_pose().x, 0.0);
  EXPECT_NEAR(vehicle.base_pose().yaw, 1.0, 0.01);
}

TEST(VehicleModelTest, DelayHoldsTheCommandBack)
{
  VehicleParams params = hunter_v2(MotionModel::Ackermann);
  params.cmd_delay_s = 0.1;
  VehicleModel vehicle(params, {0.0, 0.0, 0.0});
  vehicle.command(0.0, 1.0, 0.0);
  vehicle.step(0.095, time_step);
  EXPECT_DOUBLE_EQ(vehicle.speed(), 0.0);
  vehicle.step(0.1, time_step);
  EXPECT_DOUBLE_EQ(vehicle.speed(), 1.0);
}

TEST(VehicleModelTest, SpeedLagReachesSixtyThreePercentInOneTau)
{
  VehicleParams params = hunter_v2(MotionModel::Ackermann);
  params.speed_tau_s = 0.3;
  VehicleModel vehicle(params, {0.0, 0.0, 0.0});
  vehicle.command(0.0, 1.0, 0.0);
  run(vehicle, 0.0, 0.3);
  EXPECT_NEAR(vehicle.speed(), 1.0 - std::exp(-1.0), 0.01);
}

TEST(DeadBandTest, ZeroesInsideTheBandAndPassesOutside)
{
  EXPECT_DOUBLE_EQ(apply_dead_band(0.09, 0.1), 0.0);
  EXPECT_DOUBLE_EQ(apply_dead_band(-0.09, 0.1), 0.0);
  EXPECT_DOUBLE_EQ(apply_dead_band(0.1, 0.1), 0.1);
  EXPECT_DOUBLE_EQ(apply_dead_band(-0.5, 0.1), -0.5);
  EXPECT_DOUBLE_EQ(apply_dead_band(0.001, 0.0), 0.001);
}

TEST(VehicleModelTest, SpeedDeadBandHoldsTheVehicleAtRest)
{
  for (const MotionModel model : {MotionModel::Ackermann, MotionModel::Diff}) {
    VehicleParams params = hunter_v2(model);
    params.speed_dead_band_mps = 0.2;
    VehicleModel vehicle(params, {0.0, 0.0, 0.0});
    vehicle.command(0.0, 0.15, 0.0);
    run(vehicle, 0.0, 1.0);
    EXPECT_DOUBLE_EQ(vehicle.speed(), 0.0);
    vehicle.command(1.0, 0.25, 0.0);
    run(vehicle, 1.0, 1.0);
    EXPECT_DOUBLE_EQ(vehicle.speed(), 0.25);
  }
}

TEST(VehicleModelTest, SteerDeadBandKeepsTheWheelsCentered)
{
  VehicleParams params = hunter_v2(MotionModel::Ackermann);
  params.steer_dead_band_rad = 0.1;
  VehicleModel vehicle(params, {0.0, 0.0, 0.0});
  // Radius 20: well under 0.1 rad of steering.
  vehicle.command(0.0, 1.0, 0.05);
  run(vehicle, 0.0, 1.0);
  EXPECT_DOUBLE_EQ(vehicle.steering(), 0.0);
  EXPECT_DOUBLE_EQ(vehicle.yaw_rate(), 0.0);
  vehicle.command(1.0, 1.0, 0.5);
  run(vehicle, 1.0, 1.0);
  EXPECT_GT(vehicle.steering(), 0.1);
}

TEST(VehicleModelTest, SteerBiasCurvesAStraightCommand)
{
  VehicleParams params = hunter_v2(MotionModel::Ackermann);
  params.steer_bias_rad = 0.05;
  VehicleModel vehicle(params, {0.0, 0.0, 0.0});
  vehicle.command(0.0, 1.0, 0.0);
  run(vehicle, 0.0, 1.0);
  EXPECT_DOUBLE_EQ(vehicle.steering(), 0.05);
  EXPECT_NEAR(vehicle.yaw_rate(), std::tan(0.05) / 0.65, 1e-12);
  EXPECT_GT(vehicle.base_pose().y, 0.0);
}

TEST(VehicleModelTest, SteerBiasActsOnTheLaggedTargetBehindTheDeadBand)
{
  VehicleParams params = hunter_v2(MotionModel::Ackermann);
  params.steer_dead_band_rad = 0.1;
  params.steer_bias_rad = -0.05;
  params.steer_tau_s = 0.2;
  VehicleModel vehicle(params, {0.0, 0.0, 0.0});
  vehicle.command(0.0, 1.0, 0.05);
  run(vehicle, 0.0, 0.2);
  EXPECT_NEAR(vehicle.steering(), -0.05 * (1.0 - std::exp(-1.0)), 1e-3);
}

TEST(MotionModelTest, RejectsUnknownName)
{
  EXPECT_EQ(parse_motion_model("diff"), MotionModel::Diff);
  EXPECT_THROW(parse_motion_model("tracked"), std::invalid_argument);
}

}  // namespace
}  // namespace sensor_dummy

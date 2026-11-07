#include "imu_model.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace sensor_dummy
{
namespace
{
const Eigen::Quaterniond kVectornavMount(Eigen::AngleAxisd(-M_PI / 2.0, Eigen::Vector3d::UnitZ()));

TEST(ImuModelTest, StandingStillReadsGravityUp)
{
  const ImuSample sample = sample_imu(0.0, 0.0, 0.0, 0.0, 9.8, kVectornavMount);
  EXPECT_NEAR(sample.linear_acceleration.z(), 9.8, 1e-9);
  EXPECT_NEAR(sample.linear_acceleration.norm(), 9.8, 1e-9);
}

TEST(ImuModelTest, ForwardIsPlusYOfTheRightForwardUpFrame)
{
  const ImuSample sample = sample_imu(0.0, 0.0, 1.0, 0.0, 9.8, kVectornavMount);
  EXPECT_NEAR(sample.linear_acceleration.y(), 1.0, 1e-9);
  EXPECT_NEAR(sample.linear_acceleration.x(), 0.0, 1e-9);
}

TEST(ImuModelTest, LeftIsMinusXOfTheRightForwardUpFrame)
{
  const ImuSample sample = sample_imu(0.0, 0.3, 0.0, 1.0, 9.8, kVectornavMount);
  EXPECT_NEAR(sample.linear_acceleration.x(), -1.0, 1e-9);
  EXPECT_NEAR(sample.angular_velocity.z(), 0.3, 1e-9);
}

TEST(ImuModelTest, OrientationTakesTheMountIntoEnu)
{
  const ImuSample sample = sample_imu(M_PI / 2.0, 0.0, 0.0, 0.0, 9.8, kVectornavMount);
  // base_link points north; the sensor's y (forward) must too.
  const Eigen::Vector3d forward = sample.orientation * Eigen::Vector3d::UnitY();
  EXPECT_NEAR(forward.y(), 1.0, 1e-9);
}

TEST(ImuModelTest, EcefAttitudeMatchesTheDriverAtZeroLatLon)
{
  // lat = lon = 0: NED north is ECEF +z, east is +y, down is -x. RFU up is then ECEF +x.
  const Eigen::Quaterniond level(Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitZ()));
  const Eigen::Vector3d up = rfu_to_ecef(level, 0.0, 0.0) * Eigen::Vector3d::UnitZ();
  EXPECT_NEAR(up.x(), 1.0, 1e-9);
  const Eigen::Vector3d forward = rfu_to_ecef(level, 0.0, 0.0) * Eigen::Vector3d::UnitY();
  EXPECT_NEAR(forward.z(), 1.0, 1e-9);
}

}  // namespace
}  // namespace sensor_dummy

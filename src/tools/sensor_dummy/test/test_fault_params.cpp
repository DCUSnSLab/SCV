#include "fault_params.hpp"

#include <gtest/gtest.h>

#include <stdexcept>

namespace sensor_dummy
{
namespace
{

TEST(UpdateFaultTest, ChangesOnlyTheNamedField)
{
  FaultSpec spec{FaultMode::None, 0.0};
  EXPECT_TRUE(update_fault(spec, "fault.imu", rclcpp::Parameter("fault.imu.mode", "latency")));
  EXPECT_EQ(spec.mode, FaultMode::Latency);
  EXPECT_DOUBLE_EQ(spec.latency_s, 0.0);
  EXPECT_TRUE(update_fault(spec, "fault.imu", rclcpp::Parameter("fault.imu.latency_s", 0.4)));
  EXPECT_EQ(spec.mode, FaultMode::Latency);
  EXPECT_DOUBLE_EQ(spec.latency_s, 0.4);
}

TEST(UpdateFaultTest, IgnoresOtherPrefixes)
{
  FaultSpec spec{FaultMode::None, 0.0};
  EXPECT_FALSE(update_fault(spec, "fault.imu", rclcpp::Parameter("fault.gnss.mode", "nan")));
  EXPECT_FALSE(update_fault(spec, "fault.imu", rclcpp::Parameter("imu.rate_hz", 200.0)));
  EXPECT_EQ(spec.mode, FaultMode::None);
}

TEST(UpdateFaultTest, ThrowsOnAnUnknownMode)
{
  FaultSpec spec{FaultMode::None, 0.0};
  EXPECT_THROW(
    update_fault(spec, "fault.imu", rclcpp::Parameter("fault.imu.mode", "melt")),
    std::invalid_argument);
}

}  // namespace
}  // namespace sensor_dummy

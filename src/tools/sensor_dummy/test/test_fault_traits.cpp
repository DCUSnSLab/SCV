#include "fault_traits.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <cstring>
#include <vector>

namespace sensor_dummy
{
namespace
{

float float_at(const std::vector<std::uint8_t> & data, std::size_t offset)
{
  float value = 0.0F;
  std::memcpy(&value, &data[offset], sizeof(value));
  return value;
}

TEST(PoisonTest, CloudLosesXyzAndKeepsTheOtherFields)
{
  sensor_msgs::msg::PointCloud2 cloud;
  cloud.point_step = 16;
  cloud.data.assign(2 * cloud.point_step, 0);
  const float intensity = 7.0F;
  std::memcpy(&cloud.data[16 + 12], &intensity, sizeof(intensity));
  poison(cloud);
  for (std::size_t offset : {0u, 4u, 8u, 16u, 20u, 24u}) {
    EXPECT_TRUE(std::isnan(float_at(cloud.data, offset))) << offset;
  }
  EXPECT_FLOAT_EQ(float_at(cloud.data, 16 + 12), intensity);
}

TEST(PoisonTest, FloatImageTurnsNanAndIntegerImageTurnsZero)
{
  sensor_msgs::msg::Image depth;
  depth.encoding = "32FC1";
  depth.data.assign(8, 1);
  poison(depth);
  EXPECT_TRUE(std::isnan(float_at(depth.data, 0)));
  EXPECT_TRUE(std::isnan(float_at(depth.data, 4)));

  sensor_msgs::msg::Image color;
  color.encoding = "rgb8";
  color.data.assign(6, 200);
  poison(color);
  for (const auto byte : color.data) {
    EXPECT_EQ(byte, 0);
  }
}

TEST(PoisonTest, PoseAndTwistTurnNan)
{
  nav_msgs::msg::Odometry odom;
  poison(odom);
  EXPECT_TRUE(std::isnan(odom.pose.pose.position.x));
  EXPECT_TRUE(std::isnan(odom.pose.pose.orientation.w));
  EXPECT_TRUE(std::isnan(odom.twist.twist.linear.x));
  EXPECT_TRUE(std::isnan(odom.twist.twist.angular.z));

  sensor_msgs::msg::Imu imu;
  poison(imu);
  EXPECT_TRUE(std::isnan(imu.orientation.w));
  EXPECT_TRUE(std::isnan(imu.angular_velocity.z));
  EXPECT_TRUE(std::isnan(imu.linear_acceleration.x));

  sensor_msgs::msg::NavSatFix fix;
  poison(fix);
  EXPECT_TRUE(std::isnan(fix.latitude));
  EXPECT_TRUE(std::isnan(fix.altitude));

  tf2_msgs::msg::TFMessage tf;
  tf.transforms.resize(2);
  poison(tf);
  EXPECT_TRUE(std::isnan(tf.transforms[1].transform.translation.y));
}

TEST(PoisonTest, UbloxMessagesReportAnInvalidFix)
{
  ublox_msgs::msg::NavPVT pvt;
  pvt.fix_type = ublox_msgs::msg::NavPVT::FIX_TYPE_3D;
  pvt.flags = ublox_msgs::msg::NavPVT::FLAGS_GNSS_FIX_OK;
  poison(pvt);
  EXPECT_EQ(pvt.fix_type, ublox_msgs::msg::NavPVT::FIX_TYPE_NO_FIX);
  EXPECT_EQ(pvt.flags, 0);

  ublox_msgs::msg::RxmRTCM rtcm;
  poison(rtcm);
  EXPECT_TRUE(rtcm.flags & ublox_msgs::msg::RxmRTCM::FLAGS_CRC_FAILED);
}

TEST(CopyStampTest, TfMessageCopiesEachTransformStamp)
{
  tf2_msgs::msg::TFMessage live;
  live.transforms.resize(2);
  live.transforms[0].header.stamp.sec = 3;
  live.transforms[1].header.stamp.sec = 4;
  tf2_msgs::msg::TFMessage frozen;
  frozen.transforms.resize(2);
  copy_stamp(frozen, live);
  EXPECT_EQ(frozen.transforms[0].header.stamp.sec, 3);
  EXPECT_EQ(frozen.transforms[1].header.stamp.sec, 4);
}

}  // namespace
}  // namespace sensor_dummy

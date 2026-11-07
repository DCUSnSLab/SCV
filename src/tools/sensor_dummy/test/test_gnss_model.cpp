#include "gnss_model.hpp"

#include <GeographicLib/UTMUPS.hpp>

#include <gtest/gtest.h>

#include <cmath>

namespace sensor_dummy
{
namespace
{
constexpr double kLat = 35.9138453975;
constexpr double kLon = 128.8035838978;

TEST(GnssModelTest, OriginMapsToTheDatum)
{
  const Geodetic origin = GnssModel(kLat, kLon, 10.0).to_geodetic({0.0, 0.0, 0.5});
  EXPECT_NEAR(origin.latitude, kLat, 1e-9);
  EXPECT_NEAR(origin.longitude, kLon, 1e-9);
  EXPECT_DOUBLE_EQ(origin.altitude, 10.5);
}

TEST(GnssModelTest, MapMetersAreUtmMeters)
{
  const Geodetic there = GnssModel(kLat, kLon, 0.0).to_geodetic({100.0, 50.0, 0.0});
  int zone = 0;
  bool northp = false;
  double e0 = 0.0, n0 = 0.0, e1 = 0.0, n1 = 0.0;
  GeographicLib::UTMUPS::Forward(kLat, kLon, zone, northp, e0, n0);
  GeographicLib::UTMUPS::Forward(there.latitude, there.longitude, zone, northp, e1, n1);
  EXPECT_NEAR(e1 - e0, 100.0, 1e-6);
  EXPECT_NEAR(n1 - n0, 50.0, 1e-6);
}

TEST(GnssModelTest, ConvergenceIsTheNavsatDatumYaw)
{
  EXPECT_NEAR(GnssModel(kLat, kLon, 0.0).map_to_enu_yaw(), 0.00201082, 1e-6);
}

TEST(GnssModelTest, VectorsRotateIntoTrueEnu)
{
  const GnssModel model(kLat, kLon, 0.0);
  const Eigen::Vector2d enu = model.map_to_enu({1.0, 0.0});
  EXPECT_NEAR(enu.y(), std::sin(model.map_to_enu_yaw()), 1e-12);
}

TEST(UtcTimeTest, SplitsAKnownInstant)
{
  // 2026-11-07 00:00:00.25 UTC is a Saturday: the last day of the GPS week.
  const UtcTime utc = utc_time(1794009600LL * 1000000000LL + 250000000LL);
  EXPECT_EQ(utc.year, 2026);
  EXPECT_EQ(utc.month, 11);
  EXPECT_EQ(utc.day, 7);
  EXPECT_EQ(utc.hour, 0);
  EXPECT_EQ(utc.nano, 250000000);
  EXPECT_EQ(utc.tow_ms, 6u * 86400000u + 18000u + 250u);
}

}  // namespace
}  // namespace sensor_dummy

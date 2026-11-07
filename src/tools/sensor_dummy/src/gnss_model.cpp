#include "gnss_model.hpp"

#include <GeographicLib/UTMUPS.hpp>

#include <cmath>
#include <ctime>

namespace sensor_dummy
{
namespace
{
constexpr std::int64_t kGpsEpochUnix = 315964800;
constexpr std::int64_t kGpsLeapSeconds = 18;
constexpr std::int64_t kSecondsPerWeek = 604800;
}  // namespace

GnssModel::GnssModel(double latitude, double longitude, double altitude) : altitude_(altitude)
{
  double convergence_deg = 0.0;
  double scale = 0.0;
  GeographicLib::UTMUPS::Forward(
    latitude, longitude, zone_, northp_, origin_easting_, origin_northing_, convergence_deg, scale);
  // GeographicLib gives grid north clockwise from true north.
  map_to_enu_yaw_ = -convergence_deg * M_PI / 180.0;
}

Geodetic GnssModel::to_geodetic(const Eigen::Vector3d & map_position) const
{
  Geodetic out{};
  GeographicLib::UTMUPS::Reverse(
    zone_, northp_, origin_easting_ + map_position.x(), origin_northing_ + map_position.y(),
    out.latitude, out.longitude);
  out.altitude = altitude_ + map_position.z();
  return out;
}

Eigen::Vector2d GnssModel::map_to_enu(const Eigen::Vector2d & vector) const
{
  const double c = std::cos(map_to_enu_yaw_);
  const double s = std::sin(map_to_enu_yaw_);
  return {c * vector.x() - s * vector.y(), s * vector.x() + c * vector.y()};
}

UtcTime utc_time(std::int64_t unix_ns)
{
  const std::time_t seconds = unix_ns / 1000000000;
  std::tm utc{};
  gmtime_r(&seconds, &utc);
  const std::int64_t gps_seconds = (seconds - kGpsEpochUnix + kGpsLeapSeconds) % kSecondsPerWeek;
  const auto nano = static_cast<std::int32_t>(unix_ns % 1000000000);
  return {
    static_cast<std::uint16_t>(utc.tm_year + 1900),
    static_cast<std::uint8_t>(utc.tm_mon + 1),
    static_cast<std::uint8_t>(utc.tm_mday),
    static_cast<std::uint8_t>(utc.tm_hour),
    static_cast<std::uint8_t>(utc.tm_min),
    static_cast<std::uint8_t>(utc.tm_sec),
    nano,
    static_cast<std::uint32_t>(gps_seconds * 1000 + nano / 1000000)};
}

}  // namespace sensor_dummy

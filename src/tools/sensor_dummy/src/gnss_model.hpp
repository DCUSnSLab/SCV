#ifndef GNSS_MODEL_HPP_
#define GNSS_MODEL_HPP_

#include <Eigen/Core>

#include <cstdint>

namespace sensor_dummy
{

struct Geodetic
{
  double latitude;
  double longitude;
  double altitude;
};

struct UtcTime
{
  std::uint16_t year;
  std::uint8_t month;
  std::uint8_t day;
  std::uint8_t hour;
  std::uint8_t minute;
  std::uint8_t second;
  std::int32_t nano;
  std::uint32_t tow_ms;  // GPS time of week
};

// The real map is UTM minus the origin, unrotated (navsat_transform.param.yaml). Converting through
// UTM keeps the grid scale and the meridian convergence, which navsat_transform undoes.
class GnssModel
{
public:
  GnssModel(double latitude, double longitude, double altitude);

  Geodetic to_geodetic(const Eigen::Vector3d & map_position) const;
  // Heading in true ENU minus heading in the map. navsat datum yaw has the same value.
  double map_to_enu_yaw() const { return map_to_enu_yaw_; }
  Eigen::Vector2d map_to_enu(const Eigen::Vector2d & vector) const;

private:
  int zone_;
  bool northp_;
  double origin_easting_;
  double origin_northing_;
  double altitude_;
  double map_to_enu_yaw_;
};

UtcTime utc_time(std::int64_t unix_ns);

}  // namespace sensor_dummy

#endif  // GNSS_MODEL_HPP_

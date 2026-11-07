#include "imu_model.hpp"

#include <cmath>

namespace sensor_dummy
{

ImuSample sample_imu(
  double yaw_enu, double yaw_rate, double accel_forward, double accel_left, double gravity,
  const Eigen::Quaterniond & base_to_sensor)
{
  const Eigen::Quaterniond base_to_enu(Eigen::AngleAxisd(yaw_enu, Eigen::Vector3d::UnitZ()));
  const Eigen::Matrix3d sensor_from_base = base_to_sensor.toRotationMatrix().transpose();
  return {
    base_to_enu * base_to_sensor, sensor_from_base * Eigen::Vector3d(0.0, 0.0, yaw_rate),
    sensor_from_base * Eigen::Vector3d(accel_forward, accel_left, gravity)};
}

Eigen::Quaterniond rfu_to_ecef(
  const Eigen::Quaterniond & rfu_to_enu, double latitude_rad, double longitude_rad)
{
  const Eigen::Vector3d swap_axis = Eigen::Vector3d(1.0, 1.0, 0.0).normalized();
  const Eigen::Quaterniond ned_to_enu(Eigen::AngleAxisd(M_PI, swap_axis));
  const Eigen::Quaterniond rfu_to_frd(Eigen::AngleAxisd(M_PI, swap_axis));
  const Eigen::Quaterniond frd_to_ned = ned_to_enu.inverse() * rfu_to_enu * rfu_to_frd.inverse();
  const Eigen::Quaterniond ned_to_ecef =
    Eigen::Quaterniond(Eigen::AngleAxisd(longitude_rad, Eigen::Vector3d::UnitZ())) *
    Eigen::Quaterniond(Eigen::AngleAxisd(-M_PI / 2.0 - latitude_rad, Eigen::Vector3d::UnitY()));
  return ned_to_ecef * frd_to_ned * rfu_to_frd;
}

}  // namespace sensor_dummy

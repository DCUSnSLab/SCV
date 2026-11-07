#ifndef IMU_MODEL_HPP_
#define IMU_MODEL_HPP_

#include <Eigen/Geometry>

namespace sensor_dummy
{

struct ImuSample
{
  Eigen::Quaterniond orientation;  // sensor frame to ENU
  Eigen::Vector3d angular_velocity;
  Eigen::Vector3d linear_acceleration;
};

// Body motion on the plane as a level sensor sees it. yaw_enu is the base_link heading in ENU.
ImuSample sample_imu(
  double yaw_enu, double yaw_rate, double accel_forward, double accel_left, double gravity,
  const Eigen::Quaterniond & base_to_sensor);

// vn_sensor_msgs.cc "Pose": the attitude as sensor to ECEF, with use_enu true.
Eigen::Quaterniond rfu_to_ecef(
  const Eigen::Quaterniond & rfu_to_enu, double latitude_rad, double longitude_rad);

}  // namespace sensor_dummy

#endif  // IMU_MODEL_HPP_

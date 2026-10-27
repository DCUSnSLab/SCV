#ifndef SCV_LOCALIZATION__ODOMETRY_ESTIMATOR_HPP_
#define SCV_LOCALIZATION__ODOMETRY_ESTIMATOR_HPP_

#include <array>
#include <eigen3/Eigen/Dense>

namespace loam_fgo_localization
{

// local odom output (odom frame, pose/twist of base_link).
struct OdomOutput
{
  Eigen::Vector3d position{0.0, 0.0, 0.0};
  Eigen::Quaterniond orientation{1.0, 0.0, 0.0, 0.0};
  Eigen::Vector3d velocity_body{0.0, 0.0, 0.0};
  double yaw_rate{0.0};
  std::array<double, 36> pose_cov{};
  std::array<double, 36> twist_cov{};
};

// Common estimator interface so the node can swap implementations
// (2D gyro-odometry <-> ESKF) without changing ROS I/O.
// Inputs are already in the base_link frame (node applies the IMU extrinsic).
class OdometryEstimator
{
public:
  virtual ~OdometryEstimator() = default;

  virtual void setSpeed(double forward_speed_mps) = 0;

  // High-rate (IMU) step. Returns true when the state advanced (= publish time).
  virtual bool update(
    double t,
    const Eigen::Quaterniond & q_bl,
    const Eigen::Vector3d & gyro_bl,
    const Eigen::Vector3d & acc_bl) = 0;

  virtual const OdomOutput & output() const = 0;
};

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__ODOMETRY_ESTIMATOR_HPP_

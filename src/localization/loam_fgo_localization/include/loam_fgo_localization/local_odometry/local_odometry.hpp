#ifndef SCV_LOCALIZATION__LOCAL_ODOMETRY_HPP_
#define SCV_LOCALIZATION__LOCAL_ODOMETRY_HPP_

#include "loam_fgo_localization/local_odometry/odometry_estimator.hpp"

namespace loam_fgo_localization
{

// 2D gyro-odometry baseline (pipeline-through estimator).
//   heading : integrate gyro z (or IMU absolute yaw if use_imu_orientation)
//   position: integrate wheel forward speed (nonholonomic)
//   odom convention: starts at origin (0,0), yaw 0.
class LocalOdometry : public OdometryEstimator
{
public:
  struct Params
  {
    double wheel_scale{1.0};
    bool use_imu_orientation{false};  // false = gyro integration, true = IMU absolute yaw (offset removed)
    double max_dt{0.5};
    double k_pos{0.02};
    double k_yaw{1.0e-5};
  };

  explicit LocalOdometry(const Params & p);

  void setSpeed(double forward_speed_mps) override {speed_ = forward_speed_mps;}
  bool update(
    double t,
    const Eigen::Quaterniond & q_bl,
    const Eigen::Vector3d & gyro_bl,
    const Eigen::Vector3d & acc_bl) override;
  const OdomOutput & output() const override {return out_;}

private:
  Params params_;
  double last_t_{-1.0};
  double speed_{0.0};

  double x_{0.0};
  double y_{0.0};
  double yaw_{0.0};
  double yaw0_{0.0};
  bool yaw0_set_{false};

  double pos_var_{1.0e-4};
  double yaw_var_{1.0e-4};

  OdomOutput out_;
};

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__LOCAL_ODOMETRY_HPP_

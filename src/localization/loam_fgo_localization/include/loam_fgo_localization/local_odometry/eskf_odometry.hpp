#ifndef SCV_LOCALIZATION__ESKF_ODOMETRY_HPP_
#define SCV_LOCALIZATION__ESKF_ODOMETRY_HPP_

#include <deque>

#include "loam_fgo_localization/local_odometry/odometry_estimator.hpp"

namespace loam_fgo_localization
{

// Error-State Kalman Filter (wheel-inertial), 15-state.
//   nominal : p(3), v(3), q(orientation body->world), b_g(3), b_a(3)
//   error   : dp, dv, dtheta(local/body error), db_g, db_a   -> 15
//   wheel scale s : OFFLINE-calibrated constant (params_.wheel_scale), NOT a state.
//
//   predict : IMU mechanization  (gyro->q, gravity-compensated accel->v,p) + covariance propagation
//   update  : body velocity  [s*v_wheel, 0, 0]  (wheel forward + NHC lateral/vertical=0)
//             ZUPT (v=0) + ZARU (omega=0) on stationary detection (triple condition)
class EskfOdometry : public OdometryEstimator
{
public:
  struct Params
  {
    double wheel_scale{1.0};          // offline-calibrated constant
    double max_dt{0.5};
    double gravity{9.80665};
    bool planar{true};                // pin z position & vertical velocity to 0 (ground robot)
    bool stationary_hold{true};       // when stationary, freeze pose (no integration) -> zero at-rest drift
    bool zaru_enable{true};           // estimate gyro bias at rest (ZARU). DISABLE in sim: sim gyro
                                      // bias ~0, and imperfect stops make ZARU grab spurious bias
                                      // that corrupts yaw over long runs. Keep ON for real IMU.

    // Process noise. gyro_noise = VN-100 density; accel_noise INFLATED by tuning
    // (grid search) -> larger Q_v lets the wheel correct velocity faster (removes the
    // velocity-tracking lag that caused residual position error on curves).
    double gyro_noise{6.1e-5};        // rad/s/sqrt(Hz)
    double accel_noise{0.05};         // TUNED (was 1.373e-3 density); velocity process noise
    double gyro_bias_rw{1.0e-5};      // gyro bias random walk
    double accel_bias_rw{1.0e-4};     // accel bias random walk

    // measurement noise (stddev) - tuned by offline grid search
    double wheel_speed_sigma{0.1};    // m/s  (forward)
    double nhc_sigma{0.03};           // m/s  (lateral/vertical pseudo-measurement)
    double zupt_vel_sigma{0.01};      // m/s  (tight, when stationary)
    double zaru_sigma{0.005};         // rad/s

    // stationary detection (triple condition)
    double zupt_speed_thresh{0.05};   // m/s   (wheel encoder)
    double zupt_gyro_thresh{0.02};    // rad/s (gyro norm)
    double zupt_acc_var_thresh{0.05}; // (m/s^2)^2  (accel-norm variance over window)
    int stationary_window{20};        // samples for accel variance
  };

  explicit EskfOdometry(const Params & p);

  void setSpeed(double forward_speed_mps) override {speed_ = forward_speed_mps;}
  bool update(
    double t,
    const Eigen::Quaterniond & q_bl,
    const Eigen::Vector3d & gyro_bl,
    const Eigen::Vector3d & acc_bl) override;
  const OdomOutput & output() const override {return out_;}

private:
  void initFromFirst(const Eigen::Quaterniond & q_bl);
  void predict(double dt, const Eigen::Vector3d & gyro, const Eigen::Vector3d & acc);
  void updateWheelBody();                          // wheel forward + NHC (3D body velocity)
  void updateZupt(const Eigen::Vector3d & gyro);   // ZUPT + ZARU
  void updateZaru(const Eigen::Vector3d & gyro);   // ZARU only (gyro-bias), used during stationary hold
  bool isStationary(const Eigen::Vector3d & gyro, const Eigen::Vector3d & acc);
  void applyUpdate(
    const Eigen::Matrix<double, Eigen::Dynamic, 15> & H,
    const Eigen::VectorXd & r,
    const Eigen::MatrixXd & Rm,
    bool lock_orientation = false);
  void fillOutput(const Eigen::Vector3d & gyro);

  Params params_;
  double last_t_{-1.0};
  double speed_{0.0};
  bool initialized_{false};

  // nominal state
  Eigen::Vector3d p_{Eigen::Vector3d::Zero()};
  Eigen::Vector3d v_{Eigen::Vector3d::Zero()};
  Eigen::Quaterniond q_{Eigen::Quaterniond::Identity()};
  Eigen::Vector3d bg_{Eigen::Vector3d::Zero()};
  Eigen::Vector3d ba_{Eigen::Vector3d::Zero()};

  Eigen::Matrix<double, 15, 15> P_{Eigen::Matrix<double, 15, 15>::Identity()};
  Eigen::Vector3d g_{0.0, 0.0, -9.80665};

  std::deque<double> acc_norm_buf_;

  OdomOutput out_;
};

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__ESKF_ODOMETRY_HPP_

#include "loam_fgo_localization/local_odometry/eskf_odometry.hpp"

#include <cmath>
#include <numeric>

namespace loam_fgo_localization
{

namespace
{
Eigen::Matrix3d skew(const Eigen::Vector3d & v)
{
  Eigen::Matrix3d m;
  m << 0.0, -v.z(), v.y(),
    v.z(), 0.0, -v.x(),
    -v.y(), v.x(), 0.0;
  return m;
}

// SO(3) exponential: rotation vector -> quaternion (body increment).
Eigen::Quaterniond expSO3(const Eigen::Vector3d & w)
{
  const double th = w.norm();
  if (th < 1e-9) {
    Eigen::Quaterniond q(1.0, 0.5 * w.x(), 0.5 * w.y(), 0.5 * w.z());
    q.normalize();
    return q;
  }
  return Eigen::Quaterniond(Eigen::AngleAxisd(th, w / th));
}

double yawOf(const Eigen::Quaterniond & q)
{
  return std::atan2(2.0 * (q.w() * q.z() + q.x() * q.y()),
                    1.0 - 2.0 * (q.y() * q.y() + q.z() * q.z()));
}
}  // namespace

EskfOdometry::EskfOdometry(const Params & p)
: params_(p)
{
  g_ = Eigen::Vector3d(0.0, 0.0, -params_.gravity);
  // initial covariance (position/velocity tight, attitude/bias looser)
  P_.setIdentity();
  P_.block<3, 3>(0, 0) *= 1e-6;    // p
  P_.block<3, 3>(3, 3) *= 1e-4;    // v
  P_.block<3, 3>(6, 6) *= 1e-3;    // theta
  P_.block<3, 3>(9, 9) *= 1e-4;    // b_g
  P_.block<3, 3>(12, 12) *= 1e-2;  // b_a
}

void EskfOdometry::initFromFirst(const Eigen::Quaterniond & q_bl)
{
  // Keep roll/pitch (gravity alignment), zero yaw -> odom frame starts at yaw 0.
  const double yaw = yawOf(q_bl);
  if (params_.planar) {
    q_ = Eigen::Quaterniond::Identity();   // planar: start level, yaw 0 (no roll/pitch)
  } else {
    q_ = (Eigen::AngleAxisd(-yaw, Eigen::Vector3d::UnitZ()) * q_bl).normalized();
  }
  p_.setZero();
  v_.setZero();
  bg_.setZero();
  ba_.setZero();
  initialized_ = true;
}

bool EskfOdometry::update(
  double t,
  const Eigen::Quaterniond & q_bl,
  const Eigen::Vector3d & gyro_bl,
  const Eigen::Vector3d & acc_bl)
{
  if (last_t_ < 0.0) {
    last_t_ = t;
    initFromFirst(q_bl);
    return false;
  }
  const double dt = t - last_t_;
  last_t_ = t;
  if (dt <= 0.0 || dt > params_.max_dt) {return false;}

  const bool stat = isStationary(gyro_bl, acc_bl);
  if (params_.stationary_hold && stat) {
    // Stationary: FREEZE pose (skip integration) -> zero at-rest drift.
    // Hold p_ and q_; force velocity to 0; keep refining gyro bias (ZARU) for resume.
    v_.setZero();
    if (params_.zaru_enable) {updateZaru(gyro_bl);}
  } else {
    predict(dt, gyro_bl, acc_bl);     // IMU mechanization + covariance
    updateWheelBody();                // wheel forward + NHC
    if (stat) {updateZupt(gyro_bl);}  // (only when stationary_hold disabled)
  }

  // planar constraint (ground robot): pin z position and vertical velocity to 0.
  // NOTE: roll/pitch are kept in the INTERNAL orientation q_ on purpose — the accelerometer
  // needs them for gravity compensation. They are collapsed to yaw-only only at OUTPUT
  // (fillOutput) so the published base_link TF stays level. Forcing q_ flat here corrupts
  // gravity comp / velocity propagation / covariance and diverges.
  if (params_.planar) {
    p_.z() = 0.0;
    v_.z() = 0.0;
    // sweep out any roll/pitch that leaked in (e.g. ZARU cross-covariance) so orientation
    // stays strictly yaw-only. NOTE: do NOT pin P(6,6)/P(7,7) here - that made the filter
    // inconsistent and diverge. Nominal projection only.
    q_ = Eigen::Quaterniond(Eigen::AngleAxisd(yawOf(q_), Eigen::Vector3d::UnitZ()));
    P_(2, 2) = 1.0e-9;   // z position certain
    P_(5, 5) = 1.0e-9;   // z velocity certain
  }

  fillOutput(gyro_bl);
  return true;
}

void EskfOdometry::predict(double dt, const Eigen::Vector3d & gyro, const Eigen::Vector3d & acc)
{
  const Eigen::Matrix3d R = q_.toRotationMatrix();
  const Eigen::Vector3d w_hat = gyro - bg_;
  const Eigen::Vector3d a_hat = acc - ba_;
  const Eigen::Vector3d a_world = R * a_hat + g_;

  // --- nominal ---
  p_ += v_ * dt + 0.5 * a_world * dt * dt;
  v_ += a_world * dt;
  // planar: integrate heading from gyro-z only. Integrating wx/wy makes roll/pitch drift
  // (no gravity leveling here), which over long runs corrupts the extracted yaw. On flat
  // ground only yaw is meaningful, so keep orientation strictly yaw.
  Eigen::Vector3d w_int = w_hat;
  if (params_.planar) {w_int.x() = 0.0; w_int.y() = 0.0;}
  q_ = (q_ * expSO3(w_int * dt)).normalized();
  // bias unchanged

  // --- error-state transition F (local error) ---
  Eigen::Matrix<double, 15, 15> F = Eigen::Matrix<double, 15, 15>::Identity();
  F.block<3, 3>(0, 3) = Eigen::Matrix3d::Identity() * dt;    // dp / dv
  F.block<3, 3>(3, 6) = -R * skew(a_hat) * dt;               // dv / dtheta
  F.block<3, 3>(3, 12) = -R * dt;                            // dv / dba
  F.block<3, 3>(6, 6) = Eigen::Matrix3d::Identity() - skew(w_hat) * dt;  // dtheta / dtheta
  F.block<3, 3>(6, 9) = -Eigen::Matrix3d::Identity() * dt;   // dtheta / dbg

  // --- process noise Q (continuous densities integrated over dt) ---
  Eigen::Matrix<double, 15, 15> Q = Eigen::Matrix<double, 15, 15>::Zero();
  Q.block<3, 3>(3, 3) = Eigen::Matrix3d::Identity() * (params_.accel_noise * params_.accel_noise * dt);
  Q.block<3, 3>(6, 6) = Eigen::Matrix3d::Identity() * (params_.gyro_noise * params_.gyro_noise * dt);
  Q.block<3, 3>(9, 9) = Eigen::Matrix3d::Identity() * (params_.gyro_bias_rw * params_.gyro_bias_rw * dt);
  Q.block<3, 3>(12, 12) = Eigen::Matrix3d::Identity() * (params_.accel_bias_rw * params_.accel_bias_rw * dt);

  P_ = F * P_ * F.transpose() + Q;
}

void EskfOdometry::updateWheelBody()
{
  // measurement: body-frame velocity = [s*v_wheel, 0, 0] (wheel forward + NHC lateral/vertical)
  const Eigen::Matrix3d R = q_.toRotationMatrix();
  const Eigen::Vector3d v_body_pred = R.transpose() * v_;
  Eigen::Vector3d z(params_.wheel_scale * speed_, 0.0, 0.0);
  Eigen::VectorXd r = z - v_body_pred;

  Eigen::Matrix<double, Eigen::Dynamic, 15> H = Eigen::Matrix<double, 3, 15>::Zero();
  H.block<3, 3>(0, 3) = R.transpose();                 // d(R^T v)/dv
  // NOTE: orientation coupling (H_theta) intentionally omitted. Heading comes from the
  // gyro only; letting the velocity/NHC measurement correct yaw makes lateral velocity be
  // mis-attributed to heading error -> spurious yaw (observed ~2x over-rotation on circles).

  Eigen::MatrixXd Rm = Eigen::Matrix3d::Zero();
  Rm(0, 0) = params_.wheel_speed_sigma * params_.wheel_speed_sigma;
  Rm(1, 1) = params_.nhc_sigma * params_.nhc_sigma;
  Rm(2, 2) = params_.nhc_sigma * params_.nhc_sigma;

  applyUpdate(H, r, Rm, /*lock_orientation=*/true);
}

void EskfOdometry::updateZupt(const Eigen::Vector3d & gyro)
{
  // ZUPT: body velocity = 0 (tight)
  {
    const Eigen::Matrix3d R = q_.toRotationMatrix();
    Eigen::VectorXd r = -(R.transpose() * v_);
    Eigen::Matrix<double, Eigen::Dynamic, 15> H = Eigen::Matrix<double, 3, 15>::Zero();
    H.block<3, 3>(0, 3) = R.transpose();                 // velocity only (no H_theta, heading = gyro)
    Eigen::MatrixXd Rm = Eigen::Matrix3d::Identity() * (params_.zupt_vel_sigma * params_.zupt_vel_sigma);
    applyUpdate(H, r, Rm, /*lock_orientation=*/true);
  }
  // ZARU: gyro-bias correction
  if (params_.zaru_enable) {updateZaru(gyro);}
}

void EskfOdometry::updateZaru(const Eigen::Vector3d & gyro)
{
  // true angular rate = 0 -> corrects gyro bias.  h = omega_m - b_g,  r = 0 - h
  Eigen::VectorXd r = -(gyro - bg_);
  Eigen::Matrix<double, Eigen::Dynamic, 15> H = Eigen::Matrix<double, 3, 15>::Zero();
  H.block<3, 3>(0, 9) = -Eigen::Matrix3d::Identity();   // dh/dbg = -I
  Eigen::MatrixXd Rm = Eigen::Matrix3d::Identity() * (params_.zaru_sigma * params_.zaru_sigma);
  applyUpdate(H, r, Rm);
}

bool EskfOdometry::isStationary(const Eigen::Vector3d & gyro, const Eigen::Vector3d & acc)
{
  // triple condition: wheel speed + gyro norm + accel-norm variance
  acc_norm_buf_.push_back(acc.norm());
  if (static_cast<int>(acc_norm_buf_.size()) > params_.stationary_window) {
    acc_norm_buf_.pop_front();
  }
  const bool speed_ok = std::fabs(speed_) < params_.zupt_speed_thresh;
  const bool gyro_ok = gyro.norm() < params_.zupt_gyro_thresh;
  bool acc_ok = false;
  if (static_cast<int>(acc_norm_buf_.size()) >= params_.stationary_window) {
    const double mean =
      std::accumulate(acc_norm_buf_.begin(), acc_norm_buf_.end(), 0.0) / acc_norm_buf_.size();
    double var = 0.0;
    for (double a : acc_norm_buf_) {var += (a - mean) * (a - mean);}
    var /= acc_norm_buf_.size();
    acc_ok = var < params_.zupt_acc_var_thresh;
  }
  return speed_ok && gyro_ok && acc_ok;
}

void EskfOdometry::applyUpdate(
  const Eigen::Matrix<double, Eigen::Dynamic, 15> & H,
  const Eigen::VectorXd & r,
  const Eigen::MatrixXd & Rm,
  bool lock_orientation)
{
  const Eigen::MatrixXd S = H * P_ * H.transpose() + Rm;
  const Eigen::Matrix<double, 15, Eigen::Dynamic> K = P_ * H.transpose() * S.inverse();
  Eigen::Matrix<double, 15, 1> dx = K * r;
  // Wheel/velocity update corrects only position+velocity. Block it from touching
  // orientation(6:9), gyro bias(9:12), accel bias(12:15) via cross-covariance:
  // on a constant-curvature path velocity does not truly observe those, and the
  // spurious corrections (esp. gyro bias) make the gyro-propagated heading over-rotate.
  // Attitude comes from the gyro; biases come from ZUPT/ZARU only.
  if (lock_orientation) {dx.segment<9>(6).setZero();}

  // inject into nominal
  p_ += dx.segment<3>(0);
  v_ += dx.segment<3>(3);
  const Eigen::Vector3d dth = dx.segment<3>(6);
  q_ = (q_ * expSO3(dth)).normalized();
  bg_ += dx.segment<3>(9);
  ba_ += dx.segment<3>(12);

  // covariance update (Joseph form)
  const Eigen::Matrix<double, 15, 15> I = Eigen::Matrix<double, 15, 15>::Identity();
  const Eigen::Matrix<double, 15, 15> IKH = I - K * H;
  P_ = IKH * P_ * IKH.transpose() + K * Rm * K.transpose();

  // error reset (local): G on theta block
  Eigen::Matrix<double, 15, 15> G = Eigen::Matrix<double, 15, 15>::Identity();
  G.block<3, 3>(6, 6) = Eigen::Matrix3d::Identity() - 0.5 * skew(dth);
  P_ = G * P_ * G.transpose();
}

void EskfOdometry::fillOutput(const Eigen::Vector3d & gyro)
{
  const Eigen::Matrix3d R = q_.toRotationMatrix();
  out_.position = p_;
  // planar robot: publish yaw-only pose so the base_link TF stays level (no phantom slope).
  // full 3D q_ is retained internally for accelerometer gravity compensation.
  out_.orientation = params_.planar
    ? Eigen::Quaterniond(Eigen::AngleAxisd(yawOf(q_), Eigen::Vector3d::UnitZ()))
    : q_;
  out_.velocity_body = R.transpose() * v_;              // estimated body velocity
  out_.yaw_rate = (gyro - bg_).z();                     // bias-corrected

  out_.pose_cov.fill(0.0);
  out_.pose_cov[0] = P_(0, 0);    // x
  out_.pose_cov[7] = P_(1, 1);    // y
  out_.pose_cov[14] = P_(2, 2);   // z
  out_.pose_cov[21] = P_(6, 6);   // roll
  out_.pose_cov[28] = P_(7, 7);   // pitch
  out_.pose_cov[35] = P_(8, 8);   // yaw
  out_.twist_cov.fill(0.0);
  out_.twist_cov[0] = P_(3, 3);
  out_.twist_cov[7] = P_(4, 4);
  out_.twist_cov[14] = P_(5, 5);
  out_.twist_cov[35] = 1.0e-3;
}

}  // namespace loam_fgo_localization

#include "loam_fgo_localization/local_odometry/local_odometry.hpp"

#include <cmath>

namespace loam_fgo_localization
{

namespace
{
double yawFromQuat(const Eigen::Quaterniond & q)
{
  return std::atan2(
    2.0 * (q.w() * q.z() + q.x() * q.y()),
    1.0 - 2.0 * (q.y() * q.y() + q.z() * q.z()));
}

double normalizeAngle(double a)
{
  while (a > M_PI) {a -= 2.0 * M_PI;}
  while (a < -M_PI) {a += 2.0 * M_PI;}
  return a;
}
}  // namespace

LocalOdometry::LocalOdometry(const Params & p)
: params_(p)
{
}

bool LocalOdometry::update(
  double t,
  const Eigen::Quaterniond & q_bl,
  const Eigen::Vector3d & gyro_bl,
  const Eigen::Vector3d & /*acc_bl*/)
{
  if (last_t_ < 0.0) {
    last_t_ = t;
    if (params_.use_imu_orientation) {
      yaw0_ = yawFromQuat(q_bl);
      yaw0_set_ = true;
    }
    return false;  // 첫 샘플: dt 없음
  }

  const double dt = t - last_t_;
  last_t_ = t;
  if (dt <= 0.0 || dt > params_.max_dt) {return false;}  // 시간 튐/누락 방어

  // --- heading ---
  if (params_.use_imu_orientation) {
    if (!yaw0_set_) {yaw0_ = yawFromQuat(q_bl); yaw0_set_ = true;}
    yaw_ = normalizeAngle(yawFromQuat(q_bl) - yaw0_);   // odom 은 yaw 0 에서 시작
  } else {
    yaw_ = normalizeAngle(yaw_ + gyro_bl.z() * dt);     // 자이로-오도메트리
  }

  // --- position (비홀로노믹: 전진 성분만) ---
  const double v = params_.wheel_scale * speed_;
  x_ += v * std::cos(yaw_) * dt;
  y_ += v * std::sin(yaw_) * dt;

  // --- 공분산 성장 (baseline; EKF 교체 시 대체) ---
  const double dist = std::fabs(v) * dt;
  pos_var_ += params_.k_pos * dist * dist + 1.0e-9;
  yaw_var_ += params_.k_yaw * dt;

  // --- 출력 ---
  out_.position = Eigen::Vector3d(x_, y_, 0.0);
  out_.orientation = Eigen::Quaterniond(Eigen::AngleAxisd(yaw_, Eigen::Vector3d::UnitZ()));
  out_.velocity_body = Eigen::Vector3d(v, 0.0, 0.0);
  out_.yaw_rate = gyro_bl.z();

  out_.pose_cov.fill(0.0);
  out_.pose_cov[0] = pos_var_;    // x
  out_.pose_cov[7] = pos_var_;    // y
  out_.pose_cov[14] = 1.0e-3;     // z (2D 가정)
  out_.pose_cov[21] = 1.0e-4;     // roll
  out_.pose_cov[28] = 1.0e-4;     // pitch
  out_.pose_cov[35] = yaw_var_;   // yaw

  out_.twist_cov.fill(0.0);
  out_.twist_cov[0] = 1.0e-3;     // vx
  out_.twist_cov[7] = 1.0e-3;     // vy
  out_.twist_cov[35] = 1.0e-3;    // wz

  return true;
}

}  // namespace loam_fgo_localization

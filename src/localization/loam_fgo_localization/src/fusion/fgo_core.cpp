#include "loam_fgo_localization/fusion/fgo_core.hpp"

#include <algorithm>
#include <cmath>

#include <gtsam/inference/Symbol.h>
#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/nonlinear/PriorFactor.h>
#include <gtsam/slam/BetweenFactor.h>

namespace loam_fgo_localization
{
namespace
{

using gtsam::symbol_shorthand::B;  // GPS bias (Point2)
using gtsam::symbol_shorthand::X;  // base pose (Pose2)

double normalizeAngle(double a)
{
  return std::atan2(std::sin(a), std::cos(a));
}

// GPS 위치 측정 팩터: z = translation(X) + B
//   X: map 프레임 base pose (Pose2), B: GPS 바이어스 (Point2, map 프레임)
class GpsBiasFactor : public gtsam::NoiseModelFactor2<gtsam::Pose2, gtsam::Point2>
{
public:
  GpsBiasFactor(
    gtsam::Key pose_key, gtsam::Key bias_key, const gtsam::Point2 & measured,
    const gtsam::SharedNoiseModel & model)
  : NoiseModelFactor2<gtsam::Pose2, gtsam::Point2>(model, pose_key, bias_key),
    measured_(measured)
  {
  }

  gtsam::Vector evaluateError(
    const gtsam::Pose2 & pose, const gtsam::Point2 & bias,
    boost::optional<gtsam::Matrix &> H1 = boost::none,
    boost::optional<gtsam::Matrix &> H2 = boost::none) const override
  {
    // transformFrom(원점)은 translation과 같고 구버전 GTSAM에서도 Pose2 자코비안을 제공한다.
    const gtsam::Point2 t = pose.transformFrom(gtsam::Point2(0.0, 0.0), H1);
    if (H2) {
      *H2 = gtsam::Matrix22::Identity();
    }
    return t + bias - measured_;
  }

private:
  gtsam::Point2 measured_;
};

}  // namespace

FgoCore::FgoCore(const FgoParams & params)
: params_(params)
{
  gtsam::ISAM2Params isam_params;
  // Dogleg(trust-region): 넓은 yaw prior + 강한 위치측정 조합에서 GN 스텝 폭주 방지
  // (2026-07-31 run2 발산 진단).
  isam_params.optimizationParams = gtsam::ISAM2DoglegParams();
  isam_params.relinearizeThreshold = 0.01;
  isam_params.relinearizeSkip = 1;
  smoother_ = std::make_unique<gtsam::ISAM2>(isam_params);
}

FgoCore::~FgoCore() = default;

std::optional<gtsam::Pose2> FgoCore::interpolateOdom(double t) const
{
  if (odom_buffer_.size() < 2 ||
    t < odom_buffer_.front().t || t > odom_buffer_.back().t)
  {
    return std::nullopt;
  }
  const auto after = std::lower_bound(
    odom_buffer_.begin(), odom_buffer_.end(), t,
    [](const OdomSample & s, double value) {return s.t < value;});
  if (after == odom_buffer_.begin()) {
    return after->pose;
  }
  const auto before = std::prev(after);
  const double span = after->t - before->t;
  const double ratio = span > 1e-9 ? (t - before->t) / span : 0.0;
  const double x = before->pose.x() + ratio * (after->pose.x() - before->pose.x());
  const double y = before->pose.y() + ratio * (after->pose.y() - before->pose.y());
  const double dyaw = normalizeAngle(after->pose.theta() - before->pose.theta());
  return gtsam::Pose2(x, y, normalizeAngle(before->pose.theta() + ratio * dyaw));
}

gtsam::Pose2 FgoCore::estimateOf(gtsam::Key key) const
{
  // 새로 추가돼 아직 update() 전이면 new_values_ 에 있음.
  if (new_values_.exists(key)) {
    return new_values_.at<gtsam::Pose2>(key);
  }
  return smoother_->calculateEstimate<gtsam::Pose2>(key);
}

void FgoCore::pushKeyframe(double t, const gtsam::Pose2 & odom_pose)
{
  const gtsam::Key key = X(next_pose_index_++);

  gtsam::Pose2 initial;
  if (keyframes_.empty()) {
    // 앵커 전: map ≈ odom 으로 시작 (첫 GPS 팩터가 위치를, 주행이 yaw 를 관측)
    initial = odom_pose;
    // 자유도 고정용 약한 prior (위치는 GPS가 곧 잡아줌, yaw 는 넓게)
    const auto prior_noise = gtsam::noiseModel::Diagonal::Sigmas(
      gtsam::Vector3(50.0, 50.0, params_.init_yaw_sigma));
    new_factors_.add(gtsam::PriorFactor<gtsam::Pose2>(key, initial, prior_noise));
  } else {
    const Keyframe & prev = keyframes_.back();
    const gtsam::Pose2 delta = prev.odom_pose.between(odom_pose);
    const double dist = std::hypot(delta.x(), delta.y());
    const double pos_sigma =
      params_.odom_pos_noise_floor + params_.odom_pos_noise_per_m * dist;
    const double yaw_sigma =
      params_.odom_yaw_noise_floor + params_.odom_yaw_noise_per_m * dist;
    const auto noise = gtsam::noiseModel::Diagonal::Sigmas(
      gtsam::Vector3(pos_sigma, pos_sigma, yaw_sigma));
    new_factors_.add(gtsam::BetweenFactor<gtsam::Pose2>(prev.key, key, delta, noise));
    initial = estimateOf(prev.key).compose(delta);
  }

  new_values_.insert(key, initial);
  keyframes_.push_back({key, t, odom_pose});
  pending_ = true;
}

const FgoCore::Keyframe * FgoCore::nearestKeyframe(double t, double tolerance) const
{
  const Keyframe * best = nullptr;
  double best_dt = tolerance;
  for (const auto & kf : keyframes_) {
    const double dt = std::abs(kf.t - t);
    if (dt <= best_dt) {
      best_dt = dt;
      best = &kf;
    }
  }
  return best;
}

const FgoCore::Keyframe * FgoCore::ensureKeyframe(double t)
{
  // 이미 충분히 가까운 keyframe 이 있으면 재사용 (측정을 그 노드에 부착)
  if (const Keyframe * near = nearestKeyframe(t, 0.05)) {
    return near;
  }
  if (!keyframes_.empty() && t <= keyframes_.back().t) {
    // 과거 시각 측정(지연 도착): 가장 가까운 기존 keyframe 에 부착.
    // keyframe 간격이 최대 keyframe_time 이므로 최근접 거리는 그 절반 이내 —
    // 허용오차를 간격의 0.6배로 두면 지연 측정이 버려지지 않는다 (소급은 iSAM2 가 처리).
    return nearestKeyframe(t, 0.6 * params_.keyframe_time);
  }
  const auto odom_pose = interpolateOdom(t);
  if (!odom_pose) {
    return nullptr;
  }
  pushKeyframe(t, *odom_pose);
  return &keyframes_.back();
}

gtsam::Key FgoCore::currentBiasKey(double t)
{
  if (!have_bias_node_) {
    const gtsam::Key key = B(next_bias_index_++);
    new_values_.insert(key, gtsam::Point2(0.0, 0.0));
    const auto prior = gtsam::noiseModel::Isotropic::Sigma(2, params_.bias_prior_sigma);
    new_factors_.add(gtsam::PriorFactor<gtsam::Point2>(key, gtsam::Point2(0, 0), prior));
    have_bias_node_ = true;
    last_bias_node_t_ = t;
    pending_ = true;
    return key;
  }

  const gtsam::Key current = B(next_bias_index_ - 1);
  if (t - last_bias_node_t_ < params_.bias_node_interval) {
    return current;
  }
  // 랜덤워크 체인 연장
  const gtsam::Key next = B(next_bias_index_++);
  gtsam::Point2 bias_estimate = latest_bias_;
  if (new_values_.exists(current)) {
    bias_estimate = new_values_.at<gtsam::Point2>(current);
  } else {
    bias_estimate = smoother_->calculateEstimate<gtsam::Point2>(current);
  }
  new_values_.insert(next, bias_estimate);
  const auto walk = gtsam::noiseModel::Isotropic::Sigma(
    2, params_.bias_random_walk_sigma);
  new_factors_.add(
    gtsam::BetweenFactor<gtsam::Point2>(current, next, gtsam::Point2(0, 0), walk));
  last_bias_node_t_ = t;
  pending_ = true;
  return next;
}

void FgoCore::addOdom(const OdomSample & sample)
{
  if (!odom_buffer_.empty() && sample.t <= odom_buffer_.back().t) {
    return;  // 시간 역행 방어
  }
  odom_buffer_.push_back(sample);
  // 버퍼는 lag + 여유 만큼만 유지
  const double horizon = sample.t - params_.smoother_lag - 2.0;
  while (odom_buffer_.size() > 2 && odom_buffer_.front().t < horizon) {
    odom_buffer_.pop_front();
  }

  if (keyframes_.empty()) {
    pushKeyframe(sample.t, sample.pose);
    return;
  }
  const Keyframe & last = keyframes_.back();
  const gtsam::Pose2 delta = last.odom_pose.between(sample.pose);
  const double dist = std::hypot(delta.x(), delta.y());
  if (dist >= params_.keyframe_dist ||
    sample.t - last.t >= params_.keyframe_time)
  {
    pushKeyframe(sample.t, sample.pose);
  }
}

void FgoCore::addGps(const GpsMeasurement & measurement)
{
  // float(비RTK) 정책: 기본 미사용 (PCD/RTK 만 절대 팩터 -> 공백 시 odom 관성으로
  // map->odom 자연 동결). use_float 시엔 σ 인플레이션으로 약한 닻으로만 사용.
  GpsMeasurement gps = measurement;
  if (!gps.rtk_fixed) {
    if (!params_.gps_use_float) {
      return;
    }
    gps.sigma_x *= params_.gps_float_sigma_inflation;
    gps.sigma_y *= params_.gps_float_sigma_inflation;
  }
  const GpsMeasurement & m = gps;

  if (last_gps_factor_t_ >= 0.0 &&
    m.t - last_gps_factor_t_ < params_.gps_factor_min_interval)
  {
    return;  // 다운샘플
  }

  // ---- GPS 단독 앵커 (아직 절대측정으로 고정 전) ----
  // yaw 가 π-무지 상태에서 위치측정만 꽂으면 최적화가 불안정 -> 이동방향 기반으로
  // yaw 를 먼저 추정하고 pose prior 로 앵커한 뒤에 GPS 팩터를 흘린다.
  // (PCD 가 먼저 수락되면 그쪽이 앵커가 되고 이 경로는 건너뜀.)
  if (!anchored_) {
    const auto odom_pose = interpolateOdom(m.t);
    if (!odom_pose) {
      return;
    }
    if (!have_first_gps_) {
      first_gps_position_ = m.position;
      first_gps_odom_pose_ = *odom_pose;
      have_first_gps_ = true;
      return;
    }
    const gtsam::Point2 gps_disp = m.position - first_gps_position_;
    const double odom_dx = odom_pose->x() - first_gps_odom_pose_.x();
    const double odom_dy = odom_pose->y() - first_gps_odom_pose_.y();
    if (gps_disp.norm() < params_.yaw_init_min_travel ||
      std::hypot(odom_dx, odom_dy) < 0.3 * params_.yaw_init_min_travel)
    {
      return;  // 아직 yaw 관측 불가 (더 주행 필요)
    }
    const double yaw_offset =
      std::atan2(gps_disp.y(), gps_disp.x()) - std::atan2(odom_dy, odom_dx);
    const double yaw_estimate = normalizeAngle(odom_pose->theta() + yaw_offset);

    const Keyframe * anchor_kf = ensureKeyframe(m.t);
    if (anchor_kf == nullptr) {
      return;
    }
    const auto anchor_noise = gtsam::noiseModel::Diagonal::Sigmas(
      gtsam::Vector3(m.sigma_x, m.sigma_y,
      params_.yaw_init_prior_sigma));
    new_factors_.add(gtsam::PriorFactor<gtsam::Pose2>(
        anchor_kf->key,
        gtsam::Pose2(m.position.x(), m.position.y(), yaw_estimate),
        anchor_noise));
    anchored_ = true;
    last_absolute_factor_t_ = m.t;
    pending_ = true;
    // 이후 아래 일반 경로로도 이 측정을 bias 와 함께 반영
  }

  const Keyframe * kf = ensureKeyframe(m.t);
  if (kf == nullptr) {
    return;
  }

  const gtsam::Key bias_key = currentBiasKey(m.t);
  auto gaussian = gtsam::noiseModel::Diagonal::Sigmas(
    gtsam::Vector2(m.sigma_x, m.sigma_y));
  auto robust = gtsam::noiseModel::Robust::Create(
    gtsam::noiseModel::mEstimator::Huber::Create(params_.gps_huber_k), gaussian);
  new_factors_.add(GpsBiasFactor(kf->key, bias_key, m.position, robust));

  if (m.rtk_fixed) {
    // RTK-fixed: 현재 바이어스를 0 근방으로 강하게 앵커 (절대좌표 재고정)
    const auto anchor = gtsam::noiseModel::Isotropic::Sigma(
      2, params_.bias_rtk_prior_sigma);
    new_factors_.add(
      gtsam::PriorFactor<gtsam::Point2>(bias_key, gtsam::Point2(0, 0), anchor));
  }

  last_gps_factor_t_ = m.t;
  last_absolute_factor_t_ = m.t;
  anchored_ = true;
  pending_ = true;
}

bool FgoCore::addPcd(const PcdMeasurement & measurement)
{
  const Keyframe * kf = ensureKeyframe(measurement.t);
  if (kf == nullptr) {
    return false;
  }

  // 공분산: 대칭화 + 과신 보정 스케일 + 바닥값
  //   (Hessian 기반 공분산은 정밀도이지 정확도가 아님 -> pcd_cov_scale 로 현실화)
  Eigen::Matrix3d cov = 0.5 * (measurement.covariance +
    measurement.covariance.transpose()) * params_.pcd_cov_scale;
  cov(0, 0) = std::max(cov(0, 0), params_.pcd_sigma_floor_xy * params_.pcd_sigma_floor_xy);
  cov(1, 1) = std::max(cov(1, 1), params_.pcd_sigma_floor_xy * params_.pcd_sigma_floor_xy);
  cov(2, 2) = std::max(cov(2, 2), params_.pcd_sigma_floor_yaw * params_.pcd_sigma_floor_yaw);

  // 카이제곱 사전 게이트 + relax 히스테리시스 (락아웃 방지, kidnap 방어 겸용):
  //   정상: 게이트 통과분만 수락.
  //   연속 거부 N회 -> 완화 모드: 공분산을 크게 부풀려 수락 (부드러운 재획득).
  //   완화 모드는 정상 게이트를 통과하는 측정이 나오면 해제.
  if (anchored_) {
    const gtsam::Pose2 predicted = estimateOf(kf->key);
    gtsam::Vector3 residual;
    residual << measurement.pose.x() - predicted.x(),
      measurement.pose.y() - predicted.y(),
      normalizeAngle(measurement.pose.theta() - predicted.theta());
    const double chi2 = residual.transpose() * cov.inverse() * residual;
    const bool pass = chi2 <= params_.pcd_gate_chi2;
    if (pass) {
      pcd_gate_relaxed_ = false;
      pcd_consecutive_rejects_ = 0;
    } else if (pcd_gate_relaxed_) {
      cov *= params_.pcd_relax_cov_scale;   // 완화 수락: 약하게 반영
    } else {
      ++pcd_consecutive_rejects_;
      ++pcd_rejected_;
      if (pcd_consecutive_rejects_ >= params_.pcd_gate_relax_after) {
        pcd_gate_relaxed_ = true;
      }
      return false;
    }
  } else {
    pcd_consecutive_rejects_ = 0;
  }
  ++pcd_accepted_;

  auto gaussian = gtsam::noiseModel::Gaussian::Covariance(cov);
  if (!anchored_) {
    // 전역 초기화 전에는 map/odom 원점 차이를 이상치로 억제하면 안 된다.
    // 검증된 첫 PCD로 앵커를 잡고, 이후에는 기존 게이트와 Cauchy를 적용한다.
    new_factors_.add(gtsam::PriorFactor<gtsam::Pose2>(kf->key, measurement.pose, gaussian));
  } else {
    auto robust = gtsam::noiseModel::Robust::Create(
      gtsam::noiseModel::mEstimator::Cauchy::Create(params_.pcd_cauchy_k), gaussian);
    new_factors_.add(gtsam::PriorFactor<gtsam::Pose2>(kf->key, measurement.pose, robust));
  }

  last_absolute_factor_t_ = measurement.t;
  last_pcd_factor_t_ = measurement.t;   // PCD 전용 (GPS 와 섞지 않는다)
  anchored_ = true;
  pending_ = true;
  return true;
}

void FgoCore::update(double /*now_sec*/)
{
  if (!pending_ || keyframes_.empty()) {
    return;
  }
  smoother_->update(new_factors_, new_values_);
  new_factors_.resize(0);
  new_values_.clear();
  pending_ = false;

  const Keyframe & latest = keyframes_.back();
  latest_map_pose_ = smoother_->calculateEstimate<gtsam::Pose2>(latest.key);
  latest_odom_pose_ = latest.odom_pose;
  if (have_bias_node_) {
    latest_bias_ = smoother_->calculateEstimate<gtsam::Point2>(B(next_bias_index_ - 1));
  }
}

FgoStatus FgoCore::status(double now_sec) const
{
  if (!anchored_) {
    return FgoStatus::Init;
  }
  if (last_absolute_factor_t_ >= 0.0 &&
    now_sec - last_absolute_factor_t_ > params_.watchdog_sec)
  {
    return FgoStatus::Degraded;
  }
  return FgoStatus::Ok;
}

std::optional<gtsam::Pose2> FgoCore::latestMapPose() const
{
  return latest_map_pose_;
}

std::optional<gtsam::Pose2> FgoCore::latestOdomPose() const
{
  return latest_odom_pose_;
}

gtsam::Point2 FgoCore::gpsBias() const
{
  return latest_bias_;
}

}  // namespace loam_fgo_localization

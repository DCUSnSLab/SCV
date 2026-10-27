#include "loam_fgo_localization/fusion/anchor_core.hpp"

#include <algorithm>
#include <cmath>

namespace loam_fgo_localization
{

double normalizeAngle(double a)
{
  return std::atan2(std::sin(a), std::cos(a));
}

Se2 Se2::compose(const Se2 & other) const
{
  const double c = std::cos(yaw);
  const double s = std::sin(yaw);
  return {
    x + c * other.x - s * other.y,
    y + s * other.x + c * other.y,
    normalizeAngle(yaw + other.yaw)};
}

Se2 Se2::inverse() const
{
  const double c = std::cos(yaw);
  const double s = std::sin(yaw);
  return {
    -(c * x + s * y),
    -(-s * x + c * y),
    normalizeAngle(-yaw)};
}

const char * anchorModeName(AnchorMode m)
{
  switch (m) {
    case AnchorMode::Init: return "INIT";
    case AnchorMode::RtkActive: return "RTK_ACTIVE";
    case AnchorMode::PcdActive: return "PCD_ACTIVE";
    case AnchorMode::Hold: return "HOLD";
    case AnchorMode::Degraded: return "DEGRADED";
  }
  return "INIT";
}

AnchorCore::AnchorCore(const AnchorParams & params)
: params_(params)
{
  covariance_.setZero();
}

void AnchorCore::addOdom(double t, const Se2 & pose)
{
  if (!odom_buffer_.empty() && t <= odom_buffer_.back().first) {
    return;  // 시간 역행 방어
  }
  odom_buffer_.emplace_back(t, pose);
  // 지연 PCD 부착을 위한 여유 30초 유지
  const double horizon = t - 30.0;
  while (odom_buffer_.size() > 2 && odom_buffer_.front().first < horizon) {
    odom_buffer_.pop_front();
  }
}

std::optional<Se2> AnchorCore::interpolateOdom(double t) const
{
  if (odom_buffer_.size() < 2 ||
    t < odom_buffer_.front().first || t > odom_buffer_.back().first)
  {
    return std::nullopt;
  }
  const auto after = std::lower_bound(
    odom_buffer_.begin(), odom_buffer_.end(), t,
    [](const std::pair<double, Se2> & s, double value) {return s.first < value;});
  if (after == odom_buffer_.begin()) {
    return after->second;
  }
  const auto before = std::prev(after);
  const double span = after->first - before->first;
  const double ratio = span > 1e-9 ? (t - before->first) / span : 0.0;
  const double dyaw = normalizeAngle(after->second.yaw - before->second.yaw);
  return Se2{
    before->second.x + ratio * (after->second.x - before->second.x),
    before->second.y + ratio * (after->second.y - before->second.y),
    normalizeAngle(before->second.yaw + ratio * dyaw)};
}

void AnchorCore::ekfPredictTo(double t)
{
  if (last_predict_t_ < 0.0) {
    last_predict_t_ = t;
    return;
  }
  const double dt = t - last_predict_t_;
  if (dt <= 0.0) {
    return;
  }
  last_predict_t_ = t;
  // map->odom 은 odom 드리프트 속도로만 흐른다 (랜덤워크)
  covariance_(0, 0) += params_.process_xy_sigma * params_.process_xy_sigma * dt;
  covariance_(1, 1) += params_.process_xy_sigma * params_.process_xy_sigma * dt;
  covariance_(2, 2) += params_.process_yaw_sigma * params_.process_yaw_sigma * dt;
}

void AnchorCore::tryRtkYawInit(double t, double x, double y, double sigma)
{
  // RTK 단독 초기화: 위치만으로는 θ(map->odom 회전)를 모른다.
  // GPS 변위 방향과 odom 변위 방향의 차가 θ (이동방향 기반; FGO 초기 앵커와 동일).
  const auto base = interpolateOdom(t);
  if (!base) {
    return;
  }
  // GPS 는 안테나 위치 측정 -> odom 프레임의 안테나 점과 대응시킨다 (레버암 보상)
  const Se2 antenna_odom = base->compose(
    Se2{params_.antenna_offset_x, params_.antenna_offset_y, 0.0});
  const auto odom = std::optional<Se2>(antenna_odom);
  if (!have_first_rtk_) {
    first_rtk_x_ = x;
    first_rtk_y_ = y;
    first_rtk_odom_ = *odom;
    have_first_rtk_ = true;
    return;
  }
  const double gps_dx = x - first_rtk_x_;
  const double gps_dy = y - first_rtk_y_;
  const double odom_dx = odom->x - first_rtk_odom_.x;
  const double odom_dy = odom->y - first_rtk_odom_.y;
  if (std::hypot(gps_dx, gps_dy) < params_.yaw_init_min_travel ||
    std::hypot(odom_dx, odom_dy) < 0.3 * params_.yaw_init_min_travel)
  {
    return;  // 아직 yaw 관측 불가 (더 주행 필요)
  }
  const double theta = normalizeAngle(
    std::atan2(gps_dy, gps_dx) - std::atan2(odom_dy, odom_dx));
  const double c = std::cos(theta);
  const double s = std::sin(theta);
  transform_ = {
    x - (c * odom->x - s * odom->y),
    y - (s * odom->x + c * odom->y),
    theta};
  covariance_.setZero();
  covariance_(0, 0) = covariance_(1, 1) = sigma * sigma + 0.01;
  covariance_(2, 2) = 0.09;  // 이동방향 yaw 추정 σ ~0.3 rad
  have_transform_ = true;
  last_predict_t_ = t;
  last_absolute_t_ = t;
}

bool AnchorCore::ekfUpdateRtk(double t, double x, double y, double sigma)
{
  const auto base = interpolateOdom(t);
  if (!base) {
    return false;
  }
  ekfPredictTo(t);

  // h(T) = t_xy + R(θ)·p_odom  (안테나의 map 위치; 레버암 보상)
  const Se2 odom_val = base->compose(
    Se2{params_.antenna_offset_x, params_.antenna_offset_y, 0.0});
  const Se2 * odom = &odom_val;
  const double c = std::cos(transform_.yaw);
  const double s = std::sin(transform_.yaw);
  const double hx = transform_.x + c * odom->x - s * odom->y;
  const double hy = transform_.y + s * odom->x + c * odom->y;
  Eigen::Vector2d r(x - hx, y - hy);

  Eigen::Matrix<double, 2, 3> H;
  H << 1.0, 0.0, -s * odom->x - c * odom->y,
    0.0, 1.0, c * odom->x - s * odom->y;

  const double sig = std::max(sigma, params_.rtk_sigma_floor);
  const Eigen::Matrix2d R = Eigen::Matrix2d::Identity() * sig * sig;
  const Eigen::Matrix2d S = H * covariance_ * H.transpose() + R;
  const double chi2 = r.transpose() * S.inverse() * r;
  if (chi2 > params_.rtk_gate_chi2) {
    return false;  // 이상 RTK (멀티패스 등) 게이트아웃
  }
  const Eigen::Matrix<double, 3, 2> K = covariance_ * H.transpose() * S.inverse();
  const Eigen::Vector3d dx = K * r;
  transform_.x += dx(0);
  transform_.y += dx(1);
  transform_.yaw = normalizeAngle(transform_.yaw + dx(2));
  const Eigen::Matrix3d IKH = Eigen::Matrix3d::Identity() - K * H;
  covariance_ = IKH * covariance_ * IKH.transpose() + K * R * K.transpose();  // Joseph
  last_absolute_t_ = t;
  ++rtk_update_count_;
  return true;
}

void AnchorCore::addGpsRtk(double t, double x, double y, double sigma)
{
  last_rtk_t_ = t;
  if (!have_transform_) {
    tryRtkYawInit(t, x, y, sigma);
    return;
  }
  ekfUpdateRtk(t, x, y, sigma);
}

void AnchorCore::addGpsFloat(double t, double x, double y, double sigma)
{
  // 앵커로 쓰지 않는다. PCD 후보의 대실패(수 m 오정합) 검출 봉투로만 사용.
  have_float_ = true;
  float_t_ = t;
  float_x_ = x;
  float_y_ = y;
  float_sigma_ = sigma;
}

void AnchorCore::pruneTrustWindow(double t)
{
  while (!trust_window_.empty() &&
    t - trust_window_.front().t > params_.trust_window_sec)
  {
    trust_window_.pop_front();
  }
}

namespace
{
double p95Of(std::vector<double> values)
{
  if (values.empty()) {
    return 0.0;
  }
  const std::size_t k = static_cast<std::size_t>(0.95 * (values.size() - 1));
  std::nth_element(values.begin(), values.begin() + k, values.end());
  return values[k];
}
}  // namespace

double AnchorCore::trustP95Xy() const
{
  std::vector<double> v;
  v.reserve(trust_window_.size());
  for (const auto & s : trust_window_) {v.push_back(s.e_xy);}
  return p95Of(std::move(v));
}

double AnchorCore::trustP95Yaw() const
{
  std::vector<double> v;
  v.reserve(trust_window_.size());
  for (const auto & s : trust_window_) {v.push_back(s.e_yaw);}
  return p95Of(std::move(v));
}

bool AnchorCore::trustOk() const
{
  return static_cast<int>(trust_window_.size()) >= params_.trust_min_samples &&
         trustP95Xy() <= params_.trust_xy_max &&
         trustP95Yaw() <= params_.trust_yaw_max;
}

std::size_t AnchorCore::bestVoteCluster(Se2 & consensus) const
{
  std::vector<std::size_t> best;
  for (std::size_t i = 0; i < votes_.size(); ++i) {
    std::vector<std::size_t> cluster;
    for (std::size_t j = 0; j < votes_.size(); ++j) {
      const double dxy = std::hypot(
        votes_[j].anchor.x - votes_[i].anchor.x,
        votes_[j].anchor.y - votes_[i].anchor.y);
      const double dyaw = std::abs(
        normalizeAngle(votes_[j].anchor.yaw - votes_[i].anchor.yaw));
      if (dxy <= params_.vote_xy_tol && dyaw <= params_.vote_yaw_tol) {
        cluster.push_back(j);
      }
    }
    if (cluster.size() > best.size()) {
      best = std::move(cluster);
    }
  }
  if (best.empty()) {
    return 0;
  }
  double sx = 0.0, sy = 0.0, ss = 0.0, sc = 0.0;
  for (const std::size_t idx : best) {
    sx += votes_[idx].anchor.x;
    sy += votes_[idx].anchor.y;
    ss += std::sin(votes_[idx].anchor.yaw);
    sc += std::cos(votes_[idx].anchor.yaw);
  }
  const double n = static_cast<double>(best.size());
  consensus = {sx / n, sy / n, std::atan2(ss, sc)};
  return best.size();
}

void AnchorCore::acceptAnchor(const Se2 & anchor, double t)
{
  transform_ = anchor;
  covariance_.setZero();
  covariance_(0, 0) = covariance_(1, 1) = params_.vote_xy_tol * params_.vote_xy_tol;
  covariance_(2, 2) = params_.vote_yaw_tol * params_.vote_yaw_tol;
  have_transform_ = true;
  last_predict_t_ = t;
  last_absolute_t_ = t;
  votes_.clear();
  ++pcd_anchor_count_;
}

PcdOutcome AnchorCore::addPcd(double t, const Se2 & pose_map_base)
{
  const auto odom = interpolateOdom(t);
  if (!odom) {
    return PcdOutcome::NoOdom;
  }
  // map->odom 후보. 스탬프 시각의 odom 으로 합성하므로 정합 지연에 둔감하다
  // (map->odom 자체는 드리프트율로만 천천히 변하는 값).
  const Se2 anchor = pose_map_base.compose(odom->inverse());

  // ---- RTK_ACTIVE: 채점만 (RTK 가 참값 역할) ----
  if (mode_ == AnchorMode::RtkActive && have_transform_) {
    const Se2 expected = transform_.compose(*odom);
    TrustSample sample;
    sample.t = t;
    sample.e_xy = std::hypot(
      pose_map_base.x - expected.x, pose_map_base.y - expected.y);
    sample.e_yaw = std::abs(normalizeAngle(pose_map_base.yaw - expected.yaw));
    trust_window_.push_back(sample);
    pruneTrustWindow(t);
    // 투표 버퍼도 계속 데워둔다 -> RTK 상실 시 무지연 인계
    if (!votes_.empty() &&
      (t - votes_.back().t > params_.vote_timeout_sec || t < votes_.back().t))
    {
      votes_.clear();
    }
    votes_.push_back({t, anchor});
    while (static_cast<int>(votes_.size()) > params_.vote_required_uncalibrated) {
      votes_.pop_front();
    }
    return PcdOutcome::Calibrated;
  }

  // ---- PCD 앵커 경로 (Init / PcdActive / Hold / Degraded) ----
  // 검증 1: float 봉투 — float 이 신선하면 후보가 float 위치의 3σ+여유 안이어야 함.
  if (have_float_ && t - float_t_ <= params_.float_fresh_sec && t >= float_t_) {
    const auto odom_at_float = interpolateOdom(float_t_);
    if (odom_at_float) {
      const Se2 expected_at_float = anchor.compose(*odom_at_float);
      const double dist = std::hypot(
        expected_at_float.x - float_x_, expected_at_float.y - float_y_);
      const double envelope =
        params_.float_envelope_sigma_scale * float_sigma_ +
        params_.float_envelope_margin;
      if (dist > envelope) {
        return PcdOutcome::EnvelopeRejected;
      }
    }
  }

  // 검증 2: 시간 일관성 투표.
  if (!votes_.empty() &&
    (t - votes_.back().t > params_.vote_timeout_sec || t < votes_.back().t))
  {
    votes_.clear();
  }
  votes_.push_back({t, anchor});
  while (static_cast<int>(votes_.size()) >
    std::max(params_.vote_required_uncalibrated, params_.large_step_confirmations))
  {
    votes_.pop_front();
  }
  Se2 consensus;
  const std::size_t cluster_size = bestVoteCluster(consensus);
  // 캘리브레이션이 양호했으면 3표, 데이터 부족/불량이면 5표 요구.
  const int required = trustOk() ?
    params_.vote_required : params_.vote_required_uncalibrated;
  if (static_cast<int>(cluster_size) < required) {
    return PcdOutcome::Voting;
  }

  // 검증 3: 스텝 게이트 — 합의가 현재 추정에서 "드리프트로 설명 가능한 만큼"만
  // 벗어나야 즉시 수락. 그 이상은 재획득(대형 스텝)으로 다수 합의를 더 요구.
  if (have_transform_) {
    const double elapsed = std::max(0.0, t - last_absolute_t_);
    const double allowance =
      params_.drift_rate_m_per_min / 60.0 * elapsed + params_.step_gate_margin;
    const double step = std::hypot(
      consensus.x - transform_.x, consensus.y - transform_.y);
    if (step > allowance) {
      if (static_cast<int>(cluster_size) < params_.large_step_confirmations) {
        return PcdOutcome::StepPending;
      }
      acceptAnchor(consensus, t);
      return PcdOutcome::Relocalized;
    }
  }
  acceptAnchor(consensus, t);
  return PcdOutcome::Anchored;
}

AnchorMode AnchorCore::update(double now_sec)
{
  const bool rtk_fresh = now_sec - last_rtk_t_ <= params_.rtk_fresh_sec;
  if (rtk_fresh != last_rtk_fresh_) {
    rtk_state_since_ = now_sec;
    last_rtk_fresh_ = rtk_fresh;
  }
  const double rtk_state_dur = now_sec - rtk_state_since_;

  if (!have_transform_) {
    mode_ = AnchorMode::Init;
    return mode_;
  }

  if (mode_ == AnchorMode::RtkActive) {
    if (rtk_fresh) {
      return mode_;  // 유지 (이탈은 freshness 창 자체가 디바운스)
    }
  } else if (rtk_fresh && rtk_state_dur >= params_.rtk_recover_sec) {
    mode_ = AnchorMode::RtkActive;   // 진입은 지속시간 요구 (플래핑 방어)
    return mode_;
  }

  const double absolute_age = now_sec - last_absolute_t_;
  if (absolute_age <= params_.pcd_active_window_sec) {
    mode_ = AnchorMode::PcdActive;
  } else if (budgetUsedM(now_sec) < params_.budget_max_m) {
    mode_ = AnchorMode::Hold;
  } else {
    mode_ = AnchorMode::Degraded;
  }
  return mode_;
}

std::optional<Se2> AnchorCore::mapToOdom() const
{
  if (!have_transform_) {
    return std::nullopt;
  }
  return transform_;
}

double AnchorCore::budgetUsedM(double now_sec) const
{
  if (!have_transform_) {
    return 0.0;
  }
  return params_.drift_rate_m_per_min / 60.0 *
         std::max(0.0, now_sec - last_absolute_t_);
}

double AnchorCore::lastAbsoluteAgeSec(double now_sec) const
{
  if (!have_transform_) {
    return -1.0;
  }
  return now_sec - last_absolute_t_;
}

}  // namespace loam_fgo_localization

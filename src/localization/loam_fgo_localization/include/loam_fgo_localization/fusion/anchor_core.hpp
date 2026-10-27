#ifndef SCV_LOCALIZATION__ANCHOR_CORE_HPP_
#define SCV_LOCALIZATION__ANCHOR_CORE_HPP_

#include <deque>
#include <optional>
#include <vector>

#include <Eigen/Dense>

namespace loam_fgo_localization
{

// SE(2) 최소 구현 (anchor 파이프라인은 GTSAM 비의존)
struct Se2
{
  double x{0.0};
  double y{0.0};
  double yaw{0.0};

  Se2 compose(const Se2 & other) const;   // this ∘ other
  Se2 inverse() const;
};

double normalizeAngle(double a);

// 계층형 앵커링 (FGO 대체; 설계 논의 2026-08-24).
//   RTK_ACTIVE : RTK 로 map->odom (x,y,θ) 3-상태 EKF 연속 갱신 (주 소스).
//                PCD 는 백그라운드 연산 유지 + RTK 기준 오차 채점(신뢰 캘리브레이션).
//   PCD_ACTIVE : RTK 상실 시, 4중 검증(자체품질은 노드에서/신뢰/투표/float 봉투/스텝
//                게이트)을 통과한 PCD 정합만 이벤트성으로 map->odom 갱신.
//   HOLD       : 둘 다 불가. map->odom 동결, odom 관성 주행.
//   DEGRADED   : 드리프트 예산 소진. 상위(waypoint 관리)의 감속/정지 판단용
//                — 기존 FGO status 규약("DEGRADED" 문자열) 유지.
struct AnchorParams
{
  // ---- RTK map->odom EKF ----
  double rtk_sigma_floor{0.05};        // m (측정 노이즈 바닥값)
  double rtk_gate_chi2{9.21};          // 2-DoF 99% (이상 RTK 방어)
  // GPS 안테나의 base_link 기준 수평 오프셋 (레버암). 미보상 시 RTK 추종이
  // 안테나 위치를 base 로 오인 -> ~레버암 크기의 계통오차 (A/B 재생 실측 0.2m).
  double antenna_offset_x{0.0};        // m (base 프레임)
  double antenna_offset_y{0.0};        // m
  // map->odom 이 흐르는 속도 = odom 드리프트율 (프로세스 노이즈, 랜덤워크 σ/√s)
  double process_xy_sigma{0.03};       // m/√s  (~0.23 m/분 std)
  double process_yaw_sigma{0.002};     // rad/√s
  // RTK 모드 디바운스 (플래핑 방어)
  double rtk_fresh_sec{1.0};           // 이 시간 내 RTK 측정 있음 = fresh
  double rtk_recover_sec{3.0};         // fresh 가 이만큼 지속돼야 RTK_ACTIVE 진입
  // RTK 단독 초기화: 이동방향 기반 yaw 추정 (FGO addGps 초기 앵커와 동일 발상)
  double yaw_init_min_travel{2.0};     // m

  // ---- PCD 신뢰 캘리브레이션 (RTK_ACTIVE 중 백그라운드 채점) ----
  double trust_window_sec{120.0};
  int trust_min_samples{10};
  double trust_xy_max{0.5};            // m   (윈도우 p95 상한)
  double trust_yaw_max{0.05};          // rad (윈도우 p95 상한)

  // ---- PCD 앵커 투표 (시간 일관성; BBS addGlobalInitVote 와 동일 패턴) ----
  int vote_required{3};                // 신뢰 캘리브레이션 양호 시
  int vote_required_uncalibrated{5};   // 캘리브레이션 데이터 부족/불량 시 (엄격)
  double vote_xy_tol{0.5};             // m
  double vote_yaw_tol{0.035};          // rad (~2 deg)
  double vote_timeout_sec{5.0};        // 이 이상 벌어지면 투표 리셋

  // ---- float GPS 봉투 검증 (앵커 아님 — PCD 대실패 검출용) ----
  double float_fresh_sec{2.0};
  double float_envelope_sigma_scale{3.0};
  double float_envelope_margin{2.0};   // m (안테나 오프셋 + float floor 여유)

  // ---- 스텝 게이트 / 드리프트 예산 ----
  double drift_rate_m_per_min{0.5};    // ESKF 실측 드리프트율
  double step_gate_margin{0.5};        // m (허용 스텝 = 예산 + 이 여유)
  int large_step_confirmations{6};     // 스텝 게이트 초과 시 요구 투표 수 (재획득)
  double budget_max_m{1.5};            // 예산 소진 -> DEGRADED
  double pcd_active_window_sec{10.0};  // 마지막 절대 갱신이 이 이내면 PCD_ACTIVE
};

enum class AnchorMode
{
  Init,        // 아직 map->odom 없음
  RtkActive,   // RTK 연속 갱신 중
  PcdActive,   // PCD 이벤트 앵커로 유지 중
  Hold,        // 절대측정 공백 (예산 내) -> 동결
  Degraded     // 예산 소진
};

const char * anchorModeName(AnchorMode m);

// addPcd 처리 결과 (노드 로깅용)
enum class PcdOutcome
{
  NoOdom,            // 측정 시각 odom 보간 불가 -> 폐기
  Calibrated,        // RTK_ACTIVE: 신뢰 채점에만 사용
  Voting,            // 투표 진행 중 (합의 미달)
  EnvelopeRejected,  // float 봉투 위반 -> 거부
  StepPending,       // 합의됐으나 스텝 게이트 초과, 추가 확인 대기
  Anchored,          // map->odom 갱신됨
  Relocalized        // 대형 스텝을 다수 합의로 수락 (재획득)
};

class AnchorCore
{
public:
  explicit AnchorCore(const AnchorParams & params);

  // /odom 샘플 공급 (100Hz). 버퍼 유지 (측정 시각 보간용).
  void addOdom(double t, const Se2 & pose);
  // /gps/measurement 공급 (map 프레임 위치).
  void addGpsRtk(double t, double x, double y, double sigma);
  void addGpsFloat(double t, double x, double y, double sigma);
  // /pcd/global_pose 의 수락된 정합 공급 (map 프레임 base 자세).
  PcdOutcome addPcd(double t, const Se2 & pose_map_base);

  // 모드 전이 판정 (노드 타이머에서 주기 호출).
  AnchorMode update(double now_sec);
  AnchorMode mode() const {return mode_;}

  // ---- 출력 ----
  std::optional<Se2> mapToOdom() const;
  // ---- 진단 ----
  double budgetUsedM(double now_sec) const;      // 드리프트 예산 사용량 [m]
  double lastAbsoluteAgeSec(double now_sec) const;
  int trustSamples() const {return static_cast<int>(trust_window_.size());}
  double trustP95Xy() const;
  double trustP95Yaw() const;
  bool trustOk() const;
  int pcdAnchorCount() const {return pcd_anchor_count_;}
  int rtkUpdateCount() const {return rtk_update_count_;}

private:
  struct TrustSample
  {
    double t;
    double e_xy;
    double e_yaw;
  };
  struct VoteEntry
  {
    double t;
    Se2 anchor;      // map->odom 후보
  };

  std::optional<Se2> interpolateOdom(double t) const;
  void ekfPredictTo(double t);
  bool ekfUpdateRtk(double t, double x, double y, double sigma);
  void tryRtkYawInit(double t, double x, double y, double sigma);
  void pruneTrustWindow(double t);
  // 투표 버퍼에서 최대 상호 일치 클러스터를 찾아 크기/평균을 반환.
  std::size_t bestVoteCluster(Se2 & consensus) const;
  void acceptAnchor(const Se2 & anchor, double t);

  AnchorParams params_;
  AnchorMode mode_{AnchorMode::Init};

  std::deque<std::pair<double, Se2>> odom_buffer_;

  // map->odom EKF 상태
  bool have_transform_{false};
  Se2 transform_;
  Eigen::Matrix3d covariance_{Eigen::Matrix3d::Identity()};
  double last_predict_t_{-1.0};

  // RTK 신선도/디바운스
  double last_rtk_t_{-1.0e18};
  bool last_rtk_fresh_{false};
  double rtk_state_since_{-1.0e18};

  // RTK 단독 yaw 초기화 누적
  bool have_first_rtk_{false};
  double first_rtk_x_{0.0}, first_rtk_y_{0.0};
  Se2 first_rtk_odom_;

  // float 봉투
  bool have_float_{false};
  double float_t_{0.0}, float_x_{0.0}, float_y_{0.0}, float_sigma_{0.0};

  // PCD 신뢰 캘리브레이션 / 투표
  std::deque<TrustSample> trust_window_;
  std::deque<VoteEntry> votes_;

  double last_absolute_t_{-1.0e18};    // 마지막 절대 갱신 (RTK EKF or PCD 앵커)
  int pcd_anchor_count_{0};
  int rtk_update_count_{0};
};

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__ANCHOR_CORE_HPP_

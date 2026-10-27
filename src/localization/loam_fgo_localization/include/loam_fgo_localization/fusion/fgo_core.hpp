#ifndef SCV_LOCALIZATION__FGO_CORE_HPP_
#define SCV_LOCALIZATION__FGO_CORE_HPP_

#include <deque>
#include <memory>
#include <optional>

#include <gtsam/geometry/Pose2.h>
#include <gtsam/geometry/Point2.h>
#include <gtsam/nonlinear/ISAM2.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>

namespace loam_fgo_localization
{

// ---- 측정 입력 (ROS 비의존) ----
struct OdomSample            // /odom (odom 프레임 base pose)
{
  double t{0.0};
  gtsam::Pose2 pose;
};

struct GpsMeasurement        // /gps/measurement (map 프레임 위치)
{
  double t{0.0};
  gtsam::Point2 position{0.0, 0.0};
  double sigma_x{1.5};
  double sigma_y{1.5};
  bool rtk_fixed{false};
};

struct PcdMeasurement        // /pcd/global_pose (map 프레임 SE(2) pose)
{
  double t{0.0};
  gtsam::Pose2 pose;
  Eigen::Matrix3d covariance{Eigen::Matrix3d::Identity()};  // (x, y, yaw)
};

enum class FgoStatus
{
  Init,       // 아직 절대 측정으로 앵커되지 않음
  Ok,         // 정상 (최근 절대 팩터 존재)
  Degraded    // 절대 팩터가 워치독 시간 이상 없음 -> 하위 시스템 감속 판단용
};

struct FgoParams
{
  // keyframe 정책
  double keyframe_dist{0.5};          // m
  double keyframe_time{0.5};          // s (정지 중에도 시간 경과로 생성)
  // 참고: v1 은 marginalization 없는 순수 iSAM2 (그래프가 주행 내내 성장; 2Hz keyframe
  // 기준 1시간 ≈ 7200 노드로 문제 없음). IncrementalFixedLagSmoother 는 시간 격차가
  // 큰 bias-pose 팩터와 함께 marginalize 시 크래시하는 취약점이 있어 보류.
  // smoother_lag 는 odom 버퍼/지연측정 허용 범위로만 사용.
  double smoother_lag{20.0};          // s

  // odom between factor 노이즈 (이동거리 비례 + 바닥값)
  // TODO(tuning): 회전 비례 항(per_rad) 부재 — 선회 중 ESKF yaw 드리프트를 과신해
  // 절대측정 보정이 지연되는 현상 관측됨(2026-07-31). 원인 확정 후 AMCL α1/α4 형태로 추가 예정.
  double odom_pos_noise_per_m{0.02};  // m/m
  double odom_yaw_noise_per_m{0.005}; // rad/m
  double odom_pos_noise_floor{0.005}; // m (keyframe 당)
  double odom_yaw_noise_floor{0.002}; // rad

  // GPS
  double gps_factor_min_interval{0.2}; // s (10Hz -> 최대 5Hz 로 다운샘플)
  double gps_huber_k{1.345};
  // float(비RTK) 처리 (2026-08-03, 별도세션 bag 분석 반영):
  //   이 환경에서 float 실오차(3~10m)는 odom 드리프트(~0.5m/분)보다 나쁨
  //   -> 기본은 float 미사용 (PCD or RTK 만 절대 팩터. 공백 시 map->odom 자동 동결,
  //      워치독 DEGRADED -> waypoint_manage goal 동결과 정합).
  //   장기 공백(수십 분)의 드리프트 상한이 필요하면 use_float=true + inflation 사용.
  bool gps_use_float{false};
  double gps_float_sigma_inflation{4.0}; // use_float=true 일 때 float σ 인플레이션
  // GPS bias 체인
  double bias_node_interval{10.0};    // s
  double bias_random_walk_sigma{0.1}; // m (노드 간)
  double bias_prior_sigma{3.0};       // m (B_0 약한 prior)
  double bias_rtk_prior_sigma{0.1};   // m (RTK_FIXED 측정 시 현재 bias 앵커)

  // PCD  (2026-07-31 락아웃 진단 반영)
  //   Hessian 공분산은 "정밀도"(반복 재현성)이지 "정확도"가 아니라 과신 -> 전역 스케일 보정.
  //   게이트는 relax 히스테리시스: 연속 거부 N회 -> 완화 모드(공분산 인플레 수락) ->
  //   정상 게이트 통과가 나오면 복귀. "무조건 수락" 제거 (급격한 당김/오정합 유입 방지).
  double pcd_cauchy_k{1.0};
  double pcd_gate_chi2{11.34};        // 3-DoF 99%
  int pcd_gate_relax_after{10};       // 연속 게이트아웃 N회 -> 완화 모드 진입
  double pcd_cov_scale{100.0};        // 보고 공분산 x scale (σ x10)
  double pcd_relax_cov_scale{25.0};   // 완화 수락 시 추가 인플레 (σ x5)
  double pcd_sigma_floor_xy{0.05};    // m (스케일 적용 후 바닥값)
  double pcd_sigma_floor_yaw{0.01};   // rad

  // 초기화/워치독
  double init_yaw_sigma{3.1416};      // rad (첫 keyframe 의 자유도 고정용 약한 prior)
  // GPS 단독 앵커: 이동방향 기반 yaw 추정 후 pose prior 로 앵커
  //   (π-넓은 yaw + 위치측정 조합의 최적화 발산 방지; 2026-07-31 run2 발산 진단 반영)
  double yaw_init_min_travel{2.0};    // m (GPS/odom 변위가 이만큼 쌓이면 yaw 추정)
  double yaw_init_prior_sigma{0.3};   // rad (추정 yaw 에 거는 prior)
  double watchdog_sec{10.0};          // 절대 팩터 공백 허용 시간
};

// 슬라이딩 윈도우 FGO (ROS 비의존).
//   변수: X_i = Pose2 (map 프레임 base), B_j = Point2 (GPS 바이어스, 랜덤워크 체인)
//   팩터: odom between / GPS(z = t(X)+B, Huber) / PCD pose prior(Cauchy, chi2 게이트)
//   스레딩: 단일 스레드 가정 (호출측에서 직렬화).
class FgoCore
{
public:
  explicit FgoCore(const FgoParams & params);
  ~FgoCore();

  // /odom 샘플 공급 (100Hz). keyframe 생성 조건을 만족하면 내부에서 노드 추가.
  void addOdom(const OdomSample & sample);
  // 절대 측정 공급. 내부에서 해당 시각의 keyframe 에 팩터로 부착.
  void addGps(const GpsMeasurement & measurement);
  bool addPcd(const PcdMeasurement & measurement);   // false = 게이트 아웃

  // 그래프 최적화 (팩터가 쌓였을 때만 실제 수행).
  void update(double now_sec);

  // ---- 출력 ----
  bool anchored() const {return anchored_;}
  FgoStatus status(double now_sec) const;
  // 최신 keyframe 의 map pose 와 그 시각의 odom pose (map->odom 합성용).
  std::optional<gtsam::Pose2> latestMapPose() const;
  std::optional<gtsam::Pose2> latestOdomPose() const;
  gtsam::Point2 gpsBias() const;
  int pcdAccepted() const {return pcd_accepted_;}
  //: PCD 인자가 마지막으로 들어온 뒤 경과 시간(초). 한 번도 없었으면 -1.
  double pcdAgeSec(double now_sec) const
  {
    return last_pcd_factor_t_ < 0.0 ? -1.0 : now_sec - last_pcd_factor_t_;
  }
  int pcdRejected() const {return pcd_rejected_;}

private:
  struct Keyframe
  {
    gtsam::Key key;
    double t;
    gtsam::Pose2 odom_pose;   // 이 keyframe 시각의 odom 프레임 pose
  };

  // t 시각 odom pose (버퍼 보간). 버퍼 범위 밖이면 nullopt.
  std::optional<gtsam::Pose2> interpolateOdom(double t) const;
  // t 시각 keyframe 확보 (없으면 생성). 실패(odom 미보간) 시 nullptr.
  const Keyframe * ensureKeyframe(double t);
  const Keyframe * nearestKeyframe(double t, double tolerance) const;
  gtsam::Key currentBiasKey(double t);
  gtsam::Pose2 estimateOf(gtsam::Key key) const;
  void pushKeyframe(double t, const gtsam::Pose2 & odom_pose);

  FgoParams params_;
  std::unique_ptr<gtsam::ISAM2> smoother_;
  gtsam::NonlinearFactorGraph new_factors_;
  gtsam::Values new_values_;
  bool pending_{false};

  std::deque<OdomSample> odom_buffer_;
  std::deque<Keyframe> keyframes_;    // 전체 유지 (marginalization 없음)
  uint64_t next_pose_index_{0};
  uint64_t next_bias_index_{0};
  double last_bias_node_t_{-1.0};
  bool have_bias_node_{false};

  bool anchored_{false};
  double last_gps_factor_t_{-1.0};
  double last_absolute_factor_t_{-1.0};
  //: PCD(LiDAR 맵 정합) 전용. last_absolute_factor_t_ 는 GPS 로도 갱신되므로
  //: 그것만 보면 LiDAR 채널이 완전히 죽어도 watchdog 이 OK 를 낸다.
  //: 실측: 145 초 동안 pcd accepted=0 인데 status=Ok 였다.
  double last_pcd_factor_t_{-1.0};
  int pcd_consecutive_rejects_{0};
  bool pcd_gate_relaxed_{false};      // 완화 모드 (정상 게이트 통과 시 해제)
  int pcd_accepted_{0};
  int pcd_rejected_{0};

  // GPS 단독 앵커용 (이동방향 기반 yaw 초기화)
  bool have_first_gps_{false};
  gtsam::Point2 first_gps_position_{0.0, 0.0};
  gtsam::Pose2 first_gps_odom_pose_;

  // update() 이후 캐시된 최신 추정
  std::optional<gtsam::Pose2> latest_map_pose_;
  std::optional<gtsam::Pose2> latest_odom_pose_;
  gtsam::Point2 latest_bias_{0.0, 0.0};
};

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__FGO_CORE_HPP_

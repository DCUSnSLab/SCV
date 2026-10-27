#include <algorithm>
#include <cmath>
#include <memory>
#include <string>

#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/string.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "loam_fgo_localization/fusion/anchor_core.hpp"
#include "loam_fgo_localization/fusion/anchor_output_slew.hpp"

namespace loam_fgo_localization
{
namespace
{

double yawFromQuaternion(const geometry_msgs::msg::Quaternion & q)
{
  return std::atan2(
    2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z));
}

geometry_msgs::msg::Quaternion quaternionFromYaw(double yaw)
{
  geometry_msgs::msg::Quaternion q;
  q.z = std::sin(0.5 * yaw);
  q.w = std::cos(0.5 * yaw);
  return q;
}

}  // namespace

// 계층형 앵커링 노드: fgo_fusion_node 대체 (A/B 비교용으로 둘 다 유지).
//  입력: /odom(100Hz), /gps/measurement(RTK=EKF 갱신, FLOAT=봉투 검증),
//        /pcd/global_pose(수락 정합만 — cov[35]>0)
//  출력: map->odom TF + /localization/map_to_odom + /global_pose (기존 토픽명 유지)
//        /anchor/status (INIT/RTK_ACTIVE/PCD_ACTIVE/HOLD/DEGRADED; DEGRADED 문자열은
//        기존 FGO 규약과 동일 — 상위 waypoint 관리 감속/정지 판단용)
//        /anchor/pcd_trust, /anchor/drift_budget (진단)
//  모든 콜백/타이머는 기본 single-threaded executor 직렬 실행 -> core 락 불필요.
class AnchorManagerNode : public rclcpp::Node
{
public:
  AnchorManagerNode()
  : Node("anchor_manager"), core_(declareParams())
  {
    odom_topic_ = declare_parameter<std::string>("topics.odom", "/odom");
    gps_topic_ = declare_parameter<std::string>(
      "topics.gps_measurement", "/gps/measurement");
    pcd_topic_ = declare_parameter<std::string>(
      "topics.pcd_global_pose", "/pcd/global_pose");
    map_to_odom_topic_ = declare_parameter<std::string>(
      "topics.map_to_odom", "/localization/map_to_odom");
    global_pose_topic_ = declare_parameter<std::string>(
      "topics.global_pose", "/global_pose");
    status_topic_ = declare_parameter<std::string>("topics.status", "/anchor/status");
    trust_topic_ = declare_parameter<std::string>("topics.trust", "/anchor/pcd_trust");
    budget_topic_ = declare_parameter<std::string>(
      "topics.budget", "/anchor/drift_budget");
    map_frame_ = declare_parameter<std::string>("frames.map", "map");
    odom_frame_ = declare_parameter<std::string>("frames.odom", "odom");
    base_frame_ = declare_parameter<std::string>("frames.base_link", "base_link");
    publish_tf_ = declare_parameter<bool>("publish_tf", true);
    status_rate_hz_ = declare_parameter<double>("status_rate_hz", 5.0);
    // TF 는 고주기 재스탬프 (fgo_fusion_node 와 동일한 이유: tf2 공통시각).
    tf_rate_hz_ = declare_parameter<double>("tf_rate_hz", 50.0);
    // 앵커 갱신 점프를 제어기에 완만히 전달 (슬루 제한).
    slew_max_m_per_s_ = declare_parameter<double>("slew.max_m_per_s", 0.5);
    slew_max_rad_per_s_ = declare_parameter<double>("slew.max_rad_per_s", 0.2);

    const auto sensor_qos = rclcpp::SensorDataQoS();
    odom_subscription_ = create_subscription<nav_msgs::msg::Odometry>(
      odom_topic_, sensor_qos,
      std::bind(&AnchorManagerNode::odomCallback, this, std::placeholders::_1));
    gps_subscription_ =
      create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
      gps_topic_, sensor_qos,
      std::bind(&AnchorManagerNode::gpsCallback, this, std::placeholders::_1));
    pcd_subscription_ = create_subscription<nav_msgs::msg::Odometry>(
      pcd_topic_, sensor_qos,
      std::bind(&AnchorManagerNode::pcdCallback, this, std::placeholders::_1));

    map_to_odom_publisher_ =
      create_publisher<geometry_msgs::msg::TransformStamped>(
      map_to_odom_topic_, sensor_qos);
    global_pose_publisher_ = create_publisher<nav_msgs::msg::Odometry>(
      global_pose_topic_, sensor_qos);
    status_publisher_ = create_publisher<std_msgs::msg::String>(
      status_topic_, rclcpp::QoS(1).transient_local().reliable());
    trust_publisher_ = create_publisher<std_msgs::msg::Float64MultiArray>(
      trust_topic_, 10);
    budget_publisher_ = create_publisher<std_msgs::msg::Float64>(budget_topic_, 10);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    status_timer_ = rclcpp::create_timer(
      this, get_clock(), rclcpp::Duration::from_seconds(1.0 / status_rate_hz_),
      std::bind(&AnchorManagerNode::statusCycle, this));
    tf_timer_ = rclcpp::create_timer(
      this, get_clock(), rclcpp::Duration::from_seconds(1.0 / tf_rate_hz_),
      std::bind(&AnchorManagerNode::publishTfCycle, this));

    publishStatus(AnchorMode::Init);
    RCLCPP_INFO(
      get_logger(), "anchor manager started: odom=%s gps=%s pcd=%s -> %s",
      odom_topic_.c_str(), gps_topic_.c_str(), pcd_topic_.c_str(),
      map_to_odom_topic_.c_str());
  }

private:
  AnchorParams declareParams()
  {
    AnchorParams p;
    p.rtk_sigma_floor = declare_parameter<double>("rtk.sigma_floor", p.rtk_sigma_floor);
    p.rtk_gate_chi2 = declare_parameter<double>("rtk.gate_chi2", p.rtk_gate_chi2);
    p.antenna_offset_x = declare_parameter<double>(
      "rtk.antenna_offset_x", p.antenna_offset_x);
    p.antenna_offset_y = declare_parameter<double>(
      "rtk.antenna_offset_y", p.antenna_offset_y);
    p.process_xy_sigma = declare_parameter<double>(
      "rtk.process_xy_sigma", p.process_xy_sigma);
    p.process_yaw_sigma = declare_parameter<double>(
      "rtk.process_yaw_sigma", p.process_yaw_sigma);
    p.rtk_fresh_sec = declare_parameter<double>("rtk.fresh_sec", p.rtk_fresh_sec);
    p.rtk_recover_sec = declare_parameter<double>("rtk.recover_sec", p.rtk_recover_sec);
    p.yaw_init_min_travel = declare_parameter<double>(
      "rtk.yaw_init_min_travel", p.yaw_init_min_travel);
    p.trust_window_sec = declare_parameter<double>(
      "trust.window_sec", p.trust_window_sec);
    p.trust_min_samples = declare_parameter<int>(
      "trust.min_samples", p.trust_min_samples);
    p.trust_xy_max = declare_parameter<double>("trust.xy_max", p.trust_xy_max);
    p.trust_yaw_max = declare_parameter<double>("trust.yaw_max", p.trust_yaw_max);
    p.vote_required = declare_parameter<int>("vote.required", p.vote_required);
    p.vote_required_uncalibrated = declare_parameter<int>(
      "vote.required_uncalibrated", p.vote_required_uncalibrated);
    p.vote_xy_tol = declare_parameter<double>("vote.xy_tol", p.vote_xy_tol);
    p.vote_yaw_tol = declare_parameter<double>("vote.yaw_tol", p.vote_yaw_tol);
    p.vote_timeout_sec = declare_parameter<double>(
      "vote.timeout_sec", p.vote_timeout_sec);
    p.float_fresh_sec = declare_parameter<double>(
      "float_envelope.fresh_sec", p.float_fresh_sec);
    p.float_envelope_sigma_scale = declare_parameter<double>(
      "float_envelope.sigma_scale", p.float_envelope_sigma_scale);
    p.float_envelope_margin = declare_parameter<double>(
      "float_envelope.margin", p.float_envelope_margin);
    p.drift_rate_m_per_min = declare_parameter<double>(
      "budget.drift_rate_m_per_min", p.drift_rate_m_per_min);
    p.step_gate_margin = declare_parameter<double>(
      "budget.step_gate_margin", p.step_gate_margin);
    p.large_step_confirmations = declare_parameter<int>(
      "budget.large_step_confirmations", p.large_step_confirmations);
    p.budget_max_m = declare_parameter<double>("budget.max_m", p.budget_max_m);
    p.pcd_active_window_sec = declare_parameter<double>(
      "budget.pcd_active_window_sec", p.pcd_active_window_sec);
    return p;
  }

  void odomCallback(const nav_msgs::msg::Odometry::SharedPtr message)
  {
    const Se2 pose{
      message->pose.pose.position.x, message->pose.pose.position.y,
      yawFromQuaternion(message->pose.pose.orientation)};
    core_.addOdom(rclcpp::Time(message->header.stamp).seconds(), pose);
    latest_odom_pose_ = pose;
    latest_odom_stamp_ = message->header.stamp;
    have_latest_odom_ = true;
  }

  void gpsCallback(
    const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr message)
  {
    const double t = rclcpp::Time(message->header.stamp).seconds();
    const double x = message->pose.pose.position.x;
    const double y = message->pose.pose.position.y;
    const double sigma = std::sqrt(std::max(message->pose.covariance[0], 1e-6));
    // gps_measurement_node 규약: cov[14] = fix class (2=RTK_FIXED, 1=FLOAT)
    if (message->pose.covariance[14] >= 1.5) {
      core_.addGpsRtk(t, x, y, sigma);
    } else {
      core_.addGpsFloat(t, x, y, sigma);
    }
  }

  void pcdCallback(const nav_msgs::msg::Odometry::SharedPtr message)
  {
    // yaw 분산 0 = 정합 결과 아님 (localizer 의 odom 예측 재발행) -> 제외.
    // odom 정보 이중 계상 방지 (fgo_fusion_node 와 동일한 규약).
    if (message->pose.covariance[35] <= 0.0) {
      return;
    }
    const Se2 pose{
      message->pose.pose.position.x, message->pose.pose.position.y,
      yawFromQuaternion(message->pose.pose.orientation)};
    const PcdOutcome outcome =
      core_.addPcd(rclcpp::Time(message->header.stamp).seconds(), pose);
    switch (outcome) {
      case PcdOutcome::Anchored:
        RCLCPP_INFO_THROTTLE(
          get_logger(), *get_clock(), 5000,
          "PCD anchor accepted (#%d): map->odom updated", core_.pcdAnchorCount());
        break;
      case PcdOutcome::Relocalized:
        RCLCPP_WARN(
          get_logger(),
          "PCD anchor accepted with LARGE STEP (relocalization, %d confirmations)",
          core_.pcdAnchorCount());
        break;
      case PcdOutcome::EnvelopeRejected:
        RCLCPP_WARN_THROTTLE(
          get_logger(), *get_clock(), 2000,
          "PCD candidate rejected by float GPS envelope");
        break;
      case PcdOutcome::StepPending:
        RCLCPP_WARN_THROTTLE(
          get_logger(), *get_clock(), 2000,
          "PCD consensus exceeds drift-explainable step; awaiting more confirmations");
        break;
      case PcdOutcome::NoOdom:
        RCLCPP_WARN_THROTTLE(
          get_logger(), *get_clock(), 5000,
          "PCD measurement dropped: no odom at its stamp");
        break;
      case PcdOutcome::Calibrated:
      case PcdOutcome::Voting:
        break;
    }
  }

  void publishStatus(AnchorMode mode)
  {
    if (have_last_mode_ && mode == last_mode_) {
      return;
    }
    if (have_last_mode_) {
      RCLCPP_INFO(
        get_logger(), "anchor mode: %s -> %s",
        anchorModeName(last_mode_), anchorModeName(mode));
    }
    last_mode_ = mode;
    have_last_mode_ = true;
    std_msgs::msg::String message;
    message.data = anchorModeName(mode);
    status_publisher_->publish(message);
  }

  void statusCycle()
  {
    // "지금"은 odom header 스탬프 기준 (100Hz 라 사실상 연속).
    // 노드 클럭(/clock or wall)을 쓰면 header 와 다른 타임라인일 때
    // (eval bag 재생: 수신시각/원본스탬프 9.8일 차 실측) 나이/예산이 전부 깨진다.
    // 모든 이벤트 시각(last_rtk_t_ 등)이 header 기반이므로 기준을 통일한다.
    // odom 완전 사망 시 시간이 멈추지만 그때는 로컬라이제이션 전체가 무의미.
    const double now = have_latest_odom_ ?
      rclcpp::Time(latest_odom_stamp_).seconds() :
      get_clock()->now().seconds();
    publishStatus(core_.update(now));

    std_msgs::msg::Float64 budget;
    budget.data = core_.budgetUsedM(now);
    budget_publisher_->publish(budget);

    // [표본수, p95_xy(m), p95_yaw(rad), ok(0/1)]
    std_msgs::msg::Float64MultiArray trust;
    trust.data = {
      static_cast<double>(core_.trustSamples()),
      core_.trustP95Xy(), core_.trustP95Yaw(),
      core_.trustOk() ? 1.0 : 0.0};
    trust_publisher_->publish(trust);

    RCLCPP_INFO_THROTTLE(
      get_logger(), *get_clock(), 5000,
      "anchor: mode=%s rtk_updates=%d pcd_anchors=%d abs_age=%.1fs "
      "budget=%.2fm trust(n=%d, p95=%.2fm/%.3frad, %s)",
      anchorModeName(core_.mode()), core_.rtkUpdateCount(), core_.pcdAnchorCount(),
      core_.lastAbsoluteAgeSec(now), core_.budgetUsedM(now),
      core_.trustSamples(), core_.trustP95Xy(), core_.trustP95Yaw(),
      core_.trustOk() ? "ok" : "insufficient");
  }

  // 고주기: 슬루 제한된 map->odom 을 현재 시각으로 재스탬프 발행.
  void publishTfCycle()
  {
    const auto target = core_.mapToOdom();
    if (!target) {
      return;
    }
    RCLCPP_DEBUG_THROTTLE(
      get_logger(), *get_clock(), 2000,
      "tf: target=(%.2f %.2f %.3f) current=(%.2f %.2f %.3f)",
      target->x, target->y, target->yaw, current_.x, current_.y, current_.yaw);
    if (!have_current_) {
      current_ = *target;      // 최초 앵커: 스냅 (identity 에서 슬루하지 않음)
      have_current_ = true;
    } else {
      const double dt = 1.0 / tf_rate_hz_;
      const double max_step = slew_max_m_per_s_ * dt;
      const double max_yaw_step = slew_max_rad_per_s_ * dt;
      current_ = loam_fgo_localization::slewAnchorAtVehicle(
        current_, *target, latest_odom_pose_, max_step, max_yaw_step);
    }

    const rclcpp::Time now = get_clock()->now();
    geometry_msgs::msg::TransformStamped transform;
    transform.header.stamp = now;
    transform.header.frame_id = map_frame_;
    transform.child_frame_id = odom_frame_;
    transform.transform.translation.x = current_.x;
    transform.transform.translation.y = current_.y;
    transform.transform.rotation = quaternionFromYaw(current_.yaw);
    if (publish_tf_) {
      tf_broadcaster_->sendTransform(transform);
    }
    map_to_odom_publisher_->publish(transform);

    if (!have_latest_odom_) {
      return;
    }
    const Se2 map_base = current_.compose(latest_odom_pose_);
    nav_msgs::msg::Odometry global_pose;
    global_pose.header.stamp = latest_odom_stamp_;
    global_pose.header.frame_id = map_frame_;
    global_pose.child_frame_id = base_frame_;
    global_pose.pose.pose.position.x = map_base.x;
    global_pose.pose.pose.position.y = map_base.y;
    global_pose.pose.pose.orientation = quaternionFromYaw(map_base.yaw);
    global_pose_publisher_->publish(global_pose);
  }

  AnchorCore core_;
  std::string odom_topic_, gps_topic_, pcd_topic_;
  std::string map_to_odom_topic_, global_pose_topic_;
  std::string status_topic_, trust_topic_, budget_topic_;
  std::string map_frame_, odom_frame_, base_frame_;
  bool publish_tf_{true};
  double status_rate_hz_{5.0};
  double tf_rate_hz_{50.0};
  double slew_max_m_per_s_{0.5};
  double slew_max_rad_per_s_{0.2};

  AnchorMode last_mode_{AnchorMode::Init};
  bool have_last_mode_{false};
  Se2 current_;                 // 슬루 제한된 발행용 map->odom
  bool have_current_{false};
  Se2 latest_odom_pose_;
  builtin_interfaces::msg::Time latest_odom_stamp_;
  bool have_latest_odom_{false};

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscription_;
  rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr
    gps_subscription_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr pcd_subscription_;
  rclcpp::Publisher<geometry_msgs::msg::TransformStamped>::SharedPtr
    map_to_odom_publisher_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr global_pose_publisher_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_publisher_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr trust_publisher_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr budget_publisher_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  rclcpp::TimerBase::SharedPtr status_timer_;
  rclcpp::TimerBase::SharedPtr tf_timer_;
};

}  // namespace loam_fgo_localization

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<loam_fgo_localization::AnchorManagerNode>());
  rclcpp::shutdown();
  return 0;
}

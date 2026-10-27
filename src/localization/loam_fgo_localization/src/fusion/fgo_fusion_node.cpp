#include <cmath>
#include <cstdio>
#include <memory>
#include <string>

#include <geometry_msgs/msg/point_stamped.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "loam_fgo_localization/fusion/fgo_core.hpp"

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

const char * statusName(FgoStatus s)
{
  switch (s) {
    case FgoStatus::Init: return "INIT";
    case FgoStatus::Ok: return "OK";
    case FgoStatus::Degraded: return "DEGRADED";
  }
  return "INIT";
}

}  // namespace

// FGO 융합 노드: 규칙 기반 mode manager(src/temp) 대체.
//  입력: /odom(100Hz, between), /gps/measurement(위치+bias), /pcd/global_pose(SE(2) prior)
//  출력: map->odom TF + /localization/map_to_odom + /global_pose (기존 토픽명 유지)
//        /fgo/status (워치독), /fgo/gps_bias (진단/논문용)
//  모든 콜백/타이머는 기본 single-threaded executor 에서 직렬 실행 -> core 락 불필요.
class FgoFusionNode : public rclcpp::Node
{
public:
  FgoFusionNode()
  : Node("fgo_fusion"), core_(declareParams())
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
    status_topic_ = declare_parameter<std::string>("topics.status", "/fgo/status");
    bias_topic_ = declare_parameter<std::string>("topics.gps_bias", "/fgo/gps_bias");
    map_frame_ = declare_parameter<std::string>("frames.map", "map");
    odom_frame_ = declare_parameter<std::string>("frames.odom", "odom");
    base_frame_ = declare_parameter<std::string>("frames.base_link", "base_link");
    publish_tf_ = declare_parameter<bool>("publish_tf", true);
    // 최적화(solve)와 TF 발행을 분리: map->odom 값은 solve 주기로만 갱신되지만,
    // TF 스탬프가 저주기면 tf2 의 공통시각이 거기 묶여 map->base 가 계단처럼 보임.
    // -> TF 는 고주기로 최신 값을 재스탬프해 발행.
    publish_rate_hz_ = declare_parameter<double>("publish_rate_hz", 5.0);
    tf_rate_hz_ = declare_parameter<double>("tf_rate_hz", 50.0);

    const auto sensor_qos = rclcpp::SensorDataQoS();
    odom_subscription_ = create_subscription<nav_msgs::msg::Odometry>(
      odom_topic_, sensor_qos,
      std::bind(&FgoFusionNode::odomCallback, this, std::placeholders::_1));
    gps_subscription_ =
      create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
      gps_topic_, sensor_qos,
      std::bind(&FgoFusionNode::gpsCallback, this, std::placeholders::_1));
    pcd_subscription_ = create_subscription<nav_msgs::msg::Odometry>(
      pcd_topic_, sensor_qos,
      std::bind(&FgoFusionNode::pcdCallback, this, std::placeholders::_1));

    map_to_odom_publisher_ =
      create_publisher<geometry_msgs::msg::TransformStamped>(
      map_to_odom_topic_, sensor_qos);
    global_pose_publisher_ = create_publisher<nav_msgs::msg::Odometry>(
      global_pose_topic_, sensor_qos);
    status_publisher_ = create_publisher<std_msgs::msg::String>(
      status_topic_, rclcpp::QoS(1).transient_local().reliable());
    bias_publisher_ = create_publisher<geometry_msgs::msg::PointStamped>(
      bias_topic_, 10);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    timer_ = rclcpp::create_timer(
      this, get_clock(), rclcpp::Duration::from_seconds(1.0 / publish_rate_hz_),
      std::bind(&FgoFusionNode::solveCycle, this));
    tf_timer_ = rclcpp::create_timer(
      this, get_clock(), rclcpp::Duration::from_seconds(1.0 / tf_rate_hz_),
      std::bind(&FgoFusionNode::publishTfCycle, this));

    publishStatus(FgoStatus::Init);
    RCLCPP_INFO(
      get_logger(), "FGO fusion started: odom=%s gps=%s pcd=%s -> %s (%.1f Hz)",
      odom_topic_.c_str(), gps_topic_.c_str(), pcd_topic_.c_str(),
      map_to_odom_topic_.c_str(), publish_rate_hz_);
  }

private:
  FgoParams declareParams()
  {
    FgoParams p;
    p.keyframe_dist = declare_parameter<double>("keyframe.dist_m", p.keyframe_dist);
    p.keyframe_time = declare_parameter<double>("keyframe.time_sec", p.keyframe_time);
    p.smoother_lag = declare_parameter<double>("smoother.lag_sec", p.smoother_lag);
    p.odom_pos_noise_per_m = declare_parameter<double>(
      "odom.pos_noise_per_m", p.odom_pos_noise_per_m);
    p.odom_yaw_noise_per_m = declare_parameter<double>(
      "odom.yaw_noise_per_m", p.odom_yaw_noise_per_m);
    p.odom_pos_noise_floor = declare_parameter<double>(
      "odom.pos_noise_floor", p.odom_pos_noise_floor);
    p.odom_yaw_noise_floor = declare_parameter<double>(
      "odom.yaw_noise_floor", p.odom_yaw_noise_floor);
    p.gps_factor_min_interval = declare_parameter<double>(
      "gps.factor_min_interval_sec", p.gps_factor_min_interval);
    p.gps_huber_k = declare_parameter<double>("gps.huber_k", p.gps_huber_k);
    // float 정책: "off"(기본, PCD/RTK만) | "inflated"(σ x N 약한 닻) | "normal"
    const std::string float_mode = declare_parameter<std::string>(
      "gps.float_mode", "off");
    p.gps_use_float = float_mode != "off";
    p.gps_float_sigma_inflation = float_mode == "normal" ? 1.0 :
      declare_parameter<double>("gps.float_sigma_inflation", p.gps_float_sigma_inflation);
    p.bias_node_interval = declare_parameter<double>(
      "gps.bias_node_interval_sec", p.bias_node_interval);
    p.bias_random_walk_sigma = declare_parameter<double>(
      "gps.bias_random_walk_sigma", p.bias_random_walk_sigma);
    p.bias_prior_sigma = declare_parameter<double>(
      "gps.bias_prior_sigma", p.bias_prior_sigma);
    p.bias_rtk_prior_sigma = declare_parameter<double>(
      "gps.bias_rtk_prior_sigma", p.bias_rtk_prior_sigma);
    p.pcd_cauchy_k = declare_parameter<double>("pcd.cauchy_k", p.pcd_cauchy_k);
    p.pcd_gate_chi2 = declare_parameter<double>("pcd.gate_chi2", p.pcd_gate_chi2);
    p.pcd_gate_relax_after = declare_parameter<int>(
      "pcd.gate_relax_after", p.pcd_gate_relax_after);
    p.pcd_cov_scale = declare_parameter<double>("pcd.cov_scale", p.pcd_cov_scale);
    p.pcd_relax_cov_scale = declare_parameter<double>(
      "pcd.relax_cov_scale", p.pcd_relax_cov_scale);
    p.pcd_sigma_floor_xy = declare_parameter<double>(
      "pcd.sigma_floor_xy", p.pcd_sigma_floor_xy);
    p.pcd_sigma_floor_yaw = declare_parameter<double>(
      "pcd.sigma_floor_yaw", p.pcd_sigma_floor_yaw);
    p.init_yaw_sigma = declare_parameter<double>("init.yaw_sigma", p.init_yaw_sigma);
    p.yaw_init_min_travel = declare_parameter<double>(
      "init.yaw_init_min_travel", p.yaw_init_min_travel);
    p.yaw_init_prior_sigma = declare_parameter<double>(
      "init.yaw_init_prior_sigma", p.yaw_init_prior_sigma);
    p.watchdog_sec = declare_parameter<double>("watchdog_sec", p.watchdog_sec);
    return p;
  }

  void odomCallback(const nav_msgs::msg::Odometry::SharedPtr message)
  {
    OdomSample sample;
    sample.t = rclcpp::Time(message->header.stamp).seconds();
    sample.pose = gtsam::Pose2(
      message->pose.pose.position.x, message->pose.pose.position.y,
      yawFromQuaternion(message->pose.pose.orientation));
    core_.addOdom(sample);
    latest_odom_pose_ = sample.pose;
    latest_odom_stamp_ = message->header.stamp;
    have_latest_odom_ = true;
  }

  void gpsCallback(
    const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr message)
  {
    GpsMeasurement measurement;
    measurement.t = rclcpp::Time(message->header.stamp).seconds();
    measurement.position = gtsam::Point2(
      message->pose.pose.position.x, message->pose.pose.position.y);
    measurement.sigma_x = std::sqrt(std::max(message->pose.covariance[0], 1e-6));
    measurement.sigma_y = std::sqrt(std::max(message->pose.covariance[7], 1e-6));
    // gps_measurement_node 규약: cov[14] = fix class (2 = RTK_FIXED)
    measurement.rtk_fixed = message->pose.covariance[14] >= 1.5;
    core_.addGps(measurement);
  }

  void pcdCallback(const nav_msgs::msg::Odometry::SharedPtr message)
  {
    // yaw 분산 0 = 스캔 정합 결과가 아님 (localizer 의 odom 예측 재발행 or 공분산 미기록).
    // 그런 메시지를 팩터로 넣으면 odom 정보가 이중 계상되므로 제외.
    if (message->pose.covariance[35] <= 0.0) {
      return;
    }
    PcdMeasurement measurement;
    measurement.t = rclcpp::Time(message->header.stamp).seconds();
    measurement.pose = gtsam::Pose2(
      message->pose.pose.position.x, message->pose.pose.position.y,
      yawFromQuaternion(message->pose.pose.orientation));
    // Odometry covariance (x,y,...,yaw) -> (x,y,yaw) 3x3
    //   공분산 미기록(전부 0 또는 [0]에 플래그만)이면 보수적 기본값을 core 의 floor 가 처리.
    Eigen::Matrix3d cov = Eigen::Matrix3d::Zero();
    cov(0, 0) = message->pose.covariance[0];
    cov(0, 1) = message->pose.covariance[1];
    cov(1, 0) = message->pose.covariance[6];
    cov(1, 1) = message->pose.covariance[7];
    cov(0, 2) = message->pose.covariance[5];
    cov(2, 0) = message->pose.covariance[30];
    cov(1, 2) = message->pose.covariance[11];
    cov(2, 1) = message->pose.covariance[31];
    cov(2, 2) = message->pose.covariance[35];
    measurement.covariance = cov;
    core_.addPcd(measurement);
  }

  //: PCD 가 이만큼 없으면 경고. FgoParams 를 노드가 안 들고 있어 별도 상수로 둔다.
  static constexpr double kPcdWarnSec = 10.0;

  void publishStatus(FgoStatus status)
  {
    if (have_last_status_ && status == last_status_) {
      return;
    }
    if (have_last_status_) {
      RCLCPP_INFO(
        get_logger(), "FGO status: %s -> %s",
        statusName(last_status_), statusName(status));
    }
    last_status_ = status;
    have_last_status_ = true;
    std_msgs::msg::String message;
    message.data = statusName(status);
    status_publisher_->publish(message);
  }

  // 저주기(solve): 그래프 최적화 + map->odom 값 갱신 + 토픽/진단 발행.
  void solveCycle()
  {
    const rclcpp::Time now = get_clock()->now();
    core_.update(now.seconds());
    publishStatus(core_.status(now.seconds()));

    const auto map_pose = core_.latestMapPose();
    const auto odom_pose = core_.latestOdomPose();
    if (!map_pose || !odom_pose || !core_.anchored()) {
      return;
    }

    // map->odom = X_latest ∘ (odom pose_latest)^-1
    map_to_odom_ = map_pose->compose(odom_pose->inverse());
    have_map_to_odom_ = true;

    geometry_msgs::msg::TransformStamped transform = mapToOdomMsg(now);
    map_to_odom_publisher_->publish(transform);

    const gtsam::Point2 bias = core_.gpsBias();
    geometry_msgs::msg::PointStamped bias_msg;
    bias_msg.header.stamp = now;
    bias_msg.header.frame_id = map_frame_;
    bias_msg.point.x = bias.x();
    bias_msg.point.y = bias.y();
    bias_publisher_->publish(bias_msg);

    const double pcd_age = core_.pcdAgeSec(now.seconds());
    // named local: 임시 std::string 에 c_str() 을 걸면 수명이 위태롭다.
    char pcd_age_buf[32];
    if (pcd_age < 0.0) {
      std::snprintf(pcd_age_buf, sizeof(pcd_age_buf), "never");
    } else {
      std::snprintf(pcd_age_buf, sizeof(pcd_age_buf), "%.1fs", pcd_age);
    }
    const std::string pcd_age_text(pcd_age_buf);
    RCLCPP_INFO_THROTTLE(
      get_logger(), *get_clock(), 5000,
      "FGO: pcd accepted=%d rejected=%d age=%s, gps_bias=(%.2f, %.2f)",
      core_.pcdAccepted(), core_.pcdRejected(), pcd_age_text.c_str(),
      bias.x(), bias.y());

    // LiDAR 맵 정합의 이상을 GPS 가 가리지 못하게 따로 경고한다.
    // watchdog 이 보는 last_absolute_factor_t_ 는 GPS 로도 갱신되므로,
    // PCD 가 한 번도 안 와도 status 는 Ok 로 남는다 (실측 145초).
    // 두 고장 모드를 구분해 알린다 — 대처가 완전히 다르다.
    if (pcd_age < 0.0) {
      // (1) 아예 없음: 자세는 float GPS(실효 σ 6 m) + 오도메트리일 뿐이다.
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 5000,
        "LiDAR map-matching contributes NOTHING (no PCD constraint ever) - pose "
        "is GPS+odometry only. FGO status can still read OK because GPS refreshes "
        "the same watchdog timestamp. Check global initialisation.");
    } else if (pcd_age > kPcdWarnSec) {
      // (2) 낡음: 제약은 들어오지만 파이프라인이 입력 속도를 못 따라가 백로그가
      //     쌓이고 있다. 실측(record_20260820_162543 재생) 140 초 동안 지연이
      //     2 초 -> 91 초로 선형 증가했고 accepted 는 계속 늘었다.
      //     이 상태의 PCD 인자는 수십 초 전 자세를 현재로 주장한다.
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 5000,
        "PCD constraints are %.1fs STALE (accepted=%d, still arriving) - the "
        "matcher cannot keep up and its backlog is growing, so FGO is fusing "
        "far-past poses as current. Reduce scan-match cost (local_map_radius) "
        "or drop input rate.",
        pcd_age, core_.pcdAccepted());
    }
  }

  // 고주기(TF): 최신 map->odom 을 현재 시각으로 재스탬프해 발행.
  //   값은 solve 주기로만 변하지만, 스탬프를 높은 주기로 갱신해야 tf2 의
  //   공통시각이 odom->base(100Hz)를 따라가 map->base 가 매끄럽게 조회됨.
  //   /global_pose 도 map->odom ∘ 최신 odom 으로 합성해 같은 주기로 발행.
  void publishTfCycle()
  {
    if (!have_map_to_odom_) {
      return;
    }
    const rclcpp::Time now = get_clock()->now();
    if (publish_tf_) {
      tf_broadcaster_->sendTransform(mapToOdomMsg(now));
    }
    if (!have_latest_odom_) {
      return;
    }
    const gtsam::Pose2 map_base = map_to_odom_.compose(latest_odom_pose_);
    nav_msgs::msg::Odometry global_pose;
    global_pose.header.stamp = latest_odom_stamp_;
    global_pose.header.frame_id = map_frame_;
    global_pose.child_frame_id = base_frame_;
    global_pose.pose.pose.position.x = map_base.x();
    global_pose.pose.pose.position.y = map_base.y();
    global_pose.pose.pose.orientation = quaternionFromYaw(map_base.theta());
    global_pose_publisher_->publish(global_pose);
  }

  geometry_msgs::msg::TransformStamped mapToOdomMsg(const rclcpp::Time & stamp) const
  {
    geometry_msgs::msg::TransformStamped transform;
    transform.header.stamp = stamp;
    transform.header.frame_id = map_frame_;
    transform.child_frame_id = odom_frame_;
    transform.transform.translation.x = map_to_odom_.x();
    transform.transform.translation.y = map_to_odom_.y();
    transform.transform.rotation = quaternionFromYaw(map_to_odom_.theta());
    return transform;
  }

  FgoCore core_;
  std::string odom_topic_, gps_topic_, pcd_topic_;
  std::string map_to_odom_topic_, global_pose_topic_, status_topic_, bias_topic_;
  std::string map_frame_, odom_frame_, base_frame_;
  bool publish_tf_{true};
  double publish_rate_hz_{5.0};
  double tf_rate_hz_{50.0};
  FgoStatus last_status_{FgoStatus::Init};
  bool have_last_status_{false};
  gtsam::Pose2 map_to_odom_;
  bool have_map_to_odom_{false};
  gtsam::Pose2 latest_odom_pose_;
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
  rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr bias_publisher_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::TimerBase::SharedPtr tf_timer_;
};

}  // namespace loam_fgo_localization

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<loam_fgo_localization::FgoFusionNode>());
  rclcpp::shutdown();
  return 0;
}

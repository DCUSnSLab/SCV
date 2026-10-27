#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <deque>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <lio_sam/msg/cloud_info.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>
#include <pcl/common/transforms.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/string.hpp>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>

#ifdef LIO_SAM_LOCALIZATION_HAS_CUDA
#include "loam_fgo_localization/global_localization/cuda_knn.hpp"
#endif
#include "loam_fgo_localization/callback_timing.hpp"
#include "loam_fgo_localization/global_localization/height_initializer.hpp"
#include "loam_fgo_localization/global_localization/se2_branch_and_bound.hpp"

namespace
{
using PointT = pcl::PointXYZI;
using SteadyClock = std::chrono::steady_clock;

enum class LocalizationState
{
  Standby,
  NonInitialized,
  Initializing,
  Initialized,
  MayLost,
  Lost
};

enum class OptimizationResult
{
  Converged,
  InsufficientConstraints,
  InvalidUpdate,
  MaxIterations
};

enum class LmStepResult
{
  Continue,
  Converged,
  Invalid
};

struct GlobalInitVote
{
  Eigen::Affine3f anchor = Eigen::Affine3f::Identity();
  bool relative_to_prior{false};
  double stamp_sec{0.0};
};

const char * stateName(LocalizationState state)
{
  switch (state) {
    case LocalizationState::Standby:
      return "Standby";
    case LocalizationState::NonInitialized:
      return "NonInitialized";
    case LocalizationState::Initializing:
      return "Initializing";
    case LocalizationState::Initialized:
      return "Initialized";
    case LocalizationState::MayLost:
      return "MayLost";
    case LocalizationState::Lost:
      return "Lost";
  }
  return "Unknown";
}

const char * optimizationResultName(OptimizationResult result)
{
  switch (result) {
    case OptimizationResult::Converged:
      return "accepted";
    case OptimizationResult::InsufficientConstraints:
      return "rejected_constraints";
    case OptimizationResult::InvalidUpdate:
      return "rejected_invalid_update";
    case OptimizationResult::MaxIterations:
      return "rejected_max_iterations";
  }
  return "rejected_unknown";
}

Eigen::Affine3f trans2Affine3f(const float t[6])
{
  return pcl::getTransformation(t[3], t[4], t[5], t[0], t[1], t[2]);
}

void affineToTrans(const Eigen::Affine3f & a, float t[6])
{
  pcl::getTranslationAndEulerAngles(a, t[3], t[4], t[5], t[0], t[1], t[2]);
}

void pointAssociateToMap(const Eigen::Affine3f & tf, const PointT & pi, PointT & po)
{
  po.x = tf(0, 0) * pi.x + tf(0, 1) * pi.y + tf(0, 2) * pi.z + tf(0, 3);
  po.y = tf(1, 0) * pi.x + tf(1, 1) * pi.y + tf(1, 2) * pi.z + tf(1, 3);
  po.z = tf(2, 0) * pi.x + tf(2, 1) * pi.y + tf(2, 2) * pi.z + tf(2, 3);
  po.intensity = pi.intensity;
}

geometry_msgs::msg::Quaternion quatFromTrans(const float t[6])
{
  tf2::Quaternion q;
  q.setRPY(t[0], t[1], t[2]);
  q.normalize();
  geometry_msgs::msg::Quaternion msg;
  msg.x = q.x();
  msg.y = q.y();
  msg.z = q.z();
  msg.w = q.w();
  return msg;
}

double elapsedMs(SteadyClock::time_point start, SteadyClock::time_point end = SteadyClock::now())
{
  return std::chrono::duration<double, std::milli>(end - start).count();
}

tf2::Transform transformFromPose(const geometry_msgs::msg::Pose & pose)
{
  tf2::Transform tf;
  tf2::Quaternion q(
    pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w);
  q.normalize();
  tf.setOrigin(tf2::Vector3(pose.position.x, pose.position.y, pose.position.z));
  tf.setRotation(q);
  return tf;
}

Eigen::Affine3f eigenFromTf(const tf2::Transform & tf)
{
  const auto & q = tf.getRotation();
  const auto & p = tf.getOrigin();
  return Eigen::Translation3f(p.x(), p.y(), p.z()) * Eigen::Quaternionf(q.w(), q.x(), q.y(), q.z());
}

tf2::Transform transformFromStamped(const geometry_msgs::msg::TransformStamped & msg)
{
  tf2::Transform tf;
  tf2::Quaternion q(
    msg.transform.rotation.x,
    msg.transform.rotation.y,
    msg.transform.rotation.z,
    msg.transform.rotation.w);
  q.normalize();
  tf.setOrigin(
    tf2::Vector3(
      msg.transform.translation.x,
      msg.transform.translation.y,
      msg.transform.translation.z));
  tf.setRotation(q);
  return tf;
}

tf2::Transform transformFromTrans(const float t[6])
{
  tf2::Transform tf;
  tf2::Quaternion q;
  q.setRPY(t[0], t[1], t[2]);
  q.normalize();
  tf.setOrigin(tf2::Vector3(t[3], t[4], t[5]));
  tf.setRotation(q);
  return tf;
}

geometry_msgs::msg::Transform toTransformMsg(const tf2::Transform & tf)
{
  geometry_msgs::msg::Transform msg;
  msg.translation.x = tf.getOrigin().x();
  msg.translation.y = tf.getOrigin().y();
  msg.translation.z = tf.getOrigin().z();
  msg.rotation.x = tf.getRotation().x();
  msg.rotation.y = tf.getRotation().y();
  msg.rotation.z = tf.getRotation().z();
  msg.rotation.w = tf.getRotation().w();
  return msg;
}

}  // namespace

class LioFeatureMapLocalizer : public rclcpp::Node
{
public:
  LioFeatureMapLocalizer()
  : Node("lio_feature_map_localizer"),
    corner_map_(new pcl::PointCloud<PointT>),
    surf_map_(new pcl::PointCloud<PointT>),
    corner_map_ds_(new pcl::PointCloud<PointT>),
    surf_map_ds_(new pcl::PointCloud<PointT>),
    corner_map_local_(new pcl::PointCloud<PointT>),
    surf_map_local_(new pcl::PointCloud<PointT>),
    corner_last_(new pcl::PointCloud<PointT>),
    surf_last_(new pcl::PointCloud<PointT>),
    corner_last_ds_(new pcl::PointCloud<PointT>),
    surf_last_ds_(new pcl::PointCloud<PointT>),
    laser_ori_(new pcl::PointCloud<PointT>),
    coeff_sel_(new pcl::PointCloud<PointT>)
  {
    corner_map_path_ = declare_parameter<std::string>("corner_map_path", "");
    surf_map_path_ = declare_parameter<std::string>("surf_map_path", "");
    // 기본은 위 param 경로 로드. 아래 토픽(map_provider ~/pcd/<id>/*_path)이 오면 경로 갱신·재로드.
    corner_map_path_topic_ = declare_parameter<std::string>("corner_map_path_topic", "");
    surf_map_path_topic_ = declare_parameter<std::string>("surf_map_path_topic", "");
    input_topic_ = declare_parameter<std::string>("input_topic", "/lio_sam/feature/cloud_info");
    prior_odom_topic_ = declare_parameter<std::string>("prior_odom_topic", "/odom");
    initial_pose_topic_ = declare_parameter<std::string>("initial_pose_topic", "/initialpose");
    global_pose_topic_ = declare_parameter<std::string>("global_pose_topic", "/global_pose");
    map_to_odom_candidate_topic_ = declare_parameter<std::string>(
      "map_to_odom_candidate_topic", "/pcd/map_to_odom");
    processing_enable_topic_ = declare_parameter<std::string>(
      "processing_enable_topic", "/localization/pcd_enabled");
    map_frame_ = declare_parameter<std::string>("map_frame", "map");
    odom_frame_ = declare_parameter<std::string>("odom_frame", "odom");
    base_frame_ = declare_parameter<std::string>("base_frame", "base_link");
    lidar_frame_ = declare_parameter<std::string>("lidar_frame", "velodyne");

    map_corner_leaf_ = declare_parameter<double>("map_corner_leaf", 0.2);
    map_surf_leaf_ = declare_parameter<double>("map_surf_leaf", 0.4);
    scan_corner_leaf_ = declare_parameter<double>("scan_corner_leaf", 0.2);
    scan_surf_leaf_ = declare_parameter<double>("scan_surf_leaf", 0.4);
    edge_min_valid_ = declare_parameter<int>("edge_min_valid", 10);
    surf_min_valid_ = declare_parameter<int>("surf_min_valid", 100);
    max_iterations_ = declare_parameter<int>("max_iterations", 20);
    max_step_xy_ = declare_parameter<double>("max_step_xy", 3.0);
    lookup_backend_ = declare_parameter<std::string>("lookup_backend", "cpu");
    profile_timings_ = declare_parameter<bool>("profile_timings", false);
    use_local_map_window_ = declare_parameter<bool>("use_local_map_window", true);
    local_map_radius_ = declare_parameter<double>("local_map_radius", 35.0);
    local_map_rebuild_dist_ = declare_parameter<double>("local_map_rebuild_dist", 5.0);
    min_local_corner_points_ = declare_parameter<int>("min_local_corner_points", 200);
    min_local_surf_points_ = declare_parameter<int>("min_local_surf_points", 1000);
    publish_tf_ = declare_parameter<bool>("publish_tf", false);
    // 수락된 정합의 LM 정규방정식 (AtA)^-1 기반 pose 공분산을 /pcd/global_pose 에 기록.
    // (FGO 팩터 가중용. 거부/예측 발행에는 기록 안 함 -> cov 0 = 정합 아님 표식)
    publish_pose_covariance_ = declare_parameter<bool>("publish_pose_covariance", true);
    publish_map_to_odom_ = declare_parameter<bool>("publish_map_to_odom", true);
    publish_map_features_ = declare_parameter<bool>("publish_map_features", false);
    publish_registered_cloud_ = declare_parameter<bool>("publish_registered_cloud", false);
    use_prior_odom_ = declare_parameter<bool>("use_prior_odom", true);
    prior_pose_is_base_frame_ = declare_parameter<bool>("prior_pose_is_base_frame", true);
    initial_pose_is_base_frame_ = declare_parameter<bool>("initial_pose_is_base_frame", true);
    require_initial_pose_ = declare_parameter<bool>("require_initial_pose", false);
    require_initial_pose_without_prior_ = declare_parameter<bool>(
      "require_initial_pose_without_prior", true);
    max_consecutive_failures_ = declare_parameter<int>("max_consecutive_failures", 5);
    use_constant_velocity_guess_ = declare_parameter<bool>("use_constant_velocity_guess", true);
    imu_rpy_weight_ = declare_parameter<double>("imu_rpy_weight", 0.01);
    prior_timeout_sec_ = declare_parameter<double>("prior_timeout_sec", 0.5);
    map_native_to_map_x_ = declare_parameter<double>("map_native_to_map.x", 0.0);
    map_native_to_map_y_ = declare_parameter<double>("map_native_to_map.y", 0.0);
    map_native_to_map_z_ = declare_parameter<double>("map_native_to_map.z", 0.0);
    map_native_to_map_yaw_deg_ = declare_parameter<double>(
      "map_native_to_map.yaw_deg", 0.0);
    processing_enabled_ = declare_parameter<bool>("processing_enabled_at_start", true);
    global_init_enabled_ = declare_parameter<bool>("global_initialization.enabled", false);
    global_init_retry_interval_sec_ = declare_parameter<double>(
      "global_initialization.retry_interval_sec", 1.0);
    global_init_min_corner_points_ = declare_parameter<int>(
      "global_initialization.min_corner_points", 15);
    global_init_required_votes_ = declare_parameter<int>(
      "global_initialization.required_votes", 3);
    global_init_max_votes_ = declare_parameter<int>(
      "global_initialization.max_votes", 6);
    global_init_vote_xy_tolerance_ = declare_parameter<double>(
      "global_initialization.vote_xy_tolerance", 1.0);
    const double vote_yaw_tolerance_deg = declare_parameter<double>(
      "global_initialization.vote_yaw_tolerance_deg", 5.0);
    global_init_vote_yaw_tolerance_ = vote_yaw_tolerance_deg * M_PI / 180.0;
    global_init_vote_timeout_sec_ = declare_parameter<double>(
      "global_initialization.vote_timeout_sec", 2.0);
    global_init_z_center_ = declare_parameter<double>(
      "global_initialization.z_center", 0.0);
    global_init_use_prior_z_ = declare_parameter<bool>(
      "global_initialization.use_prior_z", true);
    global_init_z_half_range_ = declare_parameter<double>(
      "global_initialization.z_half_range", 4.0);
    global_init_z_step_ = declare_parameter<double>(
      "global_initialization.z_step", 0.25);
    global_init_z_score_sigma_ = declare_parameter<double>(
      "global_initialization.z_score_sigma", 0.75);
    global_init_z_score_cutoff_ = declare_parameter<double>(
      "global_initialization.z_score_cutoff", 2.25);
    relocalization_enabled_ = declare_parameter<bool>("relocalization.enabled", false);
    relocalization_start_after_sec_ = declare_parameter<double>(
      "relocalization.start_after_sec", 2.0);
    relocalization_retry_interval_sec_ = declare_parameter<double>(
      "relocalization.retry_interval_sec", 0.1);
    relocalization_xy_initial_radius_m_ = declare_parameter<double>(
      "relocalization.xy_initial_radius_m", 2.0);
    relocalization_max_vehicle_speed_mps_ = declare_parameter<double>(
      "relocalization.max_vehicle_speed_mps", 2.0);
    relocalization_xy_error_per_odom_meter_ = declare_parameter<double>(
      "relocalization.xy_error_per_odom_meter", 0.35);
    relocalization_odom_jump_tolerance_m_ = declare_parameter<double>(
      "relocalization.odom_jump_tolerance_m", 0.5);
    const double relocalization_max_odom_yaw_rate_deg_per_sec = declare_parameter<double>(
      "relocalization.max_odom_yaw_rate_deg_per_sec", 60.0);
    const double relocalization_odom_yaw_jump_tolerance_deg = declare_parameter<double>(
      "relocalization.odom_yaw_jump_tolerance_deg", 5.0);
    relocalization_xy_stop_radius_m_ = declare_parameter<double>(
      "relocalization.xy_stop_radius_m", 20.0);
    const double relocalization_yaw_initial_half_range_deg = declare_parameter<double>(
      "relocalization.yaw_initial_half_range_deg", 15.0);
    const double relocalization_yaw_growth_deg_per_sec = declare_parameter<double>(
      "relocalization.yaw_growth_deg_per_sec", 5.0);
    const double relocalization_yaw_max_half_range_deg = declare_parameter<double>(
      "relocalization.yaw_max_half_range_deg", 180.0);
    relocalization_yaw_initial_half_range_rad_ =
      relocalization_yaw_initial_half_range_deg * M_PI / 180.0;
    relocalization_yaw_growth_rad_per_sec_ =
      relocalization_yaw_growth_deg_per_sec * M_PI / 180.0;
    relocalization_yaw_max_half_range_rad_ =
      relocalization_yaw_max_half_range_deg * M_PI / 180.0;
    relocalization_max_odom_yaw_rate_rad_per_sec_ =
      relocalization_max_odom_yaw_rate_deg_per_sec * M_PI / 180.0;
    relocalization_odom_yaw_jump_tolerance_rad_ =
      relocalization_odom_yaw_jump_tolerance_deg * M_PI / 180.0;

    if (relocalization_enabled_ && !global_init_enabled_) {
      throw std::invalid_argument("relocalization requires global_initialization.enabled");
    }
    if (global_init_enabled_) {
      global_init_position_prior_topic_ = declare_parameter<std::string>(
        "global_initialization.position_prior_topic", "/gps/coarse_position");
      global_init_position_prior_max_age_sec_ = declare_parameter<double>(
        "global_initialization.position_prior_max_age_sec", 1.0);
      global_init_position_prior_sigma_scale_ = declare_parameter<double>(
        "global_initialization.position_prior_sigma_scale", 3.0);
      global_init_position_prior_min_radius_ = declare_parameter<double>(
        "global_initialization.position_prior_min_radius", 10.0);
      // 만료 판정 대신 "이 시간이 넘으면 아예 못 쓴다"는 상한. max_age 보다 훨씬 크게
      // 잡는다 — 그 사이는 반경을 키워서 쓴다.
      global_init_position_prior_stale_limit_sec_ = declare_parameter<double>(
        "global_initialization.position_prior_stale_limit_sec", 10.0);
      // 사전정보 1 초당 넓힐 반경(m). 차량 최고속 + 여유.
      global_init_position_prior_speed_margin_ = declare_parameter<double>(
        "global_initialization.position_prior_speed_margin", 3.0);
      global_init_position_prior_max_radius_ = declare_parameter<double>(
        "global_initialization.position_prior_max_radius", 30.0);
      if (global_init_retry_interval_sec_ < 0.0 || global_init_min_corner_points_ < 1 ||
        global_init_required_votes_ < 1 ||
        global_init_max_votes_ < global_init_required_votes_ ||
        global_init_vote_xy_tolerance_ <= 0.0 ||
        global_init_vote_yaw_tolerance_ <= 0.0 || global_init_vote_timeout_sec_ <= 0.0 ||
        global_init_z_half_range_ < 0.0 || global_init_z_step_ <= 0.0 ||
        global_init_z_score_sigma_ <= 0.0 || global_init_z_score_cutoff_ <= 0.0 ||
        global_init_position_prior_max_age_sec_ <= 0.0 ||
        global_init_position_prior_sigma_scale_ <= 0.0 ||
        global_init_position_prior_min_radius_ < 0.0 ||
        global_init_position_prior_max_radius_ < global_init_position_prior_min_radius_ ||
        relocalization_start_after_sec_ < 0.0 ||
        relocalization_retry_interval_sec_ < 0.0 ||
        relocalization_xy_initial_radius_m_ < 0.0 ||
        relocalization_max_vehicle_speed_mps_ <= 0.0 ||
        relocalization_xy_error_per_odom_meter_ < 0.0 ||
        relocalization_odom_jump_tolerance_m_ < 0.0 ||
        relocalization_max_odom_yaw_rate_rad_per_sec_ <= 0.0 ||
        relocalization_odom_yaw_jump_tolerance_rad_ < 0.0 ||
        relocalization_xy_stop_radius_m_ < relocalization_xy_initial_radius_m_ ||
        relocalization_yaw_initial_half_range_rad_ < 0.0 ||
        relocalization_yaw_growth_rad_per_sec_ < 0.0 ||
        relocalization_yaw_max_half_range_rad_ <
        relocalization_yaw_initial_half_range_rad_ ||
        relocalization_yaw_max_half_range_rad_ > M_PI)
      {
        throw std::invalid_argument("invalid global_initialization parameters");
      }
      loam_fgo_localization::Se2BranchAndBoundOptions options;
      options.resolution_m = declare_parameter<double>(
        "global_initialization.resolution", 0.5);
      options.score_sigma_m = declare_parameter<double>(
        "global_initialization.score_sigma", 0.75);
      options.score_cutoff_m = declare_parameter<double>(
        "global_initialization.score_cutoff", 2.25);
      options.map_padding_m = declare_parameter<double>(
        "global_initialization.map_padding", 5.0);
      const double yaw_step_deg = declare_parameter<double>(
        "global_initialization.yaw_step_deg", 1.0);
      options.yaw_step_rad = yaw_step_deg * M_PI / 180.0;
      options.branch_and_bound_depth = declare_parameter<int>(
        "global_initialization.branch_and_bound_depth", 6);
      options.min_score = declare_parameter<double>(
        "global_initialization.min_score", 0.25);
      options.min_scan_range_m = declare_parameter<double>(
        "global_initialization.min_scan_range", 2.0);
      options.max_scan_range_m = declare_parameter<double>(
        "global_initialization.max_scan_range", 50.0);
      options.max_scan_points = declare_parameter<int>(
        "global_initialization.max_scan_points", 300);
      // 2026-08-19: match 1회 시간 예산. 열화 환경에서 준-전수 탐색이 되면
      // 단일스레드 콜백이 분 단위로 마비된다 (DCU bag Lost 재현) -> 상한 필수.
      global_init_max_match_seconds_ = declare_parameter<double>(
        "global_initialization.max_match_seconds", 1.0);
      options.max_match_seconds = global_init_max_match_seconds_;
      global_init_matcher_.reset(
        new loam_fgo_localization::Se2BranchAndBoundMatcher(options));
    }

    for (float & v : transform_) {
      v = 0.0f;
    }
    configureLookupBackend();

    // 기본: param 경로 파일이 존재하면 즉시 로드. 없고 경로 토픽이 설정돼 있으면 토픽 대기.
    const bool have_path_topic =
      !corner_map_path_topic_.empty() || !surf_map_path_topic_.empty();
    const bool files_exist =
      std::ifstream(corner_map_path_).good() && std::ifstream(surf_map_path_).good();
    if (files_exist || !have_path_topic) {
      loadMaps();
    } else {
      RCLCPP_INFO(get_logger(), "map files not found; waiting for map path via topic...");
    }

    sub_cloud_info_ = create_subscription<lio_sam::msg::CloudInfo>(
      input_topic_, rclcpp::SensorDataQoS().keep_last(1),
      std::bind(&LioFeatureMapLocalizer::cloudInfoHandler, this, std::placeholders::_1));
    sub_initial_pose_ = create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
      initial_pose_topic_, 10,
      std::bind(&LioFeatureMapLocalizer::initialPoseHandler, this, std::placeholders::_1));
    sub_processing_enable_ = create_subscription<std_msgs::msg::Bool>(
      processing_enable_topic_, rclcpp::QoS(1).transient_local().reliable(),
      std::bind(
        &LioFeatureMapLocalizer::processingEnableHandler, this,
        std::placeholders::_1));
    // 경로 토픽(map_provider) 구독 -> 오면 맵 경로 갱신·재로드 (없으면 param 경로 유지)
    if (!corner_map_path_topic_.empty()) {
      sub_corner_path_ = create_subscription<std_msgs::msg::String>(
        corner_map_path_topic_, rclcpp::QoS(1).transient_local().reliable(),
        [this](const std_msgs::msg::String::SharedPtr m) {this->mapPathHandler(m->data, true);});
    }
    if (!surf_map_path_topic_.empty()) {
      sub_surf_path_ = create_subscription<std_msgs::msg::String>(
        surf_map_path_topic_, rclcpp::QoS(1).transient_local().reliable(),
        [this](const std_msgs::msg::String::SharedPtr m) {this->mapPathHandler(m->data, false);});
    }
    if (use_prior_odom_) {
      // depth 200 (100Hz x 2s): BBS/정합이 콜백을 1초 안팎 점유해도 odom 이
      // 큐에서 유실되지 않게 한다. 기본 SensorDataQoS(depth 5)에서는 유실이
      // "non-continuous timestamp" 로 오검출돼 재초기화 원이 불필요하게 커졌다.
      sub_prior_odom_ = create_subscription<nav_msgs::msg::Odometry>(
        prior_odom_topic_, rclcpp::SensorDataQoS().keep_last(200),
        std::bind(&LioFeatureMapLocalizer::priorOdomHandler, this, std::placeholders::_1));
    }
    if (global_init_enabled_ && !global_init_position_prior_topic_.empty()) {
      sub_global_init_position_prior_ =
        create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
        global_init_position_prior_topic_, rclcpp::SensorDataQoS().keep_last(50),
        std::bind(
          &LioFeatureMapLocalizer::globalInitPositionPriorHandler, this,
          std::placeholders::_1));
    }

    pub_odom_ = create_publisher<nav_msgs::msg::Odometry>("/lio_sam_localization/odometry", 10);
    pub_global_pose_ = create_publisher<nav_msgs::msg::Odometry>(global_pose_topic_, 10);
    pub_path_ = create_publisher<nav_msgs::msg::Path>("/lio_sam_localization/path", 10);
    pub_registered_ = create_publisher<sensor_msgs::msg::PointCloud2>(
      "/lio_sam_localization/cloud_registered", 10);
    pub_map_ = create_publisher<sensor_msgs::msg::PointCloud2>(
      "/lio_sam_localization/map_features", rclcpp::QoS(1).transient_local().reliable());
    pub_state_ = create_publisher<std_msgs::msg::String>(
      "/lio_sam_localization/state", rclcpp::QoS(1).transient_local().reliable());
    pub_correction_status_ = create_publisher<std_msgs::msg::String>(
      "/lio_sam_localization/correction_status", 10);
    pub_cycle_time_ = create_publisher<std_msgs::msg::Float64MultiArray>(
      "/scv/timing/pcd_localizer_ms", rclcpp::SensorDataQoS());
    pub_map_to_odom_candidate_ =
      create_publisher<geometry_msgs::msg::TransformStamped>(
      map_to_odom_candidate_topic_, rclcpp::SensorDataQoS());
    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    if (publish_map_features_) {
      publishMap();
      map_timer_ = create_wall_timer(
        std::chrono::seconds(2), std::bind(&LioFeatureMapLocalizer::publishMap, this));
    }
    state_ = processing_enabled_ ?
      LocalizationState::NonInitialized : LocalizationState::Standby;
    publishState();

    RCLCPP_INFO(
      get_logger(),
      "Loaded fixed LIO feature maps: corner raw=%zu ds=%zu, surf raw=%zu ds=%zu, local_window=%s radius=%.1f",
      corner_map_->size(), corner_map_ds_->size(), surf_map_->size(), surf_map_ds_->size(),
      use_local_map_window_ ? "true" : "false", local_map_radius_);
  }

private:
  void processingEnableHandler(const std_msgs::msg::Bool::SharedPtr msg)
  {
    if (processing_enabled_ == msg->data) {
      return;
    }
    processing_enabled_ = msg->data;
    if (processing_enabled_) {
      last_global_init_attempt_sec_ = -std::numeric_limits<double>::infinity();
      global_init_votes_.clear();
      setState(LocalizationState::NonInitialized, "processing enabled");
      RCLCPP_INFO(get_logger(), "fixed-map localization processing enabled");
      return;
    }

    initialized_ = false;
    received_initial_pose_ = false;
    have_map_to_prior_ = false;
    have_pending_global_pose_ = false;
    have_increment_ = false;
    global_seed_pending_ = false;
    global_seed_relocalization_ = false;
    global_init_votes_.clear();
    consecutive_failures_ = 0;
    clearLossTracking();
    path_.poses.clear();
    setState(LocalizationState::Standby, "processing disabled");
    RCLCPP_INFO(get_logger(), "fixed-map localization processing disabled");
  }

  void priorOdomHandler(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    processPriorOdom(*msg);
  }

  // 스캔 콜백 진입 시 odom 큐를 통째로 비운다.
  //   single-threaded executor 는 wait 사이클당 구독별 1개만 집는데, 스캔 콜백
  //   (~100-300ms)이 항상 준비돼 있으면 odom 소비가 ~수 Hz 로 떨어져 큐(200)가
  //   적체된다 -> localizer 가 보는 odom 이 0.5초+ 뒤처짐 (2026-08-25 실측:
  //   DDS 전달은 -27ms 상수인데 prior 나이 0.5~1.7s). take() 드레인으로 해소.
  void drainPriorOdomQueue()
  {
    if (!sub_prior_odom_) {
      return;
    }
    nav_msgs::msg::Odometry msg;
    rclcpp::MessageInfo info;
    while (sub_prior_odom_->take(msg, info)) {
      processPriorOdom(msg);
    }
  }

  void processPriorOdom(const nav_msgs::msg::Odometry & odom_msg)
  {
    const nav_msgs::msg::Odometry * msg = &odom_msg;
    tf2::Transform prior_pose = transformFromPose(msg->pose.pose);
    if (prior_pose_is_base_frame_ && base_frame_ != lidar_frame_) {
      tf2::Transform base_to_lidar;
      if (!lookupBaseToLidar(base_to_lidar)) {
        return;
      }
      prior_pose *= base_to_lidar;
    }

    const Eigen::Affine3f prior_affine = eigenFromTf(prior_pose);
    double roll = 0.0;
    double pitch = 0.0;
    double yaw = 0.0;
    const auto & q = prior_pose.getRotation();
    tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);

    latest_prior_[0] = static_cast<float>(roll);
    latest_prior_[1] = static_cast<float>(pitch);
    latest_prior_[2] = static_cast<float>(yaw);
    latest_prior_[3] = prior_affine.translation().x();
    latest_prior_[4] = prior_affine.translation().y();
    latest_prior_[5] = prior_affine.translation().z();
    latest_prior_stamp_ = rclcpp::Time(msg->header.stamp);
    have_prior_ = true;
    // 스캔 스탬프 보간용 버퍼. 파이프라인이 밀리면(실측 91초) 스캔은 과거 시각인데
    // latest_prior_(현재)와 짝지으면 backlog x 속도 만큼 추정이 앞서 나가 LM 이
    // 발산한다 (2026-08-25 재생 진단: 정지 중 정상, 출발 순간 연쇄 거부).
    const double prior_t = latest_prior_stamp_.seconds();
    if (!prior_buffer_.empty() && prior_t <= prior_buffer_.back().first) {
      prior_buffer_.clear();   // 시간 역행(재생 재시작 등) 방어
    }
    prior_buffer_.emplace_back(
      prior_t,
      std::array<float, 6>{
        latest_prior_[0], latest_prior_[1], latest_prior_[2],
        latest_prior_[3], latest_prior_[4], latest_prior_[5]});
    while (prior_buffer_.size() > 2 &&
      prior_t - prior_buffer_.front().first > 120.0)
    {
      prior_buffer_.pop_front();
    }
    updateLossPriorTracking();
    if (have_pending_global_pose_) {
      map_to_prior_ = pending_map_to_lidar_ * trans2Affine3f(latest_prior_).inverse();
      have_map_to_prior_ = true;
      have_pending_global_pose_ = false;
      RCLCPP_INFO(get_logger(), "anchored prior odometry to pending global pose");
    }
  }

  void globalInitPositionPriorHandler(
    const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
  {
    if (!msg->header.frame_id.empty() && msg->header.frame_id != map_frame_) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "ignoring BBS position prior in frame '%s'; expected '%s'",
        msg->header.frame_id.c_str(), map_frame_.c_str());
      return;
    }

    const double x = msg->pose.pose.position.x;
    const double y = msg->pose.pose.position.y;
    const double variance = std::max(
      {msg->pose.covariance[0], msg->pose.covariance[7], 0.0});
    if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(variance)) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000, "ignoring invalid BBS position prior");
      return;
    }

    global_init_position_prior_x_ = x;
    global_init_position_prior_y_ = y;
    global_init_position_prior_sigma_ = std::sqrt(variance);
    global_init_position_prior_stamp_ = rclcpp::Time(msg->header.stamp);
    have_global_init_position_prior_ = true;
  }

  // 스캔 스탬프 t 시각의 prior 를 버퍼 보간으로 구한다 (시간축 정합).
  //   t 가 버퍼 최신보다 미래: prior_timeout_sec_ 이내면 최신값 사용 (실시간 경로).
  //   t 가 버퍼 범위보다 과거(120초 초과 백로그)거나 버퍼 부족이면 false.
  bool interpolatePrior(double t, float out[6]) const
  {
    if (prior_buffer_.empty()) {
      return false;
    }
    const auto & newest = prior_buffer_.back();
    if (t >= newest.first) {
      if (t - newest.first > prior_timeout_sec_) {
        return false;
      }
      std::copy(newest.second.begin(), newest.second.end(), out);
      return true;
    }
    if (t < prior_buffer_.front().first) {
      return false;
    }
    const auto after = std::lower_bound(
      prior_buffer_.begin(), prior_buffer_.end(), t,
      [](const std::pair<double, std::array<float, 6>> & s, double value) {
        return s.first < value;
      });
    const auto before = std::prev(after);
    const double span = after->first - before->first;
    const double r = span > 1e-9 ? (t - before->first) / span : 0.0;
    for (int i = 3; i < 6; ++i) {   // xyz 선형
      out[i] = static_cast<float>(
        before->second[i] + r * (after->second[i] - before->second[i]));
    }
    for (int i = 0; i < 3; ++i) {   // rpy 각도 보간 (랩어라운드 처리)
      const double d = std::atan2(
        std::sin(after->second[i] - before->second[i]),
        std::cos(after->second[i] - before->second[i]));
      out[i] = static_cast<float>(std::atan2(
          std::sin(before->second[i] + r * d),
          std::cos(before->second[i] + r * d)));
    }
    return true;
  }

  bool lookupBaseToLidar(tf2::Transform & base_to_lidar)
  {
    if (base_frame_ == lidar_frame_) {
      base_to_lidar.setIdentity();
      return true;
    }
    try {
      base_to_lidar = transformFromStamped(
        tf_buffer_->lookupTransform(base_frame_, lidar_frame_, tf2::TimePointZero));
      return true;
    } catch (const tf2::TransformException & e) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "cannot convert %s pose to %s pose: %s",
        base_frame_.c_str(), lidar_frame_.c_str(), e.what());
      return false;
    }
  }

  void initialPoseHandler(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
  {
    if (!processing_enabled_) {
      RCLCPP_WARN(
        get_logger(), "initial pose ignored while fixed-map processing is disabled");
      return;
    }
    received_initial_pose_ = true;
    global_seed_pending_ = false;
    global_seed_relocalization_ = false;
    global_init_votes_.clear();
    if (!msg->header.frame_id.empty() && msg->header.frame_id != map_frame_) {
      RCLCPP_WARN(
        get_logger(),
        "initial pose frame '%s' differs from map frame '%s'; using pose values directly",
        msg->header.frame_id.c_str(), map_frame_.c_str());
    }

    tf2::Transform map_to_lidar = transformFromPose(msg->pose.pose);
    if (initial_pose_is_base_frame_ && base_frame_ != lidar_frame_) {
      tf2::Transform base_to_lidar;
      if (!lookupBaseToLidar(base_to_lidar)) {
        received_initial_pose_ = false;
        RCLCPP_ERROR(
          get_logger(), "initial pose rejected because %s->%s is unavailable",
          base_frame_.c_str(), lidar_frame_.c_str());
        return;
      }
      map_to_lidar *= base_to_lidar;
    }
    clearLossTracking();

    const Eigen::Affine3f map_to_lidar_affine = eigenFromTf(map_to_lidar);
    if (use_prior_odom_) {
      if (have_prior_) {
        map_to_prior_ = map_to_lidar_affine * trans2Affine3f(latest_prior_).inverse();
        have_map_to_prior_ = true;
        const double age = std::abs(
          (rclcpp::Time(
            msg->header.stamp) - latest_prior_stamp_).seconds());
        RCLCPP_INFO(
          get_logger(), "anchored prior odometry to global pose: stamp delta=%.3f sec", age);
      } else {
        pending_map_to_lidar_ = map_to_lidar_affine;
        have_pending_global_pose_ = true;
        RCLCPP_WARN(get_logger(), "global pose received before prior odometry; anchor is pending");
      }
    }

    double roll = 0.0;
    double pitch = 0.0;
    double yaw = 0.0;
    tf2::Matrix3x3(map_to_lidar.getRotation()).getRPY(roll, pitch, yaw);
    const auto origin = map_to_lidar.getOrigin();

    transform_[0] = static_cast<float>(roll);
    transform_[1] = static_cast<float>(pitch);
    transform_[2] = static_cast<float>(yaw);
    transform_[3] = static_cast<float>(origin.x());
    transform_[4] = static_cast<float>(origin.y());
    transform_[5] = static_cast<float>(origin.z());

    initialized_ = false;
    have_increment_ = false;
    if (!use_prior_odom_) {
      have_prior_ = false;
    }
    path_.poses.clear();
    consecutive_failures_ = 0;
    updateAcceptedPose(false);
    setState(LocalizationState::Initializing, "initial pose received");

    RCLCPP_INFO(
      get_logger(),
      "received initial pose on %s: lidar xyz=(%.2f %.2f %.2f), rpy=(%.3f %.3f %.3f)",
      initial_pose_topic_.c_str(), transform_[3], transform_[4], transform_[5],
      transform_[0], transform_[1], transform_[2]);
  }

  // 경로 토픽 수신 -> 경로 갱신되면 재로드 (단일스레드 실행자라 콜백 직렬 = 안전).
  void mapPathHandler(const std::string & path, bool is_corner)
  {
    std::string & target = is_corner ? corner_map_path_ : surf_map_path_;
    if (path.empty() || path == target) {
      return;
    }
    target = path;
    if (corner_map_path_.empty() || surf_map_path_.empty()) {
      return;   // corner/surf 둘 다 와야 로드 (한쪽만 오면 대기)
    }
    RCLCPP_INFO(get_logger(), "map path via topic (%s): %s -> reload",
      is_corner ? "corner" : "surf", path.c_str());
    try {
      loadMaps();   // kdtree/CUDA/BBS 전부 재구성
    } catch (const std::exception & e) {
      RCLCPP_ERROR(get_logger(), "map reload failed: %s", e.what());
    }
  }

  void loadMaps()
  {
    if (corner_map_path_.empty() || surf_map_path_.empty()) {
      throw std::runtime_error(
              "corner_map_path and surf_map_path must point to saved LIO-SAM feature maps");
    }
    if (pcl::io::loadPCDFile<PointT>(corner_map_path_, *corner_map_) != 0) {
      throw std::runtime_error("failed to load corner map: " + corner_map_path_);
    }
    if (pcl::io::loadPCDFile<PointT>(surf_map_path_, *surf_map_) != 0) {
      throw std::runtime_error("failed to load surf map: " + surf_map_path_);
    }

    const Eigen::Affine3f native_to_map = pcl::getTransformation(
      static_cast<float>(map_native_to_map_x_),
      static_cast<float>(map_native_to_map_y_),
      static_cast<float>(map_native_to_map_z_),
      0.0f, 0.0f,
      static_cast<float>(map_native_to_map_yaw_deg_ * M_PI / 180.0));
    pcl::transformPointCloud(*corner_map_, *corner_map_, native_to_map.matrix());
    pcl::transformPointCloud(*surf_map_, *surf_map_, native_to_map.matrix());
    RCLCPP_INFO(
      get_logger(),
      "applied native PCD->map transform: xyz=(%.3f %.3f %.3f), yaw=%.6f deg",
      map_native_to_map_x_, map_native_to_map_y_, map_native_to_map_z_,
      map_native_to_map_yaw_deg_);

    pcl::VoxelGrid<PointT> vg;
    vg.setInputCloud(corner_map_);
    vg.setLeafSize(map_corner_leaf_, map_corner_leaf_, map_corner_leaf_);
    vg.filter(*corner_map_ds_);
    vg.setInputCloud(surf_map_);
    vg.setLeafSize(map_surf_leaf_, map_surf_leaf_, map_surf_leaf_);
    vg.filter(*surf_map_ds_);

    corner_lookup_map_ = corner_map_ds_;
    surf_lookup_map_ = surf_map_ds_;
    kdtree_corner_.setInputCloud(corner_lookup_map_);
    kdtree_surf_.setInputCloud(surf_lookup_map_);
    kdtree_corner_global_.setInputCloud(corner_map_ds_);
    uploadCudaLookupMaps();

    if (global_init_matcher_) {
      std::vector<loam_fgo_localization::Se2Point> planar_corner_map;
      planar_corner_map.reserve(corner_map_ds_->size());
      for (const auto & point : corner_map_ds_->points) {
        planar_corner_map.push_back({point.x, point.y});
      }
      const auto start = SteadyClock::now();
      global_init_matcher_->setMap(planar_corner_map);
      RCLCPP_INFO(
        get_logger(),
        "prepared SE(2) BBS global initializer from %zu corner points in %.1f ms",
        planar_corner_map.size(), elapsedMs(start));
    }
  }

  void configureLookupBackend()
  {
    if (lookup_backend_ == "cpu") {
      use_cuda_lookup_ = false;
      return;
    }
    if (lookup_backend_ != "cuda") {
      throw std::runtime_error("lookup_backend must be 'cpu' or 'cuda'");
    }
#ifdef LIO_SAM_LOCALIZATION_HAS_CUDA
    if (!corner_cuda_.available() || !surf_cuda_.available()) {
      throw std::runtime_error("lookup_backend:=cuda requested, but no CUDA device is available");
    }
    use_cuda_lookup_ = true;
    RCLCPP_INFO(get_logger(), "using CUDA lookup backend for scan-to-map nearest-neighbor search");
#else
    throw std::runtime_error(
            "lookup_backend:=cuda requested, but this package was built without CUDA support");
#endif
  }

  void uploadCudaLookupMaps()
  {
    if (!use_cuda_lookup_) {
      return;
    }
#ifdef LIO_SAM_LOCALIZATION_HAS_CUDA
    corner_cuda_.setInputCloud(toCudaPoints(*corner_lookup_map_));
    surf_cuda_.setInputCloud(toCudaPoints(*surf_lookup_map_));
#endif
  }

#ifdef LIO_SAM_LOCALIZATION_HAS_CUDA
  static std::vector<loam_fgo_localization::CudaPoint3> toCudaPoints(
    const pcl::PointCloud<PointT> & cloud)
  {
    std::vector<loam_fgo_localization::CudaPoint3> points;
    points.reserve(cloud.size());
    for (const auto & p : cloud.points) {
      points.push_back({p.x, p.y, p.z});
    }
    return points;
  }

  static std::array<float, 12> toCudaTransformMatrix(const Eigen::Affine3f & tf)
  {
    return {
      tf(0, 0), tf(0, 1), tf(0, 2), tf(0, 3),
      tf(1, 0), tf(1, 1), tf(1, 2), tf(1, 3),
      tf(2, 0), tf(2, 1), tf(2, 2), tf(2, 3)};
  }
#endif

  void publishMap()
  {
    pcl::PointCloud<PointT>::Ptr combined(new pcl::PointCloud<PointT>);
    *combined += *corner_lookup_map_;
    *combined += *surf_lookup_map_;
    sensor_msgs::msg::PointCloud2 msg;
    pcl::toROSMsg(*combined, msg);
    msg.header.stamp = now();
    msg.header.frame_id = map_frame_;
    pub_map_->publish(msg);
  }

  bool globalInitializationDue(
    const lio_sam::msg::CloudInfo & msg, double retry_interval_sec)
  {
    const double stamp_sec = rclcpp::Time(msg.header.stamp).seconds();
    if (stamp_sec < last_global_init_attempt_sec_) {
      last_global_init_attempt_sec_ = -std::numeric_limits<double>::infinity();
      global_init_votes_.clear();
    }
    if (stamp_sec - last_global_init_attempt_sec_ < retry_interval_sec) {
      return false;
    }
    last_global_init_attempt_sec_ = stamp_sec;
    return true;
  }

  loam_fgo_localization::HeightSearchResult estimateGlobalZ(
    float roll, float pitch, float yaw, float x, float y,
    std::optional<double> map_z_prior)
  {
    const std::size_t max_points = 200;
    const std::size_t stride = std::max<std::size_t>(
      1, (corner_last_ds_->size() + max_points - 1) / max_points);
    pcl::PointCloud<PointT> scan;
    scan.reserve(max_points);
    const Eigen::Affine3f candidate = pcl::getTransformation(x, y, 0.0f, roll, pitch, yaw);
    for (std::size_t i = 0; i < corner_last_ds_->size(); i += stride) {
      PointT transformed;
      pointAssociateToMap(candidate, corner_last_ds_->points[i], transformed);
      if (std::isfinite(transformed.x) && std::isfinite(transformed.y) &&
        std::isfinite(transformed.z))
      {
        scan.push_back(transformed);
      }
    }
    if (scan.empty()) {
      return {};
    }
    const double cutoff2 = global_init_z_score_cutoff_ * global_init_z_score_cutoff_;
    const double sigma2 = global_init_z_score_sigma_ * global_init_z_score_sigma_;
    std::vector<int> index(1);
    std::vector<float> squared_distance(1);
    return loam_fgo_localization::searchMapHeight(
      *corner_map_ds_, scan,
      {global_init_z_step_, global_init_z_score_sigma_, global_init_z_score_cutoff_,
        global_init_z_half_range_}, map_z_prior,
      [&](double z) {
        double score_sum = 0.0;
        for (auto point : scan) {
          point.z += static_cast<float>(z);
          if (kdtree_corner_global_.nearestKSearch(point, 1, index, squared_distance) == 1 &&
          squared_distance[0] <= cutoff2)
          {
            score_sum += std::exp(-0.5 * squared_distance[0] / sigma2);
          }
        }
        return score_sum / scan.size();
      });
  }

  bool addGlobalInitVote(
    const Eigen::Affine3f & anchor, bool relative_to_prior, double stamp_sec,
    Eigen::Affine3f & consensus, std::size_t & consensus_size)
  {
    if (!global_init_votes_.empty() &&
      (global_init_votes_.back().relative_to_prior != relative_to_prior ||
      stamp_sec - global_init_votes_.back().stamp_sec > global_init_vote_timeout_sec_ ||
      stamp_sec < global_init_votes_.back().stamp_sec))
    {
      global_init_votes_.clear();
    }
    GlobalInitVote vote;
    vote.anchor = anchor;
    vote.relative_to_prior = relative_to_prior;
    vote.stamp_sec = stamp_sec;
    global_init_votes_.push_back(vote);
    while (static_cast<int>(global_init_votes_.size()) > global_init_max_votes_) {
      global_init_votes_.erase(global_init_votes_.begin());
    }

    std::vector<std::size_t> best_cluster;
    for (std::size_t i = 0; i < global_init_votes_.size(); ++i) {
      float center[6];
      affineToTrans(global_init_votes_[i].anchor, center);
      std::vector<std::size_t> cluster;
      for (std::size_t j = 0; j < global_init_votes_.size(); ++j) {
        float candidate[6];
        affineToTrans(global_init_votes_[j].anchor, candidate);
        const double xy_difference = std::hypot(
          candidate[3] - center[3], candidate[4] - center[4]);
        const double yaw_difference = std::abs(
          std::atan2(
            std::sin(candidate[2] - center[2]), std::cos(candidate[2] - center[2])));
        if (xy_difference <= global_init_vote_xy_tolerance_ &&
          yaw_difference <= global_init_vote_yaw_tolerance_)
        {
          cluster.push_back(j);
        }
      }
      if (cluster.size() > best_cluster.size()) {
        best_cluster = std::move(cluster);
      }
    }

    consensus_size = best_cluster.size();
    if (static_cast<int>(best_cluster.size()) < global_init_required_votes_) {
      return false;
    }

    double translation_sum[3] = {0.0, 0.0, 0.0};
    double rotation_sin_sum[3] = {0.0, 0.0, 0.0};
    double rotation_cos_sum[3] = {0.0, 0.0, 0.0};
    for (const std::size_t index : best_cluster) {
      float pose[6];
      affineToTrans(global_init_votes_[index].anchor, pose);
      for (int axis = 0; axis < 3; ++axis) {
        rotation_sin_sum[axis] += std::sin(pose[axis]);
        rotation_cos_sum[axis] += std::cos(pose[axis]);
        translation_sum[axis] += pose[axis + 3];
      }
    }
    const double count = static_cast<double>(best_cluster.size());
    consensus = pcl::getTransformation(
      static_cast<float>(translation_sum[0] / count),
      static_cast<float>(translation_sum[1] / count),
      static_cast<float>(translation_sum[2] / count),
      static_cast<float>(std::atan2(rotation_sin_sum[0], rotation_cos_sum[0])),
      static_cast<float>(std::atan2(rotation_sin_sum[1], rotation_cos_sum[1])),
      static_cast<float>(std::atan2(rotation_sin_sum[2], rotation_cos_sum[2])));
    return true;
  }

  bool relocalizationUsesPrior(double stamp_sec) const
  {
    float unused[6];
    return have_loss_map_to_prior_ && have_prior_ && loss_prior_tracking_valid_ &&
           interpolatePrior(stamp_sec, unused);
  }

  double relocalizationRadius(double stamp_sec) const
  {
    const double elapsed_sec = std::max(0.0, stamp_sec - loss_started_sec_);
    const double odom_radius_m = relocalization_xy_initial_radius_m_ +
      relocalization_xy_error_per_odom_meter_ * loss_prior_distance_m_;
    if (relocalizationUsesPrior(stamp_sec)) {
      return odom_radius_m;
    }
    // 도중에 odom까지 끊기거나 이상치가 검출되면 마지막 정상 odom 위치는 유지하고,
    // 그 시점부터 실제 차량이 이동할 수 있는 최대 거리만 원에 추가한다.
    if (have_loss_last_prior_) {
      const double odom_lost_sec = std::max(
        0.0, stamp_sec - loss_last_prior_stamp_.seconds());
      return odom_radius_m + relocalization_max_vehicle_speed_mps_ * odom_lost_sec;
    }
    // PCD 손실 시점부터 유효한 odom이 없었던 경우에만 마지막 PCD 위치에서 확장한다.
    return relocalization_xy_initial_radius_m_ +
           relocalization_max_vehicle_speed_mps_ * elapsed_sec;
  }

  LocalizationState relocalizationState(double stamp_sec) const
  {
    const double radius_m = relocalizationRadius(stamp_sec);
    return radius_m >= relocalization_xy_stop_radius_m_ ?
           LocalizationState::Lost : LocalizationState::MayLost;
  }

  loam_fgo_localization::Se2SearchWindow relocalizationSearchWindow(double stamp_sec) const
  {
    const double elapsed_sec = std::max(0.0, stamp_sec - loss_started_sec_);
    const double radius_m = std::min(
      relocalization_xy_stop_radius_m_, relocalizationRadius(stamp_sec));
    const double yaw_half_range_rad = std::min(
      relocalization_yaw_max_half_range_rad_,
      relocalization_yaw_initial_half_range_rad_ +
      relocalization_yaw_growth_rad_per_sec_ * elapsed_sec);

    Eigen::Affine3f predicted_pose = loss_origin_pose_;
    float scan_prior[6];
    if (relocalizationUsesPrior(stamp_sec) &&
      interpolatePrior(stamp_sec, scan_prior))
    {
      // BBS 는 이 스캔(과거 스탬프)을 정합하므로 예측 중심도 같은 시각으로.
      predicted_pose = loss_map_to_prior_ * trans2Affine3f(scan_prior);
    } else if (have_loss_last_prior_) {
      predicted_pose = loss_map_to_prior_ * trans2Affine3f(loss_last_prior_);
    }
    float predicted_transform[6];
    affineToTrans(predicted_pose, predicted_transform);
    // 2026-08-19: GPS coarse prior 가 신선하면 위치 원을 GPS 로 좁힌다 (yaw 중심은
    // 계속 odom 예측). 기존에는 재초기화가 odom 확장 원(최대 stop_radius)만 써서
    // float GPS(σ 수십 cm)라는 훨씬 좋은 위치 정보를 버리고 있었다.
    // 안테나-라이다 수평 오프셋(~0.2m)은 최소 반경(xy_initial)에 흡수된다.
    if (have_global_init_position_prior_ &&
      std::abs(stamp_sec - global_init_position_prior_stamp_.seconds()) <=
      global_init_position_prior_max_age_sec_)
    {
      const double gps_radius_m = std::clamp(
        global_init_position_prior_sigma_ * global_init_position_prior_sigma_scale_,
        relocalization_xy_initial_radius_m_, relocalization_xy_stop_radius_m_);
      if (gps_radius_m < radius_m) {
        return {
          global_init_position_prior_x_, global_init_position_prior_y_, gps_radius_m,
          predicted_transform[2], yaw_half_range_rad};
      }
    }
    return {
      predicted_transform[3], predicted_transform[4], radius_m,
      predicted_transform[2], yaw_half_range_rad};
  }

  void invalidateLossPriorTracking(const char * reason)
  {
    if (!loss_prior_tracking_valid_) {
      return;
    }
    loss_prior_tracking_valid_ = false;
    RCLCPP_WARN(
      get_logger(),
      "relocalization odom rejected (%s); using last valid odom pose and time bound",
      reason);
  }

  void updateLossPriorTracking()
  {
    if (!loss_active_ || !loss_prior_tracking_valid_) {
      return;
    }

    const double dt = (latest_prior_stamp_ - loss_last_prior_stamp_).seconds();
    if (dt == 0.0) {
      return;
    }
    if (dt < 0.0 || dt > prior_timeout_sec_) {
      invalidateLossPriorTracking("non-continuous timestamp");
      return;
    }

    const double dx = latest_prior_[3] - loss_last_prior_[3];
    const double dy = latest_prior_[4] - loss_last_prior_[4];
    const double distance_m = std::hypot(dx, dy);
    const double yaw_step_rad = std::abs(
      std::atan2(
        std::sin(latest_prior_[2] - loss_last_prior_[2]),
        std::cos(latest_prior_[2] - loss_last_prior_[2])));
    const double max_distance_m =
      relocalization_max_vehicle_speed_mps_ * dt + relocalization_odom_jump_tolerance_m_;
    const double max_yaw_step_rad =
      relocalization_max_odom_yaw_rate_rad_per_sec_ * dt +
      relocalization_odom_yaw_jump_tolerance_rad_;
    // 타임스탬프 역행이나 물리 한계를 넘는 위치·yaw 점프는 검출할 수 있다.
    // 반대로, 물리적으로 가능한 값으로 서서히 잘못된 방향을 가리키는 odom은
    // 같은 odom만으로 실제 주행과 구분할 수 없으므로 BBS 실패와 외부 기준으로 판단해야 한다.
    if (!std::isfinite(distance_m) || !std::isfinite(yaw_step_rad) ||
      distance_m > max_distance_m || yaw_step_rad > max_yaw_step_rad)
    {
      invalidateLossPriorTracking("implausible pose increment");
      return;
    }

    loss_prior_distance_m_ += distance_m;
    std::copy(
      std::begin(latest_prior_), std::end(latest_prior_), std::begin(loss_last_prior_));
    loss_last_prior_stamp_ = latest_prior_stamp_;
  }

  void beginRelocalization(double stamp_sec)
  {
    if (relocalizing_) {
      return;
    }
    relocalizing_ = true;
    received_initial_pose_ = false;
    initialized_ = false;
    have_increment_ = false;
    global_init_votes_.clear();
    last_global_init_attempt_sec_ = -std::numeric_limits<double>::infinity();
    local_map_ready_ = false;
    setState(relocalizationState(stamp_sec), "persistent loss; starting bounded BBS");
  }

  bool attemptGlobalInitialization(
    const lio_sam::msg::CloudInfo & msg, bool relocalizing)
  {
    const double retry_interval_sec = relocalizing ?
      relocalization_retry_interval_sec_ : global_init_retry_interval_sec_;
    if (!global_init_matcher_ || !globalInitializationDue(msg, retry_interval_sec)) {
      return false;
    }
    if (!msg.imu_available) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "waiting for IMU roll/pitch before SE(2) BBS global initialization");
      return false;
    }

    if (!relocalizing) {
      setState(LocalizationState::Initializing, "SE(2) BBS initialization");
    }
    const auto start = SteadyClock::now();
    const Eigen::Affine3f gravity_alignment = pcl::getTransformation(
      0.0f, 0.0f, 0.0f, msg.imu_roll_init, msg.imu_pitch_init, 0.0f);
    std::vector<loam_fgo_localization::Se2Point> leveled_scan;
    leveled_scan.reserve(corner_last_ds_->size());
    for (const auto & point : corner_last_ds_->points) {
      PointT leveled;
      pointAssociateToMap(gravity_alignment, point, leveled);
      leveled_scan.push_back({leveled.x, leveled.y});
    }

    const double stamp_sec = rclcpp::Time(msg.header.stamp).seconds();
    // 사전정보의 나이. 만료됐다고 **버리지 않는다** —
    //   이 콜백이 BBS 로 실행기를 ~1.08 초 독점하는 동안 GPS 사전정보가 큐에서
    //   빠져나오지 못해, 다음 스캔 시점에는 항상 만료돼 있다. 자기 기아 루프다.
    //   그 결과 실측 69/69 회가 radius=0 (사전정보 없음)으로 660x557 m 전체를
    //   1 초 예산에 뒤졌고, yaw 답 산포 96도, 위치 오차 143 m, 초기화 성공 0회였다.
    // 오래된 사전정보도 "그 사이 최대 얼마나 움직였는가"만 반경에 더하면 여전히
    // 유효하다. 3 초 된 사전정보 + 여유 반경이, 사전정보 없는 전역 탐색보다 낫다.
    const double prior_age = have_global_init_position_prior_
      ? std::abs(stamp_sec - global_init_position_prior_stamp_.seconds())
      : std::numeric_limits<double>::infinity();
    const bool use_position_prior = !relocalizing && have_global_init_position_prior_ &&
      prior_age <= global_init_position_prior_stale_limit_sec_;
    double position_search_radius = 0.0;
    double yaw_search_half_range = M_PI;
    const char * search_name = "global_xy+yaw";
    loam_fgo_localization::Se2BranchAndBoundResult match;
    if (relocalizing) {
      const auto search_window = relocalizationSearchWindow(stamp_sec);
      position_search_radius = search_window.radius_m;
      yaw_search_half_range = search_window.yaw_half_range_rad;
      search_name = "loss_circle+bounded_yaw";
      match = global_init_matcher_->match(leveled_scan, search_window);
    } else if (use_position_prior) {
      // 나이만큼 반경을 키운다: 그 시간 동안 차량이 갈 수 있는 거리 + 여유.
      const double age_slack = std::max(0.0, prior_age) *
        global_init_position_prior_speed_margin_;
      position_search_radius = std::clamp(
        global_init_position_prior_sigma_ * global_init_position_prior_sigma_scale_ +
        age_slack,
        global_init_position_prior_min_radius_, global_init_position_prior_max_radius_);
      const loam_fgo_localization::Se2SearchWindow search_window{
        global_init_position_prior_x_, global_init_position_prior_y_,
        position_search_radius};
      search_name = prior_age <= global_init_position_prior_max_age_sec_
        ? "gps_circle+yaw" : "gps_circle+yaw(aged)";
      match = global_init_matcher_->match(leveled_scan, search_window);
    } else {
      match = global_init_matcher_->match(leveled_scan);
    }
    if (!match.found ||
      static_cast<int>(match.scan_points) < global_init_min_corner_points_)
    {
      publishCorrectionStatus("global_init_rejected");
      setState(
        relocalizing ? relocalizationState(stamp_sec) : LocalizationState::NonInitialized,
        "SE(2) BBS match rejected");
      RCLCPP_WARN(
        get_logger(),
        "SE(2) BBS initialization rejected: search=%s radius=%.1f yaw_half=%.1f deg "
        "score=%.3f scan=%zu "
        "nodes=%llu leaves=%llu time=%.1f ms%s",
        search_name, position_search_radius, yaw_search_half_range * 180.0 / M_PI,
        match.score, match.scan_points,
        static_cast<unsigned long long>(match.scored_nodes),
        static_cast<unsigned long long>(match.leaf_nodes), elapsedMs(start),
        match.timed_out ? " (time budget hit)" : "");
      return false;
    }

    std::optional<double> map_z_prior;
    if (!global_init_use_prior_z_) {
      map_z_prior = global_init_z_center_;
    } else if (relocalizing && have_loss_map_to_prior_) {
      float height_prior[6];
      if (relocalizationUsesPrior(stamp_sec) && interpolatePrior(stamp_sec, height_prior)) {
        map_z_prior = loam_fgo_localization::mappedPriorHeight(
          loss_map_to_prior_, trans2Affine3f(height_prior));
      } else if (have_loss_last_prior_) {
        map_z_prior = loam_fgo_localization::mappedPriorHeight(
          loss_map_to_prior_, trans2Affine3f(loss_last_prior_));
      }
    }
    const auto z_estimate = estimateGlobalZ(
      msg.imu_roll_init, msg.imu_pitch_init, static_cast<float>(match.yaw),
      static_cast<float>(match.x), static_cast<float>(match.y), map_z_prior);
    if (!z_estimate.found) {
      global_init_votes_.clear();
      publishCorrectionStatus("global_init_height_rejected");
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "SE(2) BBS height rejected: no 3D support at xy=(%.2f %.2f)", match.x, match.y);
      return false;
    }
    RCLCPP_INFO_THROTTLE(
      get_logger(), *get_clock(), 2000,
      "BBS map height: range=[%.2f %.2f] prior=%.2f z=%.2f score=%.3f evaluations=%zu",
      z_estimate.lower, z_estimate.upper,
      map_z_prior.value_or(std::numeric_limits<double>::quiet_NaN()),
      z_estimate.z, z_estimate.score, z_estimate.evaluations);
    float candidate_transform[6] = {
      msg.imu_roll_init,
      msg.imu_pitch_init,
      static_cast<float>(match.yaw),
      static_cast<float>(match.x),
      static_cast<float>(match.y),
      static_cast<float>(z_estimate.z)};
    const Eigen::Affine3f candidate_map_to_lidar = trans2Affine3f(candidate_transform);
    // 투표 앵커도 "스캔 시각" 보간 prior 와 짝지어야 한다 (시간축 정합).
    float scan_prior[6] = {0, 0, 0, 0, 0, 0};
    const bool relative_to_prior = use_prior_odom_ &&
      interpolatePrior(stamp_sec, scan_prior);
    const Eigen::Affine3f vote_anchor = relative_to_prior ?
      candidate_map_to_lidar * trans2Affine3f(scan_prior).inverse() :
      candidate_map_to_lidar;
    Eigen::Affine3f consensus_anchor = Eigen::Affine3f::Identity();
    std::size_t consensus_size = 0;
    if (!addGlobalInitVote(
        vote_anchor, relative_to_prior, stamp_sec, consensus_anchor, consensus_size))
    {
      publishCorrectionStatus("global_init_voting");
      // 2026-08-19: 스로틀 걸어 재활성. 투표 루프는 이 로그가 유일한 진행 신호라
      // 꺼두면 재초기화 정체가 완전 무음이 된다 (DCU bag 5분 무음 마비의 교훈).
      RCLCPP_INFO_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "SE(2) BBS vote %zu/%d: search=%s radius=%.1f xyz=(%.2f %.2f %.2f) yaw=%.3f "
        "score=%.3f%s time=%.1f ms",
        consensus_size, global_init_required_votes_, search_name, position_search_radius,
        candidate_transform[3], candidate_transform[4], candidate_transform[5],
        candidate_transform[2], match.score,
        match.timed_out ? " (time budget hit)" : "", elapsedMs(start));
      return false;
    }

    const Eigen::Affine3f map_to_lidar = relative_to_prior ?
      consensus_anchor * trans2Affine3f(scan_prior) : consensus_anchor;
    affineToTrans(map_to_lidar, transform_);
    global_init_votes_.clear();
    if (use_prior_odom_) {
      if (relative_to_prior) {
        // transform_ = 스캔 시각 자세 -> 같은 시각의 보간 prior 와 짝
        map_to_prior_ = map_to_lidar * trans2Affine3f(scan_prior).inverse();
        have_map_to_prior_ = true;
      } else if (have_prior_) {
        map_to_prior_ = map_to_lidar * trans2Affine3f(latest_prior_).inverse();
        have_map_to_prior_ = true;
      } else {
        pending_map_to_lidar_ = map_to_lidar;
        have_pending_global_pose_ = true;
      }
    }
    received_initial_pose_ = true;
    initialized_ = false;
    have_increment_ = false;
    if (!relocalizing) {
      consecutive_failures_ = 0;
      path_.poses.clear();
    }
    last_imu_rot_ = pcl::getTransformation(
      0.0f, 0.0f, 0.0f, msg.imu_roll_init, msg.imu_pitch_init, msg.imu_yaw_init);
    updateAcceptedPose(false);
    global_seed_pending_ = true;
    global_seed_relocalization_ = relocalizing;
    publishCorrectionStatus("global_init_seeded");
    // 2026-08-19: 재활성 (합의당 1회라 반복 아님 — 초기화/재초기화 추적에 필수)
    RCLCPP_INFO(
      get_logger(),
      "SE(2) BBS seed: xyz=(%.2f %.2f %.2f) rpy=(%.3f %.3f %.3f) "
      "search=%s radius=%.1f yaw_half=%.1f deg score=%.3f z_score=%.3f scan=%zu "
      "nodes=%llu/%llu leaves=%llu time=%.1f ms",
      transform_[3], transform_[4], transform_[5], transform_[0], transform_[1], transform_[2],
      search_name, position_search_radius, yaw_search_half_range * 180.0 / M_PI,
      match.score, z_estimate.score, match.scan_points,
      static_cast<unsigned long long>(match.scored_nodes),
      static_cast<unsigned long long>(match.exhaustive_leaf_count),
      static_cast<unsigned long long>(match.leaf_nodes), elapsedMs(start));
    return true;
  }

  void rejectPendingGlobalSeed(const char * reason)
  {
    if (!global_seed_pending_) {
      return;
    }
    const bool was_relocalization = global_seed_relocalization_;
    global_seed_pending_ = false;
    global_seed_relocalization_ = false;
    global_init_votes_.clear();
    received_initial_pose_ = false;
    initialized_ = false;
    have_map_to_prior_ = false;
    have_pending_global_pose_ = false;
    have_increment_ = false;
    if (!was_relocalization) {
      consecutive_failures_ = 0;
      path_.poses.clear();
    }
    local_map_ready_ = false;
    setState(
      was_relocalization ? state_ : LocalizationState::NonInitialized,
      reason);
  }

  void cloudInfoHandler(const lio_sam::msg::CloudInfo::SharedPtr msg)
  {
    if (!processing_enabled_) {
      return;
    }
    // 맵 로드 전(번들 경로 토픽 대기 중) 스캔 방어: 이 가드가 없으면 bag/센서가
    // 먼저 흐를 때 전역초기화가 빈 맵으로 BBS match 를 호출해 logic_error 로
    // 노드가 종료된다 (2026-08-03 로봇 재현: FATAL 후 exit 0 -> "finished cleanly").
    if (corner_map_ds_->empty() || surf_map_ds_->empty()) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 5000,
        "map not loaded yet (%zu corner / %zu surf); skipping scan",
        corner_map_ds_->size(), surf_map_ds_->size());
      return;
    }
    // 실행자 공정성으로 적체된 odom 큐를 매칭 전에 전부 소비 (시간축 정합의 전제).
    drainPriorOdomQueue();
    const auto t_total = SteadyClock::now();
    const auto t_convert = SteadyClock::now();
    pcl::fromROSMsg(msg->cloud_corner, *corner_last_);
    pcl::fromROSMsg(msg->cloud_surface, *surf_last_);
    const double convert_ms = elapsedMs(t_convert);
    if (corner_last_->empty() || surf_last_->empty()) {
      return;
    }

    const bool can_global_initialize = global_init_matcher_ != nullptr;
    if (require_initial_pose_ && !received_initial_pose_ && !can_global_initialize) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "waiting for %s before fixed-map localization", initial_pose_topic_.c_str());
      publishState();
      return;
    }

    if (require_initial_pose_without_prior_ && !use_prior_odom_ && !initialized_ &&
      !can_global_initialize)
    {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "waiting for %s before fixed-map localization", initial_pose_topic_.c_str());
      publishState();
      return;
    }

    bool scan_downsampled = false;
    double downsample_ms = 0.0;
    const double stamp_sec = rclcpp::Time(msg->header.stamp).seconds();
    const bool start_relocalization = relocalization_enabled_ && loss_active_ &&
      !relocalizing_ &&
      (state_ == LocalizationState::MayLost || state_ == LocalizationState::Lost) &&
      stamp_sec - loss_started_sec_ >= relocalization_start_after_sec_;
    if (start_relocalization) {
      beginRelocalization(stamp_sec);
    }
    if (relocalizing_ && state_ != relocalizationState(stamp_sec)) {
      setState(relocalizationState(stamp_sec), "relocalization uncertainty expanded");
    }

    if (!received_initial_pose_ && can_global_initialize) {
      const auto t_downsample = SteadyClock::now();
      downsampleCurrentScan();
      downsample_ms = elapsedMs(t_downsample);
      scan_downsampled = true;
      if (static_cast<int>(corner_last_ds_->size()) < global_init_min_corner_points_ ||
        !attemptGlobalInitialization(*msg, relocalizing_))
      {
        publishState();
        return;
      }
    }

    const auto t_guess = SteadyClock::now();
    updateInitialGuess(*msg);
    const double guess_ms = elapsedMs(t_guess);
    const Eigen::Affine3f predicted_pose = trans2Affine3f(transform_);
    const auto t_lookup = SteadyClock::now();
    updateLookupMaps();
    const double lookup_ms = elapsedMs(t_lookup);
    if (!scan_downsampled) {
      const auto t_downsample = SteadyClock::now();
      downsampleCurrentScan();
      downsample_ms = elapsedMs(t_downsample);
    }

    last_optimize_ms_ = 0.0;
    OptimizationResult result = OptimizationResult::InsufficientConstraints;
    if (static_cast<int>(corner_last_ds_->size()) > edge_min_valid_ &&
      static_cast<int>(surf_last_ds_->size()) > surf_min_valid_)
    {
      const auto t_optimize = SteadyClock::now();
      result = optimize();
      last_optimize_ms_ = elapsedMs(t_optimize);
    }

    auto log_profile = [&](const char * correction_status, double publish_ms) {
        cb_timing_.add(elapsedMs(t_total));
        if (cb_timing_.due()) {
          RCLCPP_INFO(get_logger(), "cb %s", cb_timing_.flush("scan_match").c_str());
        }
        if (!profile_timings_) {
          return;
        }
        const double total_ms = elapsedMs(t_total);
        std_msgs::msg::Float64MultiArray timing;
        timing.data = {
          rclcpp::Time(msg->header.stamp).seconds(), total_ms};
        pub_cycle_time_->publish(timing);
        RCLCPP_INFO(
          get_logger(),
          "profile localizer bag_stamp=%.9f total=%.1f convert=%.1f guess=%.1f "
          "lookup=%.1f downsample=%.1f "
          "optimize=%.1f publish=%.1f opt_iter=%d corner=%.1f surf=%.1f combine=%.1f lm=%.1f "
          "corner_query=%.1f corner_search=%.1f corner_coeff=%.1f "
          "surf_query=%.1f surf_search=%.1f surf_coeff=%.1f "
          "scan_corner=%zu scan_surf=%zu coeff=%zu local_corner=%zu local_surf=%zu correction=%s",
          rclcpp::Time(msg->header.stamp).seconds(),
          total_ms, convert_ms, guess_ms, lookup_ms, downsample_ms,
          last_optimize_ms_, publish_ms, last_opt_iters_, last_corner_ms_, last_surf_ms_,
          last_combine_ms_, last_lm_ms_, last_corner_query_ms_, last_corner_search_ms_,
          last_corner_coeff_ms_, last_surf_query_ms_, last_surf_search_ms_, last_surf_coeff_ms_,
          corner_last_ds_->size(), surf_last_ds_->size(),
          last_coeff_count_, corner_lookup_map_->size(), surf_lookup_map_->size(),
          correction_status);
      };

    if (result != OptimizationResult::Converged) {
      restorePoseAfterRejectedCorrection(predicted_pose);
      const bool global_seed_rejected = global_seed_pending_;
      const char * status = global_seed_rejected ?
        "global_init_refinement_rejected" : optimizationResultName(result);
      publishCorrectionStatus(status);
      if (global_seed_pending_) {
        rejectPendingGlobalSeed("BBS seed failed local refinement");
      } else {
        recordFailure(status, rclcpp::Time(msg->header.stamp).seconds());
      }
      // 2026-08-25 복원 (스로틀 2s): 추적 상실의 "왜"가 이 로그에만 있다.
      // 20260813 재생에서 원인 불명 rejected_max_iterations -> Lost 를 이 로그
      // 없이는 진단할 수 없었다. 정상 주행에선 드물어 소음 아님.
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "localization correction rejected: reason=%s corner=%zu surf=%zu iterations=%d",
        status, corner_last_ds_->size(), surf_last_ds_->size(), last_opt_iters_);
      double publish_ms = 0.0;
      if (last_guess_from_prior_ && !global_seed_rejected) {
        const auto t_publish = SteadyClock::now();
        publishResult(msg->header, false);
        publish_ms = elapsedMs(t_publish);
      }
      log_profile(status, publish_ms);
      return;
    }

    const double correction_x = transform_[3] - predicted_pose.translation().x();
    const double correction_y = transform_[4] - predicted_pose.translation().y();
    const double correction_step = std::hypot(correction_x, correction_y);
    if (correction_step > max_step_xy_) {
      restorePoseAfterRejectedCorrection(predicted_pose);
      const bool global_seed_rejected = global_seed_pending_;
      const char * status = global_seed_rejected ?
        "global_init_refinement_rejected" : "rejected_step";
      publishCorrectionStatus(status);
      if (global_seed_pending_) {
        rejectPendingGlobalSeed("BBS seed failed correction step gate");
      } else {
        recordFailure(status, rclcpp::Time(msg->header.stamp).seconds());
      }
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 1000,
        "localization correction rejected by step gate: correction=%.2f m", correction_step);
      double publish_ms = 0.0;
      if (last_guess_from_prior_ && !global_seed_rejected) {
        const auto t_publish = SteadyClock::now();
        publishResult(msg->header, false);
        publish_ms = elapsedMs(t_publish);
      }
      log_profile("rejected_step", publish_ms);
      return;
    }

    reanchorPriorToAcceptedPose();
    if (global_seed_pending_) {
      const bool recovered = global_seed_relocalization_;
      global_seed_pending_ = false;
      global_seed_relocalization_ = false;
      RCLCPP_INFO(
        get_logger(), "SE(2) BBS %s accepted by 6-DoF local refinement",
        recovered ? "relocalization" : "seed");
    }
    const auto t_publish = SteadyClock::now();
    updateAcceptedPose();
    publishCorrectionStatus("accepted");
    publishResult(msg->header, true);
    const double publish_ms = elapsedMs(t_publish);
    log_profile("accepted", publish_ms);
  }

  void updateInitialGuess(const lio_sam::msg::CloudInfo & msg)
  {
    last_guess_from_prior_ = false;
    if (use_prior_odom_ && have_prior_) {
      // 스캔 스탬프 시각으로 보간한 prior 사용 (latest 사용 금지 — 백로그 시
      // 추정이 스캔보다 backlog x 속도 만큼 앞서 나가는 시간축 불일치 버그).
      const double stamp = rclcpp::Time(msg.header.stamp).seconds();
      if (interpolatePrior(stamp, last_used_prior_)) {
        Eigen::Affine3f prior_pose = trans2Affine3f(last_used_prior_);
        if (have_map_to_prior_) {
          prior_pose = map_to_prior_ * prior_pose;
        }
        affineToTrans(prior_pose, transform_);
        if (state_ == LocalizationState::NonInitialized) {
          setState(LocalizationState::Initializing, "fresh prior odom received");
        }
        last_guess_from_prior_ = true;
        return;
      }
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 1000,
        "prior odom not interpolable at scan stamp (age=%.3f sec vs buffer)",
        std::abs((rclcpp::Time(msg.header.stamp) - latest_prior_stamp_).seconds()));
    }

    if (!initialized_) {
      transform_[0] = msg.imu_roll_init;
      transform_[1] = msg.imu_pitch_init;
      transform_[2] = 0.0f;
      last_imu_rot_ = pcl::getTransformation(
        0, 0, 0, msg.imu_roll_init, msg.imu_pitch_init,
        msg.imu_yaw_init);
      return;
    }

    if (use_constant_velocity_guess_ && have_increment_) {
      Eigen::Affine3f predicted = trans2Affine3f(transform_) * last_increment_;
      affineToTrans(predicted, transform_);
    }

    if (msg.imu_available) {
      Eigen::Affine3f cur_imu = pcl::getTransformation(
        0, 0, 0, msg.imu_roll_init,
        msg.imu_pitch_init, msg.imu_yaw_init);
      Eigen::Affine3f imu_incre = last_imu_rot_.inverse() * cur_imu;
      Eigen::Affine3f pred = trans2Affine3f(transform_) * imu_incre;
      affineToTrans(pred, transform_);
      last_imu_rot_ = cur_imu;
    }
  }

  void downsampleCurrentScan()
  {
    pcl::VoxelGrid<PointT> vg;
    vg.setInputCloud(corner_last_);
    vg.setLeafSize(scan_corner_leaf_, scan_corner_leaf_, scan_corner_leaf_);
    vg.filter(*corner_last_ds_);

    vg.setInputCloud(surf_last_);
    vg.setLeafSize(scan_surf_leaf_, scan_surf_leaf_, scan_surf_leaf_);
    vg.filter(*surf_last_ds_);

    corner_ori_vec_.assign(corner_last_ds_->size(), PointT());
    corner_coeff_vec_.assign(corner_last_ds_->size(), PointT());
    corner_flag_.assign(corner_last_ds_->size(), false);
    surf_ori_vec_.assign(surf_last_ds_->size(), PointT());
    surf_coeff_vec_.assign(surf_last_ds_->size(), PointT());
    surf_flag_.assign(surf_last_ds_->size(), false);
  }

  void updateLookupMaps()
  {
    if (!use_local_map_window_) {
      useFullLookupMaps();
      return;
    }

    const double dx = transform_[3] - local_map_center_[0];
    const double dy = transform_[4] - local_map_center_[1];
    const double dz = transform_[5] - local_map_center_[2];
    if (local_map_ready_ && std::sqrt(dx * dx + dy * dy + dz * dz) < local_map_rebuild_dist_) {
      return;
    }

    rebuildLocalLookupMaps();
  }

  void useFullLookupMaps()
  {
    if (corner_lookup_map_ == corner_map_ds_ && surf_lookup_map_ == surf_map_ds_) {
      return;
    }
    corner_lookup_map_ = corner_map_ds_;
    surf_lookup_map_ = surf_map_ds_;
    kdtree_corner_.setInputCloud(corner_lookup_map_);
    kdtree_surf_.setInputCloud(surf_lookup_map_);
    uploadCudaLookupMaps();
    local_map_ready_ = false;
  }

  void rebuildLocalLookupMaps()
  {
    corner_map_local_->clear();
    surf_map_local_->clear();

    const double cx = transform_[3];
    const double cy = transform_[4];
    const double radius2 = local_map_radius_ * local_map_radius_;

    // ponytail: radius crop approximates the ROS1 keyframe window until per-keyframe maps are needed.
    for (const auto & p : corner_map_ds_->points) {
      const double dx = p.x - cx;
      const double dy = p.y - cy;
      if (dx * dx + dy * dy <= radius2) {
        corner_map_local_->push_back(p);
      }
    }
    for (const auto & p : surf_map_ds_->points) {
      const double dx = p.x - cx;
      const double dy = p.y - cy;
      if (dx * dx + dy * dy <= radius2) {
        surf_map_local_->push_back(p);
      }
    }

    if (static_cast<int>(corner_map_local_->size()) < min_local_corner_points_ ||
      static_cast<int>(surf_map_local_->size()) < min_local_surf_points_)
    {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 1000,
        "local map too sparse near pose=(%.2f %.2f): corner=%zu surf=%zu; using full map",
        cx, cy, corner_map_local_->size(), surf_map_local_->size());
      useFullLookupMaps();
      return;
    }

    corner_lookup_map_ = corner_map_local_;
    surf_lookup_map_ = surf_map_local_;
    kdtree_corner_.setInputCloud(corner_lookup_map_);
    kdtree_surf_.setInputCloud(surf_lookup_map_);
    uploadCudaLookupMaps();
    local_map_center_[0] = transform_[3];
    local_map_center_[1] = transform_[4];
    local_map_center_[2] = transform_[5];
    local_map_ready_ = true;

    RCLCPP_INFO_THROTTLE(
      get_logger(), *get_clock(), 2000,
      "rebuilt local map window: center=(%.2f %.2f), radius=%.1f, corner=%zu surf=%zu",
      local_map_center_[0], local_map_center_[1], local_map_radius_,
      corner_lookup_map_->size(), surf_lookup_map_->size());
  }

  OptimizationResult optimize()
  {
    last_corner_ms_ = 0.0;
    last_surf_ms_ = 0.0;
    last_combine_ms_ = 0.0;
    last_lm_ms_ = 0.0;
    last_corner_query_ms_ = 0.0;
    last_corner_search_ms_ = 0.0;
    last_corner_coeff_ms_ = 0.0;
    last_surf_query_ms_ = 0.0;
    last_surf_search_ms_ = 0.0;
    last_surf_coeff_ms_ = 0.0;
    last_opt_iters_ = 0;
    last_coeff_count_ = 0;
    for (int iter = 0; iter < max_iterations_; ++iter) {
      ++last_opt_iters_;
      laser_ori_->clear();
      coeff_sel_->clear();
      const auto t_corner = SteadyClock::now();
      findCornerCoeffs();
      last_corner_ms_ += elapsedMs(t_corner);
      const auto t_surf = SteadyClock::now();
      findSurfCoeffs();
      last_surf_ms_ += elapsedMs(t_surf);
      const auto t_combine = SteadyClock::now();
      combineCoeffs();
      last_combine_ms_ += elapsedMs(t_combine);
      last_coeff_count_ = laser_ori_->size();
      if (laser_ori_->size() < 50) {
        return OptimizationResult::InsufficientConstraints;
      }
      const auto t_lm = SteadyClock::now();
      const LmStepResult step_result = LMOptimization(iter);
      last_lm_ms_ += elapsedMs(t_lm);
      if (step_result == LmStepResult::Invalid) {
        return OptimizationResult::InvalidUpdate;
      }
      if (step_result == LmStepResult::Converged) {
        applyImuRPYConstraint();
        return OptimizationResult::Converged;
      }
    }
    return OptimizationResult::MaxIterations;
  }

  void findCornerCoeffs()
  {
    if (use_cuda_lookup_) {
      findCornerCoeffsCuda();
      return;
    }
    findCornerCoeffsCpu();
  }

  void findCornerCoeffsCpu()
  {
    const auto tf = trans2Affine3f(transform_);
    for (size_t i = 0; i < corner_last_ds_->size(); ++i) {
      PointT point_sel, coeff;
      const auto t_query = SteadyClock::now();
      pointAssociateToMap(tf, corner_last_ds_->points[i], point_sel);
      last_corner_query_ms_ += elapsedMs(t_query);

      std::vector<int> ind;
      std::vector<float> sqdis;
      const auto t_search = SteadyClock::now();
      if (kdtree_corner_.nearestKSearch(point_sel, 5, ind, sqdis) < 5 || sqdis[4] >= 1.0f) {
        last_corner_search_ms_ += elapsedMs(t_search);
        continue;
      }
      last_corner_search_ms_ += elapsedMs(t_search);

      const int idx[5] = {ind[0], ind[1], ind[2], ind[3], ind[4]};
      const auto t_coeff = SteadyClock::now();
      if (!computeCornerCoeff(point_sel, idx, coeff)) {
        last_corner_coeff_ms_ += elapsedMs(t_coeff);
        continue;
      }
      last_corner_coeff_ms_ += elapsedMs(t_coeff);

      corner_ori_vec_[i] = corner_last_ds_->points[i];
      corner_coeff_vec_[i] = coeff;
      corner_flag_[i] = true;
    }
  }

  void findCornerCoeffsCuda()
  {
#ifdef LIO_SAM_LOCALIZATION_HAS_CUDA
    const auto tf = trans2Affine3f(transform_);
    std::vector<loam_fgo_localization::CudaPoint3> queries;
    std::vector<PointT> point_sels;
    queries.reserve(corner_last_ds_->size());
    point_sels.resize(corner_last_ds_->size());
    const auto t_query = SteadyClock::now();
    for (size_t i = 0; i < corner_last_ds_->size(); ++i) {
      pointAssociateToMap(tf, corner_last_ds_->points[i], point_sels[i]);
      queries.push_back({point_sels[i].x, point_sels[i].y, point_sels[i].z});
    }
    last_corner_query_ms_ += elapsedMs(t_query);

    const auto t_search = SteadyClock::now();
    corner_cuda_.nearestKSearch5(queries, corner_cuda_indices_, corner_cuda_sqdis_);
    last_corner_search_ms_ += elapsedMs(t_search);
    const auto t_coeffs = SteadyClock::now();
    for (size_t i = 0; i < corner_last_ds_->size(); ++i) {
      const size_t base = i * 5;
      if (corner_cuda_indices_[base + 4] < 0 || corner_cuda_sqdis_[base + 4] >= 1.0f) {
        continue;
      }
      const int idx[5] = {
        corner_cuda_indices_[base],
        corner_cuda_indices_[base + 1],
        corner_cuda_indices_[base + 2],
        corner_cuda_indices_[base + 3],
        corner_cuda_indices_[base + 4]};
      PointT coeff;
      if (!computeCornerCoeff(point_sels[i], idx, coeff)) {
        continue;
      }
      corner_ori_vec_[i] = corner_last_ds_->points[i];
      corner_coeff_vec_[i] = coeff;
      corner_flag_[i] = true;
    }
    last_corner_coeff_ms_ += elapsedMs(t_coeffs);
#else
    throw std::runtime_error("CUDA corner lookup called without CUDA support");
#endif
  }

  bool computeCornerCoeff(const PointT & point_sel, const int ind[5], PointT & coeff)
  {
    float cx = 0, cy = 0, cz = 0;
    for (int j = 0; j < 5; ++j) {
      const auto & p = corner_lookup_map_->points[ind[j]];
      cx += p.x; cy += p.y; cz += p.z;
    }
    cx /= 5; cy /= 5; cz /= 5;

    cv::Mat matA1(3, 3, CV_32F, cv::Scalar::all(0));
    cv::Mat matD1(1, 3, CV_32F, cv::Scalar::all(0));
    cv::Mat matV1(3, 3, CV_32F, cv::Scalar::all(0));
    float a11 = 0, a12 = 0, a13 = 0, a22 = 0, a23 = 0, a33 = 0;
    for (int j = 0; j < 5; ++j) {
      const auto & p = corner_lookup_map_->points[ind[j]];
      const float ax = p.x - cx;
      const float ay = p.y - cy;
      const float az = p.z - cz;
      a11 += ax * ax; a12 += ax * ay; a13 += ax * az;
      a22 += ay * ay; a23 += ay * az; a33 += az * az;
    }
    a11 /= 5; a12 /= 5; a13 /= 5; a22 /= 5; a23 /= 5; a33 /= 5;
    matA1.at<float>(0, 0) = a11; matA1.at<float>(0, 1) = a12; matA1.at<float>(0, 2) = a13;
    matA1.at<float>(1, 0) = a12; matA1.at<float>(1, 1) = a22; matA1.at<float>(1, 2) = a23;
    matA1.at<float>(2, 0) = a13; matA1.at<float>(2, 1) = a23; matA1.at<float>(2, 2) = a33;
    cv::eigen(matA1, matD1, matV1);
    if (matD1.at<float>(0, 0) <= 3 * matD1.at<float>(0, 1)) {
      return false;
    }

    const float x0 = point_sel.x, y0 = point_sel.y, z0 = point_sel.z;
    const float x1 = cx + 0.1f * matV1.at<float>(0, 0);
    const float y1 = cy + 0.1f * matV1.at<float>(0, 1);
    const float z1 = cz + 0.1f * matV1.at<float>(0, 2);
    const float x2 = cx - 0.1f * matV1.at<float>(0, 0);
    const float y2 = cy - 0.1f * matV1.at<float>(0, 1);
    const float z2 = cz - 0.1f * matV1.at<float>(0, 2);

    const float a012 = std::sqrt(
      std::pow((x0 - x1) * (y0 - y2) - (x0 - x2) * (y0 - y1), 2) +
      std::pow((x0 - x1) * (z0 - z2) - (x0 - x2) * (z0 - z1), 2) +
      std::pow((y0 - y1) * (z0 - z2) - (y0 - y2) * (z0 - z1), 2));
    const float l12 = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2) + std::pow(z1 - z2, 2));
    if (a012 < 1e-6f || l12 < 1e-6f) {
      return false;
    }

    const float la = ((y1 - y2) * ((x0 - x1) * (y0 - y2) - (x0 - x2) * (y0 - y1)) +
      (z1 - z2) * ((x0 - x1) * (z0 - z2) - (x0 - x2) * (z0 - z1))) / a012 / l12;
    const float lb = -((x1 - x2) * ((x0 - x1) * (y0 - y2) - (x0 - x2) * (y0 - y1)) -
      (z1 - z2) * ((y0 - y1) * (z0 - z2) - (y0 - y2) * (z0 - z1))) / a012 / l12;
    const float lc = -((x1 - x2) * ((x0 - x1) * (z0 - z2) - (x0 - x2) * (z0 - z1)) +
      (y1 - y2) * ((y0 - y1) * (z0 - z2) - (y0 - y2) * (z0 - z1))) / a012 / l12;
    const float ld2 = a012 / l12;
    const float s = 1 - 0.9f * std::fabs(ld2);
    if (s <= 0.1f) {
      return false;
    }

    coeff.x = s * la;
    coeff.y = s * lb;
    coeff.z = s * lc;
    coeff.intensity = s * ld2;
    return true;
  }

  void findSurfCoeffs()
  {
    if (use_cuda_lookup_) {
      findSurfCoeffsCuda();
      return;
    }
    findSurfCoeffsCpu();
  }

  void findSurfCoeffsCpu()
  {
    const auto tf = trans2Affine3f(transform_);
    for (size_t i = 0; i < surf_last_ds_->size(); ++i) {
      PointT point_sel, coeff;
      const auto t_query = SteadyClock::now();
      pointAssociateToMap(tf, surf_last_ds_->points[i], point_sel);
      last_surf_query_ms_ += elapsedMs(t_query);

      std::vector<int> ind;
      std::vector<float> sqdis;
      const auto t_search = SteadyClock::now();
      if (kdtree_surf_.nearestKSearch(point_sel, 5, ind, sqdis) < 5 || sqdis[4] >= 1.0f) {
        last_surf_search_ms_ += elapsedMs(t_search);
        continue;
      }
      last_surf_search_ms_ += elapsedMs(t_search);

      const int idx[5] = {ind[0], ind[1], ind[2], ind[3], ind[4]};
      const auto t_coeff = SteadyClock::now();
      if (!computeSurfCoeff(point_sel, surf_last_ds_->points[i], idx, coeff)) {
        last_surf_coeff_ms_ += elapsedMs(t_coeff);
        continue;
      }
      last_surf_coeff_ms_ += elapsedMs(t_coeff);

      surf_ori_vec_[i] = surf_last_ds_->points[i];
      surf_coeff_vec_[i] = coeff;
      surf_flag_[i] = true;
    }
  }

  void findSurfCoeffsCuda()
  {
#ifdef LIO_SAM_LOCALIZATION_HAS_CUDA
    const auto tf = trans2Affine3f(transform_);
    std::vector<loam_fgo_localization::CudaPoint3> source_points;
    source_points.reserve(surf_last_ds_->size());
    const auto t_query = SteadyClock::now();
    for (size_t i = 0; i < surf_last_ds_->size(); ++i) {
      const auto & p = surf_last_ds_->points[i];
      source_points.push_back({p.x, p.y, p.z});
    }
    last_surf_query_ms_ += elapsedMs(t_query);

    const auto transform_matrix = toCudaTransformMatrix(tf);
    const auto t_fused = SteadyClock::now();
    surf_cuda_.computeSurfCoefficients(
      source_points,
      transform_matrix.data(),
      surf_cuda_coefficients_,
      surf_cuda_intensities_,
      surf_cuda_valid_);
    const double fused_ms = elapsedMs(t_fused);
    last_surf_search_ms_ += fused_ms;
    last_surf_coeff_ms_ += 0.0;

    for (size_t i = 0; i < surf_last_ds_->size(); ++i) {
      if (i >= surf_cuda_valid_.size() || !surf_cuda_valid_[i]) {
        continue;
      }
      const auto & cuda_coeff = surf_cuda_coefficients_[i];
      PointT coeff;
      coeff.x = cuda_coeff.x;
      coeff.y = cuda_coeff.y;
      coeff.z = cuda_coeff.z;
      coeff.intensity = surf_cuda_intensities_[i];
      surf_ori_vec_[i] = surf_last_ds_->points[i];
      surf_coeff_vec_[i] = coeff;
      surf_flag_[i] = true;
    }
#else
    throw std::runtime_error("CUDA surf lookup called without CUDA support");
#endif
  }

  bool computeSurfCoeff(
    const PointT & point_sel,
    const PointT & source_point,
    const int ind[5],
    PointT & coeff)
  {
    Eigen::Matrix<float, 5, 3> matA0;
    Eigen::Matrix<float, 5, 1> matB0;
    matA0.setZero();
    matB0.fill(-1);
    for (int j = 0; j < 5; ++j) {
      const auto & p = surf_lookup_map_->points[ind[j]];
      matA0(j, 0) = p.x;
      matA0(j, 1) = p.y;
      matA0(j, 2) = p.z;
    }

    Eigen::Vector3f matX0 = matA0.colPivHouseholderQr().solve(matB0);
    float pa = matX0(0), pb = matX0(1), pc = matX0(2), pd = 1.0f;
    const float ps = std::sqrt(pa * pa + pb * pb + pc * pc);
    if (ps < 1e-6f) {
      return false;
    }
    pa /= ps; pb /= ps; pc /= ps; pd /= ps;

    for (int j = 0; j < 5; ++j) {
      const auto & p = surf_lookup_map_->points[ind[j]];
      if (std::fabs(pa * p.x + pb * p.y + pc * p.z + pd) > 0.2f) {
        return false;
      }
    }

    const float pd2 = pa * point_sel.x + pb * point_sel.y + pc * point_sel.z + pd;
    const float range = std::sqrt(
      source_point.x * source_point.x +
      source_point.y * source_point.y +
      source_point.z * source_point.z);
    const float s = 1 - 0.9f * std::fabs(pd2) / std::sqrt(std::max(range, 1e-3f));
    if (s <= 0.1f) {
      return false;
    }

    coeff.x = s * pa;
    coeff.y = s * pb;
    coeff.z = s * pc;
    coeff.intensity = s * pd2;
    return true;
  }

  void combineCoeffs()
  {
    for (size_t i = 0; i < corner_flag_.size(); ++i) {
      if (corner_flag_[i]) {
        laser_ori_->push_back(corner_ori_vec_[i]);
        coeff_sel_->push_back(corner_coeff_vec_[i]);
      }
    }
    for (size_t i = 0; i < surf_flag_.size(); ++i) {
      if (surf_flag_[i]) {
        laser_ori_->push_back(surf_ori_vec_[i]);
        coeff_sel_->push_back(surf_coeff_vec_[i]);
      }
    }
    std::fill(corner_flag_.begin(), corner_flag_.end(), false);
    std::fill(surf_flag_.begin(), surf_flag_.end(), false);
  }

  LmStepResult LMOptimization(int iter_count)
  {
    const float srx = std::sin(transform_[1]);
    const float crx = std::cos(transform_[1]);
    const float sry = std::sin(transform_[2]);
    const float cry = std::cos(transform_[2]);
    const float srz = std::sin(transform_[0]);
    const float crz = std::cos(transform_[0]);

    const int n = static_cast<int>(laser_ori_->size());
    cv::Mat matA(n, 6, CV_32F, cv::Scalar::all(0));
    cv::Mat matB(n, 1, CV_32F, cv::Scalar::all(0));
    for (int i = 0; i < n; ++i) {
      PointT point_ori;
      point_ori.x = laser_ori_->points[i].y;
      point_ori.y = laser_ori_->points[i].z;
      point_ori.z = laser_ori_->points[i].x;

      PointT coeff;
      coeff.x = coeff_sel_->points[i].y;
      coeff.y = coeff_sel_->points[i].z;
      coeff.z = coeff_sel_->points[i].x;
      coeff.intensity = coeff_sel_->points[i].intensity;

      const float arx =
        (crx * sry * srz * point_ori.x + crx * crz * sry * point_ori.y - srx * sry * point_ori.z) *
        coeff.x +
        (-srx * srz * point_ori.x - crz * srx * point_ori.y - crx * point_ori.z) * coeff.y +
        (crx * cry * srz * point_ori.x + crx * cry * crz * point_ori.y - cry * srx * point_ori.z) *
        coeff.z;

      const float ary = ((cry * srx * srz - crz * sry) * point_ori.x +
        (sry * srz + cry * crz * srx) * point_ori.y + crx * cry * point_ori.z) * coeff.x +
        ((-cry * crz - srx * sry * srz) * point_ori.x +
        (cry * srz - crz * srx * sry) * point_ori.y - crx * sry * point_ori.z) * coeff.z;

      const float arz = ((crz * srx * sry - cry * srz) * point_ori.x +
        (-cry * crz - srx * sry * srz) * point_ori.y) * coeff.x +
        (crx * crz * point_ori.x - crx * srz * point_ori.y) * coeff.y +
        ((sry * srz + cry * crz * srx) * point_ori.x +
        (crz * sry - cry * srx * srz) * point_ori.y) * coeff.z;

      matA.at<float>(i, 0) = arz;
      matA.at<float>(i, 1) = arx;
      matA.at<float>(i, 2) = ary;
      matA.at<float>(i, 3) = coeff.z;
      matA.at<float>(i, 4) = coeff.x;
      matA.at<float>(i, 5) = coeff.y;
      matB.at<float>(i, 0) = -coeff.intensity;
    }

    cv::Mat matAt, matAtA, matAtB, matX;
    cv::transpose(matA, matAt);
    matAtA = matAt * matA;
    matAtB = matAt * matB;
    if (!cv::solve(matAtA, matAtB, matX, cv::DECOMP_QR)) {
      return LmStepResult::Invalid;
    }

    if (publish_pose_covariance_) {
      // 마지막 선형화의 정규방정식/잔차를 보관 (수락 시 publishResult 에서 공분산 산출).
      matAtA.copyTo(last_at_a_);
      last_residual_sq_sum_ = 0.0;
      for (int i = 0; i < n; ++i) {
        const double r = matB.at<float>(i, 0);
        last_residual_sq_sum_ += r * r;
      }
      last_residual_count_ = n;
      have_last_at_a_ = true;
    }

    if (iter_count == 0) {
      cv::Mat matE(1, 6, CV_32F, cv::Scalar::all(0));
      cv::Mat matV(6, 6, CV_32F, cv::Scalar::all(0));
      cv::Mat matV2(6, 6, CV_32F, cv::Scalar::all(0));
      cv::eigen(matAtA, matE, matV);
      matV.copyTo(matV2);
      is_degenerate_ = false;
      const float eigen_threshold[6] = {100, 100, 100, 100, 100, 100};
      for (int i = 5; i >= 0; --i) {
        if (matE.at<float>(0, i) < eigen_threshold[i]) {
          for (int j = 0; j < 6; ++j) {
            matV2.at<float>(i, j) = 0;
          }
          is_degenerate_ = true;
        } else {
          break;
        }
      }
      matP_ = matV.inv() * matV2;
    }

    if (is_degenerate_) {
      cv::Mat matX2;
      matX.copyTo(matX2);
      matX = matP_ * matX2;
    }

    for (int i = 0; i < 6; ++i) {
      if (!std::isfinite(matX.at<float>(i, 0))) {
        return LmStepResult::Invalid;
      }
      transform_[i] += matX.at<float>(i, 0);
    }

    const float deltaR = std::sqrt(
      std::pow(matX.at<float>(0, 0) * 180.0f / static_cast<float>(M_PI), 2) +
      std::pow(matX.at<float>(1, 0) * 180.0f / static_cast<float>(M_PI), 2) +
      std::pow(matX.at<float>(2, 0) * 180.0f / static_cast<float>(M_PI), 2));
    const float deltaT = std::sqrt(
      std::pow(matX.at<float>(3, 0) * 100, 2) +
      std::pow(matX.at<float>(4, 0) * 100, 2) +
      std::pow(matX.at<float>(5, 0) * 100, 2));
    return deltaR < 0.05f && deltaT < 0.05f ?
           LmStepResult::Converged : LmStepResult::Continue;
  }

  void applyImuRPYConstraint()
  {
    // Ground vehicles should not drift heavily in roll/pitch. Keep this weak, as in LIO-SAM.
    // Current IMU values are already injected in updateInitialGuess; a stronger clamp will be added only if verified.
  }

  void updateAcceptedPose(bool from_scan_match = true)
  {
    const Eigen::Affine3f new_pose = trans2Affine3f(transform_);
    if (initialized_) {
      last_increment_ = last_pose_.inverse() * new_pose;
      have_increment_ = true;
    }
    last_pose_ = new_pose;
    std::copy(std::begin(transform_), std::end(transform_), std::begin(last_accepted_transform_));
    initialized_ = true;
    if (from_scan_match) {
      consecutive_failures_ = 0;
      clearLossTracking();
      setState(LocalizationState::Initialized, "scan matched");
    }
  }

  void restorePoseAfterRejectedCorrection(const Eigen::Affine3f & predicted_pose)
  {
    if (last_guess_from_prior_) {
      affineToTrans(predicted_pose, transform_);
      return;
    }

    std::copy(
      std::begin(last_accepted_transform_), std::end(last_accepted_transform_),
      std::begin(transform_));
    have_increment_ = false;
  }

  void reanchorPriorToAcceptedPose()
  {
    if (!last_guess_from_prior_) {
      return;
    }
    // transform_ 은 "스캔 시각"의 자세 -> 같은 시각의 보간 prior(guess 에 실제
    // 사용한 값)와 짝지어야 한다. latest_prior_ 를 쓰면 백로그 편향이 주입된다.
    map_to_prior_ =
      trans2Affine3f(transform_) * trans2Affine3f(last_used_prior_).inverse();
    have_map_to_prior_ = true;
  }

  void clearLossTracking()
  {
    loss_active_ = false;
    relocalizing_ = false;
    have_loss_map_to_prior_ = false;
    have_loss_last_prior_ = false;
    loss_prior_tracking_valid_ = false;
    loss_prior_distance_m_ = 0.0;
  }

  void recordFailure(const char * reason, double stamp_sec)
  {
    if (max_consecutive_failures_ <= 0) {
      return;
    }
    if (consecutive_failures_ == 0) {
      loss_active_ = true;
      loss_started_sec_ = stamp_sec;
      loss_origin_pose_ = trans2Affine3f(last_accepted_transform_);
      loss_prior_tracking_valid_ = have_prior_ &&
        std::abs(stamp_sec - latest_prior_stamp_.seconds()) <= prior_timeout_sec_;
      have_loss_last_prior_ = loss_prior_tracking_valid_;
      loss_prior_distance_m_ = 0.0;
      if (loss_prior_tracking_valid_) {
        std::copy(
          std::begin(latest_prior_), std::end(latest_prior_), std::begin(loss_last_prior_));
        loss_last_prior_stamp_ = latest_prior_stamp_;
      }
      if (have_map_to_prior_) {
        loss_map_to_prior_ = map_to_prior_;
        have_loss_map_to_prior_ = true;
      } else if (have_prior_) {
        loss_map_to_prior_ = loss_origin_pose_ * trans2Affine3f(latest_prior_).inverse();
        have_loss_map_to_prior_ = true;
      }
    }
    ++consecutive_failures_;
    if (consecutive_failures_ >= max_consecutive_failures_ &&
      state_ != LocalizationState::MayLost && state_ != LocalizationState::Lost)
    {
      setState(LocalizationState::MayLost, reason);
    } else {
      publishState();
    }
  }

  void setState(LocalizationState next, const char * reason)
  {
    if (state_ != next) {
      RCLCPP_INFO(
        get_logger(), "localization state: %s -> %s (%s)",
        stateName(state_), stateName(next), reason);
      state_ = next;
    }
    publishState();
  }

  void publishState()
  {
    if (!pub_state_) {
      return;
    }
    std_msgs::msg::String msg;
    msg.data = stateName(state_);
    pub_state_->publish(msg);
  }

  void publishCorrectionStatus(const char * status)
  {
    std_msgs::msg::String msg;
    msg.data = status;
    pub_correction_status_->publish(msg);
  }

  bool currentMapToBase(tf2::Transform & map_to_base)
  {
    map_to_base = transformFromTrans(transform_);
    if (base_frame_ == lidar_frame_) {
      return true;
    }
    tf2::Transform base_to_lidar;
    if (!lookupBaseToLidar(base_to_lidar)) {
      return false;
    }
    map_to_base *= base_to_lidar.inverse();
    return true;
  }

  // 수락된 정합의 6x6 pose 공분산: sigma^2 * (AtA)^-1.
  //   상태 순서 transform_=[roll,pitch,yaw,x,y,z] -> msg 순서 [x,y,z,rotX,rotY,rotZ].
  //   퇴화 방향은 SVD 역행렬에서 분산이 커지는 것으로 자연히 표현됨 (상한 클램프).
  bool computePoseCovariance(std::array<double, 36> & out) const
  {
    if (!have_last_at_a_ || last_residual_count_ <= 6) {
      return false;
    }
    cv::Mat inv;
    cv::invert(last_at_a_, inv, cv::DECOMP_SVD);
    const double sigma2 =
      last_residual_sq_sum_ / static_cast<double>(last_residual_count_ - 6);
    // transform_ 인덱스 -> msg 인덱스 매핑: msg[x,y,z,rX,rY,rZ] = s[3,4,5,0,1,2]
    constexpr int kMap[6] = {3, 4, 5, 0, 1, 2};
    constexpr double kVarMax = 1.0e4;
    out.fill(0.0);
    for (int r = 0; r < 6; ++r) {
      for (int c = 0; c < 6; ++c) {
        const double v =
          sigma2 * static_cast<double>(inv.at<float>(kMap[r], kMap[c]));
        out[r * 6 + c] = std::isfinite(v) ? std::clamp(v, -kVarMax, kVarMax) : kVarMax;
      }
    }
    return true;
  }

  void publishResult(const std_msgs::msg::Header & header, bool correction_accepted)
  {
    nav_msgs::msg::Odometry odom;
    odom.header.stamp = header.stamp;
    odom.header.frame_id = map_frame_;
    odom.child_frame_id = lidar_frame_;
    odom.pose.pose.position.x = transform_[3];
    odom.pose.pose.position.y = transform_[4];
    odom.pose.pose.position.z = transform_[5];
    odom.pose.pose.orientation = quatFromTrans(transform_);
    // 공분산: 수락된 정합에만 기록. 미기록(전부 0) = 정합 아님(odom 예측 발행) 표식.
    std::array<double, 36> pose_cov;
    const bool have_cov = publish_pose_covariance_ && correction_accepted &&
      computePoseCovariance(pose_cov);
    if (have_cov) {
      for (size_t i = 0; i < 36; ++i) {
        odom.pose.covariance[i] = pose_cov[i];
      }
    } else {
      odom.pose.covariance[0] = is_degenerate_ ? 1.0 : 0.0;
    }
    pub_odom_->publish(odom);

    tf2::Transform map_to_base;
    const bool have_map_to_base = currentMapToBase(map_to_base);
    if (have_map_to_base) {
      nav_msgs::msg::Odometry global_pose;
      global_pose.header.stamp = header.stamp;
      global_pose.header.frame_id = map_frame_;
      global_pose.child_frame_id = base_frame_;
      global_pose.pose.pose.position.x = map_to_base.getOrigin().x();
      global_pose.pose.pose.position.y = map_to_base.getOrigin().y();
      global_pose.pose.pose.position.z = map_to_base.getOrigin().z();
      global_pose.pose.pose.orientation.x = map_to_base.getRotation().x();
      global_pose.pose.pose.orientation.y = map_to_base.getRotation().y();
      global_pose.pose.pose.orientation.z = map_to_base.getRotation().z();
      global_pose.pose.pose.orientation.w = map_to_base.getRotation().w();
      // base pose 공분산은 lidar pose 공분산을 그대로 사용 (base<-lidar 회전 무시 근사;
      // 지상 로봇 + 근접 장착 기준 xy/yaw 성분 차이는 미미).
      global_pose.pose.covariance = odom.pose.covariance;
      pub_global_pose_->publish(global_pose);
    }

    geometry_msgs::msg::PoseStamped pose;
    pose.header = odom.header;
    pose.pose = odom.pose.pose;
    path_.header = odom.header;
    path_.poses.push_back(pose);
    pub_path_->publish(path_);

    if (publish_registered_cloud_) {
      pcl::PointCloud<PointT>::Ptr registered(new pcl::PointCloud<PointT>);
      registered->reserve(corner_last_->size() + surf_last_->size());
      pcl::PointCloud<PointT> combined;
      combined += *corner_last_;
      combined += *surf_last_;
      const auto tf = trans2Affine3f(transform_);
      pcl::transformPointCloud(combined, *registered, tf.matrix());
      sensor_msgs::msg::PointCloud2 cloud_msg;
      pcl::toROSMsg(*registered, cloud_msg);
      cloud_msg.header.stamp = header.stamp;
      cloud_msg.header.frame_id = map_frame_;
      pub_registered_->publish(cloud_msg);
    }

    if (have_map_to_base) {
      publishMapToOdom(header, map_to_base);
    }

    if (publish_tf_) {
      geometry_msgs::msg::TransformStamped tf_msg;
      tf_msg.header.stamp = header.stamp;
      tf_msg.header.frame_id = map_frame_;
      tf_msg.child_frame_id = lidar_frame_;
      tf_msg.transform.translation.x = transform_[3];
      tf_msg.transform.translation.y = transform_[4];
      tf_msg.transform.translation.z = transform_[5];
      tf_msg.transform.rotation = odom.pose.pose.orientation;
      tf_broadcaster_->sendTransform(tf_msg);
    }

    // LOG-CLEANUP(2026-08-03): 반복 로그 주석 (필요시 복원)
    /* RCLCPP_INFO_THROTTLE(
      get_logger(), *get_clock(), 1000,
      "localization output source=%s pose=(%.2f %.2f %.2f), coeff=%zu",
      correction_accepted ? "fixed_map_correction" : "map_aligned_lio_prediction",
      transform_[3], transform_[4], transform_[5], laser_ori_->size()); */
  }

  void publishMapToOdom(
    const std_msgs::msg::Header & header,
    const tf2::Transform & map_to_base)
  {
    try {
      const auto odom_to_base_msg =
        tf_buffer_->lookupTransform(odom_frame_, base_frame_, tf2::TimePointZero);
      const tf2::Transform odom_to_base = transformFromStamped(odom_to_base_msg);
      const tf2::Transform map_to_odom = map_to_base * odom_to_base.inverse();

      geometry_msgs::msg::TransformStamped tf_msg;
      tf_msg.header.stamp = header.stamp;
      tf_msg.header.frame_id = map_frame_;
      tf_msg.child_frame_id = odom_frame_;
      tf_msg.transform = toTransformMsg(map_to_odom);
      pub_map_to_odom_candidate_->publish(tf_msg);
      if (publish_map_to_odom_) {
        tf_broadcaster_->sendTransform(tf_msg);
      }
    } catch (const tf2::TransformException & e) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "cannot publish %s->%s: missing %s->%s TF: %s",
        map_frame_.c_str(), odom_frame_.c_str(),
        odom_frame_.c_str(), base_frame_.c_str(), e.what());
    }
  }

  std::string corner_map_path_;
  std::string surf_map_path_;
  std::string corner_map_path_topic_;
  std::string surf_map_path_topic_;
  std::string input_topic_;
  std::string prior_odom_topic_;
  std::string initial_pose_topic_;
  std::string global_pose_topic_;
  std::string map_to_odom_candidate_topic_;
  std::string processing_enable_topic_;
  std::string map_frame_;
  std::string odom_frame_;
  std::string base_frame_;
  std::string lidar_frame_;
  double map_corner_leaf_;
  double map_surf_leaf_;
  double scan_corner_leaf_;
  double scan_surf_leaf_;
  int edge_min_valid_;
  int surf_min_valid_;
  int max_iterations_;
  double max_step_xy_;
  std::string lookup_backend_;
  bool profile_timings_;
  loam_fgo_localization::CallbackTiming cb_timing_;   // 2s 주기 콜백 ms 요약 로그
  bool use_local_map_window_;
  double local_map_radius_;
  double local_map_rebuild_dist_;
  int min_local_corner_points_;
  int min_local_surf_points_;
  bool publish_tf_;
  bool publish_pose_covariance_ = true;
  cv::Mat last_at_a_;                 // 마지막 LM 선형화의 AtA (6x6)
  double last_residual_sq_sum_ = 0.0;
  int last_residual_count_ = 0;
  bool have_last_at_a_ = false;
  bool publish_map_to_odom_;
  bool publish_map_features_;
  bool publish_registered_cloud_;
  bool use_prior_odom_;
  bool prior_pose_is_base_frame_;
  bool initial_pose_is_base_frame_;
  bool require_initial_pose_;
  bool require_initial_pose_without_prior_;
  int max_consecutive_failures_;
  bool use_constant_velocity_guess_;
  double imu_rpy_weight_;
  double prior_timeout_sec_;
  double map_native_to_map_x_;
  double map_native_to_map_y_;
  double map_native_to_map_z_;
  double map_native_to_map_yaw_deg_;
  bool processing_enabled_;
  bool global_init_enabled_;
  double global_init_retry_interval_sec_;
  int global_init_min_corner_points_;
  int global_init_required_votes_;
  int global_init_max_votes_;
  double global_init_vote_xy_tolerance_;
  double global_init_vote_yaw_tolerance_;
  double global_init_vote_timeout_sec_;
  double global_init_z_center_;
  bool global_init_use_prior_z_;
  double global_init_z_half_range_;
  double global_init_z_step_;
  double global_init_z_score_sigma_;
  double global_init_z_score_cutoff_;
  bool relocalization_enabled_;
  double relocalization_start_after_sec_;
  double relocalization_retry_interval_sec_;
  double relocalization_xy_initial_radius_m_;
  double relocalization_max_vehicle_speed_mps_;
  double relocalization_xy_error_per_odom_meter_;
  double relocalization_odom_jump_tolerance_m_;
  double relocalization_max_odom_yaw_rate_rad_per_sec_;
  double relocalization_odom_yaw_jump_tolerance_rad_;
  double relocalization_xy_stop_radius_m_;
  double relocalization_yaw_initial_half_range_rad_;
  double relocalization_yaw_growth_rad_per_sec_;
  double relocalization_yaw_max_half_range_rad_;
  std::string global_init_position_prior_topic_;
  double global_init_position_prior_max_age_sec_{1.0};
  double global_init_position_prior_sigma_scale_{3.0};
  double global_init_position_prior_min_radius_{10.0};
  double global_init_position_prior_max_radius_{30.0};
  //: 이 시간이 넘으면 사전정보를 아예 못 쓴다 (그 아래는 반경을 키워서 쓴다).
  double global_init_position_prior_stale_limit_sec_{10.0};
  //: 사전정보 1 초당 넓힐 반경 (m/s). 차량 최고속 + 여유.
  double global_init_position_prior_speed_margin_{3.0};
  double global_init_max_match_seconds_{1.0};
  bool use_cuda_lookup_ = false;
  double last_optimize_ms_ = 0.0;
  double last_corner_ms_ = 0.0;
  double last_surf_ms_ = 0.0;
  double last_combine_ms_ = 0.0;
  double last_lm_ms_ = 0.0;
  double last_corner_query_ms_ = 0.0;
  double last_corner_search_ms_ = 0.0;
  double last_corner_coeff_ms_ = 0.0;
  double last_surf_query_ms_ = 0.0;
  double last_surf_search_ms_ = 0.0;
  double last_surf_coeff_ms_ = 0.0;
  int last_opt_iters_ = 0;
  size_t last_coeff_count_ = 0;

  float transform_[6];
  float latest_prior_[6] = {0, 0, 0, 0, 0, 0};
  //: (stamp, lidar 프레임 prior). 스캔 스탬프 보간용 — latest 와 짝지으면
  //: 파이프라인 백로그 시 시간축 불일치로 LM 이 발산한다 (2026-08-25).
  std::deque<std::pair<double, std::array<float, 6>>> prior_buffer_;
  float last_used_prior_[6] = {0, 0, 0, 0, 0, 0};  // 이번 guess 에 실제 쓴 보간값
  float last_accepted_transform_[6] = {0, 0, 0, 0, 0, 0};
  bool have_prior_ = false;
  bool last_guess_from_prior_ = false;
  bool received_initial_pose_ = false;
  rclcpp::Time latest_prior_stamp_{0, 0, RCL_ROS_TIME};
  bool initialized_ = false;
  LocalizationState state_ = LocalizationState::NonInitialized;
  int consecutive_failures_ = 0;
  bool have_increment_ = false;
  bool is_degenerate_ = false;
  Eigen::Affine3f last_pose_ = Eigen::Affine3f::Identity();
  Eigen::Affine3f last_increment_ = Eigen::Affine3f::Identity();
  Eigen::Affine3f last_imu_rot_ = Eigen::Affine3f::Identity();
  Eigen::Affine3f map_to_prior_ = Eigen::Affine3f::Identity();
  Eigen::Affine3f pending_map_to_lidar_ = Eigen::Affine3f::Identity();
  bool have_map_to_prior_ = false;
  bool have_pending_global_pose_ = false;
  bool global_seed_pending_ = false;
  bool global_seed_relocalization_ = false;
  bool loss_active_ = false;
  bool relocalizing_ = false;
  double loss_started_sec_ = 0.0;
  Eigen::Affine3f loss_origin_pose_ = Eigen::Affine3f::Identity();
  Eigen::Affine3f loss_map_to_prior_ = Eigen::Affine3f::Identity();
  bool have_loss_map_to_prior_ = false;
  float loss_last_prior_[6] = {0, 0, 0, 0, 0, 0};
  rclcpp::Time loss_last_prior_stamp_{0, 0, RCL_ROS_TIME};
  bool have_loss_last_prior_ = false;
  bool loss_prior_tracking_valid_ = false;
  double loss_prior_distance_m_ = 0.0;
  std::vector<GlobalInitVote> global_init_votes_;
  double last_global_init_attempt_sec_ = -std::numeric_limits<double>::infinity();
  double global_init_position_prior_x_{0.0};
  double global_init_position_prior_y_{0.0};
  double global_init_position_prior_sigma_{0.0};
  rclcpp::Time global_init_position_prior_stamp_{0, 0, RCL_ROS_TIME};
  bool have_global_init_position_prior_{false};
  cv::Mat matP_;

  pcl::PointCloud<PointT>::Ptr corner_map_;
  pcl::PointCloud<PointT>::Ptr surf_map_;
  pcl::PointCloud<PointT>::Ptr corner_map_ds_;
  pcl::PointCloud<PointT>::Ptr surf_map_ds_;
  pcl::PointCloud<PointT>::Ptr corner_map_local_;
  pcl::PointCloud<PointT>::Ptr surf_map_local_;
  pcl::PointCloud<PointT>::Ptr corner_lookup_map_;
  pcl::PointCloud<PointT>::Ptr surf_lookup_map_;
  pcl::PointCloud<PointT>::Ptr corner_last_;
  pcl::PointCloud<PointT>::Ptr surf_last_;
  pcl::PointCloud<PointT>::Ptr corner_last_ds_;
  pcl::PointCloud<PointT>::Ptr surf_last_ds_;
  pcl::PointCloud<PointT>::Ptr laser_ori_;
  pcl::PointCloud<PointT>::Ptr coeff_sel_;
  pcl::KdTreeFLANN<PointT> kdtree_corner_;
  pcl::KdTreeFLANN<PointT> kdtree_surf_;
  pcl::KdTreeFLANN<PointT> kdtree_corner_global_;
  std::unique_ptr<loam_fgo_localization::Se2BranchAndBoundMatcher> global_init_matcher_;
#ifdef LIO_SAM_LOCALIZATION_HAS_CUDA
  loam_fgo_localization::CudaKnnIndex corner_cuda_;
  loam_fgo_localization::CudaKnnIndex surf_cuda_;
  std::vector<int> corner_cuda_indices_;
  std::vector<int> surf_cuda_indices_;
  std::vector<float> corner_cuda_sqdis_;
  std::vector<float> surf_cuda_sqdis_;
  std::vector<loam_fgo_localization::CudaPoint3> surf_cuda_coefficients_;
  std::vector<float> surf_cuda_intensities_;
  std::vector<unsigned char> surf_cuda_valid_;
#endif
  float local_map_center_[3] = {0.0f, 0.0f, 0.0f};
  bool local_map_ready_ = false;
  std::vector<PointT> corner_ori_vec_;
  std::vector<PointT> corner_coeff_vec_;
  std::vector<char> corner_flag_;
  std::vector<PointT> surf_ori_vec_;
  std::vector<PointT> surf_coeff_vec_;
  std::vector<char> surf_flag_;

  rclcpp::Subscription<lio_sam::msg::CloudInfo>::SharedPtr sub_cloud_info_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_prior_odom_;
  rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr
    sub_global_init_position_prior_;
  rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr sub_initial_pose_;
  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr sub_processing_enable_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_corner_path_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_surf_path_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pub_odom_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pub_global_pose_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_path_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_registered_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_map_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_state_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_correction_status_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_cycle_time_;
  rclcpp::Publisher<geometry_msgs::msg::TransformStamped>::SharedPtr
    pub_map_to_odom_candidate_;
  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  rclcpp::TimerBase::SharedPtr map_timer_;
  nav_msgs::msg::Path path_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  try {
    rclcpp::spin(std::make_shared<LioFeatureMapLocalizer>());
  } catch (const std::exception & e) {
    RCLCPP_FATAL(rclcpp::get_logger("lio_feature_map_localizer"), "%s", e.what());
    rclcpp::shutdown();
    return 1;   // launch 가 "finished cleanly" 로 오인하지 않도록 비정상 코드 반환
  }
  rclcpp::shutdown();
  return 0;
}

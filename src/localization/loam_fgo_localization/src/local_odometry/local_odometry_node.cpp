#include <chrono>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <std_msgs/msg/float64.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "loam_fgo_localization/callback_timing.hpp"
#include "loam_fgo_localization/local_odometry/odometry_estimator.hpp"
#include "loam_fgo_localization/local_odometry/local_odometry.hpp"
#include "loam_fgo_localization/local_odometry/eskf_odometry.hpp"

namespace loam_fgo_localization
{

// 로컬 오도메트리 노드.
//  담당: /odom (nav_msgs/Odometry) + TF odom->base_link (REP-105 의 local 파트).
//  발행 안 함: map->odom (전역 로컬라이저 몫).
//  IMU 는 vectornav 프레임 -> base_link 로 extrinsic 회전 후 추정기에 투입.
class LocalOdometryNode : public rclcpp::Node
{
public:
  LocalOdometryNode()
  : Node("local_odometry_node")
  {
    // ---- topics / frames ----
    imu_topic_ = declare_parameter<std::string>("topics.imu", "/vectornav/imu");
    speed_topic_ = declare_parameter<std::string>("topics.speed", "/hunter/velocity");
    odom_topic_ = declare_parameter<std::string>("topics.output_odom", "/odom");
    odom_frame_ = declare_parameter<std::string>("frames.odom", "odom");
    base_frame_ = declare_parameter<std::string>("frames.base_link", "base_link");
    publish_tf_ = declare_parameter<bool>("publish_tf", true);

    // ---- estimator selection ----
    const std::string estimator = declare_parameter<std::string>("estimator", "gyro_odometry");
    const double wheel_scale = declare_parameter<double>("wheel_scale", 1.0);  // offline-calibrated const
    const double max_dt = declare_parameter<double>("max_dt", 0.5);
    const bool use_imu_orientation = declare_parameter<bool>("use_imu_orientation", false);
    if (estimator == "eskf") {
      EskfOdometry::Params p;   // header defaults (tuned) act as fallback; yaml can override
      p.wheel_scale = wheel_scale;
      p.max_dt = max_dt;
      p.gyro_noise = declare_parameter<double>("eskf.gyro_noise", p.gyro_noise);
      p.accel_noise = declare_parameter<double>("eskf.accel_noise", p.accel_noise);
      p.gyro_bias_rw = declare_parameter<double>("eskf.gyro_bias_rw", p.gyro_bias_rw);
      p.accel_bias_rw = declare_parameter<double>("eskf.accel_bias_rw", p.accel_bias_rw);
      p.wheel_speed_sigma = declare_parameter<double>("eskf.wheel_speed_sigma", p.wheel_speed_sigma);
      p.nhc_sigma = declare_parameter<double>("eskf.nhc_sigma", p.nhc_sigma);
      p.zupt_vel_sigma = declare_parameter<double>("eskf.zupt_vel_sigma", p.zupt_vel_sigma);
      p.zaru_sigma = declare_parameter<double>("eskf.zaru_sigma", p.zaru_sigma);
      p.zupt_speed_thresh = declare_parameter<double>("eskf.zupt_speed_thresh", p.zupt_speed_thresh);
      p.zupt_gyro_thresh = declare_parameter<double>("eskf.zupt_gyro_thresh", p.zupt_gyro_thresh);
      p.zupt_acc_var_thresh = declare_parameter<double>("eskf.zupt_acc_var_thresh", p.zupt_acc_var_thresh);
      p.stationary_window = declare_parameter<int>("eskf.stationary_window", p.stationary_window);
      p.planar = declare_parameter<bool>("eskf.planar", p.planar);
      p.stationary_hold = declare_parameter<bool>("eskf.stationary_hold", p.stationary_hold);
      p.zaru_enable = declare_parameter<bool>("eskf.zaru_enable", p.zaru_enable);
      odom_ = std::make_unique<EskfOdometry>(p);
    } else {
      LocalOdometry::Params p;
      p.wheel_scale = wheel_scale;
      p.max_dt = max_dt;
      p.use_imu_orientation = use_imu_orientation;
      odom_ = std::make_unique<LocalOdometry>(p);
    }
    RCLCPP_INFO(get_logger(), "estimator: %s", estimator.c_str());

    // ---- IMU extrinsic: base_link <- imu 회전 (RPY, rad) ----
    const double roll = declare_parameter<double>("imu_extrinsic.roll", 0.0);
    const double pitch = declare_parameter<double>("imu_extrinsic.pitch", 0.0);
    const double yaw = declare_parameter<double>("imu_extrinsic.yaw", 0.0);
    q_bl_imu_ = Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitZ()) *
      Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
      Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitX());
    q_bl_imu_.normalize();

    // ---- pub/sub ----
    odom_pub_ = create_publisher<nav_msgs::msg::Odometry>(odom_topic_, 20);
    // per-loop compute time [us] of the estimator update (profiling)
    proc_time_topic_ = declare_parameter<std::string>("topics.proc_time", "/scv/proc_time_us");
    proc_time_pub_ = create_publisher<std_msgs::msg::Float64>(proc_time_topic_, 20);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
    imu_sub_ = create_subscription<sensor_msgs::msg::Imu>(
      imu_topic_, rclcpp::SensorDataQoS(),
      std::bind(&LocalOdometryNode::imuCb, this, std::placeholders::_1));
    speed_sub_ = create_subscription<std_msgs::msg::Float64>(
      speed_topic_, 10,
      std::bind(&LocalOdometryNode::speedCb, this, std::placeholders::_1));

    RCLCPP_INFO(
      get_logger(),
      "loam_fgo_localization local odom: imu=%s speed=%s -> %s  (%s->%s)  scale=%.4f imu_rpy=[%.3f %.3f %.3f]",
      imu_topic_.c_str(), speed_topic_.c_str(), odom_topic_.c_str(),
      odom_frame_.c_str(), base_frame_.c_str(), wheel_scale, roll, pitch, yaw);
  }

private:
  void speedCb(const std_msgs::msg::Float64::SharedPtr msg)
  {
    odom_->setSpeed(msg->data);
  }

  void imuCb(const sensor_msgs::msg::Imu::SharedPtr msg)
  {
    const double t = rclcpp::Time(msg->header.stamp).seconds();

    // imu 프레임 측정 -> base_link 프레임으로 회전
    const Eigen::Quaterniond q_imu(
      msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);
    const Eigen::Vector3d gyro_imu(
      msg->angular_velocity.x, msg->angular_velocity.y, msg->angular_velocity.z);
    const Eigen::Vector3d acc_imu(
      msg->linear_acceleration.x, msg->linear_acceleration.y, msg->linear_acceleration.z);

    const Eigen::Quaterniond q_bl = (q_imu * q_bl_imu_.inverse()).normalized();
    const Eigen::Vector3d gyro_bl = q_bl_imu_ * gyro_imu;
    const Eigen::Vector3d acc_bl = q_bl_imu_ * acc_imu;

    const auto t0 = std::chrono::steady_clock::now();
    const bool ok = odom_->update(t, q_bl, gyro_bl, acc_bl);
    const auto t1 = std::chrono::steady_clock::now();
    std_msgs::msg::Float64 pt;
    pt.data = std::chrono::duration<double, std::micro>(t1 - t0).count();
    proc_time_pub_->publish(pt);   // estimator update compute time [us]
    cb_timing_.add(pt.data * 1e-3);
    if (cb_timing_.due()) {
      RCLCPP_INFO(get_logger(), "cb %s", cb_timing_.flush("imu(eskf)").c_str());
    }
    if (!ok) {return;}
    publish(msg->header.stamp);
  }

  void publish(const builtin_interfaces::msg::Time & stamp)
  {
    const OdomOutput & o = odom_->output();

    nav_msgs::msg::Odometry m;
    m.header.stamp = stamp;
    m.header.frame_id = odom_frame_;
    m.child_frame_id = base_frame_;
    m.pose.pose.position.x = o.position.x();
    m.pose.pose.position.y = o.position.y();
    m.pose.pose.position.z = o.position.z();
    m.pose.pose.orientation.w = o.orientation.w();
    m.pose.pose.orientation.x = o.orientation.x();
    m.pose.pose.orientation.y = o.orientation.y();
    m.pose.pose.orientation.z = o.orientation.z();
    m.twist.twist.linear.x = o.velocity_body.x();
    m.twist.twist.linear.y = o.velocity_body.y();
    m.twist.twist.linear.z = o.velocity_body.z();
    m.twist.twist.angular.z = o.yaw_rate;
    for (size_t i = 0; i < 36; ++i) {
      m.pose.covariance[i] = o.pose_cov[i];
      m.twist.covariance[i] = o.twist_cov[i];
    }
    odom_pub_->publish(m);

    if (publish_tf_) {
      geometry_msgs::msg::TransformStamped tf;
      tf.header.stamp = stamp;
      tf.header.frame_id = odom_frame_;
      tf.child_frame_id = base_frame_;
      tf.transform.translation.x = o.position.x();
      tf.transform.translation.y = o.position.y();
      tf.transform.translation.z = o.position.z();
      tf.transform.rotation = m.pose.pose.orientation;
      tf_broadcaster_->sendTransform(tf);
    }
  }

  std::string imu_topic_, speed_topic_, odom_topic_, odom_frame_, base_frame_, proc_time_topic_;
  CallbackTiming cb_timing_;   // 2s 주기 콜백 ms 요약 로그
  bool publish_tf_{true};
  Eigen::Quaterniond q_bl_imu_{1.0, 0.0, 0.0, 0.0};

  std::unique_ptr<OdometryEstimator> odom_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr speed_sub_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr proc_time_pub_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

}  // namespace loam_fgo_localization

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<loam_fgo_localization::LocalOdometryNode>());
  rclcpp::shutdown();
  return 0;
}

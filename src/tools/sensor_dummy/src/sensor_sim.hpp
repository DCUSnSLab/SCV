#ifndef SENSOR_SIM_HPP_
#define SENSOR_SIM_HPP_

#include "fault.hpp"
#include "gnss_model.hpp"
#include "lidar_model.hpp"
#include "vehicle_model.hpp"
#include "world_map.hpp"

#include <Eigen/Geometry>
#include <rclcpp/rclcpp.hpp>

#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/twist_with_covariance_stamped.hpp>
#include <hunter_msgs/msg/hunter_status.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <std_msgs/msg/float64.hpp>
#include <tf2_msgs/msg/tf_message.hpp>
#include <ublox_msgs/msg/nav_pvt.hpp>
#include <ublox_msgs/msg/rxm_rtcm.hpp>

#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace sensor_dummy
{

// One simulated vehicle on the 2D map and every sensor that depends on where it is.
class SensorSim : public rclcpp::Node
{
public:
  explicit SensorSim(const rclcpp::NodeOptions & options);

private:
  struct Covariance3
  {
    std::array<double, 9> orientation;
    std::array<double, 9> angular_velocity;
    std::array<double, 9> linear_acceleration;
  };

  template <class Msg>
  using Output = std::unique_ptr<FaultFilter<Msg>>;

  template <class Msg>
  Output<Msg> make_output(
    const std::string & name, const rclcpp::QoS & qos, const FaultSpec & spec);
  void add_timer(double rate_hz, std::function<void()> callback);

  VehicleParams read_vehicle_params();
  LidarConfig read_lidar_config();
  Eigen::Isometry3d read_mount(const std::string & name);
  void read_channel_params();
  void setup_lidar();
  void setup_imu();
  void setup_gnss();
  void setup_hunter();
  void setup_odometry();

  rcl_interfaces::msg::SetParametersResult on_parameters(
    const std::vector<rclcpp::Parameter> & parameters);
  void on_command(const geometry_msgs::msg::Twist & msg);
  void on_physics_tick();
  void on_lidar_tick();
  void on_imu_tick();
  void on_gnss_tick();
  void on_rtcm_tick();
  void on_hunter_tick();
  void on_odometry_tick();
  void on_ground_truth_tick();
  void on_tf_tick();

  ublox_msgs::msg::NavPVT make_nav_pvt(const rclcpp::Time & stamp) const;
  nav_msgs::msg::Odometry make_wheel_odometry(const rclcpp::Time & stamp) const;

  double seconds() const { return (now() - start_time_).seconds(); }

  std::string map_frame_;
  std::string odom_frame_;
  std::string base_frame_;
  std::string lidar_frame_;
  std::string imu_frame_;
  std::string imu_pose_frame_;
  std::string gnss_frame_;

  Eigen::Isometry3d lidar_mount_;
  Eigen::Isometry3d imu_mount_;
  Eigen::Isometry3d gnss_mount_;

  Pose2d odom_origin_;
  std::optional<VehicleModel> vehicle_;
  std::optional<WorldMap> world_;
  std::optional<GnssModel> gnss_;
  std::vector<LaserBeam> beams_;
  LidarConfig lidar_config_;

  double gravity_;
  Covariance3 imu_covariance_;
  std::int64_t rtcm_message_type_;
  std::int64_t rtcm_station_;
  std::int64_t fix_service_;
  std::int64_t num_sv_;
  std::int64_t h_acc_mm_;
  std::int64_t v_acc_mm_;
  std::int64_t s_acc_mm_;
  std::int64_t vehicle_state_;
  std::int64_t control_mode_;
  double battery_voltage_;
  double transmission_rpm_per_mps_;
  double wheelbase_;

  std::map<std::string, FaultSpec> faults_;
  rclcpp::Time start_time_;
  rclcpp::Time last_physics_time_;
  rclcpp::Time scan_start_time_;
  Pose2d scan_start_pose_;
  sensor_msgs::msg::PointCloud2 cloud_;

  Output<sensor_msgs::msg::PointCloud2> cloud_output_;
  Output<sensor_msgs::msg::Imu> imu_output_;
  Output<geometry_msgs::msg::PoseWithCovarianceStamped> imu_pose_output_;
  Output<sensor_msgs::msg::NavSatFix> fix_output_;
  Output<geometry_msgs::msg::TwistWithCovarianceStamped> fix_velocity_output_;
  Output<ublox_msgs::msg::NavPVT> nav_pvt_output_;
  Output<ublox_msgs::msg::NavPVT> nav_pvt_catalog_output_;
  Output<ublox_msgs::msg::RxmRTCM> rtcm_output_;
  Output<hunter_msgs::msg::HunterStatus> status_output_;
  Output<std_msgs::msg::Float64> velocity_output_;
  Output<std_msgs::msg::Float64> current_speed_output_;
  Output<std_msgs::msg::Float64> current_steer_output_;
  Output<nav_msgs::msg::Odometry> odom_output_;
  Output<nav_msgs::msg::Odometry> ground_truth_output_;
  Output<tf2_msgs::msg::TFMessage> tf_output_;

  std::vector<std::function<void(std::int64_t)>> flushes_;
  std::vector<rclcpp::TimerBase::SharedPtr> timers_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr command_sub_;
  OnSetParametersCallbackHandle::SharedPtr parameter_handle_;
};

}  // namespace sensor_dummy

#endif  // SENSOR_SIM_HPP_

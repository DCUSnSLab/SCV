#include "sensor_sim.hpp"

#include "fault_params.hpp"
#include "fault_traits.hpp"
#include "frames.hpp"
#include "imu_model.hpp"

#include <rclcpp_components/register_node_macro.hpp>

#include <sensor_msgs/msg/nav_sat_status.hpp>
#include <sensor_msgs/msg/point_field.hpp>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace sensor_dummy
{
namespace
{
using sensor_msgs::msg::PointField;

const std::vector<std::string> channels{"lidar", "imu", "gnss",        "hunter",
                                        "odom",  "tf",  "ground_truth"};

// hunter_messenger.hpp PublishOdometryToROS: the covariance of pose and twist.
constexpr std::array<double, 36> odom_covariance{
  0.001, 0.0, 0.0,       0.0, 0.0,       0.0, 0.0, 0.001, 0.0, 0.0,       0.0, 0.0,
  0.0,   0.0, 1000000.0, 0.0, 0.0,       0.0, 0.0, 0.0,   0.0, 1000000.0, 0.0, 0.0,
  0.0,   0.0, 0.0,       0.0, 1000000.0, 0.0, 0.0, 0.0,   0.0, 0.0,       0.0, 1000.0};

geometry_msgs::msg::Quaternion yaw_quaternion(double yaw)
{
  geometry_msgs::msg::Quaternion q;
  q.z = std::sin(yaw / 2.0);
  q.w = std::cos(yaw / 2.0);
  return q;
}

template <class Quaternion>
geometry_msgs::msg::Quaternion to_msg(const Quaternion & q)
{
  geometry_msgs::msg::Quaternion out;
  out.x = q.x();
  out.y = q.y();
  out.z = q.z();
  out.w = q.w();
  return out;
}

geometry_msgs::msg::Vector3 to_msg_vector(const Eigen::Vector3d & v)
{
  geometry_msgs::msg::Vector3 out;
  out.x = v.x();
  out.y = v.y();
  out.z = v.z();
  return out;
}

std::array<double, 9> diagonal_covariance(double value)
{
  return {value, 0.0, 0.0, 0.0, value, 0.0, 0.0, 0.0, value};
}

std::vector<PointField> cloud_fields()
{
  const auto field = [](const std::string & name, std::uint32_t offset, std::uint8_t type) {
    PointField f;
    f.name = name;
    f.offset = offset;
    f.datatype = type;
    f.count = 1;
    return f;
  };
  return {
    field("x", 0, PointField::FLOAT32),
    field("y", 4, PointField::FLOAT32),
    field("z", 8, PointField::FLOAT32),
    field("intensity", 12, PointField::FLOAT32),
    field("ring", ring_offset, PointField::UINT16),
    field("time", time_offset, PointField::FLOAT32)};
}
}  // namespace

SensorSim::SensorSim(const rclcpp::NodeOptions & options)
: rclcpp::Node("sensor_sim", options),
  start_time_(now()),
  last_physics_time_(start_time_),
  scan_start_time_(start_time_)
{
  map_frame_ = declare_parameter<std::string>("frames.map");
  odom_frame_ = declare_parameter<std::string>("frames.odom");
  base_frame_ = declare_parameter<std::string>("frames.base");
  for (const auto & channel : channels) {
    faults_.emplace(channel, declare_fault(*this, "fault." + channel));
  }

  const auto initial = declare_parameter<std::vector<double>>("initial_pose");
  odom_origin_ = {initial.at(0), initial.at(1), initial.at(2)};
  scan_start_pose_ = odom_origin_;
  vehicle_.emplace(read_vehicle_params(), odom_origin_);
  world_.emplace(WorldMap::load(declare_parameter<std::string>("map_file")));

  const auto origin = declare_parameter<std::vector<double>>("gnss.origin");
  gnss_.emplace(origin.at(0), origin.at(1), origin.at(2));
  read_channel_params();

  const auto outputs = declare_parameter<std::vector<std::string>>("outputs");
  const auto enabled = [&outputs](const std::string & name) {
    return std::find(outputs.begin(), outputs.end(), name) != outputs.end();
  };
  if (enabled("lidar")) {
    setup_lidar();
  }
  if (enabled("imu")) {
    setup_imu();
  }
  if (enabled("gnss")) {
    setup_gnss();
  }
  if (enabled("hunter")) {
    setup_hunter();
  }
  if (enabled("odom")) {
    setup_odometry();
  }
  if (enabled("tf")) {
    tf_output_ = make_output<tf2_msgs::msg::TFMessage>("tf", rclcpp::QoS(100), faults_.at("tf"));
    add_timer(declare_parameter<double>("tf.rate_hz"), [this]() { on_tf_tick(); });
  }
  if (declare_parameter<bool>("ground_truth.enable")) {
    ground_truth_output_ = make_output<nav_msgs::msg::Odometry>(
      "odometry_global", rclcpp::QoS(10), faults_.at("ground_truth"));
    add_timer(
      declare_parameter<double>("ground_truth.rate_hz"), [this]() { on_ground_truth_tick(); });
  }

  command_sub_ = create_subscription<geometry_msgs::msg::Twist>(
    "~/input/final_cmd", 1, [this](const geometry_msgs::msg::Twist & msg) { on_command(msg); });
  add_timer(declare_parameter<double>("physics_rate_hz"), [this]() { on_physics_tick(); });
  parameter_handle_ =
    add_on_set_parameters_callback([this](const std::vector<rclcpp::Parameter> & parameters) {
      return on_parameters(parameters);
    });
}

template <class Msg>
SensorSim::Output<Msg> SensorSim::make_output(
  const std::string & name, const rclcpp::QoS & qos, const FaultSpec & spec)
{
  auto publisher = create_publisher<Msg>("~/output/" + name, qos);
  auto filter = std::make_unique<FaultFilter<Msg>>(
    spec, [publisher](const Msg & msg) { publisher->publish(msg); });
  flushes_.push_back([raw = filter.get()](std::int64_t now_ns) { raw->flush(now_ns); });
  return filter;
}

void SensorSim::add_timer(double rate_hz, std::function<void()> callback)
{
  timers_.push_back(create_wall_timer(
    std::chrono::duration_cast<std::chrono::nanoseconds>(
      std::chrono::duration<double>(1.0 / rate_hz)),
    std::move(callback)));
}

VehicleParams SensorSim::read_vehicle_params()
{
  VehicleParams p{};
  p.model = parse_motion_model(declare_parameter<std::string>("vehicle.motion_model"));
  p.track = declare_parameter<double>("vehicle.track");
  p.wheelbase = declare_parameter<double>("vehicle.wheelbase");
  p.rear_axle_x = declare_parameter<double>("vehicle.rear_axle_x");
  p.max_steer_angle = declare_parameter<double>("vehicle.max_steer_angle");
  p.max_linear_speed = declare_parameter<double>("vehicle.max_linear_speed");
  p.cmd_delay_s = declare_parameter<double>("vehicle.cmd_delay_s");
  p.speed_tau_s = declare_parameter<double>("vehicle.speed_tau_s");
  p.steer_tau_s = declare_parameter<double>("vehicle.steer_tau_s");
  p.speed_dead_band_mps = declare_parameter<double>("vehicle.speed_dead_band_mps");
  p.steer_dead_band_rad = declare_parameter<double>("vehicle.steer_dead_band_rad");
  p.steer_bias_rad = declare_parameter<double>("vehicle.steer_bias_rad");
  wheelbase_ = p.wheelbase;
  const double wheel_radius = declare_parameter<double>("vehicle.wheel_radius");
  const double reduction = declare_parameter<double>("vehicle.transmission_reduction_rate");
  transmission_rpm_per_mps_ = reduction * 60.0 / (2.0 * M_PI * wheel_radius);
  return p;
}

LidarConfig SensorSim::read_lidar_config()
{
  LidarConfig c{};
  c.rpm = declare_parameter<double>("lidar.rpm");
  c.blocks = static_cast<int>(declare_parameter<std::int64_t>("lidar.blocks"));
  c.block_period_s = declare_parameter<double>("lidar.block_period_s");
  c.firing_step_s = declare_parameter<double>("lidar.firing_step_s");
  c.min_range = declare_parameter<double>("lidar.min_range");
  c.max_range = declare_parameter<double>("lidar.max_range");
  return c;
}

Eigen::Isometry3d SensorSim::read_mount(const std::string & name)
{
  const auto m = declare_parameter<std::vector<double>>("mount." + name);
  Eigen::Isometry3d out = Eigen::Isometry3d::Identity();
  out.translation() = Eigen::Vector3d(m.at(0), m.at(1), m.at(2));
  out.linear() = Eigen::Quaterniond(m.at(6), m.at(3), m.at(4), m.at(5)).toRotationMatrix();
  return out;
}

void SensorSim::read_channel_params()
{
  lidar_mount_ = read_mount("velodyne");
  imu_mount_ = read_mount("vectornav");
  gnss_mount_ = read_mount("gnss_antenna");
  gravity_ = declare_parameter<double>("imu.gravity");
  imu_covariance_ = {
    diagonal_covariance(declare_parameter<double>("imu.orientation_covariance")),
    diagonal_covariance(declare_parameter<double>("imu.angular_velocity_covariance")),
    diagonal_covariance(declare_parameter<double>("imu.linear_acceleration_covariance"))};
}

void SensorSim::setup_lidar()
{
  lidar_frame_ = declare_parameter<std::string>("lidar.frame_id");
  lidar_config_ = read_lidar_config();
  beams_ = load_beams(
    declare_parameter<std::string>("lidar.calibration_file"), lidar_config_.firing_step_s);

  cloud_.header.frame_id = lidar_frame_;
  cloud_.fields = cloud_fields();
  cloud_.is_bigendian = false;
  cloud_.is_dense = false;
  cloud_.point_step = point_step;
  cloud_.width = static_cast<std::uint32_t>(beams_.size());
  cloud_.height = static_cast<std::uint32_t>(lidar_config_.blocks);
  cloud_.row_step = cloud_.width * cloud_.point_step;

  cloud_output_ = make_output<sensor_msgs::msg::PointCloud2>(
    "velodyne_points", rclcpp::QoS(10), faults_.at("lidar"));
  add_timer(lidar_config_.rpm / 60.0, [this]() { on_lidar_tick(); });
}

void SensorSim::setup_imu()
{
  imu_frame_ = declare_parameter<std::string>("imu.frame_id");
  imu_pose_frame_ = declare_parameter<std::string>("imu.pose_frame_id");
  const auto & fault = faults_.at("imu");
  imu_output_ = make_output<sensor_msgs::msg::Imu>("imu", rclcpp::QoS(10), fault);
  imu_pose_output_ =
    make_output<geometry_msgs::msg::PoseWithCovarianceStamped>("pose", rclcpp::QoS(10), fault);
  add_timer(declare_parameter<double>("imu.rate_hz"), [this]() { on_imu_tick(); });
}

void SensorSim::setup_gnss()
{
  gnss_frame_ = declare_parameter<std::string>("gnss.frame_id");
  fix_service_ = declare_parameter<std::int64_t>("gnss.service");
  num_sv_ = declare_parameter<std::int64_t>("gnss.num_sv");
  h_acc_mm_ = declare_parameter<std::int64_t>("gnss.h_acc_mm");
  v_acc_mm_ = declare_parameter<std::int64_t>("gnss.v_acc_mm");
  s_acc_mm_ = declare_parameter<std::int64_t>("gnss.s_acc_mm");
  rtcm_message_type_ = declare_parameter<std::int64_t>("gnss.rtcm_message_type");
  rtcm_station_ = declare_parameter<std::int64_t>("gnss.rtcm_station");
  const auto & fault = faults_.at("gnss");
  fix_output_ = make_output<sensor_msgs::msg::NavSatFix>("fix", rclcpp::QoS(1), fault);
  fix_velocity_output_ = make_output<geometry_msgs::msg::TwistWithCovarianceStamped>(
    "fix_velocity", rclcpp::QoS(1), fault);
  nav_pvt_output_ = make_output<ublox_msgs::msg::NavPVT>("navpvt", rclcpp::QoS(1), fault);
  nav_pvt_catalog_output_ =
    make_output<ublox_msgs::msg::NavPVT>("navpvt_catalog", rclcpp::QoS(1), fault);
  rtcm_output_ = make_output<ublox_msgs::msg::RxmRTCM>("rxmrtcm", rclcpp::QoS(1), fault);
  add_timer(declare_parameter<double>("gnss.rate_hz"), [this]() { on_gnss_tick(); });
  add_timer(declare_parameter<double>("gnss.rtcm_rate_hz"), [this]() { on_rtcm_tick(); });
}

void SensorSim::setup_hunter()
{
  vehicle_state_ = declare_parameter<std::int64_t>("hunter.vehicle_state");
  control_mode_ = declare_parameter<std::int64_t>("hunter.control_mode");
  battery_voltage_ = declare_parameter<double>("hunter.battery_voltage");
  const auto & fault = faults_.at("hunter");
  status_output_ =
    make_output<hunter_msgs::msg::HunterStatus>("hunter_status", rclcpp::QoS(10), fault);
  velocity_output_ = make_output<std_msgs::msg::Float64>("velocity", rclcpp::QoS(10), fault);
  current_speed_output_ =
    make_output<std_msgs::msg::Float64>("current_speed", rclcpp::QoS(10), fault);
  current_steer_output_ =
    make_output<std_msgs::msg::Float64>("current_steer_angle", rclcpp::QoS(10), fault);
  add_timer(declare_parameter<double>("hunter.rate_hz"), [this]() { on_hunter_tick(); });
}

void SensorSim::setup_odometry()
{
  odom_output_ = make_output<nav_msgs::msg::Odometry>("odom", rclcpp::QoS(50), faults_.at("odom"));
  add_timer(declare_parameter<double>("odom.rate_hz"), [this]() { on_odometry_tick(); });
}

rcl_interfaces::msg::SetParametersResult SensorSim::on_parameters(
  const std::vector<rclcpp::Parameter> & parameters)
{
  rcl_interfaces::msg::SetParametersResult result;
  result.successful = true;
  try {
    for (const auto & parameter : parameters) {
      for (auto & [channel, spec] : faults_) {
        if (update_fault(spec, "fault." + channel, parameter)) {
          RCLCPP_INFO(
            get_logger(), "fault %s: %s", parameter.get_name().c_str(),
            parameter.value_to_string().c_str());
        }
      }
    }
  } catch (const std::invalid_argument & e) {
    result.successful = false;
    result.reason = e.what();
  }
  return result;
}

void SensorSim::on_command(const geometry_msgs::msg::Twist & msg)
{
  vehicle_->command(seconds(), msg.linear.x, msg.angular.z);
}

void SensorSim::on_physics_tick()
{
  const rclcpp::Time time = now();
  vehicle_->step((time - start_time_).seconds(), (time - last_physics_time_).seconds());
  last_physics_time_ = time;
  for (const auto & flush : flushes_) {
    flush(time.nanoseconds());
  }
}

void SensorSim::on_lidar_tick()
{
  const rclcpp::Time time = now();
  const Pose2d pose = vehicle_->base_pose();
  render_scan(lidar_config_, beams_, *world_, scan_start_pose_, pose, lidar_mount_, cloud_.data);
  // timestamp_first_packet: the stamp is the start of the scan (lidar.param.yaml).
  cloud_.header.stamp = scan_start_time_;
  scan_start_pose_ = pose;
  scan_start_time_ = time;
  cloud_output_->push(cloud_, time.nanoseconds());
}

void SensorSim::on_imu_tick()
{
  const rclcpp::Time time = now();
  const Pose2d pose = vehicle_->base_pose();
  const ImuSample sample = sample_imu(
    pose.yaw + gnss_->map_to_enu_yaw(), vehicle_->yaw_rate(), vehicle_->acceleration(),
    vehicle_->speed() * vehicle_->yaw_rate(), gravity_, Eigen::Quaterniond(imu_mount_.linear()));

  sensor_msgs::msg::Imu imu;
  imu.header.stamp = time;
  imu.header.frame_id = imu_frame_;
  imu.orientation = to_msg(sample.orientation);
  imu.angular_velocity = to_msg_vector(sample.angular_velocity);
  imu.linear_acceleration = to_msg_vector(sample.linear_acceleration);
  imu.orientation_covariance = imu_covariance_.orientation;
  imu.angular_velocity_covariance = imu_covariance_.angular_velocity;
  imu.linear_acceleration_covariance = imu_covariance_.linear_acceleration;
  imu_output_->push(imu, time.nanoseconds());

  // A VN-100 has no INS: the driver's posecef and position fields stay zero.
  geometry_msgs::msg::PoseWithCovarianceStamped imu_pose;
  imu_pose.header.stamp = time;
  imu_pose.header.frame_id = imu_pose_frame_;
  imu_pose.pose.pose.orientation = to_msg(rfu_to_ecef(sample.orientation, 0.0, 0.0));
  imu_pose_output_->push(imu_pose, time.nanoseconds());
}

ublox_msgs::msg::NavPVT SensorSim::make_nav_pvt(const rclcpp::Time & stamp) const
{
  using ublox_msgs::msg::NavPVT;
  const Pose2d pose = vehicle_->base_pose();
  const Geodetic geodetic = gnss_->to_geodetic(map_position(pose, gnss_mount_.translation()));
  const double speed = vehicle_->speed();
  const Eigen::Vector2d velocity =
    gnss_->map_to_enu({speed * std::cos(pose.yaw), speed * std::sin(pose.yaw)});
  const UtcTime utc = utc_time(stamp.nanoseconds());

  NavPVT m;
  m.i_tow = utc.tow_ms;
  m.year = utc.year;
  m.month = utc.month;
  m.day = utc.day;
  m.hour = utc.hour;
  m.min = utc.minute;
  m.sec = utc.second;
  m.nano = utc.nano;
  m.valid = NavPVT::VALID_DATE | NavPVT::VALID_TIME | NavPVT::VALID_FULLY_RESOLVED;
  m.fix_type = NavPVT::FIX_TYPE_3D;
  m.flags = NavPVT::FLAGS_GNSS_FIX_OK | NavPVT::FLAGS_DIFF_SOLN | NavPVT::CARRIER_PHASE_FIXED;
  m.flags2 = NavPVT::FLAGS2_CONFIRMED_AVAILABLE | NavPVT::FLAGS2_CONFIRMED_DATE |
             NavPVT::FLAGS2_CONFIRMED_TIME;
  m.num_sv = static_cast<std::uint8_t>(num_sv_);
  m.lat = static_cast<std::int32_t>(std::lround(geodetic.latitude * 1e7));
  m.lon = static_cast<std::int32_t>(std::lround(geodetic.longitude * 1e7));
  m.height = static_cast<std::int32_t>(std::lround(geodetic.altitude * 1e3));
  m.h_msl = m.height;
  m.h_acc = static_cast<std::uint32_t>(h_acc_mm_);
  m.v_acc = static_cast<std::uint32_t>(v_acc_mm_);
  m.vel_e = static_cast<std::int32_t>(std::lround(velocity.x() * 1e3));
  m.vel_n = static_cast<std::int32_t>(std::lround(velocity.y() * 1e3));
  m.g_speed = static_cast<std::int32_t>(std::lround(std::abs(speed) * 1e3));
  m.s_acc = static_cast<std::uint32_t>(s_acc_mm_);
  return m;
}

void SensorSim::on_gnss_tick()
{
  using sensor_msgs::msg::NavSatFix;
  using sensor_msgs::msg::NavSatStatus;
  const rclcpp::Time time = now();
  ublox_msgs::msg::NavPVT pvt = make_nav_pvt(time);

  // Same arithmetic as ublox_firmware7plus.hpp callbackNavPvt, including the 1e-7 deg resolution.
  NavSatFix fix;
  fix.header.stamp = time;
  fix.header.frame_id = gnss_frame_;
  fix.latitude = pvt.lat * 1e-7;
  fix.longitude = pvt.lon * 1e-7;
  fix.altitude = pvt.height * 1e-3;
  fix.status.status = NavSatStatus::STATUS_GBAS_FIX;
  fix.status.service = static_cast<std::uint16_t>(fix_service_);
  const double var_h = std::pow(pvt.h_acc / 1000.0, 2);
  const double var_v = std::pow(pvt.v_acc / 1000.0, 2);
  fix.position_covariance[0] = var_h;
  fix.position_covariance[4] = var_h;
  fix.position_covariance[8] = var_v;
  fix.position_covariance_type = NavSatFix::COVARIANCE_TYPE_DIAGONAL_KNOWN;

  geometry_msgs::msg::TwistWithCovarianceStamped velocity;
  velocity.header = fix.header;
  velocity.twist.twist.linear.x = pvt.vel_e * 1e-3;
  velocity.twist.twist.linear.y = pvt.vel_n * 1e-3;
  velocity.twist.twist.linear.z = -pvt.vel_d * 1e-3;
  const double cov_speed = std::pow(pvt.s_acc * 1e-3, 2);
  velocity.twist.covariance[0] = cov_speed;
  velocity.twist.covariance[7] = cov_speed;
  velocity.twist.covariance[14] = cov_speed;
  velocity.twist.covariance[21] = -1.0;

  const std::int64_t now_ns = time.nanoseconds();
  fix_output_->push(fix, now_ns);
  fix_velocity_output_->push(velocity, now_ns);
  ublox_msgs::msg::NavPVT catalog = pvt;
  nav_pvt_output_->push(pvt, now_ns);
  nav_pvt_catalog_output_->push(catalog, now_ns);
}

void SensorSim::on_rtcm_tick()
{
  ublox_msgs::msg::RxmRTCM msg;
  msg.version = 2;
  msg.ref_station = static_cast<std::uint16_t>(rtcm_station_);
  msg.msg_type = static_cast<std::uint16_t>(rtcm_message_type_);
  rtcm_output_->push(msg, now().nanoseconds());
}

void SensorSim::on_hunter_tick()
{
  const rclcpp::Time time = now();
  const std::int64_t now_ns = time.nanoseconds();
  const double speed = vehicle_->speed();

  hunter_msgs::msg::HunterStatus status;
  status.header.stamp = time;
  status.linear_velocity = speed;
  status.steering_angle = vehicle_->steering();
  status.vehicle_state = static_cast<std::uint8_t>(vehicle_state_);
  status.control_mode = static_cast<std::uint8_t>(control_mode_);
  status.battery_voltage = battery_voltage_;
  for (auto & actuator : status.actuator_states) {
    actuator.driver_voltage = static_cast<float>(battery_voltage_);
  }
  // Index 0 stays the steering motor; the real mapping needs a CAN log to confirm.
  const auto rpm = static_cast<std::int16_t>(speed * transmission_rpm_per_mps_);
  status.actuator_states[1].rpm = rpm;
  status.actuator_states[2].rpm = rpm;
  status_output_->push(status, now_ns);

  // hunter_base: velocity_extractor_node and hunter_state_parser_node (degrees).
  std_msgs::msg::Float64 value;
  value.data = speed;
  velocity_output_->push(value, now_ns);
  value.data = speed;
  current_speed_output_->push(value, now_ns);
  value.data = vehicle_->steering() * 180.0 / M_PI;
  current_steer_output_->push(value, now_ns);
}

nav_msgs::msg::Odometry SensorSim::make_wheel_odometry(const rclcpp::Time & stamp) const
{
  const Pose2d pose = relative_pose(odom_origin_, vehicle_->base_pose());

  nav_msgs::msg::Odometry odom;
  odom.header.stamp = stamp;
  odom.header.frame_id = odom_frame_;
  odom.child_frame_id = base_frame_;
  odom.pose.pose.position.x = pose.x;
  odom.pose.pose.position.y = pose.y;
  odom.pose.pose.orientation = yaw_quaternion(pose.yaw);
  odom.twist.twist.linear.x = vehicle_->speed();
  odom.twist.twist.angular.z = vehicle_->yaw_rate();
  odom.pose.covariance = odom_covariance;
  odom.twist.covariance = odom_covariance;
  return odom;
}

void SensorSim::on_odometry_tick()
{
  const rclcpp::Time time = now();
  auto odom = make_wheel_odometry(time);
  odom_output_->push(odom, time.nanoseconds());
}

void SensorSim::on_ground_truth_tick()
{
  const rclcpp::Time time = now();
  const Pose2d pose = vehicle_->base_pose();
  nav_msgs::msg::Odometry odom;
  odom.header.stamp = time;
  odom.header.frame_id = map_frame_;
  odom.child_frame_id = base_frame_;
  odom.pose.pose.position.x = pose.x;
  odom.pose.pose.position.y = pose.y;
  odom.pose.pose.orientation = yaw_quaternion(pose.yaw);
  odom.twist.twist.linear.x = vehicle_->speed();
  odom.twist.twist.angular.z = vehicle_->yaw_rate();
  ground_truth_output_->push(odom, time.nanoseconds());
}

void SensorSim::on_tf_tick()
{
  const rclcpp::Time time = now();
  const auto odom = make_wheel_odometry(time);

  geometry_msgs::msg::TransformStamped map_to_odom;
  map_to_odom.header.stamp = time;
  map_to_odom.header.frame_id = map_frame_;
  map_to_odom.child_frame_id = odom_frame_;
  map_to_odom.transform.translation.x = odom_origin_.x;
  map_to_odom.transform.translation.y = odom_origin_.y;
  map_to_odom.transform.rotation = yaw_quaternion(odom_origin_.yaw);

  geometry_msgs::msg::TransformStamped odom_to_base;
  odom_to_base.header = odom.header;
  odom_to_base.child_frame_id = base_frame_;
  odom_to_base.transform.translation.x = odom.pose.pose.position.x;
  odom_to_base.transform.translation.y = odom.pose.pose.position.y;
  odom_to_base.transform.rotation = odom.pose.pose.orientation;

  tf2_msgs::msg::TFMessage message;
  message.transforms = {map_to_odom, odom_to_base};
  tf_output_->push(message, time.nanoseconds());
}

}  // namespace sensor_dummy

RCLCPP_COMPONENTS_REGISTER_NODE(sensor_dummy::SensorSim)

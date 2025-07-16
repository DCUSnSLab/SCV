#include "tiny_localization/imugps_to_odometry.h"
#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <sstream>
#include <GeographicLib/UTMUPS.hpp>
#include <Eigen/Dense>

namespace my_odometry_package {

IMUGPSToOdometry::IMUGPSToOdometry() :
  gps_fix_received_(false),
  init_position_flag_(true),
  last_time_(0.0),
  ekf_initialized_(false),
  gps_heading_meas_(0.0),
  gps_heading_updated_(false),
  current_speed_(0.0),
  reverse_driving_(false)
{
  ros::NodeHandle private_nh("~");

  // Publishers
  current_utm_position_pub_ = nh_.advertise<geometry_msgs::Point>("/current_utm_relative_position", 10);
  odom_for_coordinate_pub_imu_ = nh_.advertise<nav_msgs::Odometry>("/odom/coordinate/imu", 50);
  odom_for_coordinate_pub_gps_ = nh_.advertise<nav_msgs::Odometry>("/odom/coordinate/gps", 50);
  odom_for_dwa_pub_ = nh_.advertise<nav_msgs::Odometry>("/odom/dwa", 50);

  // Subscribers
  gps_fix_sub_ = nh_.subscribe("/ublox_gps/fix", 10, &IMUGPSToOdometry::gpsFixCallback, this);
  navpvt_sub_ = nh_.subscribe("/ublox_gps/navpvt", 10, &IMUGPSToOdometry::navpvtCallback, this);
  imu_sub_ = nh_.subscribe("/vectornav/IMU", 50, &IMUGPSToOdometry::imuCallback, this);
  speed_sub_ = nh_.subscribe("/hunter_status", 10, &IMUGPSToOdometry::hunterStatusCallback, this);

  // EKF noise covariance 초기화
  Q_ = Eigen::Matrix3d::Zero();
  Q_(0,0) = 0.01;
  Q_(1,1) = 0.01;
  Q_(2,2) = 0.001;

  R_ = Eigen::Matrix3d::Zero();
  R_(0,0) = 0.5;
  R_(1,1) = 0.5;
  R_(2,2) = 0.1;

  ROS_INFO("IMUGPSToOdometry node (with EKF for position & heading) initialized.");
}

IMUGPSToOdometry::~IMUGPSToOdometry()
{
}

void IMUGPSToOdometry::spin()
{
  ros::spin();
}

//////////////////////
// Callback 함수들  //
//////////////////////

void IMUGPSToOdometry::gpsFixCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
  gps_fix_msg_ = *msg;
  gps_fix_received_ = true;

  double easting, northing;
  convertLatLonToUTM(msg->latitude, msg->longitude, easting, northing);

  if (init_position_flag_) {
    ROS_INFO("Initializing position with first GPS fix...");
    ros::Duration(2.0).sleep(); // 2초 대기
    init_position_.x = easting;
    init_position_.y = northing;
    init_position_.z = 0.0;
    std::ostringstream oss;
    oss << "{x: " << easting << ", y: " << northing << "}";
    ros::param::set("/init_position", oss.str());
    init_position_flag_ = false;
    ROS_INFO("Initial UTM position set.");
  }
}

void IMUGPSToOdometry::navpvtCallback(const ublox_msgs::NavPVT::ConstPtr& msg)
{
  navpvt_msg_ = *msg;
  double heading_deg = msg->heading / 1e5; // 도 단위
  double gps_heading_rad = northDegreeToEastRadians(heading_deg);
  if (current_speed_ >= 0.6) {
    gps_heading_meas_ = gps_heading_rad;
    gps_heading_updated_ = true;
  }
}

void IMUGPSToOdometry::hunterStatusCallback(const hunter_msgs::HunterStatus::ConstPtr& msg)
{
  hunter_status_msg_ = *msg;
  current_speed_ = msg->linear_velocity; // m/s 단위
  reverse_driving_ = (current_speed_ < -0.1);
}

void IMUGPSToOdometry::imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
  imu_msg_ = *msg;
  double current_time = msg->header.stamp.toSec();

  if (init_position_flag_ || !gps_fix_received_) {
    return;
  }

  if (last_time_ == 0.0) {
    last_time_ = current_time;
    if (!ekf_initialized_ && gps_heading_meas_ != 0.0) {
      // EKF 초기화: 초기 상태를 [0, 0, gps_heading_meas_]로 설정
      ekf_state_ << 0.0, 0.0, gps_heading_meas_;
      ekf_P_ = Eigen::Matrix3d::Identity();
      ekf_initialized_ = true;
      ROS_INFO("EKF initialized with GPS heading and initial position (0,0).");
    }
    return;
  }

  double dt = current_time - last_time_;
  last_time_ = current_time;
  double omega_z = msg->angular_velocity.z;
  double theta = ekf_state_(2);
  double u = current_speed_;

  // 예측 단계: 상태 전파 (위치와 heading)
  Eigen::Vector3d x_pred;
  x_pred(0) = ekf_state_(0) + u * cos(theta) * dt;
  x_pred(1) = ekf_state_(1) + u * sin(theta) * dt;
  x_pred(2) = normalizeAngle(theta + omega_z * dt);

  // 상태 전파 야코비안 F 계산
  Eigen::Matrix3d F = Eigen::Matrix3d::Identity();
  F(0,2) = -u * sin(theta) * dt;
  F(1,2) = u * cos(theta) * dt;

  // 공분산 예측
  ekf_P_ = F * ekf_P_ * F.transpose() + Q_;

  // 측정 업데이트: 속도가 0.6 이상이고 새로운 GPS 측정이 있을 경우
  if (current_speed_ >= 0.6 && gps_heading_updated_) {
    double easting, northing;
    convertLatLonToUTM(gps_fix_msg_.latitude, gps_fix_msg_.longitude, easting, northing);
    double meas_x = easting - init_position_.x;
    double meas_y = northing - init_position_.y;
    double meas_theta = gps_heading_meas_;
    Eigen::Vector3d z;
    z << meas_x, meas_y, meas_theta;

    // 관측 모델 H (항등행렬)
    Eigen::Matrix3d H = Eigen::Matrix3d::Identity();
    Eigen::Vector3d y;
    y(0) = z(0) - x_pred(0);
    y(1) = z(1) - x_pred(1);
    y(2) = angleDiff(z(2), x_pred(2));

    Eigen::Matrix3d S = H * ekf_P_ * H.transpose() + R_;
    Eigen::Matrix3d K = ekf_P_ * H.transpose() * S.inverse();

    Eigen::Vector3d x_updated = x_pred + K * y;
    x_updated(2) = normalizeAngle(x_updated(2));
    ekf_state_ = x_updated;
    ekf_P_ = (Eigen::Matrix3d::Identity() - K * H) * ekf_P_;

    gps_heading_updated_ = false;
  } else {
    ekf_state_ = x_pred;
  }

  // EKF 결과를 이용하여 오도메트리 메시지 생성 및 퍼블리시

  // (1) IMU 기준 오도메트리 메시지 (원시 IMU orientation 사용)
  geometry_msgs::Quaternion heading_imu_quaternion = northQuaternionToEastQuaternion(msg->orientation);
  nav_msgs::Odometry odom_imu;
  odom_imu.header.stamp = msg->header.stamp;
  odom_imu.header.frame_id = "odom_utm";
  {
    double easting, northing;
    convertLatLonToUTM(gps_fix_msg_.latitude, gps_fix_msg_.longitude, easting, northing);
    geometry_msgs::Point current_utm_relative_position;
    current_utm_relative_position.x = easting - init_position_.x;
    current_utm_relative_position.y = northing - init_position_.y;
    current_utm_relative_position.z = 0.0;
    odom_imu.pose.pose.position = current_utm_relative_position;
  }
  odom_imu.pose.pose.orientation = heading_imu_quaternion;
  odom_imu.twist.twist.linear.x = current_speed_;
  odom_imu.twist.twist.angular = msg->angular_velocity;
  odom_for_coordinate_pub_imu_.publish(odom_imu);

  // (2) EKF 기반 오도메트리 메시지 (EKF 추정 결과 사용)
  nav_msgs::Odometry odom_gps;
  odom_gps.header.stamp = msg->header.stamp;
  odom_gps.header.frame_id = "odom_utm";
  {
    geometry_msgs::Point ekf_position;
    ekf_position.x = ekf_state_(0);
    ekf_position.y = ekf_state_(1);
    ekf_position.z = 0.0;
    odom_gps.pose.pose.position = ekf_position;
  }
  tf::Quaternion q;
  q.setRPY(0, 0, ekf_state_(2));
  geometry_msgs::Quaternion ekf_quat;
  ekf_quat.x = q.x();
  ekf_quat.y = q.y();
  ekf_quat.z = q.z();
  ekf_quat.w = q.w();
  odom_gps.pose.pose.orientation = ekf_quat;
  odom_gps.twist.twist.linear.x = current_speed_;
  odom_gps.twist.twist.angular.z = 0.0;
  odom_for_coordinate_pub_gps_.publish(odom_gps);

  // (3) DWA용 오도메트리 메시지 (속도 정보만 사용)
  nav_msgs::Odometry odom_dwa;
  odom_dwa.header.stamp = msg->header.stamp;
  odom_dwa.twist.twist.linear.x = current_speed_;
  odom_dwa.twist.twist.angular.z = 0.0;
  odom_for_dwa_pub_.publish(odom_dwa);

  // 현재 UTM 상대 위치 퍼블리시 (참조용)
  {
    double easting, northing;
    convertLatLonToUTM(gps_fix_msg_.latitude, gps_fix_msg_.longitude, easting, northing);
    geometry_msgs::Point current_utm_relative_position;
    current_utm_relative_position.x = easting - init_position_.x;
    current_utm_relative_position.y = northing - init_position_.y;
    current_utm_relative_position.z = 0.0;
    current_utm_position_pub_.publish(current_utm_relative_position);
  }
}

/////////////////////////
// 유틸리티 함수들    //
/////////////////////////

double IMUGPSToOdometry::normalizeAngle(double angle)
{
  return atan2(sin(angle), cos(angle));
}

double IMUGPSToOdometry::angleDiff(double a, double b)
{
  double diff = a - b;
  return atan2(sin(diff), cos(diff));
}

double IMUGPSToOdometry::northDegreeToEastRadians(double degrees)
{
  double east_based_degrees = degrees - 90.0;
  return -east_based_degrees * M_PI / 180.0;
}

geometry_msgs::Quaternion IMUGPSToOdometry::northQuaternionToEastQuaternion(const geometry_msgs::Quaternion& q)
{
  tf::Quaternion q_current(q.x, q.y, q.z, q.w);
  tf::Quaternion q_rotate;
  q_rotate.setRPY(0, 0, M_PI / 2.0);
  tf::Quaternion q_new = q_rotate * q_current;
  q_new.normalize();
  geometry_msgs::Quaternion q_result;
  q_result.x = q_new.x();
  q_result.y = q_new.y();
  q_result.z = q_new.z();
  q_result.w = q_new.w();
  return q_result;
}

void IMUGPSToOdometry::convertLatLonToUTM(double lat, double lon, double &easting, double &northing)
{
  int zone;
  bool northp;
  GeographicLib::UTMUPS::Forward(lat, lon, zone, northp, easting, northing);
}

} // namespace my_odometry_package

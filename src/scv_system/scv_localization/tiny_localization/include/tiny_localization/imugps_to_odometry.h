#ifndef IMUGPS_TO_ODOMETRY_H
#define IMUGPS_TO_ODOMETRY_H

#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <ublox_msgs/NavPVT.h>
#include <hunter_msgs/HunterStatus.h>
#include <Eigen/Dense>

namespace my_odometry_package {

class IMUGPSToOdometry
{
public:
  IMUGPSToOdometry();
  ~IMUGPSToOdometry();
  void spin();

protected:
  // Callback functions
  void gpsFixCallback(const sensor_msgs::NavSatFix::ConstPtr& msg);
  void navpvtCallback(const ublox_msgs::NavPVT::ConstPtr& msg);
  void hunterStatusCallback(const hunter_msgs::HunterStatus::ConstPtr& msg);
  void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);

  // Utility functions
  double normalizeAngle(double angle);
  double angleDiff(double a, double b);
  double northDegreeToEastRadians(double degrees);
  geometry_msgs::Quaternion northQuaternionToEastQuaternion(const geometry_msgs::Quaternion& q);
  void convertLatLonToUTM(double lat, double lon, double &easting, double &northing);

  // ROS node handle, publishers and subscribers
  ros::NodeHandle nh_;
  ros::Subscriber gps_fix_sub_;
  ros::Subscriber navpvt_sub_;
  ros::Subscriber imu_sub_;
  ros::Subscriber speed_sub_;

  ros::Publisher current_utm_position_pub_;
  ros::Publisher odom_for_coordinate_pub_imu_;
  ros::Publisher odom_for_coordinate_pub_gps_;
  ros::Publisher odom_for_dwa_pub_;

  // Message storage and state variables
  sensor_msgs::NavSatFix gps_fix_msg_;
  ublox_msgs::NavPVT navpvt_msg_;
  sensor_msgs::Imu imu_msg_;
  hunter_msgs::HunterStatus hunter_status_msg_;

  geometry_msgs::Point init_position_;
  bool gps_fix_received_;
  bool init_position_flag_;

  double last_time_;

  // EKF variables
  bool ekf_initialized_;
  Eigen::Vector3d ekf_state_; // [x, y, heading]
  Eigen::Matrix3d ekf_P_;     // Covariance matrix
  Eigen::Matrix3d Q_;         // Process noise covariance
  Eigen::Matrix3d R_;         // Measurement noise covariance

  // GPS heading measurement
  double gps_heading_meas_;
  bool gps_heading_updated_;

  // Speed and driving direction
  double current_speed_;
  bool reverse_driving_;
};

} // namespace my_odometry_package

#endif // IMUGPS_TO_ODOMETRY_H

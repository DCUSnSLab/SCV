#ifndef FAULT_TRAITS_HPP_
#define FAULT_TRAITS_HPP_

#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/twist_with_covariance_stamped.hpp>
#include <hunter_msgs/msg/hunter_status.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <std_msgs/msg/float64.hpp>
#include <tf2_msgs/msg/tf_message.hpp>
#include <ublox_msgs/msg/nav_pvt.hpp>
#include <ublox_msgs/msg/rxm_rtcm.hpp>

#include <algorithm>
#include <cstring>
#include <limits>

// These overloads live in the message namespaces so that FaultFilter finds them by ADL.
namespace sensor_dummy
{
inline constexpr double kNan = std::numeric_limits<double>::quiet_NaN();

inline void poison_vector(geometry_msgs::msg::Vector3 & v)
{
  v.x = v.y = v.z = kNan;
}

inline void poison_pose(geometry_msgs::msg::Pose & p)
{
  p.position.x = p.position.y = p.position.z = kNan;
  p.orientation.x = p.orientation.y = p.orientation.z = p.orientation.w = kNan;
}
}  // namespace sensor_dummy

namespace sensor_msgs::msg
{
inline void poison(PointCloud2 & msg)
{
  const float nan = std::numeric_limits<float>::quiet_NaN();
  for (std::size_t i = 0; i + msg.point_step <= msg.data.size(); i += msg.point_step) {
    for (std::size_t offset : {0u, 4u, 8u}) {
      std::memcpy(&msg.data[i + offset], &nan, sizeof(nan));
    }
  }
}

inline void poison(Imu & msg)
{
  msg.orientation.x = msg.orientation.y = msg.orientation.z = msg.orientation.w =
    sensor_dummy::kNan;
  sensor_dummy::poison_vector(msg.angular_velocity);
  sensor_dummy::poison_vector(msg.linear_acceleration);
}

inline void poison(NavSatFix & msg)
{
  msg.latitude = msg.longitude = msg.altitude = sensor_dummy::kNan;
}

inline void poison(CameraInfo & msg)
{
  msg.k.fill(sensor_dummy::kNan);
}

// Only float images can carry NaN; zero is the invalid value of the integer encodings.
inline void poison(Image & msg)
{
  if (msg.encoding == "32FC1") {
    const float nan = std::numeric_limits<float>::quiet_NaN();
    for (std::size_t i = 0; i + sizeof(nan) <= msg.data.size(); i += sizeof(nan)) {
      std::memcpy(&msg.data[i], &nan, sizeof(nan));
    }
  } else {
    std::fill(msg.data.begin(), msg.data.end(), 0);
  }
}
}  // namespace sensor_msgs::msg

namespace geometry_msgs::msg
{
inline void poison(PoseWithCovarianceStamped & msg)
{
  sensor_dummy::poison_pose(msg.pose.pose);
}

inline void poison(TwistWithCovarianceStamped & msg)
{
  sensor_dummy::poison_vector(msg.twist.twist.linear);
  sensor_dummy::poison_vector(msg.twist.twist.angular);
}
}  // namespace geometry_msgs::msg

namespace nav_msgs::msg
{
inline void poison(Odometry & msg)
{
  sensor_dummy::poison_pose(msg.pose.pose);
  sensor_dummy::poison_vector(msg.twist.twist.linear);
  sensor_dummy::poison_vector(msg.twist.twist.angular);
}
}  // namespace nav_msgs::msg

namespace hunter_msgs::msg
{
inline void poison(HunterStatus & msg)
{
  msg.linear_velocity = msg.steering_angle = msg.battery_voltage = sensor_dummy::kNan;
}
}  // namespace hunter_msgs::msg

namespace std_msgs::msg
{
inline void poison(Float64 & msg)
{
  msg.data = sensor_dummy::kNan;
}
}  // namespace std_msgs::msg

// The u-blox messages hold integers, so the closest invalid value is a lost fix or a bad CRC.
namespace ublox_msgs::msg
{
inline void poison(NavPVT & msg)
{
  msg.fix_type = NavPVT::FIX_TYPE_NO_FIX;
  msg.flags = 0;
}

inline void poison(RxmRTCM & msg)
{
  msg.flags |= RxmRTCM::FLAGS_CRC_FAILED;
}
}  // namespace ublox_msgs::msg

namespace tf2_msgs::msg
{
inline void poison(TFMessage & msg)
{
  for (auto & t : msg.transforms) {
    t.transform.translation.x = t.transform.translation.y = t.transform.translation.z =
      sensor_dummy::kNan;
  }
}
}  // namespace tf2_msgs::msg

namespace sensor_dummy
{
template <>
inline void copy_stamp(tf2_msgs::msg::TFMessage & to, const tf2_msgs::msg::TFMessage & from)
{
  for (std::size_t i = 0; i < to.transforms.size(); ++i) {
    to.transforms[i].header.stamp = from.transforms[i].header.stamp;
  }
}
}  // namespace sensor_dummy

#endif  // FAULT_TRAITS_HPP_

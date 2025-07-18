// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavVELECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_velecef__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavVELECEF_s_acc
{
public:
  explicit Init_NavVELECEF_s_acc(::ublox_msgs::msg::NavVELECEF & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavVELECEF s_acc(::ublox_msgs::msg::NavVELECEF::_s_acc_type arg)
  {
    msg_.s_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELECEF msg_;
};

class Init_NavVELECEF_ecef_vz
{
public:
  explicit Init_NavVELECEF_ecef_vz(::ublox_msgs::msg::NavVELECEF & msg)
  : msg_(msg)
  {}
  Init_NavVELECEF_s_acc ecef_vz(::ublox_msgs::msg::NavVELECEF::_ecef_vz_type arg)
  {
    msg_.ecef_vz = std::move(arg);
    return Init_NavVELECEF_s_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELECEF msg_;
};

class Init_NavVELECEF_ecef_vy
{
public:
  explicit Init_NavVELECEF_ecef_vy(::ublox_msgs::msg::NavVELECEF & msg)
  : msg_(msg)
  {}
  Init_NavVELECEF_ecef_vz ecef_vy(::ublox_msgs::msg::NavVELECEF::_ecef_vy_type arg)
  {
    msg_.ecef_vy = std::move(arg);
    return Init_NavVELECEF_ecef_vz(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELECEF msg_;
};

class Init_NavVELECEF_ecef_vx
{
public:
  explicit Init_NavVELECEF_ecef_vx(::ublox_msgs::msg::NavVELECEF & msg)
  : msg_(msg)
  {}
  Init_NavVELECEF_ecef_vy ecef_vx(::ublox_msgs::msg::NavVELECEF::_ecef_vx_type arg)
  {
    msg_.ecef_vx = std::move(arg);
    return Init_NavVELECEF_ecef_vy(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELECEF msg_;
};

class Init_NavVELECEF_i_tow
{
public:
  Init_NavVELECEF_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavVELECEF_ecef_vx i_tow(::ublox_msgs::msg::NavVELECEF::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavVELECEF_ecef_vx(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELECEF msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavVELECEF>()
{
  return ublox_msgs::msg::builder::Init_NavVELECEF_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__BUILDER_HPP_

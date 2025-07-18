// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavVELNED.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_velned__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavVELNED_c_acc
{
public:
  explicit Init_NavVELNED_c_acc(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavVELNED c_acc(::ublox_msgs::msg::NavVELNED::_c_acc_type arg)
  {
    msg_.c_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_s_acc
{
public:
  explicit Init_NavVELNED_s_acc(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  Init_NavVELNED_c_acc s_acc(::ublox_msgs::msg::NavVELNED::_s_acc_type arg)
  {
    msg_.s_acc = std::move(arg);
    return Init_NavVELNED_c_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_heading
{
public:
  explicit Init_NavVELNED_heading(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  Init_NavVELNED_s_acc heading(::ublox_msgs::msg::NavVELNED::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_NavVELNED_s_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_g_speed
{
public:
  explicit Init_NavVELNED_g_speed(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  Init_NavVELNED_heading g_speed(::ublox_msgs::msg::NavVELNED::_g_speed_type arg)
  {
    msg_.g_speed = std::move(arg);
    return Init_NavVELNED_heading(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_speed
{
public:
  explicit Init_NavVELNED_speed(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  Init_NavVELNED_g_speed speed(::ublox_msgs::msg::NavVELNED::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_NavVELNED_g_speed(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_vel_d
{
public:
  explicit Init_NavVELNED_vel_d(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  Init_NavVELNED_speed vel_d(::ublox_msgs::msg::NavVELNED::_vel_d_type arg)
  {
    msg_.vel_d = std::move(arg);
    return Init_NavVELNED_speed(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_vel_e
{
public:
  explicit Init_NavVELNED_vel_e(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  Init_NavVELNED_vel_d vel_e(::ublox_msgs::msg::NavVELNED::_vel_e_type arg)
  {
    msg_.vel_e = std::move(arg);
    return Init_NavVELNED_vel_d(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_vel_n
{
public:
  explicit Init_NavVELNED_vel_n(::ublox_msgs::msg::NavVELNED & msg)
  : msg_(msg)
  {}
  Init_NavVELNED_vel_e vel_n(::ublox_msgs::msg::NavVELNED::_vel_n_type arg)
  {
    msg_.vel_n = std::move(arg);
    return Init_NavVELNED_vel_e(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

class Init_NavVELNED_i_tow
{
public:
  Init_NavVELNED_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavVELNED_vel_n i_tow(::ublox_msgs::msg::NavVELNED::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavVELNED_vel_n(msg_);
  }

private:
  ::ublox_msgs::msg::NavVELNED msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavVELNED>()
{
  return ublox_msgs::msg::builder::Init_NavVELNED_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavTIMEGPS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_timegps__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavTIMEGPS_t_acc
{
public:
  explicit Init_NavTIMEGPS_t_acc(::ublox_msgs::msg::NavTIMEGPS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavTIMEGPS t_acc(::ublox_msgs::msg::NavTIMEGPS::_t_acc_type arg)
  {
    msg_.t_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEGPS msg_;
};

class Init_NavTIMEGPS_valid
{
public:
  explicit Init_NavTIMEGPS_valid(::ublox_msgs::msg::NavTIMEGPS & msg)
  : msg_(msg)
  {}
  Init_NavTIMEGPS_t_acc valid(::ublox_msgs::msg::NavTIMEGPS::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_NavTIMEGPS_t_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEGPS msg_;
};

class Init_NavTIMEGPS_leap_s
{
public:
  explicit Init_NavTIMEGPS_leap_s(::ublox_msgs::msg::NavTIMEGPS & msg)
  : msg_(msg)
  {}
  Init_NavTIMEGPS_valid leap_s(::ublox_msgs::msg::NavTIMEGPS::_leap_s_type arg)
  {
    msg_.leap_s = std::move(arg);
    return Init_NavTIMEGPS_valid(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEGPS msg_;
};

class Init_NavTIMEGPS_week
{
public:
  explicit Init_NavTIMEGPS_week(::ublox_msgs::msg::NavTIMEGPS & msg)
  : msg_(msg)
  {}
  Init_NavTIMEGPS_leap_s week(::ublox_msgs::msg::NavTIMEGPS::_week_type arg)
  {
    msg_.week = std::move(arg);
    return Init_NavTIMEGPS_leap_s(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEGPS msg_;
};

class Init_NavTIMEGPS_f_tow
{
public:
  explicit Init_NavTIMEGPS_f_tow(::ublox_msgs::msg::NavTIMEGPS & msg)
  : msg_(msg)
  {}
  Init_NavTIMEGPS_week f_tow(::ublox_msgs::msg::NavTIMEGPS::_f_tow_type arg)
  {
    msg_.f_tow = std::move(arg);
    return Init_NavTIMEGPS_week(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEGPS msg_;
};

class Init_NavTIMEGPS_i_tow
{
public:
  Init_NavTIMEGPS_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavTIMEGPS_f_tow i_tow(::ublox_msgs::msg::NavTIMEGPS::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavTIMEGPS_f_tow(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEGPS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavTIMEGPS>()
{
  return ublox_msgs::msg::builder::Init_NavTIMEGPS_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__BUILDER_HPP_

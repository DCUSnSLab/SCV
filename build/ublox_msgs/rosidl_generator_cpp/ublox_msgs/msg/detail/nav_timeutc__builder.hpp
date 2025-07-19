// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavTIMEUTC.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_timeutc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavTIMEUTC_valid
{
public:
  explicit Init_NavTIMEUTC_valid(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavTIMEUTC valid(::ublox_msgs::msg::NavTIMEUTC::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_sec
{
public:
  explicit Init_NavTIMEUTC_sec(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_valid sec(::ublox_msgs::msg::NavTIMEUTC::_sec_type arg)
  {
    msg_.sec = std::move(arg);
    return Init_NavTIMEUTC_valid(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_min
{
public:
  explicit Init_NavTIMEUTC_min(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_sec min(::ublox_msgs::msg::NavTIMEUTC::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_NavTIMEUTC_sec(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_hour
{
public:
  explicit Init_NavTIMEUTC_hour(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_min hour(::ublox_msgs::msg::NavTIMEUTC::_hour_type arg)
  {
    msg_.hour = std::move(arg);
    return Init_NavTIMEUTC_min(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_day
{
public:
  explicit Init_NavTIMEUTC_day(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_hour day(::ublox_msgs::msg::NavTIMEUTC::_day_type arg)
  {
    msg_.day = std::move(arg);
    return Init_NavTIMEUTC_hour(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_month
{
public:
  explicit Init_NavTIMEUTC_month(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_day month(::ublox_msgs::msg::NavTIMEUTC::_month_type arg)
  {
    msg_.month = std::move(arg);
    return Init_NavTIMEUTC_day(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_year
{
public:
  explicit Init_NavTIMEUTC_year(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_month year(::ublox_msgs::msg::NavTIMEUTC::_year_type arg)
  {
    msg_.year = std::move(arg);
    return Init_NavTIMEUTC_month(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_nano
{
public:
  explicit Init_NavTIMEUTC_nano(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_year nano(::ublox_msgs::msg::NavTIMEUTC::_nano_type arg)
  {
    msg_.nano = std::move(arg);
    return Init_NavTIMEUTC_year(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_t_acc
{
public:
  explicit Init_NavTIMEUTC_t_acc(::ublox_msgs::msg::NavTIMEUTC & msg)
  : msg_(msg)
  {}
  Init_NavTIMEUTC_nano t_acc(::ublox_msgs::msg::NavTIMEUTC::_t_acc_type arg)
  {
    msg_.t_acc = std::move(arg);
    return Init_NavTIMEUTC_nano(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

class Init_NavTIMEUTC_i_tow
{
public:
  Init_NavTIMEUTC_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavTIMEUTC_t_acc i_tow(::ublox_msgs::msg::NavTIMEUTC::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavTIMEUTC_t_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavTIMEUTC msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavTIMEUTC>()
{
  return ublox_msgs::msg::builder::Init_NavTIMEUTC_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__BUILDER_HPP_

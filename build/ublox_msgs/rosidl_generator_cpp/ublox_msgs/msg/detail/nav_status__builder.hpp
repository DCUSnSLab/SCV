// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSTATUS_msss
{
public:
  explicit Init_NavSTATUS_msss(::ublox_msgs::msg::NavSTATUS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSTATUS msss(::ublox_msgs::msg::NavSTATUS::_msss_type arg)
  {
    msg_.msss = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSTATUS msg_;
};

class Init_NavSTATUS_ttff
{
public:
  explicit Init_NavSTATUS_ttff(::ublox_msgs::msg::NavSTATUS & msg)
  : msg_(msg)
  {}
  Init_NavSTATUS_msss ttff(::ublox_msgs::msg::NavSTATUS::_ttff_type arg)
  {
    msg_.ttff = std::move(arg);
    return Init_NavSTATUS_msss(msg_);
  }

private:
  ::ublox_msgs::msg::NavSTATUS msg_;
};

class Init_NavSTATUS_flags2
{
public:
  explicit Init_NavSTATUS_flags2(::ublox_msgs::msg::NavSTATUS & msg)
  : msg_(msg)
  {}
  Init_NavSTATUS_ttff flags2(::ublox_msgs::msg::NavSTATUS::_flags2_type arg)
  {
    msg_.flags2 = std::move(arg);
    return Init_NavSTATUS_ttff(msg_);
  }

private:
  ::ublox_msgs::msg::NavSTATUS msg_;
};

class Init_NavSTATUS_fix_stat
{
public:
  explicit Init_NavSTATUS_fix_stat(::ublox_msgs::msg::NavSTATUS & msg)
  : msg_(msg)
  {}
  Init_NavSTATUS_flags2 fix_stat(::ublox_msgs::msg::NavSTATUS::_fix_stat_type arg)
  {
    msg_.fix_stat = std::move(arg);
    return Init_NavSTATUS_flags2(msg_);
  }

private:
  ::ublox_msgs::msg::NavSTATUS msg_;
};

class Init_NavSTATUS_flags
{
public:
  explicit Init_NavSTATUS_flags(::ublox_msgs::msg::NavSTATUS & msg)
  : msg_(msg)
  {}
  Init_NavSTATUS_fix_stat flags(::ublox_msgs::msg::NavSTATUS::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_NavSTATUS_fix_stat(msg_);
  }

private:
  ::ublox_msgs::msg::NavSTATUS msg_;
};

class Init_NavSTATUS_gps_fix
{
public:
  explicit Init_NavSTATUS_gps_fix(::ublox_msgs::msg::NavSTATUS & msg)
  : msg_(msg)
  {}
  Init_NavSTATUS_flags gps_fix(::ublox_msgs::msg::NavSTATUS::_gps_fix_type arg)
  {
    msg_.gps_fix = std::move(arg);
    return Init_NavSTATUS_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavSTATUS msg_;
};

class Init_NavSTATUS_i_tow
{
public:
  Init_NavSTATUS_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSTATUS_gps_fix i_tow(::ublox_msgs::msg::NavSTATUS::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavSTATUS_gps_fix(msg_);
  }

private:
  ::ublox_msgs::msg::NavSTATUS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSTATUS>()
{
  return ublox_msgs::msg::builder::Init_NavSTATUS_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__BUILDER_HPP_

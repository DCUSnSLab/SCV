// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgNMEA6.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_nmea6__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgNMEA6_flags
{
public:
  explicit Init_CfgNMEA6_flags(::ublox_msgs::msg::CfgNMEA6 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgNMEA6 flags(::ublox_msgs::msg::CfgNMEA6::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA6 msg_;
};

class Init_CfgNMEA6_num_sv
{
public:
  explicit Init_CfgNMEA6_num_sv(::ublox_msgs::msg::CfgNMEA6 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA6_flags num_sv(::ublox_msgs::msg::CfgNMEA6::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_CfgNMEA6_flags(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA6 msg_;
};

class Init_CfgNMEA6_version
{
public:
  explicit Init_CfgNMEA6_version(::ublox_msgs::msg::CfgNMEA6 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA6_num_sv version(::ublox_msgs::msg::CfgNMEA6::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_CfgNMEA6_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA6 msg_;
};

class Init_CfgNMEA6_filter
{
public:
  Init_CfgNMEA6_filter()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgNMEA6_version filter(::ublox_msgs::msg::CfgNMEA6::_filter_type arg)
  {
    msg_.filter = std::move(arg);
    return Init_CfgNMEA6_version(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA6 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgNMEA6>()
{
  return ublox_msgs::msg::builder::Init_CfgNMEA6_filter();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__BUILDER_HPP_

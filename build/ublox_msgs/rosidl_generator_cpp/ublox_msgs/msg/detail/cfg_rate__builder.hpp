// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgRATE.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_RATE__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_RATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_rate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgRATE_time_ref
{
public:
  explicit Init_CfgRATE_time_ref(::ublox_msgs::msg::CfgRATE & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgRATE time_ref(::ublox_msgs::msg::CfgRATE::_time_ref_type arg)
  {
    msg_.time_ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgRATE msg_;
};

class Init_CfgRATE_nav_rate
{
public:
  explicit Init_CfgRATE_nav_rate(::ublox_msgs::msg::CfgRATE & msg)
  : msg_(msg)
  {}
  Init_CfgRATE_time_ref nav_rate(::ublox_msgs::msg::CfgRATE::_nav_rate_type arg)
  {
    msg_.nav_rate = std::move(arg);
    return Init_CfgRATE_time_ref(msg_);
  }

private:
  ::ublox_msgs::msg::CfgRATE msg_;
};

class Init_CfgRATE_meas_rate
{
public:
  Init_CfgRATE_meas_rate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgRATE_nav_rate meas_rate(::ublox_msgs::msg::CfgRATE::_meas_rate_type arg)
  {
    msg_.meas_rate = std::move(arg);
    return Init_CfgRATE_nav_rate(msg_);
  }

private:
  ::ublox_msgs::msg::CfgRATE msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgRATE>()
{
  return ublox_msgs::msg::builder::Init_CfgRATE_meas_rate();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_RATE__BUILDER_HPP_

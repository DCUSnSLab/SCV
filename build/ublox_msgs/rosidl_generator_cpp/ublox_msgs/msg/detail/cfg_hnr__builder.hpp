// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgHNR.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_HNR__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_HNR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_hnr__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgHNR_reserved0
{
public:
  explicit Init_CfgHNR_reserved0(::ublox_msgs::msg::CfgHNR & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgHNR reserved0(::ublox_msgs::msg::CfgHNR::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgHNR msg_;
};

class Init_CfgHNR_high_nav_rate
{
public:
  Init_CfgHNR_high_nav_rate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgHNR_reserved0 high_nav_rate(::ublox_msgs::msg::CfgHNR::_high_nav_rate_type arg)
  {
    msg_.high_nav_rate = std::move(arg);
    return Init_CfgHNR_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::CfgHNR msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgHNR>()
{
  return ublox_msgs::msg::builder::Init_CfgHNR_high_nav_rate();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_HNR__BUILDER_HPP_

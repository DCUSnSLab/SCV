// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgANT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_ANT__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_ANT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_ant__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgANT_pins
{
public:
  explicit Init_CfgANT_pins(::ublox_msgs::msg::CfgANT & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgANT pins(::ublox_msgs::msg::CfgANT::_pins_type arg)
  {
    msg_.pins = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgANT msg_;
};

class Init_CfgANT_flags
{
public:
  Init_CfgANT_flags()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgANT_pins flags(::ublox_msgs::msg::CfgANT::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_CfgANT_pins(msg_);
  }

private:
  ::ublox_msgs::msg::CfgANT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgANT>()
{
  return ublox_msgs::msg::builder::Init_CfgANT_flags();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_ANT__BUILDER_HPP_

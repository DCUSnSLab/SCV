// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgDGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_dgnss__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgDGNSS_reserved0
{
public:
  explicit Init_CfgDGNSS_reserved0(::ublox_msgs::msg::CfgDGNSS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgDGNSS reserved0(::ublox_msgs::msg::CfgDGNSS::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDGNSS msg_;
};

class Init_CfgDGNSS_dgnss_mode
{
public:
  Init_CfgDGNSS_dgnss_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgDGNSS_reserved0 dgnss_mode(::ublox_msgs::msg::CfgDGNSS::_dgnss_mode_type arg)
  {
    msg_.dgnss_mode = std::move(arg);
    return Init_CfgDGNSS_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDGNSS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgDGNSS>()
{
  return ublox_msgs::msg::builder::Init_CfgDGNSS_dgnss_mode();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__BUILDER_HPP_

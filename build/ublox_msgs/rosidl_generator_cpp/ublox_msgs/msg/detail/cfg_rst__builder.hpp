// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgRST.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_RST__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_RST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_rst__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgRST_reserved1
{
public:
  explicit Init_CfgRST_reserved1(::ublox_msgs::msg::CfgRST & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgRST reserved1(::ublox_msgs::msg::CfgRST::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgRST msg_;
};

class Init_CfgRST_reset_mode
{
public:
  explicit Init_CfgRST_reset_mode(::ublox_msgs::msg::CfgRST & msg)
  : msg_(msg)
  {}
  Init_CfgRST_reserved1 reset_mode(::ublox_msgs::msg::CfgRST::_reset_mode_type arg)
  {
    msg_.reset_mode = std::move(arg);
    return Init_CfgRST_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgRST msg_;
};

class Init_CfgRST_nav_bbr_mask
{
public:
  Init_CfgRST_nav_bbr_mask()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgRST_reset_mode nav_bbr_mask(::ublox_msgs::msg::CfgRST::_nav_bbr_mask_type arg)
  {
    msg_.nav_bbr_mask = std::move(arg);
    return Init_CfgRST_reset_mode(msg_);
  }

private:
  ::ublox_msgs::msg::CfgRST msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgRST>()
{
  return ublox_msgs::msg::builder::Init_CfgRST_nav_bbr_mask();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_RST__BUILDER_HPP_

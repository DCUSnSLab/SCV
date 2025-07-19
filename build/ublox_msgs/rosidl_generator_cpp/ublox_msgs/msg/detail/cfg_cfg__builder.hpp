// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgCFG.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_CFG__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_CFG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_cfg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgCFG_device_mask
{
public:
  explicit Init_CfgCFG_device_mask(::ublox_msgs::msg::CfgCFG & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgCFG device_mask(::ublox_msgs::msg::CfgCFG::_device_mask_type arg)
  {
    msg_.device_mask = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgCFG msg_;
};

class Init_CfgCFG_load_mask
{
public:
  explicit Init_CfgCFG_load_mask(::ublox_msgs::msg::CfgCFG & msg)
  : msg_(msg)
  {}
  Init_CfgCFG_device_mask load_mask(::ublox_msgs::msg::CfgCFG::_load_mask_type arg)
  {
    msg_.load_mask = std::move(arg);
    return Init_CfgCFG_device_mask(msg_);
  }

private:
  ::ublox_msgs::msg::CfgCFG msg_;
};

class Init_CfgCFG_save_mask
{
public:
  explicit Init_CfgCFG_save_mask(::ublox_msgs::msg::CfgCFG & msg)
  : msg_(msg)
  {}
  Init_CfgCFG_load_mask save_mask(::ublox_msgs::msg::CfgCFG::_save_mask_type arg)
  {
    msg_.save_mask = std::move(arg);
    return Init_CfgCFG_load_mask(msg_);
  }

private:
  ::ublox_msgs::msg::CfgCFG msg_;
};

class Init_CfgCFG_clear_mask
{
public:
  Init_CfgCFG_clear_mask()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgCFG_save_mask clear_mask(::ublox_msgs::msg::CfgCFG::_clear_mask_type arg)
  {
    msg_.clear_mask = std::move(arg);
    return Init_CfgCFG_save_mask(msg_);
  }

private:
  ::ublox_msgs::msg::CfgCFG msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgCFG>()
{
  return ublox_msgs::msg::builder::Init_CfgCFG_clear_mask();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_CFG__BUILDER_HPP_

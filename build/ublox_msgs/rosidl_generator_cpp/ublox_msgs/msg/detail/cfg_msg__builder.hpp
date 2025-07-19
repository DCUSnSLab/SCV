// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgMSG.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_MSG__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgMSG_rate
{
public:
  explicit Init_CfgMSG_rate(::ublox_msgs::msg::CfgMSG & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgMSG rate(::ublox_msgs::msg::CfgMSG::_rate_type arg)
  {
    msg_.rate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgMSG msg_;
};

class Init_CfgMSG_msg_id
{
public:
  explicit Init_CfgMSG_msg_id(::ublox_msgs::msg::CfgMSG & msg)
  : msg_(msg)
  {}
  Init_CfgMSG_rate msg_id(::ublox_msgs::msg::CfgMSG::_msg_id_type arg)
  {
    msg_.msg_id = std::move(arg);
    return Init_CfgMSG_rate(msg_);
  }

private:
  ::ublox_msgs::msg::CfgMSG msg_;
};

class Init_CfgMSG_msg_class
{
public:
  Init_CfgMSG_msg_class()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgMSG_msg_id msg_class(::ublox_msgs::msg::CfgMSG::_msg_class_type arg)
  {
    msg_.msg_class = std::move(arg);
    return Init_CfgMSG_msg_id(msg_);
  }

private:
  ::ublox_msgs::msg::CfgMSG msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgMSG>()
{
  return ublox_msgs::msg::builder::Init_CfgMSG_msg_class();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_MSG__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgVALGET.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_valget__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgVALGET_keys
{
public:
  explicit Init_CfgVALGET_keys(::ublox_msgs::msg::CfgVALGET & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgVALGET keys(::ublox_msgs::msg::CfgVALGET::_keys_type arg)
  {
    msg_.keys = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALGET msg_;
};

class Init_CfgVALGET_position
{
public:
  explicit Init_CfgVALGET_position(::ublox_msgs::msg::CfgVALGET & msg)
  : msg_(msg)
  {}
  Init_CfgVALGET_keys position(::ublox_msgs::msg::CfgVALGET::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_CfgVALGET_keys(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALGET msg_;
};

class Init_CfgVALGET_layers
{
public:
  explicit Init_CfgVALGET_layers(::ublox_msgs::msg::CfgVALGET & msg)
  : msg_(msg)
  {}
  Init_CfgVALGET_position layers(::ublox_msgs::msg::CfgVALGET::_layers_type arg)
  {
    msg_.layers = std::move(arg);
    return Init_CfgVALGET_position(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALGET msg_;
};

class Init_CfgVALGET_version
{
public:
  Init_CfgVALGET_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgVALGET_layers version(::ublox_msgs::msg::CfgVALGET::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_CfgVALGET_layers(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALGET msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgVALGET>()
{
  return ublox_msgs::msg::builder::Init_CfgVALGET_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__BUILDER_HPP_

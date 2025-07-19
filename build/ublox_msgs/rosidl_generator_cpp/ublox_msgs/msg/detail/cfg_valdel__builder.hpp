// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgVALDEL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALDEL__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALDEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_valdel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgVALDEL_keys
{
public:
  explicit Init_CfgVALDEL_keys(::ublox_msgs::msg::CfgVALDEL & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgVALDEL keys(::ublox_msgs::msg::CfgVALDEL::_keys_type arg)
  {
    msg_.keys = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALDEL msg_;
};

class Init_CfgVALDEL_reserved0
{
public:
  explicit Init_CfgVALDEL_reserved0(::ublox_msgs::msg::CfgVALDEL & msg)
  : msg_(msg)
  {}
  Init_CfgVALDEL_keys reserved0(::ublox_msgs::msg::CfgVALDEL::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_CfgVALDEL_keys(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALDEL msg_;
};

class Init_CfgVALDEL_layers
{
public:
  explicit Init_CfgVALDEL_layers(::ublox_msgs::msg::CfgVALDEL & msg)
  : msg_(msg)
  {}
  Init_CfgVALDEL_reserved0 layers(::ublox_msgs::msg::CfgVALDEL::_layers_type arg)
  {
    msg_.layers = std::move(arg);
    return Init_CfgVALDEL_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALDEL msg_;
};

class Init_CfgVALDEL_version
{
public:
  Init_CfgVALDEL_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgVALDEL_layers version(::ublox_msgs::msg::CfgVALDEL::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_CfgVALDEL_layers(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALDEL msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgVALDEL>()
{
  return ublox_msgs::msg::builder::Init_CfgVALDEL_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALDEL__BUILDER_HPP_

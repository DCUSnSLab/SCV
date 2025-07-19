// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgVALSET.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_valset__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgVALSET_cfgdata
{
public:
  explicit Init_CfgVALSET_cfgdata(::ublox_msgs::msg::CfgVALSET & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgVALSET cfgdata(::ublox_msgs::msg::CfgVALSET::_cfgdata_type arg)
  {
    msg_.cfgdata = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALSET msg_;
};

class Init_CfgVALSET_reserved0
{
public:
  explicit Init_CfgVALSET_reserved0(::ublox_msgs::msg::CfgVALSET & msg)
  : msg_(msg)
  {}
  Init_CfgVALSET_cfgdata reserved0(::ublox_msgs::msg::CfgVALSET::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_CfgVALSET_cfgdata(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALSET msg_;
};

class Init_CfgVALSET_layers
{
public:
  explicit Init_CfgVALSET_layers(::ublox_msgs::msg::CfgVALSET & msg)
  : msg_(msg)
  {}
  Init_CfgVALSET_reserved0 layers(::ublox_msgs::msg::CfgVALSET::_layers_type arg)
  {
    msg_.layers = std::move(arg);
    return Init_CfgVALSET_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALSET msg_;
};

class Init_CfgVALSET_version
{
public:
  Init_CfgVALSET_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgVALSET_layers version(::ublox_msgs::msg::CfgVALSET::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_CfgVALSET_layers(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALSET msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgVALSET>()
{
  return ublox_msgs::msg::builder::Init_CfgVALSET_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__BUILDER_HPP_

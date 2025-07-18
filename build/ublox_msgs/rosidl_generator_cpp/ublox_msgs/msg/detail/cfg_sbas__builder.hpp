// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_sbas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgSBAS_scanmode1
{
public:
  explicit Init_CfgSBAS_scanmode1(::ublox_msgs::msg::CfgSBAS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgSBAS scanmode1(::ublox_msgs::msg::CfgSBAS::_scanmode1_type arg)
  {
    msg_.scanmode1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgSBAS msg_;
};

class Init_CfgSBAS_scanmode2
{
public:
  explicit Init_CfgSBAS_scanmode2(::ublox_msgs::msg::CfgSBAS & msg)
  : msg_(msg)
  {}
  Init_CfgSBAS_scanmode1 scanmode2(::ublox_msgs::msg::CfgSBAS::_scanmode2_type arg)
  {
    msg_.scanmode2 = std::move(arg);
    return Init_CfgSBAS_scanmode1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgSBAS msg_;
};

class Init_CfgSBAS_max_sbas
{
public:
  explicit Init_CfgSBAS_max_sbas(::ublox_msgs::msg::CfgSBAS & msg)
  : msg_(msg)
  {}
  Init_CfgSBAS_scanmode2 max_sbas(::ublox_msgs::msg::CfgSBAS::_max_sbas_type arg)
  {
    msg_.max_sbas = std::move(arg);
    return Init_CfgSBAS_scanmode2(msg_);
  }

private:
  ::ublox_msgs::msg::CfgSBAS msg_;
};

class Init_CfgSBAS_usage
{
public:
  explicit Init_CfgSBAS_usage(::ublox_msgs::msg::CfgSBAS & msg)
  : msg_(msg)
  {}
  Init_CfgSBAS_max_sbas usage(::ublox_msgs::msg::CfgSBAS::_usage_type arg)
  {
    msg_.usage = std::move(arg);
    return Init_CfgSBAS_max_sbas(msg_);
  }

private:
  ::ublox_msgs::msg::CfgSBAS msg_;
};

class Init_CfgSBAS_mode
{
public:
  Init_CfgSBAS_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgSBAS_usage mode(::ublox_msgs::msg::CfgSBAS::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_CfgSBAS_usage(msg_);
  }

private:
  ::ublox_msgs::msg::CfgSBAS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgSBAS>()
{
  return ublox_msgs::msg::builder::Init_CfgSBAS_mode();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__BUILDER_HPP_

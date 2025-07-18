// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/MonVER.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_VER__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_VER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/mon_ver__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_MonVER_extension
{
public:
  explicit Init_MonVER_extension(::ublox_msgs::msg::MonVER & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::MonVER extension(::ublox_msgs::msg::MonVER::_extension_type arg)
  {
    msg_.extension = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::MonVER msg_;
};

class Init_MonVER_hw_version
{
public:
  explicit Init_MonVER_hw_version(::ublox_msgs::msg::MonVER & msg)
  : msg_(msg)
  {}
  Init_MonVER_extension hw_version(::ublox_msgs::msg::MonVER::_hw_version_type arg)
  {
    msg_.hw_version = std::move(arg);
    return Init_MonVER_extension(msg_);
  }

private:
  ::ublox_msgs::msg::MonVER msg_;
};

class Init_MonVER_sw_version
{
public:
  Init_MonVER_sw_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MonVER_hw_version sw_version(::ublox_msgs::msg::MonVER::_sw_version_type arg)
  {
    msg_.sw_version = std::move(arg);
    return Init_MonVER_hw_version(msg_);
  }

private:
  ::ublox_msgs::msg::MonVER msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::MonVER>()
{
  return ublox_msgs::msg::builder::Init_MonVER_sw_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_VER__BUILDER_HPP_

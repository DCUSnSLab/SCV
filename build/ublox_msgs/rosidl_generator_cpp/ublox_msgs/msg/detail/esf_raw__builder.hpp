// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/EsfRAW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_RAW__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_RAW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/esf_raw__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_EsfRAW_blocks
{
public:
  explicit Init_EsfRAW_blocks(::ublox_msgs::msg::EsfRAW & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::EsfRAW blocks(::ublox_msgs::msg::EsfRAW::_blocks_type arg)
  {
    msg_.blocks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::EsfRAW msg_;
};

class Init_EsfRAW_reserved0
{
public:
  Init_EsfRAW_reserved0()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EsfRAW_blocks reserved0(::ublox_msgs::msg::EsfRAW::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_EsfRAW_blocks(msg_);
  }

private:
  ::ublox_msgs::msg::EsfRAW msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::EsfRAW>()
{
  return ublox_msgs::msg::builder::Init_EsfRAW_reserved0();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_RAW__BUILDER_HPP_

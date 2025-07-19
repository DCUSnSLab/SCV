// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgINF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_INF__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_INF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_inf__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgINF_blocks
{
public:
  Init_CfgINF_blocks()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ublox_msgs::msg::CfgINF blocks(::ublox_msgs::msg::CfgINF::_blocks_type arg)
  {
    msg_.blocks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgINF msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgINF>()
{
  return ublox_msgs::msg::builder::Init_CfgINF_blocks();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_INF__BUILDER_HPP_

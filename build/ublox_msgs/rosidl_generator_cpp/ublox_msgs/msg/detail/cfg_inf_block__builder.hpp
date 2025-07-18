// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgINFBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_inf_block__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgINFBlock_inf_msg_mask
{
public:
  explicit Init_CfgINFBlock_inf_msg_mask(::ublox_msgs::msg::CfgINFBlock & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgINFBlock inf_msg_mask(::ublox_msgs::msg::CfgINFBlock::_inf_msg_mask_type arg)
  {
    msg_.inf_msg_mask = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgINFBlock msg_;
};

class Init_CfgINFBlock_reserved1
{
public:
  explicit Init_CfgINFBlock_reserved1(::ublox_msgs::msg::CfgINFBlock & msg)
  : msg_(msg)
  {}
  Init_CfgINFBlock_inf_msg_mask reserved1(::ublox_msgs::msg::CfgINFBlock::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_CfgINFBlock_inf_msg_mask(msg_);
  }

private:
  ::ublox_msgs::msg::CfgINFBlock msg_;
};

class Init_CfgINFBlock_protocol_id
{
public:
  Init_CfgINFBlock_protocol_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgINFBlock_reserved1 protocol_id(::ublox_msgs::msg::CfgINFBlock::_protocol_id_type arg)
  {
    msg_.protocol_id = std::move(arg);
    return Init_CfgINFBlock_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgINFBlock msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgINFBlock>()
{
  return ublox_msgs::msg::builder::Init_CfgINFBlock_protocol_id();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__BUILDER_HPP_

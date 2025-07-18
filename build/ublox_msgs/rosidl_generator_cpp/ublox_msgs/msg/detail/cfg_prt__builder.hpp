// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgPRT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_PRT__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_PRT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_prt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgPRT_reserved1
{
public:
  explicit Init_CfgPRT_reserved1(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgPRT reserved1(::ublox_msgs::msg::CfgPRT::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_flags
{
public:
  explicit Init_CfgPRT_flags(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  Init_CfgPRT_reserved1 flags(::ublox_msgs::msg::CfgPRT::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_CfgPRT_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_out_proto_mask
{
public:
  explicit Init_CfgPRT_out_proto_mask(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  Init_CfgPRT_flags out_proto_mask(::ublox_msgs::msg::CfgPRT::_out_proto_mask_type arg)
  {
    msg_.out_proto_mask = std::move(arg);
    return Init_CfgPRT_flags(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_in_proto_mask
{
public:
  explicit Init_CfgPRT_in_proto_mask(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  Init_CfgPRT_out_proto_mask in_proto_mask(::ublox_msgs::msg::CfgPRT::_in_proto_mask_type arg)
  {
    msg_.in_proto_mask = std::move(arg);
    return Init_CfgPRT_out_proto_mask(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_baud_rate
{
public:
  explicit Init_CfgPRT_baud_rate(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  Init_CfgPRT_in_proto_mask baud_rate(::ublox_msgs::msg::CfgPRT::_baud_rate_type arg)
  {
    msg_.baud_rate = std::move(arg);
    return Init_CfgPRT_in_proto_mask(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_mode
{
public:
  explicit Init_CfgPRT_mode(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  Init_CfgPRT_baud_rate mode(::ublox_msgs::msg::CfgPRT::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_CfgPRT_baud_rate(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_tx_ready
{
public:
  explicit Init_CfgPRT_tx_ready(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  Init_CfgPRT_mode tx_ready(::ublox_msgs::msg::CfgPRT::_tx_ready_type arg)
  {
    msg_.tx_ready = std::move(arg);
    return Init_CfgPRT_mode(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_reserved0
{
public:
  explicit Init_CfgPRT_reserved0(::ublox_msgs::msg::CfgPRT & msg)
  : msg_(msg)
  {}
  Init_CfgPRT_tx_ready reserved0(::ublox_msgs::msg::CfgPRT::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_CfgPRT_tx_ready(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

class Init_CfgPRT_port_id
{
public:
  Init_CfgPRT_port_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgPRT_reserved0 port_id(::ublox_msgs::msg::CfgPRT::_port_id_type arg)
  {
    msg_.port_id = std::move(arg);
    return Init_CfgPRT_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::CfgPRT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgPRT>()
{
  return ublox_msgs::msg::builder::Init_CfgPRT_port_id();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_PRT__BUILDER_HPP_

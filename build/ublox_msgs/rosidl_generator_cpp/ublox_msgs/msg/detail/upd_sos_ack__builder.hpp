// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/UpdSOSAck.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/upd_sos_ack__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_UpdSOSAck_reserved1
{
public:
  explicit Init_UpdSOSAck_reserved1(::ublox_msgs::msg::UpdSOSAck & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::UpdSOSAck reserved1(::ublox_msgs::msg::UpdSOSAck::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::UpdSOSAck msg_;
};

class Init_UpdSOSAck_response
{
public:
  explicit Init_UpdSOSAck_response(::ublox_msgs::msg::UpdSOSAck & msg)
  : msg_(msg)
  {}
  Init_UpdSOSAck_reserved1 response(::ublox_msgs::msg::UpdSOSAck::_response_type arg)
  {
    msg_.response = std::move(arg);
    return Init_UpdSOSAck_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::UpdSOSAck msg_;
};

class Init_UpdSOSAck_reserved0
{
public:
  explicit Init_UpdSOSAck_reserved0(::ublox_msgs::msg::UpdSOSAck & msg)
  : msg_(msg)
  {}
  Init_UpdSOSAck_response reserved0(::ublox_msgs::msg::UpdSOSAck::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_UpdSOSAck_response(msg_);
  }

private:
  ::ublox_msgs::msg::UpdSOSAck msg_;
};

class Init_UpdSOSAck_cmd
{
public:
  Init_UpdSOSAck_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdSOSAck_reserved0 cmd(::ublox_msgs::msg::UpdSOSAck::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return Init_UpdSOSAck_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::UpdSOSAck msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::UpdSOSAck>()
{
  return ublox_msgs::msg::builder::Init_UpdSOSAck_cmd();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__BUILDER_HPP_

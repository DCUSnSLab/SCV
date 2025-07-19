// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/Ack.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ACK__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/ack__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_Ack_msg_id
{
public:
  explicit Init_Ack_msg_id(::ublox_msgs::msg::Ack & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::Ack msg_id(::ublox_msgs::msg::Ack::_msg_id_type arg)
  {
    msg_.msg_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::Ack msg_;
};

class Init_Ack_cls_id
{
public:
  Init_Ack_cls_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ack_msg_id cls_id(::ublox_msgs::msg::Ack::_cls_id_type arg)
  {
    msg_.cls_id = std::move(arg);
    return Init_Ack_msg_id(msg_);
  }

private:
  ::ublox_msgs::msg::Ack msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::Ack>()
{
  return ublox_msgs::msg::builder::Init_Ack_cls_id();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ACK__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/UpdSOS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__UPD_SOS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__UPD_SOS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/upd_sos__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_UpdSOS_reserved1
{
public:
  explicit Init_UpdSOS_reserved1(::ublox_msgs::msg::UpdSOS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::UpdSOS reserved1(::ublox_msgs::msg::UpdSOS::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::UpdSOS msg_;
};

class Init_UpdSOS_cmd
{
public:
  Init_UpdSOS_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdSOS_reserved1 cmd(::ublox_msgs::msg::UpdSOS::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return Init_UpdSOS_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::UpdSOS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::UpdSOS>()
{
  return ublox_msgs::msg::builder::Init_UpdSOS_cmd();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__UPD_SOS__BUILDER_HPP_

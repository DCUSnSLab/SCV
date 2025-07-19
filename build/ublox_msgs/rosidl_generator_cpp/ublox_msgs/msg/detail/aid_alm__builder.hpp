// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/AidALM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_ALM__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_ALM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/aid_alm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_AidALM_dwrd
{
public:
  explicit Init_AidALM_dwrd(::ublox_msgs::msg::AidALM & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::AidALM dwrd(::ublox_msgs::msg::AidALM::_dwrd_type arg)
  {
    msg_.dwrd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::AidALM msg_;
};

class Init_AidALM_week
{
public:
  explicit Init_AidALM_week(::ublox_msgs::msg::AidALM & msg)
  : msg_(msg)
  {}
  Init_AidALM_dwrd week(::ublox_msgs::msg::AidALM::_week_type arg)
  {
    msg_.week = std::move(arg);
    return Init_AidALM_dwrd(msg_);
  }

private:
  ::ublox_msgs::msg::AidALM msg_;
};

class Init_AidALM_svid
{
public:
  Init_AidALM_svid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AidALM_week svid(::ublox_msgs::msg::AidALM::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_AidALM_week(msg_);
  }

private:
  ::ublox_msgs::msg::AidALM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::AidALM>()
{
  return ublox_msgs::msg::builder::Init_AidALM_svid();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_ALM__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmALM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_ALM__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_ALM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_alm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmALM_dwrd
{
public:
  explicit Init_RxmALM_dwrd(::ublox_msgs::msg::RxmALM & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmALM dwrd(::ublox_msgs::msg::RxmALM::_dwrd_type arg)
  {
    msg_.dwrd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmALM msg_;
};

class Init_RxmALM_week
{
public:
  explicit Init_RxmALM_week(::ublox_msgs::msg::RxmALM & msg)
  : msg_(msg)
  {}
  Init_RxmALM_dwrd week(::ublox_msgs::msg::RxmALM::_week_type arg)
  {
    msg_.week = std::move(arg);
    return Init_RxmALM_dwrd(msg_);
  }

private:
  ::ublox_msgs::msg::RxmALM msg_;
};

class Init_RxmALM_svid
{
public:
  Init_RxmALM_svid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmALM_week svid(::ublox_msgs::msg::RxmALM::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_RxmALM_week(msg_);
  }

private:
  ::ublox_msgs::msg::RxmALM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmALM>()
{
  return ublox_msgs::msg::builder::Init_RxmALM_svid();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_ALM__BUILDER_HPP_

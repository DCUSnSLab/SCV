// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmRAW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAW__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_raw__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmRAW_sv
{
public:
  explicit Init_RxmRAW_sv(::ublox_msgs::msg::RxmRAW & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmRAW sv(::ublox_msgs::msg::RxmRAW::_sv_type arg)
  {
    msg_.sv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAW msg_;
};

class Init_RxmRAW_reserved1
{
public:
  explicit Init_RxmRAW_reserved1(::ublox_msgs::msg::RxmRAW & msg)
  : msg_(msg)
  {}
  Init_RxmRAW_sv reserved1(::ublox_msgs::msg::RxmRAW::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_RxmRAW_sv(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAW msg_;
};

class Init_RxmRAW_num_sv
{
public:
  explicit Init_RxmRAW_num_sv(::ublox_msgs::msg::RxmRAW & msg)
  : msg_(msg)
  {}
  Init_RxmRAW_reserved1 num_sv(::ublox_msgs::msg::RxmRAW::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_RxmRAW_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAW msg_;
};

class Init_RxmRAW_week
{
public:
  explicit Init_RxmRAW_week(::ublox_msgs::msg::RxmRAW & msg)
  : msg_(msg)
  {}
  Init_RxmRAW_num_sv week(::ublox_msgs::msg::RxmRAW::_week_type arg)
  {
    msg_.week = std::move(arg);
    return Init_RxmRAW_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAW msg_;
};

class Init_RxmRAW_rcv_tow
{
public:
  Init_RxmRAW_rcv_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmRAW_week rcv_tow(::ublox_msgs::msg::RxmRAW::_rcv_tow_type arg)
  {
    msg_.rcv_tow = std::move(arg);
    return Init_RxmRAW_week(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAW msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmRAW>()
{
  return ublox_msgs::msg::builder::Init_RxmRAW_rcv_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAW__BUILDER_HPP_

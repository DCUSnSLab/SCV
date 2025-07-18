// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmRAWX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_rawx__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmRAWX_meas
{
public:
  explicit Init_RxmRAWX_meas(::ublox_msgs::msg::RxmRAWX & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmRAWX meas(::ublox_msgs::msg::RxmRAWX::_meas_type arg)
  {
    msg_.meas = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

class Init_RxmRAWX_reserved1
{
public:
  explicit Init_RxmRAWX_reserved1(::ublox_msgs::msg::RxmRAWX & msg)
  : msg_(msg)
  {}
  Init_RxmRAWX_meas reserved1(::ublox_msgs::msg::RxmRAWX::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_RxmRAWX_meas(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

class Init_RxmRAWX_version
{
public:
  explicit Init_RxmRAWX_version(::ublox_msgs::msg::RxmRAWX & msg)
  : msg_(msg)
  {}
  Init_RxmRAWX_reserved1 version(::ublox_msgs::msg::RxmRAWX::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_RxmRAWX_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

class Init_RxmRAWX_rec_stat
{
public:
  explicit Init_RxmRAWX_rec_stat(::ublox_msgs::msg::RxmRAWX & msg)
  : msg_(msg)
  {}
  Init_RxmRAWX_version rec_stat(::ublox_msgs::msg::RxmRAWX::_rec_stat_type arg)
  {
    msg_.rec_stat = std::move(arg);
    return Init_RxmRAWX_version(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

class Init_RxmRAWX_num_meas
{
public:
  explicit Init_RxmRAWX_num_meas(::ublox_msgs::msg::RxmRAWX & msg)
  : msg_(msg)
  {}
  Init_RxmRAWX_rec_stat num_meas(::ublox_msgs::msg::RxmRAWX::_num_meas_type arg)
  {
    msg_.num_meas = std::move(arg);
    return Init_RxmRAWX_rec_stat(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

class Init_RxmRAWX_leap_s
{
public:
  explicit Init_RxmRAWX_leap_s(::ublox_msgs::msg::RxmRAWX & msg)
  : msg_(msg)
  {}
  Init_RxmRAWX_num_meas leap_s(::ublox_msgs::msg::RxmRAWX::_leap_s_type arg)
  {
    msg_.leap_s = std::move(arg);
    return Init_RxmRAWX_num_meas(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

class Init_RxmRAWX_week
{
public:
  explicit Init_RxmRAWX_week(::ublox_msgs::msg::RxmRAWX & msg)
  : msg_(msg)
  {}
  Init_RxmRAWX_leap_s week(::ublox_msgs::msg::RxmRAWX::_week_type arg)
  {
    msg_.week = std::move(arg);
    return Init_RxmRAWX_leap_s(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

class Init_RxmRAWX_rcv_tow
{
public:
  Init_RxmRAWX_rcv_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmRAWX_week rcv_tow(::ublox_msgs::msg::RxmRAWX::_rcv_tow_type arg)
  {
    msg_.rcv_tow = std::move(arg);
    return Init_RxmRAWX_week(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWX msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmRAWX>()
{
  return ublox_msgs::msg::builder::Init_RxmRAWX_rcv_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__BUILDER_HPP_

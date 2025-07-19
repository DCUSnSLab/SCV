// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavATT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_ATT__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_ATT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_att__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavATT_acc_heading
{
public:
  explicit Init_NavATT_acc_heading(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavATT acc_heading(::ublox_msgs::msg::NavATT::_acc_heading_type arg)
  {
    msg_.acc_heading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_acc_pitch
{
public:
  explicit Init_NavATT_acc_pitch(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  Init_NavATT_acc_heading acc_pitch(::ublox_msgs::msg::NavATT::_acc_pitch_type arg)
  {
    msg_.acc_pitch = std::move(arg);
    return Init_NavATT_acc_heading(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_acc_roll
{
public:
  explicit Init_NavATT_acc_roll(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  Init_NavATT_acc_pitch acc_roll(::ublox_msgs::msg::NavATT::_acc_roll_type arg)
  {
    msg_.acc_roll = std::move(arg);
    return Init_NavATT_acc_pitch(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_heading
{
public:
  explicit Init_NavATT_heading(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  Init_NavATT_acc_roll heading(::ublox_msgs::msg::NavATT::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_NavATT_acc_roll(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_pitch
{
public:
  explicit Init_NavATT_pitch(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  Init_NavATT_heading pitch(::ublox_msgs::msg::NavATT::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_NavATT_heading(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_roll
{
public:
  explicit Init_NavATT_roll(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  Init_NavATT_pitch roll(::ublox_msgs::msg::NavATT::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_NavATT_pitch(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_reserved0
{
public:
  explicit Init_NavATT_reserved0(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  Init_NavATT_roll reserved0(::ublox_msgs::msg::NavATT::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_NavATT_roll(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_version
{
public:
  explicit Init_NavATT_version(::ublox_msgs::msg::NavATT & msg)
  : msg_(msg)
  {}
  Init_NavATT_reserved0 version(::ublox_msgs::msg::NavATT::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_NavATT_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

class Init_NavATT_i_tow
{
public:
  Init_NavATT_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavATT_version i_tow(::ublox_msgs::msg::NavATT::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavATT_version(msg_);
  }

private:
  ::ublox_msgs::msg::NavATT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavATT>()
{
  return ublox_msgs::msg::builder::Init_NavATT_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_ATT__BUILDER_HPP_

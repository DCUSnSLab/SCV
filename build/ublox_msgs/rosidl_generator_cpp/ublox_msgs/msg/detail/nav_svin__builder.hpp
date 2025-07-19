// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSVIN.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_svin__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSVIN_reserved3
{
public:
  explicit Init_NavSVIN_reserved3(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSVIN reserved3(::ublox_msgs::msg::NavSVIN::_reserved3_type arg)
  {
    msg_.reserved3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_active
{
public:
  explicit Init_NavSVIN_active(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_reserved3 active(::ublox_msgs::msg::NavSVIN::_active_type arg)
  {
    msg_.active = std::move(arg);
    return Init_NavSVIN_reserved3(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_valid
{
public:
  explicit Init_NavSVIN_valid(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_active valid(::ublox_msgs::msg::NavSVIN::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_NavSVIN_active(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_obs
{
public:
  explicit Init_NavSVIN_obs(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_valid obs(::ublox_msgs::msg::NavSVIN::_obs_type arg)
  {
    msg_.obs = std::move(arg);
    return Init_NavSVIN_valid(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_mean_acc
{
public:
  explicit Init_NavSVIN_mean_acc(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_obs mean_acc(::ublox_msgs::msg::NavSVIN::_mean_acc_type arg)
  {
    msg_.mean_acc = std::move(arg);
    return Init_NavSVIN_obs(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_reserved1
{
public:
  explicit Init_NavSVIN_reserved1(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_mean_acc reserved1(::ublox_msgs::msg::NavSVIN::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_NavSVIN_mean_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_mean_zhp
{
public:
  explicit Init_NavSVIN_mean_zhp(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_reserved1 mean_zhp(::ublox_msgs::msg::NavSVIN::_mean_zhp_type arg)
  {
    msg_.mean_zhp = std::move(arg);
    return Init_NavSVIN_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_mean_yhp
{
public:
  explicit Init_NavSVIN_mean_yhp(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_mean_zhp mean_yhp(::ublox_msgs::msg::NavSVIN::_mean_yhp_type arg)
  {
    msg_.mean_yhp = std::move(arg);
    return Init_NavSVIN_mean_zhp(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_mean_xhp
{
public:
  explicit Init_NavSVIN_mean_xhp(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_mean_yhp mean_xhp(::ublox_msgs::msg::NavSVIN::_mean_xhp_type arg)
  {
    msg_.mean_xhp = std::move(arg);
    return Init_NavSVIN_mean_yhp(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_mean_z
{
public:
  explicit Init_NavSVIN_mean_z(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_mean_xhp mean_z(::ublox_msgs::msg::NavSVIN::_mean_z_type arg)
  {
    msg_.mean_z = std::move(arg);
    return Init_NavSVIN_mean_xhp(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_mean_y
{
public:
  explicit Init_NavSVIN_mean_y(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_mean_z mean_y(::ublox_msgs::msg::NavSVIN::_mean_y_type arg)
  {
    msg_.mean_y = std::move(arg);
    return Init_NavSVIN_mean_z(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_mean_x
{
public:
  explicit Init_NavSVIN_mean_x(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_mean_y mean_x(::ublox_msgs::msg::NavSVIN::_mean_x_type arg)
  {
    msg_.mean_x = std::move(arg);
    return Init_NavSVIN_mean_y(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_dur
{
public:
  explicit Init_NavSVIN_dur(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_mean_x dur(::ublox_msgs::msg::NavSVIN::_dur_type arg)
  {
    msg_.dur = std::move(arg);
    return Init_NavSVIN_mean_x(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_i_tow
{
public:
  explicit Init_NavSVIN_i_tow(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_dur i_tow(::ublox_msgs::msg::NavSVIN::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavSVIN_dur(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_reserved0
{
public:
  explicit Init_NavSVIN_reserved0(::ublox_msgs::msg::NavSVIN & msg)
  : msg_(msg)
  {}
  Init_NavSVIN_i_tow reserved0(::ublox_msgs::msg::NavSVIN::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_NavSVIN_i_tow(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

class Init_NavSVIN_version
{
public:
  Init_NavSVIN_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSVIN_reserved0 version(::ublox_msgs::msg::NavSVIN::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_NavSVIN_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVIN msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSVIN>()
{
  return ublox_msgs::msg::builder::Init_NavSVIN_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__BUILDER_HPP_

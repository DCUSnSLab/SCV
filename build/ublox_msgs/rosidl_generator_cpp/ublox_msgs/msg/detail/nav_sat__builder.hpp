// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSAT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SAT__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_sat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSAT_sv
{
public:
  explicit Init_NavSAT_sv(::ublox_msgs::msg::NavSAT & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSAT sv(::ublox_msgs::msg::NavSAT::_sv_type arg)
  {
    msg_.sv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSAT msg_;
};

class Init_NavSAT_reserved0
{
public:
  explicit Init_NavSAT_reserved0(::ublox_msgs::msg::NavSAT & msg)
  : msg_(msg)
  {}
  Init_NavSAT_sv reserved0(::ublox_msgs::msg::NavSAT::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_NavSAT_sv(msg_);
  }

private:
  ::ublox_msgs::msg::NavSAT msg_;
};

class Init_NavSAT_num_svs
{
public:
  explicit Init_NavSAT_num_svs(::ublox_msgs::msg::NavSAT & msg)
  : msg_(msg)
  {}
  Init_NavSAT_reserved0 num_svs(::ublox_msgs::msg::NavSAT::_num_svs_type arg)
  {
    msg_.num_svs = std::move(arg);
    return Init_NavSAT_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::NavSAT msg_;
};

class Init_NavSAT_version
{
public:
  explicit Init_NavSAT_version(::ublox_msgs::msg::NavSAT & msg)
  : msg_(msg)
  {}
  Init_NavSAT_num_svs version(::ublox_msgs::msg::NavSAT::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_NavSAT_num_svs(msg_);
  }

private:
  ::ublox_msgs::msg::NavSAT msg_;
};

class Init_NavSAT_i_tow
{
public:
  Init_NavSAT_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSAT_version i_tow(::ublox_msgs::msg::NavSAT::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavSAT_version(msg_);
  }

private:
  ::ublox_msgs::msg::NavSAT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSAT>()
{
  return ublox_msgs::msg::builder::Init_NavSAT_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SAT__BUILDER_HPP_

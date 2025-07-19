// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavDGPSSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_dgpssv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavDGPSSV_prrc
{
public:
  explicit Init_NavDGPSSV_prrc(::ublox_msgs::msg::NavDGPSSV & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavDGPSSV prrc(::ublox_msgs::msg::NavDGPSSV::_prrc_type arg)
  {
    msg_.prrc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPSSV msg_;
};

class Init_NavDGPSSV_prc
{
public:
  explicit Init_NavDGPSSV_prc(::ublox_msgs::msg::NavDGPSSV & msg)
  : msg_(msg)
  {}
  Init_NavDGPSSV_prrc prc(::ublox_msgs::msg::NavDGPSSV::_prc_type arg)
  {
    msg_.prc = std::move(arg);
    return Init_NavDGPSSV_prrc(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPSSV msg_;
};

class Init_NavDGPSSV_age_c
{
public:
  explicit Init_NavDGPSSV_age_c(::ublox_msgs::msg::NavDGPSSV & msg)
  : msg_(msg)
  {}
  Init_NavDGPSSV_prc age_c(::ublox_msgs::msg::NavDGPSSV::_age_c_type arg)
  {
    msg_.age_c = std::move(arg);
    return Init_NavDGPSSV_prc(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPSSV msg_;
};

class Init_NavDGPSSV_flags
{
public:
  explicit Init_NavDGPSSV_flags(::ublox_msgs::msg::NavDGPSSV & msg)
  : msg_(msg)
  {}
  Init_NavDGPSSV_age_c flags(::ublox_msgs::msg::NavDGPSSV::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_NavDGPSSV_age_c(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPSSV msg_;
};

class Init_NavDGPSSV_svid
{
public:
  Init_NavDGPSSV_svid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavDGPSSV_flags svid(::ublox_msgs::msg::NavDGPSSV::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_NavDGPSSV_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPSSV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavDGPSSV>()
{
  return ublox_msgs::msg::builder::Init_NavDGPSSV_svid();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__BUILDER_HPP_

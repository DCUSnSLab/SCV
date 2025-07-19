// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_sbas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSBAS_sv
{
public:
  explicit Init_NavSBAS_sv(::ublox_msgs::msg::NavSBAS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSBAS sv(::ublox_msgs::msg::NavSBAS::_sv_type arg)
  {
    msg_.sv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

class Init_NavSBAS_reserved0
{
public:
  explicit Init_NavSBAS_reserved0(::ublox_msgs::msg::NavSBAS & msg)
  : msg_(msg)
  {}
  Init_NavSBAS_sv reserved0(::ublox_msgs::msg::NavSBAS::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_NavSBAS_sv(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

class Init_NavSBAS_cnt
{
public:
  explicit Init_NavSBAS_cnt(::ublox_msgs::msg::NavSBAS & msg)
  : msg_(msg)
  {}
  Init_NavSBAS_reserved0 cnt(::ublox_msgs::msg::NavSBAS::_cnt_type arg)
  {
    msg_.cnt = std::move(arg);
    return Init_NavSBAS_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

class Init_NavSBAS_service
{
public:
  explicit Init_NavSBAS_service(::ublox_msgs::msg::NavSBAS & msg)
  : msg_(msg)
  {}
  Init_NavSBAS_cnt service(::ublox_msgs::msg::NavSBAS::_service_type arg)
  {
    msg_.service = std::move(arg);
    return Init_NavSBAS_cnt(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

class Init_NavSBAS_sys
{
public:
  explicit Init_NavSBAS_sys(::ublox_msgs::msg::NavSBAS & msg)
  : msg_(msg)
  {}
  Init_NavSBAS_service sys(::ublox_msgs::msg::NavSBAS::_sys_type arg)
  {
    msg_.sys = std::move(arg);
    return Init_NavSBAS_service(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

class Init_NavSBAS_mode
{
public:
  explicit Init_NavSBAS_mode(::ublox_msgs::msg::NavSBAS & msg)
  : msg_(msg)
  {}
  Init_NavSBAS_sys mode(::ublox_msgs::msg::NavSBAS::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_NavSBAS_sys(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

class Init_NavSBAS_geo
{
public:
  explicit Init_NavSBAS_geo(::ublox_msgs::msg::NavSBAS & msg)
  : msg_(msg)
  {}
  Init_NavSBAS_mode geo(::ublox_msgs::msg::NavSBAS::_geo_type arg)
  {
    msg_.geo = std::move(arg);
    return Init_NavSBAS_mode(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

class Init_NavSBAS_i_tow
{
public:
  Init_NavSBAS_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSBAS_geo i_tow(::ublox_msgs::msg::NavSBAS::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavSBAS_geo(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBAS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSBAS>()
{
  return ublox_msgs::msg::builder::Init_NavSBAS_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__BUILDER_HPP_

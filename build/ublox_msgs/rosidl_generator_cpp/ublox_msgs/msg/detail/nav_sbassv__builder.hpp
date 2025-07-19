// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSBASSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_sbassv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSBASSV_ic
{
public:
  explicit Init_NavSBASSV_ic(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSBASSV ic(::ublox_msgs::msg::NavSBASSV::_ic_type arg)
  {
    msg_.ic = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_reserved2
{
public:
  explicit Init_NavSBASSV_reserved2(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  Init_NavSBASSV_ic reserved2(::ublox_msgs::msg::NavSBASSV::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return Init_NavSBASSV_ic(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_prc
{
public:
  explicit Init_NavSBASSV_prc(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  Init_NavSBASSV_reserved2 prc(::ublox_msgs::msg::NavSBASSV::_prc_type arg)
  {
    msg_.prc = std::move(arg);
    return Init_NavSBASSV_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_reserved1
{
public:
  explicit Init_NavSBASSV_reserved1(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  Init_NavSBASSV_prc reserved1(::ublox_msgs::msg::NavSBASSV::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_NavSBASSV_prc(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_sv_service
{
public:
  explicit Init_NavSBASSV_sv_service(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  Init_NavSBASSV_reserved1 sv_service(::ublox_msgs::msg::NavSBASSV::_sv_service_type arg)
  {
    msg_.sv_service = std::move(arg);
    return Init_NavSBASSV_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_sv_sys
{
public:
  explicit Init_NavSBASSV_sv_sys(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  Init_NavSBASSV_sv_service sv_sys(::ublox_msgs::msg::NavSBASSV::_sv_sys_type arg)
  {
    msg_.sv_sys = std::move(arg);
    return Init_NavSBASSV_sv_service(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_udre
{
public:
  explicit Init_NavSBASSV_udre(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  Init_NavSBASSV_sv_sys udre(::ublox_msgs::msg::NavSBASSV::_udre_type arg)
  {
    msg_.udre = std::move(arg);
    return Init_NavSBASSV_sv_sys(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_flags
{
public:
  explicit Init_NavSBASSV_flags(::ublox_msgs::msg::NavSBASSV & msg)
  : msg_(msg)
  {}
  Init_NavSBASSV_udre flags(::ublox_msgs::msg::NavSBASSV::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_NavSBASSV_udre(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

class Init_NavSBASSV_svid
{
public:
  Init_NavSBASSV_svid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSBASSV_flags svid(::ublox_msgs::msg::NavSBASSV::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_NavSBASSV_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavSBASSV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSBASSV>()
{
  return ublox_msgs::msg::builder::Init_NavSBASSV_svid();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSATSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_satsv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSATSV_flags
{
public:
  explicit Init_NavSATSV_flags(::ublox_msgs::msg::NavSATSV & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSATSV flags(::ublox_msgs::msg::NavSATSV::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSATSV msg_;
};

class Init_NavSATSV_pr_res
{
public:
  explicit Init_NavSATSV_pr_res(::ublox_msgs::msg::NavSATSV & msg)
  : msg_(msg)
  {}
  Init_NavSATSV_flags pr_res(::ublox_msgs::msg::NavSATSV::_pr_res_type arg)
  {
    msg_.pr_res = std::move(arg);
    return Init_NavSATSV_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavSATSV msg_;
};

class Init_NavSATSV_azim
{
public:
  explicit Init_NavSATSV_azim(::ublox_msgs::msg::NavSATSV & msg)
  : msg_(msg)
  {}
  Init_NavSATSV_pr_res azim(::ublox_msgs::msg::NavSATSV::_azim_type arg)
  {
    msg_.azim = std::move(arg);
    return Init_NavSATSV_pr_res(msg_);
  }

private:
  ::ublox_msgs::msg::NavSATSV msg_;
};

class Init_NavSATSV_elev
{
public:
  explicit Init_NavSATSV_elev(::ublox_msgs::msg::NavSATSV & msg)
  : msg_(msg)
  {}
  Init_NavSATSV_azim elev(::ublox_msgs::msg::NavSATSV::_elev_type arg)
  {
    msg_.elev = std::move(arg);
    return Init_NavSATSV_azim(msg_);
  }

private:
  ::ublox_msgs::msg::NavSATSV msg_;
};

class Init_NavSATSV_cno
{
public:
  explicit Init_NavSATSV_cno(::ublox_msgs::msg::NavSATSV & msg)
  : msg_(msg)
  {}
  Init_NavSATSV_elev cno(::ublox_msgs::msg::NavSATSV::_cno_type arg)
  {
    msg_.cno = std::move(arg);
    return Init_NavSATSV_elev(msg_);
  }

private:
  ::ublox_msgs::msg::NavSATSV msg_;
};

class Init_NavSATSV_sv_id
{
public:
  explicit Init_NavSATSV_sv_id(::ublox_msgs::msg::NavSATSV & msg)
  : msg_(msg)
  {}
  Init_NavSATSV_cno sv_id(::ublox_msgs::msg::NavSATSV::_sv_id_type arg)
  {
    msg_.sv_id = std::move(arg);
    return Init_NavSATSV_cno(msg_);
  }

private:
  ::ublox_msgs::msg::NavSATSV msg_;
};

class Init_NavSATSV_gnss_id
{
public:
  Init_NavSATSV_gnss_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSATSV_sv_id gnss_id(::ublox_msgs::msg::NavSATSV::_gnss_id_type arg)
  {
    msg_.gnss_id = std::move(arg);
    return Init_NavSATSV_sv_id(msg_);
  }

private:
  ::ublox_msgs::msg::NavSATSV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSATSV>()
{
  return ublox_msgs::msg::builder::Init_NavSATSV_gnss_id();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__BUILDER_HPP_

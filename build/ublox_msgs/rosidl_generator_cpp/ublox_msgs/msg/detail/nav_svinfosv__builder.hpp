// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSVINFOSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_svinfosv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSVINFOSV_pr_res
{
public:
  explicit Init_NavSVINFOSV_pr_res(::ublox_msgs::msg::NavSVINFOSV & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSVINFOSV pr_res(::ublox_msgs::msg::NavSVINFOSV::_pr_res_type arg)
  {
    msg_.pr_res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

class Init_NavSVINFOSV_azim
{
public:
  explicit Init_NavSVINFOSV_azim(::ublox_msgs::msg::NavSVINFOSV & msg)
  : msg_(msg)
  {}
  Init_NavSVINFOSV_pr_res azim(::ublox_msgs::msg::NavSVINFOSV::_azim_type arg)
  {
    msg_.azim = std::move(arg);
    return Init_NavSVINFOSV_pr_res(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

class Init_NavSVINFOSV_elev
{
public:
  explicit Init_NavSVINFOSV_elev(::ublox_msgs::msg::NavSVINFOSV & msg)
  : msg_(msg)
  {}
  Init_NavSVINFOSV_azim elev(::ublox_msgs::msg::NavSVINFOSV::_elev_type arg)
  {
    msg_.elev = std::move(arg);
    return Init_NavSVINFOSV_azim(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

class Init_NavSVINFOSV_cno
{
public:
  explicit Init_NavSVINFOSV_cno(::ublox_msgs::msg::NavSVINFOSV & msg)
  : msg_(msg)
  {}
  Init_NavSVINFOSV_elev cno(::ublox_msgs::msg::NavSVINFOSV::_cno_type arg)
  {
    msg_.cno = std::move(arg);
    return Init_NavSVINFOSV_elev(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

class Init_NavSVINFOSV_quality
{
public:
  explicit Init_NavSVINFOSV_quality(::ublox_msgs::msg::NavSVINFOSV & msg)
  : msg_(msg)
  {}
  Init_NavSVINFOSV_cno quality(::ublox_msgs::msg::NavSVINFOSV::_quality_type arg)
  {
    msg_.quality = std::move(arg);
    return Init_NavSVINFOSV_cno(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

class Init_NavSVINFOSV_flags
{
public:
  explicit Init_NavSVINFOSV_flags(::ublox_msgs::msg::NavSVINFOSV & msg)
  : msg_(msg)
  {}
  Init_NavSVINFOSV_quality flags(::ublox_msgs::msg::NavSVINFOSV::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_NavSVINFOSV_quality(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

class Init_NavSVINFOSV_svid
{
public:
  explicit Init_NavSVINFOSV_svid(::ublox_msgs::msg::NavSVINFOSV & msg)
  : msg_(msg)
  {}
  Init_NavSVINFOSV_flags svid(::ublox_msgs::msg::NavSVINFOSV::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_NavSVINFOSV_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

class Init_NavSVINFOSV_chn
{
public:
  Init_NavSVINFOSV_chn()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSVINFOSV_svid chn(::ublox_msgs::msg::NavSVINFOSV::_chn_type arg)
  {
    msg_.chn = std::move(arg);
    return Init_NavSVINFOSV_svid(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFOSV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSVINFOSV>()
{
  return ublox_msgs::msg::builder::Init_NavSVINFOSV_chn();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__BUILDER_HPP_

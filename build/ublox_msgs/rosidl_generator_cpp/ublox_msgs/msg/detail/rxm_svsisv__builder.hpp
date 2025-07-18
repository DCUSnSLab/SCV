// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmSVSISV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_svsisv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmSVSISV_age
{
public:
  explicit Init_RxmSVSISV_age(::ublox_msgs::msg::RxmSVSISV & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmSVSISV age(::ublox_msgs::msg::RxmSVSISV::_age_type arg)
  {
    msg_.age = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSISV msg_;
};

class Init_RxmSVSISV_elev
{
public:
  explicit Init_RxmSVSISV_elev(::ublox_msgs::msg::RxmSVSISV & msg)
  : msg_(msg)
  {}
  Init_RxmSVSISV_age elev(::ublox_msgs::msg::RxmSVSISV::_elev_type arg)
  {
    msg_.elev = std::move(arg);
    return Init_RxmSVSISV_age(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSISV msg_;
};

class Init_RxmSVSISV_azim
{
public:
  explicit Init_RxmSVSISV_azim(::ublox_msgs::msg::RxmSVSISV & msg)
  : msg_(msg)
  {}
  Init_RxmSVSISV_elev azim(::ublox_msgs::msg::RxmSVSISV::_azim_type arg)
  {
    msg_.azim = std::move(arg);
    return Init_RxmSVSISV_elev(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSISV msg_;
};

class Init_RxmSVSISV_sv_flag
{
public:
  explicit Init_RxmSVSISV_sv_flag(::ublox_msgs::msg::RxmSVSISV & msg)
  : msg_(msg)
  {}
  Init_RxmSVSISV_azim sv_flag(::ublox_msgs::msg::RxmSVSISV::_sv_flag_type arg)
  {
    msg_.sv_flag = std::move(arg);
    return Init_RxmSVSISV_azim(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSISV msg_;
};

class Init_RxmSVSISV_svid
{
public:
  Init_RxmSVSISV_svid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmSVSISV_sv_flag svid(::ublox_msgs::msg::RxmSVSISV::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_RxmSVSISV_sv_flag(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSISV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmSVSISV>()
{
  return ublox_msgs::msg::builder::Init_RxmSVSISV_svid();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__BUILDER_HPP_

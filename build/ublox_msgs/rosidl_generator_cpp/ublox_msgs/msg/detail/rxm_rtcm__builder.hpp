// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmRTCM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_rtcm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmRTCM_msg_type
{
public:
  explicit Init_RxmRTCM_msg_type(::ublox_msgs::msg::RxmRTCM & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmRTCM msg_type(::ublox_msgs::msg::RxmRTCM::_msg_type_type arg)
  {
    msg_.msg_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRTCM msg_;
};

class Init_RxmRTCM_ref_station
{
public:
  explicit Init_RxmRTCM_ref_station(::ublox_msgs::msg::RxmRTCM & msg)
  : msg_(msg)
  {}
  Init_RxmRTCM_msg_type ref_station(::ublox_msgs::msg::RxmRTCM::_ref_station_type arg)
  {
    msg_.ref_station = std::move(arg);
    return Init_RxmRTCM_msg_type(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRTCM msg_;
};

class Init_RxmRTCM_reserved0
{
public:
  explicit Init_RxmRTCM_reserved0(::ublox_msgs::msg::RxmRTCM & msg)
  : msg_(msg)
  {}
  Init_RxmRTCM_ref_station reserved0(::ublox_msgs::msg::RxmRTCM::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_RxmRTCM_ref_station(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRTCM msg_;
};

class Init_RxmRTCM_flags
{
public:
  explicit Init_RxmRTCM_flags(::ublox_msgs::msg::RxmRTCM & msg)
  : msg_(msg)
  {}
  Init_RxmRTCM_reserved0 flags(::ublox_msgs::msg::RxmRTCM::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_RxmRTCM_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRTCM msg_;
};

class Init_RxmRTCM_version
{
public:
  Init_RxmRTCM_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmRTCM_flags version(::ublox_msgs::msg::RxmRTCM::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_RxmRTCM_flags(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRTCM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmRTCM>()
{
  return ublox_msgs::msg::builder::Init_RxmRTCM_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__BUILDER_HPP_

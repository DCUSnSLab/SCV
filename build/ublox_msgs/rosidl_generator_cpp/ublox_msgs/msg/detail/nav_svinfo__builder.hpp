// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSVINFO.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVINFO__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVINFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_svinfo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSVINFO_sv
{
public:
  explicit Init_NavSVINFO_sv(::ublox_msgs::msg::NavSVINFO & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSVINFO sv(::ublox_msgs::msg::NavSVINFO::_sv_type arg)
  {
    msg_.sv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFO msg_;
};

class Init_NavSVINFO_reserved2
{
public:
  explicit Init_NavSVINFO_reserved2(::ublox_msgs::msg::NavSVINFO & msg)
  : msg_(msg)
  {}
  Init_NavSVINFO_sv reserved2(::ublox_msgs::msg::NavSVINFO::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return Init_NavSVINFO_sv(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFO msg_;
};

class Init_NavSVINFO_global_flags
{
public:
  explicit Init_NavSVINFO_global_flags(::ublox_msgs::msg::NavSVINFO & msg)
  : msg_(msg)
  {}
  Init_NavSVINFO_reserved2 global_flags(::ublox_msgs::msg::NavSVINFO::_global_flags_type arg)
  {
    msg_.global_flags = std::move(arg);
    return Init_NavSVINFO_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFO msg_;
};

class Init_NavSVINFO_num_ch
{
public:
  explicit Init_NavSVINFO_num_ch(::ublox_msgs::msg::NavSVINFO & msg)
  : msg_(msg)
  {}
  Init_NavSVINFO_global_flags num_ch(::ublox_msgs::msg::NavSVINFO::_num_ch_type arg)
  {
    msg_.num_ch = std::move(arg);
    return Init_NavSVINFO_global_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFO msg_;
};

class Init_NavSVINFO_i_tow
{
public:
  Init_NavSVINFO_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSVINFO_num_ch i_tow(::ublox_msgs::msg::NavSVINFO::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavSVINFO_num_ch(msg_);
  }

private:
  ::ublox_msgs::msg::NavSVINFO msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSVINFO>()
{
  return ublox_msgs::msg::builder::Init_NavSVINFO_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVINFO__BUILDER_HPP_

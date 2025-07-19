// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavPOSLLH.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_POSLLH__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_POSLLH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_posllh__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavPOSLLH_v_acc
{
public:
  explicit Init_NavPOSLLH_v_acc(::ublox_msgs::msg::NavPOSLLH & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavPOSLLH v_acc(::ublox_msgs::msg::NavPOSLLH::_v_acc_type arg)
  {
    msg_.v_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSLLH msg_;
};

class Init_NavPOSLLH_h_acc
{
public:
  explicit Init_NavPOSLLH_h_acc(::ublox_msgs::msg::NavPOSLLH & msg)
  : msg_(msg)
  {}
  Init_NavPOSLLH_v_acc h_acc(::ublox_msgs::msg::NavPOSLLH::_h_acc_type arg)
  {
    msg_.h_acc = std::move(arg);
    return Init_NavPOSLLH_v_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSLLH msg_;
};

class Init_NavPOSLLH_h_msl
{
public:
  explicit Init_NavPOSLLH_h_msl(::ublox_msgs::msg::NavPOSLLH & msg)
  : msg_(msg)
  {}
  Init_NavPOSLLH_h_acc h_msl(::ublox_msgs::msg::NavPOSLLH::_h_msl_type arg)
  {
    msg_.h_msl = std::move(arg);
    return Init_NavPOSLLH_h_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSLLH msg_;
};

class Init_NavPOSLLH_height
{
public:
  explicit Init_NavPOSLLH_height(::ublox_msgs::msg::NavPOSLLH & msg)
  : msg_(msg)
  {}
  Init_NavPOSLLH_h_msl height(::ublox_msgs::msg::NavPOSLLH::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_NavPOSLLH_h_msl(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSLLH msg_;
};

class Init_NavPOSLLH_lat
{
public:
  explicit Init_NavPOSLLH_lat(::ublox_msgs::msg::NavPOSLLH & msg)
  : msg_(msg)
  {}
  Init_NavPOSLLH_height lat(::ublox_msgs::msg::NavPOSLLH::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_NavPOSLLH_height(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSLLH msg_;
};

class Init_NavPOSLLH_lon
{
public:
  explicit Init_NavPOSLLH_lon(::ublox_msgs::msg::NavPOSLLH & msg)
  : msg_(msg)
  {}
  Init_NavPOSLLH_lat lon(::ublox_msgs::msg::NavPOSLLH::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_NavPOSLLH_lat(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSLLH msg_;
};

class Init_NavPOSLLH_i_tow
{
public:
  Init_NavPOSLLH_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavPOSLLH_lon i_tow(::ublox_msgs::msg::NavPOSLLH::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavPOSLLH_lon(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSLLH msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavPOSLLH>()
{
  return ublox_msgs::msg::builder::Init_NavPOSLLH_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_POSLLH__BUILDER_HPP_

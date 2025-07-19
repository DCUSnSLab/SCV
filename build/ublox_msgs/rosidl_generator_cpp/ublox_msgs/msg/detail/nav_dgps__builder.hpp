// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavDGPS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_dgps__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavDGPS_sv
{
public:
  explicit Init_NavDGPS_sv(::ublox_msgs::msg::NavDGPS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavDGPS sv(::ublox_msgs::msg::NavDGPS::_sv_type arg)
  {
    msg_.sv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

class Init_NavDGPS_reserved1
{
public:
  explicit Init_NavDGPS_reserved1(::ublox_msgs::msg::NavDGPS & msg)
  : msg_(msg)
  {}
  Init_NavDGPS_sv reserved1(::ublox_msgs::msg::NavDGPS::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_NavDGPS_sv(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

class Init_NavDGPS_status
{
public:
  explicit Init_NavDGPS_status(::ublox_msgs::msg::NavDGPS & msg)
  : msg_(msg)
  {}
  Init_NavDGPS_reserved1 status(::ublox_msgs::msg::NavDGPS::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavDGPS_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

class Init_NavDGPS_num_ch
{
public:
  explicit Init_NavDGPS_num_ch(::ublox_msgs::msg::NavDGPS & msg)
  : msg_(msg)
  {}
  Init_NavDGPS_status num_ch(::ublox_msgs::msg::NavDGPS::_num_ch_type arg)
  {
    msg_.num_ch = std::move(arg);
    return Init_NavDGPS_status(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

class Init_NavDGPS_base_health
{
public:
  explicit Init_NavDGPS_base_health(::ublox_msgs::msg::NavDGPS & msg)
  : msg_(msg)
  {}
  Init_NavDGPS_num_ch base_health(::ublox_msgs::msg::NavDGPS::_base_health_type arg)
  {
    msg_.base_health = std::move(arg);
    return Init_NavDGPS_num_ch(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

class Init_NavDGPS_base_id
{
public:
  explicit Init_NavDGPS_base_id(::ublox_msgs::msg::NavDGPS & msg)
  : msg_(msg)
  {}
  Init_NavDGPS_base_health base_id(::ublox_msgs::msg::NavDGPS::_base_id_type arg)
  {
    msg_.base_id = std::move(arg);
    return Init_NavDGPS_base_health(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

class Init_NavDGPS_age
{
public:
  explicit Init_NavDGPS_age(::ublox_msgs::msg::NavDGPS & msg)
  : msg_(msg)
  {}
  Init_NavDGPS_base_id age(::ublox_msgs::msg::NavDGPS::_age_type arg)
  {
    msg_.age = std::move(arg);
    return Init_NavDGPS_base_id(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

class Init_NavDGPS_i_tow
{
public:
  Init_NavDGPS_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavDGPS_age i_tow(::ublox_msgs::msg::NavDGPS::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavDGPS_age(msg_);
  }

private:
  ::ublox_msgs::msg::NavDGPS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavDGPS>()
{
  return ublox_msgs::msg::builder::Init_NavDGPS_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__BUILDER_HPP_

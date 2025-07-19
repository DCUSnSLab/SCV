// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/HnrPVT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__HNR_PVT__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__HNR_PVT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/hnr_pvt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_HnrPVT_reserved1
{
public:
  explicit Init_HnrPVT_reserved1(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::HnrPVT reserved1(::ublox_msgs::msg::HnrPVT::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_head_acc
{
public:
  explicit Init_HnrPVT_head_acc(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_reserved1 head_acc(::ublox_msgs::msg::HnrPVT::_head_acc_type arg)
  {
    msg_.head_acc = std::move(arg);
    return Init_HnrPVT_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_s_acc
{
public:
  explicit Init_HnrPVT_s_acc(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_head_acc s_acc(::ublox_msgs::msg::HnrPVT::_s_acc_type arg)
  {
    msg_.s_acc = std::move(arg);
    return Init_HnrPVT_head_acc(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_v_acc
{
public:
  explicit Init_HnrPVT_v_acc(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_s_acc v_acc(::ublox_msgs::msg::HnrPVT::_v_acc_type arg)
  {
    msg_.v_acc = std::move(arg);
    return Init_HnrPVT_s_acc(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_h_acc
{
public:
  explicit Init_HnrPVT_h_acc(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_v_acc h_acc(::ublox_msgs::msg::HnrPVT::_h_acc_type arg)
  {
    msg_.h_acc = std::move(arg);
    return Init_HnrPVT_v_acc(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_head_veh
{
public:
  explicit Init_HnrPVT_head_veh(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_h_acc head_veh(::ublox_msgs::msg::HnrPVT::_head_veh_type arg)
  {
    msg_.head_veh = std::move(arg);
    return Init_HnrPVT_h_acc(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_head_mot
{
public:
  explicit Init_HnrPVT_head_mot(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_head_veh head_mot(::ublox_msgs::msg::HnrPVT::_head_mot_type arg)
  {
    msg_.head_mot = std::move(arg);
    return Init_HnrPVT_head_veh(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_speed
{
public:
  explicit Init_HnrPVT_speed(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_head_mot speed(::ublox_msgs::msg::HnrPVT::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_HnrPVT_head_mot(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_g_speed
{
public:
  explicit Init_HnrPVT_g_speed(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_speed g_speed(::ublox_msgs::msg::HnrPVT::_g_speed_type arg)
  {
    msg_.g_speed = std::move(arg);
    return Init_HnrPVT_speed(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_h_msl
{
public:
  explicit Init_HnrPVT_h_msl(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_g_speed h_msl(::ublox_msgs::msg::HnrPVT::_h_msl_type arg)
  {
    msg_.h_msl = std::move(arg);
    return Init_HnrPVT_g_speed(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_height
{
public:
  explicit Init_HnrPVT_height(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_h_msl height(::ublox_msgs::msg::HnrPVT::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_HnrPVT_h_msl(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_lat
{
public:
  explicit Init_HnrPVT_lat(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_height lat(::ublox_msgs::msg::HnrPVT::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_HnrPVT_height(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_lon
{
public:
  explicit Init_HnrPVT_lon(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_lat lon(::ublox_msgs::msg::HnrPVT::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_HnrPVT_lat(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_reserved0
{
public:
  explicit Init_HnrPVT_reserved0(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_lon reserved0(::ublox_msgs::msg::HnrPVT::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_HnrPVT_lon(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_flags
{
public:
  explicit Init_HnrPVT_flags(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_reserved0 flags(::ublox_msgs::msg::HnrPVT::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_HnrPVT_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_gps_fix
{
public:
  explicit Init_HnrPVT_gps_fix(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_flags gps_fix(::ublox_msgs::msg::HnrPVT::_gps_fix_type arg)
  {
    msg_.gps_fix = std::move(arg);
    return Init_HnrPVT_flags(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_nano
{
public:
  explicit Init_HnrPVT_nano(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_gps_fix nano(::ublox_msgs::msg::HnrPVT::_nano_type arg)
  {
    msg_.nano = std::move(arg);
    return Init_HnrPVT_gps_fix(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_valid
{
public:
  explicit Init_HnrPVT_valid(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_nano valid(::ublox_msgs::msg::HnrPVT::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_HnrPVT_nano(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_sec
{
public:
  explicit Init_HnrPVT_sec(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_valid sec(::ublox_msgs::msg::HnrPVT::_sec_type arg)
  {
    msg_.sec = std::move(arg);
    return Init_HnrPVT_valid(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_min
{
public:
  explicit Init_HnrPVT_min(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_sec min(::ublox_msgs::msg::HnrPVT::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_HnrPVT_sec(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_hour
{
public:
  explicit Init_HnrPVT_hour(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_min hour(::ublox_msgs::msg::HnrPVT::_hour_type arg)
  {
    msg_.hour = std::move(arg);
    return Init_HnrPVT_min(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_day
{
public:
  explicit Init_HnrPVT_day(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_hour day(::ublox_msgs::msg::HnrPVT::_day_type arg)
  {
    msg_.day = std::move(arg);
    return Init_HnrPVT_hour(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_month
{
public:
  explicit Init_HnrPVT_month(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_day month(::ublox_msgs::msg::HnrPVT::_month_type arg)
  {
    msg_.month = std::move(arg);
    return Init_HnrPVT_day(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_year
{
public:
  explicit Init_HnrPVT_year(::ublox_msgs::msg::HnrPVT & msg)
  : msg_(msg)
  {}
  Init_HnrPVT_month year(::ublox_msgs::msg::HnrPVT::_year_type arg)
  {
    msg_.year = std::move(arg);
    return Init_HnrPVT_month(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

class Init_HnrPVT_i_tow
{
public:
  Init_HnrPVT_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HnrPVT_year i_tow(::ublox_msgs::msg::HnrPVT::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_HnrPVT_year(msg_);
  }

private:
  ::ublox_msgs::msg::HnrPVT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::HnrPVT>()
{
  return ublox_msgs::msg::builder::Init_HnrPVT_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__HNR_PVT__BUILDER_HPP_

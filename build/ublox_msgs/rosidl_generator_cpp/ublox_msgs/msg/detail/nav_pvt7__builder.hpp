// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavPVT7.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_pvt7__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavPVT7_reserved1
{
public:
  explicit Init_NavPVT7_reserved1(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavPVT7 reserved1(::ublox_msgs::msg::NavPVT7::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_p_dop
{
public:
  explicit Init_NavPVT7_p_dop(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_reserved1 p_dop(::ublox_msgs::msg::NavPVT7::_p_dop_type arg)
  {
    msg_.p_dop = std::move(arg);
    return Init_NavPVT7_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_head_acc
{
public:
  explicit Init_NavPVT7_head_acc(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_p_dop head_acc(::ublox_msgs::msg::NavPVT7::_head_acc_type arg)
  {
    msg_.head_acc = std::move(arg);
    return Init_NavPVT7_p_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_s_acc
{
public:
  explicit Init_NavPVT7_s_acc(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_head_acc s_acc(::ublox_msgs::msg::NavPVT7::_s_acc_type arg)
  {
    msg_.s_acc = std::move(arg);
    return Init_NavPVT7_head_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_heading
{
public:
  explicit Init_NavPVT7_heading(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_s_acc heading(::ublox_msgs::msg::NavPVT7::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_NavPVT7_s_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_g_speed
{
public:
  explicit Init_NavPVT7_g_speed(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_heading g_speed(::ublox_msgs::msg::NavPVT7::_g_speed_type arg)
  {
    msg_.g_speed = std::move(arg);
    return Init_NavPVT7_heading(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_vel_d
{
public:
  explicit Init_NavPVT7_vel_d(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_g_speed vel_d(::ublox_msgs::msg::NavPVT7::_vel_d_type arg)
  {
    msg_.vel_d = std::move(arg);
    return Init_NavPVT7_g_speed(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_vel_e
{
public:
  explicit Init_NavPVT7_vel_e(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_vel_d vel_e(::ublox_msgs::msg::NavPVT7::_vel_e_type arg)
  {
    msg_.vel_e = std::move(arg);
    return Init_NavPVT7_vel_d(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_vel_n
{
public:
  explicit Init_NavPVT7_vel_n(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_vel_e vel_n(::ublox_msgs::msg::NavPVT7::_vel_n_type arg)
  {
    msg_.vel_n = std::move(arg);
    return Init_NavPVT7_vel_e(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_v_acc
{
public:
  explicit Init_NavPVT7_v_acc(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_vel_n v_acc(::ublox_msgs::msg::NavPVT7::_v_acc_type arg)
  {
    msg_.v_acc = std::move(arg);
    return Init_NavPVT7_vel_n(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_h_acc
{
public:
  explicit Init_NavPVT7_h_acc(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_v_acc h_acc(::ublox_msgs::msg::NavPVT7::_h_acc_type arg)
  {
    msg_.h_acc = std::move(arg);
    return Init_NavPVT7_v_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_h_msl
{
public:
  explicit Init_NavPVT7_h_msl(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_h_acc h_msl(::ublox_msgs::msg::NavPVT7::_h_msl_type arg)
  {
    msg_.h_msl = std::move(arg);
    return Init_NavPVT7_h_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_height
{
public:
  explicit Init_NavPVT7_height(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_h_msl height(::ublox_msgs::msg::NavPVT7::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_NavPVT7_h_msl(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_lat
{
public:
  explicit Init_NavPVT7_lat(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_height lat(::ublox_msgs::msg::NavPVT7::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_NavPVT7_height(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_lon
{
public:
  explicit Init_NavPVT7_lon(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_lat lon(::ublox_msgs::msg::NavPVT7::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_NavPVT7_lat(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_num_sv
{
public:
  explicit Init_NavPVT7_num_sv(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_lon num_sv(::ublox_msgs::msg::NavPVT7::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_NavPVT7_lon(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_flags2
{
public:
  explicit Init_NavPVT7_flags2(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_num_sv flags2(::ublox_msgs::msg::NavPVT7::_flags2_type arg)
  {
    msg_.flags2 = std::move(arg);
    return Init_NavPVT7_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_flags
{
public:
  explicit Init_NavPVT7_flags(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_flags2 flags(::ublox_msgs::msg::NavPVT7::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_NavPVT7_flags2(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_fix_type
{
public:
  explicit Init_NavPVT7_fix_type(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_flags fix_type(::ublox_msgs::msg::NavPVT7::_fix_type_type arg)
  {
    msg_.fix_type = std::move(arg);
    return Init_NavPVT7_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_nano
{
public:
  explicit Init_NavPVT7_nano(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_fix_type nano(::ublox_msgs::msg::NavPVT7::_nano_type arg)
  {
    msg_.nano = std::move(arg);
    return Init_NavPVT7_fix_type(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_t_acc
{
public:
  explicit Init_NavPVT7_t_acc(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_nano t_acc(::ublox_msgs::msg::NavPVT7::_t_acc_type arg)
  {
    msg_.t_acc = std::move(arg);
    return Init_NavPVT7_nano(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_valid
{
public:
  explicit Init_NavPVT7_valid(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_t_acc valid(::ublox_msgs::msg::NavPVT7::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_NavPVT7_t_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_sec
{
public:
  explicit Init_NavPVT7_sec(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_valid sec(::ublox_msgs::msg::NavPVT7::_sec_type arg)
  {
    msg_.sec = std::move(arg);
    return Init_NavPVT7_valid(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_min
{
public:
  explicit Init_NavPVT7_min(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_sec min(::ublox_msgs::msg::NavPVT7::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_NavPVT7_sec(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_hour
{
public:
  explicit Init_NavPVT7_hour(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_min hour(::ublox_msgs::msg::NavPVT7::_hour_type arg)
  {
    msg_.hour = std::move(arg);
    return Init_NavPVT7_min(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_day
{
public:
  explicit Init_NavPVT7_day(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_hour day(::ublox_msgs::msg::NavPVT7::_day_type arg)
  {
    msg_.day = std::move(arg);
    return Init_NavPVT7_hour(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_month
{
public:
  explicit Init_NavPVT7_month(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_day month(::ublox_msgs::msg::NavPVT7::_month_type arg)
  {
    msg_.month = std::move(arg);
    return Init_NavPVT7_day(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_year
{
public:
  explicit Init_NavPVT7_year(::ublox_msgs::msg::NavPVT7 & msg)
  : msg_(msg)
  {}
  Init_NavPVT7_month year(::ublox_msgs::msg::NavPVT7::_year_type arg)
  {
    msg_.year = std::move(arg);
    return Init_NavPVT7_month(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

class Init_NavPVT7_i_tow
{
public:
  Init_NavPVT7_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavPVT7_year i_tow(::ublox_msgs::msg::NavPVT7::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavPVT7_year(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT7 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavPVT7>()
{
  return ublox_msgs::msg::builder::Init_NavPVT7_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__BUILDER_HPP_

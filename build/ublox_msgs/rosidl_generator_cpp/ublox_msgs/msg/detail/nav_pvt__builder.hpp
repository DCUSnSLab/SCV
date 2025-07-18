// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavPVT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_PVT__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_PVT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_pvt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavPVT_mag_acc
{
public:
  explicit Init_NavPVT_mag_acc(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavPVT mag_acc(::ublox_msgs::msg::NavPVT::_mag_acc_type arg)
  {
    msg_.mag_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_mag_dec
{
public:
  explicit Init_NavPVT_mag_dec(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_mag_acc mag_dec(::ublox_msgs::msg::NavPVT::_mag_dec_type arg)
  {
    msg_.mag_dec = std::move(arg);
    return Init_NavPVT_mag_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_head_veh
{
public:
  explicit Init_NavPVT_head_veh(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_mag_dec head_veh(::ublox_msgs::msg::NavPVT::_head_veh_type arg)
  {
    msg_.head_veh = std::move(arg);
    return Init_NavPVT_mag_dec(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_reserved1
{
public:
  explicit Init_NavPVT_reserved1(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_head_veh reserved1(::ublox_msgs::msg::NavPVT::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_NavPVT_head_veh(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_p_dop
{
public:
  explicit Init_NavPVT_p_dop(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_reserved1 p_dop(::ublox_msgs::msg::NavPVT::_p_dop_type arg)
  {
    msg_.p_dop = std::move(arg);
    return Init_NavPVT_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_head_acc
{
public:
  explicit Init_NavPVT_head_acc(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_p_dop head_acc(::ublox_msgs::msg::NavPVT::_head_acc_type arg)
  {
    msg_.head_acc = std::move(arg);
    return Init_NavPVT_p_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_s_acc
{
public:
  explicit Init_NavPVT_s_acc(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_head_acc s_acc(::ublox_msgs::msg::NavPVT::_s_acc_type arg)
  {
    msg_.s_acc = std::move(arg);
    return Init_NavPVT_head_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_heading
{
public:
  explicit Init_NavPVT_heading(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_s_acc heading(::ublox_msgs::msg::NavPVT::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_NavPVT_s_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_g_speed
{
public:
  explicit Init_NavPVT_g_speed(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_heading g_speed(::ublox_msgs::msg::NavPVT::_g_speed_type arg)
  {
    msg_.g_speed = std::move(arg);
    return Init_NavPVT_heading(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_vel_d
{
public:
  explicit Init_NavPVT_vel_d(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_g_speed vel_d(::ublox_msgs::msg::NavPVT::_vel_d_type arg)
  {
    msg_.vel_d = std::move(arg);
    return Init_NavPVT_g_speed(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_vel_e
{
public:
  explicit Init_NavPVT_vel_e(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_vel_d vel_e(::ublox_msgs::msg::NavPVT::_vel_e_type arg)
  {
    msg_.vel_e = std::move(arg);
    return Init_NavPVT_vel_d(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_vel_n
{
public:
  explicit Init_NavPVT_vel_n(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_vel_e vel_n(::ublox_msgs::msg::NavPVT::_vel_n_type arg)
  {
    msg_.vel_n = std::move(arg);
    return Init_NavPVT_vel_e(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_v_acc
{
public:
  explicit Init_NavPVT_v_acc(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_vel_n v_acc(::ublox_msgs::msg::NavPVT::_v_acc_type arg)
  {
    msg_.v_acc = std::move(arg);
    return Init_NavPVT_vel_n(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_h_acc
{
public:
  explicit Init_NavPVT_h_acc(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_v_acc h_acc(::ublox_msgs::msg::NavPVT::_h_acc_type arg)
  {
    msg_.h_acc = std::move(arg);
    return Init_NavPVT_v_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_h_msl
{
public:
  explicit Init_NavPVT_h_msl(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_h_acc h_msl(::ublox_msgs::msg::NavPVT::_h_msl_type arg)
  {
    msg_.h_msl = std::move(arg);
    return Init_NavPVT_h_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_height
{
public:
  explicit Init_NavPVT_height(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_h_msl height(::ublox_msgs::msg::NavPVT::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_NavPVT_h_msl(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_lat
{
public:
  explicit Init_NavPVT_lat(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_height lat(::ublox_msgs::msg::NavPVT::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_NavPVT_height(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_lon
{
public:
  explicit Init_NavPVT_lon(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_lat lon(::ublox_msgs::msg::NavPVT::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_NavPVT_lat(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_num_sv
{
public:
  explicit Init_NavPVT_num_sv(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_lon num_sv(::ublox_msgs::msg::NavPVT::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_NavPVT_lon(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_flags2
{
public:
  explicit Init_NavPVT_flags2(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_num_sv flags2(::ublox_msgs::msg::NavPVT::_flags2_type arg)
  {
    msg_.flags2 = std::move(arg);
    return Init_NavPVT_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_flags
{
public:
  explicit Init_NavPVT_flags(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_flags2 flags(::ublox_msgs::msg::NavPVT::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_NavPVT_flags2(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_fix_type
{
public:
  explicit Init_NavPVT_fix_type(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_flags fix_type(::ublox_msgs::msg::NavPVT::_fix_type_type arg)
  {
    msg_.fix_type = std::move(arg);
    return Init_NavPVT_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_nano
{
public:
  explicit Init_NavPVT_nano(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_fix_type nano(::ublox_msgs::msg::NavPVT::_nano_type arg)
  {
    msg_.nano = std::move(arg);
    return Init_NavPVT_fix_type(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_t_acc
{
public:
  explicit Init_NavPVT_t_acc(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_nano t_acc(::ublox_msgs::msg::NavPVT::_t_acc_type arg)
  {
    msg_.t_acc = std::move(arg);
    return Init_NavPVT_nano(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_valid
{
public:
  explicit Init_NavPVT_valid(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_t_acc valid(::ublox_msgs::msg::NavPVT::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_NavPVT_t_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_sec
{
public:
  explicit Init_NavPVT_sec(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_valid sec(::ublox_msgs::msg::NavPVT::_sec_type arg)
  {
    msg_.sec = std::move(arg);
    return Init_NavPVT_valid(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_min
{
public:
  explicit Init_NavPVT_min(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_sec min(::ublox_msgs::msg::NavPVT::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_NavPVT_sec(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_hour
{
public:
  explicit Init_NavPVT_hour(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_min hour(::ublox_msgs::msg::NavPVT::_hour_type arg)
  {
    msg_.hour = std::move(arg);
    return Init_NavPVT_min(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_day
{
public:
  explicit Init_NavPVT_day(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_hour day(::ublox_msgs::msg::NavPVT::_day_type arg)
  {
    msg_.day = std::move(arg);
    return Init_NavPVT_hour(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_month
{
public:
  explicit Init_NavPVT_month(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_day month(::ublox_msgs::msg::NavPVT::_month_type arg)
  {
    msg_.month = std::move(arg);
    return Init_NavPVT_day(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_year
{
public:
  explicit Init_NavPVT_year(::ublox_msgs::msg::NavPVT & msg)
  : msg_(msg)
  {}
  Init_NavPVT_month year(::ublox_msgs::msg::NavPVT::_year_type arg)
  {
    msg_.year = std::move(arg);
    return Init_NavPVT_month(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

class Init_NavPVT_i_tow
{
public:
  Init_NavPVT_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavPVT_year i_tow(::ublox_msgs::msg::NavPVT::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavPVT_year(msg_);
  }

private:
  ::ublox_msgs::msg::NavPVT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavPVT>()
{
  return ublox_msgs::msg::builder::Init_NavPVT_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_PVT__BUILDER_HPP_

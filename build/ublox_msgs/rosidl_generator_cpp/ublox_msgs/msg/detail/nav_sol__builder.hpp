// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavSOL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SOL__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_sol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavSOL_reserved2
{
public:
  explicit Init_NavSOL_reserved2(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavSOL reserved2(::ublox_msgs::msg::NavSOL::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_num_sv
{
public:
  explicit Init_NavSOL_num_sv(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_reserved2 num_sv(::ublox_msgs::msg::NavSOL::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_NavSOL_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_reserved1
{
public:
  explicit Init_NavSOL_reserved1(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_num_sv reserved1(::ublox_msgs::msg::NavSOL::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_NavSOL_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_p_dop
{
public:
  explicit Init_NavSOL_p_dop(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_reserved1 p_dop(::ublox_msgs::msg::NavSOL::_p_dop_type arg)
  {
    msg_.p_dop = std::move(arg);
    return Init_NavSOL_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_s_acc
{
public:
  explicit Init_NavSOL_s_acc(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_p_dop s_acc(::ublox_msgs::msg::NavSOL::_s_acc_type arg)
  {
    msg_.s_acc = std::move(arg);
    return Init_NavSOL_p_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_ecef_vz
{
public:
  explicit Init_NavSOL_ecef_vz(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_s_acc ecef_vz(::ublox_msgs::msg::NavSOL::_ecef_vz_type arg)
  {
    msg_.ecef_vz = std::move(arg);
    return Init_NavSOL_s_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_ecef_vy
{
public:
  explicit Init_NavSOL_ecef_vy(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_ecef_vz ecef_vy(::ublox_msgs::msg::NavSOL::_ecef_vy_type arg)
  {
    msg_.ecef_vy = std::move(arg);
    return Init_NavSOL_ecef_vz(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_ecef_vx
{
public:
  explicit Init_NavSOL_ecef_vx(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_ecef_vy ecef_vx(::ublox_msgs::msg::NavSOL::_ecef_vx_type arg)
  {
    msg_.ecef_vx = std::move(arg);
    return Init_NavSOL_ecef_vy(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_p_acc
{
public:
  explicit Init_NavSOL_p_acc(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_ecef_vx p_acc(::ublox_msgs::msg::NavSOL::_p_acc_type arg)
  {
    msg_.p_acc = std::move(arg);
    return Init_NavSOL_ecef_vx(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_ecef_z
{
public:
  explicit Init_NavSOL_ecef_z(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_p_acc ecef_z(::ublox_msgs::msg::NavSOL::_ecef_z_type arg)
  {
    msg_.ecef_z = std::move(arg);
    return Init_NavSOL_p_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_ecef_y
{
public:
  explicit Init_NavSOL_ecef_y(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_ecef_z ecef_y(::ublox_msgs::msg::NavSOL::_ecef_y_type arg)
  {
    msg_.ecef_y = std::move(arg);
    return Init_NavSOL_ecef_z(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_ecef_x
{
public:
  explicit Init_NavSOL_ecef_x(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_ecef_y ecef_x(::ublox_msgs::msg::NavSOL::_ecef_x_type arg)
  {
    msg_.ecef_x = std::move(arg);
    return Init_NavSOL_ecef_y(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_flags
{
public:
  explicit Init_NavSOL_flags(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_ecef_x flags(::ublox_msgs::msg::NavSOL::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_NavSOL_ecef_x(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_gps_fix
{
public:
  explicit Init_NavSOL_gps_fix(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_flags gps_fix(::ublox_msgs::msg::NavSOL::_gps_fix_type arg)
  {
    msg_.gps_fix = std::move(arg);
    return Init_NavSOL_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_week
{
public:
  explicit Init_NavSOL_week(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_gps_fix week(::ublox_msgs::msg::NavSOL::_week_type arg)
  {
    msg_.week = std::move(arg);
    return Init_NavSOL_gps_fix(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_f_tow
{
public:
  explicit Init_NavSOL_f_tow(::ublox_msgs::msg::NavSOL & msg)
  : msg_(msg)
  {}
  Init_NavSOL_week f_tow(::ublox_msgs::msg::NavSOL::_f_tow_type arg)
  {
    msg_.f_tow = std::move(arg);
    return Init_NavSOL_week(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

class Init_NavSOL_i_tow
{
public:
  Init_NavSOL_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavSOL_f_tow i_tow(::ublox_msgs::msg::NavSOL::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavSOL_f_tow(msg_);
  }

private:
  ::ublox_msgs::msg::NavSOL msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavSOL>()
{
  return ublox_msgs::msg::builder::Init_NavSOL_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SOL__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_tmode3__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgTMODE3_reserved3
{
public:
  explicit Init_CfgTMODE3_reserved3(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgTMODE3 reserved3(::ublox_msgs::msg::CfgTMODE3::_reserved3_type arg)
  {
    msg_.reserved3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_svin_acc_limit
{
public:
  explicit Init_CfgTMODE3_svin_acc_limit(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_reserved3 svin_acc_limit(::ublox_msgs::msg::CfgTMODE3::_svin_acc_limit_type arg)
  {
    msg_.svin_acc_limit = std::move(arg);
    return Init_CfgTMODE3_reserved3(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_svin_min_dur
{
public:
  explicit Init_CfgTMODE3_svin_min_dur(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_svin_acc_limit svin_min_dur(::ublox_msgs::msg::CfgTMODE3::_svin_min_dur_type arg)
  {
    msg_.svin_min_dur = std::move(arg);
    return Init_CfgTMODE3_svin_acc_limit(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_fixed_pos_acc
{
public:
  explicit Init_CfgTMODE3_fixed_pos_acc(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_svin_min_dur fixed_pos_acc(::ublox_msgs::msg::CfgTMODE3::_fixed_pos_acc_type arg)
  {
    msg_.fixed_pos_acc = std::move(arg);
    return Init_CfgTMODE3_svin_min_dur(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_reserved2
{
public:
  explicit Init_CfgTMODE3_reserved2(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_fixed_pos_acc reserved2(::ublox_msgs::msg::CfgTMODE3::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return Init_CfgTMODE3_fixed_pos_acc(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_ecef_z_or_alt_hp
{
public:
  explicit Init_CfgTMODE3_ecef_z_or_alt_hp(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_reserved2 ecef_z_or_alt_hp(::ublox_msgs::msg::CfgTMODE3::_ecef_z_or_alt_hp_type arg)
  {
    msg_.ecef_z_or_alt_hp = std::move(arg);
    return Init_CfgTMODE3_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_ecef_y_or_lon_hp
{
public:
  explicit Init_CfgTMODE3_ecef_y_or_lon_hp(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_ecef_z_or_alt_hp ecef_y_or_lon_hp(::ublox_msgs::msg::CfgTMODE3::_ecef_y_or_lon_hp_type arg)
  {
    msg_.ecef_y_or_lon_hp = std::move(arg);
    return Init_CfgTMODE3_ecef_z_or_alt_hp(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_ecef_x_or_lat_hp
{
public:
  explicit Init_CfgTMODE3_ecef_x_or_lat_hp(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_ecef_y_or_lon_hp ecef_x_or_lat_hp(::ublox_msgs::msg::CfgTMODE3::_ecef_x_or_lat_hp_type arg)
  {
    msg_.ecef_x_or_lat_hp = std::move(arg);
    return Init_CfgTMODE3_ecef_y_or_lon_hp(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_ecef_z_or_alt
{
public:
  explicit Init_CfgTMODE3_ecef_z_or_alt(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_ecef_x_or_lat_hp ecef_z_or_alt(::ublox_msgs::msg::CfgTMODE3::_ecef_z_or_alt_type arg)
  {
    msg_.ecef_z_or_alt = std::move(arg);
    return Init_CfgTMODE3_ecef_x_or_lat_hp(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_ecef_y_or_lon
{
public:
  explicit Init_CfgTMODE3_ecef_y_or_lon(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_ecef_z_or_alt ecef_y_or_lon(::ublox_msgs::msg::CfgTMODE3::_ecef_y_or_lon_type arg)
  {
    msg_.ecef_y_or_lon = std::move(arg);
    return Init_CfgTMODE3_ecef_z_or_alt(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_ecef_x_or_lat
{
public:
  explicit Init_CfgTMODE3_ecef_x_or_lat(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_ecef_y_or_lon ecef_x_or_lat(::ublox_msgs::msg::CfgTMODE3::_ecef_x_or_lat_type arg)
  {
    msg_.ecef_x_or_lat = std::move(arg);
    return Init_CfgTMODE3_ecef_y_or_lon(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_flags
{
public:
  explicit Init_CfgTMODE3_flags(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_ecef_x_or_lat flags(::ublox_msgs::msg::CfgTMODE3::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_CfgTMODE3_ecef_x_or_lat(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_reserved1
{
public:
  explicit Init_CfgTMODE3_reserved1(::ublox_msgs::msg::CfgTMODE3 & msg)
  : msg_(msg)
  {}
  Init_CfgTMODE3_flags reserved1(::ublox_msgs::msg::CfgTMODE3::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_CfgTMODE3_flags(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

class Init_CfgTMODE3_version
{
public:
  Init_CfgTMODE3_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgTMODE3_reserved1 version(::ublox_msgs::msg::CfgTMODE3::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_CfgTMODE3_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgTMODE3 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgTMODE3>()
{
  return ublox_msgs::msg::builder::Init_CfgTMODE3_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__BUILDER_HPP_

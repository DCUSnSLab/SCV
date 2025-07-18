// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavRELPOSNED9.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED9__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED9__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_relposned9__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavRELPOSNED9_flags
{
public:
  explicit Init_NavRELPOSNED9_flags(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavRELPOSNED9 flags(::ublox_msgs::msg::NavRELPOSNED9::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_reserved3
{
public:
  explicit Init_NavRELPOSNED9_reserved3(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_flags reserved3(::ublox_msgs::msg::NavRELPOSNED9::_reserved3_type arg)
  {
    msg_.reserved3 = std::move(arg);
    return Init_NavRELPOSNED9_flags(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_acc_heading
{
public:
  explicit Init_NavRELPOSNED9_acc_heading(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_reserved3 acc_heading(::ublox_msgs::msg::NavRELPOSNED9::_acc_heading_type arg)
  {
    msg_.acc_heading = std::move(arg);
    return Init_NavRELPOSNED9_reserved3(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_acc_length
{
public:
  explicit Init_NavRELPOSNED9_acc_length(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_acc_heading acc_length(::ublox_msgs::msg::NavRELPOSNED9::_acc_length_type arg)
  {
    msg_.acc_length = std::move(arg);
    return Init_NavRELPOSNED9_acc_heading(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_acc_d
{
public:
  explicit Init_NavRELPOSNED9_acc_d(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_acc_length acc_d(::ublox_msgs::msg::NavRELPOSNED9::_acc_d_type arg)
  {
    msg_.acc_d = std::move(arg);
    return Init_NavRELPOSNED9_acc_length(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_acc_e
{
public:
  explicit Init_NavRELPOSNED9_acc_e(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_acc_d acc_e(::ublox_msgs::msg::NavRELPOSNED9::_acc_e_type arg)
  {
    msg_.acc_e = std::move(arg);
    return Init_NavRELPOSNED9_acc_d(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_acc_n
{
public:
  explicit Init_NavRELPOSNED9_acc_n(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_acc_e acc_n(::ublox_msgs::msg::NavRELPOSNED9::_acc_n_type arg)
  {
    msg_.acc_n = std::move(arg);
    return Init_NavRELPOSNED9_acc_e(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_hp_length
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_hp_length(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_acc_n rel_pos_hp_length(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_hp_length_type arg)
  {
    msg_.rel_pos_hp_length = std::move(arg);
    return Init_NavRELPOSNED9_acc_n(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_hpd
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_hpd(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_hp_length rel_pos_hpd(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_hpd_type arg)
  {
    msg_.rel_pos_hpd = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_hp_length(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_hpe
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_hpe(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_hpd rel_pos_hpe(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_hpe_type arg)
  {
    msg_.rel_pos_hpe = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_hpd(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_hpn
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_hpn(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_hpe rel_pos_hpn(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_hpn_type arg)
  {
    msg_.rel_pos_hpn = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_hpe(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_reserved2
{
public:
  explicit Init_NavRELPOSNED9_reserved2(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_hpn reserved2(::ublox_msgs::msg::NavRELPOSNED9::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_hpn(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_heading
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_heading(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_reserved2 rel_pos_heading(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_heading_type arg)
  {
    msg_.rel_pos_heading = std::move(arg);
    return Init_NavRELPOSNED9_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_length
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_length(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_heading rel_pos_length(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_length_type arg)
  {
    msg_.rel_pos_length = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_heading(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_d
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_d(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_length rel_pos_d(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_d_type arg)
  {
    msg_.rel_pos_d = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_length(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_e
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_e(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_d rel_pos_e(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_e_type arg)
  {
    msg_.rel_pos_e = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_d(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_rel_pos_n
{
public:
  explicit Init_NavRELPOSNED9_rel_pos_n(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_e rel_pos_n(::ublox_msgs::msg::NavRELPOSNED9::_rel_pos_n_type arg)
  {
    msg_.rel_pos_n = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_e(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_i_tow
{
public:
  explicit Init_NavRELPOSNED9_i_tow(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_rel_pos_n i_tow(::ublox_msgs::msg::NavRELPOSNED9::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavRELPOSNED9_rel_pos_n(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_ref_station_id
{
public:
  explicit Init_NavRELPOSNED9_ref_station_id(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_i_tow ref_station_id(::ublox_msgs::msg::NavRELPOSNED9::_ref_station_id_type arg)
  {
    msg_.ref_station_id = std::move(arg);
    return Init_NavRELPOSNED9_i_tow(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_reserved1
{
public:
  explicit Init_NavRELPOSNED9_reserved1(::ublox_msgs::msg::NavRELPOSNED9 & msg)
  : msg_(msg)
  {}
  Init_NavRELPOSNED9_ref_station_id reserved1(::ublox_msgs::msg::NavRELPOSNED9::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_NavRELPOSNED9_ref_station_id(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

class Init_NavRELPOSNED9_version
{
public:
  Init_NavRELPOSNED9_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavRELPOSNED9_reserved1 version(::ublox_msgs::msg::NavRELPOSNED9::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_NavRELPOSNED9_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::NavRELPOSNED9 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavRELPOSNED9>()
{
  return ublox_msgs::msg::builder::Init_NavRELPOSNED9_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED9__BUILDER_HPP_

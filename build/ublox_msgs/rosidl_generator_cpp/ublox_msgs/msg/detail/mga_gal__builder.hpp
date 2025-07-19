// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/MgaGAL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MGA_GAL__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MGA_GAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/mga_gal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_MgaGAL_reserved2
{
public:
  explicit Init_MgaGAL_reserved2(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::MgaGAL reserved2(::ublox_msgs::msg::MgaGAL::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_data_validity_e5b
{
public:
  explicit Init_MgaGAL_data_validity_e5b(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_reserved2 data_validity_e5b(::ublox_msgs::msg::MgaGAL::_data_validity_e5b_type arg)
  {
    msg_.data_validity_e5b = std::move(arg);
    return Init_MgaGAL_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_health_e5b
{
public:
  explicit Init_MgaGAL_health_e5b(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_data_validity_e5b health_e5b(::ublox_msgs::msg::MgaGAL::_health_e5b_type arg)
  {
    msg_.health_e5b = std::move(arg);
    return Init_MgaGAL_data_validity_e5b(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_data_validity_e1b
{
public:
  explicit Init_MgaGAL_data_validity_e1b(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_health_e5b data_validity_e1b(::ublox_msgs::msg::MgaGAL::_data_validity_e1b_type arg)
  {
    msg_.data_validity_e1b = std::move(arg);
    return Init_MgaGAL_health_e5b(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_health_e1b
{
public:
  explicit Init_MgaGAL_health_e1b(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_data_validity_e1b health_e1b(::ublox_msgs::msg::MgaGAL::_health_e1b_type arg)
  {
    msg_.health_e1b = std::move(arg);
    return Init_MgaGAL_data_validity_e1b(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_reserved1
{
public:
  explicit Init_MgaGAL_reserved1(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_health_e1b reserved1(::ublox_msgs::msg::MgaGAL::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_MgaGAL_health_e1b(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_bgd_e1_e5b
{
public:
  explicit Init_MgaGAL_bgd_e1_e5b(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_reserved1 bgd_e1_e5b(::ublox_msgs::msg::MgaGAL::_bgd_e1_e5b_type arg)
  {
    msg_.bgd_e1_e5b = std::move(arg);
    return Init_MgaGAL_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_toc
{
public:
  explicit Init_MgaGAL_toc(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_bgd_e1_e5b toc(::ublox_msgs::msg::MgaGAL::_toc_type arg)
  {
    msg_.toc = std::move(arg);
    return Init_MgaGAL_bgd_e1_e5b(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_sisaindex_e1_e5b
{
public:
  explicit Init_MgaGAL_sisaindex_e1_e5b(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_toc sisaindex_e1_e5b(::ublox_msgs::msg::MgaGAL::_sisaindex_e1_e5b_type arg)
  {
    msg_.sisaindex_e1_e5b = std::move(arg);
    return Init_MgaGAL_toc(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_af2
{
public:
  explicit Init_MgaGAL_af2(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_sisaindex_e1_e5b af2(::ublox_msgs::msg::MgaGAL::_af2_type arg)
  {
    msg_.af2 = std::move(arg);
    return Init_MgaGAL_sisaindex_e1_e5b(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_af1
{
public:
  explicit Init_MgaGAL_af1(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_af2 af1(::ublox_msgs::msg::MgaGAL::_af1_type arg)
  {
    msg_.af1 = std::move(arg);
    return Init_MgaGAL_af2(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_af0
{
public:
  explicit Init_MgaGAL_af0(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_af1 af0(::ublox_msgs::msg::MgaGAL::_af0_type arg)
  {
    msg_.af0 = std::move(arg);
    return Init_MgaGAL_af1(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_toe
{
public:
  explicit Init_MgaGAL_toe(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_af0 toe(::ublox_msgs::msg::MgaGAL::_toe_type arg)
  {
    msg_.toe = std::move(arg);
    return Init_MgaGAL_af0(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_cis
{
public:
  explicit Init_MgaGAL_cis(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_toe cis(::ublox_msgs::msg::MgaGAL::_cis_type arg)
  {
    msg_.cis = std::move(arg);
    return Init_MgaGAL_toe(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_cic
{
public:
  explicit Init_MgaGAL_cic(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_cis cic(::ublox_msgs::msg::MgaGAL::_cic_type arg)
  {
    msg_.cic = std::move(arg);
    return Init_MgaGAL_cis(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_crs
{
public:
  explicit Init_MgaGAL_crs(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_cic crs(::ublox_msgs::msg::MgaGAL::_crs_type arg)
  {
    msg_.crs = std::move(arg);
    return Init_MgaGAL_cic(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_crc
{
public:
  explicit Init_MgaGAL_crc(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_crs crc(::ublox_msgs::msg::MgaGAL::_crc_type arg)
  {
    msg_.crc = std::move(arg);
    return Init_MgaGAL_crs(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_cus
{
public:
  explicit Init_MgaGAL_cus(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_crc cus(::ublox_msgs::msg::MgaGAL::_cus_type arg)
  {
    msg_.cus = std::move(arg);
    return Init_MgaGAL_crc(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_cuc
{
public:
  explicit Init_MgaGAL_cuc(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_cus cuc(::ublox_msgs::msg::MgaGAL::_cuc_type arg)
  {
    msg_.cuc = std::move(arg);
    return Init_MgaGAL_cus(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_i_dot
{
public:
  explicit Init_MgaGAL_i_dot(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_cuc i_dot(::ublox_msgs::msg::MgaGAL::_i_dot_type arg)
  {
    msg_.i_dot = std::move(arg);
    return Init_MgaGAL_cuc(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_omega_dot
{
public:
  explicit Init_MgaGAL_omega_dot(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_i_dot omega_dot(::ublox_msgs::msg::MgaGAL::_omega_dot_type arg)
  {
    msg_.omega_dot = std::move(arg);
    return Init_MgaGAL_i_dot(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_omega
{
public:
  explicit Init_MgaGAL_omega(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_omega_dot omega(::ublox_msgs::msg::MgaGAL::_omega_type arg)
  {
    msg_.omega = std::move(arg);
    return Init_MgaGAL_omega_dot(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_i0
{
public:
  explicit Init_MgaGAL_i0(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_omega i0(::ublox_msgs::msg::MgaGAL::_i0_type arg)
  {
    msg_.i0 = std::move(arg);
    return Init_MgaGAL_omega(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_omega0
{
public:
  explicit Init_MgaGAL_omega0(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_i0 omega0(::ublox_msgs::msg::MgaGAL::_omega0_type arg)
  {
    msg_.omega0 = std::move(arg);
    return Init_MgaGAL_i0(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_sqrt_a
{
public:
  explicit Init_MgaGAL_sqrt_a(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_omega0 sqrt_a(::ublox_msgs::msg::MgaGAL::_sqrt_a_type arg)
  {
    msg_.sqrt_a = std::move(arg);
    return Init_MgaGAL_omega0(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_e
{
public:
  explicit Init_MgaGAL_e(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_sqrt_a e(::ublox_msgs::msg::MgaGAL::_e_type arg)
  {
    msg_.e = std::move(arg);
    return Init_MgaGAL_sqrt_a(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_m0
{
public:
  explicit Init_MgaGAL_m0(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_e m0(::ublox_msgs::msg::MgaGAL::_m0_type arg)
  {
    msg_.m0 = std::move(arg);
    return Init_MgaGAL_e(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_delta_n
{
public:
  explicit Init_MgaGAL_delta_n(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_m0 delta_n(::ublox_msgs::msg::MgaGAL::_delta_n_type arg)
  {
    msg_.delta_n = std::move(arg);
    return Init_MgaGAL_m0(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_iod_nav
{
public:
  explicit Init_MgaGAL_iod_nav(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_delta_n iod_nav(::ublox_msgs::msg::MgaGAL::_iod_nav_type arg)
  {
    msg_.iod_nav = std::move(arg);
    return Init_MgaGAL_delta_n(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_reserved0
{
public:
  explicit Init_MgaGAL_reserved0(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_iod_nav reserved0(::ublox_msgs::msg::MgaGAL::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_MgaGAL_iod_nav(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_svid
{
public:
  explicit Init_MgaGAL_svid(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_reserved0 svid(::ublox_msgs::msg::MgaGAL::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_MgaGAL_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_version
{
public:
  explicit Init_MgaGAL_version(::ublox_msgs::msg::MgaGAL & msg)
  : msg_(msg)
  {}
  Init_MgaGAL_svid version(::ublox_msgs::msg::MgaGAL::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_MgaGAL_svid(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

class Init_MgaGAL_type
{
public:
  Init_MgaGAL_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MgaGAL_version type(::ublox_msgs::msg::MgaGAL::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_MgaGAL_version(msg_);
  }

private:
  ::ublox_msgs::msg::MgaGAL msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::MgaGAL>()
{
  return ublox_msgs::msg::builder::Init_MgaGAL_type();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MGA_GAL__BUILDER_HPP_

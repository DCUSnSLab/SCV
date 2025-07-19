// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_navx5__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgNAVX5_use_adr
{
public:
  explicit Init_CfgNAVX5_use_adr(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgNAVX5 use_adr(::ublox_msgs::msg::CfgNAVX5::_use_adr_type arg)
  {
    msg_.use_adr = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_reserved6
{
public:
  explicit Init_CfgNAVX5_reserved6(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_use_adr reserved6(::ublox_msgs::msg::CfgNAVX5::_reserved6_type arg)
  {
    msg_.reserved6 = std::move(arg);
    return Init_CfgNAVX5_use_adr(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_aop_orb_max_err
{
public:
  explicit Init_CfgNAVX5_aop_orb_max_err(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_reserved6 aop_orb_max_err(::ublox_msgs::msg::CfgNAVX5::_aop_orb_max_err_type arg)
  {
    msg_.aop_orb_max_err = std::move(arg);
    return Init_CfgNAVX5_reserved6(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_reserved5
{
public:
  explicit Init_CfgNAVX5_reserved5(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_aop_orb_max_err reserved5(::ublox_msgs::msg::CfgNAVX5::_reserved5_type arg)
  {
    msg_.reserved5 = std::move(arg);
    return Init_CfgNAVX5_aop_orb_max_err(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_aop_cfg
{
public:
  explicit Init_CfgNAVX5_aop_cfg(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_reserved5 aop_cfg(::ublox_msgs::msg::CfgNAVX5::_aop_cfg_type arg)
  {
    msg_.aop_cfg = std::move(arg);
    return Init_CfgNAVX5_reserved5(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_use_ppp
{
public:
  explicit Init_CfgNAVX5_use_ppp(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_aop_cfg use_ppp(::ublox_msgs::msg::CfgNAVX5::_use_ppp_type arg)
  {
    msg_.use_ppp = std::move(arg);
    return Init_CfgNAVX5_aop_cfg(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_reserved4
{
public:
  explicit Init_CfgNAVX5_reserved4(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_use_ppp reserved4(::ublox_msgs::msg::CfgNAVX5::_reserved4_type arg)
  {
    msg_.reserved4 = std::move(arg);
    return Init_CfgNAVX5_use_ppp(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_sig_atten_comp_mode
{
public:
  explicit Init_CfgNAVX5_sig_atten_comp_mode(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_reserved4 sig_atten_comp_mode(::ublox_msgs::msg::CfgNAVX5::_sig_atten_comp_mode_type arg)
  {
    msg_.sig_atten_comp_mode = std::move(arg);
    return Init_CfgNAVX5_reserved4(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_wkn_rollover
{
public:
  explicit Init_CfgNAVX5_wkn_rollover(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_sig_atten_comp_mode wkn_rollover(::ublox_msgs::msg::CfgNAVX5::_wkn_rollover_type arg)
  {
    msg_.wkn_rollover = std::move(arg);
    return Init_CfgNAVX5_sig_atten_comp_mode(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_ack_aiding
{
public:
  explicit Init_CfgNAVX5_ack_aiding(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_wkn_rollover ack_aiding(::ublox_msgs::msg::CfgNAVX5::_ack_aiding_type arg)
  {
    msg_.ack_aiding = std::move(arg);
    return Init_CfgNAVX5_wkn_rollover(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_reserved3
{
public:
  explicit Init_CfgNAVX5_reserved3(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_ack_aiding reserved3(::ublox_msgs::msg::CfgNAVX5::_reserved3_type arg)
  {
    msg_.reserved3 = std::move(arg);
    return Init_CfgNAVX5_ack_aiding(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_ini_fix3d
{
public:
  explicit Init_CfgNAVX5_ini_fix3d(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_reserved3 ini_fix3d(::ublox_msgs::msg::CfgNAVX5::_ini_fix3d_type arg)
  {
    msg_.ini_fix3d = std::move(arg);
    return Init_CfgNAVX5_reserved3(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_reserved2
{
public:
  explicit Init_CfgNAVX5_reserved2(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_ini_fix3d reserved2(::ublox_msgs::msg::CfgNAVX5::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return Init_CfgNAVX5_ini_fix3d(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_min_cno
{
public:
  explicit Init_CfgNAVX5_min_cno(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_reserved2 min_cno(::ublox_msgs::msg::CfgNAVX5::_min_cno_type arg)
  {
    msg_.min_cno = std::move(arg);
    return Init_CfgNAVX5_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_max_svs
{
public:
  explicit Init_CfgNAVX5_max_svs(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_min_cno max_svs(::ublox_msgs::msg::CfgNAVX5::_max_svs_type arg)
  {
    msg_.max_svs = std::move(arg);
    return Init_CfgNAVX5_min_cno(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_min_svs
{
public:
  explicit Init_CfgNAVX5_min_svs(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_max_svs min_svs(::ublox_msgs::msg::CfgNAVX5::_min_svs_type arg)
  {
    msg_.min_svs = std::move(arg);
    return Init_CfgNAVX5_max_svs(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_reserved1
{
public:
  explicit Init_CfgNAVX5_reserved1(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_min_svs reserved1(::ublox_msgs::msg::CfgNAVX5::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_CfgNAVX5_min_svs(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_mask2
{
public:
  explicit Init_CfgNAVX5_mask2(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_reserved1 mask2(::ublox_msgs::msg::CfgNAVX5::_mask2_type arg)
  {
    msg_.mask2 = std::move(arg);
    return Init_CfgNAVX5_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_mask1
{
public:
  explicit Init_CfgNAVX5_mask1(::ublox_msgs::msg::CfgNAVX5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAVX5_mask2 mask1(::ublox_msgs::msg::CfgNAVX5::_mask1_type arg)
  {
    msg_.mask1 = std::move(arg);
    return Init_CfgNAVX5_mask2(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

class Init_CfgNAVX5_version
{
public:
  Init_CfgNAVX5_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgNAVX5_mask1 version(::ublox_msgs::msg::CfgNAVX5::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_CfgNAVX5_mask1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAVX5 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgNAVX5>()
{
  return ublox_msgs::msg::builder::Init_CfgNAVX5_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__BUILDER_HPP_

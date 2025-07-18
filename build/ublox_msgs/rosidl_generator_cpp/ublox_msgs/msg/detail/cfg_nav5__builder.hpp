// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgNAV5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_nav5__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgNAV5_reserved2
{
public:
  explicit Init_CfgNAV5_reserved2(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgNAV5 reserved2(::ublox_msgs::msg::CfgNAV5::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_utc_standard
{
public:
  explicit Init_CfgNAV5_utc_standard(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_reserved2 utc_standard(::ublox_msgs::msg::CfgNAV5::_utc_standard_type arg)
  {
    msg_.utc_standard = std::move(arg);
    return Init_CfgNAV5_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_static_hold_max_dist
{
public:
  explicit Init_CfgNAV5_static_hold_max_dist(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_utc_standard static_hold_max_dist(::ublox_msgs::msg::CfgNAV5::_static_hold_max_dist_type arg)
  {
    msg_.static_hold_max_dist = std::move(arg);
    return Init_CfgNAV5_utc_standard(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_reserved1
{
public:
  explicit Init_CfgNAV5_reserved1(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_static_hold_max_dist reserved1(::ublox_msgs::msg::CfgNAV5::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_CfgNAV5_static_hold_max_dist(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_cno_thresh
{
public:
  explicit Init_CfgNAV5_cno_thresh(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_reserved1 cno_thresh(::ublox_msgs::msg::CfgNAV5::_cno_thresh_type arg)
  {
    msg_.cno_thresh = std::move(arg);
    return Init_CfgNAV5_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_cno_thresh_num_svs
{
public:
  explicit Init_CfgNAV5_cno_thresh_num_svs(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_cno_thresh cno_thresh_num_svs(::ublox_msgs::msg::CfgNAV5::_cno_thresh_num_svs_type arg)
  {
    msg_.cno_thresh_num_svs = std::move(arg);
    return Init_CfgNAV5_cno_thresh(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_dgnss_time_out
{
public:
  explicit Init_CfgNAV5_dgnss_time_out(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_cno_thresh_num_svs dgnss_time_out(::ublox_msgs::msg::CfgNAV5::_dgnss_time_out_type arg)
  {
    msg_.dgnss_time_out = std::move(arg);
    return Init_CfgNAV5_cno_thresh_num_svs(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_static_hold_thresh
{
public:
  explicit Init_CfgNAV5_static_hold_thresh(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_dgnss_time_out static_hold_thresh(::ublox_msgs::msg::CfgNAV5::_static_hold_thresh_type arg)
  {
    msg_.static_hold_thresh = std::move(arg);
    return Init_CfgNAV5_dgnss_time_out(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_t_acc
{
public:
  explicit Init_CfgNAV5_t_acc(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_static_hold_thresh t_acc(::ublox_msgs::msg::CfgNAV5::_t_acc_type arg)
  {
    msg_.t_acc = std::move(arg);
    return Init_CfgNAV5_static_hold_thresh(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_p_acc
{
public:
  explicit Init_CfgNAV5_p_acc(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_t_acc p_acc(::ublox_msgs::msg::CfgNAV5::_p_acc_type arg)
  {
    msg_.p_acc = std::move(arg);
    return Init_CfgNAV5_t_acc(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_t_dop
{
public:
  explicit Init_CfgNAV5_t_dop(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_p_acc t_dop(::ublox_msgs::msg::CfgNAV5::_t_dop_type arg)
  {
    msg_.t_dop = std::move(arg);
    return Init_CfgNAV5_p_acc(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_p_dop
{
public:
  explicit Init_CfgNAV5_p_dop(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_t_dop p_dop(::ublox_msgs::msg::CfgNAV5::_p_dop_type arg)
  {
    msg_.p_dop = std::move(arg);
    return Init_CfgNAV5_t_dop(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_dr_limit
{
public:
  explicit Init_CfgNAV5_dr_limit(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_p_dop dr_limit(::ublox_msgs::msg::CfgNAV5::_dr_limit_type arg)
  {
    msg_.dr_limit = std::move(arg);
    return Init_CfgNAV5_p_dop(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_min_elev
{
public:
  explicit Init_CfgNAV5_min_elev(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_dr_limit min_elev(::ublox_msgs::msg::CfgNAV5::_min_elev_type arg)
  {
    msg_.min_elev = std::move(arg);
    return Init_CfgNAV5_dr_limit(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_fixed_alt_var
{
public:
  explicit Init_CfgNAV5_fixed_alt_var(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_min_elev fixed_alt_var(::ublox_msgs::msg::CfgNAV5::_fixed_alt_var_type arg)
  {
    msg_.fixed_alt_var = std::move(arg);
    return Init_CfgNAV5_min_elev(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_fixed_alt
{
public:
  explicit Init_CfgNAV5_fixed_alt(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_fixed_alt_var fixed_alt(::ublox_msgs::msg::CfgNAV5::_fixed_alt_type arg)
  {
    msg_.fixed_alt = std::move(arg);
    return Init_CfgNAV5_fixed_alt_var(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_fix_mode
{
public:
  explicit Init_CfgNAV5_fix_mode(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_fixed_alt fix_mode(::ublox_msgs::msg::CfgNAV5::_fix_mode_type arg)
  {
    msg_.fix_mode = std::move(arg);
    return Init_CfgNAV5_fixed_alt(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_dyn_model
{
public:
  explicit Init_CfgNAV5_dyn_model(::ublox_msgs::msg::CfgNAV5 & msg)
  : msg_(msg)
  {}
  Init_CfgNAV5_fix_mode dyn_model(::ublox_msgs::msg::CfgNAV5::_dyn_model_type arg)
  {
    msg_.dyn_model = std::move(arg);
    return Init_CfgNAV5_fix_mode(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

class Init_CfgNAV5_mask
{
public:
  Init_CfgNAV5_mask()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgNAV5_dyn_model mask(::ublox_msgs::msg::CfgNAV5::_mask_type arg)
  {
    msg_.mask = std::move(arg);
    return Init_CfgNAV5_dyn_model(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNAV5 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgNAV5>()
{
  return ublox_msgs::msg::builder::Init_CfgNAV5_mask();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/TimTM2.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__TIM_TM2__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__TIM_TM2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/tim_tm2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_TimTM2_acc_est
{
public:
  explicit Init_TimTM2_acc_est(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::TimTM2 acc_est(::ublox_msgs::msg::TimTM2::_acc_est_type arg)
  {
    msg_.acc_est = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_tow_sub_ms_f
{
public:
  explicit Init_TimTM2_tow_sub_ms_f(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_acc_est tow_sub_ms_f(::ublox_msgs::msg::TimTM2::_tow_sub_ms_f_type arg)
  {
    msg_.tow_sub_ms_f = std::move(arg);
    return Init_TimTM2_acc_est(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_tow_ms_f
{
public:
  explicit Init_TimTM2_tow_ms_f(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_tow_sub_ms_f tow_ms_f(::ublox_msgs::msg::TimTM2::_tow_ms_f_type arg)
  {
    msg_.tow_ms_f = std::move(arg);
    return Init_TimTM2_tow_sub_ms_f(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_tow_sub_ms_r
{
public:
  explicit Init_TimTM2_tow_sub_ms_r(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_tow_ms_f tow_sub_ms_r(::ublox_msgs::msg::TimTM2::_tow_sub_ms_r_type arg)
  {
    msg_.tow_sub_ms_r = std::move(arg);
    return Init_TimTM2_tow_ms_f(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_tow_ms_r
{
public:
  explicit Init_TimTM2_tow_ms_r(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_tow_sub_ms_r tow_ms_r(::ublox_msgs::msg::TimTM2::_tow_ms_r_type arg)
  {
    msg_.tow_ms_r = std::move(arg);
    return Init_TimTM2_tow_sub_ms_r(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_wn_f
{
public:
  explicit Init_TimTM2_wn_f(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_tow_ms_r wn_f(::ublox_msgs::msg::TimTM2::_wn_f_type arg)
  {
    msg_.wn_f = std::move(arg);
    return Init_TimTM2_tow_ms_r(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_wn_r
{
public:
  explicit Init_TimTM2_wn_r(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_wn_f wn_r(::ublox_msgs::msg::TimTM2::_wn_r_type arg)
  {
    msg_.wn_r = std::move(arg);
    return Init_TimTM2_wn_f(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_rising_edge_count
{
public:
  explicit Init_TimTM2_rising_edge_count(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_wn_r rising_edge_count(::ublox_msgs::msg::TimTM2::_rising_edge_count_type arg)
  {
    msg_.rising_edge_count = std::move(arg);
    return Init_TimTM2_wn_r(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_flags
{
public:
  explicit Init_TimTM2_flags(::ublox_msgs::msg::TimTM2 & msg)
  : msg_(msg)
  {}
  Init_TimTM2_rising_edge_count flags(::ublox_msgs::msg::TimTM2::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_TimTM2_rising_edge_count(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

class Init_TimTM2_ch
{
public:
  Init_TimTM2_ch()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TimTM2_flags ch(::ublox_msgs::msg::TimTM2::_ch_type arg)
  {
    msg_.ch = std::move(arg);
    return Init_TimTM2_flags(msg_);
  }

private:
  ::ublox_msgs::msg::TimTM2 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::TimTM2>()
{
  return ublox_msgs::msg::builder::Init_TimTM2_ch();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__TIM_TM2__BUILDER_HPP_

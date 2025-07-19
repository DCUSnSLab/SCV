// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/MonHW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_HW__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_HW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/mon_hw__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_MonHW_pull_l
{
public:
  explicit Init_MonHW_pull_l(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::MonHW pull_l(::ublox_msgs::msg::MonHW::_pull_l_type arg)
  {
    msg_.pull_l = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_pull_h
{
public:
  explicit Init_MonHW_pull_h(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_pull_l pull_h(::ublox_msgs::msg::MonHW::_pull_h_type arg)
  {
    msg_.pull_h = std::move(arg);
    return Init_MonHW_pull_l(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_pin_irq
{
public:
  explicit Init_MonHW_pin_irq(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_pull_h pin_irq(::ublox_msgs::msg::MonHW::_pin_irq_type arg)
  {
    msg_.pin_irq = std::move(arg);
    return Init_MonHW_pull_h(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_reserved1
{
public:
  explicit Init_MonHW_reserved1(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_pin_irq reserved1(::ublox_msgs::msg::MonHW::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_MonHW_pin_irq(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_jam_ind
{
public:
  explicit Init_MonHW_jam_ind(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_reserved1 jam_ind(::ublox_msgs::msg::MonHW::_jam_ind_type arg)
  {
    msg_.jam_ind = std::move(arg);
    return Init_MonHW_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_vp
{
public:
  explicit Init_MonHW_vp(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_jam_ind vp(::ublox_msgs::msg::MonHW::_vp_type arg)
  {
    msg_.vp = std::move(arg);
    return Init_MonHW_jam_ind(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_used_mask
{
public:
  explicit Init_MonHW_used_mask(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_vp used_mask(::ublox_msgs::msg::MonHW::_used_mask_type arg)
  {
    msg_.used_mask = std::move(arg);
    return Init_MonHW_vp(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_reserved0
{
public:
  explicit Init_MonHW_reserved0(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_used_mask reserved0(::ublox_msgs::msg::MonHW::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_MonHW_used_mask(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_flags
{
public:
  explicit Init_MonHW_flags(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_reserved0 flags(::ublox_msgs::msg::MonHW::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_MonHW_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_a_power
{
public:
  explicit Init_MonHW_a_power(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_flags a_power(::ublox_msgs::msg::MonHW::_a_power_type arg)
  {
    msg_.a_power = std::move(arg);
    return Init_MonHW_flags(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_a_status
{
public:
  explicit Init_MonHW_a_status(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_a_power a_status(::ublox_msgs::msg::MonHW::_a_status_type arg)
  {
    msg_.a_status = std::move(arg);
    return Init_MonHW_a_power(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_agc_cnt
{
public:
  explicit Init_MonHW_agc_cnt(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_a_status agc_cnt(::ublox_msgs::msg::MonHW::_agc_cnt_type arg)
  {
    msg_.agc_cnt = std::move(arg);
    return Init_MonHW_a_status(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_noise_per_ms
{
public:
  explicit Init_MonHW_noise_per_ms(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_agc_cnt noise_per_ms(::ublox_msgs::msg::MonHW::_noise_per_ms_type arg)
  {
    msg_.noise_per_ms = std::move(arg);
    return Init_MonHW_agc_cnt(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_pin_val
{
public:
  explicit Init_MonHW_pin_val(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_noise_per_ms pin_val(::ublox_msgs::msg::MonHW::_pin_val_type arg)
  {
    msg_.pin_val = std::move(arg);
    return Init_MonHW_noise_per_ms(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_pin_dir
{
public:
  explicit Init_MonHW_pin_dir(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_pin_val pin_dir(::ublox_msgs::msg::MonHW::_pin_dir_type arg)
  {
    msg_.pin_dir = std::move(arg);
    return Init_MonHW_pin_val(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_pin_bank
{
public:
  explicit Init_MonHW_pin_bank(::ublox_msgs::msg::MonHW & msg)
  : msg_(msg)
  {}
  Init_MonHW_pin_dir pin_bank(::ublox_msgs::msg::MonHW::_pin_bank_type arg)
  {
    msg_.pin_bank = std::move(arg);
    return Init_MonHW_pin_dir(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

class Init_MonHW_pin_sel
{
public:
  Init_MonHW_pin_sel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MonHW_pin_bank pin_sel(::ublox_msgs::msg::MonHW::_pin_sel_type arg)
  {
    msg_.pin_sel = std::move(arg);
    return Init_MonHW_pin_bank(msg_);
  }

private:
  ::ublox_msgs::msg::MonHW msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::MonHW>()
{
  return ublox_msgs::msg::builder::Init_MonHW_pin_sel();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_HW__BUILDER_HPP_

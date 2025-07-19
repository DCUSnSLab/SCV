// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hunter_msgs:msg/HunterRCState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_RC_STATE__BUILDER_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_RC_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hunter_msgs/msg/detail/hunter_rc_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hunter_msgs
{

namespace msg
{

namespace builder
{

class Init_HunterRCState_var_a
{
public:
  explicit Init_HunterRCState_var_a(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  ::hunter_msgs::msg::HunterRCState var_a(::hunter_msgs::msg::HunterRCState::_var_a_type arg)
  {
    msg_.var_a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_stick_left_h
{
public:
  explicit Init_HunterRCState_stick_left_h(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  Init_HunterRCState_var_a stick_left_h(::hunter_msgs::msg::HunterRCState::_stick_left_h_type arg)
  {
    msg_.stick_left_h = std::move(arg);
    return Init_HunterRCState_var_a(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_stick_left_v
{
public:
  explicit Init_HunterRCState_stick_left_v(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  Init_HunterRCState_stick_left_h stick_left_v(::hunter_msgs::msg::HunterRCState::_stick_left_v_type arg)
  {
    msg_.stick_left_v = std::move(arg);
    return Init_HunterRCState_stick_left_h(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_stick_right_h
{
public:
  explicit Init_HunterRCState_stick_right_h(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  Init_HunterRCState_stick_left_v stick_right_h(::hunter_msgs::msg::HunterRCState::_stick_right_h_type arg)
  {
    msg_.stick_right_h = std::move(arg);
    return Init_HunterRCState_stick_left_v(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_stick_right_v
{
public:
  explicit Init_HunterRCState_stick_right_v(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  Init_HunterRCState_stick_right_h stick_right_v(::hunter_msgs::msg::HunterRCState::_stick_right_v_type arg)
  {
    msg_.stick_right_v = std::move(arg);
    return Init_HunterRCState_stick_right_h(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_swd
{
public:
  explicit Init_HunterRCState_swd(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  Init_HunterRCState_stick_right_v swd(::hunter_msgs::msg::HunterRCState::_swd_type arg)
  {
    msg_.swd = std::move(arg);
    return Init_HunterRCState_stick_right_v(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_swc
{
public:
  explicit Init_HunterRCState_swc(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  Init_HunterRCState_swd swc(::hunter_msgs::msg::HunterRCState::_swc_type arg)
  {
    msg_.swc = std::move(arg);
    return Init_HunterRCState_swd(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_swb
{
public:
  explicit Init_HunterRCState_swb(::hunter_msgs::msg::HunterRCState & msg)
  : msg_(msg)
  {}
  Init_HunterRCState_swc swb(::hunter_msgs::msg::HunterRCState::_swb_type arg)
  {
    msg_.swb = std::move(arg);
    return Init_HunterRCState_swc(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

class Init_HunterRCState_swa
{
public:
  Init_HunterRCState_swa()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HunterRCState_swb swa(::hunter_msgs::msg::HunterRCState::_swa_type arg)
  {
    msg_.swa = std::move(arg);
    return Init_HunterRCState_swb(msg_);
  }

private:
  ::hunter_msgs::msg::HunterRCState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hunter_msgs::msg::HunterRCState>()
{
  return hunter_msgs::msg::builder::Init_HunterRCState_swa();
}

}  // namespace hunter_msgs

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_RC_STATE__BUILDER_HPP_

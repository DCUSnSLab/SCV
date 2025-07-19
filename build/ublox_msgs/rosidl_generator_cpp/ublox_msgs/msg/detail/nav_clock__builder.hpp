// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavCLOCK.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_clock__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavCLOCK_f_acc
{
public:
  explicit Init_NavCLOCK_f_acc(::ublox_msgs::msg::NavCLOCK & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavCLOCK f_acc(::ublox_msgs::msg::NavCLOCK::_f_acc_type arg)
  {
    msg_.f_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavCLOCK msg_;
};

class Init_NavCLOCK_t_acc
{
public:
  explicit Init_NavCLOCK_t_acc(::ublox_msgs::msg::NavCLOCK & msg)
  : msg_(msg)
  {}
  Init_NavCLOCK_f_acc t_acc(::ublox_msgs::msg::NavCLOCK::_t_acc_type arg)
  {
    msg_.t_acc = std::move(arg);
    return Init_NavCLOCK_f_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavCLOCK msg_;
};

class Init_NavCLOCK_clk_d
{
public:
  explicit Init_NavCLOCK_clk_d(::ublox_msgs::msg::NavCLOCK & msg)
  : msg_(msg)
  {}
  Init_NavCLOCK_t_acc clk_d(::ublox_msgs::msg::NavCLOCK::_clk_d_type arg)
  {
    msg_.clk_d = std::move(arg);
    return Init_NavCLOCK_t_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavCLOCK msg_;
};

class Init_NavCLOCK_clk_b
{
public:
  explicit Init_NavCLOCK_clk_b(::ublox_msgs::msg::NavCLOCK & msg)
  : msg_(msg)
  {}
  Init_NavCLOCK_clk_d clk_b(::ublox_msgs::msg::NavCLOCK::_clk_b_type arg)
  {
    msg_.clk_b = std::move(arg);
    return Init_NavCLOCK_clk_d(msg_);
  }

private:
  ::ublox_msgs::msg::NavCLOCK msg_;
};

class Init_NavCLOCK_i_tow
{
public:
  Init_NavCLOCK_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavCLOCK_clk_b i_tow(::ublox_msgs::msg::NavCLOCK::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavCLOCK_clk_b(msg_);
  }

private:
  ::ublox_msgs::msg::NavCLOCK msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavCLOCK>()
{
  return ublox_msgs::msg::builder::Init_NavCLOCK_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__BUILDER_HPP_

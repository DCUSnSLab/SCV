// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavDOP.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DOP__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DOP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_dop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavDOP_e_dop
{
public:
  explicit Init_NavDOP_e_dop(::ublox_msgs::msg::NavDOP & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavDOP e_dop(::ublox_msgs::msg::NavDOP::_e_dop_type arg)
  {
    msg_.e_dop = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

class Init_NavDOP_n_dop
{
public:
  explicit Init_NavDOP_n_dop(::ublox_msgs::msg::NavDOP & msg)
  : msg_(msg)
  {}
  Init_NavDOP_e_dop n_dop(::ublox_msgs::msg::NavDOP::_n_dop_type arg)
  {
    msg_.n_dop = std::move(arg);
    return Init_NavDOP_e_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

class Init_NavDOP_h_dop
{
public:
  explicit Init_NavDOP_h_dop(::ublox_msgs::msg::NavDOP & msg)
  : msg_(msg)
  {}
  Init_NavDOP_n_dop h_dop(::ublox_msgs::msg::NavDOP::_h_dop_type arg)
  {
    msg_.h_dop = std::move(arg);
    return Init_NavDOP_n_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

class Init_NavDOP_v_dop
{
public:
  explicit Init_NavDOP_v_dop(::ublox_msgs::msg::NavDOP & msg)
  : msg_(msg)
  {}
  Init_NavDOP_h_dop v_dop(::ublox_msgs::msg::NavDOP::_v_dop_type arg)
  {
    msg_.v_dop = std::move(arg);
    return Init_NavDOP_h_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

class Init_NavDOP_t_dop
{
public:
  explicit Init_NavDOP_t_dop(::ublox_msgs::msg::NavDOP & msg)
  : msg_(msg)
  {}
  Init_NavDOP_v_dop t_dop(::ublox_msgs::msg::NavDOP::_t_dop_type arg)
  {
    msg_.t_dop = std::move(arg);
    return Init_NavDOP_v_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

class Init_NavDOP_p_dop
{
public:
  explicit Init_NavDOP_p_dop(::ublox_msgs::msg::NavDOP & msg)
  : msg_(msg)
  {}
  Init_NavDOP_t_dop p_dop(::ublox_msgs::msg::NavDOP::_p_dop_type arg)
  {
    msg_.p_dop = std::move(arg);
    return Init_NavDOP_t_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

class Init_NavDOP_g_dop
{
public:
  explicit Init_NavDOP_g_dop(::ublox_msgs::msg::NavDOP & msg)
  : msg_(msg)
  {}
  Init_NavDOP_p_dop g_dop(::ublox_msgs::msg::NavDOP::_g_dop_type arg)
  {
    msg_.g_dop = std::move(arg);
    return Init_NavDOP_p_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

class Init_NavDOP_i_tow
{
public:
  Init_NavDOP_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavDOP_g_dop i_tow(::ublox_msgs::msg::NavDOP::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavDOP_g_dop(msg_);
  }

private:
  ::ublox_msgs::msg::NavDOP msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavDOP>()
{
  return ublox_msgs::msg::builder::Init_NavDOP_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DOP__BUILDER_HPP_

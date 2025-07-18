// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/EsfINS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_INS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_INS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/esf_ins__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_EsfINS_z_accel
{
public:
  explicit Init_EsfINS_z_accel(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::EsfINS z_accel(::ublox_msgs::msg::EsfINS::_z_accel_type arg)
  {
    msg_.z_accel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_y_accel
{
public:
  explicit Init_EsfINS_y_accel(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  Init_EsfINS_z_accel y_accel(::ublox_msgs::msg::EsfINS::_y_accel_type arg)
  {
    msg_.y_accel = std::move(arg);
    return Init_EsfINS_z_accel(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_x_accel
{
public:
  explicit Init_EsfINS_x_accel(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  Init_EsfINS_y_accel x_accel(::ublox_msgs::msg::EsfINS::_x_accel_type arg)
  {
    msg_.x_accel = std::move(arg);
    return Init_EsfINS_y_accel(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_z_ang_rate
{
public:
  explicit Init_EsfINS_z_ang_rate(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  Init_EsfINS_x_accel z_ang_rate(::ublox_msgs::msg::EsfINS::_z_ang_rate_type arg)
  {
    msg_.z_ang_rate = std::move(arg);
    return Init_EsfINS_x_accel(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_y_ang_rate
{
public:
  explicit Init_EsfINS_y_ang_rate(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  Init_EsfINS_z_ang_rate y_ang_rate(::ublox_msgs::msg::EsfINS::_y_ang_rate_type arg)
  {
    msg_.y_ang_rate = std::move(arg);
    return Init_EsfINS_z_ang_rate(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_x_ang_rate
{
public:
  explicit Init_EsfINS_x_ang_rate(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  Init_EsfINS_y_ang_rate x_ang_rate(::ublox_msgs::msg::EsfINS::_x_ang_rate_type arg)
  {
    msg_.x_ang_rate = std::move(arg);
    return Init_EsfINS_y_ang_rate(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_i_tow
{
public:
  explicit Init_EsfINS_i_tow(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  Init_EsfINS_x_ang_rate i_tow(::ublox_msgs::msg::EsfINS::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_EsfINS_x_ang_rate(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_reserved1
{
public:
  explicit Init_EsfINS_reserved1(::ublox_msgs::msg::EsfINS & msg)
  : msg_(msg)
  {}
  Init_EsfINS_i_tow reserved1(::ublox_msgs::msg::EsfINS::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_EsfINS_i_tow(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

class Init_EsfINS_bitfield0
{
public:
  Init_EsfINS_bitfield0()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EsfINS_reserved1 bitfield0(::ublox_msgs::msg::EsfINS::_bitfield0_type arg)
  {
    msg_.bitfield0 = std::move(arg);
    return Init_EsfINS_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::EsfINS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::EsfINS>()
{
  return ublox_msgs::msg::builder::Init_EsfINS_bitfield0();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_INS__BUILDER_HPP_

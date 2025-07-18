// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgDAT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_DAT__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_DAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_dat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgDAT_scale
{
public:
  explicit Init_CfgDAT_scale(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgDAT scale(::ublox_msgs::msg::CfgDAT::_scale_type arg)
  {
    msg_.scale = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_rot_z
{
public:
  explicit Init_CfgDAT_rot_z(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_scale rot_z(::ublox_msgs::msg::CfgDAT::_rot_z_type arg)
  {
    msg_.rot_z = std::move(arg);
    return Init_CfgDAT_scale(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_rot_y
{
public:
  explicit Init_CfgDAT_rot_y(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_rot_z rot_y(::ublox_msgs::msg::CfgDAT::_rot_y_type arg)
  {
    msg_.rot_y = std::move(arg);
    return Init_CfgDAT_rot_z(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_rot_x
{
public:
  explicit Init_CfgDAT_rot_x(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_rot_y rot_x(::ublox_msgs::msg::CfgDAT::_rot_x_type arg)
  {
    msg_.rot_x = std::move(arg);
    return Init_CfgDAT_rot_y(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_d_z
{
public:
  explicit Init_CfgDAT_d_z(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_rot_x d_z(::ublox_msgs::msg::CfgDAT::_d_z_type arg)
  {
    msg_.d_z = std::move(arg);
    return Init_CfgDAT_rot_x(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_d_y
{
public:
  explicit Init_CfgDAT_d_y(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_d_z d_y(::ublox_msgs::msg::CfgDAT::_d_y_type arg)
  {
    msg_.d_y = std::move(arg);
    return Init_CfgDAT_d_z(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_d_x
{
public:
  explicit Init_CfgDAT_d_x(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_d_y d_x(::ublox_msgs::msg::CfgDAT::_d_x_type arg)
  {
    msg_.d_x = std::move(arg);
    return Init_CfgDAT_d_y(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_flat
{
public:
  explicit Init_CfgDAT_flat(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_d_x flat(::ublox_msgs::msg::CfgDAT::_flat_type arg)
  {
    msg_.flat = std::move(arg);
    return Init_CfgDAT_d_x(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_maj_a
{
public:
  explicit Init_CfgDAT_maj_a(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_flat maj_a(::ublox_msgs::msg::CfgDAT::_maj_a_type arg)
  {
    msg_.maj_a = std::move(arg);
    return Init_CfgDAT_flat(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_datum_name
{
public:
  explicit Init_CfgDAT_datum_name(::ublox_msgs::msg::CfgDAT & msg)
  : msg_(msg)
  {}
  Init_CfgDAT_maj_a datum_name(::ublox_msgs::msg::CfgDAT::_datum_name_type arg)
  {
    msg_.datum_name = std::move(arg);
    return Init_CfgDAT_maj_a(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

class Init_CfgDAT_datum_num
{
public:
  Init_CfgDAT_datum_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgDAT_datum_name datum_num(::ublox_msgs::msg::CfgDAT::_datum_num_type arg)
  {
    msg_.datum_num = std::move(arg);
    return Init_CfgDAT_datum_name(msg_);
  }

private:
  ::ublox_msgs::msg::CfgDAT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgDAT>()
{
  return ublox_msgs::msg::builder::Init_CfgDAT_datum_num();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_DAT__BUILDER_HPP_

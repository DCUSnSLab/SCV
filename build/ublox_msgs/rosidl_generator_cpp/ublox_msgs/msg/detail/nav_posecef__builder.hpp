// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_posecef__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavPOSECEF_p_acc
{
public:
  explicit Init_NavPOSECEF_p_acc(::ublox_msgs::msg::NavPOSECEF & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavPOSECEF p_acc(::ublox_msgs::msg::NavPOSECEF::_p_acc_type arg)
  {
    msg_.p_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSECEF msg_;
};

class Init_NavPOSECEF_ecef_z
{
public:
  explicit Init_NavPOSECEF_ecef_z(::ublox_msgs::msg::NavPOSECEF & msg)
  : msg_(msg)
  {}
  Init_NavPOSECEF_p_acc ecef_z(::ublox_msgs::msg::NavPOSECEF::_ecef_z_type arg)
  {
    msg_.ecef_z = std::move(arg);
    return Init_NavPOSECEF_p_acc(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSECEF msg_;
};

class Init_NavPOSECEF_ecef_y
{
public:
  explicit Init_NavPOSECEF_ecef_y(::ublox_msgs::msg::NavPOSECEF & msg)
  : msg_(msg)
  {}
  Init_NavPOSECEF_ecef_z ecef_y(::ublox_msgs::msg::NavPOSECEF::_ecef_y_type arg)
  {
    msg_.ecef_y = std::move(arg);
    return Init_NavPOSECEF_ecef_z(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSECEF msg_;
};

class Init_NavPOSECEF_ecef_x
{
public:
  explicit Init_NavPOSECEF_ecef_x(::ublox_msgs::msg::NavPOSECEF & msg)
  : msg_(msg)
  {}
  Init_NavPOSECEF_ecef_y ecef_x(::ublox_msgs::msg::NavPOSECEF::_ecef_x_type arg)
  {
    msg_.ecef_x = std::move(arg);
    return Init_NavPOSECEF_ecef_y(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSECEF msg_;
};

class Init_NavPOSECEF_i_tow
{
public:
  Init_NavPOSECEF_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavPOSECEF_ecef_x i_tow(::ublox_msgs::msg::NavPOSECEF::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavPOSECEF_ecef_x(msg_);
  }

private:
  ::ublox_msgs::msg::NavPOSECEF msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavPOSECEF>()
{
  return ublox_msgs::msg::builder::Init_NavPOSECEF_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__BUILDER_HPP_

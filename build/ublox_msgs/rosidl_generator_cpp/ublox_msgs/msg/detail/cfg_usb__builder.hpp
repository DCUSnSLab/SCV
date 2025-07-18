// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgUSB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_USB__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_USB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_usb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgUSB_serial_number
{
public:
  explicit Init_CfgUSB_serial_number(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgUSB serial_number(::ublox_msgs::msg::CfgUSB::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_product_string
{
public:
  explicit Init_CfgUSB_product_string(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  Init_CfgUSB_serial_number product_string(::ublox_msgs::msg::CfgUSB::_product_string_type arg)
  {
    msg_.product_string = std::move(arg);
    return Init_CfgUSB_serial_number(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_vendor_string
{
public:
  explicit Init_CfgUSB_vendor_string(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  Init_CfgUSB_product_string vendor_string(::ublox_msgs::msg::CfgUSB::_vendor_string_type arg)
  {
    msg_.vendor_string = std::move(arg);
    return Init_CfgUSB_product_string(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_flags
{
public:
  explicit Init_CfgUSB_flags(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  Init_CfgUSB_vendor_string flags(::ublox_msgs::msg::CfgUSB::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_CfgUSB_vendor_string(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_power_consumption
{
public:
  explicit Init_CfgUSB_power_consumption(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  Init_CfgUSB_flags power_consumption(::ublox_msgs::msg::CfgUSB::_power_consumption_type arg)
  {
    msg_.power_consumption = std::move(arg);
    return Init_CfgUSB_flags(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_reserved2
{
public:
  explicit Init_CfgUSB_reserved2(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  Init_CfgUSB_power_consumption reserved2(::ublox_msgs::msg::CfgUSB::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return Init_CfgUSB_power_consumption(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_reserved1
{
public:
  explicit Init_CfgUSB_reserved1(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  Init_CfgUSB_reserved2 reserved1(::ublox_msgs::msg::CfgUSB::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_CfgUSB_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_product_id
{
public:
  explicit Init_CfgUSB_product_id(::ublox_msgs::msg::CfgUSB & msg)
  : msg_(msg)
  {}
  Init_CfgUSB_reserved1 product_id(::ublox_msgs::msg::CfgUSB::_product_id_type arg)
  {
    msg_.product_id = std::move(arg);
    return Init_CfgUSB_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

class Init_CfgUSB_vendor_id
{
public:
  Init_CfgUSB_vendor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgUSB_product_id vendor_id(::ublox_msgs::msg::CfgUSB::_vendor_id_type arg)
  {
    msg_.vendor_id = std::move(arg);
    return Init_CfgUSB_product_id(msg_);
  }

private:
  ::ublox_msgs::msg::CfgUSB msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgUSB>()
{
  return ublox_msgs::msg::builder::Init_CfgUSB_vendor_id();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_USB__BUILDER_HPP_

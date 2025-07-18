// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/EsfSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/esf_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_EsfSTATUS_sens
{
public:
  explicit Init_EsfSTATUS_sens(::ublox_msgs::msg::EsfSTATUS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::EsfSTATUS sens(::ublox_msgs::msg::EsfSTATUS::_sens_type arg)
  {
    msg_.sens = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUS msg_;
};

class Init_EsfSTATUS_num_sens
{
public:
  explicit Init_EsfSTATUS_num_sens(::ublox_msgs::msg::EsfSTATUS & msg)
  : msg_(msg)
  {}
  Init_EsfSTATUS_sens num_sens(::ublox_msgs::msg::EsfSTATUS::_num_sens_type arg)
  {
    msg_.num_sens = std::move(arg);
    return Init_EsfSTATUS_sens(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUS msg_;
};

class Init_EsfSTATUS_reserved2
{
public:
  explicit Init_EsfSTATUS_reserved2(::ublox_msgs::msg::EsfSTATUS & msg)
  : msg_(msg)
  {}
  Init_EsfSTATUS_num_sens reserved2(::ublox_msgs::msg::EsfSTATUS::_reserved2_type arg)
  {
    msg_.reserved2 = std::move(arg);
    return Init_EsfSTATUS_num_sens(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUS msg_;
};

class Init_EsfSTATUS_fusion_mode
{
public:
  explicit Init_EsfSTATUS_fusion_mode(::ublox_msgs::msg::EsfSTATUS & msg)
  : msg_(msg)
  {}
  Init_EsfSTATUS_reserved2 fusion_mode(::ublox_msgs::msg::EsfSTATUS::_fusion_mode_type arg)
  {
    msg_.fusion_mode = std::move(arg);
    return Init_EsfSTATUS_reserved2(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUS msg_;
};

class Init_EsfSTATUS_reserved1
{
public:
  explicit Init_EsfSTATUS_reserved1(::ublox_msgs::msg::EsfSTATUS & msg)
  : msg_(msg)
  {}
  Init_EsfSTATUS_fusion_mode reserved1(::ublox_msgs::msg::EsfSTATUS::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_EsfSTATUS_fusion_mode(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUS msg_;
};

class Init_EsfSTATUS_version
{
public:
  explicit Init_EsfSTATUS_version(::ublox_msgs::msg::EsfSTATUS & msg)
  : msg_(msg)
  {}
  Init_EsfSTATUS_reserved1 version(::ublox_msgs::msg::EsfSTATUS::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_EsfSTATUS_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUS msg_;
};

class Init_EsfSTATUS_i_tow
{
public:
  Init_EsfSTATUS_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EsfSTATUS_version i_tow(::ublox_msgs::msg::EsfSTATUS::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_EsfSTATUS_version(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::EsfSTATUS>()
{
  return ublox_msgs::msg::builder::Init_EsfSTATUS_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__BUILDER_HPP_

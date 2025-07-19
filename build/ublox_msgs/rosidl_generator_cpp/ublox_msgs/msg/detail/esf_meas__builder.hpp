// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/EsfMEAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_MEAS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_MEAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/esf_meas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_EsfMEAS_calib_t_tag
{
public:
  explicit Init_EsfMEAS_calib_t_tag(::ublox_msgs::msg::EsfMEAS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::EsfMEAS calib_t_tag(::ublox_msgs::msg::EsfMEAS::_calib_t_tag_type arg)
  {
    msg_.calib_t_tag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::EsfMEAS msg_;
};

class Init_EsfMEAS_data
{
public:
  explicit Init_EsfMEAS_data(::ublox_msgs::msg::EsfMEAS & msg)
  : msg_(msg)
  {}
  Init_EsfMEAS_calib_t_tag data(::ublox_msgs::msg::EsfMEAS::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_EsfMEAS_calib_t_tag(msg_);
  }

private:
  ::ublox_msgs::msg::EsfMEAS msg_;
};

class Init_EsfMEAS_id
{
public:
  explicit Init_EsfMEAS_id(::ublox_msgs::msg::EsfMEAS & msg)
  : msg_(msg)
  {}
  Init_EsfMEAS_data id(::ublox_msgs::msg::EsfMEAS::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_EsfMEAS_data(msg_);
  }

private:
  ::ublox_msgs::msg::EsfMEAS msg_;
};

class Init_EsfMEAS_flags
{
public:
  explicit Init_EsfMEAS_flags(::ublox_msgs::msg::EsfMEAS & msg)
  : msg_(msg)
  {}
  Init_EsfMEAS_id flags(::ublox_msgs::msg::EsfMEAS::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_EsfMEAS_id(msg_);
  }

private:
  ::ublox_msgs::msg::EsfMEAS msg_;
};

class Init_EsfMEAS_time_tag
{
public:
  Init_EsfMEAS_time_tag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EsfMEAS_flags time_tag(::ublox_msgs::msg::EsfMEAS::_time_tag_type arg)
  {
    msg_.time_tag = std::move(arg);
    return Init_EsfMEAS_flags(msg_);
  }

private:
  ::ublox_msgs::msg::EsfMEAS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::EsfMEAS>()
{
  return ublox_msgs::msg::builder::Init_EsfMEAS_time_tag();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_MEAS__BUILDER_HPP_

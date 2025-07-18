// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/EsfSTATUSSens.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/esf_status_sens__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_EsfSTATUSSens_faults
{
public:
  explicit Init_EsfSTATUSSens_faults(::ublox_msgs::msg::EsfSTATUSSens & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::EsfSTATUSSens faults(::ublox_msgs::msg::EsfSTATUSSens::_faults_type arg)
  {
    msg_.faults = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUSSens msg_;
};

class Init_EsfSTATUSSens_freq
{
public:
  explicit Init_EsfSTATUSSens_freq(::ublox_msgs::msg::EsfSTATUSSens & msg)
  : msg_(msg)
  {}
  Init_EsfSTATUSSens_faults freq(::ublox_msgs::msg::EsfSTATUSSens::_freq_type arg)
  {
    msg_.freq = std::move(arg);
    return Init_EsfSTATUSSens_faults(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUSSens msg_;
};

class Init_EsfSTATUSSens_sens_status2
{
public:
  explicit Init_EsfSTATUSSens_sens_status2(::ublox_msgs::msg::EsfSTATUSSens & msg)
  : msg_(msg)
  {}
  Init_EsfSTATUSSens_freq sens_status2(::ublox_msgs::msg::EsfSTATUSSens::_sens_status2_type arg)
  {
    msg_.sens_status2 = std::move(arg);
    return Init_EsfSTATUSSens_freq(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUSSens msg_;
};

class Init_EsfSTATUSSens_sens_status1
{
public:
  Init_EsfSTATUSSens_sens_status1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EsfSTATUSSens_sens_status2 sens_status1(::ublox_msgs::msg::EsfSTATUSSens::_sens_status1_type arg)
  {
    msg_.sens_status1 = std::move(arg);
    return Init_EsfSTATUSSens_sens_status2(msg_);
  }

private:
  ::ublox_msgs::msg::EsfSTATUSSens msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::EsfSTATUSSens>()
{
  return ublox_msgs::msg::builder::Init_EsfSTATUSSens_sens_status1();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/MonGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_GNSS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_GNSS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/mon_gnss__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_MonGNSS_reserved1
{
public:
  explicit Init_MonGNSS_reserved1(::ublox_msgs::msg::MonGNSS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::MonGNSS reserved1(::ublox_msgs::msg::MonGNSS::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::MonGNSS msg_;
};

class Init_MonGNSS_simultaneous
{
public:
  explicit Init_MonGNSS_simultaneous(::ublox_msgs::msg::MonGNSS & msg)
  : msg_(msg)
  {}
  Init_MonGNSS_reserved1 simultaneous(::ublox_msgs::msg::MonGNSS::_simultaneous_type arg)
  {
    msg_.simultaneous = std::move(arg);
    return Init_MonGNSS_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::MonGNSS msg_;
};

class Init_MonGNSS_enabled
{
public:
  explicit Init_MonGNSS_enabled(::ublox_msgs::msg::MonGNSS & msg)
  : msg_(msg)
  {}
  Init_MonGNSS_simultaneous enabled(::ublox_msgs::msg::MonGNSS::_enabled_type arg)
  {
    msg_.enabled = std::move(arg);
    return Init_MonGNSS_simultaneous(msg_);
  }

private:
  ::ublox_msgs::msg::MonGNSS msg_;
};

class Init_MonGNSS_default_gnss
{
public:
  explicit Init_MonGNSS_default_gnss(::ublox_msgs::msg::MonGNSS & msg)
  : msg_(msg)
  {}
  Init_MonGNSS_enabled default_gnss(::ublox_msgs::msg::MonGNSS::_default_gnss_type arg)
  {
    msg_.default_gnss = std::move(arg);
    return Init_MonGNSS_enabled(msg_);
  }

private:
  ::ublox_msgs::msg::MonGNSS msg_;
};

class Init_MonGNSS_supported
{
public:
  explicit Init_MonGNSS_supported(::ublox_msgs::msg::MonGNSS & msg)
  : msg_(msg)
  {}
  Init_MonGNSS_default_gnss supported(::ublox_msgs::msg::MonGNSS::_supported_type arg)
  {
    msg_.supported = std::move(arg);
    return Init_MonGNSS_default_gnss(msg_);
  }

private:
  ::ublox_msgs::msg::MonGNSS msg_;
};

class Init_MonGNSS_version
{
public:
  Init_MonGNSS_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MonGNSS_supported version(::ublox_msgs::msg::MonGNSS::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_MonGNSS_supported(msg_);
  }

private:
  ::ublox_msgs::msg::MonGNSS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::MonGNSS>()
{
  return ublox_msgs::msg::builder::Init_MonGNSS_version();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_GNSS__BUILDER_HPP_

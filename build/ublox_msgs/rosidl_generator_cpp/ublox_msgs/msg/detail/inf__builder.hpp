// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/Inf.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__INF__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__INF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/inf__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_Inf_str
{
public:
  Init_Inf_str()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ublox_msgs::msg::Inf str(::ublox_msgs::msg::Inf::_str_type arg)
  {
    msg_.str = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::Inf msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::Inf>()
{
  return ublox_msgs::msg::builder::Init_Inf_str();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__INF__BUILDER_HPP_

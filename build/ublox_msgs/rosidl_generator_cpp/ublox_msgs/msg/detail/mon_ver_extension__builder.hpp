// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/MonVERExtension.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/mon_ver_extension__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_MonVERExtension_field
{
public:
  Init_MonVERExtension_field()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ublox_msgs::msg::MonVERExtension field(::ublox_msgs::msg::MonVERExtension::_field_type arg)
  {
    msg_.field = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::MonVERExtension msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::MonVERExtension>()
{
  return ublox_msgs::msg::builder::Init_MonVERExtension_field();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__BUILDER_HPP_

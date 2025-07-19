// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hunter_msgs:msg/HunterLightState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__BUILDER_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hunter_msgs/msg/detail/hunter_light_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hunter_msgs
{

namespace msg
{

namespace builder
{

class Init_HunterLightState_custom_value
{
public:
  explicit Init_HunterLightState_custom_value(::hunter_msgs::msg::HunterLightState & msg)
  : msg_(msg)
  {}
  ::hunter_msgs::msg::HunterLightState custom_value(::hunter_msgs::msg::HunterLightState::_custom_value_type arg)
  {
    msg_.custom_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hunter_msgs::msg::HunterLightState msg_;
};

class Init_HunterLightState_mode
{
public:
  Init_HunterLightState_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HunterLightState_custom_value mode(::hunter_msgs::msg::HunterLightState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_HunterLightState_custom_value(msg_);
  }

private:
  ::hunter_msgs::msg::HunterLightState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hunter_msgs::msg::HunterLightState>()
{
  return hunter_msgs::msg::builder::Init_HunterLightState_mode();
}

}  // namespace hunter_msgs

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__BUILDER_HPP_

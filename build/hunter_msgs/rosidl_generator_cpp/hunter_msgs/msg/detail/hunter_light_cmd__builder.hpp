// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hunter_msgs:msg/HunterLightCmd.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_CMD__BUILDER_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hunter_msgs/msg/detail/hunter_light_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hunter_msgs
{

namespace msg
{

namespace builder
{

class Init_HunterLightCmd_rear_custom_value
{
public:
  explicit Init_HunterLightCmd_rear_custom_value(::hunter_msgs::msg::HunterLightCmd & msg)
  : msg_(msg)
  {}
  ::hunter_msgs::msg::HunterLightCmd rear_custom_value(::hunter_msgs::msg::HunterLightCmd::_rear_custom_value_type arg)
  {
    msg_.rear_custom_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hunter_msgs::msg::HunterLightCmd msg_;
};

class Init_HunterLightCmd_rear_mode
{
public:
  explicit Init_HunterLightCmd_rear_mode(::hunter_msgs::msg::HunterLightCmd & msg)
  : msg_(msg)
  {}
  Init_HunterLightCmd_rear_custom_value rear_mode(::hunter_msgs::msg::HunterLightCmd::_rear_mode_type arg)
  {
    msg_.rear_mode = std::move(arg);
    return Init_HunterLightCmd_rear_custom_value(msg_);
  }

private:
  ::hunter_msgs::msg::HunterLightCmd msg_;
};

class Init_HunterLightCmd_front_custom_value
{
public:
  explicit Init_HunterLightCmd_front_custom_value(::hunter_msgs::msg::HunterLightCmd & msg)
  : msg_(msg)
  {}
  Init_HunterLightCmd_rear_mode front_custom_value(::hunter_msgs::msg::HunterLightCmd::_front_custom_value_type arg)
  {
    msg_.front_custom_value = std::move(arg);
    return Init_HunterLightCmd_rear_mode(msg_);
  }

private:
  ::hunter_msgs::msg::HunterLightCmd msg_;
};

class Init_HunterLightCmd_front_mode
{
public:
  explicit Init_HunterLightCmd_front_mode(::hunter_msgs::msg::HunterLightCmd & msg)
  : msg_(msg)
  {}
  Init_HunterLightCmd_front_custom_value front_mode(::hunter_msgs::msg::HunterLightCmd::_front_mode_type arg)
  {
    msg_.front_mode = std::move(arg);
    return Init_HunterLightCmd_front_custom_value(msg_);
  }

private:
  ::hunter_msgs::msg::HunterLightCmd msg_;
};

class Init_HunterLightCmd_cmd_ctrl_allowed
{
public:
  Init_HunterLightCmd_cmd_ctrl_allowed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HunterLightCmd_front_mode cmd_ctrl_allowed(::hunter_msgs::msg::HunterLightCmd::_cmd_ctrl_allowed_type arg)
  {
    msg_.cmd_ctrl_allowed = std::move(arg);
    return Init_HunterLightCmd_front_mode(msg_);
  }

private:
  ::hunter_msgs::msg::HunterLightCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hunter_msgs::msg::HunterLightCmd>()
{
  return hunter_msgs::msg::builder::Init_HunterLightCmd_cmd_ctrl_allowed();
}

}  // namespace hunter_msgs

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_CMD__BUILDER_HPP_

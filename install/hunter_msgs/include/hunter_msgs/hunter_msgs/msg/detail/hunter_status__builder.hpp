// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hunter_msgs:msg/HunterStatus.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__BUILDER_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hunter_msgs/msg/detail/hunter_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hunter_msgs
{

namespace msg
{

namespace builder
{

class Init_HunterStatus_actuator_states
{
public:
  explicit Init_HunterStatus_actuator_states(::hunter_msgs::msg::HunterStatus & msg)
  : msg_(msg)
  {}
  ::hunter_msgs::msg::HunterStatus actuator_states(::hunter_msgs::msg::HunterStatus::_actuator_states_type arg)
  {
    msg_.actuator_states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

class Init_HunterStatus_battery_voltage
{
public:
  explicit Init_HunterStatus_battery_voltage(::hunter_msgs::msg::HunterStatus & msg)
  : msg_(msg)
  {}
  Init_HunterStatus_actuator_states battery_voltage(::hunter_msgs::msg::HunterStatus::_battery_voltage_type arg)
  {
    msg_.battery_voltage = std::move(arg);
    return Init_HunterStatus_actuator_states(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

class Init_HunterStatus_error_code
{
public:
  explicit Init_HunterStatus_error_code(::hunter_msgs::msg::HunterStatus & msg)
  : msg_(msg)
  {}
  Init_HunterStatus_battery_voltage error_code(::hunter_msgs::msg::HunterStatus::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_HunterStatus_battery_voltage(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

class Init_HunterStatus_control_mode
{
public:
  explicit Init_HunterStatus_control_mode(::hunter_msgs::msg::HunterStatus & msg)
  : msg_(msg)
  {}
  Init_HunterStatus_error_code control_mode(::hunter_msgs::msg::HunterStatus::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_HunterStatus_error_code(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

class Init_HunterStatus_vehicle_state
{
public:
  explicit Init_HunterStatus_vehicle_state(::hunter_msgs::msg::HunterStatus & msg)
  : msg_(msg)
  {}
  Init_HunterStatus_control_mode vehicle_state(::hunter_msgs::msg::HunterStatus::_vehicle_state_type arg)
  {
    msg_.vehicle_state = std::move(arg);
    return Init_HunterStatus_control_mode(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

class Init_HunterStatus_steering_angle
{
public:
  explicit Init_HunterStatus_steering_angle(::hunter_msgs::msg::HunterStatus & msg)
  : msg_(msg)
  {}
  Init_HunterStatus_vehicle_state steering_angle(::hunter_msgs::msg::HunterStatus::_steering_angle_type arg)
  {
    msg_.steering_angle = std::move(arg);
    return Init_HunterStatus_vehicle_state(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

class Init_HunterStatus_linear_velocity
{
public:
  explicit Init_HunterStatus_linear_velocity(::hunter_msgs::msg::HunterStatus & msg)
  : msg_(msg)
  {}
  Init_HunterStatus_steering_angle linear_velocity(::hunter_msgs::msg::HunterStatus::_linear_velocity_type arg)
  {
    msg_.linear_velocity = std::move(arg);
    return Init_HunterStatus_steering_angle(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

class Init_HunterStatus_header
{
public:
  Init_HunterStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HunterStatus_linear_velocity header(::hunter_msgs::msg::HunterStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HunterStatus_linear_velocity(msg_);
  }

private:
  ::hunter_msgs::msg::HunterStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hunter_msgs::msg::HunterStatus>()
{
  return hunter_msgs::msg::builder::Init_HunterStatus_header();
}

}  // namespace hunter_msgs

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hunter_msgs:msg/HunterActuatorState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__BUILDER_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hunter_msgs/msg/detail/hunter_actuator_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hunter_msgs
{

namespace msg
{

namespace builder
{

class Init_HunterActuatorState_driver_state
{
public:
  explicit Init_HunterActuatorState_driver_state(::hunter_msgs::msg::HunterActuatorState & msg)
  : msg_(msg)
  {}
  ::hunter_msgs::msg::HunterActuatorState driver_state(::hunter_msgs::msg::HunterActuatorState::_driver_state_type arg)
  {
    msg_.driver_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

class Init_HunterActuatorState_motor_temperature
{
public:
  explicit Init_HunterActuatorState_motor_temperature(::hunter_msgs::msg::HunterActuatorState & msg)
  : msg_(msg)
  {}
  Init_HunterActuatorState_driver_state motor_temperature(::hunter_msgs::msg::HunterActuatorState::_motor_temperature_type arg)
  {
    msg_.motor_temperature = std::move(arg);
    return Init_HunterActuatorState_driver_state(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

class Init_HunterActuatorState_driver_temperature
{
public:
  explicit Init_HunterActuatorState_driver_temperature(::hunter_msgs::msg::HunterActuatorState & msg)
  : msg_(msg)
  {}
  Init_HunterActuatorState_motor_temperature driver_temperature(::hunter_msgs::msg::HunterActuatorState::_driver_temperature_type arg)
  {
    msg_.driver_temperature = std::move(arg);
    return Init_HunterActuatorState_motor_temperature(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

class Init_HunterActuatorState_driver_voltage
{
public:
  explicit Init_HunterActuatorState_driver_voltage(::hunter_msgs::msg::HunterActuatorState & msg)
  : msg_(msg)
  {}
  Init_HunterActuatorState_driver_temperature driver_voltage(::hunter_msgs::msg::HunterActuatorState::_driver_voltage_type arg)
  {
    msg_.driver_voltage = std::move(arg);
    return Init_HunterActuatorState_driver_temperature(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

class Init_HunterActuatorState_pulse_count
{
public:
  explicit Init_HunterActuatorState_pulse_count(::hunter_msgs::msg::HunterActuatorState & msg)
  : msg_(msg)
  {}
  Init_HunterActuatorState_driver_voltage pulse_count(::hunter_msgs::msg::HunterActuatorState::_pulse_count_type arg)
  {
    msg_.pulse_count = std::move(arg);
    return Init_HunterActuatorState_driver_voltage(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

class Init_HunterActuatorState_current
{
public:
  explicit Init_HunterActuatorState_current(::hunter_msgs::msg::HunterActuatorState & msg)
  : msg_(msg)
  {}
  Init_HunterActuatorState_pulse_count current(::hunter_msgs::msg::HunterActuatorState::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_HunterActuatorState_pulse_count(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

class Init_HunterActuatorState_rpm
{
public:
  explicit Init_HunterActuatorState_rpm(::hunter_msgs::msg::HunterActuatorState & msg)
  : msg_(msg)
  {}
  Init_HunterActuatorState_current rpm(::hunter_msgs::msg::HunterActuatorState::_rpm_type arg)
  {
    msg_.rpm = std::move(arg);
    return Init_HunterActuatorState_current(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

class Init_HunterActuatorState_motor_id
{
public:
  Init_HunterActuatorState_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HunterActuatorState_rpm motor_id(::hunter_msgs::msg::HunterActuatorState::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_HunterActuatorState_rpm(msg_);
  }

private:
  ::hunter_msgs::msg::HunterActuatorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hunter_msgs::msg::HunterActuatorState>()
{
  return hunter_msgs::msg::builder::Init_HunterActuatorState_motor_id();
}

}  // namespace hunter_msgs

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__BUILDER_HPP_

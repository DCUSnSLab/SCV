// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hunter_msgs:msg/HunterStatus.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__TRAITS_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hunter_msgs/msg/detail/hunter_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'actuator_states'
#include "hunter_msgs/msg/detail/hunter_actuator_state__traits.hpp"

namespace hunter_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HunterStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: linear_velocity
  {
    out << "linear_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_velocity, out);
    out << ", ";
  }

  // member: steering_angle
  {
    out << "steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle, out);
    out << ", ";
  }

  // member: vehicle_state
  {
    out << "vehicle_state: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_state, out);
    out << ", ";
  }

  // member: control_mode
  {
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: battery_voltage
  {
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << ", ";
  }

  // member: actuator_states
  {
    if (msg.actuator_states.size() == 0) {
      out << "actuator_states: []";
    } else {
      out << "actuator_states: [";
      size_t pending_items = msg.actuator_states.size();
      for (auto item : msg.actuator_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HunterStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: linear_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_velocity, out);
    out << "\n";
  }

  // member: steering_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle, out);
    out << "\n";
  }

  // member: vehicle_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vehicle_state: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_state, out);
    out << "\n";
  }

  // member: control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }

  // member: battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << "\n";
  }

  // member: actuator_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.actuator_states.size() == 0) {
      out << "actuator_states: []\n";
    } else {
      out << "actuator_states:\n";
      for (auto item : msg.actuator_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HunterStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hunter_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hunter_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hunter_msgs::msg::HunterStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  hunter_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hunter_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hunter_msgs::msg::HunterStatus & msg)
{
  return hunter_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hunter_msgs::msg::HunterStatus>()
{
  return "hunter_msgs::msg::HunterStatus";
}

template<>
inline const char * name<hunter_msgs::msg::HunterStatus>()
{
  return "hunter_msgs/msg/HunterStatus";
}

template<>
struct has_fixed_size<hunter_msgs::msg::HunterStatus>
  : std::integral_constant<bool, has_fixed_size<hunter_msgs::msg::HunterActuatorState>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hunter_msgs::msg::HunterStatus>
  : std::integral_constant<bool, has_bounded_size<hunter_msgs::msg::HunterActuatorState>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hunter_msgs::msg::HunterStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hunter_msgs:msg/HunterLightState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__TRAITS_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hunter_msgs/msg/detail/hunter_light_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hunter_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HunterLightState & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: custom_value
  {
    out << "custom_value: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HunterLightState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: custom_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "custom_value: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HunterLightState & msg, bool use_flow_style = false)
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
  const hunter_msgs::msg::HunterLightState & msg,
  std::ostream & out, size_t indentation = 0)
{
  hunter_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hunter_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hunter_msgs::msg::HunterLightState & msg)
{
  return hunter_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hunter_msgs::msg::HunterLightState>()
{
  return "hunter_msgs::msg::HunterLightState";
}

template<>
inline const char * name<hunter_msgs::msg::HunterLightState>()
{
  return "hunter_msgs/msg/HunterLightState";
}

template<>
struct has_fixed_size<hunter_msgs::msg::HunterLightState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hunter_msgs::msg::HunterLightState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hunter_msgs::msg::HunterLightState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__TRAITS_HPP_

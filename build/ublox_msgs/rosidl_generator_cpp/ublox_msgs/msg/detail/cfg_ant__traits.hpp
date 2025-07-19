// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgANT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_ANT__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_ANT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_ant__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgANT & msg,
  std::ostream & out)
{
  out << "{";
  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: pins
  {
    out << "pins: ";
    rosidl_generator_traits::value_to_yaml(msg.pins, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgANT & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << "\n";
  }

  // member: pins
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pins: ";
    rosidl_generator_traits::value_to_yaml(msg.pins, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgANT & msg, bool use_flow_style = false)
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

}  // namespace ublox_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ublox_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ublox_msgs::msg::CfgANT & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgANT & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgANT>()
{
  return "ublox_msgs::msg::CfgANT";
}

template<>
inline const char * name<ublox_msgs::msg::CfgANT>()
{
  return "ublox_msgs/msg/CfgANT";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgANT>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgANT>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgANT>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_ANT__TRAITS_HPP_

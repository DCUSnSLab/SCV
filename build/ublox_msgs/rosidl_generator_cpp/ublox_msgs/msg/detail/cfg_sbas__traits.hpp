// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_sbas__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgSBAS & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: usage
  {
    out << "usage: ";
    rosidl_generator_traits::value_to_yaml(msg.usage, out);
    out << ", ";
  }

  // member: max_sbas
  {
    out << "max_sbas: ";
    rosidl_generator_traits::value_to_yaml(msg.max_sbas, out);
    out << ", ";
  }

  // member: scanmode2
  {
    out << "scanmode2: ";
    rosidl_generator_traits::value_to_yaml(msg.scanmode2, out);
    out << ", ";
  }

  // member: scanmode1
  {
    out << "scanmode1: ";
    rosidl_generator_traits::value_to_yaml(msg.scanmode1, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgSBAS & msg,
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

  // member: usage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "usage: ";
    rosidl_generator_traits::value_to_yaml(msg.usage, out);
    out << "\n";
  }

  // member: max_sbas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_sbas: ";
    rosidl_generator_traits::value_to_yaml(msg.max_sbas, out);
    out << "\n";
  }

  // member: scanmode2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scanmode2: ";
    rosidl_generator_traits::value_to_yaml(msg.scanmode2, out);
    out << "\n";
  }

  // member: scanmode1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scanmode1: ";
    rosidl_generator_traits::value_to_yaml(msg.scanmode1, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgSBAS & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgSBAS & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgSBAS & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgSBAS>()
{
  return "ublox_msgs::msg::CfgSBAS";
}

template<>
inline const char * name<ublox_msgs::msg::CfgSBAS>()
{
  return "ublox_msgs/msg/CfgSBAS";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgSBAS>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgSBAS>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgSBAS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__TRAITS_HPP_

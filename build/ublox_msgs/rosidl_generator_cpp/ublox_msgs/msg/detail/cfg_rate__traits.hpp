// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgRATE.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_RATE__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_RATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_rate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgRATE & msg,
  std::ostream & out)
{
  out << "{";
  // member: meas_rate
  {
    out << "meas_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.meas_rate, out);
    out << ", ";
  }

  // member: nav_rate
  {
    out << "nav_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.nav_rate, out);
    out << ", ";
  }

  // member: time_ref
  {
    out << "time_ref: ";
    rosidl_generator_traits::value_to_yaml(msg.time_ref, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgRATE & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: meas_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "meas_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.meas_rate, out);
    out << "\n";
  }

  // member: nav_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nav_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.nav_rate, out);
    out << "\n";
  }

  // member: time_ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_ref: ";
    rosidl_generator_traits::value_to_yaml(msg.time_ref, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgRATE & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgRATE & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgRATE & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgRATE>()
{
  return "ublox_msgs::msg::CfgRATE";
}

template<>
inline const char * name<ublox_msgs::msg::CfgRATE>()
{
  return "ublox_msgs/msg/CfgRATE";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgRATE>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgRATE>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgRATE>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_RATE__TRAITS_HPP_

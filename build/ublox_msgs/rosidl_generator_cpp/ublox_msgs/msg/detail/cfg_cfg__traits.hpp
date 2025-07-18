// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgCFG.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_CFG__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_CFG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_cfg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgCFG & msg,
  std::ostream & out)
{
  out << "{";
  // member: clear_mask
  {
    out << "clear_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.clear_mask, out);
    out << ", ";
  }

  // member: save_mask
  {
    out << "save_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.save_mask, out);
    out << ", ";
  }

  // member: load_mask
  {
    out << "load_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.load_mask, out);
    out << ", ";
  }

  // member: device_mask
  {
    out << "device_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.device_mask, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgCFG & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: clear_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clear_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.clear_mask, out);
    out << "\n";
  }

  // member: save_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "save_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.save_mask, out);
    out << "\n";
  }

  // member: load_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.load_mask, out);
    out << "\n";
  }

  // member: device_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.device_mask, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgCFG & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgCFG & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgCFG & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgCFG>()
{
  return "ublox_msgs::msg::CfgCFG";
}

template<>
inline const char * name<ublox_msgs::msg::CfgCFG>()
{
  return "ublox_msgs/msg/CfgCFG";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgCFG>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgCFG>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgCFG>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_CFG__TRAITS_HPP_

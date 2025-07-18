// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgDGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_dgnss__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgDGNSS & msg,
  std::ostream & out)
{
  out << "{";
  // member: dgnss_mode
  {
    out << "dgnss_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.dgnss_mode, out);
    out << ", ";
  }

  // member: reserved0
  {
    if (msg.reserved0.size() == 0) {
      out << "reserved0: []";
    } else {
      out << "reserved0: [";
      size_t pending_items = msg.reserved0.size();
      for (auto item : msg.reserved0) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const CfgDGNSS & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dgnss_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dgnss_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.dgnss_mode, out);
    out << "\n";
  }

  // member: reserved0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved0.size() == 0) {
      out << "reserved0: []\n";
    } else {
      out << "reserved0:\n";
      for (auto item : msg.reserved0) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgDGNSS & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgDGNSS & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgDGNSS & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgDGNSS>()
{
  return "ublox_msgs::msg::CfgDGNSS";
}

template<>
inline const char * name<ublox_msgs::msg::CfgDGNSS>()
{
  return "ublox_msgs/msg/CfgDGNSS";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgDGNSS>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgDGNSS>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgDGNSS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/AidALM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_ALM__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_ALM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/aid_alm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AidALM & msg,
  std::ostream & out)
{
  out << "{";
  // member: svid
  {
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << ", ";
  }

  // member: week
  {
    out << "week: ";
    rosidl_generator_traits::value_to_yaml(msg.week, out);
    out << ", ";
  }

  // member: dwrd
  {
    if (msg.dwrd.size() == 0) {
      out << "dwrd: []";
    } else {
      out << "dwrd: [";
      size_t pending_items = msg.dwrd.size();
      for (auto item : msg.dwrd) {
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
  const AidALM & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: svid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << "\n";
  }

  // member: week
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "week: ";
    rosidl_generator_traits::value_to_yaml(msg.week, out);
    out << "\n";
  }

  // member: dwrd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dwrd.size() == 0) {
      out << "dwrd: []\n";
    } else {
      out << "dwrd:\n";
      for (auto item : msg.dwrd) {
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

inline std::string to_yaml(const AidALM & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::AidALM & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::AidALM & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::AidALM>()
{
  return "ublox_msgs::msg::AidALM";
}

template<>
inline const char * name<ublox_msgs::msg::AidALM>()
{
  return "ublox_msgs/msg/AidALM";
}

template<>
struct has_fixed_size<ublox_msgs::msg::AidALM>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::AidALM>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::AidALM>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_ALM__TRAITS_HPP_

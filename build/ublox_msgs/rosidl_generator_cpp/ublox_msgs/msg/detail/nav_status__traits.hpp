// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavSTATUS & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: gps_fix
  {
    out << "gps_fix: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_fix, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: fix_stat
  {
    out << "fix_stat: ";
    rosidl_generator_traits::value_to_yaml(msg.fix_stat, out);
    out << ", ";
  }

  // member: flags2
  {
    out << "flags2: ";
    rosidl_generator_traits::value_to_yaml(msg.flags2, out);
    out << ", ";
  }

  // member: ttff
  {
    out << "ttff: ";
    rosidl_generator_traits::value_to_yaml(msg.ttff, out);
    out << ", ";
  }

  // member: msss
  {
    out << "msss: ";
    rosidl_generator_traits::value_to_yaml(msg.msss, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavSTATUS & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: i_tow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << "\n";
  }

  // member: gps_fix
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_fix: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_fix, out);
    out << "\n";
  }

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << "\n";
  }

  // member: fix_stat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fix_stat: ";
    rosidl_generator_traits::value_to_yaml(msg.fix_stat, out);
    out << "\n";
  }

  // member: flags2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags2: ";
    rosidl_generator_traits::value_to_yaml(msg.flags2, out);
    out << "\n";
  }

  // member: ttff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ttff: ";
    rosidl_generator_traits::value_to_yaml(msg.ttff, out);
    out << "\n";
  }

  // member: msss
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msss: ";
    rosidl_generator_traits::value_to_yaml(msg.msss, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavSTATUS & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavSTATUS & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavSTATUS & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavSTATUS>()
{
  return "ublox_msgs::msg::NavSTATUS";
}

template<>
inline const char * name<ublox_msgs::msg::NavSTATUS>()
{
  return "ublox_msgs/msg/NavSTATUS";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavSTATUS>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavSTATUS>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavSTATUS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__TRAITS_HPP_

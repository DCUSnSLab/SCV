// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavVELNED.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_velned__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavVELNED & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: vel_n
  {
    out << "vel_n: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_n, out);
    out << ", ";
  }

  // member: vel_e
  {
    out << "vel_e: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_e, out);
    out << ", ";
  }

  // member: vel_d
  {
    out << "vel_d: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_d, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: g_speed
  {
    out << "g_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.g_speed, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << ", ";
  }

  // member: s_acc
  {
    out << "s_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.s_acc, out);
    out << ", ";
  }

  // member: c_acc
  {
    out << "c_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.c_acc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavVELNED & msg,
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

  // member: vel_n
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_n: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_n, out);
    out << "\n";
  }

  // member: vel_e
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_e: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_e, out);
    out << "\n";
  }

  // member: vel_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_d: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_d, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: g_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.g_speed, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }

  // member: s_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "s_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.s_acc, out);
    out << "\n";
  }

  // member: c_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.c_acc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavVELNED & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavVELNED & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavVELNED & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavVELNED>()
{
  return "ublox_msgs::msg::NavVELNED";
}

template<>
inline const char * name<ublox_msgs::msg::NavVELNED>()
{
  return "ublox_msgs/msg/NavVELNED";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavVELNED>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavVELNED>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavVELNED>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__TRAITS_HPP_

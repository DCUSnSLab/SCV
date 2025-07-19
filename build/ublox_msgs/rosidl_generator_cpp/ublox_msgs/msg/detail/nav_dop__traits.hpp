// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavDOP.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DOP__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DOP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_dop__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavDOP & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: g_dop
  {
    out << "g_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.g_dop, out);
    out << ", ";
  }

  // member: p_dop
  {
    out << "p_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.p_dop, out);
    out << ", ";
  }

  // member: t_dop
  {
    out << "t_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.t_dop, out);
    out << ", ";
  }

  // member: v_dop
  {
    out << "v_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.v_dop, out);
    out << ", ";
  }

  // member: h_dop
  {
    out << "h_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.h_dop, out);
    out << ", ";
  }

  // member: n_dop
  {
    out << "n_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.n_dop, out);
    out << ", ";
  }

  // member: e_dop
  {
    out << "e_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.e_dop, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavDOP & msg,
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

  // member: g_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.g_dop, out);
    out << "\n";
  }

  // member: p_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.p_dop, out);
    out << "\n";
  }

  // member: t_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.t_dop, out);
    out << "\n";
  }

  // member: v_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.v_dop, out);
    out << "\n";
  }

  // member: h_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "h_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.h_dop, out);
    out << "\n";
  }

  // member: n_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "n_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.n_dop, out);
    out << "\n";
  }

  // member: e_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "e_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.e_dop, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavDOP & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavDOP & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavDOP & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavDOP>()
{
  return "ublox_msgs::msg::NavDOP";
}

template<>
inline const char * name<ublox_msgs::msg::NavDOP>()
{
  return "ublox_msgs/msg/NavDOP";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavDOP>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavDOP>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavDOP>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DOP__TRAITS_HPP_

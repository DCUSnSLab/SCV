// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavCLOCK.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_clock__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavCLOCK & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: clk_b
  {
    out << "clk_b: ";
    rosidl_generator_traits::value_to_yaml(msg.clk_b, out);
    out << ", ";
  }

  // member: clk_d
  {
    out << "clk_d: ";
    rosidl_generator_traits::value_to_yaml(msg.clk_d, out);
    out << ", ";
  }

  // member: t_acc
  {
    out << "t_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.t_acc, out);
    out << ", ";
  }

  // member: f_acc
  {
    out << "f_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.f_acc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavCLOCK & msg,
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

  // member: clk_b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clk_b: ";
    rosidl_generator_traits::value_to_yaml(msg.clk_b, out);
    out << "\n";
  }

  // member: clk_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clk_d: ";
    rosidl_generator_traits::value_to_yaml(msg.clk_d, out);
    out << "\n";
  }

  // member: t_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.t_acc, out);
    out << "\n";
  }

  // member: f_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.f_acc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavCLOCK & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavCLOCK & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavCLOCK & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavCLOCK>()
{
  return "ublox_msgs::msg::NavCLOCK";
}

template<>
inline const char * name<ublox_msgs::msg::NavCLOCK>()
{
  return "ublox_msgs/msg/NavCLOCK";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavCLOCK>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavCLOCK>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavCLOCK>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__TRAITS_HPP_

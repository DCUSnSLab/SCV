// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavSOL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SOL__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SOL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_sol__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavSOL & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: f_tow
  {
    out << "f_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.f_tow, out);
    out << ", ";
  }

  // member: week
  {
    out << "week: ";
    rosidl_generator_traits::value_to_yaml(msg.week, out);
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

  // member: ecef_x
  {
    out << "ecef_x: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_x, out);
    out << ", ";
  }

  // member: ecef_y
  {
    out << "ecef_y: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_y, out);
    out << ", ";
  }

  // member: ecef_z
  {
    out << "ecef_z: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_z, out);
    out << ", ";
  }

  // member: p_acc
  {
    out << "p_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.p_acc, out);
    out << ", ";
  }

  // member: ecef_vx
  {
    out << "ecef_vx: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_vx, out);
    out << ", ";
  }

  // member: ecef_vy
  {
    out << "ecef_vy: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_vy, out);
    out << ", ";
  }

  // member: ecef_vz
  {
    out << "ecef_vz: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_vz, out);
    out << ", ";
  }

  // member: s_acc
  {
    out << "s_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.s_acc, out);
    out << ", ";
  }

  // member: p_dop
  {
    out << "p_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.p_dop, out);
    out << ", ";
  }

  // member: reserved1
  {
    out << "reserved1: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved1, out);
    out << ", ";
  }

  // member: num_sv
  {
    out << "num_sv: ";
    rosidl_generator_traits::value_to_yaml(msg.num_sv, out);
    out << ", ";
  }

  // member: reserved2
  {
    out << "reserved2: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavSOL & msg,
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

  // member: f_tow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.f_tow, out);
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

  // member: ecef_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_x: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_x, out);
    out << "\n";
  }

  // member: ecef_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_y: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_y, out);
    out << "\n";
  }

  // member: ecef_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_z: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_z, out);
    out << "\n";
  }

  // member: p_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.p_acc, out);
    out << "\n";
  }

  // member: ecef_vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_vx: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_vx, out);
    out << "\n";
  }

  // member: ecef_vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_vy: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_vy, out);
    out << "\n";
  }

  // member: ecef_vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_vz: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_vz, out);
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

  // member: p_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.p_dop, out);
    out << "\n";
  }

  // member: reserved1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved1: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved1, out);
    out << "\n";
  }

  // member: num_sv
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_sv: ";
    rosidl_generator_traits::value_to_yaml(msg.num_sv, out);
    out << "\n";
  }

  // member: reserved2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved2: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavSOL & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavSOL & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavSOL & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavSOL>()
{
  return "ublox_msgs::msg::NavSOL";
}

template<>
inline const char * name<ublox_msgs::msg::NavSOL>()
{
  return "ublox_msgs/msg/NavSOL";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavSOL>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavSOL>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavSOL>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SOL__TRAITS_HPP_

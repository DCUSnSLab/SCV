// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavVELECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_velecef__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavVELECEF & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavVELECEF & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavVELECEF & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavVELECEF & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavVELECEF & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavVELECEF>()
{
  return "ublox_msgs::msg::NavVELECEF";
}

template<>
inline const char * name<ublox_msgs::msg::NavVELECEF>()
{
  return "ublox_msgs/msg/NavVELECEF";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavVELECEF>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavVELECEF>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavVELECEF>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__TRAITS_HPP_

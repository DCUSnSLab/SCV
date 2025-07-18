// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_posecef__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavPOSECEF & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavPOSECEF & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavPOSECEF & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavPOSECEF & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavPOSECEF & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavPOSECEF>()
{
  return "ublox_msgs::msg::NavPOSECEF";
}

template<>
inline const char * name<ublox_msgs::msg::NavPOSECEF>()
{
  return "ublox_msgs/msg/NavPOSECEF";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavPOSECEF>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavPOSECEF>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavPOSECEF>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__TRAITS_HPP_

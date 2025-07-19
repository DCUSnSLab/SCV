// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavPOSLLH.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_POSLLH__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_POSLLH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_posllh__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavPOSLLH & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: lon
  {
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << ", ";
  }

  // member: lat
  {
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: h_msl
  {
    out << "h_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.h_msl, out);
    out << ", ";
  }

  // member: h_acc
  {
    out << "h_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.h_acc, out);
    out << ", ";
  }

  // member: v_acc
  {
    out << "v_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.v_acc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavPOSLLH & msg,
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

  // member: lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << "\n";
  }

  // member: lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: h_msl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "h_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.h_msl, out);
    out << "\n";
  }

  // member: h_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "h_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.h_acc, out);
    out << "\n";
  }

  // member: v_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.v_acc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavPOSLLH & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavPOSLLH & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavPOSLLH & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavPOSLLH>()
{
  return "ublox_msgs::msg::NavPOSLLH";
}

template<>
inline const char * name<ublox_msgs::msg::NavPOSLLH>()
{
  return "ublox_msgs/msg/NavPOSLLH";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavPOSLLH>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavPOSLLH>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavPOSLLH>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_POSLLH__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavDGPSSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_dgpssv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavDGPSSV & msg,
  std::ostream & out)
{
  out << "{";
  // member: svid
  {
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: age_c
  {
    out << "age_c: ";
    rosidl_generator_traits::value_to_yaml(msg.age_c, out);
    out << ", ";
  }

  // member: prc
  {
    out << "prc: ";
    rosidl_generator_traits::value_to_yaml(msg.prc, out);
    out << ", ";
  }

  // member: prrc
  {
    out << "prrc: ";
    rosidl_generator_traits::value_to_yaml(msg.prrc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavDGPSSV & msg,
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

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << "\n";
  }

  // member: age_c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "age_c: ";
    rosidl_generator_traits::value_to_yaml(msg.age_c, out);
    out << "\n";
  }

  // member: prc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prc: ";
    rosidl_generator_traits::value_to_yaml(msg.prc, out);
    out << "\n";
  }

  // member: prrc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prrc: ";
    rosidl_generator_traits::value_to_yaml(msg.prrc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavDGPSSV & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavDGPSSV & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavDGPSSV & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavDGPSSV>()
{
  return "ublox_msgs::msg::NavDGPSSV";
}

template<>
inline const char * name<ublox_msgs::msg::NavDGPSSV>()
{
  return "ublox_msgs/msg/NavDGPSSV";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavDGPSSV>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavDGPSSV>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavDGPSSV>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__TRAITS_HPP_

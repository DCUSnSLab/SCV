// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavSVINFOSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_svinfosv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavSVINFOSV & msg,
  std::ostream & out)
{
  out << "{";
  // member: chn
  {
    out << "chn: ";
    rosidl_generator_traits::value_to_yaml(msg.chn, out);
    out << ", ";
  }

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

  // member: quality
  {
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
    out << ", ";
  }

  // member: cno
  {
    out << "cno: ";
    rosidl_generator_traits::value_to_yaml(msg.cno, out);
    out << ", ";
  }

  // member: elev
  {
    out << "elev: ";
    rosidl_generator_traits::value_to_yaml(msg.elev, out);
    out << ", ";
  }

  // member: azim
  {
    out << "azim: ";
    rosidl_generator_traits::value_to_yaml(msg.azim, out);
    out << ", ";
  }

  // member: pr_res
  {
    out << "pr_res: ";
    rosidl_generator_traits::value_to_yaml(msg.pr_res, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavSVINFOSV & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: chn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chn: ";
    rosidl_generator_traits::value_to_yaml(msg.chn, out);
    out << "\n";
  }

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

  // member: quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
    out << "\n";
  }

  // member: cno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cno: ";
    rosidl_generator_traits::value_to_yaml(msg.cno, out);
    out << "\n";
  }

  // member: elev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elev: ";
    rosidl_generator_traits::value_to_yaml(msg.elev, out);
    out << "\n";
  }

  // member: azim
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azim: ";
    rosidl_generator_traits::value_to_yaml(msg.azim, out);
    out << "\n";
  }

  // member: pr_res
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pr_res: ";
    rosidl_generator_traits::value_to_yaml(msg.pr_res, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavSVINFOSV & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavSVINFOSV & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavSVINFOSV & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavSVINFOSV>()
{
  return "ublox_msgs::msg::NavSVINFOSV";
}

template<>
inline const char * name<ublox_msgs::msg::NavSVINFOSV>()
{
  return "ublox_msgs/msg/NavSVINFOSV";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavSVINFOSV>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavSVINFOSV>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavSVINFOSV>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__TRAITS_HPP_

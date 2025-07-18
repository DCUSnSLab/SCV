// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_sbas__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_sbassv__traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavSBAS & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: geo
  {
    out << "geo: ";
    rosidl_generator_traits::value_to_yaml(msg.geo, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: sys
  {
    out << "sys: ";
    rosidl_generator_traits::value_to_yaml(msg.sys, out);
    out << ", ";
  }

  // member: service
  {
    out << "service: ";
    rosidl_generator_traits::value_to_yaml(msg.service, out);
    out << ", ";
  }

  // member: cnt
  {
    out << "cnt: ";
    rosidl_generator_traits::value_to_yaml(msg.cnt, out);
    out << ", ";
  }

  // member: reserved0
  {
    if (msg.reserved0.size() == 0) {
      out << "reserved0: []";
    } else {
      out << "reserved0: [";
      size_t pending_items = msg.reserved0.size();
      for (auto item : msg.reserved0) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: sv
  {
    if (msg.sv.size() == 0) {
      out << "sv: []";
    } else {
      out << "sv: [";
      size_t pending_items = msg.sv.size();
      for (auto item : msg.sv) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavSBAS & msg,
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

  // member: geo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "geo: ";
    rosidl_generator_traits::value_to_yaml(msg.geo, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: sys
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sys: ";
    rosidl_generator_traits::value_to_yaml(msg.sys, out);
    out << "\n";
  }

  // member: service
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "service: ";
    rosidl_generator_traits::value_to_yaml(msg.service, out);
    out << "\n";
  }

  // member: cnt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cnt: ";
    rosidl_generator_traits::value_to_yaml(msg.cnt, out);
    out << "\n";
  }

  // member: reserved0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved0.size() == 0) {
      out << "reserved0: []\n";
    } else {
      out << "reserved0:\n";
      for (auto item : msg.reserved0) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: sv
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sv.size() == 0) {
      out << "sv: []\n";
    } else {
      out << "sv:\n";
      for (auto item : msg.sv) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavSBAS & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavSBAS & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavSBAS & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavSBAS>()
{
  return "ublox_msgs::msg::NavSBAS";
}

template<>
inline const char * name<ublox_msgs::msg::NavSBAS>()
{
  return "ublox_msgs/msg/NavSBAS";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavSBAS>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavSBAS>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::NavSBAS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__TRAITS_HPP_

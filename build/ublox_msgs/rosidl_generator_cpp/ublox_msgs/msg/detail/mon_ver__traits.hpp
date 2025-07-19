// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/MonVER.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_VER__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_VER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/mon_ver__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'extension'
#include "ublox_msgs/msg/detail/mon_ver_extension__traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MonVER & msg,
  std::ostream & out)
{
  out << "{";
  // member: sw_version
  {
    if (msg.sw_version.size() == 0) {
      out << "sw_version: []";
    } else {
      out << "sw_version: [";
      size_t pending_items = msg.sw_version.size();
      for (auto item : msg.sw_version) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hw_version
  {
    if (msg.hw_version.size() == 0) {
      out << "hw_version: []";
    } else {
      out << "hw_version: [";
      size_t pending_items = msg.hw_version.size();
      for (auto item : msg.hw_version) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: extension
  {
    if (msg.extension.size() == 0) {
      out << "extension: []";
    } else {
      out << "extension: [";
      size_t pending_items = msg.extension.size();
      for (auto item : msg.extension) {
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
  const MonVER & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sw_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sw_version.size() == 0) {
      out << "sw_version: []\n";
    } else {
      out << "sw_version:\n";
      for (auto item : msg.sw_version) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: hw_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hw_version.size() == 0) {
      out << "hw_version: []\n";
    } else {
      out << "hw_version:\n";
      for (auto item : msg.hw_version) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: extension
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.extension.size() == 0) {
      out << "extension: []\n";
    } else {
      out << "extension:\n";
      for (auto item : msg.extension) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MonVER & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::MonVER & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::MonVER & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::MonVER>()
{
  return "ublox_msgs::msg::MonVER";
}

template<>
inline const char * name<ublox_msgs::msg::MonVER>()
{
  return "ublox_msgs/msg/MonVER";
}

template<>
struct has_fixed_size<ublox_msgs::msg::MonVER>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::MonVER>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::MonVER>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_VER__TRAITS_HPP_

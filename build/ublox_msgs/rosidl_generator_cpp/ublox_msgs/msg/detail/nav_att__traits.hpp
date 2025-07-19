// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavATT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_ATT__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_ATT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_att__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavATT & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
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

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << ", ";
  }

  // member: acc_roll
  {
    out << "acc_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_roll, out);
    out << ", ";
  }

  // member: acc_pitch
  {
    out << "acc_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_pitch, out);
    out << ", ";
  }

  // member: acc_heading
  {
    out << "acc_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_heading, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavATT & msg,
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

  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
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

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }

  // member: acc_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_roll, out);
    out << "\n";
  }

  // member: acc_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_pitch, out);
    out << "\n";
  }

  // member: acc_heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_heading, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavATT & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavATT & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavATT & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavATT>()
{
  return "ublox_msgs::msg::NavATT";
}

template<>
inline const char * name<ublox_msgs::msg::NavATT>()
{
  return "ublox_msgs/msg/NavATT";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavATT>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavATT>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavATT>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_ATT__TRAITS_HPP_

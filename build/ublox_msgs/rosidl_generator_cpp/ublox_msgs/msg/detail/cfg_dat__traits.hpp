// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgDAT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_DAT__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_DAT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_dat__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgDAT & msg,
  std::ostream & out)
{
  out << "{";
  // member: datum_num
  {
    out << "datum_num: ";
    rosidl_generator_traits::value_to_yaml(msg.datum_num, out);
    out << ", ";
  }

  // member: datum_name
  {
    if (msg.datum_name.size() == 0) {
      out << "datum_name: []";
    } else {
      out << "datum_name: [";
      size_t pending_items = msg.datum_name.size();
      for (auto item : msg.datum_name) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: maj_a
  {
    out << "maj_a: ";
    rosidl_generator_traits::value_to_yaml(msg.maj_a, out);
    out << ", ";
  }

  // member: flat
  {
    out << "flat: ";
    rosidl_generator_traits::value_to_yaml(msg.flat, out);
    out << ", ";
  }

  // member: d_x
  {
    out << "d_x: ";
    rosidl_generator_traits::value_to_yaml(msg.d_x, out);
    out << ", ";
  }

  // member: d_y
  {
    out << "d_y: ";
    rosidl_generator_traits::value_to_yaml(msg.d_y, out);
    out << ", ";
  }

  // member: d_z
  {
    out << "d_z: ";
    rosidl_generator_traits::value_to_yaml(msg.d_z, out);
    out << ", ";
  }

  // member: rot_x
  {
    out << "rot_x: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_x, out);
    out << ", ";
  }

  // member: rot_y
  {
    out << "rot_y: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_y, out);
    out << ", ";
  }

  // member: rot_z
  {
    out << "rot_z: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_z, out);
    out << ", ";
  }

  // member: scale
  {
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgDAT & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: datum_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "datum_num: ";
    rosidl_generator_traits::value_to_yaml(msg.datum_num, out);
    out << "\n";
  }

  // member: datum_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.datum_name.size() == 0) {
      out << "datum_name: []\n";
    } else {
      out << "datum_name:\n";
      for (auto item : msg.datum_name) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: maj_a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "maj_a: ";
    rosidl_generator_traits::value_to_yaml(msg.maj_a, out);
    out << "\n";
  }

  // member: flat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flat: ";
    rosidl_generator_traits::value_to_yaml(msg.flat, out);
    out << "\n";
  }

  // member: d_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d_x: ";
    rosidl_generator_traits::value_to_yaml(msg.d_x, out);
    out << "\n";
  }

  // member: d_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d_y: ";
    rosidl_generator_traits::value_to_yaml(msg.d_y, out);
    out << "\n";
  }

  // member: d_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d_z: ";
    rosidl_generator_traits::value_to_yaml(msg.d_z, out);
    out << "\n";
  }

  // member: rot_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rot_x: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_x, out);
    out << "\n";
  }

  // member: rot_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rot_y: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_y, out);
    out << "\n";
  }

  // member: rot_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rot_z: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_z, out);
    out << "\n";
  }

  // member: scale
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgDAT & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgDAT & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgDAT & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgDAT>()
{
  return "ublox_msgs::msg::CfgDAT";
}

template<>
inline const char * name<ublox_msgs::msg::CfgDAT>()
{
  return "ublox_msgs/msg/CfgDAT";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgDAT>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgDAT>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgDAT>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_DAT__TRAITS_HPP_

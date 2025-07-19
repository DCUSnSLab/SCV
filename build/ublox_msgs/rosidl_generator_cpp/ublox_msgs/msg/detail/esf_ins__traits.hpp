// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/EsfINS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_INS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_INS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/esf_ins__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EsfINS & msg,
  std::ostream & out)
{
  out << "{";
  // member: bitfield0
  {
    out << "bitfield0: ";
    rosidl_generator_traits::value_to_yaml(msg.bitfield0, out);
    out << ", ";
  }

  // member: reserved1
  {
    if (msg.reserved1.size() == 0) {
      out << "reserved1: []";
    } else {
      out << "reserved1: [";
      size_t pending_items = msg.reserved1.size();
      for (auto item : msg.reserved1) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: x_ang_rate
  {
    out << "x_ang_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.x_ang_rate, out);
    out << ", ";
  }

  // member: y_ang_rate
  {
    out << "y_ang_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.y_ang_rate, out);
    out << ", ";
  }

  // member: z_ang_rate
  {
    out << "z_ang_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.z_ang_rate, out);
    out << ", ";
  }

  // member: x_accel
  {
    out << "x_accel: ";
    rosidl_generator_traits::value_to_yaml(msg.x_accel, out);
    out << ", ";
  }

  // member: y_accel
  {
    out << "y_accel: ";
    rosidl_generator_traits::value_to_yaml(msg.y_accel, out);
    out << ", ";
  }

  // member: z_accel
  {
    out << "z_accel: ";
    rosidl_generator_traits::value_to_yaml(msg.z_accel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EsfINS & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bitfield0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bitfield0: ";
    rosidl_generator_traits::value_to_yaml(msg.bitfield0, out);
    out << "\n";
  }

  // member: reserved1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved1.size() == 0) {
      out << "reserved1: []\n";
    } else {
      out << "reserved1:\n";
      for (auto item : msg.reserved1) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: i_tow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << "\n";
  }

  // member: x_ang_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_ang_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.x_ang_rate, out);
    out << "\n";
  }

  // member: y_ang_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_ang_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.y_ang_rate, out);
    out << "\n";
  }

  // member: z_ang_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_ang_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.z_ang_rate, out);
    out << "\n";
  }

  // member: x_accel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_accel: ";
    rosidl_generator_traits::value_to_yaml(msg.x_accel, out);
    out << "\n";
  }

  // member: y_accel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_accel: ";
    rosidl_generator_traits::value_to_yaml(msg.y_accel, out);
    out << "\n";
  }

  // member: z_accel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_accel: ";
    rosidl_generator_traits::value_to_yaml(msg.z_accel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EsfINS & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::EsfINS & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::EsfINS & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::EsfINS>()
{
  return "ublox_msgs::msg::EsfINS";
}

template<>
inline const char * name<ublox_msgs::msg::EsfINS>()
{
  return "ublox_msgs/msg/EsfINS";
}

template<>
struct has_fixed_size<ublox_msgs::msg::EsfINS>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::EsfINS>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::EsfINS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_INS__TRAITS_HPP_

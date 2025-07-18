// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/EsfSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/esf_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'sens'
#include "ublox_msgs/msg/detail/esf_status_sens__traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EsfSTATUS & msg,
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

  // member: fusion_mode
  {
    out << "fusion_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.fusion_mode, out);
    out << ", ";
  }

  // member: reserved2
  {
    if (msg.reserved2.size() == 0) {
      out << "reserved2: []";
    } else {
      out << "reserved2: [";
      size_t pending_items = msg.reserved2.size();
      for (auto item : msg.reserved2) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: num_sens
  {
    out << "num_sens: ";
    rosidl_generator_traits::value_to_yaml(msg.num_sens, out);
    out << ", ";
  }

  // member: sens
  {
    if (msg.sens.size() == 0) {
      out << "sens: []";
    } else {
      out << "sens: [";
      size_t pending_items = msg.sens.size();
      for (auto item : msg.sens) {
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
  const EsfSTATUS & msg,
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

  // member: fusion_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fusion_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.fusion_mode, out);
    out << "\n";
  }

  // member: reserved2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved2.size() == 0) {
      out << "reserved2: []\n";
    } else {
      out << "reserved2:\n";
      for (auto item : msg.reserved2) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: num_sens
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_sens: ";
    rosidl_generator_traits::value_to_yaml(msg.num_sens, out);
    out << "\n";
  }

  // member: sens
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sens.size() == 0) {
      out << "sens: []\n";
    } else {
      out << "sens:\n";
      for (auto item : msg.sens) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EsfSTATUS & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::EsfSTATUS & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::EsfSTATUS & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::EsfSTATUS>()
{
  return "ublox_msgs::msg::EsfSTATUS";
}

template<>
inline const char * name<ublox_msgs::msg::EsfSTATUS>()
{
  return "ublox_msgs/msg/EsfSTATUS";
}

template<>
struct has_fixed_size<ublox_msgs::msg::EsfSTATUS>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::EsfSTATUS>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::EsfSTATUS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__TRAITS_HPP_

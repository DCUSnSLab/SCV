// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/AidEPH.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_EPH__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_EPH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/aid_eph__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AidEPH & msg,
  std::ostream & out)
{
  out << "{";
  // member: svid
  {
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << ", ";
  }

  // member: how
  {
    out << "how: ";
    rosidl_generator_traits::value_to_yaml(msg.how, out);
    out << ", ";
  }

  // member: sf1d
  {
    if (msg.sf1d.size() == 0) {
      out << "sf1d: []";
    } else {
      out << "sf1d: [";
      size_t pending_items = msg.sf1d.size();
      for (auto item : msg.sf1d) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: sf2d
  {
    if (msg.sf2d.size() == 0) {
      out << "sf2d: []";
    } else {
      out << "sf2d: [";
      size_t pending_items = msg.sf2d.size();
      for (auto item : msg.sf2d) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: sf3d
  {
    if (msg.sf3d.size() == 0) {
      out << "sf3d: []";
    } else {
      out << "sf3d: [";
      size_t pending_items = msg.sf3d.size();
      for (auto item : msg.sf3d) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const AidEPH & msg,
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

  // member: how
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "how: ";
    rosidl_generator_traits::value_to_yaml(msg.how, out);
    out << "\n";
  }

  // member: sf1d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sf1d.size() == 0) {
      out << "sf1d: []\n";
    } else {
      out << "sf1d:\n";
      for (auto item : msg.sf1d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: sf2d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sf2d.size() == 0) {
      out << "sf2d: []\n";
    } else {
      out << "sf2d:\n";
      for (auto item : msg.sf2d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: sf3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sf3d.size() == 0) {
      out << "sf3d: []\n";
    } else {
      out << "sf3d:\n";
      for (auto item : msg.sf3d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AidEPH & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::AidEPH & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::AidEPH & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::AidEPH>()
{
  return "ublox_msgs::msg::AidEPH";
}

template<>
inline const char * name<ublox_msgs::msg::AidEPH>()
{
  return "ublox_msgs/msg/AidEPH";
}

template<>
struct has_fixed_size<ublox_msgs::msg::AidEPH>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::AidEPH>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::AidEPH>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_EPH__TRAITS_HPP_

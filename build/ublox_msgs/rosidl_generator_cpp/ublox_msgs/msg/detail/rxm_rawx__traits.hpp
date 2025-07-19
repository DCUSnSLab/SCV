// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/RxmRAWX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/rxm_rawx__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'meas'
#include "ublox_msgs/msg/detail/rxm_rawx_meas__traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RxmRAWX & msg,
  std::ostream & out)
{
  out << "{";
  // member: rcv_tow
  {
    out << "rcv_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.rcv_tow, out);
    out << ", ";
  }

  // member: week
  {
    out << "week: ";
    rosidl_generator_traits::value_to_yaml(msg.week, out);
    out << ", ";
  }

  // member: leap_s
  {
    out << "leap_s: ";
    rosidl_generator_traits::value_to_yaml(msg.leap_s, out);
    out << ", ";
  }

  // member: num_meas
  {
    out << "num_meas: ";
    rosidl_generator_traits::value_to_yaml(msg.num_meas, out);
    out << ", ";
  }

  // member: rec_stat
  {
    out << "rec_stat: ";
    rosidl_generator_traits::value_to_yaml(msg.rec_stat, out);
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

  // member: meas
  {
    if (msg.meas.size() == 0) {
      out << "meas: []";
    } else {
      out << "meas: [";
      size_t pending_items = msg.meas.size();
      for (auto item : msg.meas) {
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
  const RxmRAWX & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: rcv_tow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rcv_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.rcv_tow, out);
    out << "\n";
  }

  // member: week
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "week: ";
    rosidl_generator_traits::value_to_yaml(msg.week, out);
    out << "\n";
  }

  // member: leap_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leap_s: ";
    rosidl_generator_traits::value_to_yaml(msg.leap_s, out);
    out << "\n";
  }

  // member: num_meas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_meas: ";
    rosidl_generator_traits::value_to_yaml(msg.num_meas, out);
    out << "\n";
  }

  // member: rec_stat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rec_stat: ";
    rosidl_generator_traits::value_to_yaml(msg.rec_stat, out);
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

  // member: meas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.meas.size() == 0) {
      out << "meas: []\n";
    } else {
      out << "meas:\n";
      for (auto item : msg.meas) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RxmRAWX & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::RxmRAWX & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::RxmRAWX & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::RxmRAWX>()
{
  return "ublox_msgs::msg::RxmRAWX";
}

template<>
inline const char * name<ublox_msgs::msg::RxmRAWX>()
{
  return "ublox_msgs/msg/RxmRAWX";
}

template<>
struct has_fixed_size<ublox_msgs::msg::RxmRAWX>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::RxmRAWX>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::RxmRAWX>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__TRAITS_HPP_

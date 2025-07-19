// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/TimTM2.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__TIM_TM2__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__TIM_TM2__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/tim_tm2__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TimTM2 & msg,
  std::ostream & out)
{
  out << "{";
  // member: ch
  {
    out << "ch: ";
    rosidl_generator_traits::value_to_yaml(msg.ch, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: rising_edge_count
  {
    out << "rising_edge_count: ";
    rosidl_generator_traits::value_to_yaml(msg.rising_edge_count, out);
    out << ", ";
  }

  // member: wn_r
  {
    out << "wn_r: ";
    rosidl_generator_traits::value_to_yaml(msg.wn_r, out);
    out << ", ";
  }

  // member: wn_f
  {
    out << "wn_f: ";
    rosidl_generator_traits::value_to_yaml(msg.wn_f, out);
    out << ", ";
  }

  // member: tow_ms_r
  {
    out << "tow_ms_r: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_ms_r, out);
    out << ", ";
  }

  // member: tow_sub_ms_r
  {
    out << "tow_sub_ms_r: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_sub_ms_r, out);
    out << ", ";
  }

  // member: tow_ms_f
  {
    out << "tow_ms_f: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_ms_f, out);
    out << ", ";
  }

  // member: tow_sub_ms_f
  {
    out << "tow_sub_ms_f: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_sub_ms_f, out);
    out << ", ";
  }

  // member: acc_est
  {
    out << "acc_est: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_est, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TimTM2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch: ";
    rosidl_generator_traits::value_to_yaml(msg.ch, out);
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

  // member: rising_edge_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rising_edge_count: ";
    rosidl_generator_traits::value_to_yaml(msg.rising_edge_count, out);
    out << "\n";
  }

  // member: wn_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wn_r: ";
    rosidl_generator_traits::value_to_yaml(msg.wn_r, out);
    out << "\n";
  }

  // member: wn_f
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wn_f: ";
    rosidl_generator_traits::value_to_yaml(msg.wn_f, out);
    out << "\n";
  }

  // member: tow_ms_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tow_ms_r: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_ms_r, out);
    out << "\n";
  }

  // member: tow_sub_ms_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tow_sub_ms_r: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_sub_ms_r, out);
    out << "\n";
  }

  // member: tow_ms_f
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tow_ms_f: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_ms_f, out);
    out << "\n";
  }

  // member: tow_sub_ms_f
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tow_sub_ms_f: ";
    rosidl_generator_traits::value_to_yaml(msg.tow_sub_ms_f, out);
    out << "\n";
  }

  // member: acc_est
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_est: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_est, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TimTM2 & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::TimTM2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::TimTM2 & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::TimTM2>()
{
  return "ublox_msgs::msg::TimTM2";
}

template<>
inline const char * name<ublox_msgs::msg::TimTM2>()
{
  return "ublox_msgs/msg/TimTM2";
}

template<>
struct has_fixed_size<ublox_msgs::msg::TimTM2>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::TimTM2>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::TimTM2>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__TIM_TM2__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/EsfRAWBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/esf_raw_block__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EsfRAWBlock & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << ", ";
  }

  // member: s_t_tag
  {
    out << "s_t_tag: ";
    rosidl_generator_traits::value_to_yaml(msg.s_t_tag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EsfRAWBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }

  // member: s_t_tag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "s_t_tag: ";
    rosidl_generator_traits::value_to_yaml(msg.s_t_tag, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EsfRAWBlock & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::EsfRAWBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::EsfRAWBlock & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::EsfRAWBlock>()
{
  return "ublox_msgs::msg::EsfRAWBlock";
}

template<>
inline const char * name<ublox_msgs::msg::EsfRAWBlock>()
{
  return "ublox_msgs/msg/EsfRAWBlock";
}

template<>
struct has_fixed_size<ublox_msgs::msg::EsfRAWBlock>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::EsfRAWBlock>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::EsfRAWBlock>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__TRAITS_HPP_

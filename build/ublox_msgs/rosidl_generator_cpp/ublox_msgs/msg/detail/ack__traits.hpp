// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/Ack.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ACK__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/ack__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Ack & msg,
  std::ostream & out)
{
  out << "{";
  // member: cls_id
  {
    out << "cls_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cls_id, out);
    out << ", ";
  }

  // member: msg_id
  {
    out << "msg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Ack & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cls_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cls_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cls_id, out);
    out << "\n";
  }

  // member: msg_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Ack & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::Ack & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::Ack & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::Ack>()
{
  return "ublox_msgs::msg::Ack";
}

template<>
inline const char * name<ublox_msgs::msg::Ack>()
{
  return "ublox_msgs/msg/Ack";
}

template<>
struct has_fixed_size<ublox_msgs::msg::Ack>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::Ack>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::Ack>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__ACK__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgPRT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_PRT__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_PRT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_prt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgPRT & msg,
  std::ostream & out)
{
  out << "{";
  // member: port_id
  {
    out << "port_id: ";
    rosidl_generator_traits::value_to_yaml(msg.port_id, out);
    out << ", ";
  }

  // member: reserved0
  {
    out << "reserved0: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved0, out);
    out << ", ";
  }

  // member: tx_ready
  {
    out << "tx_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.tx_ready, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: baud_rate
  {
    out << "baud_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.baud_rate, out);
    out << ", ";
  }

  // member: in_proto_mask
  {
    out << "in_proto_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.in_proto_mask, out);
    out << ", ";
  }

  // member: out_proto_mask
  {
    out << "out_proto_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.out_proto_mask, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: reserved1
  {
    out << "reserved1: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved1, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgPRT & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: port_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "port_id: ";
    rosidl_generator_traits::value_to_yaml(msg.port_id, out);
    out << "\n";
  }

  // member: reserved0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved0: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved0, out);
    out << "\n";
  }

  // member: tx_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tx_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.tx_ready, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: baud_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "baud_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.baud_rate, out);
    out << "\n";
  }

  // member: in_proto_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "in_proto_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.in_proto_mask, out);
    out << "\n";
  }

  // member: out_proto_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "out_proto_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.out_proto_mask, out);
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

  // member: reserved1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved1: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved1, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgPRT & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgPRT & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgPRT & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgPRT>()
{
  return "ublox_msgs::msg::CfgPRT";
}

template<>
inline const char * name<ublox_msgs::msg::CfgPRT>()
{
  return "ublox_msgs/msg/CfgPRT";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgPRT>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgPRT>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgPRT>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_PRT__TRAITS_HPP_

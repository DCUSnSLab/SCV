// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgINFBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_inf_block__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgINFBlock & msg,
  std::ostream & out)
{
  out << "{";
  // member: protocol_id
  {
    out << "protocol_id: ";
    rosidl_generator_traits::value_to_yaml(msg.protocol_id, out);
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

  // member: inf_msg_mask
  {
    if (msg.inf_msg_mask.size() == 0) {
      out << "inf_msg_mask: []";
    } else {
      out << "inf_msg_mask: [";
      size_t pending_items = msg.inf_msg_mask.size();
      for (auto item : msg.inf_msg_mask) {
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
  const CfgINFBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: protocol_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "protocol_id: ";
    rosidl_generator_traits::value_to_yaml(msg.protocol_id, out);
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

  // member: inf_msg_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.inf_msg_mask.size() == 0) {
      out << "inf_msg_mask: []\n";
    } else {
      out << "inf_msg_mask:\n";
      for (auto item : msg.inf_msg_mask) {
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

inline std::string to_yaml(const CfgINFBlock & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgINFBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgINFBlock & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgINFBlock>()
{
  return "ublox_msgs::msg::CfgINFBlock";
}

template<>
inline const char * name<ublox_msgs::msg::CfgINFBlock>()
{
  return "ublox_msgs/msg/CfgINFBlock";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgINFBlock>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgINFBlock>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgINFBlock>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__TRAITS_HPP_

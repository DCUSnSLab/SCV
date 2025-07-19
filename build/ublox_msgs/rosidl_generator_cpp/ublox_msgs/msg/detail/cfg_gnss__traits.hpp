// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_gnss__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'blocks'
#include "ublox_msgs/msg/detail/cfg_gnss_block__traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgGNSS & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg_ver
  {
    out << "msg_ver: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_ver, out);
    out << ", ";
  }

  // member: num_trk_ch_hw
  {
    out << "num_trk_ch_hw: ";
    rosidl_generator_traits::value_to_yaml(msg.num_trk_ch_hw, out);
    out << ", ";
  }

  // member: num_trk_ch_use
  {
    out << "num_trk_ch_use: ";
    rosidl_generator_traits::value_to_yaml(msg.num_trk_ch_use, out);
    out << ", ";
  }

  // member: num_config_blocks
  {
    out << "num_config_blocks: ";
    rosidl_generator_traits::value_to_yaml(msg.num_config_blocks, out);
    out << ", ";
  }

  // member: blocks
  {
    if (msg.blocks.size() == 0) {
      out << "blocks: []";
    } else {
      out << "blocks: [";
      size_t pending_items = msg.blocks.size();
      for (auto item : msg.blocks) {
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
  const CfgGNSS & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: msg_ver
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg_ver: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_ver, out);
    out << "\n";
  }

  // member: num_trk_ch_hw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_trk_ch_hw: ";
    rosidl_generator_traits::value_to_yaml(msg.num_trk_ch_hw, out);
    out << "\n";
  }

  // member: num_trk_ch_use
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_trk_ch_use: ";
    rosidl_generator_traits::value_to_yaml(msg.num_trk_ch_use, out);
    out << "\n";
  }

  // member: num_config_blocks
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_config_blocks: ";
    rosidl_generator_traits::value_to_yaml(msg.num_config_blocks, out);
    out << "\n";
  }

  // member: blocks
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.blocks.size() == 0) {
      out << "blocks: []\n";
    } else {
      out << "blocks:\n";
      for (auto item : msg.blocks) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgGNSS & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgGNSS & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgGNSS & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgGNSS>()
{
  return "ublox_msgs::msg::CfgGNSS";
}

template<>
inline const char * name<ublox_msgs::msg::CfgGNSS>()
{
  return "ublox_msgs/msg/CfgGNSS";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgGNSS>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgGNSS>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::CfgGNSS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__TRAITS_HPP_

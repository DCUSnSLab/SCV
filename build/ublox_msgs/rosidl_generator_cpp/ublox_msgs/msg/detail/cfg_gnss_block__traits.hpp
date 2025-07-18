// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgGNSSBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_gnss_block__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgGNSSBlock & msg,
  std::ostream & out)
{
  out << "{";
  // member: gnss_id
  {
    out << "gnss_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_id, out);
    out << ", ";
  }

  // member: res_trk_ch
  {
    out << "res_trk_ch: ";
    rosidl_generator_traits::value_to_yaml(msg.res_trk_ch, out);
    out << ", ";
  }

  // member: max_trk_ch
  {
    out << "max_trk_ch: ";
    rosidl_generator_traits::value_to_yaml(msg.max_trk_ch, out);
    out << ", ";
  }

  // member: reserved1
  {
    out << "reserved1: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved1, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgGNSSBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gnss_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_id, out);
    out << "\n";
  }

  // member: res_trk_ch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "res_trk_ch: ";
    rosidl_generator_traits::value_to_yaml(msg.res_trk_ch, out);
    out << "\n";
  }

  // member: max_trk_ch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_trk_ch: ";
    rosidl_generator_traits::value_to_yaml(msg.max_trk_ch, out);
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

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgGNSSBlock & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgGNSSBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgGNSSBlock & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgGNSSBlock>()
{
  return "ublox_msgs::msg::CfgGNSSBlock";
}

template<>
inline const char * name<ublox_msgs::msg::CfgGNSSBlock>()
{
  return "ublox_msgs/msg/CfgGNSSBlock";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgGNSSBlock>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgGNSSBlock>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgGNSSBlock>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/RxmSFRB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/rxm_sfrb__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RxmSFRB & msg,
  std::ostream & out)
{
  out << "{";
  // member: chn
  {
    out << "chn: ";
    rosidl_generator_traits::value_to_yaml(msg.chn, out);
    out << ", ";
  }

  // member: svid
  {
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << ", ";
  }

  // member: dwrd
  {
    if (msg.dwrd.size() == 0) {
      out << "dwrd: []";
    } else {
      out << "dwrd: [";
      size_t pending_items = msg.dwrd.size();
      for (auto item : msg.dwrd) {
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
  const RxmSFRB & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: chn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chn: ";
    rosidl_generator_traits::value_to_yaml(msg.chn, out);
    out << "\n";
  }

  // member: svid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << "\n";
  }

  // member: dwrd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dwrd.size() == 0) {
      out << "dwrd: []\n";
    } else {
      out << "dwrd:\n";
      for (auto item : msg.dwrd) {
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

inline std::string to_yaml(const RxmSFRB & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::RxmSFRB & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::RxmSFRB & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::RxmSFRB>()
{
  return "ublox_msgs::msg::RxmSFRB";
}

template<>
inline const char * name<ublox_msgs::msg::RxmSFRB>()
{
  return "ublox_msgs/msg/RxmSFRB";
}

template<>
struct has_fixed_size<ublox_msgs::msg::RxmSFRB>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::RxmSFRB>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::RxmSFRB>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__TRAITS_HPP_

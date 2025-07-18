// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/RxmSVSISV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/rxm_svsisv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RxmSVSISV & msg,
  std::ostream & out)
{
  out << "{";
  // member: svid
  {
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << ", ";
  }

  // member: sv_flag
  {
    out << "sv_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.sv_flag, out);
    out << ", ";
  }

  // member: azim
  {
    out << "azim: ";
    rosidl_generator_traits::value_to_yaml(msg.azim, out);
    out << ", ";
  }

  // member: elev
  {
    out << "elev: ";
    rosidl_generator_traits::value_to_yaml(msg.elev, out);
    out << ", ";
  }

  // member: age
  {
    out << "age: ";
    rosidl_generator_traits::value_to_yaml(msg.age, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RxmSVSISV & msg,
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

  // member: sv_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sv_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.sv_flag, out);
    out << "\n";
  }

  // member: azim
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azim: ";
    rosidl_generator_traits::value_to_yaml(msg.azim, out);
    out << "\n";
  }

  // member: elev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elev: ";
    rosidl_generator_traits::value_to_yaml(msg.elev, out);
    out << "\n";
  }

  // member: age
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "age: ";
    rosidl_generator_traits::value_to_yaml(msg.age, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RxmSVSISV & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::RxmSVSISV & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::RxmSVSISV & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::RxmSVSISV>()
{
  return "ublox_msgs::msg::RxmSVSISV";
}

template<>
inline const char * name<ublox_msgs::msg::RxmSVSISV>()
{
  return "ublox_msgs/msg/RxmSVSISV";
}

template<>
struct has_fixed_size<ublox_msgs::msg::RxmSVSISV>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::RxmSVSISV>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::RxmSVSISV>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__TRAITS_HPP_

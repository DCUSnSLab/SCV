// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/EsfSTATUSSens.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/esf_status_sens__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EsfSTATUSSens & msg,
  std::ostream & out)
{
  out << "{";
  // member: sens_status1
  {
    out << "sens_status1: ";
    rosidl_generator_traits::value_to_yaml(msg.sens_status1, out);
    out << ", ";
  }

  // member: sens_status2
  {
    out << "sens_status2: ";
    rosidl_generator_traits::value_to_yaml(msg.sens_status2, out);
    out << ", ";
  }

  // member: freq
  {
    out << "freq: ";
    rosidl_generator_traits::value_to_yaml(msg.freq, out);
    out << ", ";
  }

  // member: faults
  {
    out << "faults: ";
    rosidl_generator_traits::value_to_yaml(msg.faults, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EsfSTATUSSens & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sens_status1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sens_status1: ";
    rosidl_generator_traits::value_to_yaml(msg.sens_status1, out);
    out << "\n";
  }

  // member: sens_status2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sens_status2: ";
    rosidl_generator_traits::value_to_yaml(msg.sens_status2, out);
    out << "\n";
  }

  // member: freq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "freq: ";
    rosidl_generator_traits::value_to_yaml(msg.freq, out);
    out << "\n";
  }

  // member: faults
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "faults: ";
    rosidl_generator_traits::value_to_yaml(msg.faults, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EsfSTATUSSens & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::EsfSTATUSSens & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::EsfSTATUSSens & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::EsfSTATUSSens>()
{
  return "ublox_msgs::msg::EsfSTATUSSens";
}

template<>
inline const char * name<ublox_msgs::msg::EsfSTATUSSens>()
{
  return "ublox_msgs/msg/EsfSTATUSSens";
}

template<>
struct has_fixed_size<ublox_msgs::msg::EsfSTATUSSens>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::EsfSTATUSSens>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::EsfSTATUSSens>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__TRAITS_HPP_

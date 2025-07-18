// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/RxmRAWSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/rxm_rawsv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RxmRAWSV & msg,
  std::ostream & out)
{
  out << "{";
  // member: cp_mes
  {
    out << "cp_mes: ";
    rosidl_generator_traits::value_to_yaml(msg.cp_mes, out);
    out << ", ";
  }

  // member: pr_mes
  {
    out << "pr_mes: ";
    rosidl_generator_traits::value_to_yaml(msg.pr_mes, out);
    out << ", ";
  }

  // member: do_mes
  {
    out << "do_mes: ";
    rosidl_generator_traits::value_to_yaml(msg.do_mes, out);
    out << ", ";
  }

  // member: sv
  {
    out << "sv: ";
    rosidl_generator_traits::value_to_yaml(msg.sv, out);
    out << ", ";
  }

  // member: mes_qi
  {
    out << "mes_qi: ";
    rosidl_generator_traits::value_to_yaml(msg.mes_qi, out);
    out << ", ";
  }

  // member: cno
  {
    out << "cno: ";
    rosidl_generator_traits::value_to_yaml(msg.cno, out);
    out << ", ";
  }

  // member: lli
  {
    out << "lli: ";
    rosidl_generator_traits::value_to_yaml(msg.lli, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RxmRAWSV & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cp_mes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cp_mes: ";
    rosidl_generator_traits::value_to_yaml(msg.cp_mes, out);
    out << "\n";
  }

  // member: pr_mes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pr_mes: ";
    rosidl_generator_traits::value_to_yaml(msg.pr_mes, out);
    out << "\n";
  }

  // member: do_mes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "do_mes: ";
    rosidl_generator_traits::value_to_yaml(msg.do_mes, out);
    out << "\n";
  }

  // member: sv
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sv: ";
    rosidl_generator_traits::value_to_yaml(msg.sv, out);
    out << "\n";
  }

  // member: mes_qi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mes_qi: ";
    rosidl_generator_traits::value_to_yaml(msg.mes_qi, out);
    out << "\n";
  }

  // member: cno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cno: ";
    rosidl_generator_traits::value_to_yaml(msg.cno, out);
    out << "\n";
  }

  // member: lli
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lli: ";
    rosidl_generator_traits::value_to_yaml(msg.lli, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RxmRAWSV & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::RxmRAWSV & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::RxmRAWSV & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::RxmRAWSV>()
{
  return "ublox_msgs::msg::RxmRAWSV";
}

template<>
inline const char * name<ublox_msgs::msg::RxmRAWSV>()
{
  return "ublox_msgs/msg/RxmRAWSV";
}

template<>
struct has_fixed_size<ublox_msgs::msg::RxmRAWSV>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::RxmRAWSV>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::RxmRAWSV>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__TRAITS_HPP_

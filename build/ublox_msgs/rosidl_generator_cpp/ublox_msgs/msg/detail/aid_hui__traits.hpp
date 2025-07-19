// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/AidHUI.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_HUI__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_HUI__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/aid_hui__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AidHUI & msg,
  std::ostream & out)
{
  out << "{";
  // member: health
  {
    out << "health: ";
    rosidl_generator_traits::value_to_yaml(msg.health, out);
    out << ", ";
  }

  // member: utc_a0
  {
    out << "utc_a0: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_a0, out);
    out << ", ";
  }

  // member: utc_a1
  {
    out << "utc_a1: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_a1, out);
    out << ", ";
  }

  // member: utc_tow
  {
    out << "utc_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_tow, out);
    out << ", ";
  }

  // member: utc_wnt
  {
    out << "utc_wnt: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_wnt, out);
    out << ", ";
  }

  // member: utc_ls
  {
    out << "utc_ls: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_ls, out);
    out << ", ";
  }

  // member: utc_wnf
  {
    out << "utc_wnf: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_wnf, out);
    out << ", ";
  }

  // member: utc_dn
  {
    out << "utc_dn: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_dn, out);
    out << ", ";
  }

  // member: utc_lsf
  {
    out << "utc_lsf: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_lsf, out);
    out << ", ";
  }

  // member: utc_spare
  {
    out << "utc_spare: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_spare, out);
    out << ", ";
  }

  // member: klob_a0
  {
    out << "klob_a0: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a0, out);
    out << ", ";
  }

  // member: klob_a1
  {
    out << "klob_a1: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a1, out);
    out << ", ";
  }

  // member: klob_a2
  {
    out << "klob_a2: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a2, out);
    out << ", ";
  }

  // member: klob_a3
  {
    out << "klob_a3: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a3, out);
    out << ", ";
  }

  // member: klob_b0
  {
    out << "klob_b0: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b0, out);
    out << ", ";
  }

  // member: klob_b1
  {
    out << "klob_b1: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b1, out);
    out << ", ";
  }

  // member: klob_b2
  {
    out << "klob_b2: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b2, out);
    out << ", ";
  }

  // member: klob_b3
  {
    out << "klob_b3: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b3, out);
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
  const AidHUI & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "health: ";
    rosidl_generator_traits::value_to_yaml(msg.health, out);
    out << "\n";
  }

  // member: utc_a0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_a0: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_a0, out);
    out << "\n";
  }

  // member: utc_a1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_a1: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_a1, out);
    out << "\n";
  }

  // member: utc_tow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_tow, out);
    out << "\n";
  }

  // member: utc_wnt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_wnt: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_wnt, out);
    out << "\n";
  }

  // member: utc_ls
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_ls: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_ls, out);
    out << "\n";
  }

  // member: utc_wnf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_wnf: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_wnf, out);
    out << "\n";
  }

  // member: utc_dn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_dn: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_dn, out);
    out << "\n";
  }

  // member: utc_lsf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_lsf: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_lsf, out);
    out << "\n";
  }

  // member: utc_spare
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_spare: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_spare, out);
    out << "\n";
  }

  // member: klob_a0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_a0: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a0, out);
    out << "\n";
  }

  // member: klob_a1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_a1: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a1, out);
    out << "\n";
  }

  // member: klob_a2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_a2: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a2, out);
    out << "\n";
  }

  // member: klob_a3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_a3: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_a3, out);
    out << "\n";
  }

  // member: klob_b0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_b0: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b0, out);
    out << "\n";
  }

  // member: klob_b1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_b1: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b1, out);
    out << "\n";
  }

  // member: klob_b2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_b2: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b2, out);
    out << "\n";
  }

  // member: klob_b3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "klob_b3: ";
    rosidl_generator_traits::value_to_yaml(msg.klob_b3, out);
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

inline std::string to_yaml(const AidHUI & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::AidHUI & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::AidHUI & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::AidHUI>()
{
  return "ublox_msgs::msg::AidHUI";
}

template<>
inline const char * name<ublox_msgs::msg::AidHUI>()
{
  return "ublox_msgs/msg/AidHUI";
}

template<>
struct has_fixed_size<ublox_msgs::msg::AidHUI>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::AidHUI>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::AidHUI>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_HUI__TRAITS_HPP_

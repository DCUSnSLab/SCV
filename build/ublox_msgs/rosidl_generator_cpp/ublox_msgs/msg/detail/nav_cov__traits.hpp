// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavCOV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_COV__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_COV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_cov__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavCOV & msg,
  std::ostream & out)
{
  out << "{";
  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: pos_cov_valid
  {
    out << "pos_cov_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_valid, out);
    out << ", ";
  }

  // member: vel_cov_valid
  {
    out << "vel_cov_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_valid, out);
    out << ", ";
  }

  // member: reserved_0
  {
    if (msg.reserved_0.size() == 0) {
      out << "reserved_0: []";
    } else {
      out << "reserved_0: [";
      size_t pending_items = msg.reserved_0.size();
      for (auto item : msg.reserved_0) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pos_cov_nn
  {
    out << "pos_cov_nn: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_nn, out);
    out << ", ";
  }

  // member: pos_cov_ne
  {
    out << "pos_cov_ne: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_ne, out);
    out << ", ";
  }

  // member: pos_cov_nd
  {
    out << "pos_cov_nd: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_nd, out);
    out << ", ";
  }

  // member: pos_cov_ee
  {
    out << "pos_cov_ee: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_ee, out);
    out << ", ";
  }

  // member: pos_cov_ed
  {
    out << "pos_cov_ed: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_ed, out);
    out << ", ";
  }

  // member: pos_cov_dd
  {
    out << "pos_cov_dd: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_dd, out);
    out << ", ";
  }

  // member: vel_cov_nn
  {
    out << "vel_cov_nn: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_nn, out);
    out << ", ";
  }

  // member: vel_cov_ne
  {
    out << "vel_cov_ne: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_ne, out);
    out << ", ";
  }

  // member: vel_cov_nd
  {
    out << "vel_cov_nd: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_nd, out);
    out << ", ";
  }

  // member: vel_cov_ee
  {
    out << "vel_cov_ee: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_ee, out);
    out << ", ";
  }

  // member: vel_cov_ed
  {
    out << "vel_cov_ed: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_ed, out);
    out << ", ";
  }

  // member: vel_cov_dd
  {
    out << "vel_cov_dd: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_dd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavCOV & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: i_tow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << "\n";
  }

  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }

  // member: pos_cov_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cov_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_valid, out);
    out << "\n";
  }

  // member: vel_cov_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_cov_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_valid, out);
    out << "\n";
  }

  // member: reserved_0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved_0.size() == 0) {
      out << "reserved_0: []\n";
    } else {
      out << "reserved_0:\n";
      for (auto item : msg.reserved_0) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: pos_cov_nn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cov_nn: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_nn, out);
    out << "\n";
  }

  // member: pos_cov_ne
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cov_ne: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_ne, out);
    out << "\n";
  }

  // member: pos_cov_nd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cov_nd: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_nd, out);
    out << "\n";
  }

  // member: pos_cov_ee
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cov_ee: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_ee, out);
    out << "\n";
  }

  // member: pos_cov_ed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cov_ed: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_ed, out);
    out << "\n";
  }

  // member: pos_cov_dd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cov_dd: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_cov_dd, out);
    out << "\n";
  }

  // member: vel_cov_nn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_cov_nn: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_nn, out);
    out << "\n";
  }

  // member: vel_cov_ne
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_cov_ne: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_ne, out);
    out << "\n";
  }

  // member: vel_cov_nd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_cov_nd: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_nd, out);
    out << "\n";
  }

  // member: vel_cov_ee
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_cov_ee: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_ee, out);
    out << "\n";
  }

  // member: vel_cov_ed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_cov_ed: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_ed, out);
    out << "\n";
  }

  // member: vel_cov_dd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_cov_dd: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_cov_dd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavCOV & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavCOV & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavCOV & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavCOV>()
{
  return "ublox_msgs::msg::NavCOV";
}

template<>
inline const char * name<ublox_msgs::msg::NavCOV>()
{
  return "ublox_msgs/msg/NavCOV";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavCOV>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavCOV>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavCOV>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_COV__TRAITS_HPP_

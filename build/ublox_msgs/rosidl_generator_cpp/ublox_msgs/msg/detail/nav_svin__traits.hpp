// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/NavSVIN.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/nav_svin__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavSVIN & msg,
  std::ostream & out)
{
  out << "{";
  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: reserved0
  {
    if (msg.reserved0.size() == 0) {
      out << "reserved0: []";
    } else {
      out << "reserved0: [";
      size_t pending_items = msg.reserved0.size();
      for (auto item : msg.reserved0) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: i_tow
  {
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << ", ";
  }

  // member: dur
  {
    out << "dur: ";
    rosidl_generator_traits::value_to_yaml(msg.dur, out);
    out << ", ";
  }

  // member: mean_x
  {
    out << "mean_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_x, out);
    out << ", ";
  }

  // member: mean_y
  {
    out << "mean_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_y, out);
    out << ", ";
  }

  // member: mean_z
  {
    out << "mean_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_z, out);
    out << ", ";
  }

  // member: mean_xhp
  {
    out << "mean_xhp: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_xhp, out);
    out << ", ";
  }

  // member: mean_yhp
  {
    out << "mean_yhp: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_yhp, out);
    out << ", ";
  }

  // member: mean_zhp
  {
    out << "mean_zhp: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_zhp, out);
    out << ", ";
  }

  // member: reserved1
  {
    out << "reserved1: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved1, out);
    out << ", ";
  }

  // member: mean_acc
  {
    out << "mean_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_acc, out);
    out << ", ";
  }

  // member: obs
  {
    out << "obs: ";
    rosidl_generator_traits::value_to_yaml(msg.obs, out);
    out << ", ";
  }

  // member: valid
  {
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << ", ";
  }

  // member: active
  {
    out << "active: ";
    rosidl_generator_traits::value_to_yaml(msg.active, out);
    out << ", ";
  }

  // member: reserved3
  {
    if (msg.reserved3.size() == 0) {
      out << "reserved3: []";
    } else {
      out << "reserved3: [";
      size_t pending_items = msg.reserved3.size();
      for (auto item : msg.reserved3) {
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
  const NavSVIN & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }

  // member: reserved0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved0.size() == 0) {
      out << "reserved0: []\n";
    } else {
      out << "reserved0:\n";
      for (auto item : msg.reserved0) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: i_tow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i_tow: ";
    rosidl_generator_traits::value_to_yaml(msg.i_tow, out);
    out << "\n";
  }

  // member: dur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dur: ";
    rosidl_generator_traits::value_to_yaml(msg.dur, out);
    out << "\n";
  }

  // member: mean_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_x, out);
    out << "\n";
  }

  // member: mean_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_y, out);
    out << "\n";
  }

  // member: mean_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_z, out);
    out << "\n";
  }

  // member: mean_xhp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_xhp: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_xhp, out);
    out << "\n";
  }

  // member: mean_yhp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_yhp: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_yhp, out);
    out << "\n";
  }

  // member: mean_zhp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_zhp: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_zhp, out);
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

  // member: mean_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_acc, out);
    out << "\n";
  }

  // member: obs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obs: ";
    rosidl_generator_traits::value_to_yaml(msg.obs, out);
    out << "\n";
  }

  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << "\n";
  }

  // member: active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "active: ";
    rosidl_generator_traits::value_to_yaml(msg.active, out);
    out << "\n";
  }

  // member: reserved3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved3.size() == 0) {
      out << "reserved3: []\n";
    } else {
      out << "reserved3:\n";
      for (auto item : msg.reserved3) {
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

inline std::string to_yaml(const NavSVIN & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::NavSVIN & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::NavSVIN & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::NavSVIN>()
{
  return "ublox_msgs::msg::NavSVIN";
}

template<>
inline const char * name<ublox_msgs::msg::NavSVIN>()
{
  return "ublox_msgs/msg/NavSVIN";
}

template<>
struct has_fixed_size<ublox_msgs::msg::NavSVIN>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::NavSVIN>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::NavSVIN>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_tmode3__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgTMODE3 & msg,
  std::ostream & out)
{
  out << "{";
  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
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
    out << ", ";
  }

  // member: ecef_x_or_lat
  {
    out << "ecef_x_or_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_x_or_lat, out);
    out << ", ";
  }

  // member: ecef_y_or_lon
  {
    out << "ecef_y_or_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_y_or_lon, out);
    out << ", ";
  }

  // member: ecef_z_or_alt
  {
    out << "ecef_z_or_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_z_or_alt, out);
    out << ", ";
  }

  // member: ecef_x_or_lat_hp
  {
    out << "ecef_x_or_lat_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_x_or_lat_hp, out);
    out << ", ";
  }

  // member: ecef_y_or_lon_hp
  {
    out << "ecef_y_or_lon_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_y_or_lon_hp, out);
    out << ", ";
  }

  // member: ecef_z_or_alt_hp
  {
    out << "ecef_z_or_alt_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_z_or_alt_hp, out);
    out << ", ";
  }

  // member: reserved2
  {
    out << "reserved2: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved2, out);
    out << ", ";
  }

  // member: fixed_pos_acc
  {
    out << "fixed_pos_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.fixed_pos_acc, out);
    out << ", ";
  }

  // member: svin_min_dur
  {
    out << "svin_min_dur: ";
    rosidl_generator_traits::value_to_yaml(msg.svin_min_dur, out);
    out << ", ";
  }

  // member: svin_acc_limit
  {
    out << "svin_acc_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.svin_acc_limit, out);
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
  const CfgTMODE3 & msg,
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

  // member: ecef_x_or_lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_x_or_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_x_or_lat, out);
    out << "\n";
  }

  // member: ecef_y_or_lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_y_or_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_y_or_lon, out);
    out << "\n";
  }

  // member: ecef_z_or_alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_z_or_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_z_or_alt, out);
    out << "\n";
  }

  // member: ecef_x_or_lat_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_x_or_lat_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_x_or_lat_hp, out);
    out << "\n";
  }

  // member: ecef_y_or_lon_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_y_or_lon_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_y_or_lon_hp, out);
    out << "\n";
  }

  // member: ecef_z_or_alt_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ecef_z_or_alt_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ecef_z_or_alt_hp, out);
    out << "\n";
  }

  // member: reserved2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved2: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved2, out);
    out << "\n";
  }

  // member: fixed_pos_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fixed_pos_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.fixed_pos_acc, out);
    out << "\n";
  }

  // member: svin_min_dur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svin_min_dur: ";
    rosidl_generator_traits::value_to_yaml(msg.svin_min_dur, out);
    out << "\n";
  }

  // member: svin_acc_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svin_acc_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.svin_acc_limit, out);
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

inline std::string to_yaml(const CfgTMODE3 & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgTMODE3 & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgTMODE3 & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgTMODE3>()
{
  return "ublox_msgs::msg::CfgTMODE3";
}

template<>
inline const char * name<ublox_msgs::msg::CfgTMODE3>()
{
  return "ublox_msgs/msg/CfgTMODE3";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgTMODE3>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgTMODE3>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgTMODE3>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__TRAITS_HPP_

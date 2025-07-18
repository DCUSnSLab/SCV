// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgNMEA.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_nmea__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgNMEA & msg,
  std::ostream & out)
{
  out << "{";
  // member: filter
  {
    out << "filter: ";
    rosidl_generator_traits::value_to_yaml(msg.filter, out);
    out << ", ";
  }

  // member: nmea_version
  {
    out << "nmea_version: ";
    rosidl_generator_traits::value_to_yaml(msg.nmea_version, out);
    out << ", ";
  }

  // member: num_sv
  {
    out << "num_sv: ";
    rosidl_generator_traits::value_to_yaml(msg.num_sv, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: gnss_to_filter
  {
    out << "gnss_to_filter: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_to_filter, out);
    out << ", ";
  }

  // member: sv_numbering
  {
    out << "sv_numbering: ";
    rosidl_generator_traits::value_to_yaml(msg.sv_numbering, out);
    out << ", ";
  }

  // member: main_talker_id
  {
    out << "main_talker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.main_talker_id, out);
    out << ", ";
  }

  // member: gsv_talker_id
  {
    out << "gsv_talker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gsv_talker_id, out);
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: bds_talker_id
  {
    if (msg.bds_talker_id.size() == 0) {
      out << "bds_talker_id: []";
    } else {
      out << "bds_talker_id: [";
      size_t pending_items = msg.bds_talker_id.size();
      for (auto item : msg.bds_talker_id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: reserved1
  {
    if (msg.reserved1.size() == 0) {
      out << "reserved1: []";
    } else {
      out << "reserved1: [";
      size_t pending_items = msg.reserved1.size();
      for (auto item : msg.reserved1) {
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
  const CfgNMEA & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: filter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filter: ";
    rosidl_generator_traits::value_to_yaml(msg.filter, out);
    out << "\n";
  }

  // member: nmea_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nmea_version: ";
    rosidl_generator_traits::value_to_yaml(msg.nmea_version, out);
    out << "\n";
  }

  // member: num_sv
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_sv: ";
    rosidl_generator_traits::value_to_yaml(msg.num_sv, out);
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

  // member: gnss_to_filter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_to_filter: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_to_filter, out);
    out << "\n";
  }

  // member: sv_numbering
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sv_numbering: ";
    rosidl_generator_traits::value_to_yaml(msg.sv_numbering, out);
    out << "\n";
  }

  // member: main_talker_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "main_talker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.main_talker_id, out);
    out << "\n";
  }

  // member: gsv_talker_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gsv_talker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gsv_talker_id, out);
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

  // member: bds_talker_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bds_talker_id.size() == 0) {
      out << "bds_talker_id: []\n";
    } else {
      out << "bds_talker_id:\n";
      for (auto item : msg.bds_talker_id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: reserved1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved1.size() == 0) {
      out << "reserved1: []\n";
    } else {
      out << "reserved1:\n";
      for (auto item : msg.reserved1) {
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

inline std::string to_yaml(const CfgNMEA & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgNMEA & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgNMEA & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgNMEA>()
{
  return "ublox_msgs::msg::CfgNMEA";
}

template<>
inline const char * name<ublox_msgs::msg::CfgNMEA>()
{
  return "ublox_msgs/msg/CfgNMEA";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgNMEA>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgNMEA>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgNMEA>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__TRAITS_HPP_

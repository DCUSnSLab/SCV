// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/MgaGAL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MGA_GAL__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MGA_GAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/mga_gal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MgaGAL & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: svid
  {
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << ", ";
  }

  // member: reserved0
  {
    out << "reserved0: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved0, out);
    out << ", ";
  }

  // member: iod_nav
  {
    out << "iod_nav: ";
    rosidl_generator_traits::value_to_yaml(msg.iod_nav, out);
    out << ", ";
  }

  // member: delta_n
  {
    out << "delta_n: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_n, out);
    out << ", ";
  }

  // member: m0
  {
    out << "m0: ";
    rosidl_generator_traits::value_to_yaml(msg.m0, out);
    out << ", ";
  }

  // member: e
  {
    out << "e: ";
    rosidl_generator_traits::value_to_yaml(msg.e, out);
    out << ", ";
  }

  // member: sqrt_a
  {
    out << "sqrt_a: ";
    rosidl_generator_traits::value_to_yaml(msg.sqrt_a, out);
    out << ", ";
  }

  // member: omega0
  {
    out << "omega0: ";
    rosidl_generator_traits::value_to_yaml(msg.omega0, out);
    out << ", ";
  }

  // member: i0
  {
    out << "i0: ";
    rosidl_generator_traits::value_to_yaml(msg.i0, out);
    out << ", ";
  }

  // member: omega
  {
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
    out << ", ";
  }

  // member: omega_dot
  {
    out << "omega_dot: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_dot, out);
    out << ", ";
  }

  // member: i_dot
  {
    out << "i_dot: ";
    rosidl_generator_traits::value_to_yaml(msg.i_dot, out);
    out << ", ";
  }

  // member: cuc
  {
    out << "cuc: ";
    rosidl_generator_traits::value_to_yaml(msg.cuc, out);
    out << ", ";
  }

  // member: cus
  {
    out << "cus: ";
    rosidl_generator_traits::value_to_yaml(msg.cus, out);
    out << ", ";
  }

  // member: crc
  {
    out << "crc: ";
    rosidl_generator_traits::value_to_yaml(msg.crc, out);
    out << ", ";
  }

  // member: crs
  {
    out << "crs: ";
    rosidl_generator_traits::value_to_yaml(msg.crs, out);
    out << ", ";
  }

  // member: cic
  {
    out << "cic: ";
    rosidl_generator_traits::value_to_yaml(msg.cic, out);
    out << ", ";
  }

  // member: cis
  {
    out << "cis: ";
    rosidl_generator_traits::value_to_yaml(msg.cis, out);
    out << ", ";
  }

  // member: toe
  {
    out << "toe: ";
    rosidl_generator_traits::value_to_yaml(msg.toe, out);
    out << ", ";
  }

  // member: af0
  {
    out << "af0: ";
    rosidl_generator_traits::value_to_yaml(msg.af0, out);
    out << ", ";
  }

  // member: af1
  {
    out << "af1: ";
    rosidl_generator_traits::value_to_yaml(msg.af1, out);
    out << ", ";
  }

  // member: af2
  {
    out << "af2: ";
    rosidl_generator_traits::value_to_yaml(msg.af2, out);
    out << ", ";
  }

  // member: sisaindex_e1_e5b
  {
    out << "sisaindex_e1_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.sisaindex_e1_e5b, out);
    out << ", ";
  }

  // member: toc
  {
    out << "toc: ";
    rosidl_generator_traits::value_to_yaml(msg.toc, out);
    out << ", ";
  }

  // member: bgd_e1_e5b
  {
    out << "bgd_e1_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.bgd_e1_e5b, out);
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
    out << ", ";
  }

  // member: health_e1b
  {
    out << "health_e1b: ";
    rosidl_generator_traits::value_to_yaml(msg.health_e1b, out);
    out << ", ";
  }

  // member: data_validity_e1b
  {
    out << "data_validity_e1b: ";
    rosidl_generator_traits::value_to_yaml(msg.data_validity_e1b, out);
    out << ", ";
  }

  // member: health_e5b
  {
    out << "health_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.health_e5b, out);
    out << ", ";
  }

  // member: data_validity_e5b
  {
    out << "data_validity_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.data_validity_e5b, out);
    out << ", ";
  }

  // member: reserved2
  {
    if (msg.reserved2.size() == 0) {
      out << "reserved2: []";
    } else {
      out << "reserved2: [";
      size_t pending_items = msg.reserved2.size();
      for (auto item : msg.reserved2) {
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
  const MgaGAL & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
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

  // member: svid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svid: ";
    rosidl_generator_traits::value_to_yaml(msg.svid, out);
    out << "\n";
  }

  // member: reserved0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved0: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved0, out);
    out << "\n";
  }

  // member: iod_nav
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "iod_nav: ";
    rosidl_generator_traits::value_to_yaml(msg.iod_nav, out);
    out << "\n";
  }

  // member: delta_n
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_n: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_n, out);
    out << "\n";
  }

  // member: m0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m0: ";
    rosidl_generator_traits::value_to_yaml(msg.m0, out);
    out << "\n";
  }

  // member: e
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "e: ";
    rosidl_generator_traits::value_to_yaml(msg.e, out);
    out << "\n";
  }

  // member: sqrt_a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sqrt_a: ";
    rosidl_generator_traits::value_to_yaml(msg.sqrt_a, out);
    out << "\n";
  }

  // member: omega0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega0: ";
    rosidl_generator_traits::value_to_yaml(msg.omega0, out);
    out << "\n";
  }

  // member: i0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i0: ";
    rosidl_generator_traits::value_to_yaml(msg.i0, out);
    out << "\n";
  }

  // member: omega
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
    out << "\n";
  }

  // member: omega_dot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_dot: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_dot, out);
    out << "\n";
  }

  // member: i_dot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i_dot: ";
    rosidl_generator_traits::value_to_yaml(msg.i_dot, out);
    out << "\n";
  }

  // member: cuc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cuc: ";
    rosidl_generator_traits::value_to_yaml(msg.cuc, out);
    out << "\n";
  }

  // member: cus
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cus: ";
    rosidl_generator_traits::value_to_yaml(msg.cus, out);
    out << "\n";
  }

  // member: crc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "crc: ";
    rosidl_generator_traits::value_to_yaml(msg.crc, out);
    out << "\n";
  }

  // member: crs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "crs: ";
    rosidl_generator_traits::value_to_yaml(msg.crs, out);
    out << "\n";
  }

  // member: cic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cic: ";
    rosidl_generator_traits::value_to_yaml(msg.cic, out);
    out << "\n";
  }

  // member: cis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cis: ";
    rosidl_generator_traits::value_to_yaml(msg.cis, out);
    out << "\n";
  }

  // member: toe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toe: ";
    rosidl_generator_traits::value_to_yaml(msg.toe, out);
    out << "\n";
  }

  // member: af0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "af0: ";
    rosidl_generator_traits::value_to_yaml(msg.af0, out);
    out << "\n";
  }

  // member: af1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "af1: ";
    rosidl_generator_traits::value_to_yaml(msg.af1, out);
    out << "\n";
  }

  // member: af2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "af2: ";
    rosidl_generator_traits::value_to_yaml(msg.af2, out);
    out << "\n";
  }

  // member: sisaindex_e1_e5b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sisaindex_e1_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.sisaindex_e1_e5b, out);
    out << "\n";
  }

  // member: toc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toc: ";
    rosidl_generator_traits::value_to_yaml(msg.toc, out);
    out << "\n";
  }

  // member: bgd_e1_e5b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bgd_e1_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.bgd_e1_e5b, out);
    out << "\n";
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

  // member: health_e1b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "health_e1b: ";
    rosidl_generator_traits::value_to_yaml(msg.health_e1b, out);
    out << "\n";
  }

  // member: data_validity_e1b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_validity_e1b: ";
    rosidl_generator_traits::value_to_yaml(msg.data_validity_e1b, out);
    out << "\n";
  }

  // member: health_e5b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "health_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.health_e5b, out);
    out << "\n";
  }

  // member: data_validity_e5b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_validity_e5b: ";
    rosidl_generator_traits::value_to_yaml(msg.data_validity_e5b, out);
    out << "\n";
  }

  // member: reserved2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved2.size() == 0) {
      out << "reserved2: []\n";
    } else {
      out << "reserved2:\n";
      for (auto item : msg.reserved2) {
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

inline std::string to_yaml(const MgaGAL & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::MgaGAL & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::MgaGAL & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::MgaGAL>()
{
  return "ublox_msgs::msg::MgaGAL";
}

template<>
inline const char * name<ublox_msgs::msg::MgaGAL>()
{
  return "ublox_msgs/msg/MgaGAL";
}

template<>
struct has_fixed_size<ublox_msgs::msg::MgaGAL>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::MgaGAL>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::MgaGAL>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__MGA_GAL__TRAITS_HPP_

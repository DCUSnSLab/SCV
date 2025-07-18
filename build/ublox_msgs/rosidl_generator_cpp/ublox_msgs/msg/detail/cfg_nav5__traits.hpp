// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgNAV5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_nav5__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgNAV5 & msg,
  std::ostream & out)
{
  out << "{";
  // member: mask
  {
    out << "mask: ";
    rosidl_generator_traits::value_to_yaml(msg.mask, out);
    out << ", ";
  }

  // member: dyn_model
  {
    out << "dyn_model: ";
    rosidl_generator_traits::value_to_yaml(msg.dyn_model, out);
    out << ", ";
  }

  // member: fix_mode
  {
    out << "fix_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.fix_mode, out);
    out << ", ";
  }

  // member: fixed_alt
  {
    out << "fixed_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.fixed_alt, out);
    out << ", ";
  }

  // member: fixed_alt_var
  {
    out << "fixed_alt_var: ";
    rosidl_generator_traits::value_to_yaml(msg.fixed_alt_var, out);
    out << ", ";
  }

  // member: min_elev
  {
    out << "min_elev: ";
    rosidl_generator_traits::value_to_yaml(msg.min_elev, out);
    out << ", ";
  }

  // member: dr_limit
  {
    out << "dr_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.dr_limit, out);
    out << ", ";
  }

  // member: p_dop
  {
    out << "p_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.p_dop, out);
    out << ", ";
  }

  // member: t_dop
  {
    out << "t_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.t_dop, out);
    out << ", ";
  }

  // member: p_acc
  {
    out << "p_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.p_acc, out);
    out << ", ";
  }

  // member: t_acc
  {
    out << "t_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.t_acc, out);
    out << ", ";
  }

  // member: static_hold_thresh
  {
    out << "static_hold_thresh: ";
    rosidl_generator_traits::value_to_yaml(msg.static_hold_thresh, out);
    out << ", ";
  }

  // member: dgnss_time_out
  {
    out << "dgnss_time_out: ";
    rosidl_generator_traits::value_to_yaml(msg.dgnss_time_out, out);
    out << ", ";
  }

  // member: cno_thresh_num_svs
  {
    out << "cno_thresh_num_svs: ";
    rosidl_generator_traits::value_to_yaml(msg.cno_thresh_num_svs, out);
    out << ", ";
  }

  // member: cno_thresh
  {
    out << "cno_thresh: ";
    rosidl_generator_traits::value_to_yaml(msg.cno_thresh, out);
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

  // member: static_hold_max_dist
  {
    out << "static_hold_max_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.static_hold_max_dist, out);
    out << ", ";
  }

  // member: utc_standard
  {
    out << "utc_standard: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_standard, out);
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
  const CfgNAV5 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mask: ";
    rosidl_generator_traits::value_to_yaml(msg.mask, out);
    out << "\n";
  }

  // member: dyn_model
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dyn_model: ";
    rosidl_generator_traits::value_to_yaml(msg.dyn_model, out);
    out << "\n";
  }

  // member: fix_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fix_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.fix_mode, out);
    out << "\n";
  }

  // member: fixed_alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fixed_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.fixed_alt, out);
    out << "\n";
  }

  // member: fixed_alt_var
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fixed_alt_var: ";
    rosidl_generator_traits::value_to_yaml(msg.fixed_alt_var, out);
    out << "\n";
  }

  // member: min_elev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_elev: ";
    rosidl_generator_traits::value_to_yaml(msg.min_elev, out);
    out << "\n";
  }

  // member: dr_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dr_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.dr_limit, out);
    out << "\n";
  }

  // member: p_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.p_dop, out);
    out << "\n";
  }

  // member: t_dop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t_dop: ";
    rosidl_generator_traits::value_to_yaml(msg.t_dop, out);
    out << "\n";
  }

  // member: p_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.p_acc, out);
    out << "\n";
  }

  // member: t_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.t_acc, out);
    out << "\n";
  }

  // member: static_hold_thresh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "static_hold_thresh: ";
    rosidl_generator_traits::value_to_yaml(msg.static_hold_thresh, out);
    out << "\n";
  }

  // member: dgnss_time_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dgnss_time_out: ";
    rosidl_generator_traits::value_to_yaml(msg.dgnss_time_out, out);
    out << "\n";
  }

  // member: cno_thresh_num_svs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cno_thresh_num_svs: ";
    rosidl_generator_traits::value_to_yaml(msg.cno_thresh_num_svs, out);
    out << "\n";
  }

  // member: cno_thresh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cno_thresh: ";
    rosidl_generator_traits::value_to_yaml(msg.cno_thresh, out);
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

  // member: static_hold_max_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "static_hold_max_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.static_hold_max_dist, out);
    out << "\n";
  }

  // member: utc_standard
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_standard: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_standard, out);
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

inline std::string to_yaml(const CfgNAV5 & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgNAV5 & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgNAV5 & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgNAV5>()
{
  return "ublox_msgs::msg::CfgNAV5";
}

template<>
inline const char * name<ublox_msgs::msg::CfgNAV5>()
{
  return "ublox_msgs/msg/CfgNAV5";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgNAV5>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgNAV5>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgNAV5>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__TRAITS_HPP_

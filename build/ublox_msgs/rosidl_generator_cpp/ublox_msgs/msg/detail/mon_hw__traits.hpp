// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/MonHW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_HW__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_HW__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/mon_hw__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MonHW & msg,
  std::ostream & out)
{
  out << "{";
  // member: pin_sel
  {
    out << "pin_sel: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_sel, out);
    out << ", ";
  }

  // member: pin_bank
  {
    out << "pin_bank: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_bank, out);
    out << ", ";
  }

  // member: pin_dir
  {
    out << "pin_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_dir, out);
    out << ", ";
  }

  // member: pin_val
  {
    out << "pin_val: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_val, out);
    out << ", ";
  }

  // member: noise_per_ms
  {
    out << "noise_per_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.noise_per_ms, out);
    out << ", ";
  }

  // member: agc_cnt
  {
    out << "agc_cnt: ";
    rosidl_generator_traits::value_to_yaml(msg.agc_cnt, out);
    out << ", ";
  }

  // member: a_status
  {
    out << "a_status: ";
    rosidl_generator_traits::value_to_yaml(msg.a_status, out);
    out << ", ";
  }

  // member: a_power
  {
    out << "a_power: ";
    rosidl_generator_traits::value_to_yaml(msg.a_power, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: reserved0
  {
    out << "reserved0: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved0, out);
    out << ", ";
  }

  // member: used_mask
  {
    out << "used_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.used_mask, out);
    out << ", ";
  }

  // member: vp
  {
    if (msg.vp.size() == 0) {
      out << "vp: []";
    } else {
      out << "vp: [";
      size_t pending_items = msg.vp.size();
      for (auto item : msg.vp) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: jam_ind
  {
    out << "jam_ind: ";
    rosidl_generator_traits::value_to_yaml(msg.jam_ind, out);
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

  // member: pin_irq
  {
    out << "pin_irq: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_irq, out);
    out << ", ";
  }

  // member: pull_h
  {
    out << "pull_h: ";
    rosidl_generator_traits::value_to_yaml(msg.pull_h, out);
    out << ", ";
  }

  // member: pull_l
  {
    out << "pull_l: ";
    rosidl_generator_traits::value_to_yaml(msg.pull_l, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MonHW & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pin_sel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pin_sel: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_sel, out);
    out << "\n";
  }

  // member: pin_bank
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pin_bank: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_bank, out);
    out << "\n";
  }

  // member: pin_dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pin_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_dir, out);
    out << "\n";
  }

  // member: pin_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pin_val: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_val, out);
    out << "\n";
  }

  // member: noise_per_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "noise_per_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.noise_per_ms, out);
    out << "\n";
  }

  // member: agc_cnt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agc_cnt: ";
    rosidl_generator_traits::value_to_yaml(msg.agc_cnt, out);
    out << "\n";
  }

  // member: a_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_status: ";
    rosidl_generator_traits::value_to_yaml(msg.a_status, out);
    out << "\n";
  }

  // member: a_power
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_power: ";
    rosidl_generator_traits::value_to_yaml(msg.a_power, out);
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

  // member: reserved0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved0: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved0, out);
    out << "\n";
  }

  // member: used_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "used_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.used_mask, out);
    out << "\n";
  }

  // member: vp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vp.size() == 0) {
      out << "vp: []\n";
    } else {
      out << "vp:\n";
      for (auto item : msg.vp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: jam_ind
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "jam_ind: ";
    rosidl_generator_traits::value_to_yaml(msg.jam_ind, out);
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

  // member: pin_irq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pin_irq: ";
    rosidl_generator_traits::value_to_yaml(msg.pin_irq, out);
    out << "\n";
  }

  // member: pull_h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pull_h: ";
    rosidl_generator_traits::value_to_yaml(msg.pull_h, out);
    out << "\n";
  }

  // member: pull_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pull_l: ";
    rosidl_generator_traits::value_to_yaml(msg.pull_l, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MonHW & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::MonHW & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::MonHW & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::MonHW>()
{
  return "ublox_msgs::msg::MonHW";
}

template<>
inline const char * name<ublox_msgs::msg::MonHW>()
{
  return "ublox_msgs/msg/MonHW";
}

template<>
struct has_fixed_size<ublox_msgs::msg::MonHW>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::MonHW>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::MonHW>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_HW__TRAITS_HPP_

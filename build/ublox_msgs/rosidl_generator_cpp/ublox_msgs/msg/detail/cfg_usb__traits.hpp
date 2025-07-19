// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgUSB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_USB__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_USB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_usb__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgUSB & msg,
  std::ostream & out)
{
  out << "{";
  // member: vendor_id
  {
    out << "vendor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vendor_id, out);
    out << ", ";
  }

  // member: product_id
  {
    out << "product_id: ";
    rosidl_generator_traits::value_to_yaml(msg.product_id, out);
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
    out << ", ";
  }

  // member: power_consumption
  {
    out << "power_consumption: ";
    rosidl_generator_traits::value_to_yaml(msg.power_consumption, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: vendor_string
  {
    if (msg.vendor_string.size() == 0) {
      out << "vendor_string: []";
    } else {
      out << "vendor_string: [";
      size_t pending_items = msg.vendor_string.size();
      for (auto item : msg.vendor_string) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: product_string
  {
    if (msg.product_string.size() == 0) {
      out << "product_string: []";
    } else {
      out << "product_string: [";
      size_t pending_items = msg.product_string.size();
      for (auto item : msg.product_string) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: serial_number
  {
    if (msg.serial_number.size() == 0) {
      out << "serial_number: []";
    } else {
      out << "serial_number: [";
      size_t pending_items = msg.serial_number.size();
      for (auto item : msg.serial_number) {
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
  const CfgUSB & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vendor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vendor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vendor_id, out);
    out << "\n";
  }

  // member: product_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "product_id: ";
    rosidl_generator_traits::value_to_yaml(msg.product_id, out);
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

  // member: power_consumption
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_consumption: ";
    rosidl_generator_traits::value_to_yaml(msg.power_consumption, out);
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

  // member: vendor_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vendor_string.size() == 0) {
      out << "vendor_string: []\n";
    } else {
      out << "vendor_string:\n";
      for (auto item : msg.vendor_string) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: product_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.product_string.size() == 0) {
      out << "product_string: []\n";
    } else {
      out << "product_string:\n";
      for (auto item : msg.product_string) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.serial_number.size() == 0) {
      out << "serial_number: []\n";
    } else {
      out << "serial_number:\n";
      for (auto item : msg.serial_number) {
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

inline std::string to_yaml(const CfgUSB & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgUSB & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgUSB & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgUSB>()
{
  return "ublox_msgs::msg::CfgUSB";
}

template<>
inline const char * name<ublox_msgs::msg::CfgUSB>()
{
  return "ublox_msgs/msg/CfgUSB";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgUSB>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgUSB>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgUSB>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_USB__TRAITS_HPP_

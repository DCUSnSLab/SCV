// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/RxmSFRBX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/rxm_sfrbx__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RxmSFRBX & msg,
  std::ostream & out)
{
  out << "{";
  // member: gnss_id
  {
    out << "gnss_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_id, out);
    out << ", ";
  }

  // member: sv_id
  {
    out << "sv_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sv_id, out);
    out << ", ";
  }

  // member: reserved0
  {
    out << "reserved0: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved0, out);
    out << ", ";
  }

  // member: freq_id
  {
    out << "freq_id: ";
    rosidl_generator_traits::value_to_yaml(msg.freq_id, out);
    out << ", ";
  }

  // member: num_words
  {
    out << "num_words: ";
    rosidl_generator_traits::value_to_yaml(msg.num_words, out);
    out << ", ";
  }

  // member: chn
  {
    out << "chn: ";
    rosidl_generator_traits::value_to_yaml(msg.chn, out);
    out << ", ";
  }

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

  // member: dwrd
  {
    if (msg.dwrd.size() == 0) {
      out << "dwrd: []";
    } else {
      out << "dwrd: [";
      size_t pending_items = msg.dwrd.size();
      for (auto item : msg.dwrd) {
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
  const RxmSFRBX & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gnss_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_id, out);
    out << "\n";
  }

  // member: sv_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sv_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sv_id, out);
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

  // member: freq_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "freq_id: ";
    rosidl_generator_traits::value_to_yaml(msg.freq_id, out);
    out << "\n";
  }

  // member: num_words
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_words: ";
    rosidl_generator_traits::value_to_yaml(msg.num_words, out);
    out << "\n";
  }

  // member: chn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chn: ";
    rosidl_generator_traits::value_to_yaml(msg.chn, out);
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

  // member: reserved1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserved1: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved1, out);
    out << "\n";
  }

  // member: dwrd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dwrd.size() == 0) {
      out << "dwrd: []\n";
    } else {
      out << "dwrd:\n";
      for (auto item : msg.dwrd) {
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

inline std::string to_yaml(const RxmSFRBX & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::RxmSFRBX & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::RxmSFRBX & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::RxmSFRBX>()
{
  return "ublox_msgs::msg::RxmSFRBX";
}

template<>
inline const char * name<ublox_msgs::msg::RxmSFRBX>()
{
  return "ublox_msgs/msg/RxmSFRBX";
}

template<>
struct has_fixed_size<ublox_msgs::msg::RxmSFRBX>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ublox_msgs::msg::RxmSFRBX>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ublox_msgs::msg::RxmSFRBX>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__TRAITS_HPP_

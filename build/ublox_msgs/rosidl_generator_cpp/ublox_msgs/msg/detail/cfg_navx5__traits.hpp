// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__TRAITS_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ublox_msgs/msg/detail/cfg_navx5__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ublox_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CfgNAVX5 & msg,
  std::ostream & out)
{
  out << "{";
  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: mask1
  {
    out << "mask1: ";
    rosidl_generator_traits::value_to_yaml(msg.mask1, out);
    out << ", ";
  }

  // member: mask2
  {
    out << "mask2: ";
    rosidl_generator_traits::value_to_yaml(msg.mask2, out);
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

  // member: min_svs
  {
    out << "min_svs: ";
    rosidl_generator_traits::value_to_yaml(msg.min_svs, out);
    out << ", ";
  }

  // member: max_svs
  {
    out << "max_svs: ";
    rosidl_generator_traits::value_to_yaml(msg.max_svs, out);
    out << ", ";
  }

  // member: min_cno
  {
    out << "min_cno: ";
    rosidl_generator_traits::value_to_yaml(msg.min_cno, out);
    out << ", ";
  }

  // member: reserved2
  {
    out << "reserved2: ";
    rosidl_generator_traits::value_to_yaml(msg.reserved2, out);
    out << ", ";
  }

  // member: ini_fix3d
  {
    out << "ini_fix3d: ";
    rosidl_generator_traits::value_to_yaml(msg.ini_fix3d, out);
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
    out << ", ";
  }

  // member: ack_aiding
  {
    out << "ack_aiding: ";
    rosidl_generator_traits::value_to_yaml(msg.ack_aiding, out);
    out << ", ";
  }

  // member: wkn_rollover
  {
    out << "wkn_rollover: ";
    rosidl_generator_traits::value_to_yaml(msg.wkn_rollover, out);
    out << ", ";
  }

  // member: sig_atten_comp_mode
  {
    out << "sig_atten_comp_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.sig_atten_comp_mode, out);
    out << ", ";
  }

  // member: reserved4
  {
    if (msg.reserved4.size() == 0) {
      out << "reserved4: []";
    } else {
      out << "reserved4: [";
      size_t pending_items = msg.reserved4.size();
      for (auto item : msg.reserved4) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: use_ppp
  {
    out << "use_ppp: ";
    rosidl_generator_traits::value_to_yaml(msg.use_ppp, out);
    out << ", ";
  }

  // member: aop_cfg
  {
    out << "aop_cfg: ";
    rosidl_generator_traits::value_to_yaml(msg.aop_cfg, out);
    out << ", ";
  }

  // member: reserved5
  {
    if (msg.reserved5.size() == 0) {
      out << "reserved5: []";
    } else {
      out << "reserved5: [";
      size_t pending_items = msg.reserved5.size();
      for (auto item : msg.reserved5) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: aop_orb_max_err
  {
    out << "aop_orb_max_err: ";
    rosidl_generator_traits::value_to_yaml(msg.aop_orb_max_err, out);
    out << ", ";
  }

  // member: reserved6
  {
    if (msg.reserved6.size() == 0) {
      out << "reserved6: []";
    } else {
      out << "reserved6: [";
      size_t pending_items = msg.reserved6.size();
      for (auto item : msg.reserved6) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: use_adr
  {
    out << "use_adr: ";
    rosidl_generator_traits::value_to_yaml(msg.use_adr, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CfgNAVX5 & msg,
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

  // member: mask1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mask1: ";
    rosidl_generator_traits::value_to_yaml(msg.mask1, out);
    out << "\n";
  }

  // member: mask2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mask2: ";
    rosidl_generator_traits::value_to_yaml(msg.mask2, out);
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

  // member: min_svs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_svs: ";
    rosidl_generator_traits::value_to_yaml(msg.min_svs, out);
    out << "\n";
  }

  // member: max_svs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_svs: ";
    rosidl_generator_traits::value_to_yaml(msg.max_svs, out);
    out << "\n";
  }

  // member: min_cno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_cno: ";
    rosidl_generator_traits::value_to_yaml(msg.min_cno, out);
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

  // member: ini_fix3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ini_fix3d: ";
    rosidl_generator_traits::value_to_yaml(msg.ini_fix3d, out);
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

  // member: ack_aiding
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ack_aiding: ";
    rosidl_generator_traits::value_to_yaml(msg.ack_aiding, out);
    out << "\n";
  }

  // member: wkn_rollover
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wkn_rollover: ";
    rosidl_generator_traits::value_to_yaml(msg.wkn_rollover, out);
    out << "\n";
  }

  // member: sig_atten_comp_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sig_atten_comp_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.sig_atten_comp_mode, out);
    out << "\n";
  }

  // member: reserved4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved4.size() == 0) {
      out << "reserved4: []\n";
    } else {
      out << "reserved4:\n";
      for (auto item : msg.reserved4) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: use_ppp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_ppp: ";
    rosidl_generator_traits::value_to_yaml(msg.use_ppp, out);
    out << "\n";
  }

  // member: aop_cfg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aop_cfg: ";
    rosidl_generator_traits::value_to_yaml(msg.aop_cfg, out);
    out << "\n";
  }

  // member: reserved5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved5.size() == 0) {
      out << "reserved5: []\n";
    } else {
      out << "reserved5:\n";
      for (auto item : msg.reserved5) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: aop_orb_max_err
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aop_orb_max_err: ";
    rosidl_generator_traits::value_to_yaml(msg.aop_orb_max_err, out);
    out << "\n";
  }

  // member: reserved6
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reserved6.size() == 0) {
      out << "reserved6: []\n";
    } else {
      out << "reserved6:\n";
      for (auto item : msg.reserved6) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: use_adr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_adr: ";
    rosidl_generator_traits::value_to_yaml(msg.use_adr, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CfgNAVX5 & msg, bool use_flow_style = false)
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
  const ublox_msgs::msg::CfgNAVX5 & msg,
  std::ostream & out, size_t indentation = 0)
{
  ublox_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ublox_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ublox_msgs::msg::CfgNAVX5 & msg)
{
  return ublox_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ublox_msgs::msg::CfgNAVX5>()
{
  return "ublox_msgs::msg::CfgNAVX5";
}

template<>
inline const char * name<ublox_msgs::msg::CfgNAVX5>()
{
  return "ublox_msgs/msg/CfgNAVX5";
}

template<>
struct has_fixed_size<ublox_msgs::msg::CfgNAVX5>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ublox_msgs::msg::CfgNAVX5>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ublox_msgs::msg::CfgNAVX5>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__TRAITS_HPP_

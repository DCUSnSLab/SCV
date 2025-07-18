// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_navx5__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/cfg_navx5__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ublox_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_serialize(
  const ublox_msgs::msg::CfgNAVX5 & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: version
  cdr << ros_message.version;
  // Member: mask1
  cdr << ros_message.mask1;
  // Member: mask2
  cdr << ros_message.mask2;
  // Member: reserved1
  {
    cdr << ros_message.reserved1;
  }
  // Member: min_svs
  cdr << ros_message.min_svs;
  // Member: max_svs
  cdr << ros_message.max_svs;
  // Member: min_cno
  cdr << ros_message.min_cno;
  // Member: reserved2
  cdr << ros_message.reserved2;
  // Member: ini_fix3d
  cdr << ros_message.ini_fix3d;
  // Member: reserved3
  {
    cdr << ros_message.reserved3;
  }
  // Member: ack_aiding
  cdr << ros_message.ack_aiding;
  // Member: wkn_rollover
  cdr << ros_message.wkn_rollover;
  // Member: sig_atten_comp_mode
  cdr << ros_message.sig_atten_comp_mode;
  // Member: reserved4
  {
    cdr << ros_message.reserved4;
  }
  // Member: use_ppp
  cdr << ros_message.use_ppp;
  // Member: aop_cfg
  cdr << ros_message.aop_cfg;
  // Member: reserved5
  {
    cdr << ros_message.reserved5;
  }
  // Member: aop_orb_max_err
  cdr << ros_message.aop_orb_max_err;
  // Member: reserved6
  {
    cdr << ros_message.reserved6;
  }
  // Member: use_adr
  cdr << ros_message.use_adr;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::CfgNAVX5 & ros_message)
{
  // Member: version
  cdr >> ros_message.version;

  // Member: mask1
  cdr >> ros_message.mask1;

  // Member: mask2
  cdr >> ros_message.mask2;

  // Member: reserved1
  {
    cdr >> ros_message.reserved1;
  }

  // Member: min_svs
  cdr >> ros_message.min_svs;

  // Member: max_svs
  cdr >> ros_message.max_svs;

  // Member: min_cno
  cdr >> ros_message.min_cno;

  // Member: reserved2
  cdr >> ros_message.reserved2;

  // Member: ini_fix3d
  cdr >> ros_message.ini_fix3d;

  // Member: reserved3
  {
    cdr >> ros_message.reserved3;
  }

  // Member: ack_aiding
  cdr >> ros_message.ack_aiding;

  // Member: wkn_rollover
  cdr >> ros_message.wkn_rollover;

  // Member: sig_atten_comp_mode
  cdr >> ros_message.sig_atten_comp_mode;

  // Member: reserved4
  {
    cdr >> ros_message.reserved4;
  }

  // Member: use_ppp
  cdr >> ros_message.use_ppp;

  // Member: aop_cfg
  cdr >> ros_message.aop_cfg;

  // Member: reserved5
  {
    cdr >> ros_message.reserved5;
  }

  // Member: aop_orb_max_err
  cdr >> ros_message.aop_orb_max_err;

  // Member: reserved6
  {
    cdr >> ros_message.reserved6;
  }

  // Member: use_adr
  cdr >> ros_message.use_adr;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::CfgNAVX5 & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: version
  {
    size_t item_size = sizeof(ros_message.version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mask1
  {
    size_t item_size = sizeof(ros_message.mask1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mask2
  {
    size_t item_size = sizeof(ros_message.mask2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved1
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.reserved1[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: min_svs
  {
    size_t item_size = sizeof(ros_message.min_svs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_svs
  {
    size_t item_size = sizeof(ros_message.max_svs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: min_cno
  {
    size_t item_size = sizeof(ros_message.min_cno);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved2
  {
    size_t item_size = sizeof(ros_message.reserved2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ini_fix3d
  {
    size_t item_size = sizeof(ros_message.ini_fix3d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved3
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.reserved3[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ack_aiding
  {
    size_t item_size = sizeof(ros_message.ack_aiding);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: wkn_rollover
  {
    size_t item_size = sizeof(ros_message.wkn_rollover);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sig_atten_comp_mode
  {
    size_t item_size = sizeof(ros_message.sig_atten_comp_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved4
  {
    size_t array_size = 5;
    size_t item_size = sizeof(ros_message.reserved4[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: use_ppp
  {
    size_t item_size = sizeof(ros_message.use_ppp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: aop_cfg
  {
    size_t item_size = sizeof(ros_message.aop_cfg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved5
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.reserved5[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: aop_orb_max_err
  {
    size_t item_size = sizeof(ros_message.aop_orb_max_err);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved6
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.reserved6[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: use_adr
  {
    size_t item_size = sizeof(ros_message.use_adr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_CfgNAVX5(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: mask1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: mask2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: reserved1
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: min_svs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: max_svs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: min_cno
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ini_fix3d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved3
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ack_aiding
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: wkn_rollover
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: sig_atten_comp_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved4
  {
    size_t array_size = 5;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: use_ppp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: aop_cfg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved5
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: aop_orb_max_err
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: reserved6
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: use_adr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs::msg::CfgNAVX5;
    is_plain =
      (
      offsetof(DataType, use_adr) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _CfgNAVX5__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgNAVX5 *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CfgNAVX5__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::CfgNAVX5 *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CfgNAVX5__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgNAVX5 *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CfgNAVX5__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CfgNAVX5(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CfgNAVX5__callbacks = {
  "ublox_msgs::msg",
  "CfgNAVX5",
  _CfgNAVX5__cdr_serialize,
  _CfgNAVX5__cdr_deserialize,
  _CfgNAVX5__get_serialized_size,
  _CfgNAVX5__max_serialized_size
};

static rosidl_message_type_support_t _CfgNAVX5__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CfgNAVX5__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ublox_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<ublox_msgs::msg::CfgNAVX5>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgNAVX5__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, CfgNAVX5)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgNAVX5__handle;
}

#ifdef __cplusplus
}
#endif

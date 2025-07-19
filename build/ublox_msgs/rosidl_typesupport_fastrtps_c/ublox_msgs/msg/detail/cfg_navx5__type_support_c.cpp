// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_navx5__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/cfg_navx5__struct.h"
#include "ublox_msgs/msg/detail/cfg_navx5__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _CfgNAVX5__ros_msg_type = ublox_msgs__msg__CfgNAVX5;

static bool _CfgNAVX5__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CfgNAVX5__ros_msg_type * ros_message = static_cast<const _CfgNAVX5__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: mask1
  {
    cdr << ros_message->mask1;
  }

  // Field name: mask2
  {
    cdr << ros_message->mask2;
  }

  // Field name: reserved1
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved1;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: min_svs
  {
    cdr << ros_message->min_svs;
  }

  // Field name: max_svs
  {
    cdr << ros_message->max_svs;
  }

  // Field name: min_cno
  {
    cdr << ros_message->min_cno;
  }

  // Field name: reserved2
  {
    cdr << ros_message->reserved2;
  }

  // Field name: ini_fix3d
  {
    cdr << ros_message->ini_fix3d;
  }

  // Field name: reserved3
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved3;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: ack_aiding
  {
    cdr << ros_message->ack_aiding;
  }

  // Field name: wkn_rollover
  {
    cdr << ros_message->wkn_rollover;
  }

  // Field name: sig_atten_comp_mode
  {
    cdr << ros_message->sig_atten_comp_mode;
  }

  // Field name: reserved4
  {
    size_t size = 5;
    auto array_ptr = ros_message->reserved4;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: use_ppp
  {
    cdr << ros_message->use_ppp;
  }

  // Field name: aop_cfg
  {
    cdr << ros_message->aop_cfg;
  }

  // Field name: reserved5
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved5;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: aop_orb_max_err
  {
    cdr << ros_message->aop_orb_max_err;
  }

  // Field name: reserved6
  {
    size_t size = 7;
    auto array_ptr = ros_message->reserved6;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: use_adr
  {
    cdr << ros_message->use_adr;
  }

  return true;
}

static bool _CfgNAVX5__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CfgNAVX5__ros_msg_type * ros_message = static_cast<_CfgNAVX5__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: mask1
  {
    cdr >> ros_message->mask1;
  }

  // Field name: mask2
  {
    cdr >> ros_message->mask2;
  }

  // Field name: reserved1
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved1;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: min_svs
  {
    cdr >> ros_message->min_svs;
  }

  // Field name: max_svs
  {
    cdr >> ros_message->max_svs;
  }

  // Field name: min_cno
  {
    cdr >> ros_message->min_cno;
  }

  // Field name: reserved2
  {
    cdr >> ros_message->reserved2;
  }

  // Field name: ini_fix3d
  {
    cdr >> ros_message->ini_fix3d;
  }

  // Field name: reserved3
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved3;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: ack_aiding
  {
    cdr >> ros_message->ack_aiding;
  }

  // Field name: wkn_rollover
  {
    cdr >> ros_message->wkn_rollover;
  }

  // Field name: sig_atten_comp_mode
  {
    cdr >> ros_message->sig_atten_comp_mode;
  }

  // Field name: reserved4
  {
    size_t size = 5;
    auto array_ptr = ros_message->reserved4;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: use_ppp
  {
    cdr >> ros_message->use_ppp;
  }

  // Field name: aop_cfg
  {
    cdr >> ros_message->aop_cfg;
  }

  // Field name: reserved5
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved5;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: aop_orb_max_err
  {
    cdr >> ros_message->aop_orb_max_err;
  }

  // Field name: reserved6
  {
    size_t size = 7;
    auto array_ptr = ros_message->reserved6;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: use_adr
  {
    cdr >> ros_message->use_adr;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__CfgNAVX5(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CfgNAVX5__ros_msg_type * ros_message = static_cast<const _CfgNAVX5__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name version
  {
    size_t item_size = sizeof(ros_message->version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mask1
  {
    size_t item_size = sizeof(ros_message->mask1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mask2
  {
    size_t item_size = sizeof(ros_message->mask2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved1
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->reserved1;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min_svs
  {
    size_t item_size = sizeof(ros_message->min_svs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_svs
  {
    size_t item_size = sizeof(ros_message->max_svs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min_cno
  {
    size_t item_size = sizeof(ros_message->min_cno);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved2
  {
    size_t item_size = sizeof(ros_message->reserved2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ini_fix3d
  {
    size_t item_size = sizeof(ros_message->ini_fix3d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved3
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->reserved3;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ack_aiding
  {
    size_t item_size = sizeof(ros_message->ack_aiding);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name wkn_rollover
  {
    size_t item_size = sizeof(ros_message->wkn_rollover);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sig_atten_comp_mode
  {
    size_t item_size = sizeof(ros_message->sig_atten_comp_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved4
  {
    size_t array_size = 5;
    auto array_ptr = ros_message->reserved4;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name use_ppp
  {
    size_t item_size = sizeof(ros_message->use_ppp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name aop_cfg
  {
    size_t item_size = sizeof(ros_message->aop_cfg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved5
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->reserved5;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name aop_orb_max_err
  {
    size_t item_size = sizeof(ros_message->aop_orb_max_err);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved6
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->reserved6;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name use_adr
  {
    size_t item_size = sizeof(ros_message->use_adr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CfgNAVX5__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__CfgNAVX5(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__CfgNAVX5(
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

  // member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: mask1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: mask2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: reserved1
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: min_svs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: max_svs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: min_cno
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ini_fix3d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved3
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ack_aiding
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: wkn_rollover
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: sig_atten_comp_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved4
  {
    size_t array_size = 5;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: use_ppp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: aop_cfg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved5
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: aop_orb_max_err
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: reserved6
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: use_adr
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
    using DataType = ublox_msgs__msg__CfgNAVX5;
    is_plain =
      (
      offsetof(DataType, use_adr) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CfgNAVX5__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__CfgNAVX5(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CfgNAVX5 = {
  "ublox_msgs::msg",
  "CfgNAVX5",
  _CfgNAVX5__cdr_serialize,
  _CfgNAVX5__cdr_deserialize,
  _CfgNAVX5__get_serialized_size,
  _CfgNAVX5__max_serialized_size
};

static rosidl_message_type_support_t _CfgNAVX5__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CfgNAVX5,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, CfgNAVX5)() {
  return &_CfgNAVX5__type_support;
}

#if defined(__cplusplus)
}
#endif

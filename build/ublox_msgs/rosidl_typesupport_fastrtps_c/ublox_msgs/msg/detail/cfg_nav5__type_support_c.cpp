// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/CfgNAV5.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_nav5__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/cfg_nav5__struct.h"
#include "ublox_msgs/msg/detail/cfg_nav5__functions.h"
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


using _CfgNAV5__ros_msg_type = ublox_msgs__msg__CfgNAV5;

static bool _CfgNAV5__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CfgNAV5__ros_msg_type * ros_message = static_cast<const _CfgNAV5__ros_msg_type *>(untyped_ros_message);
  // Field name: mask
  {
    cdr << ros_message->mask;
  }

  // Field name: dyn_model
  {
    cdr << ros_message->dyn_model;
  }

  // Field name: fix_mode
  {
    cdr << ros_message->fix_mode;
  }

  // Field name: fixed_alt
  {
    cdr << ros_message->fixed_alt;
  }

  // Field name: fixed_alt_var
  {
    cdr << ros_message->fixed_alt_var;
  }

  // Field name: min_elev
  {
    cdr << ros_message->min_elev;
  }

  // Field name: dr_limit
  {
    cdr << ros_message->dr_limit;
  }

  // Field name: p_dop
  {
    cdr << ros_message->p_dop;
  }

  // Field name: t_dop
  {
    cdr << ros_message->t_dop;
  }

  // Field name: p_acc
  {
    cdr << ros_message->p_acc;
  }

  // Field name: t_acc
  {
    cdr << ros_message->t_acc;
  }

  // Field name: static_hold_thresh
  {
    cdr << ros_message->static_hold_thresh;
  }

  // Field name: dgnss_time_out
  {
    cdr << ros_message->dgnss_time_out;
  }

  // Field name: cno_thresh_num_svs
  {
    cdr << ros_message->cno_thresh_num_svs;
  }

  // Field name: cno_thresh
  {
    cdr << ros_message->cno_thresh;
  }

  // Field name: reserved1
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved1;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: static_hold_max_dist
  {
    cdr << ros_message->static_hold_max_dist;
  }

  // Field name: utc_standard
  {
    cdr << ros_message->utc_standard;
  }

  // Field name: reserved2
  {
    size_t size = 5;
    auto array_ptr = ros_message->reserved2;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _CfgNAV5__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CfgNAV5__ros_msg_type * ros_message = static_cast<_CfgNAV5__ros_msg_type *>(untyped_ros_message);
  // Field name: mask
  {
    cdr >> ros_message->mask;
  }

  // Field name: dyn_model
  {
    cdr >> ros_message->dyn_model;
  }

  // Field name: fix_mode
  {
    cdr >> ros_message->fix_mode;
  }

  // Field name: fixed_alt
  {
    cdr >> ros_message->fixed_alt;
  }

  // Field name: fixed_alt_var
  {
    cdr >> ros_message->fixed_alt_var;
  }

  // Field name: min_elev
  {
    cdr >> ros_message->min_elev;
  }

  // Field name: dr_limit
  {
    cdr >> ros_message->dr_limit;
  }

  // Field name: p_dop
  {
    cdr >> ros_message->p_dop;
  }

  // Field name: t_dop
  {
    cdr >> ros_message->t_dop;
  }

  // Field name: p_acc
  {
    cdr >> ros_message->p_acc;
  }

  // Field name: t_acc
  {
    cdr >> ros_message->t_acc;
  }

  // Field name: static_hold_thresh
  {
    cdr >> ros_message->static_hold_thresh;
  }

  // Field name: dgnss_time_out
  {
    cdr >> ros_message->dgnss_time_out;
  }

  // Field name: cno_thresh_num_svs
  {
    cdr >> ros_message->cno_thresh_num_svs;
  }

  // Field name: cno_thresh
  {
    cdr >> ros_message->cno_thresh;
  }

  // Field name: reserved1
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved1;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: static_hold_max_dist
  {
    cdr >> ros_message->static_hold_max_dist;
  }

  // Field name: utc_standard
  {
    cdr >> ros_message->utc_standard;
  }

  // Field name: reserved2
  {
    size_t size = 5;
    auto array_ptr = ros_message->reserved2;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__CfgNAV5(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CfgNAV5__ros_msg_type * ros_message = static_cast<const _CfgNAV5__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name mask
  {
    size_t item_size = sizeof(ros_message->mask);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dyn_model
  {
    size_t item_size = sizeof(ros_message->dyn_model);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fix_mode
  {
    size_t item_size = sizeof(ros_message->fix_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fixed_alt
  {
    size_t item_size = sizeof(ros_message->fixed_alt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fixed_alt_var
  {
    size_t item_size = sizeof(ros_message->fixed_alt_var);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min_elev
  {
    size_t item_size = sizeof(ros_message->min_elev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dr_limit
  {
    size_t item_size = sizeof(ros_message->dr_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_dop
  {
    size_t item_size = sizeof(ros_message->p_dop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name t_dop
  {
    size_t item_size = sizeof(ros_message->t_dop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_acc
  {
    size_t item_size = sizeof(ros_message->p_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name t_acc
  {
    size_t item_size = sizeof(ros_message->t_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name static_hold_thresh
  {
    size_t item_size = sizeof(ros_message->static_hold_thresh);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dgnss_time_out
  {
    size_t item_size = sizeof(ros_message->dgnss_time_out);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cno_thresh_num_svs
  {
    size_t item_size = sizeof(ros_message->cno_thresh_num_svs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cno_thresh
  {
    size_t item_size = sizeof(ros_message->cno_thresh);
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
  // field.name static_hold_max_dist
  {
    size_t item_size = sizeof(ros_message->static_hold_max_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_standard
  {
    size_t item_size = sizeof(ros_message->utc_standard);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved2
  {
    size_t array_size = 5;
    auto array_ptr = ros_message->reserved2;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CfgNAV5__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__CfgNAV5(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__CfgNAV5(
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

  // member: mask
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: dyn_model
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fix_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fixed_alt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: fixed_alt_var
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: min_elev
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: dr_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: p_dop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: t_dop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: p_acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: t_acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: static_hold_thresh
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: dgnss_time_out
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cno_thresh_num_svs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cno_thresh
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved1
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: static_hold_max_dist
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: utc_standard
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved2
  {
    size_t array_size = 5;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs__msg__CfgNAV5;
    is_plain =
      (
      offsetof(DataType, reserved2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CfgNAV5__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__CfgNAV5(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CfgNAV5 = {
  "ublox_msgs::msg",
  "CfgNAV5",
  _CfgNAV5__cdr_serialize,
  _CfgNAV5__cdr_deserialize,
  _CfgNAV5__get_serialized_size,
  _CfgNAV5__max_serialized_size
};

static rosidl_message_type_support_t _CfgNAV5__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CfgNAV5,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, CfgNAV5)() {
  return &_CfgNAV5__type_support;
}

#if defined(__cplusplus)
}
#endif

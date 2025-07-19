// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/RxmRAWXMeas.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/rxm_rawx_meas__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/rxm_rawx_meas__struct.h"
#include "ublox_msgs/msg/detail/rxm_rawx_meas__functions.h"
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


using _RxmRAWXMeas__ros_msg_type = ublox_msgs__msg__RxmRAWXMeas;

static bool _RxmRAWXMeas__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RxmRAWXMeas__ros_msg_type * ros_message = static_cast<const _RxmRAWXMeas__ros_msg_type *>(untyped_ros_message);
  // Field name: pr_mes
  {
    cdr << ros_message->pr_mes;
  }

  // Field name: cp_mes
  {
    cdr << ros_message->cp_mes;
  }

  // Field name: do_mes
  {
    cdr << ros_message->do_mes;
  }

  // Field name: gnss_id
  {
    cdr << ros_message->gnss_id;
  }

  // Field name: sv_id
  {
    cdr << ros_message->sv_id;
  }

  // Field name: reserved0
  {
    cdr << ros_message->reserved0;
  }

  // Field name: freq_id
  {
    cdr << ros_message->freq_id;
  }

  // Field name: locktime
  {
    cdr << ros_message->locktime;
  }

  // Field name: cno
  {
    cdr << ros_message->cno;
  }

  // Field name: pr_stdev
  {
    cdr << ros_message->pr_stdev;
  }

  // Field name: cp_stdev
  {
    cdr << ros_message->cp_stdev;
  }

  // Field name: do_stdev
  {
    cdr << ros_message->do_stdev;
  }

  // Field name: trk_stat
  {
    cdr << ros_message->trk_stat;
  }

  // Field name: reserved1
  {
    cdr << ros_message->reserved1;
  }

  return true;
}

static bool _RxmRAWXMeas__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RxmRAWXMeas__ros_msg_type * ros_message = static_cast<_RxmRAWXMeas__ros_msg_type *>(untyped_ros_message);
  // Field name: pr_mes
  {
    cdr >> ros_message->pr_mes;
  }

  // Field name: cp_mes
  {
    cdr >> ros_message->cp_mes;
  }

  // Field name: do_mes
  {
    cdr >> ros_message->do_mes;
  }

  // Field name: gnss_id
  {
    cdr >> ros_message->gnss_id;
  }

  // Field name: sv_id
  {
    cdr >> ros_message->sv_id;
  }

  // Field name: reserved0
  {
    cdr >> ros_message->reserved0;
  }

  // Field name: freq_id
  {
    cdr >> ros_message->freq_id;
  }

  // Field name: locktime
  {
    cdr >> ros_message->locktime;
  }

  // Field name: cno
  {
    cdr >> ros_message->cno;
  }

  // Field name: pr_stdev
  {
    cdr >> ros_message->pr_stdev;
  }

  // Field name: cp_stdev
  {
    cdr >> ros_message->cp_stdev;
  }

  // Field name: do_stdev
  {
    cdr >> ros_message->do_stdev;
  }

  // Field name: trk_stat
  {
    cdr >> ros_message->trk_stat;
  }

  // Field name: reserved1
  {
    cdr >> ros_message->reserved1;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__RxmRAWXMeas(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RxmRAWXMeas__ros_msg_type * ros_message = static_cast<const _RxmRAWXMeas__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pr_mes
  {
    size_t item_size = sizeof(ros_message->pr_mes);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cp_mes
  {
    size_t item_size = sizeof(ros_message->cp_mes);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name do_mes
  {
    size_t item_size = sizeof(ros_message->do_mes);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gnss_id
  {
    size_t item_size = sizeof(ros_message->gnss_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sv_id
  {
    size_t item_size = sizeof(ros_message->sv_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved0
  {
    size_t item_size = sizeof(ros_message->reserved0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name freq_id
  {
    size_t item_size = sizeof(ros_message->freq_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name locktime
  {
    size_t item_size = sizeof(ros_message->locktime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cno
  {
    size_t item_size = sizeof(ros_message->cno);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pr_stdev
  {
    size_t item_size = sizeof(ros_message->pr_stdev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cp_stdev
  {
    size_t item_size = sizeof(ros_message->cp_stdev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name do_stdev
  {
    size_t item_size = sizeof(ros_message->do_stdev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name trk_stat
  {
    size_t item_size = sizeof(ros_message->trk_stat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved1
  {
    size_t item_size = sizeof(ros_message->reserved1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RxmRAWXMeas__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__RxmRAWXMeas(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__RxmRAWXMeas(
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

  // member: pr_mes
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: cp_mes
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: do_mes
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gnss_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: sv_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: freq_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: locktime
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: cno
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: pr_stdev
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cp_stdev
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: do_stdev
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: trk_stat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved1
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
    using DataType = ublox_msgs__msg__RxmRAWXMeas;
    is_plain =
      (
      offsetof(DataType, reserved1) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RxmRAWXMeas__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__RxmRAWXMeas(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RxmRAWXMeas = {
  "ublox_msgs::msg",
  "RxmRAWXMeas",
  _RxmRAWXMeas__cdr_serialize,
  _RxmRAWXMeas__cdr_deserialize,
  _RxmRAWXMeas__get_serialized_size,
  _RxmRAWXMeas__max_serialized_size
};

static rosidl_message_type_support_t _RxmRAWXMeas__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RxmRAWXMeas,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, RxmRAWXMeas)() {
  return &_RxmRAWXMeas__type_support;
}

#if defined(__cplusplus)
}
#endif

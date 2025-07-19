// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/AidHUI.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/aid_hui__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/aid_hui__struct.h"
#include "ublox_msgs/msg/detail/aid_hui__functions.h"
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


using _AidHUI__ros_msg_type = ublox_msgs__msg__AidHUI;

static bool _AidHUI__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AidHUI__ros_msg_type * ros_message = static_cast<const _AidHUI__ros_msg_type *>(untyped_ros_message);
  // Field name: health
  {
    cdr << ros_message->health;
  }

  // Field name: utc_a0
  {
    cdr << ros_message->utc_a0;
  }

  // Field name: utc_a1
  {
    cdr << ros_message->utc_a1;
  }

  // Field name: utc_tow
  {
    cdr << ros_message->utc_tow;
  }

  // Field name: utc_wnt
  {
    cdr << ros_message->utc_wnt;
  }

  // Field name: utc_ls
  {
    cdr << ros_message->utc_ls;
  }

  // Field name: utc_wnf
  {
    cdr << ros_message->utc_wnf;
  }

  // Field name: utc_dn
  {
    cdr << ros_message->utc_dn;
  }

  // Field name: utc_lsf
  {
    cdr << ros_message->utc_lsf;
  }

  // Field name: utc_spare
  {
    cdr << ros_message->utc_spare;
  }

  // Field name: klob_a0
  {
    cdr << ros_message->klob_a0;
  }

  // Field name: klob_a1
  {
    cdr << ros_message->klob_a1;
  }

  // Field name: klob_a2
  {
    cdr << ros_message->klob_a2;
  }

  // Field name: klob_a3
  {
    cdr << ros_message->klob_a3;
  }

  // Field name: klob_b0
  {
    cdr << ros_message->klob_b0;
  }

  // Field name: klob_b1
  {
    cdr << ros_message->klob_b1;
  }

  // Field name: klob_b2
  {
    cdr << ros_message->klob_b2;
  }

  // Field name: klob_b3
  {
    cdr << ros_message->klob_b3;
  }

  // Field name: flags
  {
    cdr << ros_message->flags;
  }

  return true;
}

static bool _AidHUI__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AidHUI__ros_msg_type * ros_message = static_cast<_AidHUI__ros_msg_type *>(untyped_ros_message);
  // Field name: health
  {
    cdr >> ros_message->health;
  }

  // Field name: utc_a0
  {
    cdr >> ros_message->utc_a0;
  }

  // Field name: utc_a1
  {
    cdr >> ros_message->utc_a1;
  }

  // Field name: utc_tow
  {
    cdr >> ros_message->utc_tow;
  }

  // Field name: utc_wnt
  {
    cdr >> ros_message->utc_wnt;
  }

  // Field name: utc_ls
  {
    cdr >> ros_message->utc_ls;
  }

  // Field name: utc_wnf
  {
    cdr >> ros_message->utc_wnf;
  }

  // Field name: utc_dn
  {
    cdr >> ros_message->utc_dn;
  }

  // Field name: utc_lsf
  {
    cdr >> ros_message->utc_lsf;
  }

  // Field name: utc_spare
  {
    cdr >> ros_message->utc_spare;
  }

  // Field name: klob_a0
  {
    cdr >> ros_message->klob_a0;
  }

  // Field name: klob_a1
  {
    cdr >> ros_message->klob_a1;
  }

  // Field name: klob_a2
  {
    cdr >> ros_message->klob_a2;
  }

  // Field name: klob_a3
  {
    cdr >> ros_message->klob_a3;
  }

  // Field name: klob_b0
  {
    cdr >> ros_message->klob_b0;
  }

  // Field name: klob_b1
  {
    cdr >> ros_message->klob_b1;
  }

  // Field name: klob_b2
  {
    cdr >> ros_message->klob_b2;
  }

  // Field name: klob_b3
  {
    cdr >> ros_message->klob_b3;
  }

  // Field name: flags
  {
    cdr >> ros_message->flags;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__AidHUI(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AidHUI__ros_msg_type * ros_message = static_cast<const _AidHUI__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name health
  {
    size_t item_size = sizeof(ros_message->health);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_a0
  {
    size_t item_size = sizeof(ros_message->utc_a0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_a1
  {
    size_t item_size = sizeof(ros_message->utc_a1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_tow
  {
    size_t item_size = sizeof(ros_message->utc_tow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_wnt
  {
    size_t item_size = sizeof(ros_message->utc_wnt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_ls
  {
    size_t item_size = sizeof(ros_message->utc_ls);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_wnf
  {
    size_t item_size = sizeof(ros_message->utc_wnf);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_dn
  {
    size_t item_size = sizeof(ros_message->utc_dn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_lsf
  {
    size_t item_size = sizeof(ros_message->utc_lsf);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_spare
  {
    size_t item_size = sizeof(ros_message->utc_spare);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_a0
  {
    size_t item_size = sizeof(ros_message->klob_a0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_a1
  {
    size_t item_size = sizeof(ros_message->klob_a1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_a2
  {
    size_t item_size = sizeof(ros_message->klob_a2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_a3
  {
    size_t item_size = sizeof(ros_message->klob_a3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_b0
  {
    size_t item_size = sizeof(ros_message->klob_b0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_b1
  {
    size_t item_size = sizeof(ros_message->klob_b1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_b2
  {
    size_t item_size = sizeof(ros_message->klob_b2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name klob_b3
  {
    size_t item_size = sizeof(ros_message->klob_b3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flags
  {
    size_t item_size = sizeof(ros_message->flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AidHUI__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__AidHUI(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__AidHUI(
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

  // member: health
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: utc_a0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: utc_a1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: utc_tow
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: utc_wnt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: utc_ls
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: utc_wnf
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: utc_dn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: utc_lsf
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: utc_spare
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: klob_a0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: klob_a1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: klob_a2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: klob_a3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: klob_b0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: klob_b1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: klob_b2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: klob_b3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs__msg__AidHUI;
    is_plain =
      (
      offsetof(DataType, flags) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AidHUI__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__AidHUI(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AidHUI = {
  "ublox_msgs::msg",
  "AidHUI",
  _AidHUI__cdr_serialize,
  _AidHUI__cdr_deserialize,
  _AidHUI__get_serialized_size,
  _AidHUI__max_serialized_size
};

static rosidl_message_type_support_t _AidHUI__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AidHUI,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, AidHUI)() {
  return &_AidHUI__type_support;
}

#if defined(__cplusplus)
}
#endif

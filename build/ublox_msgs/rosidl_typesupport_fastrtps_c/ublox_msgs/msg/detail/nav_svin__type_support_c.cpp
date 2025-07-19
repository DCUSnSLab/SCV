// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/NavSVIN.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_svin__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/nav_svin__struct.h"
#include "ublox_msgs/msg/detail/nav_svin__functions.h"
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


using _NavSVIN__ros_msg_type = ublox_msgs__msg__NavSVIN;

static bool _NavSVIN__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NavSVIN__ros_msg_type * ros_message = static_cast<const _NavSVIN__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: reserved0
  {
    size_t size = 3;
    auto array_ptr = ros_message->reserved0;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: i_tow
  {
    cdr << ros_message->i_tow;
  }

  // Field name: dur
  {
    cdr << ros_message->dur;
  }

  // Field name: mean_x
  {
    cdr << ros_message->mean_x;
  }

  // Field name: mean_y
  {
    cdr << ros_message->mean_y;
  }

  // Field name: mean_z
  {
    cdr << ros_message->mean_z;
  }

  // Field name: mean_xhp
  {
    cdr << ros_message->mean_xhp;
  }

  // Field name: mean_yhp
  {
    cdr << ros_message->mean_yhp;
  }

  // Field name: mean_zhp
  {
    cdr << ros_message->mean_zhp;
  }

  // Field name: reserved1
  {
    cdr << ros_message->reserved1;
  }

  // Field name: mean_acc
  {
    cdr << ros_message->mean_acc;
  }

  // Field name: obs
  {
    cdr << ros_message->obs;
  }

  // Field name: valid
  {
    cdr << ros_message->valid;
  }

  // Field name: active
  {
    cdr << ros_message->active;
  }

  // Field name: reserved3
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved3;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _NavSVIN__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NavSVIN__ros_msg_type * ros_message = static_cast<_NavSVIN__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: reserved0
  {
    size_t size = 3;
    auto array_ptr = ros_message->reserved0;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: i_tow
  {
    cdr >> ros_message->i_tow;
  }

  // Field name: dur
  {
    cdr >> ros_message->dur;
  }

  // Field name: mean_x
  {
    cdr >> ros_message->mean_x;
  }

  // Field name: mean_y
  {
    cdr >> ros_message->mean_y;
  }

  // Field name: mean_z
  {
    cdr >> ros_message->mean_z;
  }

  // Field name: mean_xhp
  {
    cdr >> ros_message->mean_xhp;
  }

  // Field name: mean_yhp
  {
    cdr >> ros_message->mean_yhp;
  }

  // Field name: mean_zhp
  {
    cdr >> ros_message->mean_zhp;
  }

  // Field name: reserved1
  {
    cdr >> ros_message->reserved1;
  }

  // Field name: mean_acc
  {
    cdr >> ros_message->mean_acc;
  }

  // Field name: obs
  {
    cdr >> ros_message->obs;
  }

  // Field name: valid
  {
    cdr >> ros_message->valid;
  }

  // Field name: active
  {
    cdr >> ros_message->active;
  }

  // Field name: reserved3
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved3;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__NavSVIN(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavSVIN__ros_msg_type * ros_message = static_cast<const _NavSVIN__ros_msg_type *>(untyped_ros_message);
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
  // field.name reserved0
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->reserved0;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name i_tow
  {
    size_t item_size = sizeof(ros_message->i_tow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dur
  {
    size_t item_size = sizeof(ros_message->dur);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mean_x
  {
    size_t item_size = sizeof(ros_message->mean_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mean_y
  {
    size_t item_size = sizeof(ros_message->mean_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mean_z
  {
    size_t item_size = sizeof(ros_message->mean_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mean_xhp
  {
    size_t item_size = sizeof(ros_message->mean_xhp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mean_yhp
  {
    size_t item_size = sizeof(ros_message->mean_yhp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mean_zhp
  {
    size_t item_size = sizeof(ros_message->mean_zhp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved1
  {
    size_t item_size = sizeof(ros_message->reserved1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mean_acc
  {
    size_t item_size = sizeof(ros_message->mean_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name obs
  {
    size_t item_size = sizeof(ros_message->obs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name valid
  {
    size_t item_size = sizeof(ros_message->valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name active
  {
    size_t item_size = sizeof(ros_message->active);
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

  return current_alignment - initial_alignment;
}

static uint32_t _NavSVIN__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__NavSVIN(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__NavSVIN(
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

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved0
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: i_tow
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: dur
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: mean_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: mean_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: mean_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: mean_xhp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: mean_yhp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: mean_zhp
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
  // member: mean_acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: obs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: active
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs__msg__NavSVIN;
    is_plain =
      (
      offsetof(DataType, reserved3) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _NavSVIN__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__NavSVIN(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavSVIN = {
  "ublox_msgs::msg",
  "NavSVIN",
  _NavSVIN__cdr_serialize,
  _NavSVIN__cdr_deserialize,
  _NavSVIN__get_serialized_size,
  _NavSVIN__max_serialized_size
};

static rosidl_message_type_support_t _NavSVIN__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavSVIN,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, NavSVIN)() {
  return &_NavSVIN__type_support;
}

#if defined(__cplusplus)
}
#endif

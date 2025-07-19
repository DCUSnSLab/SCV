// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_posecef__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/nav_posecef__struct.h"
#include "ublox_msgs/msg/detail/nav_posecef__functions.h"
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


using _NavPOSECEF__ros_msg_type = ublox_msgs__msg__NavPOSECEF;

static bool _NavPOSECEF__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NavPOSECEF__ros_msg_type * ros_message = static_cast<const _NavPOSECEF__ros_msg_type *>(untyped_ros_message);
  // Field name: i_tow
  {
    cdr << ros_message->i_tow;
  }

  // Field name: ecef_x
  {
    cdr << ros_message->ecef_x;
  }

  // Field name: ecef_y
  {
    cdr << ros_message->ecef_y;
  }

  // Field name: ecef_z
  {
    cdr << ros_message->ecef_z;
  }

  // Field name: p_acc
  {
    cdr << ros_message->p_acc;
  }

  return true;
}

static bool _NavPOSECEF__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NavPOSECEF__ros_msg_type * ros_message = static_cast<_NavPOSECEF__ros_msg_type *>(untyped_ros_message);
  // Field name: i_tow
  {
    cdr >> ros_message->i_tow;
  }

  // Field name: ecef_x
  {
    cdr >> ros_message->ecef_x;
  }

  // Field name: ecef_y
  {
    cdr >> ros_message->ecef_y;
  }

  // Field name: ecef_z
  {
    cdr >> ros_message->ecef_z;
  }

  // Field name: p_acc
  {
    cdr >> ros_message->p_acc;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__NavPOSECEF(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavPOSECEF__ros_msg_type * ros_message = static_cast<const _NavPOSECEF__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name i_tow
  {
    size_t item_size = sizeof(ros_message->i_tow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_x
  {
    size_t item_size = sizeof(ros_message->ecef_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_y
  {
    size_t item_size = sizeof(ros_message->ecef_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_z
  {
    size_t item_size = sizeof(ros_message->ecef_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_acc
  {
    size_t item_size = sizeof(ros_message->p_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NavPOSECEF__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__NavPOSECEF(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__NavPOSECEF(
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

  // member: i_tow
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ecef_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ecef_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ecef_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: p_acc
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
    using DataType = ublox_msgs__msg__NavPOSECEF;
    is_plain =
      (
      offsetof(DataType, p_acc) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _NavPOSECEF__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__NavPOSECEF(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavPOSECEF = {
  "ublox_msgs::msg",
  "NavPOSECEF",
  _NavPOSECEF__cdr_serialize,
  _NavPOSECEF__cdr_deserialize,
  _NavPOSECEF__get_serialized_size,
  _NavPOSECEF__max_serialized_size
};

static rosidl_message_type_support_t _NavPOSECEF__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavPOSECEF,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, NavPOSECEF)() {
  return &_NavPOSECEF__type_support;
}

#if defined(__cplusplus)
}
#endif

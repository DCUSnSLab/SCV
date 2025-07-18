// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/NavCOV.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_cov__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/nav_cov__struct.h"
#include "ublox_msgs/msg/detail/nav_cov__functions.h"
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


using _NavCOV__ros_msg_type = ublox_msgs__msg__NavCOV;

static bool _NavCOV__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NavCOV__ros_msg_type * ros_message = static_cast<const _NavCOV__ros_msg_type *>(untyped_ros_message);
  // Field name: i_tow
  {
    cdr << ros_message->i_tow;
  }

  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: pos_cov_valid
  {
    cdr << ros_message->pos_cov_valid;
  }

  // Field name: vel_cov_valid
  {
    cdr << ros_message->vel_cov_valid;
  }

  // Field name: reserved_0
  {
    size_t size = 9;
    auto array_ptr = ros_message->reserved_0;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: pos_cov_nn
  {
    cdr << ros_message->pos_cov_nn;
  }

  // Field name: pos_cov_ne
  {
    cdr << ros_message->pos_cov_ne;
  }

  // Field name: pos_cov_nd
  {
    cdr << ros_message->pos_cov_nd;
  }

  // Field name: pos_cov_ee
  {
    cdr << ros_message->pos_cov_ee;
  }

  // Field name: pos_cov_ed
  {
    cdr << ros_message->pos_cov_ed;
  }

  // Field name: pos_cov_dd
  {
    cdr << ros_message->pos_cov_dd;
  }

  // Field name: vel_cov_nn
  {
    cdr << ros_message->vel_cov_nn;
  }

  // Field name: vel_cov_ne
  {
    cdr << ros_message->vel_cov_ne;
  }

  // Field name: vel_cov_nd
  {
    cdr << ros_message->vel_cov_nd;
  }

  // Field name: vel_cov_ee
  {
    cdr << ros_message->vel_cov_ee;
  }

  // Field name: vel_cov_ed
  {
    cdr << ros_message->vel_cov_ed;
  }

  // Field name: vel_cov_dd
  {
    cdr << ros_message->vel_cov_dd;
  }

  return true;
}

static bool _NavCOV__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NavCOV__ros_msg_type * ros_message = static_cast<_NavCOV__ros_msg_type *>(untyped_ros_message);
  // Field name: i_tow
  {
    cdr >> ros_message->i_tow;
  }

  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: pos_cov_valid
  {
    cdr >> ros_message->pos_cov_valid;
  }

  // Field name: vel_cov_valid
  {
    cdr >> ros_message->vel_cov_valid;
  }

  // Field name: reserved_0
  {
    size_t size = 9;
    auto array_ptr = ros_message->reserved_0;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: pos_cov_nn
  {
    cdr >> ros_message->pos_cov_nn;
  }

  // Field name: pos_cov_ne
  {
    cdr >> ros_message->pos_cov_ne;
  }

  // Field name: pos_cov_nd
  {
    cdr >> ros_message->pos_cov_nd;
  }

  // Field name: pos_cov_ee
  {
    cdr >> ros_message->pos_cov_ee;
  }

  // Field name: pos_cov_ed
  {
    cdr >> ros_message->pos_cov_ed;
  }

  // Field name: pos_cov_dd
  {
    cdr >> ros_message->pos_cov_dd;
  }

  // Field name: vel_cov_nn
  {
    cdr >> ros_message->vel_cov_nn;
  }

  // Field name: vel_cov_ne
  {
    cdr >> ros_message->vel_cov_ne;
  }

  // Field name: vel_cov_nd
  {
    cdr >> ros_message->vel_cov_nd;
  }

  // Field name: vel_cov_ee
  {
    cdr >> ros_message->vel_cov_ee;
  }

  // Field name: vel_cov_ed
  {
    cdr >> ros_message->vel_cov_ed;
  }

  // Field name: vel_cov_dd
  {
    cdr >> ros_message->vel_cov_dd;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__NavCOV(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavCOV__ros_msg_type * ros_message = static_cast<const _NavCOV__ros_msg_type *>(untyped_ros_message);
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
  // field.name version
  {
    size_t item_size = sizeof(ros_message->version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_cov_valid
  {
    size_t item_size = sizeof(ros_message->pos_cov_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_cov_valid
  {
    size_t item_size = sizeof(ros_message->vel_cov_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved_0
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->reserved_0;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_cov_nn
  {
    size_t item_size = sizeof(ros_message->pos_cov_nn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_cov_ne
  {
    size_t item_size = sizeof(ros_message->pos_cov_ne);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_cov_nd
  {
    size_t item_size = sizeof(ros_message->pos_cov_nd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_cov_ee
  {
    size_t item_size = sizeof(ros_message->pos_cov_ee);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_cov_ed
  {
    size_t item_size = sizeof(ros_message->pos_cov_ed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_cov_dd
  {
    size_t item_size = sizeof(ros_message->pos_cov_dd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_cov_nn
  {
    size_t item_size = sizeof(ros_message->vel_cov_nn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_cov_ne
  {
    size_t item_size = sizeof(ros_message->vel_cov_ne);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_cov_nd
  {
    size_t item_size = sizeof(ros_message->vel_cov_nd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_cov_ee
  {
    size_t item_size = sizeof(ros_message->vel_cov_ee);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_cov_ed
  {
    size_t item_size = sizeof(ros_message->vel_cov_ed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_cov_dd
  {
    size_t item_size = sizeof(ros_message->vel_cov_dd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NavCOV__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__NavCOV(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__NavCOV(
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
  // member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: pos_cov_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: vel_cov_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved_0
  {
    size_t array_size = 9;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: pos_cov_nn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pos_cov_ne
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pos_cov_nd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pos_cov_ee
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pos_cov_ed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pos_cov_dd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vel_cov_nn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vel_cov_ne
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vel_cov_nd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vel_cov_ee
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vel_cov_ed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vel_cov_dd
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
    using DataType = ublox_msgs__msg__NavCOV;
    is_plain =
      (
      offsetof(DataType, vel_cov_dd) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _NavCOV__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__NavCOV(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavCOV = {
  "ublox_msgs::msg",
  "NavCOV",
  _NavCOV__cdr_serialize,
  _NavCOV__cdr_deserialize,
  _NavCOV__get_serialized_size,
  _NavCOV__max_serialized_size
};

static rosidl_message_type_support_t _NavCOV__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavCOV,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, NavCOV)() {
  return &_NavCOV__type_support;
}

#if defined(__cplusplus)
}
#endif

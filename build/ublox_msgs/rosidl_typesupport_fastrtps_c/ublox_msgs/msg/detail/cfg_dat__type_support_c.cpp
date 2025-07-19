// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/CfgDAT.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_dat__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/cfg_dat__struct.h"
#include "ublox_msgs/msg/detail/cfg_dat__functions.h"
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


using _CfgDAT__ros_msg_type = ublox_msgs__msg__CfgDAT;

static bool _CfgDAT__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CfgDAT__ros_msg_type * ros_message = static_cast<const _CfgDAT__ros_msg_type *>(untyped_ros_message);
  // Field name: datum_num
  {
    cdr << ros_message->datum_num;
  }

  // Field name: datum_name
  {
    size_t size = 6;
    auto array_ptr = ros_message->datum_name;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: maj_a
  {
    cdr << ros_message->maj_a;
  }

  // Field name: flat
  {
    cdr << ros_message->flat;
  }

  // Field name: d_x
  {
    cdr << ros_message->d_x;
  }

  // Field name: d_y
  {
    cdr << ros_message->d_y;
  }

  // Field name: d_z
  {
    cdr << ros_message->d_z;
  }

  // Field name: rot_x
  {
    cdr << ros_message->rot_x;
  }

  // Field name: rot_y
  {
    cdr << ros_message->rot_y;
  }

  // Field name: rot_z
  {
    cdr << ros_message->rot_z;
  }

  // Field name: scale
  {
    cdr << ros_message->scale;
  }

  return true;
}

static bool _CfgDAT__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CfgDAT__ros_msg_type * ros_message = static_cast<_CfgDAT__ros_msg_type *>(untyped_ros_message);
  // Field name: datum_num
  {
    cdr >> ros_message->datum_num;
  }

  // Field name: datum_name
  {
    size_t size = 6;
    auto array_ptr = ros_message->datum_name;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: maj_a
  {
    cdr >> ros_message->maj_a;
  }

  // Field name: flat
  {
    cdr >> ros_message->flat;
  }

  // Field name: d_x
  {
    cdr >> ros_message->d_x;
  }

  // Field name: d_y
  {
    cdr >> ros_message->d_y;
  }

  // Field name: d_z
  {
    cdr >> ros_message->d_z;
  }

  // Field name: rot_x
  {
    cdr >> ros_message->rot_x;
  }

  // Field name: rot_y
  {
    cdr >> ros_message->rot_y;
  }

  // Field name: rot_z
  {
    cdr >> ros_message->rot_z;
  }

  // Field name: scale
  {
    cdr >> ros_message->scale;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__CfgDAT(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CfgDAT__ros_msg_type * ros_message = static_cast<const _CfgDAT__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name datum_num
  {
    size_t item_size = sizeof(ros_message->datum_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name datum_name
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->datum_name;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name maj_a
  {
    size_t item_size = sizeof(ros_message->maj_a);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flat
  {
    size_t item_size = sizeof(ros_message->flat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name d_x
  {
    size_t item_size = sizeof(ros_message->d_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name d_y
  {
    size_t item_size = sizeof(ros_message->d_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name d_z
  {
    size_t item_size = sizeof(ros_message->d_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rot_x
  {
    size_t item_size = sizeof(ros_message->rot_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rot_y
  {
    size_t item_size = sizeof(ros_message->rot_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rot_z
  {
    size_t item_size = sizeof(ros_message->rot_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name scale
  {
    size_t item_size = sizeof(ros_message->scale);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CfgDAT__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__CfgDAT(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__CfgDAT(
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

  // member: datum_num
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: datum_name
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: maj_a
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: flat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: d_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: d_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: d_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rot_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rot_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rot_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: scale
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
    using DataType = ublox_msgs__msg__CfgDAT;
    is_plain =
      (
      offsetof(DataType, scale) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CfgDAT__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__CfgDAT(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CfgDAT = {
  "ublox_msgs::msg",
  "CfgDAT",
  _CfgDAT__cdr_serialize,
  _CfgDAT__cdr_deserialize,
  _CfgDAT__get_serialized_size,
  _CfgDAT__max_serialized_size
};

static rosidl_message_type_support_t _CfgDAT__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CfgDAT,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, CfgDAT)() {
  return &_CfgDAT__type_support;
}

#if defined(__cplusplus)
}
#endif

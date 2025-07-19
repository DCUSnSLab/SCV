// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hunter_msgs:msg/HunterLightState.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_light_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hunter_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hunter_msgs/msg/detail/hunter_light_state__struct.h"
#include "hunter_msgs/msg/detail/hunter_light_state__functions.h"
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


using _HunterLightState__ros_msg_type = hunter_msgs__msg__HunterLightState;

static bool _HunterLightState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HunterLightState__ros_msg_type * ros_message = static_cast<const _HunterLightState__ros_msg_type *>(untyped_ros_message);
  // Field name: mode
  {
    cdr << ros_message->mode;
  }

  // Field name: custom_value
  {
    cdr << ros_message->custom_value;
  }

  return true;
}

static bool _HunterLightState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HunterLightState__ros_msg_type * ros_message = static_cast<_HunterLightState__ros_msg_type *>(untyped_ros_message);
  // Field name: mode
  {
    cdr >> ros_message->mode;
  }

  // Field name: custom_value
  {
    cdr >> ros_message->custom_value;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hunter_msgs
size_t get_serialized_size_hunter_msgs__msg__HunterLightState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HunterLightState__ros_msg_type * ros_message = static_cast<const _HunterLightState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name mode
  {
    size_t item_size = sizeof(ros_message->mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name custom_value
  {
    size_t item_size = sizeof(ros_message->custom_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HunterLightState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hunter_msgs__msg__HunterLightState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hunter_msgs
size_t max_serialized_size_hunter_msgs__msg__HunterLightState(
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

  // member: mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: custom_value
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
    using DataType = hunter_msgs__msg__HunterLightState;
    is_plain =
      (
      offsetof(DataType, custom_value) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _HunterLightState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_hunter_msgs__msg__HunterLightState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HunterLightState = {
  "hunter_msgs::msg",
  "HunterLightState",
  _HunterLightState__cdr_serialize,
  _HunterLightState__cdr_deserialize,
  _HunterLightState__get_serialized_size,
  _HunterLightState__max_serialized_size
};

static rosidl_message_type_support_t _HunterLightState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HunterLightState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hunter_msgs, msg, HunterLightState)() {
  return &_HunterLightState__type_support;
}

#if defined(__cplusplus)
}
#endif

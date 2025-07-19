// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/CfgNMEA7.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_nmea7__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/cfg_nmea7__struct.h"
#include "ublox_msgs/msg/detail/cfg_nmea7__functions.h"
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


using _CfgNMEA7__ros_msg_type = ublox_msgs__msg__CfgNMEA7;

static bool _CfgNMEA7__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CfgNMEA7__ros_msg_type * ros_message = static_cast<const _CfgNMEA7__ros_msg_type *>(untyped_ros_message);
  // Field name: filter
  {
    cdr << ros_message->filter;
  }

  // Field name: nmea_version
  {
    cdr << ros_message->nmea_version;
  }

  // Field name: num_sv
  {
    cdr << ros_message->num_sv;
  }

  // Field name: flags
  {
    cdr << ros_message->flags;
  }

  // Field name: gnss_to_filter
  {
    cdr << ros_message->gnss_to_filter;
  }

  // Field name: sv_numbering
  {
    cdr << ros_message->sv_numbering;
  }

  // Field name: main_talker_id
  {
    cdr << ros_message->main_talker_id;
  }

  // Field name: gsv_talker_id
  {
    cdr << ros_message->gsv_talker_id;
  }

  // Field name: reserved
  {
    cdr << ros_message->reserved;
  }

  return true;
}

static bool _CfgNMEA7__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CfgNMEA7__ros_msg_type * ros_message = static_cast<_CfgNMEA7__ros_msg_type *>(untyped_ros_message);
  // Field name: filter
  {
    cdr >> ros_message->filter;
  }

  // Field name: nmea_version
  {
    cdr >> ros_message->nmea_version;
  }

  // Field name: num_sv
  {
    cdr >> ros_message->num_sv;
  }

  // Field name: flags
  {
    cdr >> ros_message->flags;
  }

  // Field name: gnss_to_filter
  {
    cdr >> ros_message->gnss_to_filter;
  }

  // Field name: sv_numbering
  {
    cdr >> ros_message->sv_numbering;
  }

  // Field name: main_talker_id
  {
    cdr >> ros_message->main_talker_id;
  }

  // Field name: gsv_talker_id
  {
    cdr >> ros_message->gsv_talker_id;
  }

  // Field name: reserved
  {
    cdr >> ros_message->reserved;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__CfgNMEA7(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CfgNMEA7__ros_msg_type * ros_message = static_cast<const _CfgNMEA7__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name filter
  {
    size_t item_size = sizeof(ros_message->filter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nmea_version
  {
    size_t item_size = sizeof(ros_message->nmea_version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name num_sv
  {
    size_t item_size = sizeof(ros_message->num_sv);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flags
  {
    size_t item_size = sizeof(ros_message->flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gnss_to_filter
  {
    size_t item_size = sizeof(ros_message->gnss_to_filter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sv_numbering
  {
    size_t item_size = sizeof(ros_message->sv_numbering);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name main_talker_id
  {
    size_t item_size = sizeof(ros_message->main_talker_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gsv_talker_id
  {
    size_t item_size = sizeof(ros_message->gsv_talker_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved
  {
    size_t item_size = sizeof(ros_message->reserved);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CfgNMEA7__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__CfgNMEA7(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__CfgNMEA7(
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

  // member: filter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: nmea_version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: num_sv
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: gnss_to_filter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: sv_numbering
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: main_talker_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: gsv_talker_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved
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
    using DataType = ublox_msgs__msg__CfgNMEA7;
    is_plain =
      (
      offsetof(DataType, reserved) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CfgNMEA7__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__CfgNMEA7(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CfgNMEA7 = {
  "ublox_msgs::msg",
  "CfgNMEA7",
  _CfgNMEA7__cdr_serialize,
  _CfgNMEA7__cdr_deserialize,
  _CfgNMEA7__get_serialized_size,
  _CfgNMEA7__max_serialized_size
};

static rosidl_message_type_support_t _CfgNMEA7__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CfgNMEA7,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, CfgNMEA7)() {
  return &_CfgNMEA7__type_support;
}

#if defined(__cplusplus)
}
#endif

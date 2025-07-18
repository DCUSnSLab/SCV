// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_tmode3__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/cfg_tmode3__struct.h"
#include "ublox_msgs/msg/detail/cfg_tmode3__functions.h"
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


using _CfgTMODE3__ros_msg_type = ublox_msgs__msg__CfgTMODE3;

static bool _CfgTMODE3__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CfgTMODE3__ros_msg_type * ros_message = static_cast<const _CfgTMODE3__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: reserved1
  {
    cdr << ros_message->reserved1;
  }

  // Field name: flags
  {
    cdr << ros_message->flags;
  }

  // Field name: ecef_x_or_lat
  {
    cdr << ros_message->ecef_x_or_lat;
  }

  // Field name: ecef_y_or_lon
  {
    cdr << ros_message->ecef_y_or_lon;
  }

  // Field name: ecef_z_or_alt
  {
    cdr << ros_message->ecef_z_or_alt;
  }

  // Field name: ecef_x_or_lat_hp
  {
    cdr << ros_message->ecef_x_or_lat_hp;
  }

  // Field name: ecef_y_or_lon_hp
  {
    cdr << ros_message->ecef_y_or_lon_hp;
  }

  // Field name: ecef_z_or_alt_hp
  {
    cdr << ros_message->ecef_z_or_alt_hp;
  }

  // Field name: reserved2
  {
    cdr << ros_message->reserved2;
  }

  // Field name: fixed_pos_acc
  {
    cdr << ros_message->fixed_pos_acc;
  }

  // Field name: svin_min_dur
  {
    cdr << ros_message->svin_min_dur;
  }

  // Field name: svin_acc_limit
  {
    cdr << ros_message->svin_acc_limit;
  }

  // Field name: reserved3
  {
    size_t size = 8;
    auto array_ptr = ros_message->reserved3;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _CfgTMODE3__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CfgTMODE3__ros_msg_type * ros_message = static_cast<_CfgTMODE3__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: reserved1
  {
    cdr >> ros_message->reserved1;
  }

  // Field name: flags
  {
    cdr >> ros_message->flags;
  }

  // Field name: ecef_x_or_lat
  {
    cdr >> ros_message->ecef_x_or_lat;
  }

  // Field name: ecef_y_or_lon
  {
    cdr >> ros_message->ecef_y_or_lon;
  }

  // Field name: ecef_z_or_alt
  {
    cdr >> ros_message->ecef_z_or_alt;
  }

  // Field name: ecef_x_or_lat_hp
  {
    cdr >> ros_message->ecef_x_or_lat_hp;
  }

  // Field name: ecef_y_or_lon_hp
  {
    cdr >> ros_message->ecef_y_or_lon_hp;
  }

  // Field name: ecef_z_or_alt_hp
  {
    cdr >> ros_message->ecef_z_or_alt_hp;
  }

  // Field name: reserved2
  {
    cdr >> ros_message->reserved2;
  }

  // Field name: fixed_pos_acc
  {
    cdr >> ros_message->fixed_pos_acc;
  }

  // Field name: svin_min_dur
  {
    cdr >> ros_message->svin_min_dur;
  }

  // Field name: svin_acc_limit
  {
    cdr >> ros_message->svin_acc_limit;
  }

  // Field name: reserved3
  {
    size_t size = 8;
    auto array_ptr = ros_message->reserved3;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__CfgTMODE3(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CfgTMODE3__ros_msg_type * ros_message = static_cast<const _CfgTMODE3__ros_msg_type *>(untyped_ros_message);
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
  // field.name reserved1
  {
    size_t item_size = sizeof(ros_message->reserved1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flags
  {
    size_t item_size = sizeof(ros_message->flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_x_or_lat
  {
    size_t item_size = sizeof(ros_message->ecef_x_or_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_y_or_lon
  {
    size_t item_size = sizeof(ros_message->ecef_y_or_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_z_or_alt
  {
    size_t item_size = sizeof(ros_message->ecef_z_or_alt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_x_or_lat_hp
  {
    size_t item_size = sizeof(ros_message->ecef_x_or_lat_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_y_or_lon_hp
  {
    size_t item_size = sizeof(ros_message->ecef_y_or_lon_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ecef_z_or_alt_hp
  {
    size_t item_size = sizeof(ros_message->ecef_z_or_alt_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved2
  {
    size_t item_size = sizeof(ros_message->reserved2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fixed_pos_acc
  {
    size_t item_size = sizeof(ros_message->fixed_pos_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name svin_min_dur
  {
    size_t item_size = sizeof(ros_message->svin_min_dur);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name svin_acc_limit
  {
    size_t item_size = sizeof(ros_message->svin_acc_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved3
  {
    size_t array_size = 8;
    auto array_ptr = ros_message->reserved3;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CfgTMODE3__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__CfgTMODE3(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__CfgTMODE3(
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
  // member: reserved1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: ecef_x_or_lat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ecef_y_or_lon
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ecef_z_or_alt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ecef_x_or_lat_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ecef_y_or_lon_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ecef_z_or_alt_hp
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
  // member: fixed_pos_acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: svin_min_dur
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: svin_acc_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: reserved3
  {
    size_t array_size = 8;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs__msg__CfgTMODE3;
    is_plain =
      (
      offsetof(DataType, reserved3) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CfgTMODE3__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__CfgTMODE3(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CfgTMODE3 = {
  "ublox_msgs::msg",
  "CfgTMODE3",
  _CfgTMODE3__cdr_serialize,
  _CfgTMODE3__cdr_deserialize,
  _CfgTMODE3__get_serialized_size,
  _CfgTMODE3__max_serialized_size
};

static rosidl_message_type_support_t _CfgTMODE3__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CfgTMODE3,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, CfgTMODE3)() {
  return &_CfgTMODE3__type_support;
}

#if defined(__cplusplus)
}
#endif

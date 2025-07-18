// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/MonHW.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/mon_hw__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/mon_hw__struct.h"
#include "ublox_msgs/msg/detail/mon_hw__functions.h"
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


using _MonHW__ros_msg_type = ublox_msgs__msg__MonHW;

static bool _MonHW__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MonHW__ros_msg_type * ros_message = static_cast<const _MonHW__ros_msg_type *>(untyped_ros_message);
  // Field name: pin_sel
  {
    cdr << ros_message->pin_sel;
  }

  // Field name: pin_bank
  {
    cdr << ros_message->pin_bank;
  }

  // Field name: pin_dir
  {
    cdr << ros_message->pin_dir;
  }

  // Field name: pin_val
  {
    cdr << ros_message->pin_val;
  }

  // Field name: noise_per_ms
  {
    cdr << ros_message->noise_per_ms;
  }

  // Field name: agc_cnt
  {
    cdr << ros_message->agc_cnt;
  }

  // Field name: a_status
  {
    cdr << ros_message->a_status;
  }

  // Field name: a_power
  {
    cdr << ros_message->a_power;
  }

  // Field name: flags
  {
    cdr << ros_message->flags;
  }

  // Field name: reserved0
  {
    cdr << ros_message->reserved0;
  }

  // Field name: used_mask
  {
    cdr << ros_message->used_mask;
  }

  // Field name: vp
  {
    size_t size = 17;
    auto array_ptr = ros_message->vp;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: jam_ind
  {
    cdr << ros_message->jam_ind;
  }

  // Field name: reserved1
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved1;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: pin_irq
  {
    cdr << ros_message->pin_irq;
  }

  // Field name: pull_h
  {
    cdr << ros_message->pull_h;
  }

  // Field name: pull_l
  {
    cdr << ros_message->pull_l;
  }

  return true;
}

static bool _MonHW__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MonHW__ros_msg_type * ros_message = static_cast<_MonHW__ros_msg_type *>(untyped_ros_message);
  // Field name: pin_sel
  {
    cdr >> ros_message->pin_sel;
  }

  // Field name: pin_bank
  {
    cdr >> ros_message->pin_bank;
  }

  // Field name: pin_dir
  {
    cdr >> ros_message->pin_dir;
  }

  // Field name: pin_val
  {
    cdr >> ros_message->pin_val;
  }

  // Field name: noise_per_ms
  {
    cdr >> ros_message->noise_per_ms;
  }

  // Field name: agc_cnt
  {
    cdr >> ros_message->agc_cnt;
  }

  // Field name: a_status
  {
    cdr >> ros_message->a_status;
  }

  // Field name: a_power
  {
    cdr >> ros_message->a_power;
  }

  // Field name: flags
  {
    cdr >> ros_message->flags;
  }

  // Field name: reserved0
  {
    cdr >> ros_message->reserved0;
  }

  // Field name: used_mask
  {
    cdr >> ros_message->used_mask;
  }

  // Field name: vp
  {
    size_t size = 17;
    auto array_ptr = ros_message->vp;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: jam_ind
  {
    cdr >> ros_message->jam_ind;
  }

  // Field name: reserved1
  {
    size_t size = 2;
    auto array_ptr = ros_message->reserved1;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: pin_irq
  {
    cdr >> ros_message->pin_irq;
  }

  // Field name: pull_h
  {
    cdr >> ros_message->pull_h;
  }

  // Field name: pull_l
  {
    cdr >> ros_message->pull_l;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__MonHW(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MonHW__ros_msg_type * ros_message = static_cast<const _MonHW__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pin_sel
  {
    size_t item_size = sizeof(ros_message->pin_sel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pin_bank
  {
    size_t item_size = sizeof(ros_message->pin_bank);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pin_dir
  {
    size_t item_size = sizeof(ros_message->pin_dir);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pin_val
  {
    size_t item_size = sizeof(ros_message->pin_val);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name noise_per_ms
  {
    size_t item_size = sizeof(ros_message->noise_per_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name agc_cnt
  {
    size_t item_size = sizeof(ros_message->agc_cnt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_status
  {
    size_t item_size = sizeof(ros_message->a_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_power
  {
    size_t item_size = sizeof(ros_message->a_power);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flags
  {
    size_t item_size = sizeof(ros_message->flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved0
  {
    size_t item_size = sizeof(ros_message->reserved0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name used_mask
  {
    size_t item_size = sizeof(ros_message->used_mask);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vp
  {
    size_t array_size = 17;
    auto array_ptr = ros_message->vp;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name jam_ind
  {
    size_t item_size = sizeof(ros_message->jam_ind);
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
  // field.name pin_irq
  {
    size_t item_size = sizeof(ros_message->pin_irq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pull_h
  {
    size_t item_size = sizeof(ros_message->pull_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pull_l
  {
    size_t item_size = sizeof(ros_message->pull_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MonHW__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__MonHW(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__MonHW(
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

  // member: pin_sel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pin_bank
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pin_dir
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pin_val
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: noise_per_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: agc_cnt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: a_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: a_power
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
  // member: reserved0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: used_mask
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vp
  {
    size_t array_size = 17;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: jam_ind
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
  // member: pin_irq
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pull_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pull_l
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
    using DataType = ublox_msgs__msg__MonHW;
    is_plain =
      (
      offsetof(DataType, pull_l) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MonHW__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__MonHW(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MonHW = {
  "ublox_msgs::msg",
  "MonHW",
  _MonHW__cdr_serialize,
  _MonHW__cdr_deserialize,
  _MonHW__get_serialized_size,
  _MonHW__max_serialized_size
};

static rosidl_message_type_support_t _MonHW__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MonHW,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, MonHW)() {
  return &_MonHW__type_support;
}

#if defined(__cplusplus)
}
#endif

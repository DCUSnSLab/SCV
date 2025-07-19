// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/MonHW.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/mon_hw__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/mon_hw__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ublox_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_serialize(
  const ublox_msgs::msg::MonHW & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pin_sel
  cdr << ros_message.pin_sel;
  // Member: pin_bank
  cdr << ros_message.pin_bank;
  // Member: pin_dir
  cdr << ros_message.pin_dir;
  // Member: pin_val
  cdr << ros_message.pin_val;
  // Member: noise_per_ms
  cdr << ros_message.noise_per_ms;
  // Member: agc_cnt
  cdr << ros_message.agc_cnt;
  // Member: a_status
  cdr << ros_message.a_status;
  // Member: a_power
  cdr << ros_message.a_power;
  // Member: flags
  cdr << ros_message.flags;
  // Member: reserved0
  cdr << ros_message.reserved0;
  // Member: used_mask
  cdr << ros_message.used_mask;
  // Member: vp
  {
    cdr << ros_message.vp;
  }
  // Member: jam_ind
  cdr << ros_message.jam_ind;
  // Member: reserved1
  {
    cdr << ros_message.reserved1;
  }
  // Member: pin_irq
  cdr << ros_message.pin_irq;
  // Member: pull_h
  cdr << ros_message.pull_h;
  // Member: pull_l
  cdr << ros_message.pull_l;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::MonHW & ros_message)
{
  // Member: pin_sel
  cdr >> ros_message.pin_sel;

  // Member: pin_bank
  cdr >> ros_message.pin_bank;

  // Member: pin_dir
  cdr >> ros_message.pin_dir;

  // Member: pin_val
  cdr >> ros_message.pin_val;

  // Member: noise_per_ms
  cdr >> ros_message.noise_per_ms;

  // Member: agc_cnt
  cdr >> ros_message.agc_cnt;

  // Member: a_status
  cdr >> ros_message.a_status;

  // Member: a_power
  cdr >> ros_message.a_power;

  // Member: flags
  cdr >> ros_message.flags;

  // Member: reserved0
  cdr >> ros_message.reserved0;

  // Member: used_mask
  cdr >> ros_message.used_mask;

  // Member: vp
  {
    cdr >> ros_message.vp;
  }

  // Member: jam_ind
  cdr >> ros_message.jam_ind;

  // Member: reserved1
  {
    cdr >> ros_message.reserved1;
  }

  // Member: pin_irq
  cdr >> ros_message.pin_irq;

  // Member: pull_h
  cdr >> ros_message.pull_h;

  // Member: pull_l
  cdr >> ros_message.pull_l;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::MonHW & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pin_sel
  {
    size_t item_size = sizeof(ros_message.pin_sel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pin_bank
  {
    size_t item_size = sizeof(ros_message.pin_bank);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pin_dir
  {
    size_t item_size = sizeof(ros_message.pin_dir);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pin_val
  {
    size_t item_size = sizeof(ros_message.pin_val);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: noise_per_ms
  {
    size_t item_size = sizeof(ros_message.noise_per_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: agc_cnt
  {
    size_t item_size = sizeof(ros_message.agc_cnt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_status
  {
    size_t item_size = sizeof(ros_message.a_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_power
  {
    size_t item_size = sizeof(ros_message.a_power);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: flags
  {
    size_t item_size = sizeof(ros_message.flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved0
  {
    size_t item_size = sizeof(ros_message.reserved0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: used_mask
  {
    size_t item_size = sizeof(ros_message.used_mask);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vp
  {
    size_t array_size = 17;
    size_t item_size = sizeof(ros_message.vp[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: jam_ind
  {
    size_t item_size = sizeof(ros_message.jam_ind);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved1
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.reserved1[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pin_irq
  {
    size_t item_size = sizeof(ros_message.pin_irq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pull_h
  {
    size_t item_size = sizeof(ros_message.pull_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pull_l
  {
    size_t item_size = sizeof(ros_message.pull_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_MonHW(
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


  // Member: pin_sel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pin_bank
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pin_dir
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pin_val
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: noise_per_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: agc_cnt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: a_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: a_power
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: used_mask
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vp
  {
    size_t array_size = 17;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: jam_ind
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved1
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pin_irq
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pull_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pull_l
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
    using DataType = ublox_msgs::msg::MonHW;
    is_plain =
      (
      offsetof(DataType, pull_l) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MonHW__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::MonHW *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MonHW__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::MonHW *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MonHW__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::MonHW *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MonHW__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MonHW(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MonHW__callbacks = {
  "ublox_msgs::msg",
  "MonHW",
  _MonHW__cdr_serialize,
  _MonHW__cdr_deserialize,
  _MonHW__get_serialized_size,
  _MonHW__max_serialized_size
};

static rosidl_message_type_support_t _MonHW__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MonHW__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ublox_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<ublox_msgs::msg::MonHW>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_MonHW__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, MonHW)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_MonHW__handle;
}

#ifdef __cplusplus
}
#endif

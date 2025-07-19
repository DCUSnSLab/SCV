// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hunter_msgs:msg/HunterRCState.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_rc_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hunter_msgs/msg/detail/hunter_rc_state__struct.hpp"

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

namespace hunter_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
cdr_serialize(
  const hunter_msgs::msg::HunterRCState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: swa
  cdr << ros_message.swa;
  // Member: swb
  cdr << ros_message.swb;
  // Member: swc
  cdr << ros_message.swc;
  // Member: swd
  cdr << ros_message.swd;
  // Member: stick_right_v
  cdr << ros_message.stick_right_v;
  // Member: stick_right_h
  cdr << ros_message.stick_right_h;
  // Member: stick_left_v
  cdr << ros_message.stick_left_v;
  // Member: stick_left_h
  cdr << ros_message.stick_left_h;
  // Member: var_a
  cdr << ros_message.var_a;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hunter_msgs::msg::HunterRCState & ros_message)
{
  // Member: swa
  cdr >> ros_message.swa;

  // Member: swb
  cdr >> ros_message.swb;

  // Member: swc
  cdr >> ros_message.swc;

  // Member: swd
  cdr >> ros_message.swd;

  // Member: stick_right_v
  cdr >> ros_message.stick_right_v;

  // Member: stick_right_h
  cdr >> ros_message.stick_right_h;

  // Member: stick_left_v
  cdr >> ros_message.stick_left_v;

  // Member: stick_left_h
  cdr >> ros_message.stick_left_h;

  // Member: var_a
  cdr >> ros_message.var_a;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
get_serialized_size(
  const hunter_msgs::msg::HunterRCState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: swa
  {
    size_t item_size = sizeof(ros_message.swa);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: swb
  {
    size_t item_size = sizeof(ros_message.swb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: swc
  {
    size_t item_size = sizeof(ros_message.swc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: swd
  {
    size_t item_size = sizeof(ros_message.swd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stick_right_v
  {
    size_t item_size = sizeof(ros_message.stick_right_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stick_right_h
  {
    size_t item_size = sizeof(ros_message.stick_right_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stick_left_v
  {
    size_t item_size = sizeof(ros_message.stick_left_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stick_left_h
  {
    size_t item_size = sizeof(ros_message.stick_left_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: var_a
  {
    size_t item_size = sizeof(ros_message.var_a);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
max_serialized_size_HunterRCState(
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


  // Member: swa
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: swb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: swc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: swd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stick_right_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stick_right_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stick_left_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stick_left_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: var_a
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
    using DataType = hunter_msgs::msg::HunterRCState;
    is_plain =
      (
      offsetof(DataType, var_a) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _HunterRCState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hunter_msgs::msg::HunterRCState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HunterRCState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hunter_msgs::msg::HunterRCState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HunterRCState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hunter_msgs::msg::HunterRCState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HunterRCState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HunterRCState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HunterRCState__callbacks = {
  "hunter_msgs::msg",
  "HunterRCState",
  _HunterRCState__cdr_serialize,
  _HunterRCState__cdr_deserialize,
  _HunterRCState__get_serialized_size,
  _HunterRCState__max_serialized_size
};

static rosidl_message_type_support_t _HunterRCState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HunterRCState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hunter_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hunter_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<hunter_msgs::msg::HunterRCState>()
{
  return &hunter_msgs::msg::typesupport_fastrtps_cpp::_HunterRCState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hunter_msgs, msg, HunterRCState)() {
  return &hunter_msgs::msg::typesupport_fastrtps_cpp::_HunterRCState__handle;
}

#ifdef __cplusplus
}
#endif

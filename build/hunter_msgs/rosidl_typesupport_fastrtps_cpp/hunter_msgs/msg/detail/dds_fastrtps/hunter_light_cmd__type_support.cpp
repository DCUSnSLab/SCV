// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hunter_msgs:msg/HunterLightCmd.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_light_cmd__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hunter_msgs/msg/detail/hunter_light_cmd__struct.hpp"

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
  const hunter_msgs::msg::HunterLightCmd & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: cmd_ctrl_allowed
  cdr << (ros_message.cmd_ctrl_allowed ? true : false);
  // Member: front_mode
  cdr << ros_message.front_mode;
  // Member: front_custom_value
  cdr << ros_message.front_custom_value;
  // Member: rear_mode
  cdr << ros_message.rear_mode;
  // Member: rear_custom_value
  cdr << ros_message.rear_custom_value;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hunter_msgs::msg::HunterLightCmd & ros_message)
{
  // Member: cmd_ctrl_allowed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.cmd_ctrl_allowed = tmp ? true : false;
  }

  // Member: front_mode
  cdr >> ros_message.front_mode;

  // Member: front_custom_value
  cdr >> ros_message.front_custom_value;

  // Member: rear_mode
  cdr >> ros_message.rear_mode;

  // Member: rear_custom_value
  cdr >> ros_message.rear_custom_value;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
get_serialized_size(
  const hunter_msgs::msg::HunterLightCmd & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: cmd_ctrl_allowed
  {
    size_t item_size = sizeof(ros_message.cmd_ctrl_allowed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: front_mode
  {
    size_t item_size = sizeof(ros_message.front_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: front_custom_value
  {
    size_t item_size = sizeof(ros_message.front_custom_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rear_mode
  {
    size_t item_size = sizeof(ros_message.rear_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rear_custom_value
  {
    size_t item_size = sizeof(ros_message.rear_custom_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
max_serialized_size_HunterLightCmd(
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


  // Member: cmd_ctrl_allowed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: front_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: front_custom_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rear_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rear_custom_value
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
    using DataType = hunter_msgs::msg::HunterLightCmd;
    is_plain =
      (
      offsetof(DataType, rear_custom_value) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _HunterLightCmd__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hunter_msgs::msg::HunterLightCmd *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HunterLightCmd__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hunter_msgs::msg::HunterLightCmd *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HunterLightCmd__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hunter_msgs::msg::HunterLightCmd *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HunterLightCmd__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HunterLightCmd(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HunterLightCmd__callbacks = {
  "hunter_msgs::msg",
  "HunterLightCmd",
  _HunterLightCmd__cdr_serialize,
  _HunterLightCmd__cdr_deserialize,
  _HunterLightCmd__get_serialized_size,
  _HunterLightCmd__max_serialized_size
};

static rosidl_message_type_support_t _HunterLightCmd__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HunterLightCmd__callbacks,
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
get_message_type_support_handle<hunter_msgs::msg::HunterLightCmd>()
{
  return &hunter_msgs::msg::typesupport_fastrtps_cpp::_HunterLightCmd__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hunter_msgs, msg, HunterLightCmd)() {
  return &hunter_msgs::msg::typesupport_fastrtps_cpp::_HunterLightCmd__handle;
}

#ifdef __cplusplus
}
#endif

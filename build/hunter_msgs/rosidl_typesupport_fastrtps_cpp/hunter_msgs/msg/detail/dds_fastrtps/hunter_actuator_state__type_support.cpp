// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hunter_msgs:msg/HunterActuatorState.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_actuator_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hunter_msgs/msg/detail/hunter_actuator_state__struct.hpp"

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
  const hunter_msgs::msg::HunterActuatorState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: motor_id
  cdr << ros_message.motor_id;
  // Member: rpm
  cdr << ros_message.rpm;
  // Member: current
  cdr << ros_message.current;
  // Member: pulse_count
  cdr << ros_message.pulse_count;
  // Member: driver_voltage
  cdr << ros_message.driver_voltage;
  // Member: driver_temperature
  cdr << ros_message.driver_temperature;
  // Member: motor_temperature
  cdr << ros_message.motor_temperature;
  // Member: driver_state
  cdr << ros_message.driver_state;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hunter_msgs::msg::HunterActuatorState & ros_message)
{
  // Member: motor_id
  cdr >> ros_message.motor_id;

  // Member: rpm
  cdr >> ros_message.rpm;

  // Member: current
  cdr >> ros_message.current;

  // Member: pulse_count
  cdr >> ros_message.pulse_count;

  // Member: driver_voltage
  cdr >> ros_message.driver_voltage;

  // Member: driver_temperature
  cdr >> ros_message.driver_temperature;

  // Member: motor_temperature
  cdr >> ros_message.motor_temperature;

  // Member: driver_state
  cdr >> ros_message.driver_state;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
get_serialized_size(
  const hunter_msgs::msg::HunterActuatorState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: motor_id
  {
    size_t item_size = sizeof(ros_message.motor_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rpm
  {
    size_t item_size = sizeof(ros_message.rpm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current
  {
    size_t item_size = sizeof(ros_message.current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pulse_count
  {
    size_t item_size = sizeof(ros_message.pulse_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: driver_voltage
  {
    size_t item_size = sizeof(ros_message.driver_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: driver_temperature
  {
    size_t item_size = sizeof(ros_message.driver_temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_temperature
  {
    size_t item_size = sizeof(ros_message.motor_temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: driver_state
  {
    size_t item_size = sizeof(ros_message.driver_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hunter_msgs
max_serialized_size_HunterActuatorState(
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


  // Member: motor_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rpm
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pulse_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: driver_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: driver_temperature
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: motor_temperature
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: driver_state
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
    using DataType = hunter_msgs::msg::HunterActuatorState;
    is_plain =
      (
      offsetof(DataType, driver_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _HunterActuatorState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hunter_msgs::msg::HunterActuatorState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HunterActuatorState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hunter_msgs::msg::HunterActuatorState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HunterActuatorState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hunter_msgs::msg::HunterActuatorState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HunterActuatorState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HunterActuatorState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HunterActuatorState__callbacks = {
  "hunter_msgs::msg",
  "HunterActuatorState",
  _HunterActuatorState__cdr_serialize,
  _HunterActuatorState__cdr_deserialize,
  _HunterActuatorState__get_serialized_size,
  _HunterActuatorState__max_serialized_size
};

static rosidl_message_type_support_t _HunterActuatorState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HunterActuatorState__callbacks,
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
get_message_type_support_handle<hunter_msgs::msg::HunterActuatorState>()
{
  return &hunter_msgs::msg::typesupport_fastrtps_cpp::_HunterActuatorState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hunter_msgs, msg, HunterActuatorState)() {
  return &hunter_msgs::msg::typesupport_fastrtps_cpp::_HunterActuatorState__handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/AidALM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/aid_alm__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/aid_alm__functions.h"
#include "ublox_msgs/msg/detail/aid_alm__struct.h"


// Include directives for member types
// Member `dwrd`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__AidALM__init(message_memory);
}

void ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_fini_function(void * message_memory)
{
  ublox_msgs__msg__AidALM__fini(message_memory);
}

size_t ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__size_function__AidALM__dwrd(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__get_const_function__AidALM__dwrd(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__get_function__AidALM__dwrd(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__fetch_function__AidALM__dwrd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__get_const_function__AidALM__dwrd(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__assign_function__AidALM__dwrd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__get_function__AidALM__dwrd(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__resize_function__AidALM__dwrd(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_member_array[3] = {
  {
    "svid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__AidALM, svid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "week",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__AidALM, week),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dwrd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__AidALM, dwrd),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__size_function__AidALM__dwrd,  // size() function pointer
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__get_const_function__AidALM__dwrd,  // get_const(index) function pointer
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__get_function__AidALM__dwrd,  // get(index) function pointer
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__fetch_function__AidALM__dwrd,  // fetch(index, &value) function pointer
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__assign_function__AidALM__dwrd,  // assign(index, value) function pointer
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__resize_function__AidALM__dwrd  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_members = {
  "ublox_msgs__msg",  // message namespace
  "AidALM",  // message name
  3,  // number of fields
  sizeof(ublox_msgs__msg__AidALM),
  ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_member_array,  // message members
  ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_type_support_handle = {
  0,
  &ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, AidALM)() {
  if (!ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__AidALM__rosidl_typesupport_introspection_c__AidALM_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

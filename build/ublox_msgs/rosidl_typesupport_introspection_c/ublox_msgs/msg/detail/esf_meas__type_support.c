// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/EsfMEAS.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/esf_meas__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/esf_meas__functions.h"
#include "ublox_msgs/msg/detail/esf_meas__struct.h"


// Include directives for member types
// Member `data`
// Member `calib_t_tag`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__EsfMEAS__init(message_memory);
}

void ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_fini_function(void * message_memory)
{
  ublox_msgs__msg__EsfMEAS__fini(message_memory);
}

size_t ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__size_function__EsfMEAS__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_const_function__EsfMEAS__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_function__EsfMEAS__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__fetch_function__EsfMEAS__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_const_function__EsfMEAS__data(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__assign_function__EsfMEAS__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_function__EsfMEAS__data(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__resize_function__EsfMEAS__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

size_t ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__size_function__EsfMEAS__calib_t_tag(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_const_function__EsfMEAS__calib_t_tag(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_function__EsfMEAS__calib_t_tag(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__fetch_function__EsfMEAS__calib_t_tag(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_const_function__EsfMEAS__calib_t_tag(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__assign_function__EsfMEAS__calib_t_tag(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_function__EsfMEAS__calib_t_tag(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__resize_function__EsfMEAS__calib_t_tag(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_member_array[5] = {
  {
    "time_tag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__EsfMEAS, time_tag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flags",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__EsfMEAS, flags),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__EsfMEAS, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__EsfMEAS, data),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__size_function__EsfMEAS__data,  // size() function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_const_function__EsfMEAS__data,  // get_const(index) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_function__EsfMEAS__data,  // get(index) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__fetch_function__EsfMEAS__data,  // fetch(index, &value) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__assign_function__EsfMEAS__data,  // assign(index, value) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__resize_function__EsfMEAS__data  // resize(index) function pointer
  },
  {
    "calib_t_tag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__EsfMEAS, calib_t_tag),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__size_function__EsfMEAS__calib_t_tag,  // size() function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_const_function__EsfMEAS__calib_t_tag,  // get_const(index) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__get_function__EsfMEAS__calib_t_tag,  // get(index) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__fetch_function__EsfMEAS__calib_t_tag,  // fetch(index, &value) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__assign_function__EsfMEAS__calib_t_tag,  // assign(index, value) function pointer
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__resize_function__EsfMEAS__calib_t_tag  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_members = {
  "ublox_msgs__msg",  // message namespace
  "EsfMEAS",  // message name
  5,  // number of fields
  sizeof(ublox_msgs__msg__EsfMEAS),
  ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_member_array,  // message members
  ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_type_support_handle = {
  0,
  &ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, EsfMEAS)() {
  if (!ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__EsfMEAS__rosidl_typesupport_introspection_c__EsfMEAS_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

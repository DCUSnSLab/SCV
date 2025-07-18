// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/NavSAT.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/nav_sat__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/nav_sat__functions.h"
#include "ublox_msgs/msg/detail/nav_sat__struct.h"


// Include directives for member types
// Member `sv`
#include "ublox_msgs/msg/nav_satsv.h"
// Member `sv`
#include "ublox_msgs/msg/detail/nav_satsv__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__NavSAT__init(message_memory);
}

void ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_fini_function(void * message_memory)
{
  ublox_msgs__msg__NavSAT__fini(message_memory);
}

size_t ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__size_function__NavSAT__reserved0(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_const_function__NavSAT__reserved0(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_function__NavSAT__reserved0(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__fetch_function__NavSAT__reserved0(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_const_function__NavSAT__reserved0(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__assign_function__NavSAT__reserved0(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_function__NavSAT__reserved0(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__size_function__NavSAT__sv(
  const void * untyped_member)
{
  const ublox_msgs__msg__NavSATSV__Sequence * member =
    (const ublox_msgs__msg__NavSATSV__Sequence *)(untyped_member);
  return member->size;
}

const void * ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_const_function__NavSAT__sv(
  const void * untyped_member, size_t index)
{
  const ublox_msgs__msg__NavSATSV__Sequence * member =
    (const ublox_msgs__msg__NavSATSV__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_function__NavSAT__sv(
  void * untyped_member, size_t index)
{
  ublox_msgs__msg__NavSATSV__Sequence * member =
    (ublox_msgs__msg__NavSATSV__Sequence *)(untyped_member);
  return &member->data[index];
}

void ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__fetch_function__NavSAT__sv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ublox_msgs__msg__NavSATSV * item =
    ((const ublox_msgs__msg__NavSATSV *)
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_const_function__NavSAT__sv(untyped_member, index));
  ublox_msgs__msg__NavSATSV * value =
    (ublox_msgs__msg__NavSATSV *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__assign_function__NavSAT__sv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ublox_msgs__msg__NavSATSV * item =
    ((ublox_msgs__msg__NavSATSV *)
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_function__NavSAT__sv(untyped_member, index));
  const ublox_msgs__msg__NavSATSV * value =
    (const ublox_msgs__msg__NavSATSV *)(untyped_value);
  *item = *value;
}

bool ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__resize_function__NavSAT__sv(
  void * untyped_member, size_t size)
{
  ublox_msgs__msg__NavSATSV__Sequence * member =
    (ublox_msgs__msg__NavSATSV__Sequence *)(untyped_member);
  ublox_msgs__msg__NavSATSV__Sequence__fini(member);
  return ublox_msgs__msg__NavSATSV__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_member_array[5] = {
  {
    "i_tow",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavSAT, i_tow),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavSAT, version),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_svs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavSAT, num_svs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reserved0",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavSAT, reserved0),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__size_function__NavSAT__reserved0,  // size() function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_const_function__NavSAT__reserved0,  // get_const(index) function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_function__NavSAT__reserved0,  // get(index) function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__fetch_function__NavSAT__reserved0,  // fetch(index, &value) function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__assign_function__NavSAT__reserved0,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sv",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavSAT, sv),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__size_function__NavSAT__sv,  // size() function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_const_function__NavSAT__sv,  // get_const(index) function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__get_function__NavSAT__sv,  // get(index) function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__fetch_function__NavSAT__sv,  // fetch(index, &value) function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__assign_function__NavSAT__sv,  // assign(index, value) function pointer
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__resize_function__NavSAT__sv  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_members = {
  "ublox_msgs__msg",  // message namespace
  "NavSAT",  // message name
  5,  // number of fields
  sizeof(ublox_msgs__msg__NavSAT),
  ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_member_array,  // message members
  ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_type_support_handle = {
  0,
  &ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, NavSAT)() {
  ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, NavSATSV)();
  if (!ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__NavSAT__rosidl_typesupport_introspection_c__NavSAT_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

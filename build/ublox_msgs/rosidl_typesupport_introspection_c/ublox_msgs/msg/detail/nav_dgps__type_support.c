// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/NavDGPS.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/nav_dgps__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/nav_dgps__functions.h"
#include "ublox_msgs/msg/detail/nav_dgps__struct.h"


// Include directives for member types
// Member `sv`
#include "ublox_msgs/msg/nav_dgpssv.h"
// Member `sv`
#include "ublox_msgs/msg/detail/nav_dgpssv__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__NavDGPS__init(message_memory);
}

void ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_fini_function(void * message_memory)
{
  ublox_msgs__msg__NavDGPS__fini(message_memory);
}

size_t ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__size_function__NavDGPS__sv(
  const void * untyped_member)
{
  const ublox_msgs__msg__NavDGPSSV__Sequence * member =
    (const ublox_msgs__msg__NavDGPSSV__Sequence *)(untyped_member);
  return member->size;
}

const void * ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__get_const_function__NavDGPS__sv(
  const void * untyped_member, size_t index)
{
  const ublox_msgs__msg__NavDGPSSV__Sequence * member =
    (const ublox_msgs__msg__NavDGPSSV__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__get_function__NavDGPS__sv(
  void * untyped_member, size_t index)
{
  ublox_msgs__msg__NavDGPSSV__Sequence * member =
    (ublox_msgs__msg__NavDGPSSV__Sequence *)(untyped_member);
  return &member->data[index];
}

void ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__fetch_function__NavDGPS__sv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ublox_msgs__msg__NavDGPSSV * item =
    ((const ublox_msgs__msg__NavDGPSSV *)
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__get_const_function__NavDGPS__sv(untyped_member, index));
  ublox_msgs__msg__NavDGPSSV * value =
    (ublox_msgs__msg__NavDGPSSV *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__assign_function__NavDGPS__sv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ublox_msgs__msg__NavDGPSSV * item =
    ((ublox_msgs__msg__NavDGPSSV *)
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__get_function__NavDGPS__sv(untyped_member, index));
  const ublox_msgs__msg__NavDGPSSV * value =
    (const ublox_msgs__msg__NavDGPSSV *)(untyped_value);
  *item = *value;
}

bool ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__resize_function__NavDGPS__sv(
  void * untyped_member, size_t size)
{
  ublox_msgs__msg__NavDGPSSV__Sequence * member =
    (ublox_msgs__msg__NavDGPSSV__Sequence *)(untyped_member);
  ublox_msgs__msg__NavDGPSSV__Sequence__fini(member);
  return ublox_msgs__msg__NavDGPSSV__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_member_array[8] = {
  {
    "i_tow",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavDGPS, i_tow),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "age",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavDGPS, age),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavDGPS, base_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_health",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavDGPS, base_health),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_ch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavDGPS, num_ch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavDGPS, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reserved1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavDGPS, reserved1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
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
    offsetof(ublox_msgs__msg__NavDGPS, sv),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__size_function__NavDGPS__sv,  // size() function pointer
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__get_const_function__NavDGPS__sv,  // get_const(index) function pointer
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__get_function__NavDGPS__sv,  // get(index) function pointer
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__fetch_function__NavDGPS__sv,  // fetch(index, &value) function pointer
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__assign_function__NavDGPS__sv,  // assign(index, value) function pointer
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__resize_function__NavDGPS__sv  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_members = {
  "ublox_msgs__msg",  // message namespace
  "NavDGPS",  // message name
  8,  // number of fields
  sizeof(ublox_msgs__msg__NavDGPS),
  ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_member_array,  // message members
  ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_type_support_handle = {
  0,
  &ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, NavDGPS)() {
  ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, NavDGPSSV)();
  if (!ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__NavDGPS__rosidl_typesupport_introspection_c__NavDGPS_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/RxmRTCM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/rxm_rtcm__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/rxm_rtcm__functions.h"
#include "ublox_msgs/msg/detail/rxm_rtcm__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__RxmRTCM__init(message_memory);
}

void ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_fini_function(void * message_memory)
{
  ublox_msgs__msg__RxmRTCM__fini(message_memory);
}

size_t ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__size_function__RxmRTCM__reserved0(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__get_const_function__RxmRTCM__reserved0(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__get_function__RxmRTCM__reserved0(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__fetch_function__RxmRTCM__reserved0(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__get_const_function__RxmRTCM__reserved0(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__assign_function__RxmRTCM__reserved0(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__get_function__RxmRTCM__reserved0(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_member_array[5] = {
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__RxmRTCM, version),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__RxmRTCM, flags),  // bytes offset in struct
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
    offsetof(ublox_msgs__msg__RxmRTCM, reserved0),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__size_function__RxmRTCM__reserved0,  // size() function pointer
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__get_const_function__RxmRTCM__reserved0,  // get_const(index) function pointer
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__get_function__RxmRTCM__reserved0,  // get(index) function pointer
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__fetch_function__RxmRTCM__reserved0,  // fetch(index, &value) function pointer
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__assign_function__RxmRTCM__reserved0,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ref_station",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__RxmRTCM, ref_station),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__RxmRTCM, msg_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_members = {
  "ublox_msgs__msg",  // message namespace
  "RxmRTCM",  // message name
  5,  // number of fields
  sizeof(ublox_msgs__msg__RxmRTCM),
  ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_member_array,  // message members
  ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_type_support_handle = {
  0,
  &ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, RxmRTCM)() {
  if (!ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__RxmRTCM__rosidl_typesupport_introspection_c__RxmRTCM_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

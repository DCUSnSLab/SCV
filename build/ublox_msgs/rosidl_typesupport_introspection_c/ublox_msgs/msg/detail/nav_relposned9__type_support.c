// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/NavRELPOSNED9.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/nav_relposned9__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/nav_relposned9__functions.h"
#include "ublox_msgs/msg/detail/nav_relposned9__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__NavRELPOSNED9__init(message_memory);
}

void ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_fini_function(void * message_memory)
{
  ublox_msgs__msg__NavRELPOSNED9__fini(message_memory);
}

size_t ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__size_function__NavRELPOSNED9__reserved2(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_const_function__NavRELPOSNED9__reserved2(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_function__NavRELPOSNED9__reserved2(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__fetch_function__NavRELPOSNED9__reserved2(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_const_function__NavRELPOSNED9__reserved2(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__assign_function__NavRELPOSNED9__reserved2(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_function__NavRELPOSNED9__reserved2(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__size_function__NavRELPOSNED9__reserved3(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_const_function__NavRELPOSNED9__reserved3(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_function__NavRELPOSNED9__reserved3(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__fetch_function__NavRELPOSNED9__reserved3(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_const_function__NavRELPOSNED9__reserved3(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__assign_function__NavRELPOSNED9__reserved3(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_function__NavRELPOSNED9__reserved3(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_member_array[21] = {
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, version),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, reserved1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ref_station_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, ref_station_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "i_tow",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, i_tow),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_n",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_n),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_e",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_e),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_heading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_heading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reserved2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, reserved2),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__size_function__NavRELPOSNED9__reserved2,  // size() function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_const_function__NavRELPOSNED9__reserved2,  // get_const(index) function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_function__NavRELPOSNED9__reserved2,  // get(index) function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__fetch_function__NavRELPOSNED9__reserved2,  // fetch(index, &value) function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__assign_function__NavRELPOSNED9__reserved2,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_hpn",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_hpn),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_hpe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_hpe),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_hpd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_hpd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rel_pos_hp_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, rel_pos_hp_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc_n",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, acc_n),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc_e",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, acc_e),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc_d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, acc_d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, acc_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc_heading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, acc_heading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reserved3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, reserved3),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__size_function__NavRELPOSNED9__reserved3,  // size() function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_const_function__NavRELPOSNED9__reserved3,  // get_const(index) function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__get_function__NavRELPOSNED9__reserved3,  // get(index) function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__fetch_function__NavRELPOSNED9__reserved3,  // fetch(index, &value) function pointer
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__assign_function__NavRELPOSNED9__reserved3,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flags",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavRELPOSNED9, flags),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_members = {
  "ublox_msgs__msg",  // message namespace
  "NavRELPOSNED9",  // message name
  21,  // number of fields
  sizeof(ublox_msgs__msg__NavRELPOSNED9),
  ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_member_array,  // message members
  ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_type_support_handle = {
  0,
  &ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, NavRELPOSNED9)() {
  if (!ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__NavRELPOSNED9__rosidl_typesupport_introspection_c__NavRELPOSNED9_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/CfgDAT.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/cfg_dat__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/cfg_dat__functions.h"
#include "ublox_msgs/msg/detail/cfg_dat__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__CfgDAT__init(message_memory);
}

void ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_fini_function(void * message_memory)
{
  ublox_msgs__msg__CfgDAT__fini(message_memory);
}

size_t ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__size_function__CfgDAT__datum_name(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__get_const_function__CfgDAT__datum_name(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__get_function__CfgDAT__datum_name(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__fetch_function__CfgDAT__datum_name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__get_const_function__CfgDAT__datum_name(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__assign_function__CfgDAT__datum_name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__get_function__CfgDAT__datum_name(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_member_array[11] = {
  {
    "datum_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, datum_num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "datum_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, datum_name),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__size_function__CfgDAT__datum_name,  // size() function pointer
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__get_const_function__CfgDAT__datum_name,  // get_const(index) function pointer
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__get_function__CfgDAT__datum_name,  // get(index) function pointer
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__fetch_function__CfgDAT__datum_name,  // fetch(index, &value) function pointer
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__assign_function__CfgDAT__datum_name,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "maj_a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, maj_a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, flat),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "d_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, d_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "d_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, d_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "d_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, d_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rot_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, rot_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rot_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, rot_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rot_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, rot_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scale",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgDAT, scale),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_members = {
  "ublox_msgs__msg",  // message namespace
  "CfgDAT",  // message name
  11,  // number of fields
  sizeof(ublox_msgs__msg__CfgDAT),
  ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_member_array,  // message members
  ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_type_support_handle = {
  0,
  &ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, CfgDAT)() {
  if (!ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__CfgDAT__rosidl_typesupport_introspection_c__CfgDAT_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

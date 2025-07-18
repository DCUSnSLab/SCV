// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/MonVER.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/mon_ver__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/mon_ver__functions.h"
#include "ublox_msgs/msg/detail/mon_ver__struct.h"


// Include directives for member types
// Member `extension`
#include "ublox_msgs/msg/mon_ver_extension.h"
// Member `extension`
#include "ublox_msgs/msg/detail/mon_ver_extension__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__MonVER__init(message_memory);
}

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_fini_function(void * message_memory)
{
  ublox_msgs__msg__MonVER__fini(message_memory);
}

size_t ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__size_function__MonVER__sw_version(
  const void * untyped_member)
{
  (void)untyped_member;
  return 30;
}

const void * ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__sw_version(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__sw_version(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__fetch_function__MonVER__sw_version(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__sw_version(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__assign_function__MonVER__sw_version(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__sw_version(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__size_function__MonVER__hw_version(
  const void * untyped_member)
{
  (void)untyped_member;
  return 10;
}

const void * ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__hw_version(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__hw_version(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__fetch_function__MonVER__hw_version(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__hw_version(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__assign_function__MonVER__hw_version(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__hw_version(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__size_function__MonVER__extension(
  const void * untyped_member)
{
  const ublox_msgs__msg__MonVERExtension__Sequence * member =
    (const ublox_msgs__msg__MonVERExtension__Sequence *)(untyped_member);
  return member->size;
}

const void * ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__extension(
  const void * untyped_member, size_t index)
{
  const ublox_msgs__msg__MonVERExtension__Sequence * member =
    (const ublox_msgs__msg__MonVERExtension__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__extension(
  void * untyped_member, size_t index)
{
  ublox_msgs__msg__MonVERExtension__Sequence * member =
    (ublox_msgs__msg__MonVERExtension__Sequence *)(untyped_member);
  return &member->data[index];
}

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__fetch_function__MonVER__extension(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ublox_msgs__msg__MonVERExtension * item =
    ((const ublox_msgs__msg__MonVERExtension *)
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__extension(untyped_member, index));
  ublox_msgs__msg__MonVERExtension * value =
    (ublox_msgs__msg__MonVERExtension *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__assign_function__MonVER__extension(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ublox_msgs__msg__MonVERExtension * item =
    ((ublox_msgs__msg__MonVERExtension *)
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__extension(untyped_member, index));
  const ublox_msgs__msg__MonVERExtension * value =
    (const ublox_msgs__msg__MonVERExtension *)(untyped_value);
  *item = *value;
}

bool ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__resize_function__MonVER__extension(
  void * untyped_member, size_t size)
{
  ublox_msgs__msg__MonVERExtension__Sequence * member =
    (ublox_msgs__msg__MonVERExtension__Sequence *)(untyped_member);
  ublox_msgs__msg__MonVERExtension__Sequence__fini(member);
  return ublox_msgs__msg__MonVERExtension__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_member_array[3] = {
  {
    "sw_version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    30,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonVER, sw_version),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__size_function__MonVER__sw_version,  // size() function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__sw_version,  // get_const(index) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__sw_version,  // get(index) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__fetch_function__MonVER__sw_version,  // fetch(index, &value) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__assign_function__MonVER__sw_version,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hw_version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    10,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonVER, hw_version),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__size_function__MonVER__hw_version,  // size() function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__hw_version,  // get_const(index) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__hw_version,  // get(index) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__fetch_function__MonVER__hw_version,  // fetch(index, &value) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__assign_function__MonVER__hw_version,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "extension",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonVER, extension),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__size_function__MonVER__extension,  // size() function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_const_function__MonVER__extension,  // get_const(index) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__get_function__MonVER__extension,  // get(index) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__fetch_function__MonVER__extension,  // fetch(index, &value) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__assign_function__MonVER__extension,  // assign(index, value) function pointer
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__resize_function__MonVER__extension  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_members = {
  "ublox_msgs__msg",  // message namespace
  "MonVER",  // message name
  3,  // number of fields
  sizeof(ublox_msgs__msg__MonVER),
  ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_member_array,  // message members
  ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_type_support_handle = {
  0,
  &ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, MonVER)() {
  ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, MonVERExtension)();
  if (!ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__MonVER__rosidl_typesupport_introspection_c__MonVER_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

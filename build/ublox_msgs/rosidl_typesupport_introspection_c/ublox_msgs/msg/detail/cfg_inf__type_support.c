// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/CfgINF.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/cfg_inf__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/cfg_inf__functions.h"
#include "ublox_msgs/msg/detail/cfg_inf__struct.h"


// Include directives for member types
// Member `blocks`
#include "ublox_msgs/msg/cfg_inf_block.h"
// Member `blocks`
#include "ublox_msgs/msg/detail/cfg_inf_block__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__CfgINF__init(message_memory);
}

void ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_fini_function(void * message_memory)
{
  ublox_msgs__msg__CfgINF__fini(message_memory);
}

size_t ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__size_function__CfgINF__blocks(
  const void * untyped_member)
{
  const ublox_msgs__msg__CfgINFBlock__Sequence * member =
    (const ublox_msgs__msg__CfgINFBlock__Sequence *)(untyped_member);
  return member->size;
}

const void * ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__get_const_function__CfgINF__blocks(
  const void * untyped_member, size_t index)
{
  const ublox_msgs__msg__CfgINFBlock__Sequence * member =
    (const ublox_msgs__msg__CfgINFBlock__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__get_function__CfgINF__blocks(
  void * untyped_member, size_t index)
{
  ublox_msgs__msg__CfgINFBlock__Sequence * member =
    (ublox_msgs__msg__CfgINFBlock__Sequence *)(untyped_member);
  return &member->data[index];
}

void ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__fetch_function__CfgINF__blocks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ublox_msgs__msg__CfgINFBlock * item =
    ((const ublox_msgs__msg__CfgINFBlock *)
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__get_const_function__CfgINF__blocks(untyped_member, index));
  ublox_msgs__msg__CfgINFBlock * value =
    (ublox_msgs__msg__CfgINFBlock *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__assign_function__CfgINF__blocks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ublox_msgs__msg__CfgINFBlock * item =
    ((ublox_msgs__msg__CfgINFBlock *)
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__get_function__CfgINF__blocks(untyped_member, index));
  const ublox_msgs__msg__CfgINFBlock * value =
    (const ublox_msgs__msg__CfgINFBlock *)(untyped_value);
  *item = *value;
}

bool ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__resize_function__CfgINF__blocks(
  void * untyped_member, size_t size)
{
  ublox_msgs__msg__CfgINFBlock__Sequence * member =
    (ublox_msgs__msg__CfgINFBlock__Sequence *)(untyped_member);
  ublox_msgs__msg__CfgINFBlock__Sequence__fini(member);
  return ublox_msgs__msg__CfgINFBlock__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_member_array[1] = {
  {
    "blocks",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__CfgINF, blocks),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__size_function__CfgINF__blocks,  // size() function pointer
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__get_const_function__CfgINF__blocks,  // get_const(index) function pointer
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__get_function__CfgINF__blocks,  // get(index) function pointer
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__fetch_function__CfgINF__blocks,  // fetch(index, &value) function pointer
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__assign_function__CfgINF__blocks,  // assign(index, value) function pointer
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__resize_function__CfgINF__blocks  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_members = {
  "ublox_msgs__msg",  // message namespace
  "CfgINF",  // message name
  1,  // number of fields
  sizeof(ublox_msgs__msg__CfgINF),
  ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_member_array,  // message members
  ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_type_support_handle = {
  0,
  &ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, CfgINF)() {
  ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, CfgINFBlock)();
  if (!ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__CfgINF__rosidl_typesupport_introspection_c__CfgINF_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

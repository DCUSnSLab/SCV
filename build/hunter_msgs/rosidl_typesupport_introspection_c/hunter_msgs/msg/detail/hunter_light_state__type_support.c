// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hunter_msgs:msg/HunterLightState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hunter_msgs/msg/detail/hunter_light_state__rosidl_typesupport_introspection_c.h"
#include "hunter_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hunter_msgs/msg/detail/hunter_light_state__functions.h"
#include "hunter_msgs/msg/detail/hunter_light_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hunter_msgs__msg__HunterLightState__init(message_memory);
}

void hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_fini_function(void * message_memory)
{
  hunter_msgs__msg__HunterLightState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_member_array[2] = {
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterLightState, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "custom_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterLightState, custom_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_members = {
  "hunter_msgs__msg",  // message namespace
  "HunterLightState",  // message name
  2,  // number of fields
  sizeof(hunter_msgs__msg__HunterLightState),
  hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_member_array,  // message members
  hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_init_function,  // function to initialize message memory (memory has to be allocated)
  hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_type_support_handle = {
  0,
  &hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hunter_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hunter_msgs, msg, HunterLightState)() {
  if (!hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_type_support_handle.typesupport_identifier) {
    hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hunter_msgs__msg__HunterLightState__rosidl_typesupport_introspection_c__HunterLightState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hunter_msgs:msg/HunterStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hunter_msgs/msg/detail/hunter_status__rosidl_typesupport_introspection_c.h"
#include "hunter_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hunter_msgs/msg/detail/hunter_status__functions.h"
#include "hunter_msgs/msg/detail/hunter_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `actuator_states`
#include "hunter_msgs/msg/hunter_actuator_state.h"
// Member `actuator_states`
#include "hunter_msgs/msg/detail/hunter_actuator_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hunter_msgs__msg__HunterStatus__init(message_memory);
}

void hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_fini_function(void * message_memory)
{
  hunter_msgs__msg__HunterStatus__fini(message_memory);
}

size_t hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__size_function__HunterStatus__actuator_states(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__get_const_function__HunterStatus__actuator_states(
  const void * untyped_member, size_t index)
{
  const hunter_msgs__msg__HunterActuatorState * member =
    (const hunter_msgs__msg__HunterActuatorState *)(untyped_member);
  return &member[index];
}

void * hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__get_function__HunterStatus__actuator_states(
  void * untyped_member, size_t index)
{
  hunter_msgs__msg__HunterActuatorState * member =
    (hunter_msgs__msg__HunterActuatorState *)(untyped_member);
  return &member[index];
}

void hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__fetch_function__HunterStatus__actuator_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hunter_msgs__msg__HunterActuatorState * item =
    ((const hunter_msgs__msg__HunterActuatorState *)
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__get_const_function__HunterStatus__actuator_states(untyped_member, index));
  hunter_msgs__msg__HunterActuatorState * value =
    (hunter_msgs__msg__HunterActuatorState *)(untyped_value);
  *value = *item;
}

void hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__assign_function__HunterStatus__actuator_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hunter_msgs__msg__HunterActuatorState * item =
    ((hunter_msgs__msg__HunterActuatorState *)
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__get_function__HunterStatus__actuator_states(untyped_member, index));
  const hunter_msgs__msg__HunterActuatorState * value =
    (const hunter_msgs__msg__HunterActuatorState *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, linear_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steering_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, steering_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vehicle_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, vehicle_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "control_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, control_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, error_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "battery_voltage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, battery_voltage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "actuator_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(hunter_msgs__msg__HunterStatus, actuator_states),  // bytes offset in struct
    NULL,  // default value
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__size_function__HunterStatus__actuator_states,  // size() function pointer
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__get_const_function__HunterStatus__actuator_states,  // get_const(index) function pointer
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__get_function__HunterStatus__actuator_states,  // get(index) function pointer
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__fetch_function__HunterStatus__actuator_states,  // fetch(index, &value) function pointer
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__assign_function__HunterStatus__actuator_states,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_members = {
  "hunter_msgs__msg",  // message namespace
  "HunterStatus",  // message name
  8,  // number of fields
  sizeof(hunter_msgs__msg__HunterStatus),
  hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_member_array,  // message members
  hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_type_support_handle = {
  0,
  &hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hunter_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hunter_msgs, msg, HunterStatus)() {
  hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hunter_msgs, msg, HunterActuatorState)();
  if (!hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_type_support_handle.typesupport_identifier) {
    hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hunter_msgs__msg__HunterStatus__rosidl_typesupport_introspection_c__HunterStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

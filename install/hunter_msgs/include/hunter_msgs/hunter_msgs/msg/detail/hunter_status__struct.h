// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hunter_msgs:msg/HunterStatus.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__STRUCT_H_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MOTOR_ID_FRONT_RIGHT'.
enum
{
  hunter_msgs__msg__HunterStatus__MOTOR_ID_FRONT_RIGHT = 0
};

/// Constant 'MOTOR_ID_FRONT_LEFT'.
enum
{
  hunter_msgs__msg__HunterStatus__MOTOR_ID_FRONT_LEFT = 1
};

/// Constant 'MOTOR_ID_REAR_RIGHT'.
enum
{
  hunter_msgs__msg__HunterStatus__MOTOR_ID_REAR_RIGHT = 2
};

/// Constant 'MOTOR_ID_REAR_LEFT'.
enum
{
  hunter_msgs__msg__HunterStatus__MOTOR_ID_REAR_LEFT = 3
};

/// Constant 'LIGHT_ID_FRONT'.
enum
{
  hunter_msgs__msg__HunterStatus__LIGHT_ID_FRONT = 0
};

/// Constant 'LIGHT_ID_REAR'.
enum
{
  hunter_msgs__msg__HunterStatus__LIGHT_ID_REAR = 1
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'actuator_states'
#include "hunter_msgs/msg/detail/hunter_actuator_state__struct.h"

/// Struct defined in msg/HunterStatus in the package hunter_msgs.
typedef struct hunter_msgs__msg__HunterStatus
{
  std_msgs__msg__Header header;
  /// motion state
  double linear_velocity;
  double steering_angle;
  /// base state
  uint8_t vehicle_state;
  uint8_t control_mode;
  uint16_t error_code;
  double battery_voltage;
  /// motor state
  hunter_msgs__msg__HunterActuatorState actuator_states[3];
} hunter_msgs__msg__HunterStatus;

// Struct for a sequence of hunter_msgs__msg__HunterStatus.
typedef struct hunter_msgs__msg__HunterStatus__Sequence
{
  hunter_msgs__msg__HunterStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hunter_msgs__msg__HunterStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hunter_msgs:msg/HunterLightCmd.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_CMD__STRUCT_H_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'LIGHT_CONST_OFF'.
enum
{
  hunter_msgs__msg__HunterLightCmd__LIGHT_CONST_OFF = 0
};

/// Constant 'LIGHT_CONST_ON'.
enum
{
  hunter_msgs__msg__HunterLightCmd__LIGHT_CONST_ON = 1
};

/// Constant 'LIGHT_BREATH'.
enum
{
  hunter_msgs__msg__HunterLightCmd__LIGHT_BREATH = 2
};

/// Constant 'LIGHT_CUSTOM'.
enum
{
  hunter_msgs__msg__HunterLightCmd__LIGHT_CUSTOM = 3
};

/// Struct defined in msg/HunterLightCmd in the package hunter_msgs.
typedef struct hunter_msgs__msg__HunterLightCmd
{
  bool cmd_ctrl_allowed;
  uint8_t front_mode;
  uint8_t front_custom_value;
  uint8_t rear_mode;
  uint8_t rear_custom_value;
} hunter_msgs__msg__HunterLightCmd;

// Struct for a sequence of hunter_msgs__msg__HunterLightCmd.
typedef struct hunter_msgs__msg__HunterLightCmd__Sequence
{
  hunter_msgs__msg__HunterLightCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hunter_msgs__msg__HunterLightCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_CMD__STRUCT_H_

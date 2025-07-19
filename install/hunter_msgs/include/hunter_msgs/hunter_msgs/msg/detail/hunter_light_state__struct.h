// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hunter_msgs:msg/HunterLightState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__STRUCT_H_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/HunterLightState in the package hunter_msgs.
typedef struct hunter_msgs__msg__HunterLightState
{
  uint8_t mode;
  uint8_t custom_value;
} hunter_msgs__msg__HunterLightState;

// Struct for a sequence of hunter_msgs__msg__HunterLightState.
typedef struct hunter_msgs__msg__HunterLightState__Sequence
{
  hunter_msgs__msg__HunterLightState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hunter_msgs__msg__HunterLightState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__STRUCT_H_

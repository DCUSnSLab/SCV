// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hunter_msgs:msg/HunterRCState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_RC_STATE__STRUCT_H_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_RC_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/HunterRCState in the package hunter_msgs.
typedef struct hunter_msgs__msg__HunterRCState
{
  uint8_t swa;
  uint8_t swb;
  uint8_t swc;
  uint8_t swd;
  int8_t stick_right_v;
  int8_t stick_right_h;
  int8_t stick_left_v;
  int8_t stick_left_h;
  int8_t var_a;
} hunter_msgs__msg__HunterRCState;

// Struct for a sequence of hunter_msgs__msg__HunterRCState.
typedef struct hunter_msgs__msg__HunterRCState__Sequence
{
  hunter_msgs__msg__HunterRCState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hunter_msgs__msg__HunterRCState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_RC_STATE__STRUCT_H_

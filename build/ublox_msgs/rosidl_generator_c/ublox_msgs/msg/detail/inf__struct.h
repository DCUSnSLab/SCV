// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/Inf.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__INF__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__INF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'CLASS_ID'.
enum
{
  ublox_msgs__msg__Inf__CLASS_ID = 4
};

// Include directives for member types
// Member 'str'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Inf in the package ublox_msgs.
/**
  * UBX-INF (0x04, 0x00...0x04)
  * ASCII output
  *
  * This message has a variable length payload, representing an ASCII string.
 */
typedef struct ublox_msgs__msg__Inf
{
  rosidl_runtime_c__uint8__Sequence str;
} ublox_msgs__msg__Inf;

// Struct for a sequence of ublox_msgs__msg__Inf.
typedef struct ublox_msgs__msg__Inf__Sequence
{
  ublox_msgs__msg__Inf * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__Inf__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__INF__STRUCT_H_

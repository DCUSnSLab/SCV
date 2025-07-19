// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/MonVERExtension.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MonVERExtension in the package ublox_msgs.
/**
  * see MonVER message
 */
typedef struct ublox_msgs__msg__MonVERExtension
{
  uint8_t field[30];
} ublox_msgs__msg__MonVERExtension;

// Struct for a sequence of ublox_msgs__msg__MonVERExtension.
typedef struct ublox_msgs__msg__MonVERExtension__Sequence
{
  ublox_msgs__msg__MonVERExtension * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__MonVERExtension__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__STRUCT_H_

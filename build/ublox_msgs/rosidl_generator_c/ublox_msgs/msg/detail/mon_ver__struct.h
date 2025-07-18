// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/MonVER.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_VER__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__MON_VER__STRUCT_H_

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
  ublox_msgs__msg__MonVER__CLASS_ID = 10
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__MonVER__MESSAGE_ID = 4
};

// Include directives for member types
// Member 'extension'
#include "ublox_msgs/msg/detail/mon_ver_extension__struct.h"

/// Struct defined in msg/MonVER in the package ublox_msgs.
/**
  * MON-VER (0x0A 0x04)
  *
  * Receiver/Software Version
  * Returned when the version is polled.
 */
typedef struct ublox_msgs__msg__MonVER
{
  /// Zero-terminated software version string.
  uint8_t sw_version[30];
  /// Zero-terminated hardware version string.
  uint8_t hw_version[10];
  /// Start of repeated block (N times)
  ublox_msgs__msg__MonVERExtension__Sequence extension;
} ublox_msgs__msg__MonVER;

// Struct for a sequence of ublox_msgs__msg__MonVER.
typedef struct ublox_msgs__msg__MonVER__Sequence
{
  ublox_msgs__msg__MonVER * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__MonVER__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_VER__STRUCT_H_

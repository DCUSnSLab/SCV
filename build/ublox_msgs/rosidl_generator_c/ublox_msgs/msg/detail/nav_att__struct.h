// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavATT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_ATT__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_ATT__STRUCT_H_

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
  ublox_msgs__msg__NavATT__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavATT__MESSAGE_ID = 5
};

/// Struct defined in msg/NavATT in the package ublox_msgs.
/**
  * NAV-ATT (0x01 0x05)
  * Attitude Solution
  *
  * This message outputs the attitude solution as roll, pitch and heading angles.
  * Supported on ADR and UDR products.
 */
typedef struct ublox_msgs__msg__NavATT
{
  /// GPS time of week of the navigation epoch
  uint32_t i_tow;
  /// Message version (0 for this version)
  uint8_t version;
  /// Reserved
  uint8_t reserved0[3];
  /// Vehicle roll.
  int32_t roll;
  /// Vehicle pitch.
  int32_t pitch;
  /// Vehicle heading.
  int32_t heading;
  /// Vehicle roll accuracy (if null, roll angle is not
  /// available).
  uint32_t acc_roll;
  /// Vehicle pitch accuracy (if null, pitch angle is not
  /// available).
  uint32_t acc_pitch;
  /// Vehicle heading accuracy
  uint32_t acc_heading;
} ublox_msgs__msg__NavATT;

// Struct for a sequence of ublox_msgs__msg__NavATT.
typedef struct ublox_msgs__msg__NavATT__Sequence
{
  ublox_msgs__msg__NavATT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavATT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_ATT__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__STRUCT_H_

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
  ublox_msgs__msg__NavPOSECEF__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavPOSECEF__MESSAGE_ID = 1
};

/// Struct defined in msg/NavPOSECEF in the package ublox_msgs.
/**
  * NAV-POSECEF (0x01 0x01)
  * Position Solution in ECEF
  *
  * See important comments concerning validity of position given in section
  * Navigation Output Filters.
 */
typedef struct ublox_msgs__msg__NavPOSECEF
{
  /// GPS Millisecond Time of Week
  uint32_t i_tow;
  /// ECEF X coordinate
  int32_t ecef_x;
  /// ECEF Y coordinate
  int32_t ecef_y;
  /// ECEF Z coordinate
  int32_t ecef_z;
  /// Position Accuracy Estimate
  uint32_t p_acc;
} ublox_msgs__msg__NavPOSECEF;

// Struct for a sequence of ublox_msgs__msg__NavPOSECEF.
typedef struct ublox_msgs__msg__NavPOSECEF__Sequence
{
  ublox_msgs__msg__NavPOSECEF * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavPOSECEF__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__STRUCT_H_

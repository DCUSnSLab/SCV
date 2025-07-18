// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavVELECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__STRUCT_H_

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
  ublox_msgs__msg__NavVELECEF__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavVELECEF__MESSAGE_ID = 17
};

/// Struct defined in msg/NavVELECEF in the package ublox_msgs.
/**
  * NAV-VELECEF (0x01 0x11)
  * Velocity Solution in ECEF
  *
  * See important comments concerning validity of velocity given in section
  * Navigation Output Filters.
 */
typedef struct ublox_msgs__msg__NavVELECEF
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// ECEF X velocity
  int32_t ecef_vx;
  /// ECEF Y velocity
  int32_t ecef_vy;
  /// ECEF Z velocity
  int32_t ecef_vz;
  /// Speed Accuracy Estimate
  uint32_t s_acc;
} ublox_msgs__msg__NavVELECEF;

// Struct for a sequence of ublox_msgs__msg__NavVELECEF.
typedef struct ublox_msgs__msg__NavVELECEF__Sequence
{
  ublox_msgs__msg__NavVELECEF * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavVELECEF__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__STRUCT_H_

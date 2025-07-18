// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavDGPS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__STRUCT_H_

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
  ublox_msgs__msg__NavDGPS__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavDGPS__MESSAGE_ID = 49
};

/// Constant 'DGPS_CORRECTION_NONE'.
enum
{
  ublox_msgs__msg__NavDGPS__DGPS_CORRECTION_NONE = 0
};

/// Constant 'DGPS_CORRECTION_PR_PRR'.
enum
{
  ublox_msgs__msg__NavDGPS__DGPS_CORRECTION_PR_PRR = 1
};

// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_dgpssv__struct.h"

/// Struct defined in msg/NavDGPS in the package ublox_msgs.
/**
  * NAV-DGPS (0x01 0x31)
  * DGPS Data Used for NAV
  *
  * This message outputs the Correction data as it has been applied to the current
  * NAV Solution. See also the notes on the RTCM protocol.
 */
typedef struct ublox_msgs__msg__NavDGPS
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// Age of newest correction data
  int32_t age;
  /// DGPS Base Station ID
  int16_t base_id;
  /// DGPS Base Station Health Status
  int16_t base_health;
  /// Number of channels for which correction data is
  /// following
  int8_t num_ch;
  /// DGPS Correction Type Status
  uint8_t status;
  /// Reserved
  uint16_t reserved1;
  ublox_msgs__msg__NavDGPSSV__Sequence sv;
} ublox_msgs__msg__NavDGPS;

// Struct for a sequence of ublox_msgs__msg__NavDGPS.
typedef struct ublox_msgs__msg__NavDGPS__Sequence
{
  ublox_msgs__msg__NavDGPS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavDGPS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__STRUCT_H_

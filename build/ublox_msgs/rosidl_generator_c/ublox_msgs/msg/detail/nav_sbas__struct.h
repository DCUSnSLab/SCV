// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__STRUCT_H_

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
  ublox_msgs__msg__NavSBAS__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavSBAS__MESSAGE_ID = 50
};

/// Constant 'MODE_DISABLED'.
enum
{
  ublox_msgs__msg__NavSBAS__MODE_DISABLED = 0
};

/// Constant 'MODE_ENABLED_INTEGRITY'.
enum
{
  ublox_msgs__msg__NavSBAS__MODE_ENABLED_INTEGRITY = 1
};

/// Constant 'MODE_ENABLED_TESTMODE'.
enum
{
  ublox_msgs__msg__NavSBAS__MODE_ENABLED_TESTMODE = 3
};

/// Constant 'SYS_UNKNOWN'.
enum
{
  ublox_msgs__msg__NavSBAS__SYS_UNKNOWN = -1
};

/// Constant 'SYS_WAAS'.
enum
{
  ublox_msgs__msg__NavSBAS__SYS_WAAS = 0
};

/// Constant 'SYS_EGNOS'.
enum
{
  ublox_msgs__msg__NavSBAS__SYS_EGNOS = 1
};

/// Constant 'SYS_MSAS'.
enum
{
  ublox_msgs__msg__NavSBAS__SYS_MSAS = 2
};

/// Constant 'SYS_GAGAN'.
enum
{
  ublox_msgs__msg__NavSBAS__SYS_GAGAN = 3
};

/// Constant 'SYS_GPS'.
enum
{
  ublox_msgs__msg__NavSBAS__SYS_GPS = 16
};

/// Constant 'SERVICE_RANGING'.
enum
{
  ublox_msgs__msg__NavSBAS__SERVICE_RANGING = 1
};

/// Constant 'SERVICE_CORRECTIONS'.
enum
{
  ublox_msgs__msg__NavSBAS__SERVICE_CORRECTIONS = 2
};

/// Constant 'SERVICE_INTEGRITY'.
enum
{
  ublox_msgs__msg__NavSBAS__SERVICE_INTEGRITY = 4
};

/// Constant 'SERVICE_TESTMODE'.
enum
{
  ublox_msgs__msg__NavSBAS__SERVICE_TESTMODE = 8
};

// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_sbassv__struct.h"

/// Struct defined in msg/NavSBAS in the package ublox_msgs.
/**
  * NAV-SBAS (0x01 0x32)
  * SBAS Status Data
  *
  * This message outputs the status of the SBAS sub system
 */
typedef struct ublox_msgs__msg__NavSBAS
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// PRN Number of the GEO where correction and integrity
  /// data is used from
  uint8_t geo;
  /// SBAS Mode
  uint8_t mode;
  /// SBAS System (WAAS/EGNOS/...)
  int8_t sys;
  /// SBAS Services available
  uint8_t service;
  /// Number of SV data following
  uint8_t cnt;
  /// Reserved
  uint8_t reserved0[3];
  ublox_msgs__msg__NavSBASSV__Sequence sv;
} ublox_msgs__msg__NavSBAS;

// Struct for a sequence of ublox_msgs__msg__NavSBAS.
typedef struct ublox_msgs__msg__NavSBAS__Sequence
{
  ublox_msgs__msg__NavSBAS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavSBAS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__STRUCT_H_

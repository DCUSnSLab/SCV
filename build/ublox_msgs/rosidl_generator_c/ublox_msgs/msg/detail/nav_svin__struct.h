// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavSVIN.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__STRUCT_H_

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
  ublox_msgs__msg__NavSVIN__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavSVIN__MESSAGE_ID = 59
};

/// Struct defined in msg/NavSVIN in the package ublox_msgs.
/**
  * NAV-SVIN (0x01 0x3B)
  * Survey-in data
  *
  * This message contains information about survey-in parameters.
  * Supported on:
  *  - u-blox 8 / u-blox M8 with protocol version 20 (only with High Precision
  *    GNSS products)
 */
typedef struct ublox_msgs__msg__NavSVIN
{
  /// Message version (0x00 for this version)
  uint8_t version;
  /// Reserved
  uint8_t reserved0[3];
  /// GPS time of week of the navigation epoch
  uint32_t i_tow;
  /// Passed survey-in observation time
  uint32_t dur;
  /// Current survey-in mean position ECEF X coordinate
  int32_t mean_x;
  /// Current survey-in mean position ECEF Y coordinate
  int32_t mean_y;
  /// Current survey-in mean position ECEF Z coordinate
  int32_t mean_z;
  /// Current high-precision survey-in mean position
  /// ECEF X coordinate. 0.1_mm
  /// Must be in the range -99..+99.
  /// The current survey-in mean position ECEF X
  /// coordinate, in units of cm, is given by
  /// meanX + (0.01 * meanXHP)
  int8_t mean_xhp;
  /// Current high-precision survey-in mean position
  /// ECEF Y coordinate.
  /// Must be in the range -99..+99.
  /// The current survey-in mean position ECEF Y
  /// coordinate, in units of cm, is given by
  /// meanY + (0.01 * meanYHP)
  int8_t mean_yhp;
  /// Current high-precision survey-in mean position
  /// ECEF Z coordinate.
  /// Must be in the range -99..+99.
  /// The current survey-in mean position ECEF Z
  /// coordinate, in units of cm, is given by
  /// meanZ + (0.01 * meanZHP)
  int8_t mean_zhp;
  /// Reserved
  uint8_t reserved1;
  /// Current survey-in mean position accuracy
  uint32_t mean_acc;
  /// Number of position observations used during survey-in
  uint32_t obs;
  /// Survey-in position validity flag, 1 = valid
  /// otherwise 0
  uint8_t valid;
  /// Survey-in in progress flag, 1 = in-progress
  /// otherwise 0
  uint8_t active;
  /// Reserved
  uint8_t reserved3[2];
} ublox_msgs__msg__NavSVIN;

// Struct for a sequence of ublox_msgs__msg__NavSVIN.
typedef struct ublox_msgs__msg__NavSVIN__Sequence
{
  ublox_msgs__msg__NavSVIN * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavSVIN__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__STRUCT_H_

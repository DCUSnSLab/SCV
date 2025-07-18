// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgDGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__STRUCT_H_

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
  ublox_msgs__msg__CfgDGNSS__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgDGNSS__MESSAGE_ID = 112
};

/// Constant 'DGNSS_MODE_RTK_FLOAT'.
/**
  * RTK float: No attempts are made to fix
  * ambiguities.
 */
enum
{
  ublox_msgs__msg__CfgDGNSS__DGNSS_MODE_RTK_FLOAT = 2
};

/// Constant 'DGNSS_MODE_RTK_FIXED'.
/**
  * RTK fixed: Ambiguities are fixed whenever
  * possible.
 */
enum
{
  ublox_msgs__msg__CfgDGNSS__DGNSS_MODE_RTK_FIXED = 3
};

/// Struct defined in msg/CfgDGNSS in the package ublox_msgs.
/**
  * CFG-DGNSS (0x06 0x70)
  * DGNSS configuration
  *
  * This message allows the user to configure the DGNSS configuration of the
  * receiver.
  * Supported on:
  *  - u-blox 8 / u-blox M8 from protocol version 20.01 up to version 23.01 (only
  *    with High Precision GNSS products)
 */
typedef struct ublox_msgs__msg__CfgDGNSS
{
  /// Specifies differential mode:
  uint8_t dgnss_mode;
  /// Reserved
  uint8_t reserved0[3];
} ublox_msgs__msg__CfgDGNSS;

// Struct for a sequence of ublox_msgs__msg__CfgDGNSS.
typedef struct ublox_msgs__msg__CfgDGNSS__Sequence
{
  ublox_msgs__msg__CfgDGNSS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgDGNSS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_DGNSS__STRUCT_H_

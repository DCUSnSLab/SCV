// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgNMEA6.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__STRUCT_H_

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
  ublox_msgs__msg__CfgNMEA6__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgNMEA6__MESSAGE_ID = 23
};

/// Constant 'FILTER_POS'.
/**
  * Disable position filtering
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FILTER_POS = 1
};

/// Constant 'FILTER_MSK_POS'.
/**
  * Disable masked position filtering
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FILTER_MSK_POS = 2
};

/// Constant 'FILTER_TIME'.
/**
  * Disable time filtering
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FILTER_TIME = 4
};

/// Constant 'FILTER_DATE'.
/**
  * Disable date filtering
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FILTER_DATE = 8
};

/// Constant 'FILTER_SBAS_FILT'.
/**
  * Enable SBAS filtering
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FILTER_SBAS_FILT = 16
};

/// Constant 'FILTER_TRACK'.
/**
  * Disable track filtering
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FILTER_TRACK = 32
};

/// Constant 'NMEA_VERSION_2_3'.
/**
  * Version 2.3
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__NMEA_VERSION_2_3 = 35
};

/// Constant 'NMEA_VERSION_2_1'.
/**
  * Version 2.1
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__NMEA_VERSION_2_1 = 33
};

/// Constant 'FLAGS_COMPAT'.
/**
  * enable compatibility mode.
  * This might be needed for certain applications
  * when customer's NMEA parser expects a fixed
  * number of  digits in position coordinates
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FLAGS_COMPAT = 1
};

/// Constant 'FLAGS_CONSIDER'.
/**
  * enable considering mode
 */
enum
{
  ublox_msgs__msg__CfgNMEA6__FLAGS_CONSIDER = 2
};

/// Struct defined in msg/CfgNMEA6 in the package ublox_msgs.
/**
  * CFG-NMEA (0x06 0x17)
  * NMEA protocol configuration
  *
  * Set/Get the NMEA protocol configuration. See section NMEA Protocol
  * Configuration for a detailed description of the configuration effects on
  * NMEA output
  *
  * Supported on u-blox 6 from firmware version 6.00 up to version 7.03.
 */
typedef struct ublox_msgs__msg__CfgNMEA6
{
  /// filter flags
  uint8_t filter;
  /// NMEA version
  uint8_t version;
  /// Maximum Number of SVs to report in NMEA
  /// protocol.
  /// This does not affect the receiver's operation.
  /// It only limits the number of SVs reported in
  /// NMEA mode (this might be needed with older
  /// mapping applications which only support 8- or
  /// 12-channel receivers)
  uint8_t num_sv;
  /// flags
  uint8_t flags;
} ublox_msgs__msg__CfgNMEA6;

// Struct for a sequence of ublox_msgs__msg__CfgNMEA6.
typedef struct ublox_msgs__msg__CfgNMEA6__Sequence
{
  ublox_msgs__msg__CfgNMEA6 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgNMEA6__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__STRUCT_H_

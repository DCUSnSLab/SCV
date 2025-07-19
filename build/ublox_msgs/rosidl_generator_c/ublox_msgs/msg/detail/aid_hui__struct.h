// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/AidHUI.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_HUI__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__AID_HUI__STRUCT_H_

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
  ublox_msgs__msg__AidHUI__CLASS_ID = 11
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__AidHUI__MESSAGE_ID = 2
};

/// Constant 'FLAGS_HEALTH'.
/**
  * Healthmask field in this message is valid
 */
enum
{
  ublox_msgs__msg__AidHUI__FLAGS_HEALTH = 1ul
};

/// Constant 'FLAGS_UTC'.
/**
  * UTC parameter fields in this message are valid
 */
enum
{
  ublox_msgs__msg__AidHUI__FLAGS_UTC = 2ul
};

/// Constant 'FLAGS_KLOB'.
/**
  * Klobuchar parameter fields in this message are
  * valid
 */
enum
{
  ublox_msgs__msg__AidHUI__FLAGS_KLOB = 4ul
};

/// Struct defined in msg/AidHUI in the package ublox_msgs.
/**
  * AID-HUI (0x0B 0x02)
  * GPS Health, UTC and ionosphere parameters
  *
  * All UBX-AID messages are deprecated; use UBX-MGA messages instead.
  * This message contains a health bit mask, UTC time and Klobuchar parameters. For more
  * information on these parameters, please see the ICD-GPS-200 documentation.
 */
typedef struct ublox_msgs__msg__AidHUI
{
  /// Bitmask, every bit represents a GPS SV (1-32).
  /// If the bit is set the SV is healthy.
  uint32_t health;
  /// UTC - parameter A0
  double utc_a0;
  /// UTC - parameter A1
  double utc_a1;
  /// UTC - reference time of week
  int32_t utc_tow;
  /// UTC - reference week number
  int16_t utc_wnt;
  /// UTC - time difference due to leap seconds before event
  int16_t utc_ls;
  /// UTC - week number when next leap second event occurs
  int16_t utc_wnf;
  /// UTC - day of week when next leap second event occurs
  int16_t utc_dn;
  /// UTC - time difference due to leap seconds after event
  int16_t utc_lsf;
  /// UTC - Spare to ensure structure is a multiple of 4
  /// bytes
  int16_t utc_spare;
  /// Klobuchar - alpha 0
  float klob_a0;
  /// Klobuchar - alpha 1
  float klob_a1;
  /// Klobuchar - alpha 2
  float klob_a2;
  /// Klobuchar - alpha 3
  float klob_a3;
  /// Klobuchar - beta 0
  float klob_b0;
  /// Klobuchar - beta 1
  float klob_b1;
  /// Klobuchar - beta 2
  float klob_b2;
  /// Klobuchar - beta 3
  float klob_b3;
  /// flags
  uint32_t flags;
} ublox_msgs__msg__AidHUI;

// Struct for a sequence of ublox_msgs__msg__AidHUI.
typedef struct ublox_msgs__msg__AidHUI__Sequence
{
  ublox_msgs__msg__AidHUI * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__AidHUI__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_HUI__STRUCT_H_

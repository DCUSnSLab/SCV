// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavTIMEUTC.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__STRUCT_H_

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
  ublox_msgs__msg__NavTIMEUTC__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavTIMEUTC__MESSAGE_ID = 33
};

/// Constant 'VALID_TOW'.
/**
  * Valid Time of Week
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__VALID_TOW = 1
};

/// Constant 'VALID_WKN'.
/**
  * Valid Week Number
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__VALID_WKN = 2
};

/// Constant 'VALID_UTC'.
/**
  * Valid Leap Seconds, i.e. Leap Seconds already known
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__VALID_UTC = 4
};

/// Constant 'VALID_UTC_STANDARD_MASK'.
/**
  * UTC standard Identifier Bit mask:
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__VALID_UTC_STANDARD_MASK = 240
};

/// Constant 'UTC_STANDARD_NOT_AVAILABLE'.
/**
  * Information not available
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_NOT_AVAILABLE = 0
};

/// Constant 'UTC_STANDARD_CRL'.
/**
  * Communications Research Labratory
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_CRL = 16
};

/// Constant 'UTC_STANDARD_NIST'.
/**
  * National Institute of Standards and
  * Technology (NIST)
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_NIST = 32
};

/// Constant 'UTC_STANDARD_USNO'.
/**
  * U.S. Naval Observatory (USNO)
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_USNO = 48
};

/// Constant 'UTC_STANDARD_BIPM'.
/**
  * International Bureau of Weights and
  * Measures (BIPM)
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_BIPM = 64
};

/// Constant 'UTC_STANDARD_EL'.
/**
  * European Laboratory (tbd)
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_EL = 80
};

/// Constant 'UTC_STANDARD_SU'.
/**
  * Former Soviet Union (SU)
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_SU = 96
};

/// Constant 'UTC_STANDARD_NTSC'.
/**
  * National Time Service Center, China
 */
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_NTSC = 112
};

/// Constant 'UTC_STANDARD_UNKNOWN'.
enum
{
  ublox_msgs__msg__NavTIMEUTC__UTC_STANDARD_UNKNOWN = 240
};

/// Struct defined in msg/NavTIMEUTC in the package ublox_msgs.
/**
  * NAV-TIMEUTC (0x01 0x21)
  * UTC Time Solution
 */
typedef struct ublox_msgs__msg__NavTIMEUTC
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// Time Accuracy Estimate
  uint32_t t_acc;
  /// Fraction of second, range -1e9 .. 1e9 (UTC)
  int32_t nano;
  /// Year, range 1999..2099 (UTC)
  uint16_t year;
  /// Month, range 1..12 (UTC)
  uint8_t month;
  /// Day of Month, range 1..31 (UTC)
  uint8_t day;
  /// Hour of Day, range 0..23 (UTC)
  uint8_t hour;
  /// Minute of Hour, range 0..59 (UTC)
  uint8_t min;
  /// Seconds of Minute, range 0..60 (UTC) (60 for
  /// leap second)
  uint8_t sec;
  /// Validity Flags
  uint8_t valid;
} ublox_msgs__msg__NavTIMEUTC;

// Struct for a sequence of ublox_msgs__msg__NavTIMEUTC.
typedef struct ublox_msgs__msg__NavTIMEUTC__Sequence
{
  ublox_msgs__msg__NavTIMEUTC * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavTIMEUTC__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__STRUCT_H_

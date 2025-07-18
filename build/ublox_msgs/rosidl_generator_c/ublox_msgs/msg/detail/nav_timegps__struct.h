// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavTIMEGPS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__STRUCT_H_

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
  ublox_msgs__msg__NavTIMEGPS__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavTIMEGPS__MESSAGE_ID = 32
};

/// Constant 'VALID_TOW'.
/**
  * Valid Time of Week
 */
enum
{
  ublox_msgs__msg__NavTIMEGPS__VALID_TOW = 1
};

/// Constant 'VALID_WEEK'.
/**
  * Valid Week Number
 */
enum
{
  ublox_msgs__msg__NavTIMEGPS__VALID_WEEK = 2
};

/// Constant 'VALID_LEAP_S'.
/**
  * Valid Leap Seconds
 */
enum
{
  ublox_msgs__msg__NavTIMEGPS__VALID_LEAP_S = 4
};

/// Struct defined in msg/NavTIMEGPS in the package ublox_msgs.
/**
  * NAV-TIMEGPS (0x01 0x20)
  * GPS Time Solution
 */
typedef struct ublox_msgs__msg__NavTIMEGPS
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// Fractional Nanoseconds remainder of rounded
  /// ms above, range -500000 .. 500000
  int32_t f_tow;
  /// GPS week (GPS time)
  int16_t week;
  /// Leap Seconds (GPS-UTC)
  int8_t leap_s;
  /// Validity Flags
  uint8_t valid;
  /// Time Accuracy Estimate
  uint32_t t_acc;
} ublox_msgs__msg__NavTIMEGPS;

// Struct for a sequence of ublox_msgs__msg__NavTIMEGPS.
typedef struct ublox_msgs__msg__NavTIMEGPS__Sequence
{
  ublox_msgs__msg__NavTIMEGPS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavTIMEGPS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__STRUCT_H_

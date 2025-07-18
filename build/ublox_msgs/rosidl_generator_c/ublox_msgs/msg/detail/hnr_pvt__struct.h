// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/HnrPVT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__HNR_PVT__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__HNR_PVT__STRUCT_H_

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
  ublox_msgs__msg__HnrPVT__CLASS_ID = 40
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__HnrPVT__MESSAGE_ID = 0
};

/// Constant 'VALID_DATE'.
/**
  * Valid UTC Date
 */
enum
{
  ublox_msgs__msg__HnrPVT__VALID_DATE = 1
};

/// Constant 'VALID_TIME'.
/**
  * Valid
 */
enum
{
  ublox_msgs__msg__HnrPVT__VALID_TIME = 2
};

/// Constant 'VALID_FULLY_RESOLVED'.
/**
  * UTC time of day has been fully resolved
  * (no seconds uncertainty)
 */
enum
{
  ublox_msgs__msg__HnrPVT__VALID_FULLY_RESOLVED = 4
};

/// Constant 'VALID_MAG'.
/**
  * Valid Magnetic Declination
 */
enum
{
  ublox_msgs__msg__HnrPVT__VALID_MAG = 8
};

/// Constant 'FIX_TYPE_NO_FIX'.
enum
{
  ublox_msgs__msg__HnrPVT__FIX_TYPE_NO_FIX = 0
};

/// Constant 'FIX_TYPE_DEAD_RECKONING_ONLY'.
enum
{
  ublox_msgs__msg__HnrPVT__FIX_TYPE_DEAD_RECKONING_ONLY = 1
};

/// Constant 'FIX_TYPE_2D'.
/**
  * Signal from only 3 SVs,
  * constant altitude assumed
 */
enum
{
  ublox_msgs__msg__HnrPVT__FIX_TYPE_2D = 2
};

/// Constant 'FIX_TYPE_3D'.
enum
{
  ublox_msgs__msg__HnrPVT__FIX_TYPE_3D = 3
};

/// Constant 'FIX_TYPE_GPS_DEAD_RECKONING_COMBINED'.
/**
  * GPS + Dead reckoning
 */
enum
{
  ublox_msgs__msg__HnrPVT__FIX_TYPE_GPS_DEAD_RECKONING_COMBINED = 4
};

/// Constant 'FIX_TYPE_TIME_ONLY'.
/**
  * Time only fix
 */
enum
{
  ublox_msgs__msg__HnrPVT__FIX_TYPE_TIME_ONLY = 5
};

/// Constant 'FLAGS_GNSS_FIX_OK'.
/**
  * i.e. within DOP & accuracy masks
 */
enum
{
  ublox_msgs__msg__HnrPVT__FLAGS_GNSS_FIX_OK = 1
};

/// Constant 'FLAGS_DIFF_SOLN'.
/**
  * DGPS used
 */
enum
{
  ublox_msgs__msg__HnrPVT__FLAGS_DIFF_SOLN = 2
};

/// Constant 'FLAGS_WKN_SET'.
/**
  * Valid GPS week number
 */
enum
{
  ublox_msgs__msg__HnrPVT__FLAGS_WKN_SET = 4
};

/// Constant 'FLAGS_TOW_SET'.
/**
  * Valid GPS time of week (iTOW & fTOW)
 */
enum
{
  ublox_msgs__msg__HnrPVT__FLAGS_TOW_SET = 8
};

/// Constant 'FLAGS_HEAD_VEH_VALID'.
/**
  * heading of vehicle is valid
 */
enum
{
  ublox_msgs__msg__HnrPVT__FLAGS_HEAD_VEH_VALID = 32
};

/// Struct defined in msg/HnrPVT in the package ublox_msgs.
/**
  * HNR-PVT (0x28 0x00)
  * High Rate Output of PVT Solution
  *
  * Note that during a leap second there may be more (or less) than 60 seconds in
  * a minute; see the description of leap seconds for details.
  *
  * This message provides the position, velocity and time solution with high
  * output rate.
  *
  * Supported on ADR and UDR products.
 */
typedef struct ublox_msgs__msg__HnrPVT
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// Year (UTC)
  uint16_t year;
  /// Month, range 1..12 (UTC)
  uint8_t month;
  /// Day of month, range 1..31 (UTC)
  uint8_t day;
  /// Hour of day, range 0..23 (UTC)
  uint8_t hour;
  /// Minute of hour, range 0..59 (UTC)
  uint8_t min;
  /// Seconds of minute, range 0..60 (UTC)
  uint8_t sec;
  /// Validity flags
  uint8_t valid;
  /// fraction of a second, range -1e9 .. 1e9 (UTC)
  int32_t nano;
  /// GPS fix Type, range 0..5
  uint8_t gps_fix;
  /// Fix Status Flags
  uint8_t flags;
  /// Reserved
  uint8_t reserved0[2];
  /// Longitude
  int32_t lon;
  /// Latitude
  int32_t lat;
  /// Height above Ellipsoid
  int32_t height;
  /// Height above mean sea level
  int32_t h_msl;
  /// Ground Speed (2-D)
  int32_t g_speed;
  /// Speed (3-D)
  int32_t speed;
  /// Heading of motion (2-D)
  int32_t head_mot;
  /// Heading of vehicle (2-D)
  int32_t head_veh;
  /// Horizontal Accuracy Estimate
  uint32_t h_acc;
  /// Vertical Accuracy Estimate
  uint32_t v_acc;
  /// Speed Accuracy Estimate
  uint32_t s_acc;
  /// Heading Accuracy Estimate (both motion & vehicle)
  /// [deg / 1e-5]
  uint32_t head_acc;
  /// Reserved
  uint8_t reserved1[4];
} ublox_msgs__msg__HnrPVT;

// Struct for a sequence of ublox_msgs__msg__HnrPVT.
typedef struct ublox_msgs__msg__HnrPVT__Sequence
{
  ublox_msgs__msg__HnrPVT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__HnrPVT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__HNR_PVT__STRUCT_H_

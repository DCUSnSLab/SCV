// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavSVINFOSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FLAGS_SV_USED'.
/**
  * SV is used for navigation
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_SV_USED = 1
};

/// Constant 'FLAGS_DIFF_CORR'.
/**
  * Differential correction data
  * is available for this SV
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_DIFF_CORR = 2
};

/// Constant 'FLAGS_ORBIT_AVAIL'.
/**
  * Orbit information is available for
  * this SV (Ephemeris or Almanach)
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_ORBIT_AVAIL = 4
};

/// Constant 'FLAGS_ORBIT_EPH'.
/**
  * Orbit information is Ephemeris
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_ORBIT_EPH = 8
};

/// Constant 'FLAGS_UNHEALTHY'.
/**
  * SV is unhealthy / shall not be
  * used
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_UNHEALTHY = 16
};

/// Constant 'FLAGS_ORBIT_ALM'.
/**
  * Orbit information is Almanac Plus
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_ORBIT_ALM = 32
};

/// Constant 'FLAGS_ORBIT_AOP'.
/**
  * Orbit information is AssistNow
  * Autonomous
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_ORBIT_AOP = 64
};

/// Constant 'FLAGS_SMOOTHED'.
/**
  * Carrier smoothed pseudorange used
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__FLAGS_SMOOTHED = 128
};

/// Constant 'QUALITY_IDLE'.
/**
  * qualityInd: Signal Quality indicator (range 0..7). The following list shows
  * the meaning of the different QI values:
  * Note: Since IMES signals are not time synchronized, a channel tracking an IMES
  * signal can never reach a quality indicator value of higher than 3.
  * This channel is idle
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_IDLE = 0
};

/// Constant 'QUALITY_SEARCHING'.
/**
  * Channel is searching
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_SEARCHING = 1
};

/// Constant 'QUALITY_ACQUIRED'.
/**
  * Signal acquired
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_ACQUIRED = 2
};

/// Constant 'QUALITY_DETECTED'.
/**
  * Signal detected but unusable
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_DETECTED = 3
};

/// Constant 'QUALITY_CODE_LOCK'.
/**
  * Code Lock on Signal
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_CODE_LOCK = 4
};

/// Constant 'QUALITY_CODE_AND_CARRIER_LOCKED1'.
/**
  * Code and Carrier locked
  * and time synchronized
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_CODE_AND_CARRIER_LOCKED1 = 5
};

/// Constant 'QUALITY_CODE_AND_CARRIER_LOCKED2'.
/**
  * Code and Carrier locked
  * and time synchronized
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_CODE_AND_CARRIER_LOCKED2 = 6
};

/// Constant 'QUALITY_CODE_AND_CARRIER_LOCKED3'.
/**
  * Code and Carrier locked
  * and time synchronized
 */
enum
{
  ublox_msgs__msg__NavSVINFOSV__QUALITY_CODE_AND_CARRIER_LOCKED3 = 7
};

/// Struct defined in msg/NavSVINFOSV in the package ublox_msgs.
/**
  * see message NavSVINFO
 */
typedef struct ublox_msgs__msg__NavSVINFOSV
{
  /// Channel number, 255 for SVs not assigned to a channel
  uint8_t chn;
  /// Satellite ID
  uint8_t svid;
  /// Bitmask
  uint8_t flags;
  /// Bitfield
  uint8_t quality;
  /// Carrier to Noise Ratio (Signal Strength)
  uint8_t cno;
  /// Elevation in integer degrees
  int8_t elev;
  /// Azimuth in integer degrees
  int16_t azim;
  /// Pseudo range residual in centimetres
  int32_t pr_res;
} ublox_msgs__msg__NavSVINFOSV;

// Struct for a sequence of ublox_msgs__msg__NavSVINFOSV.
typedef struct ublox_msgs__msg__NavSVINFOSV__Sequence
{
  ublox_msgs__msg__NavSVINFOSV * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavSVINFOSV__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__STRUCT_H_

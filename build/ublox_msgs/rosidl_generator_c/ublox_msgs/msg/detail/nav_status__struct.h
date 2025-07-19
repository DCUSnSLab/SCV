// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_H_

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
  ublox_msgs__msg__NavSTATUS__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavSTATUS__MESSAGE_ID = 3
};

/// Constant 'GPS_NO_FIX'.
enum
{
  ublox_msgs__msg__NavSTATUS__GPS_NO_FIX = 0
};

/// Constant 'GPS_DEAD_RECKONING_ONLY'.
enum
{
  ublox_msgs__msg__NavSTATUS__GPS_DEAD_RECKONING_ONLY = 1
};

/// Constant 'GPS_2D_FIX'.
enum
{
  ublox_msgs__msg__NavSTATUS__GPS_2D_FIX = 2
};

/// Constant 'GPS_3D_FIX'.
enum
{
  ublox_msgs__msg__NavSTATUS__GPS_3D_FIX = 3
};

/// Constant 'GPS_GPS_DEAD_RECKONING_COMBINED'.
enum
{
  ublox_msgs__msg__NavSTATUS__GPS_GPS_DEAD_RECKONING_COMBINED = 4
};

/// Constant 'GPS_TIME_ONLY_FIX'.
enum
{
  ublox_msgs__msg__NavSTATUS__GPS_TIME_ONLY_FIX = 5
};

/// Constant 'FLAGS_GPS_FIX_OK'.
/**
  * position & velocity valid & within DOP & ACC
  * Masks
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FLAGS_GPS_FIX_OK = 1
};

/// Constant 'FLAGS_DIFF_SOLN'.
/**
  * Differential corrections were applied
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FLAGS_DIFF_SOLN = 2
};

/// Constant 'FLAGS_WKNSET'.
/**
  * Week Number valid
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FLAGS_WKNSET = 4
};

/// Constant 'FLAGS_TOWSET'.
/**
  * Time of Week valid
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FLAGS_TOWSET = 8
};

/// Constant 'FIX_STAT_DIFF_CORR_MASK'.
/**
  * 1 = differential corrections available
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FIX_STAT_DIFF_CORR_MASK = 1
};

/// Constant 'FIX_STAT_MAP_MATCHING_MASK'.
/**
  * map matching status:
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FIX_STAT_MAP_MATCHING_MASK = 192
};

/// Constant 'MAP_MATCHING_NONE'.
/**
  * none
 */
enum
{
  ublox_msgs__msg__NavSTATUS__MAP_MATCHING_NONE = 0
};

/// Constant 'MAP_MATCHING_VALID'.
/**
  * valid but not used, i.e. map matching data
  * was received, but was too old
 */
enum
{
  ublox_msgs__msg__NavSTATUS__MAP_MATCHING_VALID = 64
};

/// Constant 'MAP_MATCHING_USED'.
/**
  * valid and used, map matching data was applied
 */
enum
{
  ublox_msgs__msg__NavSTATUS__MAP_MATCHING_USED = 128
};

/// Constant 'MAP_MATCHING_DR'.
/**
  * valid and used, map matching data was
  * applied. In case of sensor unavailability map
  * matching data enables dead reckoning.
  * This requires map matched latitude/longitude
  * or heading data.
 */
enum
{
  ublox_msgs__msg__NavSTATUS__MAP_MATCHING_DR = 192
};

/// Constant 'FLAGS2_PSM_STATE_MASK'.
/**
  * power safe mode state (Only for FW version >= 7.01; undefined otherwise)
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FLAGS2_PSM_STATE_MASK = 3
};

/// Constant 'PSM_STATE_ACQUISITION'.
/**
  * ACQUISITION
  * [or when psm disabled]
 */
enum
{
  ublox_msgs__msg__NavSTATUS__PSM_STATE_ACQUISITION = 0
};

/// Constant 'PSM_STATE_TRACKING'.
/**
  * TRACKING
 */
enum
{
  ublox_msgs__msg__NavSTATUS__PSM_STATE_TRACKING = 1
};

/// Constant 'PSM_STATE_POWER_OPTIMIZED_TRACKING'.
/**
  * POWER OPTIMIZED TRACKING
 */
enum
{
  ublox_msgs__msg__NavSTATUS__PSM_STATE_POWER_OPTIMIZED_TRACKING = 2
};

/// Constant 'PSM_STATE_INACTIVE'.
/**
  * INACTIVE
 */
enum
{
  ublox_msgs__msg__NavSTATUS__PSM_STATE_INACTIVE = 3
};

/// Constant 'FLAGS2_SPOOF_DET_STATE_MASK'.
/**
  * Note that the spoofing state value only reflects the detector state for the
  * current navigation epoch. As spoofing can be detected most easily at the
  * transition from real signal to spoofing signal, this is also where the
  * detector is triggered the most. I.e. a value of 1 - No spoofing indicated does
  * not mean that the receiver is not spoofed, it #simply states that the detector
  * was not triggered in this epoch.
 */
enum
{
  ublox_msgs__msg__NavSTATUS__FLAGS2_SPOOF_DET_STATE_MASK = 24
};

/// Constant 'SPOOF_DET_STATE_UNKNOWN'.
/**
  * Unknown or deactivated
 */
enum
{
  ublox_msgs__msg__NavSTATUS__SPOOF_DET_STATE_UNKNOWN = 0
};

/// Constant 'SPOOF_DET_STATE_NONE'.
/**
  * No spoofing indicated
 */
enum
{
  ublox_msgs__msg__NavSTATUS__SPOOF_DET_STATE_NONE = 8
};

/// Constant 'SPOOF_DET_STATE_SPOOFING'.
/**
  * Spoofing indicated
 */
enum
{
  ublox_msgs__msg__NavSTATUS__SPOOF_DET_STATE_SPOOFING = 16
};

/// Constant 'SPOOF_DET_STATE_MULTIPLE'.
/**
  * Multiple spoofing indication
 */
enum
{
  ublox_msgs__msg__NavSTATUS__SPOOF_DET_STATE_MULTIPLE = 24
};

/// Struct defined in msg/NavSTATUS in the package ublox_msgs.
/**
  * NAV-STATUS (0x01 0x03)
  * Receiver Navigation Status
  *
  * See important comments concerning validity of position and velocity given in
  * section Navigation Output Filters.
 */
typedef struct ublox_msgs__msg__NavSTATUS
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// GPSfix Type, this value does not qualify a fix as
  /// valid and within the limits. See note on flag gpsFixOk
  /// below
  uint8_t gps_fix;
  /// Navigation Status Flags
  uint8_t flags;
  /// Fix Status Information
  uint8_t fix_stat;
  /// further information about navigation output
  uint8_t flags2;
  /// Time to first fix (millisecond time tag)
  uint32_t ttff;
  /// Milliseconds since Startup / Reset
  uint32_t msss;
} ublox_msgs__msg__NavSTATUS;

// Struct for a sequence of ublox_msgs__msg__NavSTATUS.
typedef struct ublox_msgs__msg__NavSTATUS__Sequence
{
  ublox_msgs__msg__NavSTATUS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavSTATUS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_H_

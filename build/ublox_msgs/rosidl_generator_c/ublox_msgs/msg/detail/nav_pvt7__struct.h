// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavPVT7.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__STRUCT_H_

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
  ublox_msgs__msg__NavPVT7__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavPVT7__MESSAGE_ID = 7
};

/// Constant 'VALID_DATE'.
/**
  * Valid UTC Date
 */
enum
{
  ublox_msgs__msg__NavPVT7__VALID_DATE = 1
};

/// Constant 'VALID_TIME'.
/**
  * Valid
 */
enum
{
  ublox_msgs__msg__NavPVT7__VALID_TIME = 2
};

/// Constant 'VALID_FULLY_RESOLVED'.
/**
  * UTC time of day has been fully resolved
  * (no seconds uncertainty)
 */
enum
{
  ublox_msgs__msg__NavPVT7__VALID_FULLY_RESOLVED = 4
};

/// Constant 'VALID_MAG'.
/**
  * Valid Magnetic Declination
 */
enum
{
  ublox_msgs__msg__NavPVT7__VALID_MAG = 8
};

/// Constant 'FIX_TYPE_NO_FIX'.
enum
{
  ublox_msgs__msg__NavPVT7__FIX_TYPE_NO_FIX = 0
};

/// Constant 'FIX_TYPE_DEAD_RECKONING_ONLY'.
enum
{
  ublox_msgs__msg__NavPVT7__FIX_TYPE_DEAD_RECKONING_ONLY = 1
};

/// Constant 'FIX_TYPE_2D'.
/**
  * Signal from only 3 SVs,
  * constant altitude assumed
 */
enum
{
  ublox_msgs__msg__NavPVT7__FIX_TYPE_2D = 2
};

/// Constant 'FIX_TYPE_3D'.
enum
{
  ublox_msgs__msg__NavPVT7__FIX_TYPE_3D = 3
};

/// Constant 'FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED'.
/**
  * GNSS + Dead reckoning
 */
enum
{
  ublox_msgs__msg__NavPVT7__FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED = 4
};

/// Constant 'FIX_TYPE_TIME_ONLY'.
/**
  * Time only fix (High precision
  * devices)
 */
enum
{
  ublox_msgs__msg__NavPVT7__FIX_TYPE_TIME_ONLY = 5
};

/// Constant 'FLAGS_GNSS_FIX_OK'.
/**
  * i.e. within DOP & accuracy masks
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS_GNSS_FIX_OK = 1
};

/// Constant 'FLAGS_DIFF_SOLN'.
/**
  * DGPS used
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS_DIFF_SOLN = 2
};

/// Constant 'FLAGS_PSM_MASK'.
/**
  * Power Save Mode
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS_PSM_MASK = 28
};

/// Constant 'PSM_OFF'.
/**
  * PSM is off
 */
enum
{
  ublox_msgs__msg__NavPVT7__PSM_OFF = 0
};

/// Constant 'PSM_ENABLED'.
/**
  * Enabled (state before acquisition)
 */
enum
{
  ublox_msgs__msg__NavPVT7__PSM_ENABLED = 4
};

/// Constant 'PSM_ACQUIRED'.
/**
  * Acquisition
 */
enum
{
  ublox_msgs__msg__NavPVT7__PSM_ACQUIRED = 8
};

/// Constant 'PSM_TRACKING'.
/**
  * Tracking
 */
enum
{
  ublox_msgs__msg__NavPVT7__PSM_TRACKING = 12
};

/// Constant 'PSM_POWER_OPTIMIZED_TRACKING'.
/**
  * Power Optimized Tracking
 */
enum
{
  ublox_msgs__msg__NavPVT7__PSM_POWER_OPTIMIZED_TRACKING = 16
};

/// Constant 'PSM_INACTIVE'.
/**
  * Inactive
 */
enum
{
  ublox_msgs__msg__NavPVT7__PSM_INACTIVE = 20
};

/// Constant 'FLAGS_HEAD_VEH_VALID'.
/**
  * heading of vehicle is valid
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS_HEAD_VEH_VALID = 32
};

/// Constant 'FLAGS_CARRIER_PHASE_MASK'.
/**
  * Carrier Phase Range Solution Status
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS_CARRIER_PHASE_MASK = 192
};

/// Constant 'CARRIER_PHASE_NO_SOLUTION'.
/**
  * no carrier phase range solution
 */
enum
{
  ublox_msgs__msg__NavPVT7__CARRIER_PHASE_NO_SOLUTION = 0
};

/// Constant 'CARRIER_PHASE_FLOAT'.
/**
  * carrier phase float solution (no fixed
  * integer measurements have been used to
  * calculate the solution)
 */
enum
{
  ublox_msgs__msg__NavPVT7__CARRIER_PHASE_FLOAT = 64
};

/// Constant 'CARRIER_PHASE_FIXED'.
/**
  * fixed solution (>=1 fixed integer
  * carrier phase range measurements have
  * been used to calculate  the solution)
 */
enum
{
  ublox_msgs__msg__NavPVT7__CARRIER_PHASE_FIXED = 128
};

/// Constant 'FLAGS2_CONFIRMED_AVAILABLE'.
/**
  * information about UTC Date and Time of
  * Day validity confirmation is available
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS2_CONFIRMED_AVAILABLE = 32
};

/// Constant 'FLAGS2_CONFIRMED_DATE'.
/**
  * UTC Date validity could be confirmed
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS2_CONFIRMED_DATE = 64
};

/// Constant 'FLAGS2_CONFIRMED_TIME'.
/**
  * UTC Time of Day could be confirmed
 */
enum
{
  ublox_msgs__msg__NavPVT7__FLAGS2_CONFIRMED_TIME = 128
};

/// Struct defined in msg/NavPVT7 in the package ublox_msgs.
/**
  * NAV-PVT (0x01 0x07)
  * Navigation Position Velocity Time Solution Firmware version 7
  *
  * Note that during a leap second there may be more (or less) than 60 seconds in
  * a minute; see the description of leap seconds for details.
  *
  * This message combines Position, velocity and time solution in LLH,
  * including accuracy figures
  *
  * WARNING: For firmware version 7, this message is a different length.
 */
typedef struct ublox_msgs__msg__NavPVT7
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
  /// time accuracy estimate (UTC)
  uint32_t t_acc;
  /// fraction of a second, range -1e9 .. 1e9 (UTC)
  int32_t nano;
  /// GNSS fix Type, range 0..5
  uint8_t fix_type;
  /// Fix Status Flags
  uint8_t flags;
  /// Additional Flags
  uint8_t flags2;
  /// Number of SVs used in Nav Solution
  uint8_t num_sv;
  /// Longitude
  int32_t lon;
  /// Latitude
  int32_t lat;
  /// Height above Ellipsoid
  int32_t height;
  /// Height above mean sea level
  int32_t h_msl;
  /// Horizontal Accuracy Estimate
  uint32_t h_acc;
  /// Vertical Accuracy Estimate
  uint32_t v_acc;
  /// NED north velocity
  int32_t vel_n;
  /// NED east velocity
  int32_t vel_e;
  /// NED down velocity
  int32_t vel_d;
  /// Ground Speed (2-D)
  int32_t g_speed;
  /// Heading of motion 2-D
  int32_t heading;
  /// Speed Accuracy Estimate
  uint32_t s_acc;
  /// Heading Accuracy Estimate (both motion & vehicle)
  /// [deg / 1e-5]
  uint32_t head_acc;
  /// Position DOP
  uint16_t p_dop;
  /// Reserved
  uint8_t reserved1[6];
} ublox_msgs__msg__NavPVT7;

// Struct for a sequence of ublox_msgs__msg__NavPVT7.
typedef struct ublox_msgs__msg__NavPVT7__Sequence
{
  ublox_msgs__msg__NavPVT7 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavPVT7__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__STRUCT_H_

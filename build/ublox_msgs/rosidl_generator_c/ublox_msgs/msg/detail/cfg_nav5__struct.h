// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgNAV5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__STRUCT_H_

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
  ublox_msgs__msg__CfgNAV5__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgNAV5__MESSAGE_ID = 36
};

/// Constant 'MASK_DYN'.
/**
  * Apply dynamic model settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_DYN = 1
};

/// Constant 'MASK_MIN_EL'.
/**
  * Apply minimum elevation settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_MIN_EL = 2
};

/// Constant 'MASK_FIX_MODE'.
/**
  * Apply fix mode settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_FIX_MODE = 4
};

/// Constant 'MASK_DR_LIM'.
/**
  * Apply DR limit settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_DR_LIM = 8
};

/// Constant 'MASK_POS_MASK'.
/**
  * Apply position mask settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_POS_MASK = 16
};

/// Constant 'MASK_TIME_MASK'.
/**
  * Apply time mask settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_TIME_MASK = 32
};

/// Constant 'MASK_STATIC_HOLD_MASK'.
/**
  * Apply static hold settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_STATIC_HOLD_MASK = 64
};

/// Constant 'MASK_DGPS_MASK'.
/**
  * Apply DGPS settings, firmware >= 7 only
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_DGPS_MASK = 128
};

/// Constant 'MASK_CNO'.
/**
  * Apply CNO threshold settings
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_CNO = 256
};

/// Constant 'MASK_UTC'.
/**
  * Apply UTC settings, protocol >= 16 only
 */
enum
{
  ublox_msgs__msg__CfgNAV5__MASK_UTC = 1024
};

/// Constant 'DYN_MODEL_PORTABLE'.
/**
  * Portable
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_PORTABLE = 0
};

/// Constant 'DYN_MODEL_STATIONARY'.
/**
  * Stationary
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_STATIONARY = 2
};

/// Constant 'DYN_MODEL_PEDESTRIAN'.
/**
  * Pedestrian
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_PEDESTRIAN = 3
};

/// Constant 'DYN_MODEL_AUTOMOTIVE'.
/**
  * Automotive
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_AUTOMOTIVE = 4
};

/// Constant 'DYN_MODEL_SEA'.
/**
  * Sea
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_SEA = 5
};

/// Constant 'DYN_MODEL_AIRBORNE_1G'.
/**
  * Airborne with <1g Acceleration
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_AIRBORNE_1G = 6
};

/// Constant 'DYN_MODEL_AIRBORNE_2G'.
/**
  * Airborne with <2g Acceleration
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_AIRBORNE_2G = 7
};

/// Constant 'DYN_MODEL_AIRBORNE_4G'.
/**
  * Airborne with <4g Acceleration
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_AIRBORNE_4G = 8
};

/// Constant 'DYN_MODEL_WRIST_WATCH'.
/**
  * Wrist watch, protocol >= 18
 */
enum
{
  ublox_msgs__msg__CfgNAV5__DYN_MODEL_WRIST_WATCH = 9
};

/// Constant 'FIX_MODE_2D_ONLY'.
/**
  * 2D only
 */
enum
{
  ublox_msgs__msg__CfgNAV5__FIX_MODE_2D_ONLY = 1
};

/// Constant 'FIX_MODE_3D_ONLY'.
/**
  * 3D only
 */
enum
{
  ublox_msgs__msg__CfgNAV5__FIX_MODE_3D_ONLY = 2
};

/// Constant 'FIX_MODE_AUTO'.
/**
  * Auto 2D/3D
 */
enum
{
  ublox_msgs__msg__CfgNAV5__FIX_MODE_AUTO = 3
};

/// Constant 'UTC_STANDARD_AUTOMATIC'.
/**
  * receiver selects based on GNSS configuration
 */
enum
{
  ublox_msgs__msg__CfgNAV5__UTC_STANDARD_AUTOMATIC = 0
};

/// Constant 'UTC_STANDARD_GPS'.
/**
  * UTC as operated by the U.S. Naval Observatory
  * (USNO); derived from GPS time
 */
enum
{
  ublox_msgs__msg__CfgNAV5__UTC_STANDARD_GPS = 3
};

/// Constant 'UTC_STANDARD_GLONASS'.
/**
  * UTC as operated by the former Soviet Union;
  * derived from GLONASS time
 */
enum
{
  ublox_msgs__msg__CfgNAV5__UTC_STANDARD_GLONASS = 6
};

/// Constant 'UTC_STANDARD_BEIDOU'.
/**
  * UTC as operated by the National Time Service
  * Center, China; derived from BeiDou time
 */
enum
{
  ublox_msgs__msg__CfgNAV5__UTC_STANDARD_BEIDOU = 7
};

/// Struct defined in msg/CfgNAV5 in the package ublox_msgs.
/**
  * CFG-NAV5 (0x06 0x24)
  * Navigation Engine Settings
 */
typedef struct ublox_msgs__msg__CfgNAV5
{
  /// Parameters Bitmask. Only the masked
  /// parameters will be applied.
  uint16_t mask;
  /// Dynamic Platform model:
  uint8_t dyn_model;
  /// Position Fixing Mode.
  uint8_t fix_mode;
  /// Fixed altitude (mean sea level) for 2D fix mode.
  /// [m / 0.01]
  int32_t fixed_alt;
  /// Fixed altitude variance for 2D mode.
  uint32_t fixed_alt_var;
  /// Minimum Elevation for a GNSS satellite to be used in
  /// NAV
  int8_t min_elev;
  /// Maximum time to perform dead reckoning
  /// (linear extrapolation) in case of GPS signal loss
  uint8_t dr_limit;
  /// Position DOP Mask to use
  uint16_t p_dop;
  /// Time DOP Mask to use
  uint16_t t_dop;
  /// Position Accuracy Mask
  uint16_t p_acc;
  /// Time Accuracy Mask
  uint16_t t_acc;
  /// Static hold threshold
  uint8_t static_hold_thresh;
  /// DGNSS timeout, firmware 7 and newer only
  uint8_t dgnss_time_out;
  /// Number of satellites required to have C/N0 above
  /// cnoThresh for a fix to be attempted
  uint8_t cno_thresh_num_svs;
  /// C/N0 threshold for deciding whether to attempt a fix
  /// [dBHz]
  uint8_t cno_thresh;
  /// Reserved
  uint8_t reserved1[2];
  /// Static hold distance threshold (before quitting
  /// static hold)
  uint16_t static_hold_max_dist;
  /// UTC standard to be used:
  uint8_t utc_standard;
  /// Reserved
  uint8_t reserved2[5];
} ublox_msgs__msg__CfgNAV5;

// Struct for a sequence of ublox_msgs__msg__CfgNAV5.
typedef struct ublox_msgs__msg__CfgNAV5__Sequence
{
  ublox_msgs__msg__CfgNAV5 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgNAV5__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__STRUCT_H_

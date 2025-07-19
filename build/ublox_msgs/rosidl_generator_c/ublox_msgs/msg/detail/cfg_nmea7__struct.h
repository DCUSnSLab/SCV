// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgNMEA7.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA7__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA7__STRUCT_H_

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
  ublox_msgs__msg__CfgNMEA7__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgNMEA7__MESSAGE_ID = 23
};

/// Constant 'FILTER_POS'.
/**
  * Enable position output for failed or
  * invalid fixes
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__FILTER_POS = 1
};

/// Constant 'FILTER_MSK_POS'.
/**
  * Enable position output for invalid fixes
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__FILTER_MSK_POS = 2
};

/// Constant 'FILTER_TIME'.
/**
  * Enable time output for invalid times
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__FILTER_TIME = 4
};

/// Constant 'FILTER_DATE'.
/**
  * Enable date output for invalid dates
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__FILTER_DATE = 8
};

/// Constant 'FILTER_GPS_ONLY'.
/**
  * Restrict output to GPS satellites only
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__FILTER_GPS_ONLY = 16
};

/// Constant 'FILTER_TRACK'.
/**
  * Enable COG output even if COG is frozen
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__FILTER_TRACK = 32
};

/// Constant 'NMEA_VERSION_2_3'.
/**
  * Version 2.3
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__NMEA_VERSION_2_3 = 35
};

/// Constant 'NMEA_VERSION_2_1'.
/**
  * Version 2.1
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__NMEA_VERSION_2_1 = 33
};

/// Constant 'NUM_SV_UNLIMITED'.
enum
{
  ublox_msgs__msg__CfgNMEA7__NUM_SV_UNLIMITED = 0
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
  ublox_msgs__msg__CfgNMEA7__FLAGS_COMPAT = 1
};

/// Constant 'FLAGS_CONSIDER'.
/**
  * enable considering mode
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__FLAGS_CONSIDER = 2
};

/// Constant 'GNSS_TO_FILTER_GPS'.
/**
  * Disable reporting of GPS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__GNSS_TO_FILTER_GPS = 1ul
};

/// Constant 'GNSS_TO_FILTER_SBAS'.
/**
  * Disable reporting of SBAS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__GNSS_TO_FILTER_SBAS = 2ul
};

/// Constant 'GNSS_TO_FILTER_QZSS'.
/**
  * Disable reporting of QZSS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__GNSS_TO_FILTER_QZSS = 16ul
};

/// Constant 'GNSS_TO_FILTER_GLONASS'.
/**
  * Disable reporting of GLONASS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__GNSS_TO_FILTER_GLONASS = 32ul
};

/// Constant 'SV_NUMBERING_STRICT'.
/**
  * Strict - Satellites are not output
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__SV_NUMBERING_STRICT = 0
};

/// Constant 'SV_NUMBERING_EXTENDED'.
/**
  * Extended - Use proprietary numbering
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__SV_NUMBERING_EXTENDED = 1
};

/// Constant 'MAIN_TALKER_ID_NOT_OVERRIDDEN'.
/**
  * Main Talker ID is not overridden
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__MAIN_TALKER_ID_NOT_OVERRIDDEN = 0
};

/// Constant 'MAIN_TALKER_ID_GP'.
/**
  * Set main Talker ID to 'GP'
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__MAIN_TALKER_ID_GP = 1
};

/// Constant 'MAIN_TALKER_ID_GL'.
/**
  * Set main Talker ID to 'GL'
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__MAIN_TALKER_ID_GL = 2
};

/// Constant 'MAIN_TALKER_ID_GN'.
/**
  * Set main Talker ID to 'GN'
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__MAIN_TALKER_ID_GN = 3
};

/// Constant 'GSV_TALKER_ID_GNSS_SPECIFIC'.
/**
  * Use GNSS specific Talker ID
  * (as defined by NMEA)
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__GSV_TALKER_ID_GNSS_SPECIFIC = 0
};

/// Constant 'GSV_TALKER_ID_MAIN'.
/**
  * Use the main Talker ID
 */
enum
{
  ublox_msgs__msg__CfgNMEA7__GSV_TALKER_ID_MAIN = 1
};

/// Struct defined in msg/CfgNMEA7 in the package ublox_msgs.
/**
  * CFG-NMEA (0x06 0x17)
  * NMEA protocol configuration V0
  *
  * Set/Get the NMEA protocol configuration. See section NMEA Protocol
  * Configuration for a detailed description of the configuration effects on
  * NMEA output
  *
  * Supported on: u-blox 7 firmware version 1.00
 */
typedef struct ublox_msgs__msg__CfgNMEA7
{
  /// filter flags
  uint8_t filter;
  /// NMEA version
  uint8_t nmea_version;
  /// Maximum Number of SVs to report per TalkerId:
  /// unlimited (0) or 8, 12, 16
  uint8_t num_sv;
  /// flags
  uint8_t flags;
  /// Filters out satellites based on their GNSS.
  /// If a bitfield is enabled, the corresponding
  /// satellites will be not output.
  uint32_t gnss_to_filter;
  /// Configures the display of satellites that do not
  /// have an NMEA-defined value. Note: this does not
  /// apply to satellites with an unknown ID.
  uint8_t sv_numbering;
  /// By default the main Talker ID (i.e. the Talker
  /// ID used  for all messages other than GSV) is
  /// determined by the  GNSS assignment of the
  /// receiver's channels (see CfgGNSS).
  /// This field enables the main Talker ID to be
  /// overridden
  uint8_t main_talker_id;
  /// By default the Talker ID for GSV messages is
  /// GNSS specific (as defined by NMEA). This field
  /// enables the GSV Talker ID to be overridden.
  uint8_t gsv_talker_id;
  /// Reserved
  uint8_t reserved;
} ublox_msgs__msg__CfgNMEA7;

// Struct for a sequence of ublox_msgs__msg__CfgNMEA7.
typedef struct ublox_msgs__msg__CfgNMEA7__Sequence
{
  ublox_msgs__msg__CfgNMEA7 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgNMEA7__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA7__STRUCT_H_

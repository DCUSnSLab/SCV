// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgNMEA.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__STRUCT_H_

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
  ublox_msgs__msg__CfgNMEA__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgNMEA__MESSAGE_ID = 23
};

/// Constant 'FILTER_POS'.
/**
  * Enable position output for failed or
  * invalid fixes
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FILTER_POS = 1
};

/// Constant 'FILTER_MSK_POS'.
/**
  * Enable position output for invalid fixes
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FILTER_MSK_POS = 2
};

/// Constant 'FILTER_TIME'.
/**
  * Enable time output for invalid times
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FILTER_TIME = 4
};

/// Constant 'FILTER_DATE'.
/**
  * Enable date output for invalid dates
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FILTER_DATE = 8
};

/// Constant 'FILTER_GPS_ONLY'.
/**
  * Restrict output to GPS satellites only
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FILTER_GPS_ONLY = 16
};

/// Constant 'FILTER_TRACK'.
/**
  * Enable COG output even if COG is frozen
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FILTER_TRACK = 32
};

/// Constant 'NMEA_VERSION_4_1'.
/**
  * Version 4.1
 */
enum
{
  ublox_msgs__msg__CfgNMEA__NMEA_VERSION_4_1 = 65
};

/// Constant 'NMEA_VERSION_4_0'.
/**
  * Version 4.0
 */
enum
{
  ublox_msgs__msg__CfgNMEA__NMEA_VERSION_4_0 = 64
};

/// Constant 'NMEA_VERSION_2_3'.
/**
  * Version 2.3
 */
enum
{
  ublox_msgs__msg__CfgNMEA__NMEA_VERSION_2_3 = 35
};

/// Constant 'NMEA_VERSION_2_1'.
/**
  * Version 2.1
 */
enum
{
  ublox_msgs__msg__CfgNMEA__NMEA_VERSION_2_1 = 33
};

/// Constant 'NUM_SV_UNLIMITED'.
enum
{
  ublox_msgs__msg__CfgNMEA__NUM_SV_UNLIMITED = 0
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
  ublox_msgs__msg__CfgNMEA__FLAGS_COMPAT = 1
};

/// Constant 'FLAGS_CONSIDER'.
/**
  * enable considering mode
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FLAGS_CONSIDER = 2
};

/// Constant 'FLAGS_LIMIT82'.
/**
  * enable strict limit to 82 characters maximum
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FLAGS_LIMIT82 = 4
};

/// Constant 'FLAGS_HIGH_PREC'.
/**
  * enable high precision mode
  * This flag cannot be set in conjunction with
  * either Compatibility Mode or Limit82 Mode.
  * (not supported in protocol versions < 20.01)
 */
enum
{
  ublox_msgs__msg__CfgNMEA__FLAGS_HIGH_PREC = 8
};

/// Constant 'GNSS_TO_FILTER_GPS'.
/**
  * Disable reporting of GPS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA__GNSS_TO_FILTER_GPS = 1ul
};

/// Constant 'GNSS_TO_FILTER_SBAS'.
/**
  * Disable reporting of SBAS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA__GNSS_TO_FILTER_SBAS = 2ul
};

/// Constant 'GNSS_TO_FILTER_QZSS'.
/**
  * Disable reporting of QZSS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA__GNSS_TO_FILTER_QZSS = 16ul
};

/// Constant 'GNSS_TO_FILTER_GLONASS'.
/**
  * Disable reporting of GLONASS satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA__GNSS_TO_FILTER_GLONASS = 32ul
};

/// Constant 'GNSS_TO_FILTER_BEIDOU'.
/**
  * Disable reporting of BeiDou satellites
 */
enum
{
  ublox_msgs__msg__CfgNMEA__GNSS_TO_FILTER_BEIDOU = 64ul
};

/// Constant 'SV_NUMBERING_STRICT'.
/**
  * Strict - Satellites are not output
 */
enum
{
  ublox_msgs__msg__CfgNMEA__SV_NUMBERING_STRICT = 0
};

/// Constant 'SV_NUMBERING_EXTENDED'.
/**
  * Extended - Use proprietary numbering
 */
enum
{
  ublox_msgs__msg__CfgNMEA__SV_NUMBERING_EXTENDED = 1
};

/// Constant 'MAIN_TALKER_ID_NOT_OVERRIDDEN'.
/**
  * Main Talker ID is not overridden
 */
enum
{
  ublox_msgs__msg__CfgNMEA__MAIN_TALKER_ID_NOT_OVERRIDDEN = 0
};

/// Constant 'MAIN_TALKER_ID_GP'.
/**
  * Set main Talker ID to 'GP'
 */
enum
{
  ublox_msgs__msg__CfgNMEA__MAIN_TALKER_ID_GP = 1
};

/// Constant 'MAIN_TALKER_ID_GL'.
/**
  * Set main Talker ID to 'GL'
 */
enum
{
  ublox_msgs__msg__CfgNMEA__MAIN_TALKER_ID_GL = 2
};

/// Constant 'MAIN_TALKER_ID_GN'.
/**
  * Set main Talker ID to 'GN'
 */
enum
{
  ublox_msgs__msg__CfgNMEA__MAIN_TALKER_ID_GN = 3
};

/// Constant 'MAIN_TALKER_ID_GA'.
/**
  * Set main Talker ID to 'GA'
 */
enum
{
  ublox_msgs__msg__CfgNMEA__MAIN_TALKER_ID_GA = 4
};

/// Constant 'MAIN_TALKER_ID_GB'.
/**
  * Set main Talker ID to 'GB'
 */
enum
{
  ublox_msgs__msg__CfgNMEA__MAIN_TALKER_ID_GB = 5
};

/// Constant 'GSV_TALKER_ID_GNSS_SPECIFIC'.
/**
  * Use GNSS specific Talker ID
  * (as defined by NMEA)
 */
enum
{
  ublox_msgs__msg__CfgNMEA__GSV_TALKER_ID_GNSS_SPECIFIC = 0
};

/// Constant 'GSV_TALKER_ID_MAIN'.
/**
  * Use the main Talker ID
 */
enum
{
  ublox_msgs__msg__CfgNMEA__GSV_TALKER_ID_MAIN = 1
};

/// Constant 'VERSION'.
enum
{
  ublox_msgs__msg__CfgNMEA__VERSION = 1
};

/// Struct defined in msg/CfgNMEA in the package ublox_msgs.
/**
  * CFG-NMEA (0x06 0x17)
  * NMEA protocol configuration V1
  *
  * Set/Get the NMEA protocol configuration. See section NMEA Protocol
  * Configuration for a detailed description of the configuration effects on
  * NMEA output
 */
typedef struct ublox_msgs__msg__CfgNMEA
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
  /// Message version (set to 1 for this version)
  uint8_t version;
  /// Sets the two characters that should be used
  /// for the BeiDou Talker ID. If these are set to
  /// zero, the default BeiDou TalkerId will be used
  uint8_t bds_talker_id[2];
  /// Reserved
  uint8_t reserved1[6];
} ublox_msgs__msg__CfgNMEA;

// Struct for a sequence of ublox_msgs__msg__CfgNMEA.
typedef struct ublox_msgs__msg__CfgNMEA__Sequence
{
  ublox_msgs__msg__CfgNMEA * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgNMEA__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__STRUCT_H_

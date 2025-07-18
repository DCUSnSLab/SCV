// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__STRUCT_H_

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
  ublox_msgs__msg__CfgTMODE3__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgTMODE3__MESSAGE_ID = 113
};

/// Constant 'FLAGS_MODE_MASK'.
/**
  * Receiver Mode:
 */
enum
{
  ublox_msgs__msg__CfgTMODE3__FLAGS_MODE_MASK = 255
};

/// Constant 'FLAGS_MODE_DISABLED'.
/**
  * Disabled
 */
enum
{
  ublox_msgs__msg__CfgTMODE3__FLAGS_MODE_DISABLED = 0
};

/// Constant 'FLAGS_MODE_SURVEY_IN'.
/**
  * Survey In
 */
enum
{
  ublox_msgs__msg__CfgTMODE3__FLAGS_MODE_SURVEY_IN = 1
};

/// Constant 'FLAGS_MODE_FIXED'.
/**
  * Fixed Mode (true ARP position required)
 */
enum
{
  ublox_msgs__msg__CfgTMODE3__FLAGS_MODE_FIXED = 2
};

/// Constant 'FLAGS_LLA'.
/**
  * Position is given in LAT/LON/ALT
  * (default is ECEF)
 */
enum
{
  ublox_msgs__msg__CfgTMODE3__FLAGS_LLA = 256
};

/// Struct defined in msg/CfgTMODE3 in the package ublox_msgs.
/**
  * CFG-TMODE3 (0x06, 0x71)
  * Time Mode Settings 3
  *
  * Configures the receiver to be in Time Mode. The position referred to in this
  * message is that of the Antenna Reference Point (ARP). See the Time Mode
  * Description for details.
  *
  * Supported on:
  *  - u-blox 8 / u-blox M8 with protocol version 20 (only with High Precision
  *    GNSS products)
 */
typedef struct ublox_msgs__msg__CfgTMODE3
{
  /// Message version (0x00 for this version)
  uint8_t version;
  /// Reserved
  uint8_t reserved1;
  uint16_t flags;
  /// WGS84 ECEF X coordinate (or latitude) of
  /// the ARP position, depending on flags above
  /// [cm] or [deg / 1e-7]
  int32_t ecef_x_or_lat;
  /// WGS84 ECEF Y coordinate (or longitude) of
  /// the ARP position, depending on flags above
  /// [cm] or [deg / 1e-7]
  int32_t ecef_y_or_lon;
  /// WGS84 ECEF Z coordinate (or altitude) of
  /// the ARP position, depending on flags above
  /// [cm]
  int32_t ecef_z_or_alt;
  /// High-precision WGS84 ECEF X coordinate (or
  /// latitude) of the ARP position, depending on
  /// flags above. Must be in the range -99..+99.
  /// The precise WGS84 ECEF X coordinate in units
  /// of cm, or the precise WGS84 ECEF latitude in
  /// units of 1e-7 degrees, is given by
  /// ecefXOrLat + (ecefXOrLatHP * 1e-2)
  /// [0.1 mm] or [deg * 1e-9]
  int8_t ecef_x_or_lat_hp;
  /// High-precision WGS84 ECEF Y coordinate (or
  /// longitude) of the ARP position, depending on
  /// flags above. Must be in the range -99..+99.
  /// The precise WGS84 ECEF Y coordinate in units
  /// of cm, or the precise WGS84 ECEF longitude
  /// in units of 1e-7 degrees, is given by
  /// ecefYOrLon + (ecefYOrLonHP * 1e-2)
  /// [0.1 mm] or [deg * 1e-9]
  int8_t ecef_y_or_lon_hp;
  /// High-precision WGS84 ECEF Z coordinate (or
  /// altitude) of the ARP position, depending on
  /// flags above. Must be in the range -99..+99.
  /// The precise WGS84 ECEF Z coordinate, or
  /// altitude coordinate, in units of cm is given
  /// by ecefZOrAlt + (ecefZOrAltHP * 1e-2)
  /// [0.1 mm]
  int8_t ecef_z_or_alt_hp;
  /// Reserved
  uint8_t reserved2;
  /// Fixed position 3D accuracy
  /// [0.1 mm]
  uint32_t fixed_pos_acc;
  /// Survey-in minimum duration
  /// [s]
  uint32_t svin_min_dur;
  /// Survey-in position accuracy limit
  /// [0.1 mm]
  uint32_t svin_acc_limit;
  /// Reserved
  uint8_t reserved3[8];
} ublox_msgs__msg__CfgTMODE3;

// Struct for a sequence of ublox_msgs__msg__CfgTMODE3.
typedef struct ublox_msgs__msg__CfgTMODE3__Sequence
{
  ublox_msgs__msg__CfgTMODE3 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgTMODE3__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__STRUCT_H_

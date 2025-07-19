// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__STRUCT_H_

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
  ublox_msgs__msg__CfgSBAS__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgSBAS__MESSAGE_ID = 22
};

/// Constant 'MODE_ENABLED'.
/**
  * SBAS Enabled (1) / Disabled (0)
  *  This field is deprecated; use UBX-CFG-GNSS to
  * enable/disable SBAS operation
 */
enum
{
  ublox_msgs__msg__CfgSBAS__MODE_ENABLED = 1
};

/// Constant 'MODE_TEST'.
/**
  * SBAS Testbed: Use data anyhow (1) / Ignore data when
  * in Test Mode (SBAS Msg 0)
 */
enum
{
  ublox_msgs__msg__CfgSBAS__MODE_TEST = 2
};

/// Constant 'USAGE_RANGE'.
/**
  * Use SBAS GEOs as a ranging source (for navigation)
 */
enum
{
  ublox_msgs__msg__CfgSBAS__USAGE_RANGE = 1
};

/// Constant 'USAGE_DIFF_CORR'.
/**
  * Use SBAS Differential Corrections
 */
enum
{
  ublox_msgs__msg__CfgSBAS__USAGE_DIFF_CORR = 2
};

/// Constant 'USAGE_INTEGRITY'.
/**
  * Use SBAS Integrity Information
 */
enum
{
  ublox_msgs__msg__CfgSBAS__USAGE_INTEGRITY = 4
};

/// Struct defined in msg/CfgSBAS in the package ublox_msgs.
/**
  * CFG-SBAS (0x06 0x16)
  * SBAS Configuration
  *
  * This message configures the SBAS receiver subsystem (i.e. WAAS, EGNOS, MSAS).
  * See the SBAS Configuration Settings Description for a detailed description of
  * how these settings affect receiver operation
 */
typedef struct ublox_msgs__msg__CfgSBAS
{
  /// SBAS Mode
  uint8_t mode;
  /// SBAS Usage
  uint8_t usage;
  /// Maximum Number of SBAS prioritized tracking
  /// channels (valid range: 0 - 3) to use
  /// (obsolete and superseeded by UBX-CFG-GNSS in protocol
  /// versions 14+).
  uint8_t max_sbas;
  /// Continuation of scanmode bitmask below
  /// PRN 152...158
  uint8_t scanmode2;
  /// Which SBAS PRN numbers to search for (Bitmask)
  /// If all Bits are set to zero, auto-scan (i.e. all valid
  /// PRNs) are searched. Every bit corresponds to a PRN
  /// number.
  /// PRN 120..151
  uint32_t scanmode1;
} ublox_msgs__msg__CfgSBAS;

// Struct for a sequence of ublox_msgs__msg__CfgSBAS.
typedef struct ublox_msgs__msg__CfgSBAS__Sequence
{
  ublox_msgs__msg__CfgSBAS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgSBAS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__STRUCT_H_

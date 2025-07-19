// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__STRUCT_H_

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
  ublox_msgs__msg__CfgGNSS__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgGNSS__MESSAGE_ID = 62
};

// Include directives for member types
// Member 'blocks'
#include "ublox_msgs/msg/detail/cfg_gnss_block__struct.h"

/// Struct defined in msg/CfgGNSS in the package ublox_msgs.
/**
  * CFG-GNSS (0x06 0x3E)
  * GNSS Configuration
  *
  * Gets or sets the GNSS system channel sharing configuration.
  * If the receiver is sent a valid new configuration, it will respond with a
  * UBX-ACK-ACK message and immediately change to the new configuration. Otherwise
  * the receiver will reject the request, by issuing a UBX-ACK-NAK and continuing
  * operation with the previous configuration.
  * Configuration requirements:
  *  - It is necessary for at least one major GNSS to be enabled, after applying
  *    the new configuration to the current one.
  *  - It is also required that at least 4 tracking channels are available to each
  *    enabled major GNSS, i.e. maxTrkCh must have a minimum value of 4 for each
  *    enabled major GNSS.
  *  - The number of tracking channels in use must not exceed the number of
  *    tracking channels available in hardware, and the sum of all reserved
  *    tracking channels needs to be less than or equal to the number of tracking
  *    channels in use.
  * Notes:
  *  - To avoid cross-correlation issues, it is recommended that GPS and QZSS are
  *    always both enabled or both disabled.
  *  - Polling this message returns the configuration of all supported GNSS,
  *    whether enabled or not; it may also include GNSS unsupported by the
  *    particular product, but in such cases the enable flag will always be unset.
  *  - See section GNSS Configuration for a discussion of the use of this message
  *    and section Satellite Numbering for a description of the GNSS IDs available
  *  - Configuration specific to the GNSS system can be done via other messages
  *    (e.g. UBX-CFG-SBAS).
 */
typedef struct ublox_msgs__msg__CfgGNSS
{
  /// Message version (= 0 for this version)
  uint8_t msg_ver;
  /// Number of tracking channels in hardware (read only)
  uint8_t num_trk_ch_hw;
  /// (Read only in protocol versions greater than 23)
  /// Number of tracking channels to use (<= numTrkChHw)
  /// If 0xFF, then number of tracking channels to use will
  /// be set to numTrkChHw
  uint8_t num_trk_ch_use;
  /// Number of configuration blocks following
  uint8_t num_config_blocks;
  /// Start of repeated block (numConfigBlocks times)
  ublox_msgs__msg__CfgGNSSBlock__Sequence blocks;
} ublox_msgs__msg__CfgGNSS;

// Struct for a sequence of ublox_msgs__msg__CfgGNSS.
typedef struct ublox_msgs__msg__CfgGNSS__Sequence
{
  ublox_msgs__msg__CfgGNSS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgGNSS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__STRUCT_H_

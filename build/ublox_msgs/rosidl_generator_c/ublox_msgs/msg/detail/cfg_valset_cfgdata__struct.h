// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgVALSETCfgdata.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'GPS_ENABLE'.
/**
  * 0x1031001f
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GPS_ENABLE = 271646751ul
};

/// Constant 'GPS_L1CA_ENABLE'.
/**
  * 0x10310001
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GPS_L1CA_ENABLE = 271646721ul
};

/// Constant 'GPS_L2C_ENABLE'.
/**
  * 0x10310003
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GPS_L2C_ENABLE = 271646723ul
};

/// Constant 'SBAS_ENABLE'.
/**
  * 0x10310020
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__SBAS_ENABLE = 271646752ul
};

/// Constant 'SBAS_L1CA_ENABLE'.
/**
  * 0x10310005
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__SBAS_L1CA_ENABLE = 271646725ul
};

/// Constant 'GAL_ENABLE'.
/**
  * 0x10310021
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GAL_ENABLE = 271646753ul
};

/// Constant 'GAL_E1_ENABLE'.
/**
  * 0x10310007
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GAL_E1_ENABLE = 271646727ul
};

/// Constant 'GAL_E5B_ENABLE'.
/**
  * 0x1031000a
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GAL_E5B_ENABLE = 271646730ul
};

/// Constant 'BDS_ENABLE'.
/**
  * 0x10310022
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__BDS_ENABLE = 271646754ul
};

/// Constant 'BDS_B1_ENABLE'.
/**
  * 0x1031000d
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__BDS_B1_ENABLE = 271646733ul
};

/// Constant 'BDS_B2_ENABLE'.
/**
  * 0x1031000e
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__BDS_B2_ENABLE = 271646734ul
};

/// Constant 'QZSS_ENABLE'.
/**
  * 0x10310024
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__QZSS_ENABLE = 271646756ul
};

/// Constant 'QZSS_L1CA_ENABLE'.
/**
  * 0x10310012
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__QZSS_L1CA_ENABLE = 271646738ul
};

/// Constant 'QZSS_L1S_ENABLE'.
/**
  * 0x10310014
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__QZSS_L1S_ENABLE = 271646740ul
};

/// Constant 'QZSS_L2C_ENABLE'.
/**
  * 0x10310015
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__QZSS_L2C_ENABLE = 271646741ul
};

/// Constant 'GLO_ENABLE'.
/**
  * 0x10310025
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GLO_ENABLE = 271646757ul
};

/// Constant 'GLO_L1_ENABLE'.
/**
  * 0x10310018
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GLO_L1_ENABLE = 271646744ul
};

/// Constant 'GLO_L2_ENABLE'.
/**
  * 0x1031001a
 */
enum
{
  ublox_msgs__msg__CfgVALSETCfgdata__GLO_L2_ENABLE = 271646746ul
};

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/CfgVALSETCfgdata in the package ublox_msgs.
/**
  * CFG-SIGNAL Keys
 */
typedef struct ublox_msgs__msg__CfgVALSETCfgdata
{
  /// See Cfg-VALSET
  ///
  /// Key for configuration item being changed
  uint32_t key;
  /// Data for configuration item being changed,
  /// array can be of length 1 - 8 (i.e. 1 - 8 bytes long)
  rosidl_runtime_c__uint8__Sequence data;
} ublox_msgs__msg__CfgVALSETCfgdata;

// Struct for a sequence of ublox_msgs__msg__CfgVALSETCfgdata.
typedef struct ublox_msgs__msg__CfgVALSETCfgdata__Sequence
{
  ublox_msgs__msg__CfgVALSETCfgdata * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgVALSETCfgdata__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__STRUCT_H_

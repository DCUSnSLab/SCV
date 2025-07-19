// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgVALSET.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__STRUCT_H_

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
  ublox_msgs__msg__CfgVALSET__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgVALSET__MESSAGE_ID = 138
};

/// Constant 'LAYER_RAM'.
/**
  * RAM layer
 */
enum
{
  ublox_msgs__msg__CfgVALSET__LAYER_RAM = 1
};

/// Constant 'LAYER_BBR'.
/**
  * BBR layer
 */
enum
{
  ublox_msgs__msg__CfgVALSET__LAYER_BBR = 2
};

/// Constant 'LAYER_FLASH'.
/**
  * Flash Layer
 */
enum
{
  ublox_msgs__msg__CfgVALSET__LAYER_FLASH = 4
};

// Include directives for member types
// Member 'cfgdata'
#include "ublox_msgs/msg/detail/cfg_valset_cfgdata__struct.h"

/// Struct defined in msg/CfgVALSET in the package ublox_msgs.
/**
  * CFG-VALSET (0x06 0x8a)
  * Set configuration item values
  *
  * This message is used to set a configuration by providing configuration data ( a list of
  * key and value pairs), which identify the configuration items to change, and their new values.
  * Maximum of 64 Key IDs.
 */
typedef struct ublox_msgs__msg__CfgVALSET
{
  /// Message Version (0x00 for this version)
  uint8_t version;
  /// Bit mask: the layers where the configuration should be applied
  uint8_t layers;
  uint8_t reserved0[2];
  /// Start of repeated block
  /// Configuration data (key and value pairs)
  ublox_msgs__msg__CfgVALSETCfgdata__Sequence cfgdata;
} ublox_msgs__msg__CfgVALSET;

// Struct for a sequence of ublox_msgs__msg__CfgVALSET.
typedef struct ublox_msgs__msg__CfgVALSET__Sequence
{
  ublox_msgs__msg__CfgVALSET * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgVALSET__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgVALGET.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__STRUCT_H_

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
  ublox_msgs__msg__CfgVALGET__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgVALGET__MESSAGE_ID = 139
};

/// Constant 'LAYER_RAM'.
/**
  * RAM layer
 */
enum
{
  ublox_msgs__msg__CfgVALGET__LAYER_RAM = 0
};

/// Constant 'LAYER_BBR'.
/**
  * BBR layer
 */
enum
{
  ublox_msgs__msg__CfgVALGET__LAYER_BBR = 1
};

/// Constant 'LAYER_FLASH'.
/**
  * Flash Layer
 */
enum
{
  ublox_msgs__msg__CfgVALGET__LAYER_FLASH = 2
};

/// Constant 'LAYER_DEFAULT'.
/**
  * Default Layer
 */
enum
{
  ublox_msgs__msg__CfgVALGET__LAYER_DEFAULT = 7
};

// Include directives for member types
// Member 'keys'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/CfgVALGET in the package ublox_msgs.
/**
  * CFG-VALGET (0x06 0x8b)
  * Get configuration items
  *
  * This message is used to get configuration values by providing a list of configuration key IDs,
  * which identify the configuration items to retrieve. Maximum of 64 Key IDs.
 */
typedef struct ublox_msgs__msg__CfgVALGET
{
  /// Message Version (0x00 for this version)
  uint8_t version;
  /// The layer which the configuration items should be retrieved
  uint8_t layers;
  /// Skip this many key values before constructing output message
  uint16_t position;
  /// Start of repeated block
  /// Configuration key IDs of configuration items to be retrieved
  rosidl_runtime_c__uint32__Sequence keys;
} ublox_msgs__msg__CfgVALGET;

// Struct for a sequence of ublox_msgs__msg__CfgVALGET.
typedef struct ublox_msgs__msg__CfgVALGET__Sequence
{
  ublox_msgs__msg__CfgVALGET * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgVALGET__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__STRUCT_H_

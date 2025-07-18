// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgVALDEL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALDEL__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALDEL__STRUCT_H_

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
  ublox_msgs__msg__CfgVALDEL__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgVALDEL__MESSAGE_ID = 140
};

/// Constant 'LAYER_BBR'.
/**
  * BBR layer
 */
enum
{
  ublox_msgs__msg__CfgVALDEL__LAYER_BBR = 1
};

/// Constant 'LAYER_FLASH'.
/**
  * Flash Layer
 */
enum
{
  ublox_msgs__msg__CfgVALDEL__LAYER_FLASH = 2
};

// Include directives for member types
// Member 'keys'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/CfgVALDEL in the package ublox_msgs.
/**
  * CFG-VALDEL (0x06 0x8c)
  * Delete configuration item values
  *
  * This message is used to delete saved configurations to effectively revert the items values to
  * defaults. Maximum of 64 Key IDs.
 */
typedef struct ublox_msgs__msg__CfgVALDEL
{
  /// Message Version (0x00 for this version)
  uint8_t version;
  /// Bit mask: the layers where the configuration should be applied
  uint8_t layers;
  uint8_t reserved0[2];
  /// Start of repeated block
  /// Configuration key IDs of configuration items to be retrieved
  rosidl_runtime_c__uint32__Sequence keys;
} ublox_msgs__msg__CfgVALDEL;

// Struct for a sequence of ublox_msgs__msg__CfgVALDEL.
typedef struct ublox_msgs__msg__CfgVALDEL__Sequence
{
  ublox_msgs__msg__CfgVALDEL * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgVALDEL__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALDEL__STRUCT_H_

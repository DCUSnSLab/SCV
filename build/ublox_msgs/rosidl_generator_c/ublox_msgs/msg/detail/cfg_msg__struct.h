// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgMSG.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_MSG__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_MSG__STRUCT_H_

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
  ublox_msgs__msg__CfgMSG__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgMSG__MESSAGE_ID = 1
};

/// Struct defined in msg/CfgMSG in the package ublox_msgs.
/**
  * CFG-MSG (0x06 0x01)
  * Message Rate(s)
  *
  * Set message rate for the current port
 */
typedef struct ublox_msgs__msg__CfgMSG
{
  /// Message Class
  uint8_t msg_class;
  /// Message Identifier
  uint8_t msg_id;
  /// Send rate on current port
  /// [number of navigation solutions]
  uint8_t rate;
} ublox_msgs__msg__CfgMSG;

// Struct for a sequence of ublox_msgs__msg__CfgMSG.
typedef struct ublox_msgs__msg__CfgMSG__Sequence
{
  ublox_msgs__msg__CfgMSG * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgMSG__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_MSG__STRUCT_H_

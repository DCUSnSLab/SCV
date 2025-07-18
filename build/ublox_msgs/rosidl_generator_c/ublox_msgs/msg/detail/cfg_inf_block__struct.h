// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgINFBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PROTOCOL_ID_UBX'.
enum
{
  ublox_msgs__msg__CfgINFBlock__PROTOCOL_ID_UBX = 0
};

/// Constant 'PROTOCOL_ID_NMEA'.
enum
{
  ublox_msgs__msg__CfgINFBlock__PROTOCOL_ID_NMEA = 1
};

/// Constant 'INF_MSG_ERROR'.
/**
  * enable ERROR
 */
enum
{
  ublox_msgs__msg__CfgINFBlock__INF_MSG_ERROR = 1
};

/// Constant 'INF_MSG_WARNING'.
/**
  * enable WARNING
 */
enum
{
  ublox_msgs__msg__CfgINFBlock__INF_MSG_WARNING = 2
};

/// Constant 'INF_MSG_NOTICE'.
/**
  * enable NOTICE
 */
enum
{
  ublox_msgs__msg__CfgINFBlock__INF_MSG_NOTICE = 4
};

/// Constant 'INF_MSG_TEST'.
/**
  * enable TEST
 */
enum
{
  ublox_msgs__msg__CfgINFBlock__INF_MSG_TEST = 8
};

/// Constant 'INF_MSG_DEBUG'.
/**
  * enable DEBUG
 */
enum
{
  ublox_msgs__msg__CfgINFBlock__INF_MSG_DEBUG = 16
};

/// Struct defined in msg/CfgINFBlock in the package ublox_msgs.
/**
  * See CfgINF message
 */
typedef struct ublox_msgs__msg__CfgINFBlock
{
  /// Protocol Identifier, identifying for which
  /// protocol the configuration is set/get. The
  /// following are valid Protocol Identifiers:
  /// 0: UBX Protocol
  /// 1: NMEA Protocol
  /// 2-255: Reserved
  uint8_t protocol_id;
  /// Reserved
  uint8_t reserved1[3];
  /// A bit mask, saying which information messages
  /// are enabled on each I/O port
  uint8_t inf_msg_mask[6];
} ublox_msgs__msg__CfgINFBlock;

// Struct for a sequence of ublox_msgs__msg__CfgINFBlock.
typedef struct ublox_msgs__msg__CfgINFBlock__Sequence
{
  ublox_msgs__msg__CfgINFBlock * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgINFBlock__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__STRUCT_H_

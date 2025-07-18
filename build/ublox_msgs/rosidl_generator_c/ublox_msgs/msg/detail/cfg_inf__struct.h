// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgINF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_INF__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_INF__STRUCT_H_

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
  ublox_msgs__msg__CfgINF__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgINF__MESSAGE_ID = 2
};

// Include directives for member types
// Member 'blocks'
#include "ublox_msgs/msg/detail/cfg_inf_block__struct.h"

/// Struct defined in msg/CfgINF in the package ublox_msgs.
/**
  * CFG-INF  (0x06 0x02)
  * Information message configuration
  *
  * The value of infMsgMask below are that each bit represents one of the INF
  * class messages (Bit 0 for ERROR, Bit 1 for WARNING and so on.). For a complete
  * list, see the Message Class INF. Several configurations can be concatenated to
  * one input message.
  * In this case the payload length can be a multiple of the normal length. Output
  * messages from the module contain only one configuration unit. Note that I/O
  * Ports 1 and 2 correspond to serial ports 1 and 2. I/O port 0 is DDC. I/O port
  * 3 is USB. I/O port 4 is SPI. I/O port 5 is reserved for future use
 */
typedef struct ublox_msgs__msg__CfgINF
{
  /// start of repeated block
  ublox_msgs__msg__CfgINFBlock__Sequence blocks;
} ublox_msgs__msg__CfgINF;

// Struct for a sequence of ublox_msgs__msg__CfgINF.
typedef struct ublox_msgs__msg__CfgINF__Sequence
{
  ublox_msgs__msg__CfgINF * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgINF__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_INF__STRUCT_H_

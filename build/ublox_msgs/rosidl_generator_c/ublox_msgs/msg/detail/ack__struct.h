// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/Ack.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ACK__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__ACK__STRUCT_H_

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
  ublox_msgs__msg__Ack__CLASS_ID = 5
};

/// Constant 'NACK_MESSAGE_ID'.
enum
{
  ublox_msgs__msg__Ack__NACK_MESSAGE_ID = 0
};

/// Constant 'ACK_MESSAGE_ID'.
enum
{
  ublox_msgs__msg__Ack__ACK_MESSAGE_ID = 1
};

/// Struct defined in msg/Ack in the package ublox_msgs.
/**
  * ACK (0x05)
  * Message Acknowledged / Not-Acknowledged
  *
  * Output upon processing of an input message
 */
typedef struct ublox_msgs__msg__Ack
{
  /// Class ID of the (Not-)Acknowledged Message
  uint8_t cls_id;
  /// Message ID of the (Not-)Acknowledged Message
  uint8_t msg_id;
} ublox_msgs__msg__Ack;

// Struct for a sequence of ublox_msgs__msg__Ack.
typedef struct ublox_msgs__msg__Ack__Sequence
{
  ublox_msgs__msg__Ack * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__Ack__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__ACK__STRUCT_H_

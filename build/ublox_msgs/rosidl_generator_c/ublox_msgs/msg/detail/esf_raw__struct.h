// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/EsfRAW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_RAW__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__ESF_RAW__STRUCT_H_

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
  ublox_msgs__msg__EsfRAW__CLASS_ID = 16
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__EsfRAW__MESSAGE_ID = 3
};

// Include directives for member types
// Member 'blocks'
#include "ublox_msgs/msg/detail/esf_raw_block__struct.h"

/// Struct defined in msg/EsfRAW in the package ublox_msgs.
/**
  * ESF-RAW (0x10 0x03)
  * Raw sensor measurements
  *
  * The message contains measurements from the active inertial sensors connected
  * to the GNSS chip. Possible data types for the data field are accelerometer,
  * gyroscope and temperature readings as described in the ESF Measurement Data
  * section. Note that the rate selected in CFG-MSG is not respected. If a
  * positive rate is selected then all raw measurements will be output.
  *
  * Supported on ADR/UDR products.
 */
typedef struct ublox_msgs__msg__EsfRAW
{
  /// Reserved
  uint8_t reserved0[4];
  ublox_msgs__msg__EsfRAWBlock__Sequence blocks;
} ublox_msgs__msg__EsfRAW;

// Struct for a sequence of ublox_msgs__msg__EsfRAW.
typedef struct ublox_msgs__msg__EsfRAW__Sequence
{
  ublox_msgs__msg__EsfRAW * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__EsfRAW__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_RAW__STRUCT_H_

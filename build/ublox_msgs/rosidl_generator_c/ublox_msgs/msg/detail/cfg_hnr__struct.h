// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgHNR.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_HNR__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_HNR__STRUCT_H_

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
  ublox_msgs__msg__CfgHNR__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgHNR__MESSAGE_ID = 92
};

/// Struct defined in msg/CfgHNR in the package ublox_msgs.
/**
  * CFG-HNR (0x06 0x5C)
  * High Navigation Rate Settings
  *
  * The u-blox receivers support high rates of navigation update up to 30 Hz.
  * The navigation solution output (NAV-HNR) will not be aligned to the top of a
  * second.
  * The update rate has a direct influence on the power consumption. The more
  * fixes that are required, the more CPU power and communication resources are
  * required.
  * For most applications a 1 Hz update rate would be sufficient.
  *
  * (only with ADR or UDR products)
 */
typedef struct ublox_msgs__msg__CfgHNR
{
  /// Rate of navigation solution output
  uint8_t high_nav_rate;
  /// Reserved
  uint8_t reserved0[3];
} ublox_msgs__msg__CfgHNR;

// Struct for a sequence of ublox_msgs__msg__CfgHNR.
typedef struct ublox_msgs__msg__CfgHNR__Sequence
{
  ublox_msgs__msg__CfgHNR * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgHNR__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_HNR__STRUCT_H_

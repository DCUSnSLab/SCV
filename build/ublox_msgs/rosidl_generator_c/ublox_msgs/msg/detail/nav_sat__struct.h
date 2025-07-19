// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavSAT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SAT__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SAT__STRUCT_H_

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
  ublox_msgs__msg__NavSAT__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavSAT__MESSAGE_ID = 53
};

// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_satsv__struct.h"

/// Struct defined in msg/NavSAT in the package ublox_msgs.
/**
  * NAV-SAT (0x01 0x35)
  * Satellite Information
  *
  * This message displays information about SVs which are either known to be
  * visible or currently tracked by the receiver.
 */
typedef struct ublox_msgs__msg__NavSAT
{
  /// GPS time of week of the navigation epoch.
  uint32_t i_tow;
  /// Message version (1 for this version)
  uint8_t version;
  /// Number of satellites
  uint8_t num_svs;
  /// Reserved
  uint8_t reserved0[2];
  /// start of repeated block (numSvs times)
  ublox_msgs__msg__NavSATSV__Sequence sv;
} ublox_msgs__msg__NavSAT;

// Struct for a sequence of ublox_msgs__msg__NavSAT.
typedef struct ublox_msgs__msg__NavSAT__Sequence
{
  ublox_msgs__msg__NavSAT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavSAT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SAT__STRUCT_H_

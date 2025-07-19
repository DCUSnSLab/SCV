// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/EsfSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__STRUCT_H_

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
  ublox_msgs__msg__EsfSTATUS__CLASS_ID = 16
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__EsfSTATUS__MESSAGE_ID = 16
};

/// Constant 'FUSION_MODE_INIT'.
/**
  * receiver is initializing some unknown values
  * required for doing sensor fusion
 */
enum
{
  ublox_msgs__msg__EsfSTATUS__FUSION_MODE_INIT = 0
};

/// Constant 'FUSION_MODE_FUSION'.
/**
  * GNSS and sensor data are
  * used for navigation solution computation
 */
enum
{
  ublox_msgs__msg__EsfSTATUS__FUSION_MODE_FUSION = 1
};

/// Constant 'FUSION_MODE_SUSPENDED'.
/**
  * sensor fusion is temporarily disabled
  * due to e.g. invalid sensor data or detected
  * ferry
 */
enum
{
  ublox_msgs__msg__EsfSTATUS__FUSION_MODE_SUSPENDED = 2
};

/// Constant 'FUSION_MODE_DISABLED'.
/**
  * sensor fusion is permanently disabled
  * until receiver reset due e.g. to sensor
  * error
 */
enum
{
  ublox_msgs__msg__EsfSTATUS__FUSION_MODE_DISABLED = 3
};

// Include directives for member types
// Member 'sens'
#include "ublox_msgs/msg/detail/esf_status_sens__struct.h"

/// Struct defined in msg/EsfSTATUS in the package ublox_msgs.
/**
  * ESF-STATUS (0x10 0x10)
  * External Sensor Fusion (ESF) status information
  *
  * Supported on UDR/ADR products
 */
typedef struct ublox_msgs__msg__EsfSTATUS
{
  /// GPS time of week of the navigation epoch
  uint32_t i_tow;
  /// Message version (2 for this version)
  uint8_t version;
  /// Reserved
  uint8_t reserved1[7];
  /// Fusion mode:
  uint8_t fusion_mode;
  /// Reserved
  uint8_t reserved2[2];
  /// Number of sensors
  uint8_t num_sens;
  /// Start of repeated block (numSens times)
  ublox_msgs__msg__EsfSTATUSSens__Sequence sens;
} ublox_msgs__msg__EsfSTATUS;

// Struct for a sequence of ublox_msgs__msg__EsfSTATUS.
typedef struct ublox_msgs__msg__EsfSTATUS__Sequence
{
  ublox_msgs__msg__EsfSTATUS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__EsfSTATUS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__STRUCT_H_

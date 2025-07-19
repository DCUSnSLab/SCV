// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/EsfSTATUSSens.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EsfSTATUSSens in the package ublox_msgs.
/**
  * See Esf-STATUS
 */
typedef struct ublox_msgs__msg__EsfSTATUSSens
{
  /// Sensor status, part 1 (see graphic below)
  uint8_t sens_status1;
  /// Sensor status, part 2 (see graphic below)
  uint8_t sens_status2;
  /// Observation frequency
  uint8_t freq;
  /// Sensor faults (see graphic below)
  uint8_t faults;
} ublox_msgs__msg__EsfSTATUSSens;

// Struct for a sequence of ublox_msgs__msg__EsfSTATUSSens.
typedef struct ublox_msgs__msg__EsfSTATUSSens__Sequence
{
  ublox_msgs__msg__EsfSTATUSSens * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__EsfSTATUSSens__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__STRUCT_H_

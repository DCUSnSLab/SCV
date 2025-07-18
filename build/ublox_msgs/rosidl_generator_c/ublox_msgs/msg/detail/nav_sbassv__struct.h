// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavSBASSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/NavSBASSV in the package ublox_msgs.
/**
  * see message NavSBAS
 */
typedef struct ublox_msgs__msg__NavSBASSV
{
  /// SV Id
  uint8_t svid;
  /// Flags for this SV
  uint8_t flags;
  /// Monitoring status
  uint8_t udre;
  /// System (WAAS/EGNOS/...), same as SYS
  uint8_t sv_sys;
  /// Services available, same as SERVICE
  uint8_t sv_service;
  /// Reserved
  uint8_t reserved1;
  /// Pseudo Range correction in
  int16_t prc;
  /// Reserved
  uint16_t reserved2;
  /// Ionosphere correction in
  int16_t ic;
} ublox_msgs__msg__NavSBASSV;

// Struct for a sequence of ublox_msgs__msg__NavSBASSV.
typedef struct ublox_msgs__msg__NavSBASSV__Sequence
{
  ublox_msgs__msg__NavSBASSV * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavSBASSV__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__STRUCT_H_

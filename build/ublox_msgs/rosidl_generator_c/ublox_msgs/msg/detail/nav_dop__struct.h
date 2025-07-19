// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavDOP.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DOP__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DOP__STRUCT_H_

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
  ublox_msgs__msg__NavDOP__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavDOP__MESSAGE_ID = 4
};

/// Struct defined in msg/NavDOP in the package ublox_msgs.
/**
  * NAV-DOP (0x01 0x04)
  * Dilution of precision
  *
  * - DOP values are dimensionless.
  * - All DOP values are scaled by a factor of 100. If the unit transmits a value
  *   of e.g. 156, the DOP value is 1.56.
 */
typedef struct ublox_msgs__msg__NavDOP
{
  /// GPS Millisecond Time of Week
  uint32_t i_tow;
  /// Geometric DOP
  uint16_t g_dop;
  /// Position DOP
  uint16_t p_dop;
  /// Time DOP
  uint16_t t_dop;
  /// Vertical DOP
  uint16_t v_dop;
  /// Horizontal DOP
  uint16_t h_dop;
  /// Northing DOP
  uint16_t n_dop;
  /// Easting DOP
  uint16_t e_dop;
} ublox_msgs__msg__NavDOP;

// Struct for a sequence of ublox_msgs__msg__NavDOP.
typedef struct ublox_msgs__msg__NavDOP__Sequence
{
  ublox_msgs__msg__NavDOP * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavDOP__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DOP__STRUCT_H_

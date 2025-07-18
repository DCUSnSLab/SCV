// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/EsfINS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_INS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__ESF_INS__STRUCT_H_

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
  ublox_msgs__msg__EsfINS__CLASS_ID = 16
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__EsfINS__MESSAGE_ID = 21
};

/// Constant 'BITFIELD0_VERSION'.
/**
  * Message version (1 for this version).
 */
enum
{
  ublox_msgs__msg__EsfINS__BITFIELD0_VERSION = 255ul
};

/// Constant 'BITFIELD0_X_ANG_RATE_VALID'.
/**
  * Compensated x-axis angular rate data
  * validity flag
 */
enum
{
  ublox_msgs__msg__EsfINS__BITFIELD0_X_ANG_RATE_VALID = 256ul
};

/// Constant 'BITFIELD0_Y_ANG_RATE_VALID'.
/**
  * Compensated y-axis angular rate data
  * validity flag
 */
enum
{
  ublox_msgs__msg__EsfINS__BITFIELD0_Y_ANG_RATE_VALID = 512ul
};

/// Constant 'BITFIELD0_Z_ANG_RATE_VALID'.
/**
  * Compensated z-axis angular rate data
  * validity flag
 */
enum
{
  ublox_msgs__msg__EsfINS__BITFIELD0_Z_ANG_RATE_VALID = 1024ul
};

/// Constant 'BITFIELD0_X_ACCEL_VALID'.
/**
  * Compensated x-axis acceleration data
  * validity flag
 */
enum
{
  ublox_msgs__msg__EsfINS__BITFIELD0_X_ACCEL_VALID = 2048ul
};

/// Constant 'BITFIELD0_Y_ACCEL_VALID'.
/**
  * Compensated y-axis acceleration data
  * validity flag
 */
enum
{
  ublox_msgs__msg__EsfINS__BITFIELD0_Y_ACCEL_VALID = 4096ul
};

/// Constant 'BITFIELD0_Z_ACCEL_VALID'.
/**
  * Compensated z-axis acceleration data
  * validity flag
 */
enum
{
  ublox_msgs__msg__EsfINS__BITFIELD0_Z_ACCEL_VALID = 8192ul
};

/// Struct defined in msg/EsfINS in the package ublox_msgs.
/**
  * ESF-INS (0x10 0x15)
  * Vehicle dynamics information
  *
  * This message outputs information about vehicle dynamics computed by the
  * Inertial Navigation System (INS) during ESF-based navigation.
  * For ADR products, the output dynamics information (angular rates and
  * accelerations) is expressed with respect to the vehicle-frame.
  * For UDR products, the output dynamics information (angular rates and
  * accelerations) is expressed with respect to the body-frame.
 */
typedef struct ublox_msgs__msg__EsfINS
{
  /// Bitfield (see graphic below)
  uint32_t bitfield0;
  /// Reserved
  uint8_t reserved1[4];
  /// GPS time of week of the navigation epoch
  uint32_t i_tow;
  /// Compensated x-axis angular rate
  int32_t x_ang_rate;
  /// Compensated y-axis angular rate
  int32_t y_ang_rate;
  /// Compensated z-axis angular rate
  int32_t z_ang_rate;
  /// Compensated x-axis acceleration (gravity-free)
  int32_t x_accel;
  /// Compensated y-axis acceleration (gravity-free)
  int32_t y_accel;
  /// Compensated z-axis acceleration (gravity-free)
  int32_t z_accel;
} ublox_msgs__msg__EsfINS;

// Struct for a sequence of ublox_msgs__msg__EsfINS.
typedef struct ublox_msgs__msg__EsfINS__Sequence
{
  ublox_msgs__msg__EsfINS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__EsfINS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_INS__STRUCT_H_

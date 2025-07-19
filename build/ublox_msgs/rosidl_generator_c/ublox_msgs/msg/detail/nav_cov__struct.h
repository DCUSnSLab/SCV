// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavCOV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_COV__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_COV__STRUCT_H_

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
  ublox_msgs__msg__NavCOV__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavCOV__MESSAGE_ID = 54
};

/// Struct defined in msg/NavCOV in the package ublox_msgs.
/**
  * NAV-COV (0x01 0x36)
  * Covariance matrices for position and velocity solutions
 */
typedef struct ublox_msgs__msg__NavCOV
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// Message version (0x00 for this version)
  uint8_t version;
  /// Position covariance matrix validity flag
  uint8_t pos_cov_valid;
  /// Velocity covariance matrix validity flag
  uint8_t vel_cov_valid;
  /// Reserved
  uint8_t reserved_0[9];
  /// Position covariance matrix value p_NN
  float pos_cov_nn;
  /// Position covariance matrix value p_NE
  float pos_cov_ne;
  /// Position covariance matrix value p_ND
  float pos_cov_nd;
  /// Position covariance matrix value p_EE
  float pos_cov_ee;
  /// Position covariance matrix value p_ED
  float pos_cov_ed;
  /// Position covariance matrix value p_DD
  float pos_cov_dd;
  /// Velocity covariance matrix value v_NN
  float vel_cov_nn;
  /// Velocity covariance matrix value v_NE
  float vel_cov_ne;
  /// Velocity covariance matrix value v_ND
  float vel_cov_nd;
  /// Velocity covariance matrix value v_EE
  float vel_cov_ee;
  /// Velocity covariance matrix value v_ED
  float vel_cov_ed;
  /// Velocity covariance matrix value v_DD
  float vel_cov_dd;
} ublox_msgs__msg__NavCOV;

// Struct for a sequence of ublox_msgs__msg__NavCOV.
typedef struct ublox_msgs__msg__NavCOV__Sequence
{
  ublox_msgs__msg__NavCOV * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavCOV__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_COV__STRUCT_H_

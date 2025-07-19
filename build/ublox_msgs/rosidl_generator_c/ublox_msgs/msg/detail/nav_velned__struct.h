// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavVELNED.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__STRUCT_H_

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
  ublox_msgs__msg__NavVELNED__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavVELNED__MESSAGE_ID = 18
};

/// Struct defined in msg/NavVELNED in the package ublox_msgs.
/**
  * NAV-VELNED (0x01 0x12)
  * Velocity Solution in NED
  *
  * See important comments concerning validity of velocity given in section
  * Navigation Output Filters.
 */
typedef struct ublox_msgs__msg__NavVELNED
{
  /// GPS Millisecond time of week
  uint32_t i_tow;
  /// NED north velocity
  int32_t vel_n;
  /// NED east velocity
  int32_t vel_e;
  /// NED down velocity
  int32_t vel_d;
  /// Speed (3-D)
  uint32_t speed;
  /// Ground Speed (2-D)
  uint32_t g_speed;
  /// Heading of motion 2-D
  int32_t heading;
  /// Speed Accuracy Estimate
  uint32_t s_acc;
  /// Course / Heading Accuracy Estimate
  uint32_t c_acc;
} ublox_msgs__msg__NavVELNED;

// Struct for a sequence of ublox_msgs__msg__NavVELNED.
typedef struct ublox_msgs__msg__NavVELNED__Sequence
{
  ublox_msgs__msg__NavVELNED * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavVELNED__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_VELNED__STRUCT_H_

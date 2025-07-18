// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/TimTM2.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__TIM_TM2__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__TIM_TM2__STRUCT_H_

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
  ublox_msgs__msg__TimTM2__CLASS_ID = 13
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__TimTM2__MESSAGE_ID = 3
};

/// Constant 'FLAGS_MODE_RUNNING'.
/**
  * single = 0, running = 1
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_MODE_RUNNING = 1
};

/// Constant 'FLAGS_RUN'.
/**
  * armed = 0, stopped = 1
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_RUN = 2
};

/// Constant 'FLAGS_NEWFALLINGEDGE'.
/**
  * new falling edge detected
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_NEWFALLINGEDGE = 4
};

/// Constant 'FLAGS_TIMEBASE_GNSS'.
/**
  * 0 = time base is receiver time, 1 = time base is GNSS Time (according to the configuration in CFG-TP5 for tpldx= 0)
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_TIMEBASE_GNSS = 8
};

/// Constant 'FLAGS_TIMEBASE_UTC'.
/**
  * Time Base is UTC (the variant according to the configuration in CFG-NAV5
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_TIMEBASE_UTC = 16
};

/// Constant 'FLAGS_UTC_AVAIL'.
/**
  * 0 = utc not available, 1 = utc available
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_UTC_AVAIL = 32
};

/// Constant 'FLAGS_TIME_VALID'.
/**
  * 0 = time is not valid, 1 time is valid
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_TIME_VALID = 64
};

/// Constant 'FLAGS_NEWRISINGEDGE'.
/**
  * new rising edge detected
 */
enum
{
  ublox_msgs__msg__TimTM2__FLAGS_NEWRISINGEDGE = 128
};

/// Struct defined in msg/TimTM2 in the package ublox_msgs.
/**
  * TIM-TM2 (0x0D, 0x03)
  * Time mark data
  *
  * Description for details.
  *
  * Supported on:
  *  - u-blox 8 / u-blox M8 with protocol version 22 (only with Timing Products)
 */
typedef struct ublox_msgs__msg__TimTM2
{
  /// Channel (i.e. EXTINT) upon which the pulse was measured
  uint8_t ch;
  /// Bitmask [newRisingEdge, time, utc, timeBase, , newFallingEdge, run, mode]
  uint8_t flags;
  /// rising edge count
  uint16_t rising_edge_count;
  /// week number of last rising edge
  uint16_t wn_r;
  /// week number of last falling edge
  uint16_t wn_f;
  /// Tow of rising edge
  uint32_t tow_ms_r;
  /// Millisecond Fraction of Tow of rising edge in nanoseconds
  uint32_t tow_sub_ms_r;
  /// tow of falling edge
  uint32_t tow_ms_f;
  /// millisecond fraction of tow of falling edge in nanoseconds
  uint32_t tow_sub_ms_f;
  /// Accuracy estimate
  uint32_t acc_est;
} ublox_msgs__msg__TimTM2;

// Struct for a sequence of ublox_msgs__msg__TimTM2.
typedef struct ublox_msgs__msg__TimTM2__Sequence
{
  ublox_msgs__msg__TimTM2 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__TimTM2__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__TIM_TM2__STRUCT_H_

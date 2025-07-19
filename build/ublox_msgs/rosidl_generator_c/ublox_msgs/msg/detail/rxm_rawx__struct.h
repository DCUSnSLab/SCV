// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmRAWX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__STRUCT_H_

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
  ublox_msgs__msg__RxmRAWX__CLASS_ID = 2
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__RxmRAWX__MESSAGE_ID = 21
};

/// Constant 'REC_STAT_LEAP_SEC'.
/**
  * Leap seconds have been determined
 */
enum
{
  ublox_msgs__msg__RxmRAWX__REC_STAT_LEAP_SEC = 1
};

/// Constant 'REC_STAT_CLK_RESET'.
/**
  * Clock reset applied. Typically the receiver
  * clock is changed in increments of integer
  * milliseconds.
 */
enum
{
  ublox_msgs__msg__RxmRAWX__REC_STAT_CLK_RESET = 2
};

// Include directives for member types
// Member 'meas'
#include "ublox_msgs/msg/detail/rxm_rawx_meas__struct.h"

/// Struct defined in msg/RxmRAWX in the package ublox_msgs.
/**
  * RXM-RAWX (0x02 0x15)
  * Multi-GNSS Raw Measurement Data
  *
  * This message contains the information needed to be able to generate a RINEX 3
  * multi-GNSS observation file.
  * This message contains pseudorange, Doppler, carrier phase, phase lock and
  * signal quality information for GNSS satellites once signals have been
  * synchronized. This message supports all active GNSS.
 */
typedef struct ublox_msgs__msg__RxmRAWX
{
  /// Measurement time of week in receiver local time
  /// approximately aligned to the GPS time system. The
  /// receiver local time of week number and leap second
  /// information can be used to translate the time to other
  /// time systems. More information about the difference in
  /// time systems can be found in RINEX 3 documentation.
  /// For a receiver operating in GLONASS only mode, UTC
  /// time can be determined by subtracting the leapS field
  /// from GPS time regardless of whether the GPS leap
  /// seconds are valid.
  double rcv_tow;
  /// GPS week number in receiver local time.
  uint16_t week;
  /// GPS leap seconds (GPS-UTC).
  /// This field represents the receiver's best knowledge of
  /// the leap seconds offset. A flag is given in the
  /// recStat bitfield to indicate if the leap seconds
  /// are known.
  int8_t leap_s;
  /// # of measurements to follow
  uint8_t num_meas;
  /// Receiver tracking status bitfield
  uint8_t rec_stat;
  /// Message version (0x01 for this version).
  uint8_t version;
  /// Reserved
  uint8_t reserved1[2];
  ublox_msgs__msg__RxmRAWXMeas__Sequence meas;
} ublox_msgs__msg__RxmRAWX;

// Struct for a sequence of ublox_msgs__msg__RxmRAWX.
typedef struct ublox_msgs__msg__RxmRAWX__Sequence
{
  ublox_msgs__msg__RxmRAWX * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmRAWX__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__STRUCT_H_

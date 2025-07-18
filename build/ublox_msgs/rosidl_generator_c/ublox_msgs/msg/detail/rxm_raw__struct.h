// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmRAW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAW__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAW__STRUCT_H_

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
  ublox_msgs__msg__RxmRAW__CLASS_ID = 2
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__RxmRAW__MESSAGE_ID = 16
};

// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/rxm_rawsv__struct.h"

/// Struct defined in msg/RxmRAW in the package ublox_msgs.
/**
  * RXM-RAW (0x02 0x10)
  * Raw Measurement Data
  *
  * Supported up to ublox 7 firmware. See RxmRAWX for ublox 8
  * This message contains all information needed to be able to generate a RINEX
  * observation file.
  * This message outputs pseudorange, doppler and carrier phase measurements for
  * GPS satellites once signals have been synchronised. No other GNSS types are
  * currently supported.
 */
typedef struct ublox_msgs__msg__RxmRAW
{
  /// Measurement time of week in receiver local time
  int32_t rcv_tow;
  /// Measurement week number in receiver local time
  int16_t week;
  /// # of satellites following
  uint8_t num_sv;
  /// Reserved
  uint8_t reserved1;
  /// numSV times
  ublox_msgs__msg__RxmRAWSV__Sequence sv;
} ublox_msgs__msg__RxmRAW;

// Struct for a sequence of ublox_msgs__msg__RxmRAW.
typedef struct ublox_msgs__msg__RxmRAW__Sequence
{
  ublox_msgs__msg__RxmRAW * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmRAW__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAW__STRUCT_H_

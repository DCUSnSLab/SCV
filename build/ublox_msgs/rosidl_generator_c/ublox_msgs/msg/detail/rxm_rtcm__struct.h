// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmRTCM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__STRUCT_H_

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
  ublox_msgs__msg__RxmRTCM__CLASS_ID = 2
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__RxmRTCM__MESSAGE_ID = 50
};

/// Constant 'FLAGS_CRC_FAILED'.
/**
  * 0 when RTCM message received and passed CRC
  * check, 1 when failed in which case refStation
  * and msgType might be corrupted and misleading
 */
enum
{
  ublox_msgs__msg__RxmRTCM__FLAGS_CRC_FAILED = 1
};

/// Struct defined in msg/RxmRTCM in the package ublox_msgs.
/**
  * RXM-RTCM (0x02 0x32)
  * RTCM input status
  *
  * Output upon processing of an RTCM input message
  * Supported on:
  * - u-blox 8 / u-blox M8 from protocol version 20.01 up to version 23.01
 */
typedef struct ublox_msgs__msg__RxmRTCM
{
  /// Message version (0x02 for this version)
  uint8_t version;
  /// RTCM input status flags
  uint8_t flags;
  /// Reserved
  uint8_t reserved0[2];
  /// Reference station ID
  uint16_t ref_station;
  /// Message type
  uint16_t msg_type;
} ublox_msgs__msg__RxmRTCM;

// Struct for a sequence of ublox_msgs__msg__RxmRTCM.
typedef struct ublox_msgs__msg__RxmRTCM__Sequence
{
  ublox_msgs__msg__RxmRTCM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmRTCM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__STRUCT_H_

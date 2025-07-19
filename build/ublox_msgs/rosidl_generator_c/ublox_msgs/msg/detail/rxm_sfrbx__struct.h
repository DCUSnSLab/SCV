// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmSFRBX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__STRUCT_H_

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
  ublox_msgs__msg__RxmSFRBX__CLASS_ID = 2
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__RxmSFRBX__MESSAGE_ID = 19
};

// Include directives for member types
// Member 'dwrd'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RxmSFRBX in the package ublox_msgs.
/**
  * RXM-SFRB (0x02 0x13)
  * Subframe Buffer
  *
  * This message reports a complete subframe of broadcast navigation data decoded
  * from a single signal. The number of data words reported in each message
  * depends on the nature of the signal. See the section on Broadcast Navigation
  * Data for further details.
 */
typedef struct ublox_msgs__msg__RxmSFRBX
{
  /// GNSS identifier (see Cfg GNSS for constants)
  uint8_t gnss_id;
  /// Satellite identifier within corresponding GNSS system
  uint8_t sv_id;
  /// Reserved
  uint8_t reserved0;
  /// Only used for GLONASS: This is the frequency
  /// slot + 7 (range from 0 to 13)
  uint8_t freq_id;
  /// The number of data words contained in this message (up
  /// to 10, for currently supported signals)
  uint8_t num_words;
  /// The tracking channel number the message was received
  /// on
  uint8_t chn;
  /// Message version, (0x02 for this version)
  uint8_t version;
  /// Reserved
  uint8_t reserved1;
  /// Start of repeated block (numWords times)
  /// The data words
  rosidl_runtime_c__uint32__Sequence dwrd;
} ublox_msgs__msg__RxmSFRBX;

// Struct for a sequence of ublox_msgs__msg__RxmSFRBX.
typedef struct ublox_msgs__msg__RxmSFRBX__Sequence
{
  ublox_msgs__msg__RxmSFRBX * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmSFRBX__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__STRUCT_H_

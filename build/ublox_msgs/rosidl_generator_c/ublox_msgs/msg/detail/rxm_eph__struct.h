// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmEPH.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_EPH__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_EPH__STRUCT_H_

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
  ublox_msgs__msg__RxmEPH__CLASS_ID = 2
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__RxmEPH__MESSAGE_ID = 49
};

// Include directives for member types
// Member 'sf1d'
// Member 'sf2d'
// Member 'sf3d'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RxmEPH in the package ublox_msgs.
/**
  * RXM-EPH (0x02 0x31)
  * GPS Aiding Ephemeris Input/Output Message
  *
  * This message is provided considered obsolete, please use AID-EPH instead!
  * - SF1D0 to SF3D7 is only sent if ephemeris is available for this SV. If not, 
  *   the payload may be reduced to 8 Bytes, or all bytes are set to zero, 
  *   indicating that this SV Number does not have valid ephemeris for the moment.
  * - SF1D0 to SF3D7 contain the 24 words following the Hand-Over Word ( HOW ) 
  *   from the GPS navigation message, subframes 1 to 3. See IS-GPS-200 for a 
  *   full description of the contents of the Subframes.
  * - In SF1D0 to SF3D7, the parity bits have been removed, and the 24 bits of 
  *   data are located in Bits 0 to 23. Bits 24 to 31 shall be ignored.
 */
typedef struct ublox_msgs__msg__RxmEPH
{
  /// SV ID for which this ephemeris data is (Valid Range: 1 .. 32).
  uint32_t svid;
  /// Hand-Over Word of first Subframe. This is
  /// required if data is sent to the receiver.
  /// 0 indicates that no Ephemeris Data is following.
  uint32_t how;
  /// Start of optional block
  /// Subframe 1 Words 3..10 (SF1D0..SF1D7)
  rosidl_runtime_c__uint32__Sequence sf1d;
  /// Subframe 2 Words 3..10 (SF2D0..SF2D7)
  rosidl_runtime_c__uint32__Sequence sf2d;
  /// Subframe 3 Words 3..10 (SF3D0..SF3D7)
  rosidl_runtime_c__uint32__Sequence sf3d;
} ublox_msgs__msg__RxmEPH;

// Struct for a sequence of ublox_msgs__msg__RxmEPH.
typedef struct ublox_msgs__msg__RxmEPH__Sequence
{
  ublox_msgs__msg__RxmEPH * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmEPH__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_EPH__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmALM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_ALM__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_ALM__STRUCT_H_

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
  ublox_msgs__msg__RxmALM__CLASS_ID = 2
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__RxmALM__MESSAGE_ID = 48
};

// Include directives for member types
// Member 'dwrd'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RxmALM in the package ublox_msgs.
/**
  * RXM-ALM (0x02 0x30)
  * GPS Aiding Almanach Input/Output Message
  *
  * This message is provided considered obsolete, please use AID-ALM instead!
  * - If the WEEK Value is 0, DWRD0 to DWRD7 are not sent as the almanach is not 
  *   available for the given SV.
  * - DWORD0 to DWORD7 contain the 8 words following the Hand-Over Word ( HOW )
  *   from the GPS navigation message, either pages 1 to 24 of sub-frame 5 or 
  *   pages 2 to 10 of subframe 4. See IS-GPS-200 for a full description of the 
  *   contents of the Almanac pages.
  * - In DWORD0 to DWORD7, the parity bits have been removed, and the 24 bits of 
  *   data are located in Bits 0 to 23. Bits 24 to 31 shall be ignored.
  * - Example: Parameter e (Eccentricity) from Almanach Subframe 4/5, Word 3, 
  *   Bits 69-84 within the subframe can be found in DWRD0, Bits 15-0 whereas 
  *   Bit 0 is the LSB.
 */
typedef struct ublox_msgs__msg__RxmALM
{
  /// SV ID for which this Almanach Data is
  /// (Valid Range: 1 .. 32 or 51, 56, 63).
  uint32_t svid;
  /// Issue Date of Almanach (GPS week number)
  uint32_t week;
  /// Start of optional block
  /// Almanach Words
  rosidl_runtime_c__uint32__Sequence dwrd;
} ublox_msgs__msg__RxmALM;

// Struct for a sequence of ublox_msgs__msg__RxmALM.
typedef struct ublox_msgs__msg__RxmALM__Sequence
{
  ublox_msgs__msg__RxmALM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmALM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_ALM__STRUCT_H_

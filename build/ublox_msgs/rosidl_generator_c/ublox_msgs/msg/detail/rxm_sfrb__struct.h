// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmSFRB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__STRUCT_H_

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
  ublox_msgs__msg__RxmSFRB__CLASS_ID = 2
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__RxmSFRB__MESSAGE_ID = 17
};

/// Struct defined in msg/RxmSFRB in the package ublox_msgs.
/**
  * RXM-SFRB (0x02 0x11)
  * Subframe Buffer
  *
  * The content of one single subframe buffer
  * For GPS satellites, the 10 dwrd values contain the parity checked subframe 
  * data for 10 Words. Each dwrd has 24 Bits with valid data (Bits 23 to 0). The 
  * remaining 8 bits (31 to 24) have an undefined value. The direction within the 
  * Word is that the higher order bits are received from the SV first. Example: 
  * The Preamble can be found in dwrd[0], at bit position 23 down to 16. For more 
  * details on the data format please refer to the ICD-GPS-200C
  * Interface document.
  * For SBAS satellites, the 250 Bit message block can be found in dwrd[0] to 
  * dwrd[6] for the first 224 bits. The remaining 26 bits are in dwrd[7], whereas
  * Bits 25 and 24 are the last two data bits, and Bits 23 down to 0 are the
  * parity bits. For more information on SBAS data format, please refer to 
  * RTCA/DO-229C (MOPS), Appendix A.
 */
typedef struct ublox_msgs__msg__RxmSFRB
{
  /// Channel Number
  uint8_t chn;
  /// ID of Satellite transmitting Subframe
  uint8_t svid;
  /// Words of Data
  uint32_t dwrd[10];
} ublox_msgs__msg__RxmSFRB;

// Struct for a sequence of ublox_msgs__msg__RxmSFRB.
typedef struct ublox_msgs__msg__RxmSFRB__Sequence
{
  ublox_msgs__msg__RxmSFRB * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmSFRB__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__STRUCT_H_

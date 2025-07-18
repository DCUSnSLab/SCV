// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/RxmRAWXMeas.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TRK_STAT_PR_VALID'.
/**
  * Pseudorange valid
 */
enum
{
  ublox_msgs__msg__RxmRAWXMeas__TRK_STAT_PR_VALID = 1
};

/// Constant 'TRK_STAT_CP_VALID'.
/**
  * Carrier phase valid
 */
enum
{
  ublox_msgs__msg__RxmRAWXMeas__TRK_STAT_CP_VALID = 2
};

/// Constant 'TRK_STAT_HALF_CYC'.
/**
  * Half cycle valid
 */
enum
{
  ublox_msgs__msg__RxmRAWXMeas__TRK_STAT_HALF_CYC = 4
};

/// Constant 'TRK_STAT_SUB_HALF_CYC'.
/**
  * Half cycle subtracted from phase
 */
enum
{
  ublox_msgs__msg__RxmRAWXMeas__TRK_STAT_SUB_HALF_CYC = 8
};

/// Struct defined in msg/RxmRAWXMeas in the package ublox_msgs.
/**
  * see message RxmRAWX
 */
typedef struct ublox_msgs__msg__RxmRAWXMeas
{
  /// Pseudorange measurement. GLONASS inter frequency
  /// channel delays are compensated with an internal
  /// calibration table.
  double pr_mes;
  /// Carrier phase measurement. The carrier
  /// phase initial ambiguity is initialized using an
  /// approximate value to make the magnitude of
  /// the phase close to the pseudorange
  /// measurement. Clock resets are applied to both
  /// phase and code measurements in accordance
  /// with the RINEX specification.
  double cp_mes;
  /// Doppler measurement (positive sign for
  /// approaching satellites)
  float do_mes;
  /// GNSS identifier (see CfgGNSS for constants)
  uint8_t gnss_id;
  /// Satellite identifier (see Satellite Numbering)
  uint8_t sv_id;
  /// Reserved
  uint8_t reserved0;
  /// Only used for GLONASS: This is the frequency
  /// slot + 7 (range from 0 to 13)
  uint8_t freq_id;
  /// Carrier phase locktime counter
  /// (maximum 64500 ms)
  uint16_t locktime;
  /// Carrier-to-noise density ratio (signal strength)
  /// [dB-Hz]
  int8_t cno;
  /// Estimated pseudorange measurement standard
  /// deviation
  uint8_t pr_stdev;
  /// Estimated carrier phase measurement standard
  /// deviation (note a raw value of 0x0F indicates the
  /// value is invalid)
  uint8_t cp_stdev;
  /// Estimated Doppler measurement standard deviation
  /// [Hz / 0.002*2^n]
  uint8_t do_stdev;
  /// Tracking status bitfield
  uint8_t trk_stat;
  /// Reserved
  uint8_t reserved1;
} ublox_msgs__msg__RxmRAWXMeas;

// Struct for a sequence of ublox_msgs__msg__RxmRAWXMeas.
typedef struct ublox_msgs__msg__RxmRAWXMeas__Sequence
{
  ublox_msgs__msg__RxmRAWXMeas * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__RxmRAWXMeas__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__STRUCT_H_

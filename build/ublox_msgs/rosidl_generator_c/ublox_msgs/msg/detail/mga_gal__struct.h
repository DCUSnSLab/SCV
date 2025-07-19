// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/MgaGAL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MGA_GAL__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__MGA_GAL__STRUCT_H_

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
  ublox_msgs__msg__MgaGAL__CLASS_ID = 19
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__MgaGAL__MESSAGE_ID = 2
};

/// Struct defined in msg/MgaGAL in the package ublox_msgs.
/**
  * MGA-GAL (0x13 0x02)
  * Galileo Ephemeris Assistance
  *
  * This message allows the delivery of Galileo ephemeris assistance to a
  * receiver. See the description of AssistNow Online for details.
 */
typedef struct ublox_msgs__msg__MgaGAL
{
  /// Message type (0x01 for this type)
  uint8_t type;
  /// Message version (0x00 for this version)
  uint8_t version;
  /// Galileo Satellite identifier
  uint8_t svid;
  /// Reserved
  uint8_t reserved0;
  /// Ephemeris and clock correction issue of Data
  uint16_t iod_nav;
  /// Mean motion difference from computed value
  /// [semi-cir cles/s * 2^-43]
  int16_t delta_n;
  /// Mean anomaly at reference time
  int32_t m0;
  /// Eccentricity
  uint32_t e;
  /// Square root of the semi-major axis
  uint32_t sqrt_a;
  /// Longitude of ascending node of orbital plane at weekly
  /// epoch
  int32_t omega0;
  /// inclination angle at reference time
  /// [semi-cir cles 2^-31]
  int32_t i0;
  /// Argument of perigee
  int32_t omega;
  /// Rate of change of right ascension
  /// [semi-cir cles/s 2^-43]
  int32_t omega_dot;
  /// Rate of change of inclination angle
  /// [semi-cir cles/s 2^-43]
  int16_t i_dot;
  /// Amplitude of the cosine harmonic correction term to
  /// the argument of latitude
  int16_t cuc;
  /// Amplitude of the sine harmonic correction term to
  /// the argument of latitude
  int16_t cus;
  /// Amplitude of the cosine harmonic correction term
  /// to the orbit radius
  int16_t crc;
  /// Amplitude of the sine harmonic correction term to the
  /// orbit radius
  int16_t crs;
  /// Amplitude of the cosine harmonic correction term to
  /// the angle of inclination
  int16_t cic;
  /// Amplitude of the sine harmonic correction term to the
  /// angle of inclination
  int16_t cis;
  /// Ephemeris reference time
  uint16_t toe;
  /// clock bias correction coefficient
  int32_t af0;
  /// SV clock drift correction coefficient
  int32_t af1;
  /// SV clock drift rate correction coefficient
  /// [s/s^2 * 2^-59]
  int8_t af2;
  /// Signal-in-Space Accuracy index for dual frequency
  /// E1-E5b
  uint8_t sisaindex_e1_e5b;
  /// Clock correction data reference Time of Week
  uint16_t toc;
  /// E1-E5b Broadcast Group Delay
  int16_t bgd_e1_e5b;
  /// Reserved
  uint8_t reserved1[2];
  /// E1-B Signal Health Status
  uint8_t health_e1b;
  /// E1-B Data Validity Status
  uint8_t data_validity_e1b;
  /// E5b Signal Health Status
  uint8_t health_e5b;
  /// E5b Data Validity Status
  uint8_t data_validity_e5b;
  /// Reserved
  uint8_t reserved2[4];
} ublox_msgs__msg__MgaGAL;

// Struct for a sequence of ublox_msgs__msg__MgaGAL.
typedef struct ublox_msgs__msg__MgaGAL__Sequence
{
  ublox_msgs__msg__MgaGAL * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__MgaGAL__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__MGA_GAL__STRUCT_H_

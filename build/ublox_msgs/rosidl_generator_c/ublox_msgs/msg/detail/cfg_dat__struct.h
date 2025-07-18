// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgDAT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_DAT__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_DAT__STRUCT_H_

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
  ublox_msgs__msg__CfgDAT__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgDAT__MESSAGE_ID = 6
};

/// Constant 'DATUM_NUM_WGS84'.
enum
{
  ublox_msgs__msg__CfgDAT__DATUM_NUM_WGS84 = 0
};

/// Constant 'DATUM_NUM_USER'.
enum
{
  ublox_msgs__msg__CfgDAT__DATUM_NUM_USER = 65535
};

/// Struct defined in msg/CfgDAT in the package ublox_msgs.
/**
  * CFG-DAT (0x06 0x06)
  * Set User-defined Datum
  *
  * For more information see the description of Geodetic Systems and Frames.
 */
typedef struct ublox_msgs__msg__CfgDAT
{
  /// Only for GET, these values are not used for write
  /// Datum Number: 0 = WGS84, 0xFFFF = user-defined
  uint16_t datum_num;
  /// ASCII String: WGS84 or USER
  uint8_t datum_name[6];
  /// Semi-major Axis
  /// accepted range = 6,300,000.0 to 6,500,000.0 meters
  double maj_a;
  /// 1.0 / Flattening
  /// accepted range is 0.0 to 500.0
  double flat;
  /// X Axis shift at the origin
  /// accepted range is +/- 5000.0 meters
  float d_x;
  /// Y Axis shift at the origin
  /// accepted range is +/- 5000.0 meters
  float d_y;
  /// Z Axis shift at the origin
  /// accepted range is +/- 5000.0 meters
  float d_z;
  /// Rotation about the X Axis
  /// accepted range is +/- 20.0 milli-arc seconds
  float rot_x;
  /// Rotation about the Y Axis
  /// accepted range is +/- 20.0 milli-arc seconds
  float rot_y;
  /// Rotation about the Z Axis
  /// accepted range is +/- 20.0 milli-arc seconds
  float rot_z;
  /// Scale change
  /// accepted range is 0.0 to 50.0 parts per million
  float scale;
} ublox_msgs__msg__CfgDAT;

// Struct for a sequence of ublox_msgs__msg__CfgDAT.
typedef struct ublox_msgs__msg__CfgDAT__Sequence
{
  ublox_msgs__msg__CfgDAT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgDAT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_DAT__STRUCT_H_

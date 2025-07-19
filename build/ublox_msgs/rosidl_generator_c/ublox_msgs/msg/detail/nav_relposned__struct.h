// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavRELPOSNED.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__STRUCT_H_

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
  ublox_msgs__msg__NavRELPOSNED__CLASS_ID = 1
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__NavRELPOSNED__MESSAGE_ID = 60
};

/// Constant 'FLAGS_GNSS_FIX_OK'.
/**
  * A valid fix (i.e within DOP & accuracy
  * masks)
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_GNSS_FIX_OK = 1ul
};

/// Constant 'FLAGS_DIFF_SOLN'.
/**
  * Set if differential corrections were applied
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_DIFF_SOLN = 2ul
};

/// Constant 'FLAGS_REL_POS_VALID'.
/**
  * Set if relative position components and
  * accuracies are valid
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_REL_POS_VALID = 4ul
};

/// Constant 'FLAGS_CARR_SOLN_MASK'.
/**
  * Carrier phase range solution status:
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_CARR_SOLN_MASK = 24ul
};

/// Constant 'FLAGS_CARR_SOLN_NONE'.
/**
  * No carrier phase range solution
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_CARR_SOLN_NONE = 0ul
};

/// Constant 'FLAGS_CARR_SOLN_FLOAT'.
/**
  * Float solution. No fixed integer carrier
  * phase measurements have been used to
  * calculate the solution
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_CARR_SOLN_FLOAT = 8ul
};

/// Constant 'FLAGS_CARR_SOLN_FIXED'.
/**
  * Fixed solution. One or more fixed
  * integer carrier phase range measurements
  * have been used to calculate the solution
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_CARR_SOLN_FIXED = 16ul
};

/// Constant 'FLAGS_IS_MOVING'.
/**
  * if the receiver is operating in moving
  * baseline mode (not supported in protocol
  * versions less than 20.3)
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_IS_MOVING = 32ul
};

/// Constant 'FLAGS_REF_POS_MISS'.
/**
  * Set if extrapolated reference position was
  * used to compute moving baseline solution
  * this epoch (not supported in protocol
  * versions less than 20.3)
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_REF_POS_MISS = 64ul
};

/// Constant 'FLAGS_REF_OBS_MISS'.
/**
  * Set if extrapolated reference observations
  * were used to compute moving baseline
  * solution this epoch (not supported in
  * protocol versions less than 20.3)
 */
enum
{
  ublox_msgs__msg__NavRELPOSNED__FLAGS_REF_OBS_MISS = 128ul
};

/// Struct defined in msg/NavRELPOSNED in the package ublox_msgs.
/**
  * NAV-RELPOSNED (0x01 0x3C)
  * Relative Positioning Information in NED frame
  *
  * The NED frame is defined as the local topological system at the reference
  * station. The relative position vector components in this message, along with
  * their associated accuracies, are given in that local topological system
  * This message contains the relative position vector from the Reference Station
  * to the Rover, including accuracy figures, in the local topological system
  * defined at the reference station
  *
  * Supported on:
  *  - u-blox 8 / u-blox M8 from protocol version 20 up to version 23.01 (only
  *    with High Precision GNSS products)
 */
typedef struct ublox_msgs__msg__NavRELPOSNED
{
  /// Message version (0x00 for this version)
  uint8_t version;
  /// Reserved
  uint8_t reserved0;
  /// Reference Station ID. Must be in the range
  /// 0..4095
  uint16_t ref_station_id;
  /// GPS time of week of the navigation epoch
  /// [ms]
  uint32_t i_tow;
  /// North component of relative position vector
  /// [cm]
  int32_t rel_pos_n;
  /// East component of relative position vector
  /// [cm]
  int32_t rel_pos_e;
  /// Down component of relative position vector
  /// [cm]
  int32_t rel_pos_d;
  /// High-precision North component of relative
  /// position vector.
  /// Must be in the range -99 to +99.
  /// The full North component of the relative
  /// position vector, in units of cm, is given by
  /// relPosN + (relPosHPN * 1e-2)
  int8_t rel_pos_hpn;
  /// High-precision East component of relative
  /// position vector.
  /// Must be in the range -99 to +99.
  /// The full East component of the relative
  /// position vector, in units of cm, is given by
  /// relPosE + (relPosHPE * 1e-2)
  int8_t rel_pos_hpe;
  /// High-precision Down component of relative
  /// position vector.
  /// Must be in the range -99 to +99.
  /// The full Down component of the relative
  /// position vector, in units of cm, is given by
  /// relPosD + (relPosHPD * 1e-2)
  int8_t rel_pos_hpd;
  /// Reserved
  uint8_t reserved1;
  /// Accuracy of relative position North
  /// component
  uint32_t acc_n;
  /// Accuracy of relative position East component
  /// [0.1 mm]
  uint32_t acc_e;
  /// Accuracy of relative position Down component
  /// [0.1 mm]
  uint32_t acc_d;
  uint32_t flags;
} ublox_msgs__msg__NavRELPOSNED;

// Struct for a sequence of ublox_msgs__msg__NavRELPOSNED.
typedef struct ublox_msgs__msg__NavRELPOSNED__Sequence
{
  ublox_msgs__msg__NavRELPOSNED * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavRELPOSNED__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__STRUCT_H_

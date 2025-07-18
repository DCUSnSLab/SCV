// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgUSB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_USB__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_USB__STRUCT_H_

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
  ublox_msgs__msg__CfgUSB__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgUSB__MESSAGE_ID = 27
};

/// Constant 'FLAGS_RE_ENUM'.
/**
  * force re-enumeration
 */
enum
{
  ublox_msgs__msg__CfgUSB__FLAGS_RE_ENUM = 0
};

/// Constant 'FLAGS_POWER_MODE'.
/**
  * self-powered (1), bus-powered (0)
 */
enum
{
  ublox_msgs__msg__CfgUSB__FLAGS_POWER_MODE = 2
};

/// Struct defined in msg/CfgUSB in the package ublox_msgs.
/**
  * UBX-CFG-USB (0x06 0x1B)
  * USB Configuration
 */
typedef struct ublox_msgs__msg__CfgUSB
{
  /// Only set to registered Vendor IDs.
  /// Changing this field requires special Host drivers.
  uint16_t vendor_id;
  /// Product ID. Changing this field requires special
  /// Host drivers.
  uint16_t product_id;
  /// Reserved
  uint8_t reserved1[2];
  /// Reserved
  uint8_t reserved2[2];
  /// Power consumed by the device
  uint16_t power_consumption;
  /// various configuration flags (see graphic below)
  uint16_t flags;
  /// String containing the vendor name.
  /// 32 ASCII bytes including 0-termination.
  int8_t vendor_string[32];
  /// String containing the product name.
  /// 32 ASCII bytes including 0-termination.
  int8_t product_string[32];
  /// String containing the serial number.
  /// 32 ASCII bytes including 0-termination.
  /// Changing the String fields requires special Host
  /// drivers.
  int8_t serial_number[32];
} ublox_msgs__msg__CfgUSB;

// Struct for a sequence of ublox_msgs__msg__CfgUSB.
typedef struct ublox_msgs__msg__CfgUSB__Sequence
{
  ublox_msgs__msg__CfgUSB * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgUSB__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_USB__STRUCT_H_

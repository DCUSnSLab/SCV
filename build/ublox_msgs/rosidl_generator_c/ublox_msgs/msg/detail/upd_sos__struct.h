// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/UpdSOS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__UPD_SOS__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__UPD_SOS__STRUCT_H_

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
  ublox_msgs__msg__UpdSOS__CLASS_ID = 9
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__UpdSOS__MESSAGE_ID = 20
};

/// Constant 'CMD_FLASH_BACKUP_CREATE'.
/**
  * The host can send this message in order to save part of the BBR memory in a
  * file in flash file system. The feature is designed in order to emulate the
  * presence of the backup battery even if it is not present; the host can issue
  * the save on shutdown command before switching off the device supply. It is
  * recommended to issue a GNSS stop command before, in order to keep the BBR
  * memory content consistent.
  * Create Backup File in Flash
 */
enum
{
  ublox_msgs__msg__UpdSOS__CMD_FLASH_BACKUP_CREATE = 0
};

/// Constant 'CMD_FLASH_BACKUP_CLEAR'.
/**
  * The host can send this message in order to erase the backup file present in
  * flash. It is recommended that the clear operation is issued after the host has
  * received the notification that the memory has been restored after a reset.
  * Alternatively the host can parse the startup string 'Restored data saved on
  * shutdown' or poll the UBX-UPD-SOS message for getting the status.
  * Clear Backup File in Flash
 */
enum
{
  ublox_msgs__msg__UpdSOS__CMD_FLASH_BACKUP_CLEAR = 1
};

/// Struct defined in msg/UpdSOS in the package ublox_msgs.
/**
  * UPD-SOS (0x09 0x14)
  *
  * Firmware Supported on:
  * u-blox 8 / u-blox M8 from protocol version 15 up to version 23.01
 */
typedef struct ublox_msgs__msg__UpdSOS
{
  /// Command
  uint8_t cmd;
  /// Reserved
  uint8_t reserved1[3];
} ublox_msgs__msg__UpdSOS;

// Struct for a sequence of ublox_msgs__msg__UpdSOS.
typedef struct ublox_msgs__msg__UpdSOS__Sequence
{
  ublox_msgs__msg__UpdSOS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__UpdSOS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__UPD_SOS__STRUCT_H_

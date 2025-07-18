// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/UpdSOSAck.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__STRUCT_H_

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
  ublox_msgs__msg__UpdSOSAck__CLASS_ID = 9
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__UpdSOSAck__MESSAGE_ID = 20
};

/// Constant 'CMD_BACKUP_CREATE_ACK'.
/**
  * Backup File Creation Acknowledge
  * The message is sent from the device as
  * confirmation of creation of a backup file
  * in flash. The host can safely shut down the
  * device after received this message.
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__CMD_BACKUP_CREATE_ACK = 2
};

/// Constant 'CMD_SYSTEM_RESTORED'.
/**
  * System Restored from Backup
  * The message is sent from the device to
  * notify the host the BBR has been restored
  * from a backup file in flash. The host
  * should clear the backup file after
  * receiving this message. If the UBX-UPD-SOS
  * message is polled, this message will be
  * present.
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__CMD_SYSTEM_RESTORED = 3
};

/// Constant 'BACKUP_CREATE_NACK'.
/**
  * Not acknowledged
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__BACKUP_CREATE_NACK = 0
};

/// Constant 'BACKUP_CREATE_ACK'.
/**
  * Acknowledged
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__BACKUP_CREATE_ACK = 1
};

/// Constant 'SYSTEM_RESTORED_RESPONSE_UNKNOWN'.
/**
  * Unknown
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__SYSTEM_RESTORED_RESPONSE_UNKNOWN = 0
};

/// Constant 'SYSTEM_RESTORED_RESPONSE_FAILED'.
/**
  * Failed restoring from backup
  * file
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__SYSTEM_RESTORED_RESPONSE_FAILED = 1
};

/// Constant 'SYSTEM_RESTORED_RESPONSE_RESTORED'.
/**
  * Restored from backup file
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__SYSTEM_RESTORED_RESPONSE_RESTORED = 2
};

/// Constant 'SYSTEM_RESTORED_RESPONSE_NOT_RESTORED'.
/**
  * Not restored (no backup)
 */
enum
{
  ublox_msgs__msg__UpdSOSAck__SYSTEM_RESTORED_RESPONSE_NOT_RESTORED = 3
};

/// Struct defined in msg/UpdSOSAck in the package ublox_msgs.
/**
  * UPD-SOS (0x09 0x14)
  *
  * Backup File Creation Acknowledge / System Restored from Backup
  *
  * Firmware Supported on:
  * u-blox 8 / u-blox M8 from protocol version 15 up to version 23.01
 */
typedef struct ublox_msgs__msg__UpdSOSAck
{
  /// Command
  uint8_t cmd;
  /// Reserved
  uint8_t reserved0[3];
  /// Response:
  uint8_t response;
  /// Reserved
  uint8_t reserved1[3];
} ublox_msgs__msg__UpdSOSAck;

// Struct for a sequence of ublox_msgs__msg__UpdSOSAck.
typedef struct ublox_msgs__msg__UpdSOSAck__Sequence
{
  ublox_msgs__msg__UpdSOSAck * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__UpdSOSAck__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__STRUCT_H_

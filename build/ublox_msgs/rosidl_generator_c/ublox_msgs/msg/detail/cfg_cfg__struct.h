// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgCFG.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_CFG__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_CFG__STRUCT_H_

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
  ublox_msgs__msg__CfgCFG__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgCFG__MESSAGE_ID = 9
};

/// Constant 'MASK_IO_PORT'.
/**
  * Communications port settings. Modifying this
  * sub-section results in an IO system reset.
  * Because of this undefined data may be output
  * for a short period of time after receiving the
  * message.
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_IO_PORT = 1ul
};

/// Constant 'MASK_MSG_CONF'.
/**
  * Message Configuration
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_MSG_CONF = 2ul
};

/// Constant 'MASK_INF_MSG'.
/**
  * INF Message Configuration
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_INF_MSG = 4ul
};

/// Constant 'MASK_NAV_CONF'.
/**
  * Navigation Configuration
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_NAV_CONF = 8ul
};

/// Constant 'MASK_RXM_CONF'.
/**
  * Receiver Manager Configuration
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_RXM_CONF = 16ul
};

/// Constant 'MASK_SEN_CONF'.
/**
  * Sensor Interface Configuration, protocol >= 19
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_SEN_CONF = 256ul
};

/// Constant 'MASK_RINV_CONF'.
/**
  * Remote Inventory Configuration
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_RINV_CONF = 512ul
};

/// Constant 'MASK_ANT_CONF'.
/**
  * Antenna Configuration
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_ANT_CONF = 1024ul
};

/// Constant 'MASK_LOG_CONF'.
/**
  * Logging Configuration
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_LOG_CONF = 2048ul
};

/// Constant 'MASK_FTS_CONF'.
/**
  * FTS Configuration. Only applicable to the
  * FTS product variant.
 */
enum
{
  ublox_msgs__msg__CfgCFG__MASK_FTS_CONF = 4096ul
};

/// Constant 'DEV_BBR'.
/**
  * device battery backed RAM
 */
enum
{
  ublox_msgs__msg__CfgCFG__DEV_BBR = 1
};

/// Constant 'DEV_FLASH'.
/**
  * device Flash
 */
enum
{
  ublox_msgs__msg__CfgCFG__DEV_FLASH = 2
};

/// Constant 'DEV_EEPROM'.
/**
  * device EEPROM
 */
enum
{
  ublox_msgs__msg__CfgCFG__DEV_EEPROM = 4
};

/// Constant 'DEV_SPI_FLASH'.
/**
  * device SPI Flash
 */
enum
{
  ublox_msgs__msg__CfgCFG__DEV_SPI_FLASH = 16
};

/// Struct defined in msg/CfgCFG in the package ublox_msgs.
/**
  * CFG-CFG (0x06 0x09)
  * Clear, Save and Load configurations
 */
typedef struct ublox_msgs__msg__CfgCFG
{
  /// Mask with configuration sub-sections to Clear
  /// (=Load Default Configurations to Permanent
  /// Configurations in non-volatile memory)
  uint32_t clear_mask;
  /// Mask with configuration sub-section to Save
  /// (=Save Current Configuration to Non-volatile
  /// Memory)
  uint32_t save_mask;
  /// Mask with configuration sub-sections to Load
  /// (=Load Permanent Configurations from
  /// Non-volatile Memory to Current Configurations)
  uint32_t load_mask;
  /// Mask which selects the devices for this command
  uint8_t device_mask;
} ublox_msgs__msg__CfgCFG;

// Struct for a sequence of ublox_msgs__msg__CfgCFG.
typedef struct ublox_msgs__msg__CfgCFG__Sequence
{
  ublox_msgs__msg__CfgCFG * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgCFG__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_CFG__STRUCT_H_

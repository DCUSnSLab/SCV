// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/MonHW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_HW__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__MON_HW__STRUCT_H_

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
  ublox_msgs__msg__MonHW__CLASS_ID = 10
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__MonHW__MESSAGE_ID = 9
};

/// Constant 'A_STATUS_INIT'.
enum
{
  ublox_msgs__msg__MonHW__A_STATUS_INIT = 0
};

/// Constant 'A_STATUS_UNKNOWN'.
enum
{
  ublox_msgs__msg__MonHW__A_STATUS_UNKNOWN = 1
};

/// Constant 'A_STATUS_OK'.
enum
{
  ublox_msgs__msg__MonHW__A_STATUS_OK = 2
};

/// Constant 'A_STATUS_SHORT'.
enum
{
  ublox_msgs__msg__MonHW__A_STATUS_SHORT = 3
};

/// Constant 'A_STATUS_OPEN'.
enum
{
  ublox_msgs__msg__MonHW__A_STATUS_OPEN = 4
};

/// Constant 'A_POWER_OFF'.
enum
{
  ublox_msgs__msg__MonHW__A_POWER_OFF = 0
};

/// Constant 'A_POWER_ON'.
enum
{
  ublox_msgs__msg__MonHW__A_POWER_ON = 1
};

/// Constant 'A_POWER_UNKNOWN'.
enum
{
  ublox_msgs__msg__MonHW__A_POWER_UNKNOWN = 2
};

/// Constant 'FLAGS_RTC_CALIB'.
/**
  * RTC is calibrated
 */
enum
{
  ublox_msgs__msg__MonHW__FLAGS_RTC_CALIB = 1
};

/// Constant 'FLAGS_SAFE_BOOT'.
/**
  * Safe boot mode (0 = inactive, 1 = active)
 */
enum
{
  ublox_msgs__msg__MonHW__FLAGS_SAFE_BOOT = 2
};

/// Constant 'FLAGS_JAMMING_STATE_MASK'.
/**
  * output from Jamming/Interference Monitor:
 */
enum
{
  ublox_msgs__msg__MonHW__FLAGS_JAMMING_STATE_MASK = 12
};

/// Constant 'JAMMING_STATE_UNKNOWN_OR_DISABLED'.
/**
  * unknown or feature disabled
 */
enum
{
  ublox_msgs__msg__MonHW__JAMMING_STATE_UNKNOWN_OR_DISABLED = 0
};

/// Constant 'JAMMING_STATE_OK'.
/**
  * ok - no significant jamming
 */
enum
{
  ublox_msgs__msg__MonHW__JAMMING_STATE_OK = 4
};

/// Constant 'JAMMING_STATE_WARNING'.
/**
  * interference visible but fix OK
 */
enum
{
  ublox_msgs__msg__MonHW__JAMMING_STATE_WARNING = 8
};

/// Constant 'JAMMING_STATE_CRITICAL'.
/**
  * interference visible and no fix
 */
enum
{
  ublox_msgs__msg__MonHW__JAMMING_STATE_CRITICAL = 12
};

/// Constant 'FLAGS_XTAL_ABSENT'.
/**
  * RTC XTAL is absent
  * (not supported in protocol versions < 18)
 */
enum
{
  ublox_msgs__msg__MonHW__FLAGS_XTAL_ABSENT = 16
};

/// Constant 'JAM_IND_NONE'.
/**
  * No CW Jamming
 */
enum
{
  ublox_msgs__msg__MonHW__JAM_IND_NONE = 0
};

/// Constant 'JAM_IND_STRONG'.
/**
  * Strong CW Jamming
 */
enum
{
  ublox_msgs__msg__MonHW__JAM_IND_STRONG = 255
};

/// Struct defined in msg/MonHW in the package ublox_msgs.
/**
  * MON-HW (0x0A 0x09)
  * Hardware Status
  *
  * Status of different aspect of the hardware, such as Antenna, PIO/Peripheral
  * Pins, Noise Level, Automatic Gain Control (AGC)
  *
  * WARNING: this message is a different length than the MonHW message for
  * firmware version 6
 */
typedef struct ublox_msgs__msg__MonHW
{
  /// Mask of Pins Set as Peripheral/PIO
  uint32_t pin_sel;
  /// Mask of Pins Set as Bank A/B
  uint32_t pin_bank;
  /// Mask of Pins Set as Input/Output
  uint32_t pin_dir;
  /// Mask of Pins Value Low/High
  uint32_t pin_val;
  /// Noise Level as measured by the GPS Core
  uint16_t noise_per_ms;
  /// AGC Monitor (counts SIGHI xor SIGLO,
  /// range 0 to 8191)
  uint16_t agc_cnt;
  /// Status of the Antenna Supervisor State Machine
  uint8_t a_status;
  /// Current PowerStatus of Antenna
  uint8_t a_power;
  /// Flags:
  uint8_t flags;
  /// Reserved
  uint8_t reserved0;
  /// Mask of Pins that are used by the Virtual Pin
  /// Manager
  uint32_t used_mask;
  /// Array of Pin Mappings for each of the 17
  /// Physical Pins
  uint8_t vp[17];
  /// CW Jamming indicator, scaled:
  uint8_t jam_ind;
  /// Reserved
  uint8_t reserved1[2];
  /// Mask of Pins Value using the PIO Irq
  uint32_t pin_irq;
  /// Mask of Pins Value using the PIO Pull High
  /// Resistor
  uint32_t pull_h;
  /// Mask of Pins Value using the PIO Pull Low
  /// Resistor
  uint32_t pull_l;
} ublox_msgs__msg__MonHW;

// Struct for a sequence of ublox_msgs__msg__MonHW.
typedef struct ublox_msgs__msg__MonHW__Sequence
{
  ublox_msgs__msg__MonHW * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__MonHW__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_HW__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__STRUCT_H_

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
  ublox_msgs__msg__CfgNAVX5__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgNAVX5__MESSAGE_ID = 35
};

/// Constant 'MASK1_MIN_MAX'.
/**
  * apply min/max SVs settings
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK1_MIN_MAX = 4
};

/// Constant 'MASK1_MIN_CNO'.
/**
  * apply minimum C/N0 setting
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK1_MIN_CNO = 8
};

/// Constant 'MASK1_INITIAL_FIX_3D'.
/**
  * apply initial 3D fix settings
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK1_INITIAL_FIX_3D = 64
};

/// Constant 'MASK1_WKN_ROLL'.
/**
  * apply GPS week number rollover settings
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK1_WKN_ROLL = 512
};

/// Constant 'MASK1_ACK_AID'.
/**
  * apply assistance acknowledgment
  * settings
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK1_ACK_AID = 1024
};

/// Constant 'MASK1_PPP'.
/**
  * apply usePPP flag
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK1_PPP = 8192
};

/// Constant 'MASK1_AOP'.
/**
  * apply aopCfg (useAOP flag) and
  * aopOrbMaxErr settings
  * (AssistNow Autonomous)
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK1_AOP = 16384
};

/// Constant 'MASK2_ADR'.
/**
  * Apply ADR sensor fusion on/off
  * setting
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK2_ADR = 64ul
};

/// Constant 'MASK2_SIG_ATTEN_COMP_MODE'.
/**
  * Apply signal attenuation
  * compensation feature settings
 */
enum
{
  ublox_msgs__msg__CfgNAVX5__MASK2_SIG_ATTEN_COMP_MODE = 128ul
};

/// Struct defined in msg/CfgNAVX5 in the package ublox_msgs.
/**
  * CFG-NAVX5 (0x06 0x23)
  * Navigation Engine Expert Settings
  *
  * Warning: Refer to u-blox protocol spec before changing these settings.
 */
typedef struct ublox_msgs__msg__CfgNAVX5
{
  /// Message version (set to 0)
  uint16_t version;
  /// First parameters bitmask (possible values below)
  uint16_t mask1;
  /// Second parameters bitmask (possible values below)
  /// Firmware >=8 only
  uint32_t mask2;
  /// Always set to zero
  uint8_t reserved1[2];
  /// Minimum number of satellites for navigation
  uint8_t min_svs;
  /// Maximum number of satellites for navigation
  uint8_t max_svs;
  /// Minimum satellite signal level for navigation
  uint8_t min_cno;
  /// Always set to zero
  uint8_t reserved2;
  /// If set to 1, initial fix must be 3D
  uint8_t ini_fix3d;
  /// Always set to zero
  uint8_t reserved3[2];
  /// If set to 1, issue acknowledgments for assistance
  uint8_t ack_aiding;
  /// GPS week rollover number, GPS week numbers will be set
  /// correctly from this week up to 1024 weeks after this
  /// week
  uint16_t wkn_rollover;
  /// Permanently attenuated signal compensation
  /// 0 = disabled, 255 = automatic
  /// 1..63 = maximum expected C/N0 value
  /// Firmware 8 only
  uint8_t sig_atten_comp_mode;
  /// Always set to zero
  uint8_t reserved4[5];
  /// Enable/disable PPP (on supported units)
  uint8_t use_ppp;
  /// AssistNow Autonomous configuration, 1: enabled
  uint8_t aop_cfg;
  /// Always set to zero
  uint8_t reserved5[2];
  /// Maximum acceptable (modeled) autonomous orbit
  /// error
  /// valid range = 5..1000
  /// 0 = reset to firmware default
  uint16_t aop_orb_max_err;
  /// Always set to zero
  uint8_t reserved6[7];
  /// Enable/disable ADR sensor fusion
  /// 1: enabled, 0: disabled
  /// Only supported on certain products
  uint8_t use_adr;
} ublox_msgs__msg__CfgNAVX5;

// Struct for a sequence of ublox_msgs__msg__CfgNAVX5.
typedef struct ublox_msgs__msg__CfgNAVX5__Sequence
{
  ublox_msgs__msg__CfgNAVX5 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgNAVX5__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__STRUCT_H_

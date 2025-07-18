// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/NavSATSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FLAGS_QUALITY_IND_MASK'.
/**
  * Signal quality indicator:
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_QUALITY_IND_MASK = 7ul
};

/// Constant 'QUALITY_IND_NO_SIGNAL'.
/**
  * no signal
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_NO_SIGNAL = 0
};

/// Constant 'QUALITY_IND_SEARCHING_SIGNAL'.
/**
  * searching signal
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_SEARCHING_SIGNAL = 1
};

/// Constant 'QUALITY_IND_SIGNAL_ACQUIRED'.
/**
  * signal acquired
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_SIGNAL_ACQUIRED = 2
};

/// Constant 'QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE'.
/**
  * signal detected but
  * unusable
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE = 3
};

/// Constant 'QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC'.
/**
  * code locked and time
  * synchronized
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC = 4
};

/// Constant 'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1'.
/**
  * code and carrier
  * locked and time
  * synchronized,
  * quality = 1
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1 = 5
};

/// Constant 'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2'.
/**
  * code and carrier
  * locked and time
  * synchronized,
  * quality = 2
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2 = 6
};

/// Constant 'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3'.
/**
  * code and carrier
  * locked and time
  * synchronized,
  * quality = 3
 */
enum
{
  ublox_msgs__msg__NavSATSV__QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3 = 7
};

/// Constant 'FLAGS_SV_USED'.
/**
  * Note: Since IMES signals are not time synchronized, a channel tracking an IMES
  * signal can never reach a quality indicator value of higher than 3.
  * whether SV is currently being
  * used for navigation
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_SV_USED = 8ul
};

/// Constant 'FLAGS_HEALTH_MASK'.
/**
  * SV health flag:
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_HEALTH_MASK = 48ul
};

/// Constant 'HEALTH_UNKNOWN'.
/**
  * unknown
 */
enum
{
  ublox_msgs__msg__NavSATSV__HEALTH_UNKNOWN = 0ul
};

/// Constant 'HEALTH_HEALTHY'.
/**
  * healthy
 */
enum
{
  ublox_msgs__msg__NavSATSV__HEALTH_HEALTHY = 1ul
};

/// Constant 'HEALTH_UNHEALTHY'.
/**
  * unhealthy
 */
enum
{
  ublox_msgs__msg__NavSATSV__HEALTH_UNHEALTHY = 2ul
};

/// Constant 'FLAGS_DIFF_CORR'.
/**
  * whether differential correction
  * data is available for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_DIFF_CORR = 64ul
};

/// Constant 'FLAGS_SMOOTHED'.
/**
  * whether carrier smoothed
  * pseudorange used
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_SMOOTHED = 128ul
};

/// Constant 'FLAGS_ORBIT_SOURCE_MASK'.
/**
  * Orbit source:
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_ORBIT_SOURCE_MASK = 1792ul
};

/// Constant 'ORBIT_SOURCE_UNAVAILABLE'.
/**
  * no orbit information is
  * available for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_UNAVAILABLE = 0ul
};

/// Constant 'ORBIT_SOURCE_EPH'.
/**
  * ephemeris is used
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_EPH = 256ul
};

/// Constant 'ORBIT_SOURCE_ALM'.
/**
  * almanac is used
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_ALM = 512ul
};

/// Constant 'ORBIT_SOURCE_ASSIST_OFFLINE'.
/**
  * AssistNow Offline orbit is
  * used
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_ASSIST_OFFLINE = 768ul
};

/// Constant 'ORBIT_SOURCE_ASSIST_AUTONOMOUS'.
/**
  * AssistNow Autonomous orbit is
  * used
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_ASSIST_AUTONOMOUS = 1024ul
};

/// Constant 'ORBIT_SOURCE_OTHER1'.
/**
  * other orbit information is
  * used
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_OTHER1 = 1280ul
};

/// Constant 'ORBIT_SOURCE_OTHER2'.
/**
  * other orbit information is
  * used
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_OTHER2 = 1536ul
};

/// Constant 'ORBIT_SOURCE_OTHER3'.
/**
  * other orbit information is
  * used
 */
enum
{
  ublox_msgs__msg__NavSATSV__ORBIT_SOURCE_OTHER3 = 1792ul
};

/// Constant 'FLAGS_EPH_AVAIL'.
/**
  * whether ephemeris is available
  * for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_EPH_AVAIL = 2048ul
};

/// Constant 'FLAGS_ALM_AVAIL'.
/**
  * whether almanac is available for
  * this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_ALM_AVAIL = 4096ul
};

/// Constant 'FLAGS_ANO_AVAIL'.
/**
  * whether AssistNow Offline data
  * is available for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_ANO_AVAIL = 8192ul
};

/// Constant 'FLAGS_AOP_AVAIL'.
/**
  * whether AssistNow Autonomous
  * data is available for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_AOP_AVAIL = 16384ul
};

/// Constant 'FLAGS_SBAS_CORR_USED'.
/**
  * whether SBAS corrections have
  * been used for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_SBAS_CORR_USED = 65536ul
};

/// Constant 'FLAGS_RTCM_CORR_USED'.
/**
  * whether RTCM corrections have
  * been used for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_RTCM_CORR_USED = 131072ul
};

/// Constant 'FLAGS_PR_CORR_USED'.
/**
  * whether Pseudorange corrections
  * have been used for this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_PR_CORR_USED = 1048576ul
};

/// Constant 'FLAGS_CR_CORR_USED'.
/**
  * whether Carrier range
  * corrections have been used for
  * this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_CR_CORR_USED = 2097152ul
};

/// Constant 'FLAGS_DO_CORR_USED'.
/**
  * whether Range rate (Doppler)
  * corrections have been used for
  * this SV
 */
enum
{
  ublox_msgs__msg__NavSATSV__FLAGS_DO_CORR_USED = 4194304ul
};

/// Struct defined in msg/NavSATSV in the package ublox_msgs.
/**
  * see NAV-SAT message
 */
typedef struct ublox_msgs__msg__NavSATSV
{
  /// GNSS identifier
  uint8_t gnss_id;
  /// Satellite identifier
  uint8_t sv_id;
  /// Carrier to noise ratio (signal strength) ]dBHz
  uint8_t cno;
  /// Elevation (range: +/-90), unknown if out of range
  int8_t elev;
  /// Azimuth (range 0-360), unknown if elevation is out of range
  /// [deg]
  int16_t azim;
  /// Pseudo range residual
  int16_t pr_res;
  /// Bitmask
  uint32_t flags;
} ublox_msgs__msg__NavSATSV;

// Struct for a sequence of ublox_msgs__msg__NavSATSV.
typedef struct ublox_msgs__msg__NavSATSV__Sequence
{
  ublox_msgs__msg__NavSATSV * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__NavSATSV__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__STRUCT_H_

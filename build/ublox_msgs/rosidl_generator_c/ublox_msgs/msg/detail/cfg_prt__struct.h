// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgPRT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_PRT__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_PRT__STRUCT_H_

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
  ublox_msgs__msg__CfgPRT__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgPRT__MESSAGE_ID = 0
};

/// Constant 'PORT_ID_DDC'.
enum
{
  ublox_msgs__msg__CfgPRT__PORT_ID_DDC = 0
};

/// Constant 'PORT_ID_UART1'.
enum
{
  ublox_msgs__msg__CfgPRT__PORT_ID_UART1 = 1
};

/// Constant 'PORT_ID_UART2'.
enum
{
  ublox_msgs__msg__CfgPRT__PORT_ID_UART2 = 2
};

/// Constant 'PORT_ID_USB'.
enum
{
  ublox_msgs__msg__CfgPRT__PORT_ID_USB = 3
};

/// Constant 'PORT_ID_SPI'.
enum
{
  ublox_msgs__msg__CfgPRT__PORT_ID_SPI = 4
};

/// Constant 'TX_READY_EN'.
/**
  * Enable TX ready feature for this
  * port
 */
enum
{
  ublox_msgs__msg__CfgPRT__TX_READY_EN = 1
};

/// Constant 'TX_READY_POLARITY_HIGH_ACTIVE'.
/**
  * Polarity High-active
 */
enum
{
  ublox_msgs__msg__CfgPRT__TX_READY_POLARITY_HIGH_ACTIVE = 0
};

/// Constant 'TX_READY_POLARITY_LOW_ACTIVE'.
/**
  * Polarity Low-active
 */
enum
{
  ublox_msgs__msg__CfgPRT__TX_READY_POLARITY_LOW_ACTIVE = 2
};

/// Constant 'TX_READY_PIN_SHIFT'.
/**
  * PIO to be used (must not be in use
  * already by another function)
 */
enum
{
  ublox_msgs__msg__CfgPRT__TX_READY_PIN_SHIFT = 2
};

/// Constant 'TX_READY_PIN_MASK'.
enum
{
  ublox_msgs__msg__CfgPRT__TX_READY_PIN_MASK = 124
};

/// Constant 'TX_READY_THRES_SHIFT'.
/**
  * Threshold
 */
enum
{
  ublox_msgs__msg__CfgPRT__TX_READY_THRES_SHIFT = 7
};

/// Constant 'TX_READY_THRES_MASK'.
/**
  * The given threshold is multiplied by
  * 8 bytes.
  * The TX ready PIN goes active
  * after >= thres*8 bytes are pending
  * for the port and going inactive
  * after the last pending bytes have
  * been written to hardware (0-4 bytes
  * before end of stream).
 */
enum
{
  ublox_msgs__msg__CfgPRT__TX_READY_THRES_MASK = 65408
};

/// Constant 'MODE_DDC_SLAVE_ADDR_SHIFT'.
/**
  * DDC Mode Constants
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_DDC_SLAVE_ADDR_SHIFT = 1ul
};

/// Constant 'MODE_DDC_SLAVE_ADDR_MASK'.
/**
  * Slave address
  * Range: 0x07 < slaveAddr < 0x78.
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_DDC_SLAVE_ADDR_MASK = 254ul
};

/// Constant 'MODE_RESERVED1'.
/**
  * UART Mode Constants
  * Default 1 for compatibility with A4
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_RESERVED1 = 16ul
};

/// Constant 'MODE_CHAR_LEN_MASK'.
/**
  * Character Length
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_CHAR_LEN_MASK = 192ul
};

/// Constant 'MODE_CHAR_LEN_5BIT'.
/**
  * 5bit (not supported)
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_CHAR_LEN_5BIT = 0ul
};

/// Constant 'MODE_CHAR_LEN_6BIT'.
/**
  * 6bit (not supported)
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_CHAR_LEN_6BIT = 64ul
};

/// Constant 'MODE_CHAR_LEN_7BIT'.
/**
  * 7bit (supported only with parity)
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_CHAR_LEN_7BIT = 128ul
};

/// Constant 'MODE_CHAR_LEN_8BIT'.
/**
  * 8bit
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_CHAR_LEN_8BIT = 192ul
};

/// Constant 'MODE_PARITY_MASK'.
enum
{
  ublox_msgs__msg__CfgPRT__MODE_PARITY_MASK = 3584ul
};

/// Constant 'MODE_PARITY_EVEN'.
/**
  * Even Parity
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_PARITY_EVEN = 0ul
};

/// Constant 'MODE_PARITY_ODD'.
/**
  * Odd Parity
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_PARITY_ODD = 512ul
};

/// Constant 'MODE_PARITY_NO'.
/**
  * No Parity (even/odd ignored)
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_PARITY_NO = 2048ul
};

/// Constant 'MODE_STOP_BITS_MASK'.
/**
  * Number of Stop Bits
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_STOP_BITS_MASK = 12288ul
};

/// Constant 'MODE_STOP_BITS_1'.
/**
  * 1 Stop Bit
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_STOP_BITS_1 = 0ul
};

/// Constant 'MODE_STOP_BITS_15'.
/**
  * 1.5 Stop Bit
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_STOP_BITS_15 = 4096ul
};

/// Constant 'MODE_STOP_BITS_2'.
/**
  * 2 Stop Bit
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_STOP_BITS_2 = 8192ul
};

/// Constant 'MODE_STOP_BITS_05'.
/**
  * 0.5 Stop Bit
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_STOP_BITS_05 = 12288ul
};

/// Constant 'MODE_SPI_SPI_MODE_CPOL'.
/**
  * SPI Mode Constants
  * SPI Mode CPOL (0/1)
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_SPI_SPI_MODE_CPOL = 4ul
};

/// Constant 'MODE_SPI_SPI_MODE_CPHA'.
/**
  * SPI Mode CPH (0/1)
  * (both CPOL/CPHA) can be = 1
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_SPI_SPI_MODE_CPHA = 2ul
};

/// Constant 'MODE_SPI_FLOW_CONTROL'.
/**
  * (u-blox 6 only)
  * 0 Flow control disabled
  * 1 Flow control enabled (9-bit mode)
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_SPI_FLOW_CONTROL = 64ul
};

/// Constant 'MODE_SPI_FF_COUNT_SHIFT'.
enum
{
  ublox_msgs__msg__CfgPRT__MODE_SPI_FF_COUNT_SHIFT = 8ul
};

/// Constant 'MODE_SPI_FF_COUNT_MASK'.
/**
  * Number of bytes containing 0xFF to
  * receive before switching off
  * reception.
  * Range: 0(mechanism off)-63
 */
enum
{
  ublox_msgs__msg__CfgPRT__MODE_SPI_FF_COUNT_MASK = 16128ul
};

/// Constant 'PROTO_UBX'.
enum
{
  ublox_msgs__msg__CfgPRT__PROTO_UBX = 1
};

/// Constant 'PROTO_NMEA'.
enum
{
  ublox_msgs__msg__CfgPRT__PROTO_NMEA = 2
};

/// Constant 'PROTO_RTCM'.
/**
  * only for inProtoMask
 */
enum
{
  ublox_msgs__msg__CfgPRT__PROTO_RTCM = 4
};

/// Constant 'PROTO_RTCM3'.
/**
  * (not supported in protocol versions less than 20)
 */
enum
{
  ublox_msgs__msg__CfgPRT__PROTO_RTCM3 = 32
};

/// Constant 'FLAGS_EXTENDED_TX_TIMEOUT'.
/**
  * if set, the port will timeout if
  * allocated TX memory >=4 kB and no
  * activity for 1.5s. If not set the port
  * will timoout if no activity for 1.5s
  * regardless on the amount of allocated
  * TX memory.
 */
enum
{
  ublox_msgs__msg__CfgPRT__FLAGS_EXTENDED_TX_TIMEOUT = 2
};

/// Struct defined in msg/CfgPRT in the package ublox_msgs.
/**
  * CFG-PRT (0x06 0x00)
  * Port Configuration for DDC, UART, USB, SPI
  *
  * Several configurations can be concatenated to one input message. In this case
  * the payload length can be a multiple of the normal length (see the other
  * versions of CFG-PRT). Output messages from the module contain only one
  * configuration unit.
 */
typedef struct ublox_msgs__msg__CfgPRT
{
  /// Port Identifier Number
  uint8_t port_id;
  /// Reserved
  uint8_t reserved0;
  /// TX ready PIN configuration (since Firmware 7.01)
  /// reserved (Always set to zero) up to Firmware 7.01
  uint16_t tx_ready;
  /// A bit mask describing the DDC, UART or SPI mode
  /// Reserved for USB
  uint32_t mode;
  /// UART Baudrate in bits/second
  /// Reserved for USB, SPI, DDC
  /// Possible values: 4800, 9600, 19200, 38400, 57600,
  ///                  115200, 230400, 460800
  uint32_t baud_rate;
  /// A mask describing which input protocols are active.
  /// Each bit of this mask is used for a protocol.
  /// Through that, multiple protocols can be defined
  /// on a single port.
  uint16_t in_proto_mask;
  /// A mask describing which output protocols are active.
  /// Each bit of this mask is used for a protocol.
  /// Through that, multiple protocols can be defined
  /// on a single port.
  uint16_t out_proto_mask;
  /// Flags for UART & SPI, Reserved for USB
  uint16_t flags;
  /// Always set to zero
  uint16_t reserved1;
} ublox_msgs__msg__CfgPRT;

// Struct for a sequence of ublox_msgs__msg__CfgPRT.
typedef struct ublox_msgs__msg__CfgPRT__Sequence
{
  ublox_msgs__msg__CfgPRT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgPRT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_PRT__STRUCT_H_

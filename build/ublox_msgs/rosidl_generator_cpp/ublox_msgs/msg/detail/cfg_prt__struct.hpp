// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgPRT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_PRT__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_PRT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgPRT __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgPRT __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgPRT_
{
  using Type = CfgPRT_<ContainerAllocator>;

  explicit CfgPRT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->port_id = 0;
      this->reserved0 = 0;
      this->tx_ready = 0;
      this->mode = 0ul;
      this->baud_rate = 0ul;
      this->in_proto_mask = 0;
      this->out_proto_mask = 0;
      this->flags = 0;
      this->reserved1 = 0;
    }
  }

  explicit CfgPRT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->port_id = 0;
      this->reserved0 = 0;
      this->tx_ready = 0;
      this->mode = 0ul;
      this->baud_rate = 0ul;
      this->in_proto_mask = 0;
      this->out_proto_mask = 0;
      this->flags = 0;
      this->reserved1 = 0;
    }
  }

  // field types and members
  using _port_id_type =
    uint8_t;
  _port_id_type port_id;
  using _reserved0_type =
    uint8_t;
  _reserved0_type reserved0;
  using _tx_ready_type =
    uint16_t;
  _tx_ready_type tx_ready;
  using _mode_type =
    uint32_t;
  _mode_type mode;
  using _baud_rate_type =
    uint32_t;
  _baud_rate_type baud_rate;
  using _in_proto_mask_type =
    uint16_t;
  _in_proto_mask_type in_proto_mask;
  using _out_proto_mask_type =
    uint16_t;
  _out_proto_mask_type out_proto_mask;
  using _flags_type =
    uint16_t;
  _flags_type flags;
  using _reserved1_type =
    uint16_t;
  _reserved1_type reserved1;

  // setters for named parameter idiom
  Type & set__port_id(
    const uint8_t & _arg)
  {
    this->port_id = _arg;
    return *this;
  }
  Type & set__reserved0(
    const uint8_t & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__tx_ready(
    const uint16_t & _arg)
  {
    this->tx_ready = _arg;
    return *this;
  }
  Type & set__mode(
    const uint32_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__baud_rate(
    const uint32_t & _arg)
  {
    this->baud_rate = _arg;
    return *this;
  }
  Type & set__in_proto_mask(
    const uint16_t & _arg)
  {
    this->in_proto_mask = _arg;
    return *this;
  }
  Type & set__out_proto_mask(
    const uint16_t & _arg)
  {
    this->out_proto_mask = _arg;
    return *this;
  }
  Type & set__flags(
    const uint16_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint16_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    0u;
  static constexpr uint8_t PORT_ID_DDC =
    0u;
  static constexpr uint8_t PORT_ID_UART1 =
    1u;
  static constexpr uint8_t PORT_ID_UART2 =
    2u;
  static constexpr uint8_t PORT_ID_USB =
    3u;
  static constexpr uint8_t PORT_ID_SPI =
    4u;
  static constexpr uint16_t TX_READY_EN =
    1u;
  static constexpr uint16_t TX_READY_POLARITY_HIGH_ACTIVE =
    0u;
  static constexpr uint16_t TX_READY_POLARITY_LOW_ACTIVE =
    2u;
  static constexpr uint16_t TX_READY_PIN_SHIFT =
    2u;
  static constexpr uint16_t TX_READY_PIN_MASK =
    124u;
  static constexpr uint16_t TX_READY_THRES_SHIFT =
    7u;
  static constexpr uint16_t TX_READY_THRES_MASK =
    65408u;
  static constexpr uint32_t MODE_DDC_SLAVE_ADDR_SHIFT =
    1u;
  static constexpr uint32_t MODE_DDC_SLAVE_ADDR_MASK =
    254u;
  static constexpr uint32_t MODE_RESERVED1 =
    16u;
  static constexpr uint32_t MODE_CHAR_LEN_MASK =
    192u;
  static constexpr uint32_t MODE_CHAR_LEN_5BIT =
    0u;
  static constexpr uint32_t MODE_CHAR_LEN_6BIT =
    64u;
  static constexpr uint32_t MODE_CHAR_LEN_7BIT =
    128u;
  static constexpr uint32_t MODE_CHAR_LEN_8BIT =
    192u;
  static constexpr uint32_t MODE_PARITY_MASK =
    3584u;
  static constexpr uint32_t MODE_PARITY_EVEN =
    0u;
  static constexpr uint32_t MODE_PARITY_ODD =
    512u;
  static constexpr uint32_t MODE_PARITY_NO =
    2048u;
  static constexpr uint32_t MODE_STOP_BITS_MASK =
    12288u;
  static constexpr uint32_t MODE_STOP_BITS_1 =
    0u;
  static constexpr uint32_t MODE_STOP_BITS_15 =
    4096u;
  static constexpr uint32_t MODE_STOP_BITS_2 =
    8192u;
  static constexpr uint32_t MODE_STOP_BITS_05 =
    12288u;
  static constexpr uint32_t MODE_SPI_SPI_MODE_CPOL =
    4u;
  static constexpr uint32_t MODE_SPI_SPI_MODE_CPHA =
    2u;
  static constexpr uint32_t MODE_SPI_FLOW_CONTROL =
    64u;
  static constexpr uint32_t MODE_SPI_FF_COUNT_SHIFT =
    8u;
  static constexpr uint32_t MODE_SPI_FF_COUNT_MASK =
    16128u;
  static constexpr uint16_t PROTO_UBX =
    1u;
  static constexpr uint16_t PROTO_NMEA =
    2u;
  static constexpr uint16_t PROTO_RTCM =
    4u;
  static constexpr uint16_t PROTO_RTCM3 =
    32u;
  static constexpr uint16_t FLAGS_EXTENDED_TX_TIMEOUT =
    2u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgPRT_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgPRT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgPRT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgPRT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgPRT
    std::shared_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgPRT
    std::shared_ptr<ublox_msgs::msg::CfgPRT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgPRT_ & other) const
  {
    if (this->port_id != other.port_id) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->tx_ready != other.tx_ready) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->baud_rate != other.baud_rate) {
      return false;
    }
    if (this->in_proto_mask != other.in_proto_mask) {
      return false;
    }
    if (this->out_proto_mask != other.out_proto_mask) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgPRT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgPRT_

// alias to use template instance with default allocator
using CfgPRT =
  ublox_msgs::msg::CfgPRT_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgPRT_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgPRT_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgPRT_<ContainerAllocator>::PORT_ID_DDC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgPRT_<ContainerAllocator>::PORT_ID_UART1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgPRT_<ContainerAllocator>::PORT_ID_UART2;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgPRT_<ContainerAllocator>::PORT_ID_USB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgPRT_<ContainerAllocator>::PORT_ID_SPI;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::TX_READY_EN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::TX_READY_POLARITY_HIGH_ACTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::TX_READY_POLARITY_LOW_ACTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::TX_READY_PIN_SHIFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::TX_READY_PIN_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::TX_READY_THRES_SHIFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::TX_READY_THRES_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_DDC_SLAVE_ADDR_SHIFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_DDC_SLAVE_ADDR_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_RESERVED1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_CHAR_LEN_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_CHAR_LEN_5BIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_CHAR_LEN_6BIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_CHAR_LEN_7BIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_CHAR_LEN_8BIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_PARITY_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_PARITY_EVEN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_PARITY_ODD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_PARITY_NO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_STOP_BITS_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_STOP_BITS_1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_STOP_BITS_15;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_STOP_BITS_2;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_STOP_BITS_05;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_SPI_SPI_MODE_CPOL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_SPI_SPI_MODE_CPHA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_SPI_FLOW_CONTROL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_SPI_FF_COUNT_SHIFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgPRT_<ContainerAllocator>::MODE_SPI_FF_COUNT_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::PROTO_UBX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::PROTO_NMEA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::PROTO_RTCM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::PROTO_RTCM3;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgPRT_<ContainerAllocator>::FLAGS_EXTENDED_TX_TIMEOUT;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_PRT__STRUCT_HPP_

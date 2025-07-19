// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgRST.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_RST__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_RST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgRST __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgRST __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgRST_
{
  using Type = CfgRST_<ContainerAllocator>;

  explicit CfgRST_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nav_bbr_mask = 0;
      this->reset_mode = 0;
      this->reserved1 = 0;
    }
  }

  explicit CfgRST_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nav_bbr_mask = 0;
      this->reset_mode = 0;
      this->reserved1 = 0;
    }
  }

  // field types and members
  using _nav_bbr_mask_type =
    uint16_t;
  _nav_bbr_mask_type nav_bbr_mask;
  using _reset_mode_type =
    uint8_t;
  _reset_mode_type reset_mode;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;

  // setters for named parameter idiom
  Type & set__nav_bbr_mask(
    const uint16_t & _arg)
  {
    this->nav_bbr_mask = _arg;
    return *this;
  }
  Type & set__reset_mode(
    const uint8_t & _arg)
  {
    this->reset_mode = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    4u;
  static constexpr uint16_t NAV_BBR_HOT_START =
    0u;
  static constexpr uint16_t NAV_BBR_WARM_START =
    1u;
  static constexpr uint16_t NAV_BBR_COLD_START =
    65535u;
  static constexpr uint16_t NAV_BBR_EPH =
    1u;
  static constexpr uint16_t NAV_BBR_ALM =
    2u;
  static constexpr uint16_t NAV_BBR_HEALTH =
    4u;
  static constexpr uint16_t NAV_BBR_KLOB =
    8u;
  static constexpr uint16_t NAV_BBR_POS =
    16u;
  static constexpr uint16_t NAV_BBR_CLKD =
    32u;
  static constexpr uint16_t NAV_BBR_OSC =
    64u;
  static constexpr uint16_t NAV_BBR_UTC =
    128u;
  static constexpr uint16_t NAV_BBR_RTC =
    256u;
  static constexpr uint16_t NAV_BBR_AOP =
    32768u;
  static constexpr uint8_t RESET_MODE_HW_IMMEDIATE =
    0u;
  static constexpr uint8_t RESET_MODE_SW =
    1u;
  static constexpr uint8_t RESET_MODE_GNSS =
    2u;
  static constexpr uint8_t RESET_MODE_HW_AFTER_SHUTDOWN =
    4u;
  static constexpr uint8_t RESET_MODE_GNSS_STOP =
    8u;
  static constexpr uint8_t RESET_MODE_GNSS_START =
    9u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgRST_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgRST_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgRST_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgRST_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgRST
    std::shared_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgRST
    std::shared_ptr<ublox_msgs::msg::CfgRST_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgRST_ & other) const
  {
    if (this->nav_bbr_mask != other.nav_bbr_mask) {
      return false;
    }
    if (this->reset_mode != other.reset_mode) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgRST_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgRST_

// alias to use template instance with default allocator
using CfgRST =
  ublox_msgs::msg::CfgRST_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_HOT_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_WARM_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_COLD_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_EPH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_ALM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_HEALTH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_KLOB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_POS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_CLKD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_OSC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_UTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_RTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRST_<ContainerAllocator>::NAV_BBR_AOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::RESET_MODE_HW_IMMEDIATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::RESET_MODE_SW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::RESET_MODE_GNSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::RESET_MODE_HW_AFTER_SHUTDOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::RESET_MODE_GNSS_STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRST_<ContainerAllocator>::RESET_MODE_GNSS_START;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_RST__STRUCT_HPP_

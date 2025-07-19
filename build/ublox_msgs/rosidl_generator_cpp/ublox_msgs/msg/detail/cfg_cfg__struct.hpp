// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgCFG.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_CFG__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_CFG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgCFG __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgCFG __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgCFG_
{
  using Type = CfgCFG_<ContainerAllocator>;

  explicit CfgCFG_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->clear_mask = 0ul;
      this->save_mask = 0ul;
      this->load_mask = 0ul;
      this->device_mask = 0;
    }
  }

  explicit CfgCFG_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->clear_mask = 0ul;
      this->save_mask = 0ul;
      this->load_mask = 0ul;
      this->device_mask = 0;
    }
  }

  // field types and members
  using _clear_mask_type =
    uint32_t;
  _clear_mask_type clear_mask;
  using _save_mask_type =
    uint32_t;
  _save_mask_type save_mask;
  using _load_mask_type =
    uint32_t;
  _load_mask_type load_mask;
  using _device_mask_type =
    uint8_t;
  _device_mask_type device_mask;

  // setters for named parameter idiom
  Type & set__clear_mask(
    const uint32_t & _arg)
  {
    this->clear_mask = _arg;
    return *this;
  }
  Type & set__save_mask(
    const uint32_t & _arg)
  {
    this->save_mask = _arg;
    return *this;
  }
  Type & set__load_mask(
    const uint32_t & _arg)
  {
    this->load_mask = _arg;
    return *this;
  }
  Type & set__device_mask(
    const uint8_t & _arg)
  {
    this->device_mask = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    9u;
  static constexpr uint32_t MASK_IO_PORT =
    1u;
  static constexpr uint32_t MASK_MSG_CONF =
    2u;
  static constexpr uint32_t MASK_INF_MSG =
    4u;
  static constexpr uint32_t MASK_NAV_CONF =
    8u;
  static constexpr uint32_t MASK_RXM_CONF =
    16u;
  static constexpr uint32_t MASK_SEN_CONF =
    256u;
  static constexpr uint32_t MASK_RINV_CONF =
    512u;
  static constexpr uint32_t MASK_ANT_CONF =
    1024u;
  static constexpr uint32_t MASK_LOG_CONF =
    2048u;
  static constexpr uint32_t MASK_FTS_CONF =
    4096u;
  static constexpr uint8_t DEV_BBR =
    1u;
  static constexpr uint8_t DEV_FLASH =
    2u;
  static constexpr uint8_t DEV_EEPROM =
    4u;
  static constexpr uint8_t DEV_SPI_FLASH =
    16u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgCFG_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgCFG_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgCFG_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgCFG_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgCFG
    std::shared_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgCFG
    std::shared_ptr<ublox_msgs::msg::CfgCFG_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgCFG_ & other) const
  {
    if (this->clear_mask != other.clear_mask) {
      return false;
    }
    if (this->save_mask != other.save_mask) {
      return false;
    }
    if (this->load_mask != other.load_mask) {
      return false;
    }
    if (this->device_mask != other.device_mask) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgCFG_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgCFG_

// alias to use template instance with default allocator
using CfgCFG =
  ublox_msgs::msg::CfgCFG_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgCFG_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgCFG_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_IO_PORT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_MSG_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_INF_MSG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_NAV_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_RXM_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_SEN_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_RINV_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_ANT_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_LOG_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgCFG_<ContainerAllocator>::MASK_FTS_CONF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgCFG_<ContainerAllocator>::DEV_BBR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgCFG_<ContainerAllocator>::DEV_FLASH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgCFG_<ContainerAllocator>::DEV_EEPROM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgCFG_<ContainerAllocator>::DEV_SPI_FLASH;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_CFG__STRUCT_HPP_

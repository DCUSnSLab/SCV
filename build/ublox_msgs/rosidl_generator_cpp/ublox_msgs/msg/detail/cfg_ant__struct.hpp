// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgANT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_ANT__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_ANT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgANT __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgANT __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgANT_
{
  using Type = CfgANT_<ContainerAllocator>;

  explicit CfgANT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flags = 0;
      this->pins = 0;
    }
  }

  explicit CfgANT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flags = 0;
      this->pins = 0;
    }
  }

  // field types and members
  using _flags_type =
    uint16_t;
  _flags_type flags;
  using _pins_type =
    uint16_t;
  _pins_type pins;

  // setters for named parameter idiom
  Type & set__flags(
    const uint16_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__pins(
    const uint16_t & _arg)
  {
    this->pins = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    19u;
  static constexpr uint16_t FLAGS_SVCS =
    1u;
  static constexpr uint16_t FLAGS_SCD =
    2u;
  static constexpr uint16_t FLAGS_OCD =
    4u;
  static constexpr uint16_t FLAGS_PDWN_ON_SCD =
    8u;
  static constexpr uint16_t FLAGS_RECOVERY =
    16u;
  static constexpr uint16_t PIN_SWITCH_MASK =
    31u;
  static constexpr uint16_t PIN_SCD_MASK =
    992u;
  static constexpr uint16_t PIN_OCD_MASK =
    31744u;
  static constexpr uint16_t PIN_RECONFIG =
    32678u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgANT_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgANT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgANT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgANT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgANT
    std::shared_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgANT
    std::shared_ptr<ublox_msgs::msg::CfgANT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgANT_ & other) const
  {
    if (this->flags != other.flags) {
      return false;
    }
    if (this->pins != other.pins) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgANT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgANT_

// alias to use template instance with default allocator
using CfgANT =
  ublox_msgs::msg::CfgANT_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgANT_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgANT_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::FLAGS_SVCS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::FLAGS_SCD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::FLAGS_OCD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::FLAGS_PDWN_ON_SCD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::FLAGS_RECOVERY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::PIN_SWITCH_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::PIN_SCD_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::PIN_OCD_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgANT_<ContainerAllocator>::PIN_RECONFIG;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_ANT__STRUCT_HPP_

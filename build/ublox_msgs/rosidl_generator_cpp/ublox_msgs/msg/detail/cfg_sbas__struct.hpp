// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgSBAS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgSBAS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgSBAS_
{
  using Type = CfgSBAS_<ContainerAllocator>;

  explicit CfgSBAS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->usage = 0;
      this->max_sbas = 0;
      this->scanmode2 = 0;
      this->scanmode1 = 0ul;
    }
  }

  explicit CfgSBAS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->usage = 0;
      this->max_sbas = 0;
      this->scanmode2 = 0;
      this->scanmode1 = 0ul;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _usage_type =
    uint8_t;
  _usage_type usage;
  using _max_sbas_type =
    uint8_t;
  _max_sbas_type max_sbas;
  using _scanmode2_type =
    uint8_t;
  _scanmode2_type scanmode2;
  using _scanmode1_type =
    uint32_t;
  _scanmode1_type scanmode1;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__usage(
    const uint8_t & _arg)
  {
    this->usage = _arg;
    return *this;
  }
  Type & set__max_sbas(
    const uint8_t & _arg)
  {
    this->max_sbas = _arg;
    return *this;
  }
  Type & set__scanmode2(
    const uint8_t & _arg)
  {
    this->scanmode2 = _arg;
    return *this;
  }
  Type & set__scanmode1(
    const uint32_t & _arg)
  {
    this->scanmode1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    22u;
  static constexpr uint8_t MODE_ENABLED =
    1u;
  static constexpr uint8_t MODE_TEST =
    2u;
  static constexpr uint8_t USAGE_RANGE =
    1u;
  static constexpr uint8_t USAGE_DIFF_CORR =
    2u;
  static constexpr uint8_t USAGE_INTEGRITY =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgSBAS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgSBAS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgSBAS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgSBAS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgSBAS
    std::shared_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgSBAS
    std::shared_ptr<ublox_msgs::msg::CfgSBAS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgSBAS_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->usage != other.usage) {
      return false;
    }
    if (this->max_sbas != other.max_sbas) {
      return false;
    }
    if (this->scanmode2 != other.scanmode2) {
      return false;
    }
    if (this->scanmode1 != other.scanmode1) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgSBAS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgSBAS_

// alias to use template instance with default allocator
using CfgSBAS =
  ublox_msgs::msg::CfgSBAS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgSBAS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgSBAS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgSBAS_<ContainerAllocator>::MODE_ENABLED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgSBAS_<ContainerAllocator>::MODE_TEST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgSBAS_<ContainerAllocator>::USAGE_RANGE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgSBAS_<ContainerAllocator>::USAGE_DIFF_CORR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgSBAS_<ContainerAllocator>::USAGE_INTEGRITY;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_SBAS__STRUCT_HPP_

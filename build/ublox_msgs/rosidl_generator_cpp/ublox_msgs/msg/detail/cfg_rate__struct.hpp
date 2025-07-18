// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgRATE.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_RATE__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_RATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgRATE __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgRATE __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgRATE_
{
  using Type = CfgRATE_<ContainerAllocator>;

  explicit CfgRATE_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->meas_rate = 0;
      this->nav_rate = 0;
      this->time_ref = 0;
    }
  }

  explicit CfgRATE_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->meas_rate = 0;
      this->nav_rate = 0;
      this->time_ref = 0;
    }
  }

  // field types and members
  using _meas_rate_type =
    uint16_t;
  _meas_rate_type meas_rate;
  using _nav_rate_type =
    uint16_t;
  _nav_rate_type nav_rate;
  using _time_ref_type =
    uint16_t;
  _time_ref_type time_ref;

  // setters for named parameter idiom
  Type & set__meas_rate(
    const uint16_t & _arg)
  {
    this->meas_rate = _arg;
    return *this;
  }
  Type & set__nav_rate(
    const uint16_t & _arg)
  {
    this->nav_rate = _arg;
    return *this;
  }
  Type & set__time_ref(
    const uint16_t & _arg)
  {
    this->time_ref = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    8u;
  static constexpr uint16_t TIME_REF_UTC =
    0u;
  static constexpr uint16_t TIME_REF_GPS =
    1u;
  static constexpr uint16_t TIME_REF_GLONASS =
    2u;
  static constexpr uint16_t TIME_REF_BEIDOU =
    3u;
  static constexpr uint16_t TIME_REF_GALILEO =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgRATE_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgRATE_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgRATE_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgRATE_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgRATE
    std::shared_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgRATE
    std::shared_ptr<ublox_msgs::msg::CfgRATE_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgRATE_ & other) const
  {
    if (this->meas_rate != other.meas_rate) {
      return false;
    }
    if (this->nav_rate != other.nav_rate) {
      return false;
    }
    if (this->time_ref != other.time_ref) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgRATE_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgRATE_

// alias to use template instance with default allocator
using CfgRATE =
  ublox_msgs::msg::CfgRATE_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRATE_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgRATE_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRATE_<ContainerAllocator>::TIME_REF_UTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRATE_<ContainerAllocator>::TIME_REF_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRATE_<ContainerAllocator>::TIME_REF_GLONASS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRATE_<ContainerAllocator>::TIME_REF_BEIDOU;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgRATE_<ContainerAllocator>::TIME_REF_GALILEO;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_RATE__STRUCT_HPP_

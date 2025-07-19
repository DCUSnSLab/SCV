// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgHNR.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_HNR__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_HNR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgHNR __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgHNR __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgHNR_
{
  using Type = CfgHNR_<ContainerAllocator>;

  explicit CfgHNR_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->high_nav_rate = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  explicit CfgHNR_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->high_nav_rate = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  // field types and members
  using _high_nav_rate_type =
    uint8_t;
  _high_nav_rate_type high_nav_rate;
  using _reserved0_type =
    std::array<uint8_t, 3>;
  _reserved0_type reserved0;

  // setters for named parameter idiom
  Type & set__high_nav_rate(
    const uint8_t & _arg)
  {
    this->high_nav_rate = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    92u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgHNR_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgHNR_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgHNR_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgHNR_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgHNR
    std::shared_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgHNR
    std::shared_ptr<ublox_msgs::msg::CfgHNR_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgHNR_ & other) const
  {
    if (this->high_nav_rate != other.high_nav_rate) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgHNR_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgHNR_

// alias to use template instance with default allocator
using CfgHNR =
  ublox_msgs::msg::CfgHNR_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgHNR_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgHNR_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_HNR__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/AidALM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_ALM__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_ALM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__AidALM __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__AidALM __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AidALM_
{
  using Type = AidALM_<ContainerAllocator>;

  explicit AidALM_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0ul;
      this->week = 0ul;
    }
  }

  explicit AidALM_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0ul;
      this->week = 0ul;
    }
  }

  // field types and members
  using _svid_type =
    uint32_t;
  _svid_type svid;
  using _week_type =
    uint32_t;
  _week_type week;
  using _dwrd_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _dwrd_type dwrd;

  // setters for named parameter idiom
  Type & set__svid(
    const uint32_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__week(
    const uint32_t & _arg)
  {
    this->week = _arg;
    return *this;
  }
  Type & set__dwrd(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->dwrd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    11u;
  static constexpr uint8_t MESSAGE_ID =
    48u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::AidALM_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::AidALM_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::AidALM_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::AidALM_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__AidALM
    std::shared_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__AidALM
    std::shared_ptr<ublox_msgs::msg::AidALM_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AidALM_ & other) const
  {
    if (this->svid != other.svid) {
      return false;
    }
    if (this->week != other.week) {
      return false;
    }
    if (this->dwrd != other.dwrd) {
      return false;
    }
    return true;
  }
  bool operator!=(const AidALM_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AidALM_

// alias to use template instance with default allocator
using AidALM =
  ublox_msgs::msg::AidALM_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AidALM_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AidALM_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_ALM__STRUCT_HPP_

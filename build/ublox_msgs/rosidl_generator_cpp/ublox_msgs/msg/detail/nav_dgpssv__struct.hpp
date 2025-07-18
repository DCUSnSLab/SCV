// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavDGPSSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavDGPSSV __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavDGPSSV __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavDGPSSV_
{
  using Type = NavDGPSSV_<ContainerAllocator>;

  explicit NavDGPSSV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0;
      this->flags = 0;
      this->age_c = 0;
      this->prc = 0.0f;
      this->prrc = 0.0f;
    }
  }

  explicit NavDGPSSV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0;
      this->flags = 0;
      this->age_c = 0;
      this->prc = 0.0f;
      this->prrc = 0.0f;
    }
  }

  // field types and members
  using _svid_type =
    uint8_t;
  _svid_type svid;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _age_c_type =
    uint16_t;
  _age_c_type age_c;
  using _prc_type =
    float;
  _prc_type prc;
  using _prrc_type =
    float;
  _prrc_type prrc;

  // setters for named parameter idiom
  Type & set__svid(
    const uint8_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__age_c(
    const uint16_t & _arg)
  {
    this->age_c = _arg;
    return *this;
  }
  Type & set__prc(
    const float & _arg)
  {
    this->prc = _arg;
    return *this;
  }
  Type & set__prrc(
    const float & _arg)
  {
    this->prrc = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t FLAGS_CHANNEL_MASK =
    15u;
  static constexpr uint8_t FLAGS_DGPS =
    16u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavDGPSSV_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavDGPSSV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavDGPSSV
    std::shared_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavDGPSSV
    std::shared_ptr<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavDGPSSV_ & other) const
  {
    if (this->svid != other.svid) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->age_c != other.age_c) {
      return false;
    }
    if (this->prc != other.prc) {
      return false;
    }
    if (this->prrc != other.prrc) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavDGPSSV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavDGPSSV_

// alias to use template instance with default allocator
using NavDGPSSV =
  ublox_msgs::msg::NavDGPSSV_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDGPSSV_<ContainerAllocator>::FLAGS_CHANNEL_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDGPSSV_<ContainerAllocator>::FLAGS_DGPS;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DGPSSV__STRUCT_HPP_

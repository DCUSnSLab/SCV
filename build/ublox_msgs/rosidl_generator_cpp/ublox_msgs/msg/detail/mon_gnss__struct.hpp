// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/MonGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_GNSS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_GNSS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__MonGNSS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__MonGNSS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MonGNSS_
{
  using Type = MonGNSS_<ContainerAllocator>;

  explicit MonGNSS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->supported = 0;
      this->default_gnss = 0;
      this->enabled = 0;
      this->simultaneous = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  explicit MonGNSS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->supported = 0;
      this->default_gnss = 0;
      this->enabled = 0;
      this->simultaneous = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _supported_type =
    uint8_t;
  _supported_type supported;
  using _default_gnss_type =
    uint8_t;
  _default_gnss_type default_gnss;
  using _enabled_type =
    uint8_t;
  _enabled_type enabled;
  using _simultaneous_type =
    uint8_t;
  _simultaneous_type simultaneous;
  using _reserved1_type =
    std::array<uint8_t, 3>;
  _reserved1_type reserved1;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__supported(
    const uint8_t & _arg)
  {
    this->supported = _arg;
    return *this;
  }
  Type & set__default_gnss(
    const uint8_t & _arg)
  {
    this->default_gnss = _arg;
    return *this;
  }
  Type & set__enabled(
    const uint8_t & _arg)
  {
    this->enabled = _arg;
    return *this;
  }
  Type & set__simultaneous(
    const uint8_t & _arg)
  {
    this->simultaneous = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    10u;
  static constexpr uint8_t MESSAGE_ID =
    40u;
  static constexpr uint8_t BIT_MASK_GPS =
    1u;
  static constexpr uint8_t BIT_MASK_GLONASS =
    2u;
  static constexpr uint8_t BIT_MASK_BEIDOU =
    4u;
  static constexpr uint8_t BIT_MASK_GALILEO =
    8u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::MonGNSS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::MonGNSS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonGNSS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonGNSS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__MonGNSS
    std::shared_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__MonGNSS
    std::shared_ptr<ublox_msgs::msg::MonGNSS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MonGNSS_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->supported != other.supported) {
      return false;
    }
    if (this->default_gnss != other.default_gnss) {
      return false;
    }
    if (this->enabled != other.enabled) {
      return false;
    }
    if (this->simultaneous != other.simultaneous) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    return true;
  }
  bool operator!=(const MonGNSS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MonGNSS_

// alias to use template instance with default allocator
using MonGNSS =
  ublox_msgs::msg::MonGNSS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonGNSS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonGNSS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonGNSS_<ContainerAllocator>::BIT_MASK_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonGNSS_<ContainerAllocator>::BIT_MASK_GLONASS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonGNSS_<ContainerAllocator>::BIT_MASK_BEIDOU;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonGNSS_<ContainerAllocator>::BIT_MASK_GALILEO;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_GNSS__STRUCT_HPP_

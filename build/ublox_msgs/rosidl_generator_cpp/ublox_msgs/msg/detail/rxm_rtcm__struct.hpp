// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmRTCM.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmRTCM __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmRTCM __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmRTCM_
{
  using Type = RxmRTCM_<ContainerAllocator>;

  explicit RxmRTCM_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->flags = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->ref_station = 0;
      this->msg_type = 0;
    }
  }

  explicit RxmRTCM_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->flags = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->ref_station = 0;
      this->msg_type = 0;
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _reserved0_type =
    std::array<uint8_t, 2>;
  _reserved0_type reserved0;
  using _ref_station_type =
    uint16_t;
  _ref_station_type ref_station;
  using _msg_type_type =
    uint16_t;
  _msg_type_type msg_type;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__ref_station(
    const uint16_t & _arg)
  {
    this->ref_station = _arg;
    return *this;
  }
  Type & set__msg_type(
    const uint16_t & _arg)
  {
    this->msg_type = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    2u;
  static constexpr uint8_t MESSAGE_ID =
    50u;
  static constexpr uint8_t FLAGS_CRC_FAILED =
    1u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmRTCM_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmRTCM_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRTCM_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRTCM_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmRTCM
    std::shared_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmRTCM
    std::shared_ptr<ublox_msgs::msg::RxmRTCM_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmRTCM_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->ref_station != other.ref_station) {
      return false;
    }
    if (this->msg_type != other.msg_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmRTCM_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmRTCM_

// alias to use template instance with default allocator
using RxmRTCM =
  ublox_msgs::msg::RxmRTCM_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRTCM_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRTCM_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRTCM_<ContainerAllocator>::FLAGS_CRC_FAILED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RTCM__STRUCT_HPP_

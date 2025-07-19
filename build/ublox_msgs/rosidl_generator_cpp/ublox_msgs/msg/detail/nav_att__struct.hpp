// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavATT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_ATT__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_ATT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavATT __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavATT __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavATT_
{
  using Type = NavATT_<ContainerAllocator>;

  explicit NavATT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->roll = 0l;
      this->pitch = 0l;
      this->heading = 0l;
      this->acc_roll = 0ul;
      this->acc_pitch = 0ul;
      this->acc_heading = 0ul;
    }
  }

  explicit NavATT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->roll = 0l;
      this->pitch = 0l;
      this->heading = 0l;
      this->acc_roll = 0ul;
      this->acc_pitch = 0ul;
      this->acc_heading = 0ul;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved0_type =
    std::array<uint8_t, 3>;
  _reserved0_type reserved0;
  using _roll_type =
    int32_t;
  _roll_type roll;
  using _pitch_type =
    int32_t;
  _pitch_type pitch;
  using _heading_type =
    int32_t;
  _heading_type heading;
  using _acc_roll_type =
    uint32_t;
  _acc_roll_type acc_roll;
  using _acc_pitch_type =
    uint32_t;
  _acc_pitch_type acc_pitch;
  using _acc_heading_type =
    uint32_t;
  _acc_heading_type acc_heading;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__roll(
    const int32_t & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const int32_t & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__heading(
    const int32_t & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__acc_roll(
    const uint32_t & _arg)
  {
    this->acc_roll = _arg;
    return *this;
  }
  Type & set__acc_pitch(
    const uint32_t & _arg)
  {
    this->acc_pitch = _arg;
    return *this;
  }
  Type & set__acc_heading(
    const uint32_t & _arg)
  {
    this->acc_heading = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    5u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavATT_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavATT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavATT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavATT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavATT
    std::shared_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavATT
    std::shared_ptr<ublox_msgs::msg::NavATT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavATT_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->acc_roll != other.acc_roll) {
      return false;
    }
    if (this->acc_pitch != other.acc_pitch) {
      return false;
    }
    if (this->acc_heading != other.acc_heading) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavATT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavATT_

// alias to use template instance with default allocator
using NavATT =
  ublox_msgs::msg::NavATT_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavATT_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavATT_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_ATT__STRUCT_HPP_

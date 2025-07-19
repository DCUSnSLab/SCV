// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/EsfINS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_INS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_INS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__EsfINS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__EsfINS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EsfINS_
{
  using Type = EsfINS_<ContainerAllocator>;

  explicit EsfINS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bitfield0 = 0ul;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->i_tow = 0ul;
      this->x_ang_rate = 0l;
      this->y_ang_rate = 0l;
      this->z_ang_rate = 0l;
      this->x_accel = 0l;
      this->y_accel = 0l;
      this->z_accel = 0l;
    }
  }

  explicit EsfINS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bitfield0 = 0ul;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->i_tow = 0ul;
      this->x_ang_rate = 0l;
      this->y_ang_rate = 0l;
      this->z_ang_rate = 0l;
      this->x_accel = 0l;
      this->y_accel = 0l;
      this->z_accel = 0l;
    }
  }

  // field types and members
  using _bitfield0_type =
    uint32_t;
  _bitfield0_type bitfield0;
  using _reserved1_type =
    std::array<uint8_t, 4>;
  _reserved1_type reserved1;
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _x_ang_rate_type =
    int32_t;
  _x_ang_rate_type x_ang_rate;
  using _y_ang_rate_type =
    int32_t;
  _y_ang_rate_type y_ang_rate;
  using _z_ang_rate_type =
    int32_t;
  _z_ang_rate_type z_ang_rate;
  using _x_accel_type =
    int32_t;
  _x_accel_type x_accel;
  using _y_accel_type =
    int32_t;
  _y_accel_type y_accel;
  using _z_accel_type =
    int32_t;
  _z_accel_type z_accel;

  // setters for named parameter idiom
  Type & set__bitfield0(
    const uint32_t & _arg)
  {
    this->bitfield0 = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 4> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__x_ang_rate(
    const int32_t & _arg)
  {
    this->x_ang_rate = _arg;
    return *this;
  }
  Type & set__y_ang_rate(
    const int32_t & _arg)
  {
    this->y_ang_rate = _arg;
    return *this;
  }
  Type & set__z_ang_rate(
    const int32_t & _arg)
  {
    this->z_ang_rate = _arg;
    return *this;
  }
  Type & set__x_accel(
    const int32_t & _arg)
  {
    this->x_accel = _arg;
    return *this;
  }
  Type & set__y_accel(
    const int32_t & _arg)
  {
    this->y_accel = _arg;
    return *this;
  }
  Type & set__z_accel(
    const int32_t & _arg)
  {
    this->z_accel = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    16u;
  static constexpr uint8_t MESSAGE_ID =
    21u;
  static constexpr uint32_t BITFIELD0_VERSION =
    255u;
  static constexpr uint32_t BITFIELD0_X_ANG_RATE_VALID =
    256u;
  static constexpr uint32_t BITFIELD0_Y_ANG_RATE_VALID =
    512u;
  static constexpr uint32_t BITFIELD0_Z_ANG_RATE_VALID =
    1024u;
  static constexpr uint32_t BITFIELD0_X_ACCEL_VALID =
    2048u;
  static constexpr uint32_t BITFIELD0_Y_ACCEL_VALID =
    4096u;
  static constexpr uint32_t BITFIELD0_Z_ACCEL_VALID =
    8192u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::EsfINS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::EsfINS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfINS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfINS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__EsfINS
    std::shared_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__EsfINS
    std::shared_ptr<ublox_msgs::msg::EsfINS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EsfINS_ & other) const
  {
    if (this->bitfield0 != other.bitfield0) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->x_ang_rate != other.x_ang_rate) {
      return false;
    }
    if (this->y_ang_rate != other.y_ang_rate) {
      return false;
    }
    if (this->z_ang_rate != other.z_ang_rate) {
      return false;
    }
    if (this->x_accel != other.x_accel) {
      return false;
    }
    if (this->y_accel != other.y_accel) {
      return false;
    }
    if (this->z_accel != other.z_accel) {
      return false;
    }
    return true;
  }
  bool operator!=(const EsfINS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EsfINS_

// alias to use template instance with default allocator
using EsfINS =
  ublox_msgs::msg::EsfINS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfINS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfINS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfINS_<ContainerAllocator>::BITFIELD0_VERSION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfINS_<ContainerAllocator>::BITFIELD0_X_ANG_RATE_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfINS_<ContainerAllocator>::BITFIELD0_Y_ANG_RATE_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfINS_<ContainerAllocator>::BITFIELD0_Z_ANG_RATE_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfINS_<ContainerAllocator>::BITFIELD0_X_ACCEL_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfINS_<ContainerAllocator>::BITFIELD0_Y_ACCEL_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfINS_<ContainerAllocator>::BITFIELD0_Z_ACCEL_VALID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_INS__STRUCT_HPP_

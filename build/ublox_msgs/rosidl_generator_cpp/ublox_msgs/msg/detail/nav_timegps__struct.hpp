// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavTIMEGPS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavTIMEGPS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavTIMEGPS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavTIMEGPS_
{
  using Type = NavTIMEGPS_<ContainerAllocator>;

  explicit NavTIMEGPS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->f_tow = 0l;
      this->week = 0;
      this->leap_s = 0;
      this->valid = 0;
      this->t_acc = 0ul;
    }
  }

  explicit NavTIMEGPS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->f_tow = 0l;
      this->week = 0;
      this->leap_s = 0;
      this->valid = 0;
      this->t_acc = 0ul;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _f_tow_type =
    int32_t;
  _f_tow_type f_tow;
  using _week_type =
    int16_t;
  _week_type week;
  using _leap_s_type =
    int8_t;
  _leap_s_type leap_s;
  using _valid_type =
    uint8_t;
  _valid_type valid;
  using _t_acc_type =
    uint32_t;
  _t_acc_type t_acc;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__f_tow(
    const int32_t & _arg)
  {
    this->f_tow = _arg;
    return *this;
  }
  Type & set__week(
    const int16_t & _arg)
  {
    this->week = _arg;
    return *this;
  }
  Type & set__leap_s(
    const int8_t & _arg)
  {
    this->leap_s = _arg;
    return *this;
  }
  Type & set__valid(
    const uint8_t & _arg)
  {
    this->valid = _arg;
    return *this;
  }
  Type & set__t_acc(
    const uint32_t & _arg)
  {
    this->t_acc = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    32u;
  static constexpr uint8_t VALID_TOW =
    1u;
  static constexpr uint8_t VALID_WEEK =
    2u;
  static constexpr uint8_t VALID_LEAP_S =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavTIMEGPS
    std::shared_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavTIMEGPS
    std::shared_ptr<ublox_msgs::msg::NavTIMEGPS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavTIMEGPS_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->f_tow != other.f_tow) {
      return false;
    }
    if (this->week != other.week) {
      return false;
    }
    if (this->leap_s != other.leap_s) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->t_acc != other.t_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavTIMEGPS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavTIMEGPS_

// alias to use template instance with default allocator
using NavTIMEGPS =
  ublox_msgs::msg::NavTIMEGPS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEGPS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEGPS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEGPS_<ContainerAllocator>::VALID_TOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEGPS_<ContainerAllocator>::VALID_WEEK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEGPS_<ContainerAllocator>::VALID_LEAP_S;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_TIMEGPS__STRUCT_HPP_

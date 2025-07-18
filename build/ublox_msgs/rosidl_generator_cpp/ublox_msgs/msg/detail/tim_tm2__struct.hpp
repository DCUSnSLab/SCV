// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/TimTM2.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__TIM_TM2__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__TIM_TM2__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__TimTM2 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__TimTM2 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TimTM2_
{
  using Type = TimTM2_<ContainerAllocator>;

  explicit TimTM2_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ch = 0;
      this->flags = 0;
      this->rising_edge_count = 0;
      this->wn_r = 0;
      this->wn_f = 0;
      this->tow_ms_r = 0ul;
      this->tow_sub_ms_r = 0ul;
      this->tow_ms_f = 0ul;
      this->tow_sub_ms_f = 0ul;
      this->acc_est = 0ul;
    }
  }

  explicit TimTM2_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ch = 0;
      this->flags = 0;
      this->rising_edge_count = 0;
      this->wn_r = 0;
      this->wn_f = 0;
      this->tow_ms_r = 0ul;
      this->tow_sub_ms_r = 0ul;
      this->tow_ms_f = 0ul;
      this->tow_sub_ms_f = 0ul;
      this->acc_est = 0ul;
    }
  }

  // field types and members
  using _ch_type =
    uint8_t;
  _ch_type ch;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _rising_edge_count_type =
    uint16_t;
  _rising_edge_count_type rising_edge_count;
  using _wn_r_type =
    uint16_t;
  _wn_r_type wn_r;
  using _wn_f_type =
    uint16_t;
  _wn_f_type wn_f;
  using _tow_ms_r_type =
    uint32_t;
  _tow_ms_r_type tow_ms_r;
  using _tow_sub_ms_r_type =
    uint32_t;
  _tow_sub_ms_r_type tow_sub_ms_r;
  using _tow_ms_f_type =
    uint32_t;
  _tow_ms_f_type tow_ms_f;
  using _tow_sub_ms_f_type =
    uint32_t;
  _tow_sub_ms_f_type tow_sub_ms_f;
  using _acc_est_type =
    uint32_t;
  _acc_est_type acc_est;

  // setters for named parameter idiom
  Type & set__ch(
    const uint8_t & _arg)
  {
    this->ch = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__rising_edge_count(
    const uint16_t & _arg)
  {
    this->rising_edge_count = _arg;
    return *this;
  }
  Type & set__wn_r(
    const uint16_t & _arg)
  {
    this->wn_r = _arg;
    return *this;
  }
  Type & set__wn_f(
    const uint16_t & _arg)
  {
    this->wn_f = _arg;
    return *this;
  }
  Type & set__tow_ms_r(
    const uint32_t & _arg)
  {
    this->tow_ms_r = _arg;
    return *this;
  }
  Type & set__tow_sub_ms_r(
    const uint32_t & _arg)
  {
    this->tow_sub_ms_r = _arg;
    return *this;
  }
  Type & set__tow_ms_f(
    const uint32_t & _arg)
  {
    this->tow_ms_f = _arg;
    return *this;
  }
  Type & set__tow_sub_ms_f(
    const uint32_t & _arg)
  {
    this->tow_sub_ms_f = _arg;
    return *this;
  }
  Type & set__acc_est(
    const uint32_t & _arg)
  {
    this->acc_est = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    13u;
  static constexpr uint8_t MESSAGE_ID =
    3u;
  static constexpr uint8_t FLAGS_MODE_RUNNING =
    1u;
  static constexpr uint8_t FLAGS_RUN =
    2u;
  static constexpr uint8_t FLAGS_NEWFALLINGEDGE =
    4u;
  static constexpr uint8_t FLAGS_TIMEBASE_GNSS =
    8u;
  static constexpr uint8_t FLAGS_TIMEBASE_UTC =
    16u;
  static constexpr uint8_t FLAGS_UTC_AVAIL =
    32u;
  static constexpr uint8_t FLAGS_TIME_VALID =
    64u;
  static constexpr uint8_t FLAGS_NEWRISINGEDGE =
    128u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::TimTM2_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::TimTM2_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::TimTM2_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::TimTM2_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__TimTM2
    std::shared_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__TimTM2
    std::shared_ptr<ublox_msgs::msg::TimTM2_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TimTM2_ & other) const
  {
    if (this->ch != other.ch) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->rising_edge_count != other.rising_edge_count) {
      return false;
    }
    if (this->wn_r != other.wn_r) {
      return false;
    }
    if (this->wn_f != other.wn_f) {
      return false;
    }
    if (this->tow_ms_r != other.tow_ms_r) {
      return false;
    }
    if (this->tow_sub_ms_r != other.tow_sub_ms_r) {
      return false;
    }
    if (this->tow_ms_f != other.tow_ms_f) {
      return false;
    }
    if (this->tow_sub_ms_f != other.tow_sub_ms_f) {
      return false;
    }
    if (this->acc_est != other.acc_est) {
      return false;
    }
    return true;
  }
  bool operator!=(const TimTM2_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TimTM2_

// alias to use template instance with default allocator
using TimTM2 =
  ublox_msgs::msg::TimTM2_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_MODE_RUNNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_RUN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_NEWFALLINGEDGE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_TIMEBASE_GNSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_TIMEBASE_UTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_UTC_AVAIL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_TIME_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TimTM2_<ContainerAllocator>::FLAGS_NEWRISINGEDGE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__TIM_TM2__STRUCT_HPP_

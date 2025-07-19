// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavTIMEUTC.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavTIMEUTC __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavTIMEUTC __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavTIMEUTC_
{
  using Type = NavTIMEUTC_<ContainerAllocator>;

  explicit NavTIMEUTC_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->t_acc = 0ul;
      this->nano = 0l;
      this->year = 0;
      this->month = 0;
      this->day = 0;
      this->hour = 0;
      this->min = 0;
      this->sec = 0;
      this->valid = 0;
    }
  }

  explicit NavTIMEUTC_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->t_acc = 0ul;
      this->nano = 0l;
      this->year = 0;
      this->month = 0;
      this->day = 0;
      this->hour = 0;
      this->min = 0;
      this->sec = 0;
      this->valid = 0;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _t_acc_type =
    uint32_t;
  _t_acc_type t_acc;
  using _nano_type =
    int32_t;
  _nano_type nano;
  using _year_type =
    uint16_t;
  _year_type year;
  using _month_type =
    uint8_t;
  _month_type month;
  using _day_type =
    uint8_t;
  _day_type day;
  using _hour_type =
    uint8_t;
  _hour_type hour;
  using _min_type =
    uint8_t;
  _min_type min;
  using _sec_type =
    uint8_t;
  _sec_type sec;
  using _valid_type =
    uint8_t;
  _valid_type valid;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__t_acc(
    const uint32_t & _arg)
  {
    this->t_acc = _arg;
    return *this;
  }
  Type & set__nano(
    const int32_t & _arg)
  {
    this->nano = _arg;
    return *this;
  }
  Type & set__year(
    const uint16_t & _arg)
  {
    this->year = _arg;
    return *this;
  }
  Type & set__month(
    const uint8_t & _arg)
  {
    this->month = _arg;
    return *this;
  }
  Type & set__day(
    const uint8_t & _arg)
  {
    this->day = _arg;
    return *this;
  }
  Type & set__hour(
    const uint8_t & _arg)
  {
    this->hour = _arg;
    return *this;
  }
  Type & set__min(
    const uint8_t & _arg)
  {
    this->min = _arg;
    return *this;
  }
  Type & set__sec(
    const uint8_t & _arg)
  {
    this->sec = _arg;
    return *this;
  }
  Type & set__valid(
    const uint8_t & _arg)
  {
    this->valid = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    33u;
  static constexpr uint8_t VALID_TOW =
    1u;
  static constexpr uint8_t VALID_WKN =
    2u;
  static constexpr uint8_t VALID_UTC =
    4u;
  static constexpr uint8_t VALID_UTC_STANDARD_MASK =
    240u;
  static constexpr uint8_t UTC_STANDARD_NOT_AVAILABLE =
    0u;
  static constexpr uint8_t UTC_STANDARD_CRL =
    16u;
  static constexpr uint8_t UTC_STANDARD_NIST =
    32u;
  static constexpr uint8_t UTC_STANDARD_USNO =
    48u;
  static constexpr uint8_t UTC_STANDARD_BIPM =
    64u;
  static constexpr uint8_t UTC_STANDARD_EL =
    80u;
  static constexpr uint8_t UTC_STANDARD_SU =
    96u;
  static constexpr uint8_t UTC_STANDARD_NTSC =
    112u;
  static constexpr uint8_t UTC_STANDARD_UNKNOWN =
    240u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavTIMEUTC
    std::shared_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavTIMEUTC
    std::shared_ptr<ublox_msgs::msg::NavTIMEUTC_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavTIMEUTC_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->t_acc != other.t_acc) {
      return false;
    }
    if (this->nano != other.nano) {
      return false;
    }
    if (this->year != other.year) {
      return false;
    }
    if (this->month != other.month) {
      return false;
    }
    if (this->day != other.day) {
      return false;
    }
    if (this->hour != other.hour) {
      return false;
    }
    if (this->min != other.min) {
      return false;
    }
    if (this->sec != other.sec) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavTIMEUTC_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavTIMEUTC_

// alias to use template instance with default allocator
using NavTIMEUTC =
  ublox_msgs::msg::NavTIMEUTC_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::VALID_TOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::VALID_WKN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::VALID_UTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::VALID_UTC_STANDARD_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_NOT_AVAILABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_CRL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_NIST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_USNO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_BIPM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_EL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_SU;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_NTSC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavTIMEUTC_<ContainerAllocator>::UTC_STANDARD_UNKNOWN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_TIMEUTC__STRUCT_HPP_

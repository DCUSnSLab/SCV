// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSBAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_sbassv__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSBAS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSBAS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSBAS_
{
  using Type = NavSBAS_<ContainerAllocator>;

  explicit NavSBAS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->geo = 0;
      this->mode = 0;
      this->sys = 0;
      this->service = 0;
      this->cnt = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  explicit NavSBAS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->geo = 0;
      this->mode = 0;
      this->sys = 0;
      this->service = 0;
      this->cnt = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _geo_type =
    uint8_t;
  _geo_type geo;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _sys_type =
    int8_t;
  _sys_type sys;
  using _service_type =
    uint8_t;
  _service_type service;
  using _cnt_type =
    uint8_t;
  _cnt_type cnt;
  using _reserved0_type =
    std::array<uint8_t, 3>;
  _reserved0_type reserved0;
  using _sv_type =
    std::vector<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>>>;
  _sv_type sv;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__geo(
    const uint8_t & _arg)
  {
    this->geo = _arg;
    return *this;
  }
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__sys(
    const int8_t & _arg)
  {
    this->sys = _arg;
    return *this;
  }
  Type & set__service(
    const uint8_t & _arg)
  {
    this->service = _arg;
    return *this;
  }
  Type & set__cnt(
    const uint8_t & _arg)
  {
    this->cnt = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__sv(
    const std::vector<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>>> & _arg)
  {
    this->sv = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    50u;
  static constexpr uint8_t MODE_DISABLED =
    0u;
  static constexpr uint8_t MODE_ENABLED_INTEGRITY =
    1u;
  static constexpr uint8_t MODE_ENABLED_TESTMODE =
    3u;
  static constexpr int8_t SYS_UNKNOWN =
    -1;
  static constexpr int8_t SYS_WAAS =
    0;
  static constexpr int8_t SYS_EGNOS =
    1;
  static constexpr int8_t SYS_MSAS =
    2;
  static constexpr int8_t SYS_GAGAN =
    3;
  static constexpr int8_t SYS_GPS =
    16;
  static constexpr uint8_t SERVICE_RANGING =
    1u;
  static constexpr uint8_t SERVICE_CORRECTIONS =
    2u;
  static constexpr uint8_t SERVICE_INTEGRITY =
    4u;
  static constexpr uint8_t SERVICE_TESTMODE =
    8u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSBAS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSBAS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSBAS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSBAS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSBAS
    std::shared_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSBAS
    std::shared_ptr<ublox_msgs::msg::NavSBAS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSBAS_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->geo != other.geo) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->sys != other.sys) {
      return false;
    }
    if (this->service != other.service) {
      return false;
    }
    if (this->cnt != other.cnt) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->sv != other.sv) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSBAS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSBAS_

// alias to use template instance with default allocator
using NavSBAS =
  ublox_msgs::msg::NavSBAS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::MODE_DISABLED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::MODE_ENABLED_INTEGRITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::MODE_ENABLED_TESTMODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t NavSBAS_<ContainerAllocator>::SYS_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t NavSBAS_<ContainerAllocator>::SYS_WAAS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t NavSBAS_<ContainerAllocator>::SYS_EGNOS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t NavSBAS_<ContainerAllocator>::SYS_MSAS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t NavSBAS_<ContainerAllocator>::SYS_GAGAN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t NavSBAS_<ContainerAllocator>::SYS_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::SERVICE_RANGING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::SERVICE_CORRECTIONS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::SERVICE_INTEGRITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSBAS_<ContainerAllocator>::SERVICE_TESTMODE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SBAS__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgNMEA6.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgNMEA6 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgNMEA6 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgNMEA6_
{
  using Type = CfgNMEA6_<ContainerAllocator>;

  explicit CfgNMEA6_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter = 0;
      this->version = 0;
      this->num_sv = 0;
      this->flags = 0;
    }
  }

  explicit CfgNMEA6_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter = 0;
      this->version = 0;
      this->num_sv = 0;
      this->flags = 0;
    }
  }

  // field types and members
  using _filter_type =
    uint8_t;
  _filter_type filter;
  using _version_type =
    uint8_t;
  _version_type version;
  using _num_sv_type =
    uint8_t;
  _num_sv_type num_sv;
  using _flags_type =
    uint8_t;
  _flags_type flags;

  // setters for named parameter idiom
  Type & set__filter(
    const uint8_t & _arg)
  {
    this->filter = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__num_sv(
    const uint8_t & _arg)
  {
    this->num_sv = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    23u;
  static constexpr uint8_t FILTER_POS =
    1u;
  static constexpr uint8_t FILTER_MSK_POS =
    2u;
  static constexpr uint8_t FILTER_TIME =
    4u;
  static constexpr uint8_t FILTER_DATE =
    8u;
  static constexpr uint8_t FILTER_SBAS_FILT =
    16u;
  static constexpr uint8_t FILTER_TRACK =
    32u;
  static constexpr uint8_t NMEA_VERSION_2_3 =
    35u;
  static constexpr uint8_t NMEA_VERSION_2_1 =
    33u;
  static constexpr uint8_t FLAGS_COMPAT =
    1u;
  static constexpr uint8_t FLAGS_CONSIDER =
    2u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgNMEA6_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgNMEA6_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNMEA6_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNMEA6_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgNMEA6
    std::shared_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgNMEA6
    std::shared_ptr<ublox_msgs::msg::CfgNMEA6_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgNMEA6_ & other) const
  {
    if (this->filter != other.filter) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->num_sv != other.num_sv) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgNMEA6_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgNMEA6_

// alias to use template instance with default allocator
using CfgNMEA6 =
  ublox_msgs::msg::CfgNMEA6_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FILTER_POS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FILTER_MSK_POS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FILTER_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FILTER_DATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FILTER_SBAS_FILT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FILTER_TRACK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::NMEA_VERSION_2_3;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::NMEA_VERSION_2_1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FLAGS_COMPAT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA6_<ContainerAllocator>::FLAGS_CONSIDER;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA6__STRUCT_HPP_

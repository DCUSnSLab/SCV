// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSVINFO.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVINFO__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVINFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_svinfosv__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSVINFO __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSVINFO __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSVINFO_
{
  using Type = NavSVINFO_<ContainerAllocator>;

  explicit NavSVINFO_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->num_ch = 0;
      this->global_flags = 0;
      this->reserved2 = 0;
    }
  }

  explicit NavSVINFO_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->num_ch = 0;
      this->global_flags = 0;
      this->reserved2 = 0;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _num_ch_type =
    uint8_t;
  _num_ch_type num_ch;
  using _global_flags_type =
    uint8_t;
  _global_flags_type global_flags;
  using _reserved2_type =
    uint16_t;
  _reserved2_type reserved2;
  using _sv_type =
    std::vector<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>>>;
  _sv_type sv;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__num_ch(
    const uint8_t & _arg)
  {
    this->num_ch = _arg;
    return *this;
  }
  Type & set__global_flags(
    const uint8_t & _arg)
  {
    this->global_flags = _arg;
    return *this;
  }
  Type & set__reserved2(
    const uint16_t & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }
  Type & set__sv(
    const std::vector<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>>> & _arg)
  {
    this->sv = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    48u;
  static constexpr uint8_t CHIPGEN_ANTARIS =
    0u;
  static constexpr uint8_t CHIPGEN_UBLOX5 =
    1u;
  static constexpr uint8_t CHIPGEN_UBLOX6 =
    2u;
  static constexpr uint8_t CHIPGEN_UBLOX7 =
    3u;
  static constexpr uint8_t CHIPGEN_UBLOX8 =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSVINFO_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSVINFO_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSVINFO_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSVINFO_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSVINFO
    std::shared_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSVINFO
    std::shared_ptr<ublox_msgs::msg::NavSVINFO_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSVINFO_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->num_ch != other.num_ch) {
      return false;
    }
    if (this->global_flags != other.global_flags) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    if (this->sv != other.sv) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSVINFO_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSVINFO_

// alias to use template instance with default allocator
using NavSVINFO =
  ublox_msgs::msg::NavSVINFO_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFO_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFO_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFO_<ContainerAllocator>::CHIPGEN_ANTARIS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFO_<ContainerAllocator>::CHIPGEN_UBLOX5;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFO_<ContainerAllocator>::CHIPGEN_UBLOX6;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFO_<ContainerAllocator>::CHIPGEN_UBLOX7;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFO_<ContainerAllocator>::CHIPGEN_UBLOX8;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVINFO__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/AidHUI.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_HUI__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_HUI__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__AidHUI __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__AidHUI __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AidHUI_
{
  using Type = AidHUI_<ContainerAllocator>;

  explicit AidHUI_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->health = 0ul;
      this->utc_a0 = 0.0;
      this->utc_a1 = 0.0;
      this->utc_tow = 0l;
      this->utc_wnt = 0;
      this->utc_ls = 0;
      this->utc_wnf = 0;
      this->utc_dn = 0;
      this->utc_lsf = 0;
      this->utc_spare = 0;
      this->klob_a0 = 0.0f;
      this->klob_a1 = 0.0f;
      this->klob_a2 = 0.0f;
      this->klob_a3 = 0.0f;
      this->klob_b0 = 0.0f;
      this->klob_b1 = 0.0f;
      this->klob_b2 = 0.0f;
      this->klob_b3 = 0.0f;
      this->flags = 0ul;
    }
  }

  explicit AidHUI_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->health = 0ul;
      this->utc_a0 = 0.0;
      this->utc_a1 = 0.0;
      this->utc_tow = 0l;
      this->utc_wnt = 0;
      this->utc_ls = 0;
      this->utc_wnf = 0;
      this->utc_dn = 0;
      this->utc_lsf = 0;
      this->utc_spare = 0;
      this->klob_a0 = 0.0f;
      this->klob_a1 = 0.0f;
      this->klob_a2 = 0.0f;
      this->klob_a3 = 0.0f;
      this->klob_b0 = 0.0f;
      this->klob_b1 = 0.0f;
      this->klob_b2 = 0.0f;
      this->klob_b3 = 0.0f;
      this->flags = 0ul;
    }
  }

  // field types and members
  using _health_type =
    uint32_t;
  _health_type health;
  using _utc_a0_type =
    double;
  _utc_a0_type utc_a0;
  using _utc_a1_type =
    double;
  _utc_a1_type utc_a1;
  using _utc_tow_type =
    int32_t;
  _utc_tow_type utc_tow;
  using _utc_wnt_type =
    int16_t;
  _utc_wnt_type utc_wnt;
  using _utc_ls_type =
    int16_t;
  _utc_ls_type utc_ls;
  using _utc_wnf_type =
    int16_t;
  _utc_wnf_type utc_wnf;
  using _utc_dn_type =
    int16_t;
  _utc_dn_type utc_dn;
  using _utc_lsf_type =
    int16_t;
  _utc_lsf_type utc_lsf;
  using _utc_spare_type =
    int16_t;
  _utc_spare_type utc_spare;
  using _klob_a0_type =
    float;
  _klob_a0_type klob_a0;
  using _klob_a1_type =
    float;
  _klob_a1_type klob_a1;
  using _klob_a2_type =
    float;
  _klob_a2_type klob_a2;
  using _klob_a3_type =
    float;
  _klob_a3_type klob_a3;
  using _klob_b0_type =
    float;
  _klob_b0_type klob_b0;
  using _klob_b1_type =
    float;
  _klob_b1_type klob_b1;
  using _klob_b2_type =
    float;
  _klob_b2_type klob_b2;
  using _klob_b3_type =
    float;
  _klob_b3_type klob_b3;
  using _flags_type =
    uint32_t;
  _flags_type flags;

  // setters for named parameter idiom
  Type & set__health(
    const uint32_t & _arg)
  {
    this->health = _arg;
    return *this;
  }
  Type & set__utc_a0(
    const double & _arg)
  {
    this->utc_a0 = _arg;
    return *this;
  }
  Type & set__utc_a1(
    const double & _arg)
  {
    this->utc_a1 = _arg;
    return *this;
  }
  Type & set__utc_tow(
    const int32_t & _arg)
  {
    this->utc_tow = _arg;
    return *this;
  }
  Type & set__utc_wnt(
    const int16_t & _arg)
  {
    this->utc_wnt = _arg;
    return *this;
  }
  Type & set__utc_ls(
    const int16_t & _arg)
  {
    this->utc_ls = _arg;
    return *this;
  }
  Type & set__utc_wnf(
    const int16_t & _arg)
  {
    this->utc_wnf = _arg;
    return *this;
  }
  Type & set__utc_dn(
    const int16_t & _arg)
  {
    this->utc_dn = _arg;
    return *this;
  }
  Type & set__utc_lsf(
    const int16_t & _arg)
  {
    this->utc_lsf = _arg;
    return *this;
  }
  Type & set__utc_spare(
    const int16_t & _arg)
  {
    this->utc_spare = _arg;
    return *this;
  }
  Type & set__klob_a0(
    const float & _arg)
  {
    this->klob_a0 = _arg;
    return *this;
  }
  Type & set__klob_a1(
    const float & _arg)
  {
    this->klob_a1 = _arg;
    return *this;
  }
  Type & set__klob_a2(
    const float & _arg)
  {
    this->klob_a2 = _arg;
    return *this;
  }
  Type & set__klob_a3(
    const float & _arg)
  {
    this->klob_a3 = _arg;
    return *this;
  }
  Type & set__klob_b0(
    const float & _arg)
  {
    this->klob_b0 = _arg;
    return *this;
  }
  Type & set__klob_b1(
    const float & _arg)
  {
    this->klob_b1 = _arg;
    return *this;
  }
  Type & set__klob_b2(
    const float & _arg)
  {
    this->klob_b2 = _arg;
    return *this;
  }
  Type & set__klob_b3(
    const float & _arg)
  {
    this->klob_b3 = _arg;
    return *this;
  }
  Type & set__flags(
    const uint32_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    11u;
  static constexpr uint8_t MESSAGE_ID =
    2u;
  static constexpr uint32_t FLAGS_HEALTH =
    1u;
  static constexpr uint32_t FLAGS_UTC =
    2u;
  static constexpr uint32_t FLAGS_KLOB =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::AidHUI_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::AidHUI_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::AidHUI_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::AidHUI_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__AidHUI
    std::shared_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__AidHUI
    std::shared_ptr<ublox_msgs::msg::AidHUI_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AidHUI_ & other) const
  {
    if (this->health != other.health) {
      return false;
    }
    if (this->utc_a0 != other.utc_a0) {
      return false;
    }
    if (this->utc_a1 != other.utc_a1) {
      return false;
    }
    if (this->utc_tow != other.utc_tow) {
      return false;
    }
    if (this->utc_wnt != other.utc_wnt) {
      return false;
    }
    if (this->utc_ls != other.utc_ls) {
      return false;
    }
    if (this->utc_wnf != other.utc_wnf) {
      return false;
    }
    if (this->utc_dn != other.utc_dn) {
      return false;
    }
    if (this->utc_lsf != other.utc_lsf) {
      return false;
    }
    if (this->utc_spare != other.utc_spare) {
      return false;
    }
    if (this->klob_a0 != other.klob_a0) {
      return false;
    }
    if (this->klob_a1 != other.klob_a1) {
      return false;
    }
    if (this->klob_a2 != other.klob_a2) {
      return false;
    }
    if (this->klob_a3 != other.klob_a3) {
      return false;
    }
    if (this->klob_b0 != other.klob_b0) {
      return false;
    }
    if (this->klob_b1 != other.klob_b1) {
      return false;
    }
    if (this->klob_b2 != other.klob_b2) {
      return false;
    }
    if (this->klob_b3 != other.klob_b3) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    return true;
  }
  bool operator!=(const AidHUI_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AidHUI_

// alias to use template instance with default allocator
using AidHUI =
  ublox_msgs::msg::AidHUI_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AidHUI_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AidHUI_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t AidHUI_<ContainerAllocator>::FLAGS_HEALTH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t AidHUI_<ContainerAllocator>::FLAGS_UTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t AidHUI_<ContainerAllocator>::FLAGS_KLOB;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_HUI__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgTMODE3 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgTMODE3 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgTMODE3_
{
  using Type = CfgTMODE3_<ContainerAllocator>;

  explicit CfgTMODE3_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->reserved1 = 0;
      this->flags = 0;
      this->ecef_x_or_lat = 0l;
      this->ecef_y_or_lon = 0l;
      this->ecef_z_or_alt = 0l;
      this->ecef_x_or_lat_hp = 0;
      this->ecef_y_or_lon_hp = 0;
      this->ecef_z_or_alt_hp = 0;
      this->reserved2 = 0;
      this->fixed_pos_acc = 0ul;
      this->svin_min_dur = 0ul;
      this->svin_acc_limit = 0ul;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
    }
  }

  explicit CfgTMODE3_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved3(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->reserved1 = 0;
      this->flags = 0;
      this->ecef_x_or_lat = 0l;
      this->ecef_y_or_lon = 0l;
      this->ecef_z_or_alt = 0l;
      this->ecef_x_or_lat_hp = 0;
      this->ecef_y_or_lon_hp = 0;
      this->ecef_z_or_alt_hp = 0;
      this->reserved2 = 0;
      this->fixed_pos_acc = 0ul;
      this->svin_min_dur = 0ul;
      this->svin_acc_limit = 0ul;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _flags_type =
    uint16_t;
  _flags_type flags;
  using _ecef_x_or_lat_type =
    int32_t;
  _ecef_x_or_lat_type ecef_x_or_lat;
  using _ecef_y_or_lon_type =
    int32_t;
  _ecef_y_or_lon_type ecef_y_or_lon;
  using _ecef_z_or_alt_type =
    int32_t;
  _ecef_z_or_alt_type ecef_z_or_alt;
  using _ecef_x_or_lat_hp_type =
    int8_t;
  _ecef_x_or_lat_hp_type ecef_x_or_lat_hp;
  using _ecef_y_or_lon_hp_type =
    int8_t;
  _ecef_y_or_lon_hp_type ecef_y_or_lon_hp;
  using _ecef_z_or_alt_hp_type =
    int8_t;
  _ecef_z_or_alt_hp_type ecef_z_or_alt_hp;
  using _reserved2_type =
    uint8_t;
  _reserved2_type reserved2;
  using _fixed_pos_acc_type =
    uint32_t;
  _fixed_pos_acc_type fixed_pos_acc;
  using _svin_min_dur_type =
    uint32_t;
  _svin_min_dur_type svin_min_dur;
  using _svin_acc_limit_type =
    uint32_t;
  _svin_acc_limit_type svin_acc_limit;
  using _reserved3_type =
    std::array<uint8_t, 8>;
  _reserved3_type reserved3;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__flags(
    const uint16_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__ecef_x_or_lat(
    const int32_t & _arg)
  {
    this->ecef_x_or_lat = _arg;
    return *this;
  }
  Type & set__ecef_y_or_lon(
    const int32_t & _arg)
  {
    this->ecef_y_or_lon = _arg;
    return *this;
  }
  Type & set__ecef_z_or_alt(
    const int32_t & _arg)
  {
    this->ecef_z_or_alt = _arg;
    return *this;
  }
  Type & set__ecef_x_or_lat_hp(
    const int8_t & _arg)
  {
    this->ecef_x_or_lat_hp = _arg;
    return *this;
  }
  Type & set__ecef_y_or_lon_hp(
    const int8_t & _arg)
  {
    this->ecef_y_or_lon_hp = _arg;
    return *this;
  }
  Type & set__ecef_z_or_alt_hp(
    const int8_t & _arg)
  {
    this->ecef_z_or_alt_hp = _arg;
    return *this;
  }
  Type & set__reserved2(
    const uint8_t & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }
  Type & set__fixed_pos_acc(
    const uint32_t & _arg)
  {
    this->fixed_pos_acc = _arg;
    return *this;
  }
  Type & set__svin_min_dur(
    const uint32_t & _arg)
  {
    this->svin_min_dur = _arg;
    return *this;
  }
  Type & set__svin_acc_limit(
    const uint32_t & _arg)
  {
    this->svin_acc_limit = _arg;
    return *this;
  }
  Type & set__reserved3(
    const std::array<uint8_t, 8> & _arg)
  {
    this->reserved3 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    113u;
  static constexpr uint16_t FLAGS_MODE_MASK =
    255u;
  static constexpr uint16_t FLAGS_MODE_DISABLED =
    0u;
  static constexpr uint16_t FLAGS_MODE_SURVEY_IN =
    1u;
  static constexpr uint16_t FLAGS_MODE_FIXED =
    2u;
  static constexpr uint16_t FLAGS_LLA =
    256u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgTMODE3_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgTMODE3_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgTMODE3_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgTMODE3_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgTMODE3
    std::shared_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgTMODE3
    std::shared_ptr<ublox_msgs::msg::CfgTMODE3_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgTMODE3_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->ecef_x_or_lat != other.ecef_x_or_lat) {
      return false;
    }
    if (this->ecef_y_or_lon != other.ecef_y_or_lon) {
      return false;
    }
    if (this->ecef_z_or_alt != other.ecef_z_or_alt) {
      return false;
    }
    if (this->ecef_x_or_lat_hp != other.ecef_x_or_lat_hp) {
      return false;
    }
    if (this->ecef_y_or_lon_hp != other.ecef_y_or_lon_hp) {
      return false;
    }
    if (this->ecef_z_or_alt_hp != other.ecef_z_or_alt_hp) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    if (this->fixed_pos_acc != other.fixed_pos_acc) {
      return false;
    }
    if (this->svin_min_dur != other.svin_min_dur) {
      return false;
    }
    if (this->svin_acc_limit != other.svin_acc_limit) {
      return false;
    }
    if (this->reserved3 != other.reserved3) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgTMODE3_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgTMODE3_

// alias to use template instance with default allocator
using CfgTMODE3 =
  ublox_msgs::msg::CfgTMODE3_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgTMODE3_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgTMODE3_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgTMODE3_<ContainerAllocator>::FLAGS_MODE_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgTMODE3_<ContainerAllocator>::FLAGS_MODE_DISABLED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgTMODE3_<ContainerAllocator>::FLAGS_MODE_SURVEY_IN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgTMODE3_<ContainerAllocator>::FLAGS_MODE_FIXED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgTMODE3_<ContainerAllocator>::FLAGS_LLA;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_TMODE3__STRUCT_HPP_

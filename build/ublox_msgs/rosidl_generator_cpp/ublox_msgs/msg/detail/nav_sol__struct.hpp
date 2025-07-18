// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSOL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SOL__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SOL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSOL __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSOL __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSOL_
{
  using Type = NavSOL_<ContainerAllocator>;

  explicit NavSOL_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->f_tow = 0l;
      this->week = 0;
      this->gps_fix = 0;
      this->flags = 0;
      this->ecef_x = 0l;
      this->ecef_y = 0l;
      this->ecef_z = 0l;
      this->p_acc = 0ul;
      this->ecef_vx = 0l;
      this->ecef_vy = 0l;
      this->ecef_vz = 0l;
      this->s_acc = 0ul;
      this->p_dop = 0;
      this->reserved1 = 0;
      this->num_sv = 0;
      this->reserved2 = 0ul;
    }
  }

  explicit NavSOL_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->f_tow = 0l;
      this->week = 0;
      this->gps_fix = 0;
      this->flags = 0;
      this->ecef_x = 0l;
      this->ecef_y = 0l;
      this->ecef_z = 0l;
      this->p_acc = 0ul;
      this->ecef_vx = 0l;
      this->ecef_vy = 0l;
      this->ecef_vz = 0l;
      this->s_acc = 0ul;
      this->p_dop = 0;
      this->reserved1 = 0;
      this->num_sv = 0;
      this->reserved2 = 0ul;
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
  using _gps_fix_type =
    uint8_t;
  _gps_fix_type gps_fix;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _ecef_x_type =
    int32_t;
  _ecef_x_type ecef_x;
  using _ecef_y_type =
    int32_t;
  _ecef_y_type ecef_y;
  using _ecef_z_type =
    int32_t;
  _ecef_z_type ecef_z;
  using _p_acc_type =
    uint32_t;
  _p_acc_type p_acc;
  using _ecef_vx_type =
    int32_t;
  _ecef_vx_type ecef_vx;
  using _ecef_vy_type =
    int32_t;
  _ecef_vy_type ecef_vy;
  using _ecef_vz_type =
    int32_t;
  _ecef_vz_type ecef_vz;
  using _s_acc_type =
    uint32_t;
  _s_acc_type s_acc;
  using _p_dop_type =
    uint16_t;
  _p_dop_type p_dop;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _num_sv_type =
    uint8_t;
  _num_sv_type num_sv;
  using _reserved2_type =
    uint32_t;
  _reserved2_type reserved2;

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
  Type & set__gps_fix(
    const uint8_t & _arg)
  {
    this->gps_fix = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__ecef_x(
    const int32_t & _arg)
  {
    this->ecef_x = _arg;
    return *this;
  }
  Type & set__ecef_y(
    const int32_t & _arg)
  {
    this->ecef_y = _arg;
    return *this;
  }
  Type & set__ecef_z(
    const int32_t & _arg)
  {
    this->ecef_z = _arg;
    return *this;
  }
  Type & set__p_acc(
    const uint32_t & _arg)
  {
    this->p_acc = _arg;
    return *this;
  }
  Type & set__ecef_vx(
    const int32_t & _arg)
  {
    this->ecef_vx = _arg;
    return *this;
  }
  Type & set__ecef_vy(
    const int32_t & _arg)
  {
    this->ecef_vy = _arg;
    return *this;
  }
  Type & set__ecef_vz(
    const int32_t & _arg)
  {
    this->ecef_vz = _arg;
    return *this;
  }
  Type & set__s_acc(
    const uint32_t & _arg)
  {
    this->s_acc = _arg;
    return *this;
  }
  Type & set__p_dop(
    const uint16_t & _arg)
  {
    this->p_dop = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__num_sv(
    const uint8_t & _arg)
  {
    this->num_sv = _arg;
    return *this;
  }
  Type & set__reserved2(
    const uint32_t & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    6u;
  static constexpr uint8_t GPS_NO_FIX =
    0u;
  static constexpr uint8_t GPS_DEAD_RECKONING_ONLY =
    1u;
  static constexpr uint8_t GPS_2D_FIX =
    2u;
  static constexpr uint8_t GPS_3D_FIX =
    3u;
  static constexpr uint8_t GPS_GPS_DEAD_RECKONING_COMBINED =
    4u;
  static constexpr uint8_t GPS_TIME_ONLY_FIX =
    5u;
  static constexpr uint8_t FLAGS_GPS_FIX_OK =
    1u;
  static constexpr uint8_t FLAGS_DIFF_SOLN =
    2u;
  static constexpr uint8_t FLAGS_WKNSET =
    4u;
  static constexpr uint8_t FLAGS_TOWSET =
    8u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSOL_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSOL_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSOL_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSOL_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSOL
    std::shared_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSOL
    std::shared_ptr<ublox_msgs::msg::NavSOL_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSOL_ & other) const
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
    if (this->gps_fix != other.gps_fix) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->ecef_x != other.ecef_x) {
      return false;
    }
    if (this->ecef_y != other.ecef_y) {
      return false;
    }
    if (this->ecef_z != other.ecef_z) {
      return false;
    }
    if (this->p_acc != other.p_acc) {
      return false;
    }
    if (this->ecef_vx != other.ecef_vx) {
      return false;
    }
    if (this->ecef_vy != other.ecef_vy) {
      return false;
    }
    if (this->ecef_vz != other.ecef_vz) {
      return false;
    }
    if (this->s_acc != other.s_acc) {
      return false;
    }
    if (this->p_dop != other.p_dop) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->num_sv != other.num_sv) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSOL_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSOL_

// alias to use template instance with default allocator
using NavSOL =
  ublox_msgs::msg::NavSOL_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::GPS_NO_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::GPS_DEAD_RECKONING_ONLY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::GPS_2D_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::GPS_3D_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::GPS_GPS_DEAD_RECKONING_COMBINED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::GPS_TIME_ONLY_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::FLAGS_GPS_FIX_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::FLAGS_DIFF_SOLN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::FLAGS_WKNSET;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSOL_<ContainerAllocator>::FLAGS_TOWSET;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SOL__STRUCT_HPP_

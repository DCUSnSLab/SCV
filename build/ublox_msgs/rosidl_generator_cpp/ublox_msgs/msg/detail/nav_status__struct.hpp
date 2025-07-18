// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSTATUS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSTATUS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSTATUS_
{
  using Type = NavSTATUS_<ContainerAllocator>;

  explicit NavSTATUS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->gps_fix = 0;
      this->flags = 0;
      this->fix_stat = 0;
      this->flags2 = 0;
      this->ttff = 0ul;
      this->msss = 0ul;
    }
  }

  explicit NavSTATUS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->gps_fix = 0;
      this->flags = 0;
      this->fix_stat = 0;
      this->flags2 = 0;
      this->ttff = 0ul;
      this->msss = 0ul;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _gps_fix_type =
    uint8_t;
  _gps_fix_type gps_fix;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _fix_stat_type =
    uint8_t;
  _fix_stat_type fix_stat;
  using _flags2_type =
    uint8_t;
  _flags2_type flags2;
  using _ttff_type =
    uint32_t;
  _ttff_type ttff;
  using _msss_type =
    uint32_t;
  _msss_type msss;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
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
  Type & set__fix_stat(
    const uint8_t & _arg)
  {
    this->fix_stat = _arg;
    return *this;
  }
  Type & set__flags2(
    const uint8_t & _arg)
  {
    this->flags2 = _arg;
    return *this;
  }
  Type & set__ttff(
    const uint32_t & _arg)
  {
    this->ttff = _arg;
    return *this;
  }
  Type & set__msss(
    const uint32_t & _arg)
  {
    this->msss = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    3u;
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
  static constexpr uint8_t FIX_STAT_DIFF_CORR_MASK =
    1u;
  static constexpr uint8_t FIX_STAT_MAP_MATCHING_MASK =
    192u;
  static constexpr uint8_t MAP_MATCHING_NONE =
    0u;
  static constexpr uint8_t MAP_MATCHING_VALID =
    64u;
  static constexpr uint8_t MAP_MATCHING_USED =
    128u;
  static constexpr uint8_t MAP_MATCHING_DR =
    192u;
  static constexpr uint8_t FLAGS2_PSM_STATE_MASK =
    3u;
  static constexpr uint8_t PSM_STATE_ACQUISITION =
    0u;
  static constexpr uint8_t PSM_STATE_TRACKING =
    1u;
  static constexpr uint8_t PSM_STATE_POWER_OPTIMIZED_TRACKING =
    2u;
  static constexpr uint8_t PSM_STATE_INACTIVE =
    3u;
  static constexpr uint8_t FLAGS2_SPOOF_DET_STATE_MASK =
    24u;
  static constexpr uint8_t SPOOF_DET_STATE_UNKNOWN =
    0u;
  static constexpr uint8_t SPOOF_DET_STATE_NONE =
    8u;
  static constexpr uint8_t SPOOF_DET_STATE_SPOOFING =
    16u;
  static constexpr uint8_t SPOOF_DET_STATE_MULTIPLE =
    24u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSTATUS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSTATUS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSTATUS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSTATUS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSTATUS
    std::shared_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSTATUS
    std::shared_ptr<ublox_msgs::msg::NavSTATUS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSTATUS_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->gps_fix != other.gps_fix) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->fix_stat != other.fix_stat) {
      return false;
    }
    if (this->flags2 != other.flags2) {
      return false;
    }
    if (this->ttff != other.ttff) {
      return false;
    }
    if (this->msss != other.msss) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSTATUS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSTATUS_

// alias to use template instance with default allocator
using NavSTATUS =
  ublox_msgs::msg::NavSTATUS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::GPS_NO_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::GPS_DEAD_RECKONING_ONLY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::GPS_2D_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::GPS_3D_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::GPS_GPS_DEAD_RECKONING_COMBINED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::GPS_TIME_ONLY_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FLAGS_GPS_FIX_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FLAGS_DIFF_SOLN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FLAGS_WKNSET;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FLAGS_TOWSET;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FIX_STAT_DIFF_CORR_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FIX_STAT_MAP_MATCHING_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::MAP_MATCHING_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::MAP_MATCHING_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::MAP_MATCHING_USED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::MAP_MATCHING_DR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FLAGS2_PSM_STATE_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::PSM_STATE_ACQUISITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::PSM_STATE_TRACKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::PSM_STATE_POWER_OPTIMIZED_TRACKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::PSM_STATE_INACTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::FLAGS2_SPOOF_DET_STATE_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::SPOOF_DET_STATE_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::SPOOF_DET_STATE_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::SPOOF_DET_STATE_SPOOFING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSTATUS_<ContainerAllocator>::SPOOF_DET_STATE_MULTIPLE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_HPP_

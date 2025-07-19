// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSVINFOSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSVINFOSV __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSVINFOSV __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSVINFOSV_
{
  using Type = NavSVINFOSV_<ContainerAllocator>;

  explicit NavSVINFOSV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chn = 0;
      this->svid = 0;
      this->flags = 0;
      this->quality = 0;
      this->cno = 0;
      this->elev = 0;
      this->azim = 0;
      this->pr_res = 0l;
    }
  }

  explicit NavSVINFOSV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chn = 0;
      this->svid = 0;
      this->flags = 0;
      this->quality = 0;
      this->cno = 0;
      this->elev = 0;
      this->azim = 0;
      this->pr_res = 0l;
    }
  }

  // field types and members
  using _chn_type =
    uint8_t;
  _chn_type chn;
  using _svid_type =
    uint8_t;
  _svid_type svid;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _quality_type =
    uint8_t;
  _quality_type quality;
  using _cno_type =
    uint8_t;
  _cno_type cno;
  using _elev_type =
    int8_t;
  _elev_type elev;
  using _azim_type =
    int16_t;
  _azim_type azim;
  using _pr_res_type =
    int32_t;
  _pr_res_type pr_res;

  // setters for named parameter idiom
  Type & set__chn(
    const uint8_t & _arg)
  {
    this->chn = _arg;
    return *this;
  }
  Type & set__svid(
    const uint8_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__quality(
    const uint8_t & _arg)
  {
    this->quality = _arg;
    return *this;
  }
  Type & set__cno(
    const uint8_t & _arg)
  {
    this->cno = _arg;
    return *this;
  }
  Type & set__elev(
    const int8_t & _arg)
  {
    this->elev = _arg;
    return *this;
  }
  Type & set__azim(
    const int16_t & _arg)
  {
    this->azim = _arg;
    return *this;
  }
  Type & set__pr_res(
    const int32_t & _arg)
  {
    this->pr_res = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t FLAGS_SV_USED =
    1u;
  static constexpr uint8_t FLAGS_DIFF_CORR =
    2u;
  static constexpr uint8_t FLAGS_ORBIT_AVAIL =
    4u;
  static constexpr uint8_t FLAGS_ORBIT_EPH =
    8u;
  static constexpr uint8_t FLAGS_UNHEALTHY =
    16u;
  static constexpr uint8_t FLAGS_ORBIT_ALM =
    32u;
  static constexpr uint8_t FLAGS_ORBIT_AOP =
    64u;
  static constexpr uint8_t FLAGS_SMOOTHED =
    128u;
  static constexpr uint8_t QUALITY_IDLE =
    0u;
  static constexpr uint8_t QUALITY_SEARCHING =
    1u;
  static constexpr uint8_t QUALITY_ACQUIRED =
    2u;
  static constexpr uint8_t QUALITY_DETECTED =
    3u;
  static constexpr uint8_t QUALITY_CODE_LOCK =
    4u;
  static constexpr uint8_t QUALITY_CODE_AND_CARRIER_LOCKED1 =
    5u;
  static constexpr uint8_t QUALITY_CODE_AND_CARRIER_LOCKED2 =
    6u;
  static constexpr uint8_t QUALITY_CODE_AND_CARRIER_LOCKED3 =
    7u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSVINFOSV
    std::shared_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSVINFOSV
    std::shared_ptr<ublox_msgs::msg::NavSVINFOSV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSVINFOSV_ & other) const
  {
    if (this->chn != other.chn) {
      return false;
    }
    if (this->svid != other.svid) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->quality != other.quality) {
      return false;
    }
    if (this->cno != other.cno) {
      return false;
    }
    if (this->elev != other.elev) {
      return false;
    }
    if (this->azim != other.azim) {
      return false;
    }
    if (this->pr_res != other.pr_res) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSVINFOSV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSVINFOSV_

// alias to use template instance with default allocator
using NavSVINFOSV =
  ublox_msgs::msg::NavSVINFOSV_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_SV_USED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_DIFF_CORR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_ORBIT_AVAIL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_ORBIT_EPH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_UNHEALTHY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_ORBIT_ALM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_ORBIT_AOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::FLAGS_SMOOTHED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_SEARCHING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_ACQUIRED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_DETECTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_CODE_LOCK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_CODE_AND_CARRIER_LOCKED1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_CODE_AND_CARRIER_LOCKED2;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVINFOSV_<ContainerAllocator>::QUALITY_CODE_AND_CARRIER_LOCKED3;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__STRUCT_HPP_

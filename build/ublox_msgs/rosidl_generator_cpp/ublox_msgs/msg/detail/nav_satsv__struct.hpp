// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSATSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSATSV __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSATSV __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSATSV_
{
  using Type = NavSATSV_<ContainerAllocator>;

  explicit NavSATSV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gnss_id = 0;
      this->sv_id = 0;
      this->cno = 0;
      this->elev = 0;
      this->azim = 0;
      this->pr_res = 0;
      this->flags = 0ul;
    }
  }

  explicit NavSATSV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gnss_id = 0;
      this->sv_id = 0;
      this->cno = 0;
      this->elev = 0;
      this->azim = 0;
      this->pr_res = 0;
      this->flags = 0ul;
    }
  }

  // field types and members
  using _gnss_id_type =
    uint8_t;
  _gnss_id_type gnss_id;
  using _sv_id_type =
    uint8_t;
  _sv_id_type sv_id;
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
    int16_t;
  _pr_res_type pr_res;
  using _flags_type =
    uint32_t;
  _flags_type flags;

  // setters for named parameter idiom
  Type & set__gnss_id(
    const uint8_t & _arg)
  {
    this->gnss_id = _arg;
    return *this;
  }
  Type & set__sv_id(
    const uint8_t & _arg)
  {
    this->sv_id = _arg;
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
    const int16_t & _arg)
  {
    this->pr_res = _arg;
    return *this;
  }
  Type & set__flags(
    const uint32_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t FLAGS_QUALITY_IND_MASK =
    7u;
  static constexpr uint8_t QUALITY_IND_NO_SIGNAL =
    0u;
  static constexpr uint8_t QUALITY_IND_SEARCHING_SIGNAL =
    1u;
  static constexpr uint8_t QUALITY_IND_SIGNAL_ACQUIRED =
    2u;
  static constexpr uint8_t QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE =
    3u;
  static constexpr uint8_t QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC =
    4u;
  static constexpr uint8_t QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1 =
    5u;
  static constexpr uint8_t QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2 =
    6u;
  static constexpr uint8_t QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3 =
    7u;
  static constexpr uint32_t FLAGS_SV_USED =
    8u;
  static constexpr uint32_t FLAGS_HEALTH_MASK =
    48u;
  static constexpr uint32_t HEALTH_UNKNOWN =
    0u;
  static constexpr uint32_t HEALTH_HEALTHY =
    1u;
  static constexpr uint32_t HEALTH_UNHEALTHY =
    2u;
  static constexpr uint32_t FLAGS_DIFF_CORR =
    64u;
  static constexpr uint32_t FLAGS_SMOOTHED =
    128u;
  static constexpr uint32_t FLAGS_ORBIT_SOURCE_MASK =
    1792u;
  static constexpr uint32_t ORBIT_SOURCE_UNAVAILABLE =
    0u;
  static constexpr uint32_t ORBIT_SOURCE_EPH =
    256u;
  static constexpr uint32_t ORBIT_SOURCE_ALM =
    512u;
  static constexpr uint32_t ORBIT_SOURCE_ASSIST_OFFLINE =
    768u;
  static constexpr uint32_t ORBIT_SOURCE_ASSIST_AUTONOMOUS =
    1024u;
  static constexpr uint32_t ORBIT_SOURCE_OTHER1 =
    1280u;
  static constexpr uint32_t ORBIT_SOURCE_OTHER2 =
    1536u;
  static constexpr uint32_t ORBIT_SOURCE_OTHER3 =
    1792u;
  static constexpr uint32_t FLAGS_EPH_AVAIL =
    2048u;
  static constexpr uint32_t FLAGS_ALM_AVAIL =
    4096u;
  static constexpr uint32_t FLAGS_ANO_AVAIL =
    8192u;
  static constexpr uint32_t FLAGS_AOP_AVAIL =
    16384u;
  static constexpr uint32_t FLAGS_SBAS_CORR_USED =
    65536u;
  static constexpr uint32_t FLAGS_RTCM_CORR_USED =
    131072u;
  static constexpr uint32_t FLAGS_PR_CORR_USED =
    1048576u;
  static constexpr uint32_t FLAGS_CR_CORR_USED =
    2097152u;
  static constexpr uint32_t FLAGS_DO_CORR_USED =
    4194304u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSATSV_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSATSV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSATSV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSATSV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSATSV
    std::shared_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSATSV
    std::shared_ptr<ublox_msgs::msg::NavSATSV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSATSV_ & other) const
  {
    if (this->gnss_id != other.gnss_id) {
      return false;
    }
    if (this->sv_id != other.sv_id) {
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
    if (this->flags != other.flags) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSATSV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSATSV_

// alias to use template instance with default allocator
using NavSATSV =
  ublox_msgs::msg::NavSATSV_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_QUALITY_IND_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_NO_SIGNAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_SEARCHING_SIGNAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_SIGNAL_ACQUIRED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSATSV_<ContainerAllocator>::QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_SV_USED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_HEALTH_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::HEALTH_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::HEALTH_HEALTHY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::HEALTH_UNHEALTHY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_DIFF_CORR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_SMOOTHED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_ORBIT_SOURCE_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_UNAVAILABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_EPH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_ALM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_ASSIST_OFFLINE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_ASSIST_AUTONOMOUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_OTHER1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_OTHER2;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::ORBIT_SOURCE_OTHER3;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_EPH_AVAIL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_ALM_AVAIL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_ANO_AVAIL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_AOP_AVAIL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_SBAS_CORR_USED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_RTCM_CORR_USED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_PR_CORR_USED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_CR_CORR_USED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavSATSV_<ContainerAllocator>::FLAGS_DO_CORR_USED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SATSV__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavRELPOSNED.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavRELPOSNED __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavRELPOSNED __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavRELPOSNED_
{
  using Type = NavRELPOSNED_<ContainerAllocator>;

  explicit NavRELPOSNED_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->reserved0 = 0;
      this->ref_station_id = 0;
      this->i_tow = 0ul;
      this->rel_pos_n = 0l;
      this->rel_pos_e = 0l;
      this->rel_pos_d = 0l;
      this->rel_pos_hpn = 0;
      this->rel_pos_hpe = 0;
      this->rel_pos_hpd = 0;
      this->reserved1 = 0;
      this->acc_n = 0ul;
      this->acc_e = 0ul;
      this->acc_d = 0ul;
      this->flags = 0ul;
    }
  }

  explicit NavRELPOSNED_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->reserved0 = 0;
      this->ref_station_id = 0;
      this->i_tow = 0ul;
      this->rel_pos_n = 0l;
      this->rel_pos_e = 0l;
      this->rel_pos_d = 0l;
      this->rel_pos_hpn = 0;
      this->rel_pos_hpe = 0;
      this->rel_pos_hpd = 0;
      this->reserved1 = 0;
      this->acc_n = 0ul;
      this->acc_e = 0ul;
      this->acc_d = 0ul;
      this->flags = 0ul;
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved0_type =
    uint8_t;
  _reserved0_type reserved0;
  using _ref_station_id_type =
    uint16_t;
  _ref_station_id_type ref_station_id;
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _rel_pos_n_type =
    int32_t;
  _rel_pos_n_type rel_pos_n;
  using _rel_pos_e_type =
    int32_t;
  _rel_pos_e_type rel_pos_e;
  using _rel_pos_d_type =
    int32_t;
  _rel_pos_d_type rel_pos_d;
  using _rel_pos_hpn_type =
    int8_t;
  _rel_pos_hpn_type rel_pos_hpn;
  using _rel_pos_hpe_type =
    int8_t;
  _rel_pos_hpe_type rel_pos_hpe;
  using _rel_pos_hpd_type =
    int8_t;
  _rel_pos_hpd_type rel_pos_hpd;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _acc_n_type =
    uint32_t;
  _acc_n_type acc_n;
  using _acc_e_type =
    uint32_t;
  _acc_e_type acc_e;
  using _acc_d_type =
    uint32_t;
  _acc_d_type acc_d;
  using _flags_type =
    uint32_t;
  _flags_type flags;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__reserved0(
    const uint8_t & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__ref_station_id(
    const uint16_t & _arg)
  {
    this->ref_station_id = _arg;
    return *this;
  }
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__rel_pos_n(
    const int32_t & _arg)
  {
    this->rel_pos_n = _arg;
    return *this;
  }
  Type & set__rel_pos_e(
    const int32_t & _arg)
  {
    this->rel_pos_e = _arg;
    return *this;
  }
  Type & set__rel_pos_d(
    const int32_t & _arg)
  {
    this->rel_pos_d = _arg;
    return *this;
  }
  Type & set__rel_pos_hpn(
    const int8_t & _arg)
  {
    this->rel_pos_hpn = _arg;
    return *this;
  }
  Type & set__rel_pos_hpe(
    const int8_t & _arg)
  {
    this->rel_pos_hpe = _arg;
    return *this;
  }
  Type & set__rel_pos_hpd(
    const int8_t & _arg)
  {
    this->rel_pos_hpd = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__acc_n(
    const uint32_t & _arg)
  {
    this->acc_n = _arg;
    return *this;
  }
  Type & set__acc_e(
    const uint32_t & _arg)
  {
    this->acc_e = _arg;
    return *this;
  }
  Type & set__acc_d(
    const uint32_t & _arg)
  {
    this->acc_d = _arg;
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
    1u;
  static constexpr uint8_t MESSAGE_ID =
    60u;
  static constexpr uint32_t FLAGS_GNSS_FIX_OK =
    1u;
  static constexpr uint32_t FLAGS_DIFF_SOLN =
    2u;
  static constexpr uint32_t FLAGS_REL_POS_VALID =
    4u;
  static constexpr uint32_t FLAGS_CARR_SOLN_MASK =
    24u;
  static constexpr uint32_t FLAGS_CARR_SOLN_NONE =
    0u;
  static constexpr uint32_t FLAGS_CARR_SOLN_FLOAT =
    8u;
  static constexpr uint32_t FLAGS_CARR_SOLN_FIXED =
    16u;
  static constexpr uint32_t FLAGS_IS_MOVING =
    32u;
  static constexpr uint32_t FLAGS_REF_POS_MISS =
    64u;
  static constexpr uint32_t FLAGS_REF_OBS_MISS =
    128u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavRELPOSNED
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavRELPOSNED
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavRELPOSNED_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->ref_station_id != other.ref_station_id) {
      return false;
    }
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->rel_pos_n != other.rel_pos_n) {
      return false;
    }
    if (this->rel_pos_e != other.rel_pos_e) {
      return false;
    }
    if (this->rel_pos_d != other.rel_pos_d) {
      return false;
    }
    if (this->rel_pos_hpn != other.rel_pos_hpn) {
      return false;
    }
    if (this->rel_pos_hpe != other.rel_pos_hpe) {
      return false;
    }
    if (this->rel_pos_hpd != other.rel_pos_hpd) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->acc_n != other.acc_n) {
      return false;
    }
    if (this->acc_e != other.acc_e) {
      return false;
    }
    if (this->acc_d != other.acc_d) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavRELPOSNED_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavRELPOSNED_

// alias to use template instance with default allocator
using NavRELPOSNED =
  ublox_msgs::msg::NavRELPOSNED_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavRELPOSNED_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavRELPOSNED_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_GNSS_FIX_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_DIFF_SOLN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_REL_POS_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_CARR_SOLN_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_CARR_SOLN_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_CARR_SOLN_FLOAT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_CARR_SOLN_FIXED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_IS_MOVING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_REF_POS_MISS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED_<ContainerAllocator>::FLAGS_REF_OBS_MISS;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__STRUCT_HPP_

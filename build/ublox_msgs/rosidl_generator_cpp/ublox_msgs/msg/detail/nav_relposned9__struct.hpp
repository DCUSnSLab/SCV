// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavRELPOSNED9.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED9__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED9__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavRELPOSNED9 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavRELPOSNED9 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavRELPOSNED9_
{
  using Type = NavRELPOSNED9_<ContainerAllocator>;

  explicit NavRELPOSNED9_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->reserved1 = 0;
      this->ref_station_id = 0;
      this->i_tow = 0ul;
      this->rel_pos_n = 0l;
      this->rel_pos_e = 0l;
      this->rel_pos_d = 0l;
      this->rel_pos_length = 0l;
      this->rel_pos_heading = 0l;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
      this->rel_pos_hpn = 0;
      this->rel_pos_hpe = 0;
      this->rel_pos_hpd = 0;
      this->rel_pos_hp_length = 0;
      this->acc_n = 0ul;
      this->acc_e = 0ul;
      this->acc_d = 0ul;
      this->acc_length = 0ul;
      this->acc_heading = 0ul;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
      this->flags = 0ul;
    }
  }

  explicit NavRELPOSNED9_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved2(_alloc),
    reserved3(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->reserved1 = 0;
      this->ref_station_id = 0;
      this->i_tow = 0ul;
      this->rel_pos_n = 0l;
      this->rel_pos_e = 0l;
      this->rel_pos_d = 0l;
      this->rel_pos_length = 0l;
      this->rel_pos_heading = 0l;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
      this->rel_pos_hpn = 0;
      this->rel_pos_hpe = 0;
      this->rel_pos_hpd = 0;
      this->rel_pos_hp_length = 0;
      this->acc_n = 0ul;
      this->acc_e = 0ul;
      this->acc_d = 0ul;
      this->acc_length = 0ul;
      this->acc_heading = 0ul;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
      this->flags = 0ul;
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
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
  using _rel_pos_length_type =
    int32_t;
  _rel_pos_length_type rel_pos_length;
  using _rel_pos_heading_type =
    int32_t;
  _rel_pos_heading_type rel_pos_heading;
  using _reserved2_type =
    std::array<uint8_t, 4>;
  _reserved2_type reserved2;
  using _rel_pos_hpn_type =
    int8_t;
  _rel_pos_hpn_type rel_pos_hpn;
  using _rel_pos_hpe_type =
    int8_t;
  _rel_pos_hpe_type rel_pos_hpe;
  using _rel_pos_hpd_type =
    int8_t;
  _rel_pos_hpd_type rel_pos_hpd;
  using _rel_pos_hp_length_type =
    int8_t;
  _rel_pos_hp_length_type rel_pos_hp_length;
  using _acc_n_type =
    uint32_t;
  _acc_n_type acc_n;
  using _acc_e_type =
    uint32_t;
  _acc_e_type acc_e;
  using _acc_d_type =
    uint32_t;
  _acc_d_type acc_d;
  using _acc_length_type =
    uint32_t;
  _acc_length_type acc_length;
  using _acc_heading_type =
    uint32_t;
  _acc_heading_type acc_heading;
  using _reserved3_type =
    std::array<uint8_t, 4>;
  _reserved3_type reserved3;
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
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
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
  Type & set__rel_pos_length(
    const int32_t & _arg)
  {
    this->rel_pos_length = _arg;
    return *this;
  }
  Type & set__rel_pos_heading(
    const int32_t & _arg)
  {
    this->rel_pos_heading = _arg;
    return *this;
  }
  Type & set__reserved2(
    const std::array<uint8_t, 4> & _arg)
  {
    this->reserved2 = _arg;
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
  Type & set__rel_pos_hp_length(
    const int8_t & _arg)
  {
    this->rel_pos_hp_length = _arg;
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
  Type & set__acc_length(
    const uint32_t & _arg)
  {
    this->acc_length = _arg;
    return *this;
  }
  Type & set__acc_heading(
    const uint32_t & _arg)
  {
    this->acc_heading = _arg;
    return *this;
  }
  Type & set__reserved3(
    const std::array<uint8_t, 4> & _arg)
  {
    this->reserved3 = _arg;
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
  static constexpr uint32_t FLAGS_REL_POS_HEAD_VALID =
    256u;
  static constexpr uint32_t FLAGS_REL_POS_NORM =
    512u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavRELPOSNED9
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavRELPOSNED9
    std::shared_ptr<ublox_msgs::msg::NavRELPOSNED9_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavRELPOSNED9_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
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
    if (this->rel_pos_length != other.rel_pos_length) {
      return false;
    }
    if (this->rel_pos_heading != other.rel_pos_heading) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
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
    if (this->rel_pos_hp_length != other.rel_pos_hp_length) {
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
    if (this->acc_length != other.acc_length) {
      return false;
    }
    if (this->acc_heading != other.acc_heading) {
      return false;
    }
    if (this->reserved3 != other.reserved3) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavRELPOSNED9_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavRELPOSNED9_

// alias to use template instance with default allocator
using NavRELPOSNED9 =
  ublox_msgs::msg::NavRELPOSNED9_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavRELPOSNED9_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavRELPOSNED9_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_GNSS_FIX_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_DIFF_SOLN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_REL_POS_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_CARR_SOLN_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_CARR_SOLN_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_CARR_SOLN_FLOAT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_CARR_SOLN_FIXED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_IS_MOVING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_REF_POS_MISS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_REF_OBS_MISS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_REL_POS_HEAD_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavRELPOSNED9_<ContainerAllocator>::FLAGS_REL_POS_NORM;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED9__STRUCT_HPP_

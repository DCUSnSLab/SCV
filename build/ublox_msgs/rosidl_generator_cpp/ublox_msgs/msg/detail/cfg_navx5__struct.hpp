// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgNAVX5 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgNAVX5 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgNAVX5_
{
  using Type = CfgNAVX5_<ContainerAllocator>;

  explicit CfgNAVX5_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->mask1 = 0;
      this->mask2 = 0ul;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->min_svs = 0;
      this->max_svs = 0;
      this->min_cno = 0;
      this->reserved2 = 0;
      this->ini_fix3d = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
      this->ack_aiding = 0;
      this->wkn_rollover = 0;
      this->sig_atten_comp_mode = 0;
      std::fill<typename std::array<uint8_t, 5>::iterator, uint8_t>(this->reserved4.begin(), this->reserved4.end(), 0);
      this->use_ppp = 0;
      this->aop_cfg = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved5.begin(), this->reserved5.end(), 0);
      this->aop_orb_max_err = 0;
      std::fill<typename std::array<uint8_t, 7>::iterator, uint8_t>(this->reserved6.begin(), this->reserved6.end(), 0);
      this->use_adr = 0;
    }
  }

  explicit CfgNAVX5_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc),
    reserved3(_alloc),
    reserved4(_alloc),
    reserved5(_alloc),
    reserved6(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->mask1 = 0;
      this->mask2 = 0ul;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->min_svs = 0;
      this->max_svs = 0;
      this->min_cno = 0;
      this->reserved2 = 0;
      this->ini_fix3d = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
      this->ack_aiding = 0;
      this->wkn_rollover = 0;
      this->sig_atten_comp_mode = 0;
      std::fill<typename std::array<uint8_t, 5>::iterator, uint8_t>(this->reserved4.begin(), this->reserved4.end(), 0);
      this->use_ppp = 0;
      this->aop_cfg = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved5.begin(), this->reserved5.end(), 0);
      this->aop_orb_max_err = 0;
      std::fill<typename std::array<uint8_t, 7>::iterator, uint8_t>(this->reserved6.begin(), this->reserved6.end(), 0);
      this->use_adr = 0;
    }
  }

  // field types and members
  using _version_type =
    uint16_t;
  _version_type version;
  using _mask1_type =
    uint16_t;
  _mask1_type mask1;
  using _mask2_type =
    uint32_t;
  _mask2_type mask2;
  using _reserved1_type =
    std::array<uint8_t, 2>;
  _reserved1_type reserved1;
  using _min_svs_type =
    uint8_t;
  _min_svs_type min_svs;
  using _max_svs_type =
    uint8_t;
  _max_svs_type max_svs;
  using _min_cno_type =
    uint8_t;
  _min_cno_type min_cno;
  using _reserved2_type =
    uint8_t;
  _reserved2_type reserved2;
  using _ini_fix3d_type =
    uint8_t;
  _ini_fix3d_type ini_fix3d;
  using _reserved3_type =
    std::array<uint8_t, 2>;
  _reserved3_type reserved3;
  using _ack_aiding_type =
    uint8_t;
  _ack_aiding_type ack_aiding;
  using _wkn_rollover_type =
    uint16_t;
  _wkn_rollover_type wkn_rollover;
  using _sig_atten_comp_mode_type =
    uint8_t;
  _sig_atten_comp_mode_type sig_atten_comp_mode;
  using _reserved4_type =
    std::array<uint8_t, 5>;
  _reserved4_type reserved4;
  using _use_ppp_type =
    uint8_t;
  _use_ppp_type use_ppp;
  using _aop_cfg_type =
    uint8_t;
  _aop_cfg_type aop_cfg;
  using _reserved5_type =
    std::array<uint8_t, 2>;
  _reserved5_type reserved5;
  using _aop_orb_max_err_type =
    uint16_t;
  _aop_orb_max_err_type aop_orb_max_err;
  using _reserved6_type =
    std::array<uint8_t, 7>;
  _reserved6_type reserved6;
  using _use_adr_type =
    uint8_t;
  _use_adr_type use_adr;

  // setters for named parameter idiom
  Type & set__version(
    const uint16_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__mask1(
    const uint16_t & _arg)
  {
    this->mask1 = _arg;
    return *this;
  }
  Type & set__mask2(
    const uint32_t & _arg)
  {
    this->mask2 = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__min_svs(
    const uint8_t & _arg)
  {
    this->min_svs = _arg;
    return *this;
  }
  Type & set__max_svs(
    const uint8_t & _arg)
  {
    this->max_svs = _arg;
    return *this;
  }
  Type & set__min_cno(
    const uint8_t & _arg)
  {
    this->min_cno = _arg;
    return *this;
  }
  Type & set__reserved2(
    const uint8_t & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }
  Type & set__ini_fix3d(
    const uint8_t & _arg)
  {
    this->ini_fix3d = _arg;
    return *this;
  }
  Type & set__reserved3(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved3 = _arg;
    return *this;
  }
  Type & set__ack_aiding(
    const uint8_t & _arg)
  {
    this->ack_aiding = _arg;
    return *this;
  }
  Type & set__wkn_rollover(
    const uint16_t & _arg)
  {
    this->wkn_rollover = _arg;
    return *this;
  }
  Type & set__sig_atten_comp_mode(
    const uint8_t & _arg)
  {
    this->sig_atten_comp_mode = _arg;
    return *this;
  }
  Type & set__reserved4(
    const std::array<uint8_t, 5> & _arg)
  {
    this->reserved4 = _arg;
    return *this;
  }
  Type & set__use_ppp(
    const uint8_t & _arg)
  {
    this->use_ppp = _arg;
    return *this;
  }
  Type & set__aop_cfg(
    const uint8_t & _arg)
  {
    this->aop_cfg = _arg;
    return *this;
  }
  Type & set__reserved5(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved5 = _arg;
    return *this;
  }
  Type & set__aop_orb_max_err(
    const uint16_t & _arg)
  {
    this->aop_orb_max_err = _arg;
    return *this;
  }
  Type & set__reserved6(
    const std::array<uint8_t, 7> & _arg)
  {
    this->reserved6 = _arg;
    return *this;
  }
  Type & set__use_adr(
    const uint8_t & _arg)
  {
    this->use_adr = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    35u;
  static constexpr uint16_t MASK1_MIN_MAX =
    4u;
  static constexpr uint16_t MASK1_MIN_CNO =
    8u;
  static constexpr uint16_t MASK1_INITIAL_FIX_3D =
    64u;
  static constexpr uint16_t MASK1_WKN_ROLL =
    512u;
  static constexpr uint16_t MASK1_ACK_AID =
    1024u;
  static constexpr uint16_t MASK1_PPP =
    8192u;
  static constexpr uint16_t MASK1_AOP =
    16384u;
  static constexpr uint32_t MASK2_ADR =
    64u;
  static constexpr uint32_t MASK2_SIG_ATTEN_COMP_MODE =
    128u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgNAVX5_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgNAVX5_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNAVX5_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNAVX5_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgNAVX5
    std::shared_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgNAVX5
    std::shared_ptr<ublox_msgs::msg::CfgNAVX5_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgNAVX5_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->mask1 != other.mask1) {
      return false;
    }
    if (this->mask2 != other.mask2) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->min_svs != other.min_svs) {
      return false;
    }
    if (this->max_svs != other.max_svs) {
      return false;
    }
    if (this->min_cno != other.min_cno) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    if (this->ini_fix3d != other.ini_fix3d) {
      return false;
    }
    if (this->reserved3 != other.reserved3) {
      return false;
    }
    if (this->ack_aiding != other.ack_aiding) {
      return false;
    }
    if (this->wkn_rollover != other.wkn_rollover) {
      return false;
    }
    if (this->sig_atten_comp_mode != other.sig_atten_comp_mode) {
      return false;
    }
    if (this->reserved4 != other.reserved4) {
      return false;
    }
    if (this->use_ppp != other.use_ppp) {
      return false;
    }
    if (this->aop_cfg != other.aop_cfg) {
      return false;
    }
    if (this->reserved5 != other.reserved5) {
      return false;
    }
    if (this->aop_orb_max_err != other.aop_orb_max_err) {
      return false;
    }
    if (this->reserved6 != other.reserved6) {
      return false;
    }
    if (this->use_adr != other.use_adr) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgNAVX5_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgNAVX5_

// alias to use template instance with default allocator
using CfgNAVX5 =
  ublox_msgs::msg::CfgNAVX5_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAVX5_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAVX5_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAVX5_<ContainerAllocator>::MASK1_MIN_MAX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAVX5_<ContainerAllocator>::MASK1_MIN_CNO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAVX5_<ContainerAllocator>::MASK1_INITIAL_FIX_3D;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAVX5_<ContainerAllocator>::MASK1_WKN_ROLL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAVX5_<ContainerAllocator>::MASK1_ACK_AID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAVX5_<ContainerAllocator>::MASK1_PPP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAVX5_<ContainerAllocator>::MASK1_AOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgNAVX5_<ContainerAllocator>::MASK2_ADR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgNAVX5_<ContainerAllocator>::MASK2_SIG_ATTEN_COMP_MODE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAVX5__STRUCT_HPP_

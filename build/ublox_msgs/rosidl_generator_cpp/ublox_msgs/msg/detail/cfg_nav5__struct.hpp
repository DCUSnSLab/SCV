// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgNAV5.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgNAV5 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgNAV5 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgNAV5_
{
  using Type = CfgNAV5_<ContainerAllocator>;

  explicit CfgNAV5_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mask = 0;
      this->dyn_model = 0;
      this->fix_mode = 0;
      this->fixed_alt = 0l;
      this->fixed_alt_var = 0ul;
      this->min_elev = 0;
      this->dr_limit = 0;
      this->p_dop = 0;
      this->t_dop = 0;
      this->p_acc = 0;
      this->t_acc = 0;
      this->static_hold_thresh = 0;
      this->dgnss_time_out = 0;
      this->cno_thresh_num_svs = 0;
      this->cno_thresh = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->static_hold_max_dist = 0;
      this->utc_standard = 0;
      std::fill<typename std::array<uint8_t, 5>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
    }
  }

  explicit CfgNAV5_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc),
    reserved2(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mask = 0;
      this->dyn_model = 0;
      this->fix_mode = 0;
      this->fixed_alt = 0l;
      this->fixed_alt_var = 0ul;
      this->min_elev = 0;
      this->dr_limit = 0;
      this->p_dop = 0;
      this->t_dop = 0;
      this->p_acc = 0;
      this->t_acc = 0;
      this->static_hold_thresh = 0;
      this->dgnss_time_out = 0;
      this->cno_thresh_num_svs = 0;
      this->cno_thresh = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->static_hold_max_dist = 0;
      this->utc_standard = 0;
      std::fill<typename std::array<uint8_t, 5>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
    }
  }

  // field types and members
  using _mask_type =
    uint16_t;
  _mask_type mask;
  using _dyn_model_type =
    uint8_t;
  _dyn_model_type dyn_model;
  using _fix_mode_type =
    uint8_t;
  _fix_mode_type fix_mode;
  using _fixed_alt_type =
    int32_t;
  _fixed_alt_type fixed_alt;
  using _fixed_alt_var_type =
    uint32_t;
  _fixed_alt_var_type fixed_alt_var;
  using _min_elev_type =
    int8_t;
  _min_elev_type min_elev;
  using _dr_limit_type =
    uint8_t;
  _dr_limit_type dr_limit;
  using _p_dop_type =
    uint16_t;
  _p_dop_type p_dop;
  using _t_dop_type =
    uint16_t;
  _t_dop_type t_dop;
  using _p_acc_type =
    uint16_t;
  _p_acc_type p_acc;
  using _t_acc_type =
    uint16_t;
  _t_acc_type t_acc;
  using _static_hold_thresh_type =
    uint8_t;
  _static_hold_thresh_type static_hold_thresh;
  using _dgnss_time_out_type =
    uint8_t;
  _dgnss_time_out_type dgnss_time_out;
  using _cno_thresh_num_svs_type =
    uint8_t;
  _cno_thresh_num_svs_type cno_thresh_num_svs;
  using _cno_thresh_type =
    uint8_t;
  _cno_thresh_type cno_thresh;
  using _reserved1_type =
    std::array<uint8_t, 2>;
  _reserved1_type reserved1;
  using _static_hold_max_dist_type =
    uint16_t;
  _static_hold_max_dist_type static_hold_max_dist;
  using _utc_standard_type =
    uint8_t;
  _utc_standard_type utc_standard;
  using _reserved2_type =
    std::array<uint8_t, 5>;
  _reserved2_type reserved2;

  // setters for named parameter idiom
  Type & set__mask(
    const uint16_t & _arg)
  {
    this->mask = _arg;
    return *this;
  }
  Type & set__dyn_model(
    const uint8_t & _arg)
  {
    this->dyn_model = _arg;
    return *this;
  }
  Type & set__fix_mode(
    const uint8_t & _arg)
  {
    this->fix_mode = _arg;
    return *this;
  }
  Type & set__fixed_alt(
    const int32_t & _arg)
  {
    this->fixed_alt = _arg;
    return *this;
  }
  Type & set__fixed_alt_var(
    const uint32_t & _arg)
  {
    this->fixed_alt_var = _arg;
    return *this;
  }
  Type & set__min_elev(
    const int8_t & _arg)
  {
    this->min_elev = _arg;
    return *this;
  }
  Type & set__dr_limit(
    const uint8_t & _arg)
  {
    this->dr_limit = _arg;
    return *this;
  }
  Type & set__p_dop(
    const uint16_t & _arg)
  {
    this->p_dop = _arg;
    return *this;
  }
  Type & set__t_dop(
    const uint16_t & _arg)
  {
    this->t_dop = _arg;
    return *this;
  }
  Type & set__p_acc(
    const uint16_t & _arg)
  {
    this->p_acc = _arg;
    return *this;
  }
  Type & set__t_acc(
    const uint16_t & _arg)
  {
    this->t_acc = _arg;
    return *this;
  }
  Type & set__static_hold_thresh(
    const uint8_t & _arg)
  {
    this->static_hold_thresh = _arg;
    return *this;
  }
  Type & set__dgnss_time_out(
    const uint8_t & _arg)
  {
    this->dgnss_time_out = _arg;
    return *this;
  }
  Type & set__cno_thresh_num_svs(
    const uint8_t & _arg)
  {
    this->cno_thresh_num_svs = _arg;
    return *this;
  }
  Type & set__cno_thresh(
    const uint8_t & _arg)
  {
    this->cno_thresh = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__static_hold_max_dist(
    const uint16_t & _arg)
  {
    this->static_hold_max_dist = _arg;
    return *this;
  }
  Type & set__utc_standard(
    const uint8_t & _arg)
  {
    this->utc_standard = _arg;
    return *this;
  }
  Type & set__reserved2(
    const std::array<uint8_t, 5> & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    36u;
  static constexpr uint16_t MASK_DYN =
    1u;
  static constexpr uint16_t MASK_MIN_EL =
    2u;
  static constexpr uint16_t MASK_FIX_MODE =
    4u;
  static constexpr uint16_t MASK_DR_LIM =
    8u;
  static constexpr uint16_t MASK_POS_MASK =
    16u;
  static constexpr uint16_t MASK_TIME_MASK =
    32u;
  static constexpr uint16_t MASK_STATIC_HOLD_MASK =
    64u;
  static constexpr uint16_t MASK_DGPS_MASK =
    128u;
  static constexpr uint16_t MASK_CNO =
    256u;
  static constexpr uint16_t MASK_UTC =
    1024u;
  static constexpr uint8_t DYN_MODEL_PORTABLE =
    0u;
  static constexpr uint8_t DYN_MODEL_STATIONARY =
    2u;
  static constexpr uint8_t DYN_MODEL_PEDESTRIAN =
    3u;
  static constexpr uint8_t DYN_MODEL_AUTOMOTIVE =
    4u;
  static constexpr uint8_t DYN_MODEL_SEA =
    5u;
  static constexpr uint8_t DYN_MODEL_AIRBORNE_1G =
    6u;
  static constexpr uint8_t DYN_MODEL_AIRBORNE_2G =
    7u;
  static constexpr uint8_t DYN_MODEL_AIRBORNE_4G =
    8u;
  static constexpr uint8_t DYN_MODEL_WRIST_WATCH =
    9u;
  static constexpr uint8_t FIX_MODE_2D_ONLY =
    1u;
  static constexpr uint8_t FIX_MODE_3D_ONLY =
    2u;
  static constexpr uint8_t FIX_MODE_AUTO =
    3u;
  static constexpr uint8_t UTC_STANDARD_AUTOMATIC =
    0u;
  static constexpr uint8_t UTC_STANDARD_GPS =
    3u;
  static constexpr uint8_t UTC_STANDARD_GLONASS =
    6u;
  static constexpr uint8_t UTC_STANDARD_BEIDOU =
    7u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgNAV5_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgNAV5_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNAV5_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNAV5_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgNAV5
    std::shared_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgNAV5
    std::shared_ptr<ublox_msgs::msg::CfgNAV5_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgNAV5_ & other) const
  {
    if (this->mask != other.mask) {
      return false;
    }
    if (this->dyn_model != other.dyn_model) {
      return false;
    }
    if (this->fix_mode != other.fix_mode) {
      return false;
    }
    if (this->fixed_alt != other.fixed_alt) {
      return false;
    }
    if (this->fixed_alt_var != other.fixed_alt_var) {
      return false;
    }
    if (this->min_elev != other.min_elev) {
      return false;
    }
    if (this->dr_limit != other.dr_limit) {
      return false;
    }
    if (this->p_dop != other.p_dop) {
      return false;
    }
    if (this->t_dop != other.t_dop) {
      return false;
    }
    if (this->p_acc != other.p_acc) {
      return false;
    }
    if (this->t_acc != other.t_acc) {
      return false;
    }
    if (this->static_hold_thresh != other.static_hold_thresh) {
      return false;
    }
    if (this->dgnss_time_out != other.dgnss_time_out) {
      return false;
    }
    if (this->cno_thresh_num_svs != other.cno_thresh_num_svs) {
      return false;
    }
    if (this->cno_thresh != other.cno_thresh) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->static_hold_max_dist != other.static_hold_max_dist) {
      return false;
    }
    if (this->utc_standard != other.utc_standard) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgNAV5_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgNAV5_

// alias to use template instance with default allocator
using CfgNAV5 =
  ublox_msgs::msg::CfgNAV5_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_DYN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_MIN_EL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_FIX_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_DR_LIM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_POS_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_TIME_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_STATIC_HOLD_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_DGPS_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_CNO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgNAV5_<ContainerAllocator>::MASK_UTC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_PORTABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_STATIONARY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_PEDESTRIAN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_AUTOMOTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_SEA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_AIRBORNE_1G;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_AIRBORNE_2G;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_AIRBORNE_4G;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::DYN_MODEL_WRIST_WATCH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::FIX_MODE_2D_ONLY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::FIX_MODE_3D_ONLY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::FIX_MODE_AUTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::UTC_STANDARD_AUTOMATIC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::UTC_STANDARD_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::UTC_STANDARD_GLONASS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNAV5_<ContainerAllocator>::UTC_STANDARD_BEIDOU;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NAV5__STRUCT_HPP_

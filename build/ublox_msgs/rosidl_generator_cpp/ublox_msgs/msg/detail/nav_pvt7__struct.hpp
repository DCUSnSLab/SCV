// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavPVT7.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavPVT7 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavPVT7 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavPVT7_
{
  using Type = NavPVT7_<ContainerAllocator>;

  explicit NavPVT7_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->year = 0;
      this->month = 0;
      this->day = 0;
      this->hour = 0;
      this->min = 0;
      this->sec = 0;
      this->valid = 0;
      this->t_acc = 0ul;
      this->nano = 0l;
      this->fix_type = 0;
      this->flags = 0;
      this->flags2 = 0;
      this->num_sv = 0;
      this->lon = 0l;
      this->lat = 0l;
      this->height = 0l;
      this->h_msl = 0l;
      this->h_acc = 0ul;
      this->v_acc = 0ul;
      this->vel_n = 0l;
      this->vel_e = 0l;
      this->vel_d = 0l;
      this->g_speed = 0l;
      this->heading = 0l;
      this->s_acc = 0ul;
      this->head_acc = 0ul;
      this->p_dop = 0;
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  explicit NavPVT7_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->year = 0;
      this->month = 0;
      this->day = 0;
      this->hour = 0;
      this->min = 0;
      this->sec = 0;
      this->valid = 0;
      this->t_acc = 0ul;
      this->nano = 0l;
      this->fix_type = 0;
      this->flags = 0;
      this->flags2 = 0;
      this->num_sv = 0;
      this->lon = 0l;
      this->lat = 0l;
      this->height = 0l;
      this->h_msl = 0l;
      this->h_acc = 0ul;
      this->v_acc = 0ul;
      this->vel_n = 0l;
      this->vel_e = 0l;
      this->vel_d = 0l;
      this->g_speed = 0l;
      this->heading = 0l;
      this->s_acc = 0ul;
      this->head_acc = 0ul;
      this->p_dop = 0;
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _year_type =
    uint16_t;
  _year_type year;
  using _month_type =
    uint8_t;
  _month_type month;
  using _day_type =
    uint8_t;
  _day_type day;
  using _hour_type =
    uint8_t;
  _hour_type hour;
  using _min_type =
    uint8_t;
  _min_type min;
  using _sec_type =
    uint8_t;
  _sec_type sec;
  using _valid_type =
    uint8_t;
  _valid_type valid;
  using _t_acc_type =
    uint32_t;
  _t_acc_type t_acc;
  using _nano_type =
    int32_t;
  _nano_type nano;
  using _fix_type_type =
    uint8_t;
  _fix_type_type fix_type;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _flags2_type =
    uint8_t;
  _flags2_type flags2;
  using _num_sv_type =
    uint8_t;
  _num_sv_type num_sv;
  using _lon_type =
    int32_t;
  _lon_type lon;
  using _lat_type =
    int32_t;
  _lat_type lat;
  using _height_type =
    int32_t;
  _height_type height;
  using _h_msl_type =
    int32_t;
  _h_msl_type h_msl;
  using _h_acc_type =
    uint32_t;
  _h_acc_type h_acc;
  using _v_acc_type =
    uint32_t;
  _v_acc_type v_acc;
  using _vel_n_type =
    int32_t;
  _vel_n_type vel_n;
  using _vel_e_type =
    int32_t;
  _vel_e_type vel_e;
  using _vel_d_type =
    int32_t;
  _vel_d_type vel_d;
  using _g_speed_type =
    int32_t;
  _g_speed_type g_speed;
  using _heading_type =
    int32_t;
  _heading_type heading;
  using _s_acc_type =
    uint32_t;
  _s_acc_type s_acc;
  using _head_acc_type =
    uint32_t;
  _head_acc_type head_acc;
  using _p_dop_type =
    uint16_t;
  _p_dop_type p_dop;
  using _reserved1_type =
    std::array<uint8_t, 6>;
  _reserved1_type reserved1;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__year(
    const uint16_t & _arg)
  {
    this->year = _arg;
    return *this;
  }
  Type & set__month(
    const uint8_t & _arg)
  {
    this->month = _arg;
    return *this;
  }
  Type & set__day(
    const uint8_t & _arg)
  {
    this->day = _arg;
    return *this;
  }
  Type & set__hour(
    const uint8_t & _arg)
  {
    this->hour = _arg;
    return *this;
  }
  Type & set__min(
    const uint8_t & _arg)
  {
    this->min = _arg;
    return *this;
  }
  Type & set__sec(
    const uint8_t & _arg)
  {
    this->sec = _arg;
    return *this;
  }
  Type & set__valid(
    const uint8_t & _arg)
  {
    this->valid = _arg;
    return *this;
  }
  Type & set__t_acc(
    const uint32_t & _arg)
  {
    this->t_acc = _arg;
    return *this;
  }
  Type & set__nano(
    const int32_t & _arg)
  {
    this->nano = _arg;
    return *this;
  }
  Type & set__fix_type(
    const uint8_t & _arg)
  {
    this->fix_type = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__flags2(
    const uint8_t & _arg)
  {
    this->flags2 = _arg;
    return *this;
  }
  Type & set__num_sv(
    const uint8_t & _arg)
  {
    this->num_sv = _arg;
    return *this;
  }
  Type & set__lon(
    const int32_t & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__lat(
    const int32_t & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__height(
    const int32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__h_msl(
    const int32_t & _arg)
  {
    this->h_msl = _arg;
    return *this;
  }
  Type & set__h_acc(
    const uint32_t & _arg)
  {
    this->h_acc = _arg;
    return *this;
  }
  Type & set__v_acc(
    const uint32_t & _arg)
  {
    this->v_acc = _arg;
    return *this;
  }
  Type & set__vel_n(
    const int32_t & _arg)
  {
    this->vel_n = _arg;
    return *this;
  }
  Type & set__vel_e(
    const int32_t & _arg)
  {
    this->vel_e = _arg;
    return *this;
  }
  Type & set__vel_d(
    const int32_t & _arg)
  {
    this->vel_d = _arg;
    return *this;
  }
  Type & set__g_speed(
    const int32_t & _arg)
  {
    this->g_speed = _arg;
    return *this;
  }
  Type & set__heading(
    const int32_t & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__s_acc(
    const uint32_t & _arg)
  {
    this->s_acc = _arg;
    return *this;
  }
  Type & set__head_acc(
    const uint32_t & _arg)
  {
    this->head_acc = _arg;
    return *this;
  }
  Type & set__p_dop(
    const uint16_t & _arg)
  {
    this->p_dop = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 6> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    7u;
  static constexpr uint8_t VALID_DATE =
    1u;
  static constexpr uint8_t VALID_TIME =
    2u;
  static constexpr uint8_t VALID_FULLY_RESOLVED =
    4u;
  static constexpr uint8_t VALID_MAG =
    8u;
  static constexpr uint8_t FIX_TYPE_NO_FIX =
    0u;
  static constexpr uint8_t FIX_TYPE_DEAD_RECKONING_ONLY =
    1u;
  static constexpr uint8_t FIX_TYPE_2D =
    2u;
  static constexpr uint8_t FIX_TYPE_3D =
    3u;
  static constexpr uint8_t FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED =
    4u;
  static constexpr uint8_t FIX_TYPE_TIME_ONLY =
    5u;
  static constexpr uint8_t FLAGS_GNSS_FIX_OK =
    1u;
  static constexpr uint8_t FLAGS_DIFF_SOLN =
    2u;
  static constexpr uint8_t FLAGS_PSM_MASK =
    28u;
  static constexpr uint8_t PSM_OFF =
    0u;
  static constexpr uint8_t PSM_ENABLED =
    4u;
  static constexpr uint8_t PSM_ACQUIRED =
    8u;
  static constexpr uint8_t PSM_TRACKING =
    12u;
  static constexpr uint8_t PSM_POWER_OPTIMIZED_TRACKING =
    16u;
  static constexpr uint8_t PSM_INACTIVE =
    20u;
  static constexpr uint8_t FLAGS_HEAD_VEH_VALID =
    32u;
  static constexpr uint8_t FLAGS_CARRIER_PHASE_MASK =
    192u;
  static constexpr uint8_t CARRIER_PHASE_NO_SOLUTION =
    0u;
  static constexpr uint8_t CARRIER_PHASE_FLOAT =
    64u;
  static constexpr uint8_t CARRIER_PHASE_FIXED =
    128u;
  static constexpr uint8_t FLAGS2_CONFIRMED_AVAILABLE =
    32u;
  static constexpr uint8_t FLAGS2_CONFIRMED_DATE =
    64u;
  static constexpr uint8_t FLAGS2_CONFIRMED_TIME =
    128u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavPVT7_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavPVT7_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavPVT7_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavPVT7_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavPVT7
    std::shared_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavPVT7
    std::shared_ptr<ublox_msgs::msg::NavPVT7_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavPVT7_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->year != other.year) {
      return false;
    }
    if (this->month != other.month) {
      return false;
    }
    if (this->day != other.day) {
      return false;
    }
    if (this->hour != other.hour) {
      return false;
    }
    if (this->min != other.min) {
      return false;
    }
    if (this->sec != other.sec) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->t_acc != other.t_acc) {
      return false;
    }
    if (this->nano != other.nano) {
      return false;
    }
    if (this->fix_type != other.fix_type) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->flags2 != other.flags2) {
      return false;
    }
    if (this->num_sv != other.num_sv) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->lat != other.lat) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->h_msl != other.h_msl) {
      return false;
    }
    if (this->h_acc != other.h_acc) {
      return false;
    }
    if (this->v_acc != other.v_acc) {
      return false;
    }
    if (this->vel_n != other.vel_n) {
      return false;
    }
    if (this->vel_e != other.vel_e) {
      return false;
    }
    if (this->vel_d != other.vel_d) {
      return false;
    }
    if (this->g_speed != other.g_speed) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->s_acc != other.s_acc) {
      return false;
    }
    if (this->head_acc != other.head_acc) {
      return false;
    }
    if (this->p_dop != other.p_dop) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavPVT7_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavPVT7_

// alias to use template instance with default allocator
using NavPVT7 =
  ublox_msgs::msg::NavPVT7_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::VALID_DATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::VALID_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::VALID_FULLY_RESOLVED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::VALID_MAG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FIX_TYPE_NO_FIX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FIX_TYPE_DEAD_RECKONING_ONLY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FIX_TYPE_2D;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FIX_TYPE_3D;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FIX_TYPE_TIME_ONLY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS_GNSS_FIX_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS_DIFF_SOLN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS_PSM_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::PSM_OFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::PSM_ENABLED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::PSM_ACQUIRED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::PSM_TRACKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::PSM_POWER_OPTIMIZED_TRACKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::PSM_INACTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS_HEAD_VEH_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS_CARRIER_PHASE_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::CARRIER_PHASE_NO_SOLUTION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::CARRIER_PHASE_FLOAT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::CARRIER_PHASE_FIXED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS2_CONFIRMED_AVAILABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS2_CONFIRMED_DATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPVT7_<ContainerAllocator>::FLAGS2_CONFIRMED_TIME;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_PVT7__STRUCT_HPP_

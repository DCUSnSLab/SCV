// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/MonHW6.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_HW6__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_HW6__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__MonHW6 __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__MonHW6 __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MonHW6_
{
  using Type = MonHW6_<ContainerAllocator>;

  explicit MonHW6_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pin_sel = 0ul;
      this->pin_bank = 0ul;
      this->pin_dir = 0ul;
      this->pin_val = 0ul;
      this->noise_per_ms = 0;
      this->agc_cnt = 0;
      this->a_status = 0;
      this->a_power = 0;
      this->flags = 0;
      this->reserved0 = 0;
      this->used_mask = 0ul;
      std::fill<typename std::array<uint8_t, 25>::iterator, uint8_t>(this->vp.begin(), this->vp.end(), 0);
      this->jam_ind = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->pin_irq = 0ul;
      this->pull_h = 0ul;
      this->pull_l = 0ul;
    }
  }

  explicit MonHW6_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vp(_alloc),
    reserved1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pin_sel = 0ul;
      this->pin_bank = 0ul;
      this->pin_dir = 0ul;
      this->pin_val = 0ul;
      this->noise_per_ms = 0;
      this->agc_cnt = 0;
      this->a_status = 0;
      this->a_power = 0;
      this->flags = 0;
      this->reserved0 = 0;
      this->used_mask = 0ul;
      std::fill<typename std::array<uint8_t, 25>::iterator, uint8_t>(this->vp.begin(), this->vp.end(), 0);
      this->jam_ind = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->pin_irq = 0ul;
      this->pull_h = 0ul;
      this->pull_l = 0ul;
    }
  }

  // field types and members
  using _pin_sel_type =
    uint32_t;
  _pin_sel_type pin_sel;
  using _pin_bank_type =
    uint32_t;
  _pin_bank_type pin_bank;
  using _pin_dir_type =
    uint32_t;
  _pin_dir_type pin_dir;
  using _pin_val_type =
    uint32_t;
  _pin_val_type pin_val;
  using _noise_per_ms_type =
    uint16_t;
  _noise_per_ms_type noise_per_ms;
  using _agc_cnt_type =
    uint16_t;
  _agc_cnt_type agc_cnt;
  using _a_status_type =
    uint8_t;
  _a_status_type a_status;
  using _a_power_type =
    uint8_t;
  _a_power_type a_power;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _reserved0_type =
    uint8_t;
  _reserved0_type reserved0;
  using _used_mask_type =
    uint32_t;
  _used_mask_type used_mask;
  using _vp_type =
    std::array<uint8_t, 25>;
  _vp_type vp;
  using _jam_ind_type =
    uint8_t;
  _jam_ind_type jam_ind;
  using _reserved1_type =
    std::array<uint8_t, 2>;
  _reserved1_type reserved1;
  using _pin_irq_type =
    uint32_t;
  _pin_irq_type pin_irq;
  using _pull_h_type =
    uint32_t;
  _pull_h_type pull_h;
  using _pull_l_type =
    uint32_t;
  _pull_l_type pull_l;

  // setters for named parameter idiom
  Type & set__pin_sel(
    const uint32_t & _arg)
  {
    this->pin_sel = _arg;
    return *this;
  }
  Type & set__pin_bank(
    const uint32_t & _arg)
  {
    this->pin_bank = _arg;
    return *this;
  }
  Type & set__pin_dir(
    const uint32_t & _arg)
  {
    this->pin_dir = _arg;
    return *this;
  }
  Type & set__pin_val(
    const uint32_t & _arg)
  {
    this->pin_val = _arg;
    return *this;
  }
  Type & set__noise_per_ms(
    const uint16_t & _arg)
  {
    this->noise_per_ms = _arg;
    return *this;
  }
  Type & set__agc_cnt(
    const uint16_t & _arg)
  {
    this->agc_cnt = _arg;
    return *this;
  }
  Type & set__a_status(
    const uint8_t & _arg)
  {
    this->a_status = _arg;
    return *this;
  }
  Type & set__a_power(
    const uint8_t & _arg)
  {
    this->a_power = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__reserved0(
    const uint8_t & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__used_mask(
    const uint32_t & _arg)
  {
    this->used_mask = _arg;
    return *this;
  }
  Type & set__vp(
    const std::array<uint8_t, 25> & _arg)
  {
    this->vp = _arg;
    return *this;
  }
  Type & set__jam_ind(
    const uint8_t & _arg)
  {
    this->jam_ind = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__pin_irq(
    const uint32_t & _arg)
  {
    this->pin_irq = _arg;
    return *this;
  }
  Type & set__pull_h(
    const uint32_t & _arg)
  {
    this->pull_h = _arg;
    return *this;
  }
  Type & set__pull_l(
    const uint32_t & _arg)
  {
    this->pull_l = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    10u;
  static constexpr uint8_t MESSAGE_ID =
    9u;
  static constexpr uint8_t A_STATUS_INIT =
    0u;
  static constexpr uint8_t A_STATUS_UNKNOWN =
    1u;
  static constexpr uint8_t A_STATUS_OK =
    2u;
  static constexpr uint8_t A_STATUS_SHORT =
    3u;
  static constexpr uint8_t A_STATUS_OPEN =
    4u;
  static constexpr uint8_t A_POWER_OFF =
    0u;
  static constexpr uint8_t A_POWER_ON =
    1u;
  static constexpr uint8_t A_POWER_UNKNOWN =
    2u;
  static constexpr uint8_t FLAGS_RTC_CALIB =
    1u;
  static constexpr uint8_t FLAGS_SAFE_BOOT =
    2u;
  static constexpr uint8_t FLAGS_JAMMING_STATE_MASK =
    12u;
  static constexpr uint8_t JAMMING_STATE_UNKNOWN_OR_DISABLED =
    0u;
  static constexpr uint8_t JAMMING_STATE_OK =
    4u;
  static constexpr uint8_t JAMMING_STATE_WARNING =
    8u;
  static constexpr uint8_t JAMMING_STATE_CRITICAL =
    12u;
  static constexpr uint8_t FLAGS_XTAL_ABSENT =
    16u;
  static constexpr uint8_t JAM_IND_NONE =
    0u;
  static constexpr uint8_t JAM_IND_STRONG =
    255u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::MonHW6_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::MonHW6_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonHW6_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonHW6_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__MonHW6
    std::shared_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__MonHW6
    std::shared_ptr<ublox_msgs::msg::MonHW6_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MonHW6_ & other) const
  {
    if (this->pin_sel != other.pin_sel) {
      return false;
    }
    if (this->pin_bank != other.pin_bank) {
      return false;
    }
    if (this->pin_dir != other.pin_dir) {
      return false;
    }
    if (this->pin_val != other.pin_val) {
      return false;
    }
    if (this->noise_per_ms != other.noise_per_ms) {
      return false;
    }
    if (this->agc_cnt != other.agc_cnt) {
      return false;
    }
    if (this->a_status != other.a_status) {
      return false;
    }
    if (this->a_power != other.a_power) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->used_mask != other.used_mask) {
      return false;
    }
    if (this->vp != other.vp) {
      return false;
    }
    if (this->jam_ind != other.jam_ind) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->pin_irq != other.pin_irq) {
      return false;
    }
    if (this->pull_h != other.pull_h) {
      return false;
    }
    if (this->pull_l != other.pull_l) {
      return false;
    }
    return true;
  }
  bool operator!=(const MonHW6_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MonHW6_

// alias to use template instance with default allocator
using MonHW6 =
  ublox_msgs::msg::MonHW6_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_STATUS_INIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_STATUS_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_STATUS_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_STATUS_SHORT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_STATUS_OPEN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_POWER_OFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_POWER_ON;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::A_POWER_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::FLAGS_RTC_CALIB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::FLAGS_SAFE_BOOT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::FLAGS_JAMMING_STATE_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::JAMMING_STATE_UNKNOWN_OR_DISABLED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::JAMMING_STATE_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::JAMMING_STATE_WARNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::JAMMING_STATE_CRITICAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::FLAGS_XTAL_ABSENT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::JAM_IND_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonHW6_<ContainerAllocator>::JAM_IND_STRONG;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_HW6__STRUCT_HPP_

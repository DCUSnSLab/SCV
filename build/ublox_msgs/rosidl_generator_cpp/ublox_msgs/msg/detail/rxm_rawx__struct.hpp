// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmRAWX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'meas'
#include "ublox_msgs/msg/detail/rxm_rawx_meas__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmRAWX __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmRAWX __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmRAWX_
{
  using Type = RxmRAWX_<ContainerAllocator>;

  explicit RxmRAWX_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rcv_tow = 0.0;
      this->week = 0;
      this->leap_s = 0;
      this->num_meas = 0;
      this->rec_stat = 0;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  explicit RxmRAWX_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rcv_tow = 0.0;
      this->week = 0;
      this->leap_s = 0;
      this->num_meas = 0;
      this->rec_stat = 0;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  // field types and members
  using _rcv_tow_type =
    double;
  _rcv_tow_type rcv_tow;
  using _week_type =
    uint16_t;
  _week_type week;
  using _leap_s_type =
    int8_t;
  _leap_s_type leap_s;
  using _num_meas_type =
    uint8_t;
  _num_meas_type num_meas;
  using _rec_stat_type =
    uint8_t;
  _rec_stat_type rec_stat;
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved1_type =
    std::array<uint8_t, 2>;
  _reserved1_type reserved1;
  using _meas_type =
    std::vector<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>>>;
  _meas_type meas;

  // setters for named parameter idiom
  Type & set__rcv_tow(
    const double & _arg)
  {
    this->rcv_tow = _arg;
    return *this;
  }
  Type & set__week(
    const uint16_t & _arg)
  {
    this->week = _arg;
    return *this;
  }
  Type & set__leap_s(
    const int8_t & _arg)
  {
    this->leap_s = _arg;
    return *this;
  }
  Type & set__num_meas(
    const uint8_t & _arg)
  {
    this->num_meas = _arg;
    return *this;
  }
  Type & set__rec_stat(
    const uint8_t & _arg)
  {
    this->rec_stat = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__meas(
    const std::vector<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>>> & _arg)
  {
    this->meas = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    2u;
  static constexpr uint8_t MESSAGE_ID =
    21u;
  static constexpr uint8_t REC_STAT_LEAP_SEC =
    1u;
  static constexpr uint8_t REC_STAT_CLK_RESET =
    2u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmRAWX_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmRAWX_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAWX_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAWX_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmRAWX
    std::shared_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmRAWX
    std::shared_ptr<ublox_msgs::msg::RxmRAWX_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmRAWX_ & other) const
  {
    if (this->rcv_tow != other.rcv_tow) {
      return false;
    }
    if (this->week != other.week) {
      return false;
    }
    if (this->leap_s != other.leap_s) {
      return false;
    }
    if (this->num_meas != other.num_meas) {
      return false;
    }
    if (this->rec_stat != other.rec_stat) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->meas != other.meas) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmRAWX_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmRAWX_

// alias to use template instance with default allocator
using RxmRAWX =
  ublox_msgs::msg::RxmRAWX_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWX_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWX_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWX_<ContainerAllocator>::REC_STAT_LEAP_SEC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWX_<ContainerAllocator>::REC_STAT_CLK_RESET;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWX__STRUCT_HPP_

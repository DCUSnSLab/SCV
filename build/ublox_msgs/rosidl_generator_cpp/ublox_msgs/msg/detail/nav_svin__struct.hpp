// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSVIN.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSVIN __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSVIN __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSVIN_
{
  using Type = NavSVIN_<ContainerAllocator>;

  explicit NavSVIN_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->i_tow = 0ul;
      this->dur = 0ul;
      this->mean_x = 0l;
      this->mean_y = 0l;
      this->mean_z = 0l;
      this->mean_xhp = 0;
      this->mean_yhp = 0;
      this->mean_zhp = 0;
      this->reserved1 = 0;
      this->mean_acc = 0ul;
      this->obs = 0ul;
      this->valid = 0;
      this->active = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
    }
  }

  explicit NavSVIN_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc),
    reserved3(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->i_tow = 0ul;
      this->dur = 0ul;
      this->mean_x = 0l;
      this->mean_y = 0l;
      this->mean_z = 0l;
      this->mean_xhp = 0;
      this->mean_yhp = 0;
      this->mean_zhp = 0;
      this->reserved1 = 0;
      this->mean_acc = 0ul;
      this->obs = 0ul;
      this->valid = 0;
      this->active = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved3.begin(), this->reserved3.end(), 0);
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved0_type =
    std::array<uint8_t, 3>;
  _reserved0_type reserved0;
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _dur_type =
    uint32_t;
  _dur_type dur;
  using _mean_x_type =
    int32_t;
  _mean_x_type mean_x;
  using _mean_y_type =
    int32_t;
  _mean_y_type mean_y;
  using _mean_z_type =
    int32_t;
  _mean_z_type mean_z;
  using _mean_xhp_type =
    int8_t;
  _mean_xhp_type mean_xhp;
  using _mean_yhp_type =
    int8_t;
  _mean_yhp_type mean_yhp;
  using _mean_zhp_type =
    int8_t;
  _mean_zhp_type mean_zhp;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _mean_acc_type =
    uint32_t;
  _mean_acc_type mean_acc;
  using _obs_type =
    uint32_t;
  _obs_type obs;
  using _valid_type =
    uint8_t;
  _valid_type valid;
  using _active_type =
    uint8_t;
  _active_type active;
  using _reserved3_type =
    std::array<uint8_t, 2>;
  _reserved3_type reserved3;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__dur(
    const uint32_t & _arg)
  {
    this->dur = _arg;
    return *this;
  }
  Type & set__mean_x(
    const int32_t & _arg)
  {
    this->mean_x = _arg;
    return *this;
  }
  Type & set__mean_y(
    const int32_t & _arg)
  {
    this->mean_y = _arg;
    return *this;
  }
  Type & set__mean_z(
    const int32_t & _arg)
  {
    this->mean_z = _arg;
    return *this;
  }
  Type & set__mean_xhp(
    const int8_t & _arg)
  {
    this->mean_xhp = _arg;
    return *this;
  }
  Type & set__mean_yhp(
    const int8_t & _arg)
  {
    this->mean_yhp = _arg;
    return *this;
  }
  Type & set__mean_zhp(
    const int8_t & _arg)
  {
    this->mean_zhp = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__mean_acc(
    const uint32_t & _arg)
  {
    this->mean_acc = _arg;
    return *this;
  }
  Type & set__obs(
    const uint32_t & _arg)
  {
    this->obs = _arg;
    return *this;
  }
  Type & set__valid(
    const uint8_t & _arg)
  {
    this->valid = _arg;
    return *this;
  }
  Type & set__active(
    const uint8_t & _arg)
  {
    this->active = _arg;
    return *this;
  }
  Type & set__reserved3(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved3 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    59u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSVIN_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSVIN_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSVIN_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSVIN_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSVIN
    std::shared_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSVIN
    std::shared_ptr<ublox_msgs::msg::NavSVIN_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSVIN_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->dur != other.dur) {
      return false;
    }
    if (this->mean_x != other.mean_x) {
      return false;
    }
    if (this->mean_y != other.mean_y) {
      return false;
    }
    if (this->mean_z != other.mean_z) {
      return false;
    }
    if (this->mean_xhp != other.mean_xhp) {
      return false;
    }
    if (this->mean_yhp != other.mean_yhp) {
      return false;
    }
    if (this->mean_zhp != other.mean_zhp) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->mean_acc != other.mean_acc) {
      return false;
    }
    if (this->obs != other.obs) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->active != other.active) {
      return false;
    }
    if (this->reserved3 != other.reserved3) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSVIN_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSVIN_

// alias to use template instance with default allocator
using NavSVIN =
  ublox_msgs::msg::NavSVIN_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVIN_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSVIN_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVIN__STRUCT_HPP_

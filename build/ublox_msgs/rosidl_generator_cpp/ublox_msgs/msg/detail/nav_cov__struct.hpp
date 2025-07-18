// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavCOV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_COV__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_COV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavCOV __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavCOV __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavCOV_
{
  using Type = NavCOV_<ContainerAllocator>;

  explicit NavCOV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      this->pos_cov_valid = 0;
      this->vel_cov_valid = 0;
      std::fill<typename std::array<uint8_t, 9>::iterator, uint8_t>(this->reserved_0.begin(), this->reserved_0.end(), 0);
      this->pos_cov_nn = 0.0f;
      this->pos_cov_ne = 0.0f;
      this->pos_cov_nd = 0.0f;
      this->pos_cov_ee = 0.0f;
      this->pos_cov_ed = 0.0f;
      this->pos_cov_dd = 0.0f;
      this->vel_cov_nn = 0.0f;
      this->vel_cov_ne = 0.0f;
      this->vel_cov_nd = 0.0f;
      this->vel_cov_ee = 0.0f;
      this->vel_cov_ed = 0.0f;
      this->vel_cov_dd = 0.0f;
    }
  }

  explicit NavCOV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved_0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      this->pos_cov_valid = 0;
      this->vel_cov_valid = 0;
      std::fill<typename std::array<uint8_t, 9>::iterator, uint8_t>(this->reserved_0.begin(), this->reserved_0.end(), 0);
      this->pos_cov_nn = 0.0f;
      this->pos_cov_ne = 0.0f;
      this->pos_cov_nd = 0.0f;
      this->pos_cov_ee = 0.0f;
      this->pos_cov_ed = 0.0f;
      this->pos_cov_dd = 0.0f;
      this->vel_cov_nn = 0.0f;
      this->vel_cov_ne = 0.0f;
      this->vel_cov_nd = 0.0f;
      this->vel_cov_ee = 0.0f;
      this->vel_cov_ed = 0.0f;
      this->vel_cov_dd = 0.0f;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _version_type =
    uint8_t;
  _version_type version;
  using _pos_cov_valid_type =
    uint8_t;
  _pos_cov_valid_type pos_cov_valid;
  using _vel_cov_valid_type =
    uint8_t;
  _vel_cov_valid_type vel_cov_valid;
  using _reserved_0_type =
    std::array<uint8_t, 9>;
  _reserved_0_type reserved_0;
  using _pos_cov_nn_type =
    float;
  _pos_cov_nn_type pos_cov_nn;
  using _pos_cov_ne_type =
    float;
  _pos_cov_ne_type pos_cov_ne;
  using _pos_cov_nd_type =
    float;
  _pos_cov_nd_type pos_cov_nd;
  using _pos_cov_ee_type =
    float;
  _pos_cov_ee_type pos_cov_ee;
  using _pos_cov_ed_type =
    float;
  _pos_cov_ed_type pos_cov_ed;
  using _pos_cov_dd_type =
    float;
  _pos_cov_dd_type pos_cov_dd;
  using _vel_cov_nn_type =
    float;
  _vel_cov_nn_type vel_cov_nn;
  using _vel_cov_ne_type =
    float;
  _vel_cov_ne_type vel_cov_ne;
  using _vel_cov_nd_type =
    float;
  _vel_cov_nd_type vel_cov_nd;
  using _vel_cov_ee_type =
    float;
  _vel_cov_ee_type vel_cov_ee;
  using _vel_cov_ed_type =
    float;
  _vel_cov_ed_type vel_cov_ed;
  using _vel_cov_dd_type =
    float;
  _vel_cov_dd_type vel_cov_dd;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__pos_cov_valid(
    const uint8_t & _arg)
  {
    this->pos_cov_valid = _arg;
    return *this;
  }
  Type & set__vel_cov_valid(
    const uint8_t & _arg)
  {
    this->vel_cov_valid = _arg;
    return *this;
  }
  Type & set__reserved_0(
    const std::array<uint8_t, 9> & _arg)
  {
    this->reserved_0 = _arg;
    return *this;
  }
  Type & set__pos_cov_nn(
    const float & _arg)
  {
    this->pos_cov_nn = _arg;
    return *this;
  }
  Type & set__pos_cov_ne(
    const float & _arg)
  {
    this->pos_cov_ne = _arg;
    return *this;
  }
  Type & set__pos_cov_nd(
    const float & _arg)
  {
    this->pos_cov_nd = _arg;
    return *this;
  }
  Type & set__pos_cov_ee(
    const float & _arg)
  {
    this->pos_cov_ee = _arg;
    return *this;
  }
  Type & set__pos_cov_ed(
    const float & _arg)
  {
    this->pos_cov_ed = _arg;
    return *this;
  }
  Type & set__pos_cov_dd(
    const float & _arg)
  {
    this->pos_cov_dd = _arg;
    return *this;
  }
  Type & set__vel_cov_nn(
    const float & _arg)
  {
    this->vel_cov_nn = _arg;
    return *this;
  }
  Type & set__vel_cov_ne(
    const float & _arg)
  {
    this->vel_cov_ne = _arg;
    return *this;
  }
  Type & set__vel_cov_nd(
    const float & _arg)
  {
    this->vel_cov_nd = _arg;
    return *this;
  }
  Type & set__vel_cov_ee(
    const float & _arg)
  {
    this->vel_cov_ee = _arg;
    return *this;
  }
  Type & set__vel_cov_ed(
    const float & _arg)
  {
    this->vel_cov_ed = _arg;
    return *this;
  }
  Type & set__vel_cov_dd(
    const float & _arg)
  {
    this->vel_cov_dd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    54u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavCOV_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavCOV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavCOV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavCOV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavCOV
    std::shared_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavCOV
    std::shared_ptr<ublox_msgs::msg::NavCOV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavCOV_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->pos_cov_valid != other.pos_cov_valid) {
      return false;
    }
    if (this->vel_cov_valid != other.vel_cov_valid) {
      return false;
    }
    if (this->reserved_0 != other.reserved_0) {
      return false;
    }
    if (this->pos_cov_nn != other.pos_cov_nn) {
      return false;
    }
    if (this->pos_cov_ne != other.pos_cov_ne) {
      return false;
    }
    if (this->pos_cov_nd != other.pos_cov_nd) {
      return false;
    }
    if (this->pos_cov_ee != other.pos_cov_ee) {
      return false;
    }
    if (this->pos_cov_ed != other.pos_cov_ed) {
      return false;
    }
    if (this->pos_cov_dd != other.pos_cov_dd) {
      return false;
    }
    if (this->vel_cov_nn != other.vel_cov_nn) {
      return false;
    }
    if (this->vel_cov_ne != other.vel_cov_ne) {
      return false;
    }
    if (this->vel_cov_nd != other.vel_cov_nd) {
      return false;
    }
    if (this->vel_cov_ee != other.vel_cov_ee) {
      return false;
    }
    if (this->vel_cov_ed != other.vel_cov_ed) {
      return false;
    }
    if (this->vel_cov_dd != other.vel_cov_dd) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavCOV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavCOV_

// alias to use template instance with default allocator
using NavCOV =
  ublox_msgs::msg::NavCOV_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavCOV_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavCOV_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_COV__STRUCT_HPP_

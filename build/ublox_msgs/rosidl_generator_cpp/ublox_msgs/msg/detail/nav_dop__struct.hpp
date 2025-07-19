// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavDOP.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DOP__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DOP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavDOP __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavDOP __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavDOP_
{
  using Type = NavDOP_<ContainerAllocator>;

  explicit NavDOP_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->g_dop = 0;
      this->p_dop = 0;
      this->t_dop = 0;
      this->v_dop = 0;
      this->h_dop = 0;
      this->n_dop = 0;
      this->e_dop = 0;
    }
  }

  explicit NavDOP_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->g_dop = 0;
      this->p_dop = 0;
      this->t_dop = 0;
      this->v_dop = 0;
      this->h_dop = 0;
      this->n_dop = 0;
      this->e_dop = 0;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _g_dop_type =
    uint16_t;
  _g_dop_type g_dop;
  using _p_dop_type =
    uint16_t;
  _p_dop_type p_dop;
  using _t_dop_type =
    uint16_t;
  _t_dop_type t_dop;
  using _v_dop_type =
    uint16_t;
  _v_dop_type v_dop;
  using _h_dop_type =
    uint16_t;
  _h_dop_type h_dop;
  using _n_dop_type =
    uint16_t;
  _n_dop_type n_dop;
  using _e_dop_type =
    uint16_t;
  _e_dop_type e_dop;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__g_dop(
    const uint16_t & _arg)
  {
    this->g_dop = _arg;
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
  Type & set__v_dop(
    const uint16_t & _arg)
  {
    this->v_dop = _arg;
    return *this;
  }
  Type & set__h_dop(
    const uint16_t & _arg)
  {
    this->h_dop = _arg;
    return *this;
  }
  Type & set__n_dop(
    const uint16_t & _arg)
  {
    this->n_dop = _arg;
    return *this;
  }
  Type & set__e_dop(
    const uint16_t & _arg)
  {
    this->e_dop = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavDOP_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavDOP_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavDOP_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavDOP_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavDOP
    std::shared_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavDOP
    std::shared_ptr<ublox_msgs::msg::NavDOP_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavDOP_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->g_dop != other.g_dop) {
      return false;
    }
    if (this->p_dop != other.p_dop) {
      return false;
    }
    if (this->t_dop != other.t_dop) {
      return false;
    }
    if (this->v_dop != other.v_dop) {
      return false;
    }
    if (this->h_dop != other.h_dop) {
      return false;
    }
    if (this->n_dop != other.n_dop) {
      return false;
    }
    if (this->e_dop != other.e_dop) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavDOP_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavDOP_

// alias to use template instance with default allocator
using NavDOP =
  ublox_msgs::msg::NavDOP_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDOP_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDOP_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DOP__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavCLOCK.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavCLOCK __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavCLOCK __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavCLOCK_
{
  using Type = NavCLOCK_<ContainerAllocator>;

  explicit NavCLOCK_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->clk_b = 0l;
      this->clk_d = 0l;
      this->t_acc = 0ul;
      this->f_acc = 0ul;
    }
  }

  explicit NavCLOCK_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->clk_b = 0l;
      this->clk_d = 0l;
      this->t_acc = 0ul;
      this->f_acc = 0ul;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _clk_b_type =
    int32_t;
  _clk_b_type clk_b;
  using _clk_d_type =
    int32_t;
  _clk_d_type clk_d;
  using _t_acc_type =
    uint32_t;
  _t_acc_type t_acc;
  using _f_acc_type =
    uint32_t;
  _f_acc_type f_acc;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__clk_b(
    const int32_t & _arg)
  {
    this->clk_b = _arg;
    return *this;
  }
  Type & set__clk_d(
    const int32_t & _arg)
  {
    this->clk_d = _arg;
    return *this;
  }
  Type & set__t_acc(
    const uint32_t & _arg)
  {
    this->t_acc = _arg;
    return *this;
  }
  Type & set__f_acc(
    const uint32_t & _arg)
  {
    this->f_acc = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    34u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavCLOCK_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavCLOCK_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavCLOCK_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavCLOCK_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavCLOCK
    std::shared_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavCLOCK
    std::shared_ptr<ublox_msgs::msg::NavCLOCK_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavCLOCK_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->clk_b != other.clk_b) {
      return false;
    }
    if (this->clk_d != other.clk_d) {
      return false;
    }
    if (this->t_acc != other.t_acc) {
      return false;
    }
    if (this->f_acc != other.f_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavCLOCK_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavCLOCK_

// alias to use template instance with default allocator
using NavCLOCK =
  ublox_msgs::msg::NavCLOCK_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavCLOCK_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavCLOCK_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_CLOCK__STRUCT_HPP_

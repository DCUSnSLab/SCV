// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/Inf.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__INF__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__INF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__Inf __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__Inf __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Inf_
{
  using Type = Inf_<ContainerAllocator>;

  explicit Inf_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Inf_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _str_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _str_type str;

  // setters for named parameter idiom
  Type & set__str(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->str = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::Inf_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::Inf_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::Inf_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::Inf_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::Inf_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::Inf_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::Inf_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::Inf_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::Inf_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::Inf_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__Inf
    std::shared_ptr<ublox_msgs::msg::Inf_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__Inf
    std::shared_ptr<ublox_msgs::msg::Inf_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Inf_ & other) const
  {
    if (this->str != other.str) {
      return false;
    }
    return true;
  }
  bool operator!=(const Inf_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Inf_

// alias to use template instance with default allocator
using Inf =
  ublox_msgs::msg::Inf_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Inf_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__INF__STRUCT_HPP_

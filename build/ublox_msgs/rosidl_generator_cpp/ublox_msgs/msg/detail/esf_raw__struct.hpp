// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/EsfRAW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_RAW__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_RAW__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'blocks'
#include "ublox_msgs/msg/detail/esf_raw_block__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__EsfRAW __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__EsfRAW __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EsfRAW_
{
  using Type = EsfRAW_<ContainerAllocator>;

  explicit EsfRAW_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  explicit EsfRAW_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  // field types and members
  using _reserved0_type =
    std::array<uint8_t, 4>;
  _reserved0_type reserved0;
  using _blocks_type =
    std::vector<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>>>;
  _blocks_type blocks;

  // setters for named parameter idiom
  Type & set__reserved0(
    const std::array<uint8_t, 4> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__blocks(
    const std::vector<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>>> & _arg)
  {
    this->blocks = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    16u;
  static constexpr uint8_t MESSAGE_ID =
    3u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::EsfRAW_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::EsfRAW_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfRAW_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfRAW_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__EsfRAW
    std::shared_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__EsfRAW
    std::shared_ptr<ublox_msgs::msg::EsfRAW_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EsfRAW_ & other) const
  {
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->blocks != other.blocks) {
      return false;
    }
    return true;
  }
  bool operator!=(const EsfRAW_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EsfRAW_

// alias to use template instance with default allocator
using EsfRAW =
  ublox_msgs::msg::EsfRAW_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfRAW_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfRAW_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_RAW__STRUCT_HPP_

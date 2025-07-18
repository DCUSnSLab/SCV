// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/EsfRAWBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__EsfRAWBlock __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__EsfRAWBlock __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EsfRAWBlock_
{
  using Type = EsfRAWBlock_<ContainerAllocator>;

  explicit EsfRAWBlock_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0ul;
      this->s_t_tag = 0ul;
    }
  }

  explicit EsfRAWBlock_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0ul;
      this->s_t_tag = 0ul;
    }
  }

  // field types and members
  using _data_type =
    uint32_t;
  _data_type data;
  using _s_t_tag_type =
    uint32_t;
  _s_t_tag_type s_t_tag;

  // setters for named parameter idiom
  Type & set__data(
    const uint32_t & _arg)
  {
    this->data = _arg;
    return *this;
  }
  Type & set__s_t_tag(
    const uint32_t & _arg)
  {
    this->s_t_tag = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t DATA_FIELD_MASK =
    16777215u;
  static constexpr uint32_t DATA_TYPE_MASK =
    4278190080u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__EsfRAWBlock
    std::shared_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__EsfRAWBlock
    std::shared_ptr<ublox_msgs::msg::EsfRAWBlock_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EsfRAWBlock_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    if (this->s_t_tag != other.s_t_tag) {
      return false;
    }
    return true;
  }
  bool operator!=(const EsfRAWBlock_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EsfRAWBlock_

// alias to use template instance with default allocator
using EsfRAWBlock =
  ublox_msgs::msg::EsfRAWBlock_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfRAWBlock_<ContainerAllocator>::DATA_FIELD_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfRAWBlock_<ContainerAllocator>::DATA_TYPE_MASK;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgMSG.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_MSG__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgMSG __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgMSG __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgMSG_
{
  using Type = CfgMSG_<ContainerAllocator>;

  explicit CfgMSG_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_class = 0;
      this->msg_id = 0;
      this->rate = 0;
    }
  }

  explicit CfgMSG_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_class = 0;
      this->msg_id = 0;
      this->rate = 0;
    }
  }

  // field types and members
  using _msg_class_type =
    uint8_t;
  _msg_class_type msg_class;
  using _msg_id_type =
    uint8_t;
  _msg_id_type msg_id;
  using _rate_type =
    uint8_t;
  _rate_type rate;

  // setters for named parameter idiom
  Type & set__msg_class(
    const uint8_t & _arg)
  {
    this->msg_class = _arg;
    return *this;
  }
  Type & set__msg_id(
    const uint8_t & _arg)
  {
    this->msg_id = _arg;
    return *this;
  }
  Type & set__rate(
    const uint8_t & _arg)
  {
    this->rate = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    1u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgMSG_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgMSG_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgMSG_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgMSG_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgMSG
    std::shared_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgMSG
    std::shared_ptr<ublox_msgs::msg::CfgMSG_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgMSG_ & other) const
  {
    if (this->msg_class != other.msg_class) {
      return false;
    }
    if (this->msg_id != other.msg_id) {
      return false;
    }
    if (this->rate != other.rate) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgMSG_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgMSG_

// alias to use template instance with default allocator
using CfgMSG =
  ublox_msgs::msg::CfgMSG_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgMSG_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgMSG_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_MSG__STRUCT_HPP_

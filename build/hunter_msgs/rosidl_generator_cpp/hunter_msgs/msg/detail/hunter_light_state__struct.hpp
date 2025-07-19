// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hunter_msgs:msg/HunterLightState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__STRUCT_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hunter_msgs__msg__HunterLightState __attribute__((deprecated))
#else
# define DEPRECATED__hunter_msgs__msg__HunterLightState __declspec(deprecated)
#endif

namespace hunter_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HunterLightState_
{
  using Type = HunterLightState_<ContainerAllocator>;

  explicit HunterLightState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->custom_value = 0;
    }
  }

  explicit HunterLightState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->custom_value = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _custom_value_type =
    uint8_t;
  _custom_value_type custom_value;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__custom_value(
    const uint8_t & _arg)
  {
    this->custom_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hunter_msgs::msg::HunterLightState_<ContainerAllocator> *;
  using ConstRawPtr =
    const hunter_msgs::msg::HunterLightState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hunter_msgs::msg::HunterLightState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hunter_msgs::msg::HunterLightState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hunter_msgs__msg__HunterLightState
    std::shared_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hunter_msgs__msg__HunterLightState
    std::shared_ptr<hunter_msgs::msg::HunterLightState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HunterLightState_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->custom_value != other.custom_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const HunterLightState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HunterLightState_

// alias to use template instance with default allocator
using HunterLightState =
  hunter_msgs::msg::HunterLightState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hunter_msgs

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__STRUCT_HPP_

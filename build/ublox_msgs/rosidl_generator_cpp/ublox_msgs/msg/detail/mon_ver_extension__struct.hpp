// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/MonVERExtension.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__MonVERExtension __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__MonVERExtension __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MonVERExtension_
{
  using Type = MonVERExtension_<ContainerAllocator>;

  explicit MonVERExtension_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 30>::iterator, uint8_t>(this->field.begin(), this->field.end(), 0);
    }
  }

  explicit MonVERExtension_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : field(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 30>::iterator, uint8_t>(this->field.begin(), this->field.end(), 0);
    }
  }

  // field types and members
  using _field_type =
    std::array<uint8_t, 30>;
  _field_type field;

  // setters for named parameter idiom
  Type & set__field(
    const std::array<uint8_t, 30> & _arg)
  {
    this->field = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ublox_msgs::msg::MonVERExtension_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::MonVERExtension_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonVERExtension_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonVERExtension_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__MonVERExtension
    std::shared_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__MonVERExtension
    std::shared_ptr<ublox_msgs::msg::MonVERExtension_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MonVERExtension_ & other) const
  {
    if (this->field != other.field) {
      return false;
    }
    return true;
  }
  bool operator!=(const MonVERExtension_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MonVERExtension_

// alias to use template instance with default allocator
using MonVERExtension =
  ublox_msgs::msg::MonVERExtension_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_VER_EXTENSION__STRUCT_HPP_

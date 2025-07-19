// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/MonVER.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MON_VER__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MON_VER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'extension'
#include "ublox_msgs/msg/detail/mon_ver_extension__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__MonVER __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__MonVER __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MonVER_
{
  using Type = MonVER_<ContainerAllocator>;

  explicit MonVER_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 30>::iterator, uint8_t>(this->sw_version.begin(), this->sw_version.end(), 0);
      std::fill<typename std::array<uint8_t, 10>::iterator, uint8_t>(this->hw_version.begin(), this->hw_version.end(), 0);
    }
  }

  explicit MonVER_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sw_version(_alloc),
    hw_version(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 30>::iterator, uint8_t>(this->sw_version.begin(), this->sw_version.end(), 0);
      std::fill<typename std::array<uint8_t, 10>::iterator, uint8_t>(this->hw_version.begin(), this->hw_version.end(), 0);
    }
  }

  // field types and members
  using _sw_version_type =
    std::array<uint8_t, 30>;
  _sw_version_type sw_version;
  using _hw_version_type =
    std::array<uint8_t, 10>;
  _hw_version_type hw_version;
  using _extension_type =
    std::vector<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>>>;
  _extension_type extension;

  // setters for named parameter idiom
  Type & set__sw_version(
    const std::array<uint8_t, 30> & _arg)
  {
    this->sw_version = _arg;
    return *this;
  }
  Type & set__hw_version(
    const std::array<uint8_t, 10> & _arg)
  {
    this->hw_version = _arg;
    return *this;
  }
  Type & set__extension(
    const std::vector<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::MonVERExtension_<ContainerAllocator>>> & _arg)
  {
    this->extension = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    10u;
  static constexpr uint8_t MESSAGE_ID =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::MonVER_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::MonVER_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonVER_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MonVER_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__MonVER
    std::shared_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__MonVER
    std::shared_ptr<ublox_msgs::msg::MonVER_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MonVER_ & other) const
  {
    if (this->sw_version != other.sw_version) {
      return false;
    }
    if (this->hw_version != other.hw_version) {
      return false;
    }
    if (this->extension != other.extension) {
      return false;
    }
    return true;
  }
  bool operator!=(const MonVER_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MonVER_

// alias to use template instance with default allocator
using MonVER =
  ublox_msgs::msg::MonVER_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonVER_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MonVER_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MON_VER__STRUCT_HPP_

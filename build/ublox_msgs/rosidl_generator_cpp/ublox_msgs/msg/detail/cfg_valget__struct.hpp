// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgVALGET.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgVALGET __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgVALGET __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgVALGET_
{
  using Type = CfgVALGET_<ContainerAllocator>;

  explicit CfgVALGET_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->layers = 0;
      this->position = 0;
    }
  }

  explicit CfgVALGET_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->layers = 0;
      this->position = 0;
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _layers_type =
    uint8_t;
  _layers_type layers;
  using _position_type =
    uint16_t;
  _position_type position;
  using _keys_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _keys_type keys;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__layers(
    const uint8_t & _arg)
  {
    this->layers = _arg;
    return *this;
  }
  Type & set__position(
    const uint16_t & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__keys(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->keys = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    139u;
  static constexpr uint8_t LAYER_RAM =
    0u;
  static constexpr uint8_t LAYER_BBR =
    1u;
  static constexpr uint8_t LAYER_FLASH =
    2u;
  static constexpr uint8_t LAYER_DEFAULT =
    7u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgVALGET_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgVALGET_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgVALGET_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgVALGET_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgVALGET
    std::shared_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgVALGET
    std::shared_ptr<ublox_msgs::msg::CfgVALGET_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgVALGET_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->layers != other.layers) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->keys != other.keys) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgVALGET_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgVALGET_

// alias to use template instance with default allocator
using CfgVALGET =
  ublox_msgs::msg::CfgVALGET_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALGET_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALGET_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALGET_<ContainerAllocator>::LAYER_RAM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALGET_<ContainerAllocator>::LAYER_BBR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALGET_<ContainerAllocator>::LAYER_FLASH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALGET_<ContainerAllocator>::LAYER_DEFAULT;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALGET__STRUCT_HPP_

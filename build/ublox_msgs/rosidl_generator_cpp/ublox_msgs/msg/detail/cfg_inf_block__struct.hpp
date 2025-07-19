// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgINFBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgINFBlock __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgINFBlock __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgINFBlock_
{
  using Type = CfgINFBlock_<ContainerAllocator>;

  explicit CfgINFBlock_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->protocol_id = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->inf_msg_mask.begin(), this->inf_msg_mask.end(), 0);
    }
  }

  explicit CfgINFBlock_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc),
    inf_msg_mask(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->protocol_id = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->inf_msg_mask.begin(), this->inf_msg_mask.end(), 0);
    }
  }

  // field types and members
  using _protocol_id_type =
    uint8_t;
  _protocol_id_type protocol_id;
  using _reserved1_type =
    std::array<uint8_t, 3>;
  _reserved1_type reserved1;
  using _inf_msg_mask_type =
    std::array<uint8_t, 6>;
  _inf_msg_mask_type inf_msg_mask;

  // setters for named parameter idiom
  Type & set__protocol_id(
    const uint8_t & _arg)
  {
    this->protocol_id = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__inf_msg_mask(
    const std::array<uint8_t, 6> & _arg)
  {
    this->inf_msg_mask = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t PROTOCOL_ID_UBX =
    0u;
  static constexpr uint8_t PROTOCOL_ID_NMEA =
    1u;
  static constexpr uint8_t INF_MSG_ERROR =
    1u;
  static constexpr uint8_t INF_MSG_WARNING =
    2u;
  static constexpr uint8_t INF_MSG_NOTICE =
    4u;
  static constexpr uint8_t INF_MSG_TEST =
    8u;
  static constexpr uint8_t INF_MSG_DEBUG =
    16u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgINFBlock_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgINFBlock_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgINFBlock_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgINFBlock_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgINFBlock
    std::shared_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgINFBlock
    std::shared_ptr<ublox_msgs::msg::CfgINFBlock_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgINFBlock_ & other) const
  {
    if (this->protocol_id != other.protocol_id) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->inf_msg_mask != other.inf_msg_mask) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgINFBlock_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgINFBlock_

// alias to use template instance with default allocator
using CfgINFBlock =
  ublox_msgs::msg::CfgINFBlock_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgINFBlock_<ContainerAllocator>::PROTOCOL_ID_UBX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgINFBlock_<ContainerAllocator>::PROTOCOL_ID_NMEA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgINFBlock_<ContainerAllocator>::INF_MSG_ERROR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgINFBlock_<ContainerAllocator>::INF_MSG_WARNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgINFBlock_<ContainerAllocator>::INF_MSG_NOTICE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgINFBlock_<ContainerAllocator>::INF_MSG_TEST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgINFBlock_<ContainerAllocator>::INF_MSG_DEBUG;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_INF_BLOCK__STRUCT_HPP_

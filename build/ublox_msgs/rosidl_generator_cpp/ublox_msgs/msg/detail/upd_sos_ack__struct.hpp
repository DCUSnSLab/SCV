// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/UpdSOSAck.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__UpdSOSAck __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__UpdSOSAck __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UpdSOSAck_
{
  using Type = UpdSOSAck_<ContainerAllocator>;

  explicit UpdSOSAck_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->response = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  explicit UpdSOSAck_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc),
    reserved1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
      this->response = 0;
      std::fill<typename std::array<uint8_t, 3>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  // field types and members
  using _cmd_type =
    uint8_t;
  _cmd_type cmd;
  using _reserved0_type =
    std::array<uint8_t, 3>;
  _reserved0_type reserved0;
  using _response_type =
    uint8_t;
  _response_type response;
  using _reserved1_type =
    std::array<uint8_t, 3>;
  _reserved1_type reserved1;

  // setters for named parameter idiom
  Type & set__cmd(
    const uint8_t & _arg)
  {
    this->cmd = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__response(
    const uint8_t & _arg)
  {
    this->response = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 3> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    9u;
  static constexpr uint8_t MESSAGE_ID =
    20u;
  static constexpr uint8_t CMD_BACKUP_CREATE_ACK =
    2u;
  static constexpr uint8_t CMD_SYSTEM_RESTORED =
    3u;
  static constexpr uint8_t BACKUP_CREATE_NACK =
    0u;
  static constexpr uint8_t BACKUP_CREATE_ACK =
    1u;
  static constexpr uint8_t SYSTEM_RESTORED_RESPONSE_UNKNOWN =
    0u;
  static constexpr uint8_t SYSTEM_RESTORED_RESPONSE_FAILED =
    1u;
  static constexpr uint8_t SYSTEM_RESTORED_RESPONSE_RESTORED =
    2u;
  static constexpr uint8_t SYSTEM_RESTORED_RESPONSE_NOT_RESTORED =
    3u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::UpdSOSAck_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::UpdSOSAck_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::UpdSOSAck_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::UpdSOSAck_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__UpdSOSAck
    std::shared_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__UpdSOSAck
    std::shared_ptr<ublox_msgs::msg::UpdSOSAck_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpdSOSAck_ & other) const
  {
    if (this->cmd != other.cmd) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpdSOSAck_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpdSOSAck_

// alias to use template instance with default allocator
using UpdSOSAck =
  ublox_msgs::msg::UpdSOSAck_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::CMD_BACKUP_CREATE_ACK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::CMD_SYSTEM_RESTORED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::BACKUP_CREATE_NACK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::BACKUP_CREATE_ACK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::SYSTEM_RESTORED_RESPONSE_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::SYSTEM_RESTORED_RESPONSE_FAILED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::SYSTEM_RESTORED_RESPONSE_RESTORED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UpdSOSAck_<ContainerAllocator>::SYSTEM_RESTORED_RESPONSE_NOT_RESTORED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__UPD_SOS_ACK__STRUCT_HPP_

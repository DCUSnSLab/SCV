// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmSFRB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmSFRB __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmSFRB __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmSFRB_
{
  using Type = RxmSFRB_<ContainerAllocator>;

  explicit RxmSFRB_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chn = 0;
      this->svid = 0;
      std::fill<typename std::array<uint32_t, 10>::iterator, uint32_t>(this->dwrd.begin(), this->dwrd.end(), 0ul);
    }
  }

  explicit RxmSFRB_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : dwrd(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chn = 0;
      this->svid = 0;
      std::fill<typename std::array<uint32_t, 10>::iterator, uint32_t>(this->dwrd.begin(), this->dwrd.end(), 0ul);
    }
  }

  // field types and members
  using _chn_type =
    uint8_t;
  _chn_type chn;
  using _svid_type =
    uint8_t;
  _svid_type svid;
  using _dwrd_type =
    std::array<uint32_t, 10>;
  _dwrd_type dwrd;

  // setters for named parameter idiom
  Type & set__chn(
    const uint8_t & _arg)
  {
    this->chn = _arg;
    return *this;
  }
  Type & set__svid(
    const uint8_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__dwrd(
    const std::array<uint32_t, 10> & _arg)
  {
    this->dwrd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    2u;
  static constexpr uint8_t MESSAGE_ID =
    17u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmSFRB_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmSFRB_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmSFRB_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmSFRB_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmSFRB
    std::shared_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmSFRB
    std::shared_ptr<ublox_msgs::msg::RxmSFRB_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmSFRB_ & other) const
  {
    if (this->chn != other.chn) {
      return false;
    }
    if (this->svid != other.svid) {
      return false;
    }
    if (this->dwrd != other.dwrd) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmSFRB_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmSFRB_

// alias to use template instance with default allocator
using RxmSFRB =
  ublox_msgs::msg::RxmSFRB_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSFRB_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSFRB_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__STRUCT_HPP_

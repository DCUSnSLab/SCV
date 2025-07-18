// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmRAW.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAW__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAW__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/rxm_rawsv__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmRAW __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmRAW __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmRAW_
{
  using Type = RxmRAW_<ContainerAllocator>;

  explicit RxmRAW_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rcv_tow = 0l;
      this->week = 0;
      this->num_sv = 0;
      this->reserved1 = 0;
    }
  }

  explicit RxmRAW_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rcv_tow = 0l;
      this->week = 0;
      this->num_sv = 0;
      this->reserved1 = 0;
    }
  }

  // field types and members
  using _rcv_tow_type =
    int32_t;
  _rcv_tow_type rcv_tow;
  using _week_type =
    int16_t;
  _week_type week;
  using _num_sv_type =
    uint8_t;
  _num_sv_type num_sv;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _sv_type =
    std::vector<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>>>;
  _sv_type sv;

  // setters for named parameter idiom
  Type & set__rcv_tow(
    const int32_t & _arg)
  {
    this->rcv_tow = _arg;
    return *this;
  }
  Type & set__week(
    const int16_t & _arg)
  {
    this->week = _arg;
    return *this;
  }
  Type & set__num_sv(
    const uint8_t & _arg)
  {
    this->num_sv = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__sv(
    const std::vector<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>>> & _arg)
  {
    this->sv = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    2u;
  static constexpr uint8_t MESSAGE_ID =
    16u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmRAW_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmRAW_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAW_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAW_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmRAW
    std::shared_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmRAW
    std::shared_ptr<ublox_msgs::msg::RxmRAW_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmRAW_ & other) const
  {
    if (this->rcv_tow != other.rcv_tow) {
      return false;
    }
    if (this->week != other.week) {
      return false;
    }
    if (this->num_sv != other.num_sv) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->sv != other.sv) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmRAW_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmRAW_

// alias to use template instance with default allocator
using RxmRAW =
  ublox_msgs::msg::RxmRAW_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAW_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAW_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAW__STRUCT_HPP_

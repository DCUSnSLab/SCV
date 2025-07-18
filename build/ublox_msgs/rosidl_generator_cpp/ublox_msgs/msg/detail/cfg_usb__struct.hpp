// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgUSB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_USB__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_USB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgUSB __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgUSB __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgUSB_
{
  using Type = CfgUSB_<ContainerAllocator>;

  explicit CfgUSB_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vendor_id = 0;
      this->product_id = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
      this->power_consumption = 0;
      this->flags = 0;
      std::fill<typename std::array<int8_t, 32>::iterator, int8_t>(this->vendor_string.begin(), this->vendor_string.end(), 0);
      std::fill<typename std::array<int8_t, 32>::iterator, int8_t>(this->product_string.begin(), this->product_string.end(), 0);
      std::fill<typename std::array<int8_t, 32>::iterator, int8_t>(this->serial_number.begin(), this->serial_number.end(), 0);
    }
  }

  explicit CfgUSB_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc),
    reserved2(_alloc),
    vendor_string(_alloc),
    product_string(_alloc),
    serial_number(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vendor_id = 0;
      this->product_id = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
      this->power_consumption = 0;
      this->flags = 0;
      std::fill<typename std::array<int8_t, 32>::iterator, int8_t>(this->vendor_string.begin(), this->vendor_string.end(), 0);
      std::fill<typename std::array<int8_t, 32>::iterator, int8_t>(this->product_string.begin(), this->product_string.end(), 0);
      std::fill<typename std::array<int8_t, 32>::iterator, int8_t>(this->serial_number.begin(), this->serial_number.end(), 0);
    }
  }

  // field types and members
  using _vendor_id_type =
    uint16_t;
  _vendor_id_type vendor_id;
  using _product_id_type =
    uint16_t;
  _product_id_type product_id;
  using _reserved1_type =
    std::array<uint8_t, 2>;
  _reserved1_type reserved1;
  using _reserved2_type =
    std::array<uint8_t, 2>;
  _reserved2_type reserved2;
  using _power_consumption_type =
    uint16_t;
  _power_consumption_type power_consumption;
  using _flags_type =
    uint16_t;
  _flags_type flags;
  using _vendor_string_type =
    std::array<int8_t, 32>;
  _vendor_string_type vendor_string;
  using _product_string_type =
    std::array<int8_t, 32>;
  _product_string_type product_string;
  using _serial_number_type =
    std::array<int8_t, 32>;
  _serial_number_type serial_number;

  // setters for named parameter idiom
  Type & set__vendor_id(
    const uint16_t & _arg)
  {
    this->vendor_id = _arg;
    return *this;
  }
  Type & set__product_id(
    const uint16_t & _arg)
  {
    this->product_id = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__reserved2(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }
  Type & set__power_consumption(
    const uint16_t & _arg)
  {
    this->power_consumption = _arg;
    return *this;
  }
  Type & set__flags(
    const uint16_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__vendor_string(
    const std::array<int8_t, 32> & _arg)
  {
    this->vendor_string = _arg;
    return *this;
  }
  Type & set__product_string(
    const std::array<int8_t, 32> & _arg)
  {
    this->product_string = _arg;
    return *this;
  }
  Type & set__serial_number(
    const std::array<int8_t, 32> & _arg)
  {
    this->serial_number = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    27u;
  static constexpr uint16_t FLAGS_RE_ENUM =
    0u;
  static constexpr uint16_t FLAGS_POWER_MODE =
    2u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgUSB_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgUSB_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgUSB_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgUSB_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgUSB
    std::shared_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgUSB
    std::shared_ptr<ublox_msgs::msg::CfgUSB_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgUSB_ & other) const
  {
    if (this->vendor_id != other.vendor_id) {
      return false;
    }
    if (this->product_id != other.product_id) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    if (this->power_consumption != other.power_consumption) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->vendor_string != other.vendor_string) {
      return false;
    }
    if (this->product_string != other.product_string) {
      return false;
    }
    if (this->serial_number != other.serial_number) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgUSB_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgUSB_

// alias to use template instance with default allocator
using CfgUSB =
  ublox_msgs::msg::CfgUSB_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgUSB_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgUSB_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgUSB_<ContainerAllocator>::FLAGS_RE_ENUM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgUSB_<ContainerAllocator>::FLAGS_POWER_MODE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_USB__STRUCT_HPP_

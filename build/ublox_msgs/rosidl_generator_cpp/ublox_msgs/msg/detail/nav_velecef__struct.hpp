// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavVELECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavVELECEF __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavVELECEF __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavVELECEF_
{
  using Type = NavVELECEF_<ContainerAllocator>;

  explicit NavVELECEF_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->ecef_vx = 0l;
      this->ecef_vy = 0l;
      this->ecef_vz = 0l;
      this->s_acc = 0ul;
    }
  }

  explicit NavVELECEF_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->ecef_vx = 0l;
      this->ecef_vy = 0l;
      this->ecef_vz = 0l;
      this->s_acc = 0ul;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _ecef_vx_type =
    int32_t;
  _ecef_vx_type ecef_vx;
  using _ecef_vy_type =
    int32_t;
  _ecef_vy_type ecef_vy;
  using _ecef_vz_type =
    int32_t;
  _ecef_vz_type ecef_vz;
  using _s_acc_type =
    uint32_t;
  _s_acc_type s_acc;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__ecef_vx(
    const int32_t & _arg)
  {
    this->ecef_vx = _arg;
    return *this;
  }
  Type & set__ecef_vy(
    const int32_t & _arg)
  {
    this->ecef_vy = _arg;
    return *this;
  }
  Type & set__ecef_vz(
    const int32_t & _arg)
  {
    this->ecef_vz = _arg;
    return *this;
  }
  Type & set__s_acc(
    const uint32_t & _arg)
  {
    this->s_acc = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    17u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavVELECEF_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavVELECEF_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavVELECEF_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavVELECEF_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavVELECEF
    std::shared_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavVELECEF
    std::shared_ptr<ublox_msgs::msg::NavVELECEF_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavVELECEF_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->ecef_vx != other.ecef_vx) {
      return false;
    }
    if (this->ecef_vy != other.ecef_vy) {
      return false;
    }
    if (this->ecef_vz != other.ecef_vz) {
      return false;
    }
    if (this->s_acc != other.s_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavVELECEF_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavVELECEF_

// alias to use template instance with default allocator
using NavVELECEF =
  ublox_msgs::msg::NavVELECEF_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavVELECEF_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavVELECEF_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_VELECEF__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSBASSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSBASSV __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSBASSV __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSBASSV_
{
  using Type = NavSBASSV_<ContainerAllocator>;

  explicit NavSBASSV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0;
      this->flags = 0;
      this->udre = 0;
      this->sv_sys = 0;
      this->sv_service = 0;
      this->reserved1 = 0;
      this->prc = 0;
      this->reserved2 = 0;
      this->ic = 0;
    }
  }

  explicit NavSBASSV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0;
      this->flags = 0;
      this->udre = 0;
      this->sv_sys = 0;
      this->sv_service = 0;
      this->reserved1 = 0;
      this->prc = 0;
      this->reserved2 = 0;
      this->ic = 0;
    }
  }

  // field types and members
  using _svid_type =
    uint8_t;
  _svid_type svid;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _udre_type =
    uint8_t;
  _udre_type udre;
  using _sv_sys_type =
    uint8_t;
  _sv_sys_type sv_sys;
  using _sv_service_type =
    uint8_t;
  _sv_service_type sv_service;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _prc_type =
    int16_t;
  _prc_type prc;
  using _reserved2_type =
    uint16_t;
  _reserved2_type reserved2;
  using _ic_type =
    int16_t;
  _ic_type ic;

  // setters for named parameter idiom
  Type & set__svid(
    const uint8_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__udre(
    const uint8_t & _arg)
  {
    this->udre = _arg;
    return *this;
  }
  Type & set__sv_sys(
    const uint8_t & _arg)
  {
    this->sv_sys = _arg;
    return *this;
  }
  Type & set__sv_service(
    const uint8_t & _arg)
  {
    this->sv_service = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__prc(
    const int16_t & _arg)
  {
    this->prc = _arg;
    return *this;
  }
  Type & set__reserved2(
    const uint16_t & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }
  Type & set__ic(
    const int16_t & _arg)
  {
    this->ic = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSBASSV_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSBASSV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSBASSV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSBASSV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSBASSV
    std::shared_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSBASSV
    std::shared_ptr<ublox_msgs::msg::NavSBASSV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSBASSV_ & other) const
  {
    if (this->svid != other.svid) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->udre != other.udre) {
      return false;
    }
    if (this->sv_sys != other.sv_sys) {
      return false;
    }
    if (this->sv_service != other.sv_service) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->prc != other.prc) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    if (this->ic != other.ic) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSBASSV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSBASSV_

// alias to use template instance with default allocator
using NavSBASSV =
  ublox_msgs::msg::NavSBASSV_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SBASSV__STRUCT_HPP_

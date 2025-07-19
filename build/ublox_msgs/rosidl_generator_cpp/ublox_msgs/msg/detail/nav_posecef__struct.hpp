// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavPOSECEF __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavPOSECEF __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavPOSECEF_
{
  using Type = NavPOSECEF_<ContainerAllocator>;

  explicit NavPOSECEF_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->ecef_x = 0l;
      this->ecef_y = 0l;
      this->ecef_z = 0l;
      this->p_acc = 0ul;
    }
  }

  explicit NavPOSECEF_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->ecef_x = 0l;
      this->ecef_y = 0l;
      this->ecef_z = 0l;
      this->p_acc = 0ul;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _ecef_x_type =
    int32_t;
  _ecef_x_type ecef_x;
  using _ecef_y_type =
    int32_t;
  _ecef_y_type ecef_y;
  using _ecef_z_type =
    int32_t;
  _ecef_z_type ecef_z;
  using _p_acc_type =
    uint32_t;
  _p_acc_type p_acc;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__ecef_x(
    const int32_t & _arg)
  {
    this->ecef_x = _arg;
    return *this;
  }
  Type & set__ecef_y(
    const int32_t & _arg)
  {
    this->ecef_y = _arg;
    return *this;
  }
  Type & set__ecef_z(
    const int32_t & _arg)
  {
    this->ecef_z = _arg;
    return *this;
  }
  Type & set__p_acc(
    const uint32_t & _arg)
  {
    this->p_acc = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    1u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavPOSECEF_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavPOSECEF_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavPOSECEF_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavPOSECEF_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavPOSECEF
    std::shared_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavPOSECEF
    std::shared_ptr<ublox_msgs::msg::NavPOSECEF_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavPOSECEF_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->ecef_x != other.ecef_x) {
      return false;
    }
    if (this->ecef_y != other.ecef_y) {
      return false;
    }
    if (this->ecef_z != other.ecef_z) {
      return false;
    }
    if (this->p_acc != other.p_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavPOSECEF_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavPOSECEF_

// alias to use template instance with default allocator
using NavPOSECEF =
  ublox_msgs::msg::NavPOSECEF_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPOSECEF_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavPOSECEF_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_POSECEF__STRUCT_HPP_

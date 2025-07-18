// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavDGPS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_dgpssv__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavDGPS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavDGPS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavDGPS_
{
  using Type = NavDGPS_<ContainerAllocator>;

  explicit NavDGPS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->age = 0l;
      this->base_id = 0;
      this->base_health = 0;
      this->num_ch = 0;
      this->status = 0;
      this->reserved1 = 0;
    }
  }

  explicit NavDGPS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->age = 0l;
      this->base_id = 0;
      this->base_health = 0;
      this->num_ch = 0;
      this->status = 0;
      this->reserved1 = 0;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _age_type =
    int32_t;
  _age_type age;
  using _base_id_type =
    int16_t;
  _base_id_type base_id;
  using _base_health_type =
    int16_t;
  _base_health_type base_health;
  using _num_ch_type =
    int8_t;
  _num_ch_type num_ch;
  using _status_type =
    uint8_t;
  _status_type status;
  using _reserved1_type =
    uint16_t;
  _reserved1_type reserved1;
  using _sv_type =
    std::vector<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>>>;
  _sv_type sv;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__age(
    const int32_t & _arg)
  {
    this->age = _arg;
    return *this;
  }
  Type & set__base_id(
    const int16_t & _arg)
  {
    this->base_id = _arg;
    return *this;
  }
  Type & set__base_health(
    const int16_t & _arg)
  {
    this->base_health = _arg;
    return *this;
  }
  Type & set__num_ch(
    const int8_t & _arg)
  {
    this->num_ch = _arg;
    return *this;
  }
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint16_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__sv(
    const std::vector<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavDGPSSV_<ContainerAllocator>>> & _arg)
  {
    this->sv = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    49u;
  static constexpr uint8_t DGPS_CORRECTION_NONE =
    0u;
  static constexpr uint8_t DGPS_CORRECTION_PR_PRR =
    1u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavDGPS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavDGPS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavDGPS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavDGPS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavDGPS
    std::shared_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavDGPS
    std::shared_ptr<ublox_msgs::msg::NavDGPS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavDGPS_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->age != other.age) {
      return false;
    }
    if (this->base_id != other.base_id) {
      return false;
    }
    if (this->base_health != other.base_health) {
      return false;
    }
    if (this->num_ch != other.num_ch) {
      return false;
    }
    if (this->status != other.status) {
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
  bool operator!=(const NavDGPS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavDGPS_

// alias to use template instance with default allocator
using NavDGPS =
  ublox_msgs::msg::NavDGPS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDGPS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDGPS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDGPS_<ContainerAllocator>::DGPS_CORRECTION_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavDGPS_<ContainerAllocator>::DGPS_CORRECTION_PR_PRR;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_DGPS__STRUCT_HPP_

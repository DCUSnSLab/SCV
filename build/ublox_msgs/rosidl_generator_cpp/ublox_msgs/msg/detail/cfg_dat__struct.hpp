// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgDAT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_DAT__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_DAT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgDAT __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgDAT __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgDAT_
{
  using Type = CfgDAT_<ContainerAllocator>;

  explicit CfgDAT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->datum_num = 0;
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->datum_name.begin(), this->datum_name.end(), 0);
      this->maj_a = 0.0;
      this->flat = 0.0;
      this->d_x = 0.0f;
      this->d_y = 0.0f;
      this->d_z = 0.0f;
      this->rot_x = 0.0f;
      this->rot_y = 0.0f;
      this->rot_z = 0.0f;
      this->scale = 0.0f;
    }
  }

  explicit CfgDAT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : datum_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->datum_num = 0;
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->datum_name.begin(), this->datum_name.end(), 0);
      this->maj_a = 0.0;
      this->flat = 0.0;
      this->d_x = 0.0f;
      this->d_y = 0.0f;
      this->d_z = 0.0f;
      this->rot_x = 0.0f;
      this->rot_y = 0.0f;
      this->rot_z = 0.0f;
      this->scale = 0.0f;
    }
  }

  // field types and members
  using _datum_num_type =
    uint16_t;
  _datum_num_type datum_num;
  using _datum_name_type =
    std::array<uint8_t, 6>;
  _datum_name_type datum_name;
  using _maj_a_type =
    double;
  _maj_a_type maj_a;
  using _flat_type =
    double;
  _flat_type flat;
  using _d_x_type =
    float;
  _d_x_type d_x;
  using _d_y_type =
    float;
  _d_y_type d_y;
  using _d_z_type =
    float;
  _d_z_type d_z;
  using _rot_x_type =
    float;
  _rot_x_type rot_x;
  using _rot_y_type =
    float;
  _rot_y_type rot_y;
  using _rot_z_type =
    float;
  _rot_z_type rot_z;
  using _scale_type =
    float;
  _scale_type scale;

  // setters for named parameter idiom
  Type & set__datum_num(
    const uint16_t & _arg)
  {
    this->datum_num = _arg;
    return *this;
  }
  Type & set__datum_name(
    const std::array<uint8_t, 6> & _arg)
  {
    this->datum_name = _arg;
    return *this;
  }
  Type & set__maj_a(
    const double & _arg)
  {
    this->maj_a = _arg;
    return *this;
  }
  Type & set__flat(
    const double & _arg)
  {
    this->flat = _arg;
    return *this;
  }
  Type & set__d_x(
    const float & _arg)
  {
    this->d_x = _arg;
    return *this;
  }
  Type & set__d_y(
    const float & _arg)
  {
    this->d_y = _arg;
    return *this;
  }
  Type & set__d_z(
    const float & _arg)
  {
    this->d_z = _arg;
    return *this;
  }
  Type & set__rot_x(
    const float & _arg)
  {
    this->rot_x = _arg;
    return *this;
  }
  Type & set__rot_y(
    const float & _arg)
  {
    this->rot_y = _arg;
    return *this;
  }
  Type & set__rot_z(
    const float & _arg)
  {
    this->rot_z = _arg;
    return *this;
  }
  Type & set__scale(
    const float & _arg)
  {
    this->scale = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    6u;
  static constexpr uint16_t DATUM_NUM_WGS84 =
    0u;
  static constexpr uint16_t DATUM_NUM_USER =
    65535u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgDAT_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgDAT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgDAT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgDAT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgDAT
    std::shared_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgDAT
    std::shared_ptr<ublox_msgs::msg::CfgDAT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgDAT_ & other) const
  {
    if (this->datum_num != other.datum_num) {
      return false;
    }
    if (this->datum_name != other.datum_name) {
      return false;
    }
    if (this->maj_a != other.maj_a) {
      return false;
    }
    if (this->flat != other.flat) {
      return false;
    }
    if (this->d_x != other.d_x) {
      return false;
    }
    if (this->d_y != other.d_y) {
      return false;
    }
    if (this->d_z != other.d_z) {
      return false;
    }
    if (this->rot_x != other.rot_x) {
      return false;
    }
    if (this->rot_y != other.rot_y) {
      return false;
    }
    if (this->rot_z != other.rot_z) {
      return false;
    }
    if (this->scale != other.scale) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgDAT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgDAT_

// alias to use template instance with default allocator
using CfgDAT =
  ublox_msgs::msg::CfgDAT_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgDAT_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgDAT_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgDAT_<ContainerAllocator>::DATUM_NUM_WGS84;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t CfgDAT_<ContainerAllocator>::DATUM_NUM_USER;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_DAT__STRUCT_HPP_

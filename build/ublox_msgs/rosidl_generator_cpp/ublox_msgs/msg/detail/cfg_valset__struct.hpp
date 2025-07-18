// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgVALSET.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cfgdata'
#include "ublox_msgs/msg/detail/cfg_valset_cfgdata__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgVALSET __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgVALSET __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgVALSET_
{
  using Type = CfgVALSET_<ContainerAllocator>;

  explicit CfgVALSET_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->layers = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  explicit CfgVALSET_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version = 0;
      this->layers = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _layers_type =
    uint8_t;
  _layers_type layers;
  using _reserved0_type =
    std::array<uint8_t, 2>;
  _reserved0_type reserved0;
  using _cfgdata_type =
    std::vector<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>>>;
  _cfgdata_type cfgdata;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__layers(
    const uint8_t & _arg)
  {
    this->layers = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__cfgdata(
    const std::vector<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>>> & _arg)
  {
    this->cfgdata = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    138u;
  static constexpr uint8_t LAYER_RAM =
    1u;
  static constexpr uint8_t LAYER_BBR =
    2u;
  static constexpr uint8_t LAYER_FLASH =
    4u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgVALSET_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgVALSET_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgVALSET_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgVALSET_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgVALSET
    std::shared_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgVALSET
    std::shared_ptr<ublox_msgs::msg::CfgVALSET_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgVALSET_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->layers != other.layers) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->cfgdata != other.cfgdata) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgVALSET_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgVALSET_

// alias to use template instance with default allocator
using CfgVALSET =
  ublox_msgs::msg::CfgVALSET_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALSET_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALSET_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALSET_<ContainerAllocator>::LAYER_RAM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALSET_<ContainerAllocator>::LAYER_BBR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgVALSET_<ContainerAllocator>::LAYER_FLASH;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALSET__STRUCT_HPP_

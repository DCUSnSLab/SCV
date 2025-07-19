// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/EsfSTATUS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sens'
#include "ublox_msgs/msg/detail/esf_status_sens__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__EsfSTATUS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__EsfSTATUS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EsfSTATUS_
{
  using Type = EsfSTATUS_<ContainerAllocator>;

  explicit EsfSTATUS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 7>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->fusion_mode = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
      this->num_sens = 0;
    }
  }

  explicit EsfSTATUS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc),
    reserved2(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 7>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->fusion_mode = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
      this->num_sens = 0;
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved1_type =
    std::array<uint8_t, 7>;
  _reserved1_type reserved1;
  using _fusion_mode_type =
    uint8_t;
  _fusion_mode_type fusion_mode;
  using _reserved2_type =
    std::array<uint8_t, 2>;
  _reserved2_type reserved2;
  using _num_sens_type =
    uint8_t;
  _num_sens_type num_sens;
  using _sens_type =
    std::vector<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>>>;
  _sens_type sens;

  // setters for named parameter idiom
  Type & set__i_tow(
    const uint32_t & _arg)
  {
    this->i_tow = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 7> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__fusion_mode(
    const uint8_t & _arg)
  {
    this->fusion_mode = _arg;
    return *this;
  }
  Type & set__reserved2(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }
  Type & set__num_sens(
    const uint8_t & _arg)
  {
    this->num_sens = _arg;
    return *this;
  }
  Type & set__sens(
    const std::vector<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>>> & _arg)
  {
    this->sens = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    16u;
  static constexpr uint8_t MESSAGE_ID =
    16u;
  static constexpr uint8_t FUSION_MODE_INIT =
    0u;
  static constexpr uint8_t FUSION_MODE_FUSION =
    1u;
  static constexpr uint8_t FUSION_MODE_SUSPENDED =
    2u;
  static constexpr uint8_t FUSION_MODE_DISABLED =
    3u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::EsfSTATUS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::EsfSTATUS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfSTATUS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfSTATUS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__EsfSTATUS
    std::shared_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__EsfSTATUS
    std::shared_ptr<ublox_msgs::msg::EsfSTATUS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EsfSTATUS_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->fusion_mode != other.fusion_mode) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    if (this->num_sens != other.num_sens) {
      return false;
    }
    if (this->sens != other.sens) {
      return false;
    }
    return true;
  }
  bool operator!=(const EsfSTATUS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EsfSTATUS_

// alias to use template instance with default allocator
using EsfSTATUS =
  ublox_msgs::msg::EsfSTATUS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfSTATUS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfSTATUS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfSTATUS_<ContainerAllocator>::FUSION_MODE_INIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfSTATUS_<ContainerAllocator>::FUSION_MODE_FUSION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfSTATUS_<ContainerAllocator>::FUSION_MODE_SUSPENDED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfSTATUS_<ContainerAllocator>::FUSION_MODE_DISABLED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/NavSAT.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SAT__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SAT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sv'
#include "ublox_msgs/msg/detail/nav_satsv__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__NavSAT __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__NavSAT __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSAT_
{
  using Type = NavSAT_<ContainerAllocator>;

  explicit NavSAT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      this->num_svs = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  explicit NavSAT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved0(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->i_tow = 0ul;
      this->version = 0;
      this->num_svs = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved0.begin(), this->reserved0.end(), 0);
    }
  }

  // field types and members
  using _i_tow_type =
    uint32_t;
  _i_tow_type i_tow;
  using _version_type =
    uint8_t;
  _version_type version;
  using _num_svs_type =
    uint8_t;
  _num_svs_type num_svs;
  using _reserved0_type =
    std::array<uint8_t, 2>;
  _reserved0_type reserved0;
  using _sv_type =
    std::vector<ublox_msgs::msg::NavSATSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavSATSV_<ContainerAllocator>>>;
  _sv_type sv;

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
  Type & set__num_svs(
    const uint8_t & _arg)
  {
    this->num_svs = _arg;
    return *this;
  }
  Type & set__reserved0(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__sv(
    const std::vector<ublox_msgs::msg::NavSATSV_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::NavSATSV_<ContainerAllocator>>> & _arg)
  {
    this->sv = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    1u;
  static constexpr uint8_t MESSAGE_ID =
    53u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::NavSAT_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::NavSAT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSAT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::NavSAT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__NavSAT
    std::shared_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__NavSAT
    std::shared_ptr<ublox_msgs::msg::NavSAT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSAT_ & other) const
  {
    if (this->i_tow != other.i_tow) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->num_svs != other.num_svs) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->sv != other.sv) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSAT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSAT_

// alias to use template instance with default allocator
using NavSAT =
  ublox_msgs::msg::NavSAT_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSAT_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavSAT_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SAT__STRUCT_HPP_
